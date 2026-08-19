/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucca <lucca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 16:06:35 by lucca             #+#    #+#             */
/*   Updated: 2026/08/19 18:40:51 by lucca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

using std::string;

static bool writeIntoBuffer(const string& filename, string& buffer)
{
	string			line;
	std::ifstream	in(filename.c_str());
	if (in.is_open() == false)
	{
		std::cerr << "[ERROR]: no such file or no permition: " << filename << '\n';
		return (false);
	}
	while (std::getline(in, line))
	{
		buffer += line + '\n';
	}
	in.close();
	return (true);
}

static void	myReplaceAll(string& buffer, const string& s1, const string& s2)
{
	string::size_type	pos = 0;

	if (s1.empty())
	{
		std::cerr << "[ERROR]: s1(argv[2]) cannot be empty.\n";
		return ;
	}
	while (pos != string::npos)
	{
		pos = buffer.find(s1, pos);
		if (pos != string::npos)
		{
			buffer.erase(pos, s1.length());
			buffer.insert(pos, s2);
			pos += s2.length();
		}
	}
}

static bool writeIntoOutput(const string& filename, const string& buffer)
{
	const string	outputFilename = filename + ".replace";

	std::ofstream	out(outputFilename.c_str());
	if (out.is_open() == false)
	{
		std::cerr << "[ERROR]: fail to open or create file: " << filename << '\n';
		return (false);
	}
	out << buffer;
	out.close();
	return (true);
}

static bool	validateInput(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "[ERROR]: invalid number of arguments: got " << argc << ", expected 4.\n";
		return (false);
	}
	const string& s1 = argv[2];
	if (s1.empty())
	{
		std::cerr << "[ERROR]: s1(argv[2]) cannot be empty.\n";
		return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	if (!validateInput(argc, argv))
		return (1);

	const string	filename = argv[1];
	const string	s1 = argv[2];
	const string	s2 = argv[3];
	string			buffer;
	if (!writeIntoBuffer(filename, buffer))
		return (1);
	myReplaceAll(buffer, s1, s2);
	if (!writeIntoOutput(filename, buffer))
		return (1);
	return (0);
}
