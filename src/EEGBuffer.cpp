#include "EEGBuffer.h"
#include <iostream>

EEGBuffer::EEGBuffer(int windowSize)
{
    this->windowSize = windowSize;

    std::cout << "EEGBuffer created. Window size = "
              << this->windowSize
              << std::endl;
}
void EEGBuffer::addSample(const std::vector<double>& sample)
{
    buffer.push_back(sample);

    if (buffer.size() > windowSize)
    {
        buffer.erase(buffer.begin());
    }
}
void EEGBuffer::print()
{
    std::cout << "Buffer:" << std::endl;

    for (const auto& sample : buffer)
    {
        for (double value : sample)
        {
            std::cout << value << " ";
        }

        std::cout << std::endl;
    }
}
bool EEGBuffer::isFull()
{
    return buffer.size() == windowSize;
}
std::vector<std::vector<double>> EEGBuffer::getWindow()
{
    return buffer;
}