#include "ICA.h"


ICA::ICA()
{

}



Eigen::MatrixXd ICA::process(
    const Eigen::MatrixXd& X)
{
    Eigen::MatrixXd centered =
        center(X);

    Eigen::MatrixXd white =
        whiten(centered);

    Eigen::MatrixXd sources =
        fastICA(white);

    return sources;
}




Eigen::MatrixXd ICA::center(
    const Eigen::MatrixXd& X)
{

    Eigen::MatrixXd centered = X;


    for(int col = 0;
        col < centered.cols();
        col++)
    {
        double mean =
            centered.col(col).mean();


        centered.col(col).array()
            -= mean;
    }


    return centered;
}





Eigen::MatrixXd ICA::whiten(
    const Eigen::MatrixXd& X)
{

    Eigen::MatrixXd covariance =
        (X.transpose() * X)
        /
        double(X.rows() - 1);



    Eigen::SelfAdjointEigenSolver
        <Eigen::MatrixXd>
        solver(covariance);



    Eigen::VectorXd eigenvalues =
        solver.eigenvalues();



    for(int i = 0;
        i < eigenvalues.size();
        i++)
    {
        if(eigenvalues(i) < 1e-8)
        {
            eigenvalues(i) = 1e-8;
        }
    }



    Eigen::MatrixXd D_inv_sqrt =
        eigenvalues
        .cwiseInverse()
        .cwiseSqrt()
        .asDiagonal();



    Eigen::MatrixXd E =
        solver.eigenvectors();



    Eigen::MatrixXd X_white =
        X * E * D_inv_sqrt;



    return X_white;
}

Eigen::MatrixXd ICA::fastICA(
    const Eigen::MatrixXd& X)
{

    int components = X.cols();


    Eigen::MatrixXd W =
        Eigen::MatrixXd::Random(
            components,
            components
        );


    W = decorrelate(W);


    int maxIterations = 100;

    double tolerance = 1e-6;



    for(int iter = 0;
        iter < maxIterations;
        iter++)
    {

        Eigen::MatrixXd W_old =
            W;



        Eigen::MatrixXd Y =
            X * W;



        Eigen::MatrixXd G =
            Y.array().tanh();



        Eigen::MatrixXd W_new =
            (X.transpose() * G)
            /
            double(X.rows());



        W_new =
            decorrelate(W_new);



        double change =
            (W_new - W_old)
            .norm();



        W = W_new;



        if(change < tolerance)
        {
            break;
        }

    }



    Eigen::MatrixXd S =
        X * W;


    return S;
}

Eigen::MatrixXd ICA::decorrelate(
    const Eigen::MatrixXd& W)
{

    Eigen::MatrixXd covariance =
        W.transpose() * W;


    Eigen::SelfAdjointEigenSolver
        <Eigen::MatrixXd>
        solver(covariance);


    Eigen::VectorXd eigenvalues =
        solver.eigenvalues();


    for(int i = 0;
        i < eigenvalues.size();
        i++)
    {
        if(eigenvalues(i) < 1e-8)
        {
            eigenvalues(i) = 1e-8;
        }
    }


    Eigen::MatrixXd D_inv_sqrt =
        eigenvalues
        .cwiseInverse()
        .cwiseSqrt()
        .asDiagonal();


    Eigen::MatrixXd E =
        solver.eigenvectors();


    return W * E * D_inv_sqrt * E.transpose();

}