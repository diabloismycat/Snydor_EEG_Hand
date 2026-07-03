#include <iostream>
#include <Eigen/Dense>
#include "ICA.h"

int main()
{
    Eigen::MatrixXd X(2, 3);

    X << 1, 2, 3,
         4, 5, 6;

    ICA ica;

    Eigen::MatrixXd clean = ica.process(X);

    std::cout << clean << std::endl;

    return 0;
}