#include <iostream>
#include <cctype>

// std::toupper() does NOT return a char, it returns an int. *(char) * : Take the integer returned by toupper and treat it as a character
int main(int argc, char **argv)
{
	if (argc == 1)
		std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for(int j = 0; argv[i][j] != '\0'; j++)
			{
				std :: cout << (char)std :: toupper(argv[i][j]);
			}
		}
	}
	std :: cout << std :: endl; //Print a newline and flush the output stream
	return (0);
}
