#pragma once
#include <vector>
#include <string>

class Matrix {
public:
  Matrix() = default;
  Matrix(int rows, int cols);
  Matrix(const std::vector<std::vector<double> > & data);
  Matrix(const std::vector<double> & data);
  Matrix transpose() const;

  friend Matrix operator*(const Matrix & lhs, const Matrix & rhs);
  friend Matrix operator*(const Matrix & lhs, double rhs);
  friend Matrix operator*(double lhs, const Matrix & rhs);

  friend Matrix operator+(const Matrix & lhs, const Matrix & rhs);
  friend Matrix operator-(const Matrix & lhs, const Matrix & rhs);

  Matrix& operator=(const std::vector<double> & lhs);

  std::vector<std::vector<double> > getMatrix() const;
  std::vector<double> getVector() const;

  int getRows();
  int getCols();

private:
  std::vector<std::vector<double> > data;
  int rows;
  int cols;

};
