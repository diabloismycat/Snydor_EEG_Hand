#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <string>
#include <vector>

class CSVReader
{
public:
    CSVReader(const std::string& filename);
    
    bool readSample(std::vector<double>& sample);

private:
    std::ifstream file;
};

#endif