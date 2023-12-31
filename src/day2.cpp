#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dayLinker.hh"

int day2(int part)
{
	std::ifstream input("./input/day2input.txt");
	std::string line{};
	const int NUM_RED = 12;
	const int NUM_GREEN = 13;
	const int NUM_BLUE = 14;
	int minRed = 0;
	int minGreen = 0;
	int minBlue = 0;
	int numSuccess = 0;
	std::vector<std::string> splits{};
	std::vector<std::string> games{};
	std::vector <std::string> colors{};
	bool possible = true;
	if (input.is_open())
	{
		while (std::getline(input, line))
		{
			minRed = 0;
			minGreen = 0;
			minBlue = 0;
			possible = true;
			splits = split(split(line, ": ")[1], "; ");
			for (std::string cube : splits)
			{
				games = split(cube, ", ");
				for (std::string game : games)
				{
					colors = split(game, " ");
					switch (colors[1][0])
					{
					case 'r':
						if (std::stoi(colors[0]) > minRed)
						{
							minRed = std::stoi(colors[0]);
						}
						if (std::stoi(colors[0]) > NUM_RED)
						{
							possible = false;
						}
						break;
					case 'g':
						if (std::stoi(colors[0]) > minGreen)
						{
							minGreen = std::stoi(colors[0]);
						}
						if (std::stoi(colors[0]) > NUM_GREEN)
						{
							possible = false;
						}
						break;
					case 'b':
						if (std::stoi(colors[0]) > minBlue)
						{
							minBlue = std::stoi(colors[0]);
						}
						if (std::stoi(colors[0]) > NUM_BLUE)
						{
							possible = false;
						}
						break;
					}
				}
			}
			// part one
			if (part == 1)
			{
				if (possible)
				{
					//std::cout << "this line works! " << line << std::endl;
					numSuccess += std::stoi(split(split(line, ": ")[0], " ")[1]);
				}
			}
			else 
			{
				// part two
				numSuccess += minRed * minGreen * minBlue;
			}
		}
		std::cout << "final sum: " << numSuccess << std::endl;
	}
	else {
		std::cerr << "missing input file.. exiting!" << std::endl;
		return -1;
	}
	return 0;
}