#ifndef ICA_H
#define ICA_H

#include <Eigen/Dense>

class ICA
{
public:

    ICA();


    Eigen::MatrixXd process(
        const Eigen::MatrixXd& X
    );


private:

    Eigen::MatrixXd center(
        const Eigen::MatrixXd& X
    );


    Eigen::MatrixXd whiten(
        const Eigen::MatrixXd& X
    );


    Eigen::MatrixXd fastICA(
        const Eigen::MatrixXd& X
    );


    Eigen::MatrixXd decorrelate(
        const Eigen::MatrixXd& W
    );

};

#endif