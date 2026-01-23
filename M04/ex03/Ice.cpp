#include "Ice.hpp"

void	Cure::use(ICharacter& target)
{
	std::cout << this->getType() << ": * shoots an ice bolt at " << target.getName();
}