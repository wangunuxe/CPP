#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <algorithm>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void run(int argc, char **argv);

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    // Parse and validate all arguments into both containers
    void parseInput(int argc, char **argv);

    // Print a container's contents
    template <typename Container>
    void printContainer(const Container &c) const;

    // ── Ford-Johnson for std::vector<int> 

    // Generate Jacobsthal insertion order indices
    // The sequence: 1, 3, 5, 11, 21, 43, 85, ... (T(n) = 2*T(n-2) + T(n-1))
    std::vector<std::size_t> jacobsthalOrder(std::size_t n) const;

    // Binary-search insertion into a sorted range [begin, end)
    void binaryInsert(std::vector<int> &sorted,
                      int value,
                      std::size_t bound) const;

    void mergeInsertVec(std::vector<int> &seq);

    // ── Ford-Johnson for std::deque<int> 

    void binaryInsertDeq(std::deque<int> &sorted,
                         int value,
                         std::size_t bound) const;

    void mergeInsertDeq(std::deque<int> &seq);
};

// Template must be visible at compile time
template <typename Container>
void PmergeMe::printContainer(const Container &c) const
{
    typename Container::const_iterator it = c.begin();
    for (; it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

#endif
