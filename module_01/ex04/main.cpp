#include <string>
#include <fstream>
#include <iostream>

int read_and_replace(std::string fileName, std::string s1, std::string s2)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error opening the file!\n";
        return 2;
    }
    std::ofstream newFile((fileName + ".replace").c_str());
    if (!newFile.is_open())
    {
        std::cerr << "Error creating new file!\n";
        return 3;
    }

    std::string line;
    bool first = true;
    while (std::getline(file, line))
    {
        size_t pos = line.find(s1);
        while (pos != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos = line.find(s1, pos + s2.length());
        }
        if (!first)
            newFile << "\n";
        newFile << line;
        first = false;
    }
    file.close();
    newFile.close();
    return 0;
}

int main(int argc, char **argv)
{

    if (argc != 4)
    {
        std::cerr << "Wrong number of arguments!\n";
		std::cerr << "Type in ./sed_pro <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    return read_and_replace(fileName, s1, s2);
}
