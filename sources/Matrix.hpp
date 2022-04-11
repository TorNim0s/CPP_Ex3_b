#include <iostream>
#include <vector>
#include <stdexcept>

namespace zich
{
    class Matrix
    {
    private:
        std::vector<double> mat;
        size_t row;
        size_t col;
        int sum() const;

    public:
        // Constructors
        Matrix(const std::vector<double> &mat, const int row, const int col);

        // Operator +
        Matrix operator+(Matrix const &other) const;
        Matrix &operator+=(Matrix const &other);
        Matrix &operator++();
        Matrix operator++(const int num);

        // Operator -
        Matrix operator-(Matrix const &other) const;
        Matrix &operator-=(Matrix const &other);
        Matrix &operator--();
        Matrix operator--(const int num);

        // Operator *
        Matrix operator*(const Matrix &other) const;
        Matrix &operator*=(const Matrix &other);
        Matrix operator*(const double num) const;
        Matrix &operator*=(const double num);

        // statements
        bool operator<(const Matrix &other) const;
        bool operator<=(const Matrix &other) const;
        bool operator>(const Matrix &other) const;
        bool operator>=(const Matrix &other) const;
        bool operator==(const Matrix &other) const;
        bool operator!=(const Matrix &other) const;

        // cout <<
        friend std::ostream & operator<<(std::ostream &os, const Matrix &ourMat);

        // cout <<
        friend std::istream & operator>>(std::istream &is, Matrix &ourMat);

        // * and -
        friend Matrix operator*(const double num, const Matrix &ourMat);
        friend Matrix operator-(const Matrix &ourMat);
        friend Matrix operator+(const Matrix &ourMat);
        
    };
}