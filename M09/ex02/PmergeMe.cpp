#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// ── Input parsing 

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int val;

        if (!(iss >> val))
            throw std::runtime_error("Error: invalid argument");

        std::string leftover;
        if (iss >> leftover)
            throw std::runtime_error("Error: invalid argument");

        if (val < 0)
            throw std::runtime_error("Error: negative number not allowed");

        _vec.push_back(val);
        _deq.push_back(val);
    }
}

// ── Jacobsthal sequence 
//
// Ford-Johnson uses Jacobsthal numbers to decide insertion order, minimising
// the number of comparisons needed.
// Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...
// T(n) = T(n-1) + 2*T(n-2)
//
// We generate indices that cover [0, n) in Jacobsthal order so that binary search bounds stay as tight as possible.

std::vector<std::size_t> PmergeMe::jacobsthalOrder(std::size_t n) const
{
    // Build Jacobsthal numbers up to just past n
    std::vector<std::size_t> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < n)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

    // Expand into an ordered list of indices not yet seen
    std::vector<bool>        seen(n, false);
    std::vector<std::size_t> order;

    for (std::size_t k = 1; k < jac.size(); ++k)
    {
        // Insert from jac[k]-1 down to jac[k-1] (the previous boundary)
        std::size_t hi = jac[k];
        std::size_t lo = jac[k - 1];

        if (hi > n) hi = n;

        // Walk backwards from hi-1 down to lo
        for (std::size_t idx = hi; idx > lo; --idx)
        {
            std::size_t i = idx - 1;
            if (i < n && !seen[i])
            {
                seen[i] = true;
                order.push_back(i);
            }
        }
    }
    // Catch any remaining indices (shouldn't happen, but safety net)
    for (std::size_t i = 0; i < n; ++i)
        if (!seen[i]) order.push_back(i);

    return order;
}

// ── Vector implementation 

