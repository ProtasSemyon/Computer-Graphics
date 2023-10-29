#include "Matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int rows, int cols): rows(rows), cols(cols){
}

Matrix::Matrix(const std::vector<std::vector<double> > & data){
    this->data = data;
    rows = data.size();
    cols = data[0].size();
}

Matrix::Matrix(const std::vector<double> & data){
    this->data.push_back(data);
    rows = 1;
    cols = data.size();
}

Matrix Matrix::transpose() const {
    auto retValue = Matrix(cols, rows);
    for (int rowNum = 0; rowNum < rows; ++rowNum){
        for(int colNum = 0; colNum < cols; ++colNum){
            retValue.data[colNum][rowNum] = data[rowNum][colNum];
        }
    }
    return retValue;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs){
    if(lhs.cols != rhs.rows){
        throw std::invalid_argument("Invalid matrix size");
    }

    auto retValue = Matrix(lhs.rows, rhs.cols);
    for (int rowNum = 0; rowNum < lhs.rows; ++rowNum){
        for (int colNum = 0; colNum < rhs.cols; ++colNum){
            for(int currElem = 0; currElem < lhs.cols; ++currElem){
                retValue.data[rowNum][colNum] += lhs.data[rowNum][currElem] * rhs.data[currElem][colNum];
            }
        }
    }
    return retValue;
}

Matrix operator*(const Matrix& rhs, double lhs){
    auto retValue = Matrix(rhs.data);
    for(auto& row : retValue.data){
        for(auto& val : row){
            val *= lhs;
        }
    }
    return retValue;
} 

Matrix operator*(double lhs, const Matrix& rhs){
    return rhs * lhs;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs){
    if(lhs.cols != rhs.cols || lhs.rows != rhs.rows){
        throw std::invalid_argument("Invalid matrix size");
    }
    auto retValue = Matrix(lhs.data);
    for(int rowNum = 0; rowNum < lhs.rows; ++rowNum){
        for(int colNum = 0; colNum < rhs.cols; ++colNum){
            retValue.data[rowNum][colNum] -= rhs.data[rowNum][colNum];
        }
    }
    return retValue;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs){
    if(lhs.cols != rhs.cols || lhs.rows != rhs.rows){
        throw std::invalid_argument("Invalid matrix size");
    }
    auto retValue = Matrix(lhs.data);
    for(int rowNum = 0; rowNum < lhs.rows; ++rowNum){
        for(int colNum = 0; colNum < rhs.cols; ++colNum){
            retValue.data[rowNum][colNum] += rhs.data[rowNum][colNum];
        }
    }
    return retValue;
}

Matrix& Matrix::operator=(const std::vector<double>& rhs){
    rows = 1;
    cols = rhs.size();
    data = std::vector<std::vector<double> >();
    data.push_back(rhs);
    return *this;
}


std::vector<std::vector<double> > Matrix::getMatrix() const {
    return data;
}

std::vector<double>  Matrix::getVector() const {
    if(rows != 1){
        throw std::invalid_argument("No vector");
    }
    return data[0];
}

int Matrix::getCols(){
    return cols;
}

int Matrix::getRows(){
    return rows;
}