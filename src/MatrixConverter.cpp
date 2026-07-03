#include "MatrixConverter.h"

Eigen::MatrixXd MatrixConverter::toEigenMatrix(
    const std::vector<std::vector<double>>& window)
{
    // 如果窗口为空，返回一个 0×0 的矩阵
    if (window.empty())
    {
        return Eigen::MatrixXd();
    }

    // 获取行数和列数
    int rows = window.size();
    int cols = window[0].size();

    // 创建 Eigen 矩阵
    Eigen::MatrixXd X(rows, cols);

    // 把 vector<vector<double>> 拷贝到 MatrixXd
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            X(i, j) = window[i][j];
        }
    }

    return X;
}