// Binary-search insert `value` into the sorted prefix [0, bound) of `sorted`
void PmergeMe::binaryInsert(std::vector<int> &sorted,
                             int              value,
                             std::size_t      bound) const
{
    if (bound > sorted.size())
        bound = sorted.size();

    std::size_t lo = 0, hi = bound;
    while (lo < hi)
    {
        std::size_t mid = lo + (hi - lo) / 2;
        if (sorted[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    sorted.insert(sorted.begin() + static_cast<std::ptrdiff_t>(lo), value);
}

// Ford-Johnson merge-insertion sort for std::vector<int>
void PmergeMe::mergeInsertVec(std::vector<int> &seq)
{
    std::size_t n = seq.size();
    if (n <= 1) return;

    // Step 1: Pair up elements, sort each pair so larger is first
    bool hasStraggler = (n % 2 != 0);
    int  straggler    = hasStraggler ? seq.back() : 0;
    if (hasStraggler) seq.pop_back();

    std::size_t pairs = seq.size() / 2;

    // Store pairs: (larger, smaller)
    std::vector<std::pair<int, int> > paired(pairs);
    for (std::size_t i = 0; i < pairs; ++i)
    {
        int a = seq[2 * i];
        int b = seq[2 * i + 1];
        paired[i] = (a >= b) ? std::make_pair(a, b) : std::make_pair(b, a);
    }

    //  Step 2: Recursively sort the "larger" (main) elements ────────────────
    std::vector<int> main_chain;
    for (std::size_t i = 0; i < pairs; ++i)
        main_chain.push_back(paired[i].first);

    mergeInsertVec(main_chain); // recursive call

    // Step 3: Build the pend list aligned to sorted main_chain 

    // After recursion, main_chain is sorted.  We need to find, for each
    // main element, its corresponding pend (smaller) partner.
    //
    // Because recursion may have reordered main elements we must match them.
    // aFor[i] records the "a" value originally paired with pend[i], so that
    // later we can relocate it inside the (mutating) main_chain.
    std::vector<int> pend;
    std::vector<int> aFor;
    {
        // Match each pend to its partner by value.
        // We use a temporary copy of paired and mark used entries.
        std::vector<std::pair<int, int> > tmp = paired;
        for (std::size_t i = 0; i < main_chain.size(); ++i)
        {
            for (std::size_t j = 0; j < tmp.size(); ++j)
            {
                if (tmp[j].first == main_chain[i] && tmp[j].second != -1)
                {
                    pend.push_back(tmp[j].second);
                    aFor.push_back(tmp[j].first);
                    tmp[j].second = -1; // mark used
                    break;
                }
            }
        }
    }

    // Step 4: Insert pend elements using Jacobsthal order 
    // The first pend element is guaranteed <= main_chain[0], insert at front
    if (!pend.empty())
    {
        main_chain.insert(main_chain.begin(), pend[0]);

        if (pend.size() > 1)
        {
            std::vector<std::size_t> order = jacobsthalOrder(pend.size());

            for (std::size_t k = 0; k < order.size(); ++k)
            {
                std::size_t idx = order[k];
                if (idx == 0) continue; // already inserted

                // Earlier insertions may have shifted the position of this
                // pend's paired "a" value within main_chain, so we must
                // locate it *now* rather than trust a static formula.
                std::vector<int>::iterator pos =
                    std::find(main_chain.begin(), main_chain.end(), aFor[idx]);
                std::size_t bound = static_cast<std::size_t>(pos - main_chain.begin()) + 1;
                binaryInsert(main_chain, pend[idx], bound);
            }
        }
    }

    // Step 5: Insert straggler if odd count 
    if (hasStraggler)
        binaryInsert(main_chain, straggler, main_chain.size());

    seq = main_chain;
}

// ── Deque implementation 

void PmergeMe::binaryInsertDeq(std::deque<int> &sorted,
                                int              value,
                                std::size_t      bound) const
{
    if (bound > sorted.size())
        bound = sorted.size();

    std::size_t lo = 0, hi = bound;
    while (lo < hi)
    {
        std::size_t mid = lo + (hi - lo) / 2;
        if (sorted[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    sorted.insert(sorted.begin() + static_cast<std::ptrdiff_t>(lo), value);
}

// Ford-Johnson merge-insertion sort for std::deque<int>
void PmergeMe::mergeInsertDeq(std::deque<int> &seq)
{
    std::size_t n = seq.size();
    if (n <= 1) return;

    bool hasStraggler = (n % 2 != 0);
    int  straggler    = hasStraggler ? seq.back() : 0;
    if (hasStraggler) seq.pop_back();

    std::size_t pairs = seq.size() / 2;

    std::vector<std::pair<int, int> > paired(pairs);
    for (std::size_t i = 0; i < pairs; ++i)
    {
        int a = seq[2 * i];
        int b = seq[2 * i + 1];
        paired[i] = (a >= b) ? std::make_pair(a, b) : std::make_pair(b, a);
    }

    std::deque<int> main_chain;
    for (std::size_t i = 0; i < pairs; ++i)
        main_chain.push_back(paired[i].first);

    mergeInsertDeq(main_chain);

    std::deque<int> pend;
    std::vector<int> aFor;
    {
        std::vector<std::pair<int, int> > tmp = paired;
        for (std::size_t i = 0; i < main_chain.size(); ++i)
        {
            for (std::size_t j = 0; j < tmp.size(); ++j)
            {
                if (tmp[j].first == main_chain[i] && tmp[j].second != -1)
                {
                    pend.push_back(tmp[j].second);
                    aFor.push_back(tmp[j].first);
                    tmp[j].second = -1;
                    break;
                }
            }
        }
    }

    if (!pend.empty())
    {
        main_chain.insert(main_chain.begin(), pend[0]);

        if (pend.size() > 1)
        {
            std::vector<std::size_t> order = jacobsthalOrder(pend.size());

            for (std::size_t k = 0; k < order.size(); ++k)
            {
                std::size_t idx = order[k];
                if (idx == 0) continue;

                std::deque<int>::iterator pos =
                    std::find(main_chain.begin(), main_chain.end(), aFor[idx]);
                std::size_t bound = static_cast<std::size_t>(pos - main_chain.begin()) + 1;
                binaryInsertDeq(main_chain, pend[idx], bound);
            }
        }
    }

    if (hasStraggler)
        binaryInsertDeq(main_chain, straggler, main_chain.size());

    seq = main_chain;
}

// ── Public entry point 

void PmergeMe::run(int argc, char **argv)
{
    parseInput(argc, argv);

    // Print unsorted sequence
    std::cout << "Before: ";
    printContainer(_vec);

    // ── Sort with std::vector and measure time 
    std::clock_t startVec = std::clock();
    mergeInsertVec(_vec);
    std::clock_t endVec = std::clock();
    double timeVec = static_cast<double>(endVec - startVec)
                     / CLOCKS_PER_SEC * 1e6; // microseconds

    // ── Sort with std::deque and measure time 
    std::clock_t startDeq = std::clock();
    mergeInsertDeq(_deq);
    std::clock_t endDeq = std::clock();
    double timeDeq = static_cast<double>(endDeq - startDeq)
                     / CLOCKS_PER_SEC * 1e6;

    // Print sorted sequence (use vector result)
    std::cout << "After:  ";
    printContainer(_vec);

    std::size_t count = _vec.size();

    std::cout << "Time to process a range of " << count
              << " elements with std::vector : "
              << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << count
              << " elements with std::deque  : "
              << timeDeq << " us" << std::endl;
}
