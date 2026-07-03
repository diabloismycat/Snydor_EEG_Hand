#ifndef EEG_BUFFER_H
#define EEG_BUFFER_H

#include <vector>

class EEGBuffer
{
public:
    EEGBuffer(int windowSize);
    void addSample(const std::vector<double>& sample);
    void print();
    bool isFull();
    std::vector<std::vector<double>> getWindow();

private:
    int windowSize;
    std::vector<std::vector<double>> buffer;
};

#endif