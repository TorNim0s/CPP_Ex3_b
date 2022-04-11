#include "Matrix.hpp"
#include <sstream>

using namespace std;

namespace zich
{
    Matrix::Matrix(const vector<double> &mat, const int row, const int col)
    {
        if (row <= 0 || col <= 0)
        {
            throw invalid_argument("Matrix::Matrix(const vector<double> &mat, const int row, const int col)");
        }

        if (mat.size() != row * col)
        {
            throw invalid_argument("Matrix::Matrix(const vector<double> &mat, const int row, const int col)");
        }

        this->mat = mat;
        this->row = (size_t)row;
        this->col = (size_t)col;
    }

    // Operator +
    Matrix Matrix::operator+(Matrix const &other) const
    {
        if (other.row != this->row || other.col != this->col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }
        vector<double> newMat;
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                newMat.push_back(this->mat[i * this->col + j] + other.mat[i * other.col + j]);
            }
        }
        return Matrix(newMat, this->row, this->col);
    }
    Matrix &Matrix::operator+=(Matrix const &other)
    {
        if (other.row != this->row || other.col != this->col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                this->mat[i * this->col + j] += other.mat[i * other.col + j];
            }
        }
        return *this;
    }
    Matrix &Matrix::operator++()
    {
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                this->mat[i * this->col + j] += 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator++(const int num)
    {
        Matrix temp = *this;
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                this->mat[i * this->col + j] += 1;
            }
        }
        return temp;
    }

    // Operator -
    Matrix Matrix::operator-(Matrix const &other) const
    {
        if (other.row != this->row || other.col != this->col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }
        vector<double> newMat;
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                newMat.push_back(this->mat[i * this->col + j] - other.mat[i * other.col + j]);
            }
        }
        return Matrix(newMat, this->row, this->col);
    }
    Matrix &Matrix::operator-=(Matrix const &other)
    {
        if (other.row != this->row || other.col != this->col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                this->mat[i * this->col + j] -= other.mat[i * other.col + j];
            }
        }
        return *this;
    }
    Matrix &Matrix::operator--()
    {
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                this->mat[i * this->col + j] -= 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator--(const int num)
    {
        Matrix temp = *this;
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                this->mat[i * this->col + j] -= 1;
            }
        }
        return temp;
    }

    // Operator *
    Matrix Matrix::operator*(const Matrix &other) const
    {
        if (this->col != other.row)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }
        vector<double> newMat;
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < other.col; j++)
            {
                double sum = 0;
                for (size_t k = 0; k < this->col; k++)
                {
                    sum += this->mat[i * this->col + k] * other.mat[k * other.col + j];
                }
                newMat.push_back(sum);
            }
        }
        return Matrix(newMat, this->row, other.col);
    }
    Matrix &Matrix::operator*=(const Matrix &other)
    {
        if (this->col != other.row)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }
        vector<double> newMat;
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < other.col; j++)
            {
                double sum = 0;
                for (size_t k = 0; k < this->col; k++)
                {
                    sum += this->mat[i * this->col + k] * other.mat[k * other.col + j];
                }
                newMat.push_back(sum);
            }
        }
        this->mat = newMat;
        return *this;
    }

    Matrix Matrix::operator*(const double num) const
    {
        vector<double> newMat;
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                newMat.push_back(this->mat[i * this->col + j] * num);
            }
        }
        return Matrix(newMat, this->row, this->col);
    }
    Matrix &Matrix::operator*=(const double num)
    {
        vector<double> newMat;
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                this->mat[i * this->col + j] *= num;
            }
        }
        return *this;
    }

    int Matrix::sum() const
    {
        int sum = 0;
        for (size_t i = 0; i < this->row * this->col; i++)
        {
            sum += this->mat[i];
        }

        return sum;
    }

    // statements
    bool Matrix::operator<(const Matrix &other) const
    {
        if (this->row != other.row || this->col != other.col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }

        return this->sum() < other.sum();
    }
    bool Matrix::operator<=(const Matrix &other) const
    {
        if (this->row != other.row || this->col != other.col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }

        return this->sum() <= other.sum();
    }
    bool Matrix::operator>(const Matrix &other) const
    {
        if (this->row != other.row || this->col != other.col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }

        return this->sum() > other.sum();
    }
    bool Matrix::operator>=(const Matrix &other) const
    {
        if (this->row != other.row || this->col != other.col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }

        return this->sum() >= other.sum();
    }
    bool Matrix::operator==(const Matrix &other) const
    {
        if (this->row != other.row || this->col != other.col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }

        for (size_t i = 0; i < this->row * this->col; i++)
        {
            if (this->mat[i] != other.mat[i])
            {
                return false;
            }
        }
        return true;
    }
    bool Matrix::operator!=(const Matrix &other) const
    {
        if (this->row != other.row || this->col != other.col)
        {
            throw invalid_argument("Matrix sizes are not equal");
        }

        return !(*this==other);
    }

    // cout <<
    ostream &operator<<(ostream &os, const Matrix &mat)
    {
        for (size_t i = 0; i < mat.row; i++)
        {
            os << '[';
            for (size_t j = 0; j < mat.col; j++)
            {
                if (j != mat.col - 1)
                {
                    os << mat.mat[i * mat.col + j] << " ";
                }
                else
                {
                    os << mat.mat[i * mat.col + j];
                }
            }
            if (i != mat.row - 1)
            {
                os << "]\n";
            }
            else
            {
                os << ']';
            }
        }
        return os;
    }

    istream &operator>>(istream &is, Matrix &mat)
    {
        int row = 0;
        int col = 0;
        int check_col = 0;
        string curr;
        int counter = 0; // check for [ ] correctness
        vector<double> newMat;
        while (getline(is, curr))
        {
            for (unsigned int i = 0; i < curr.length(); ++i)
            {
                if (curr[i] == '[')
                {
                    if (col == 0)
                    {
                        col = check_col;
                    }
                    else if (check_col != col)
                    {
                        throw invalid_argument("Matrix sizes are not equal");
                    }

                    check_col = 0;

                    row++;
                    counter++;
                    if (counter > 1)
                    {
                        throw invalid_argument("You have entered incorrect syntax [ problem");
                    }
                }
                else if (curr[i] == ']')
                {
                    counter--;
                    if (counter < 0)
                    {
                        throw invalid_argument("You have entered incorrect syntax ] problem");
                    }
                }
                else if (curr[i] == ' ' || curr[i] == ',')
                {
                    if (curr[i] == ',')
                    {
                        if (i == 0)
                        {
                            throw invalid_argument("You have entered incorrect syntax cannot put , in the start");
                        }
                        if (curr[i - 1] != ']' || curr[i + 1] != ' ')
                        {
                            throw invalid_argument("You have entered incorrect syntax");
                        }
                    }

                    continue;
                }
                else if (curr[i] >= '0' && curr[i] <= '9')
                {
                    string pushNum;
                    while (curr[i] >= '0' && curr[i] <= '9')
                    {
                        pushNum += curr[i];
                        i++;
                    }
                    double push_double = std::stod(pushNum);
                    newMat.push_back(push_double);
                    check_col++;
                    i--;
                }
                else
                {
                    throw invalid_argument("Syntax of the istream is not correct");
                }
            }
        }
        if (counter != 0)
        {
            throw invalid_argument("You have entered incorrect syntax [ problem");
        }
        mat = Matrix(newMat, row, col);
        return is;
    }

    // * and -
    Matrix operator*(const double num, const Matrix &ourMat)
    {
        return ourMat * num;
    }
    Matrix operator-(const Matrix &ourMat)
    {
        return ourMat * (-1);
    }
    Matrix operator+(const Matrix &ourMat)
    {
        return ourMat;
    }
}