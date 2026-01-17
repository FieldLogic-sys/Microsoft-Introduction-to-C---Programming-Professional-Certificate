#include <iostream>
#include <array>
#include <iomanip>
#include <stdexcept>

// Type alias for a 3x3 grid
using Matrix3x3 = std::array<std::array<int, 3>, 3>; 

// Test Matrix 1: Double braces are usually safest for nested std::arrays
Matrix3x3 matrix1 = {{
    {{6, 1, 1}},
    {{4, -2, 5}},
    {{2, 8, 7}}
}};

Matrix3x3 matrix2 = {{
    {{1, 2, 3}},
    {{0, 4, 5}},
    {{1, 0, 6}}
}};

void printMatrix(const Matrix3x3 &mat) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << std::setw(4) << mat.at(row).at(col); 
        }
        std::cout << std::endl;
    }
}

Matrix3x3 addMatrices(const Matrix3x3 &a, const Matrix3x3 &b) {
    Matrix3x3 localResults; 
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            localResults.at(row).at(col) = a.at(row).at(col) + b.at(row).at(col);
        }
    }
    return localResults;
}

Matrix3x3 multiplyMatrices(const Matrix3x3 &a, const Matrix3x3 &b) {
    Matrix3x3 localResult = {}; // Initialize to zeros

    for (int i = 0; i < 3; ++i) {        
        for (int j = 0; j < 3; ++j) {    
            for (int k = 0; k < 3; ++k) { 
                localResult.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
            }
        }
    }
    return localResult;
}

Matrix3x3 transposeMatrix(const Matrix3x3 &mat) {
    Matrix3x3 localResult;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            localResult.at(col).at(row) = mat.at(row).at(col);
        }
    }
    return localResult;
}

int calculateDeterminant(const Matrix3x3 &mat) {
    // Accessing elements by index to match Laplace Expansion formula
    int a = mat.at(0).at(0), b = mat.at(0).at(1), c = mat.at(0).at(2);
    int d = mat.at(1).at(0), e = mat.at(1).at(1), f = mat.at(1).at(2);
    int g = mat.at(2).at(0), h = mat.at(2).at(1), i = mat.at(2).at(2);

    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}

int main() {
    try {
        std::cout << "--- Matrix 1 ---\n";
        printMatrix(matrix1);
        
        std::cout << "\n--- Matrix 2 ---\n";
        printMatrix(matrix2);

        Matrix3x3 sum = addMatrices(matrix1, matrix2);
        std::cout << "\nSum:\n";
        printMatrix(sum);

        Matrix3x3 prod = multiplyMatrices(matrix1, matrix2);
        std::cout << "\nProduct:\n";
        printMatrix(prod);

        std::cout << "\nDet(M1): " << calculateDeterminant(matrix1) << std::endl;
        std::cout << "Det(M2): " << calculateDeterminant(matrix2) << std::endl;

    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}