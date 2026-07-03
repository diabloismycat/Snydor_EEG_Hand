#include "CSVReader.h"
#include <iostream>
#include <sstream>

CSVReader::CSVReader(const std::string& filename)
{
    file.open(filename);

    if(file.is_open())
    {
        std::cout << "CSV opened successfully!" << std::endl;
    }
    else
    {
        std::cout << "Cannot open CSV!" << std::endl;
    }
}

bool CSVReader::readSample(std::vector<double>& sample)
{
    sample.clear();

    std::string line;

    if (!std::getline(file, line))
    {
        return false;
    }

    std::stringstream ss(line);

    std::string value;

    while (std::getline(ss, value, ','))
    {
        double number = std::stod(value);

        sample.push_back(number);
    }

    return true;
}