/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:11:21 by jili              #+#    #+#             */
/*   Updated: 2026/01/17 12:11:23 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceLine(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::string res;
	size_t pos = 0;//current position(index) in line 
	size_t found;// store the position where s1 is found in line

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		res += line.substr(pos, found - pos);
		res += s2;
		pos = found + s1.length();
	}
	res += line.substr(pos);
	return res;
}

//***std::string::npos*** 
	// is a special value that means “NOT FOUND”.
	//npos is a static constant defined inside std::string, The value used to indicate that a search failed
//***find(sub, pos)***: line.find(s1, pos);
	//1.If it finds s1: It returns the index (position) where s1 starts
	//2.If it does not find s1: It returns std::string::npo
	//3.pos: Position from where the string search is to begin. By default, it is 0.
//***substr(pos, len)***
	//1.pos: Index of the first character to be copied.
	//2.len: Length of the sub-string
int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr <<"Usage:./sed filename s1 s2" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream infile(filename.c_str());
	if(!infile)
	{
		std::cerr << "Error: cannot open input file" << std::endl;
		return 1;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: cannot create output file" << std::endl;
		return 1;
	}
	std::string line;
	while(std::getline(infile, line))
	{
		outfile << replaceLine(line, s1, s2);
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close(); 
	outfile.close();
	return 0;
}

//***std::ifstream inputfile(filename.c_str())***
	// 1. c_str() converts a std::string into a C-style string (const char*)
	// 2. ifstream means input file stream; It is a C++ class used to read data from a file
	// 3. infile is the object name
//***std::ofstream outfile((filename + ".replace").c_str());***/
	// 1. ofstream means output file stream; It is a C++ class used to write data to a file; 
		// If the file does not exist, it is created
		// If it exists, it is truncated (cleared)
