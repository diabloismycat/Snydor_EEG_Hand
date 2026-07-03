#include <iostream>
#include <vector>

#include "CSVReader.h"
#include "EEGBuffer.h"
#include "MatrixConverter.h"
#include "ICA.h"


int main()
{

    CSVReader reader("../data/test.csv");


    EEGBuffer buffer(4);


    ICA ica;


    std::vector<double> sample;



    while(reader.readSample(sample))
    {

        buffer.addSample(sample);



        if(buffer.isFull())
        {

            auto window =
                buffer.getWindow();



            Eigen::MatrixXd X =
                MatrixConverter::toEigenMatrix(
                    window
                );



            Eigen::MatrixXd clean =
                ica.process(X);



            std::cout
                << "Processed EEG:"
                << std::endl;


            std::cout
                << clean
                << std::endl;


            std::cout
                << "-------------"
                << std::endl;

        }

    }


    return 0;
}