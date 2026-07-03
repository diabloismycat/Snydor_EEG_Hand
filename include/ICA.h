#ifndef ICA_H
#define ICA_H

#include <Eigen/Dense>

class ICA
{
public:
    ICA();

    Eigen::MatrixXd process(const Eigen::MatrixXd& X);
};

#endif