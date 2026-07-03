#ifndef MATRIX_CONVERTER_H
#define MATRIX_CONVERTER_H

#include <vector>
#include <Eigen/Dense>

class MatrixConverter
{
public:
    static Eigen::MatrixXd toEigenMatrix(
        const std::vector<std::vector<double>>& window
    );
};

#endif