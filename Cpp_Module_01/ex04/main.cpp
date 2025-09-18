#include <iostream>
#include <fstream>

std::string startReplace(std::string line, std::string ori, std::string rep)
{
    std::string	rzlt;
	std::size_t	position;
	std::size_t	start;

    start = 0;
    while (1) 
	{
    	position = line.find(ori, start);
    	if (position == std::string::npos)
        	break;
    	rzlt.append(line.substr(start, position - start));
    	rzlt.append(rep);
    	start = position + ori.size();
	}
    rzlt.append(line.substr(start));
    return (rzlt);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: ./Replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string fileName = av[1];
    std::string ori = av[2];
    std::string  rep = av[3];
    if (fileName.empty() || ori.empty() || rep.empty())
    {
        std::cout << "Empty arguments." << std::endl;
        return (1);
    }
    std::ifstream inputFile(fileName.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "Can't open input file." << std::endl;
        return (1);
    }
    std::ofstream outputFile((fileName + ".replace").c_str());
    if (!outputFile.is_open())
    {
        std::cout << "Can't open output file." << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << startReplace(line, ori, rep);
        if (!inputFile.eof())
            outputFile << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return (0);
}