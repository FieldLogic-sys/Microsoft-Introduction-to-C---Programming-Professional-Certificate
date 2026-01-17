#include <iostream>
#include <array>
#include <iomanip>
#include <stdexcept> // Required for exception handling

// Type alias to keep code readable
using Matrix3x3 = std::array<std::array<int, 3>, 3>; 

// ==============================================================
// Global Variables for the lab 
// ==============================================================

// Test Matrix 1: Positive Determinant (-306)
Matrix3x3 matrix1 = {{
    {6, 1, 1},
    {4, -2, 5},
    {2, 8, 7}
}};

// Test Matrix 2: Negative Determinant (22)
Matrix3x3 matrix2 = {{
    {1, 2, 3},
    {0, 4, 5},
    {1, 0, 6}
}};

// ==============================================================
// printMatrix function
// ==============================================================
void printMatrix(const Matrix3x3 &mat)
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            // setw is from <iomanip> to format the output neatly
            std::cout << std::setw(4) << mat.at(row).at(col); 
        }
        std::cout << std::endl;
    }
}

// ==============================================================
// addMatrices function
// ==============================================================
Matrix3x3 addMatrices(const Matrix3x3 &a, const Matrix3x3 &b)
{
    Matrix3x3 localResults; 
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            localResults.at(row).at(col) = a.at(row).at(col) + b.at(row).at(col);
        }
    }
    return localResults;
}

// ==============================================================
// multiplyMatrices function
// ==============================================================
Matrix3x3 multiplyMatrices(const Matrix3x3 &a, const Matrix3x3 &b) {
    Matrix3x3 localResult = {}; // Initialize to all zeros to prevent "garbage" data

    for (int i = 0; i < 3; ++i) {        
        for (int j = 0; j < 3; ++j) {    
            for (int k = 0; k < 3; ++k) { 
                // Cumulative sum: multiply across row 'i' and down column 'j'
                localResult.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
            }
        }
    }
    return localResult;
}

// ==============================================================
// transposeMatrix function
// ==============================================================
Matrix3x3 transposeMatrix(const Matrix3x3 &mat) {
    Matrix3x3 localResult;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            // THE SWAP: Row becomes Column, Column becomes Row
            localResult.at(col).at(row) = mat.at(row).at(col);
        }
    }
    return localResult;
}

// ==============================================================
// calculateDeterminant function
// ==============================================================
// Disclaimer: Formula researched online for 3x3 matrix Laplace Expansion
int calculateDeterminant(const Matrix3x3 &mat) {
    int a = mat.at(0).at(0);
    int b = mat.at(0).at(1);
    int c = mat.at(0).at(2);
    
    int d = mat.at(1).at(0);
    int e = mat.at(1).at(1);
    int f = mat.at(1).at(2);
    
    int g = mat.at(2).at(0);
    int h = mat.at(2).at(1);
    int i = mat.at(2).at(2);

    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}

// ==============================================================
// main function
// ==============================================================
int main()
{
    // Try block captures any out_of_range errors thrown by .at()
    try {
        std::cout << "--- Initial Matrices ---" << std::endl;
        std::cout << "Matrix 1:" << std::endl;
        printMatrix(matrix1);

        std::cout << "\nMatrix 2:" << std::endl;
        printMatrix(matrix2);

        // Matrix Addition
        Matrix3x3 sumMatrix = addMatrices(matrix1, matrix2);
        std::cout << "\nSum of Matrix 1 and Matrix 2:" << std::endl;
        printMatrix(sumMatrix);

        // Matrix Multiplication
        Matrix3x3 productMatrix = multiplyMatrices(matrix1, matrix2);
        std::cout << "\nProduct of Matrix 1 and Matrix 2:" << std::endl;
        printMatrix(productMatrix);

        // Matrix Transpose
        Matrix3x3 transposedMatrix = transposeMatrix(matrix1);
        std::cout << "\nTranspose of Matrix 1:" << std::endl;
        printMatrix(transposedMatrix);

        // Matrix Determinants
        std::cout << "\nDeterminant of Matrix 1: " << calculateDeterminant(matrix1) << std::endl;
        std::cout << "Determinant of Matrix 2: " << calculateDeterminant(matrix2) << std::endl;

    } 
    // catch handles exceptions instantly (unbuffered) via std::cerr
    catch (const std::out_of_range& e) {
        std::cerr << "CRITICAL ERROR: Out of range access detected. " << e.what() << std::endl;
        return 1;
    } 
    catch (const std::exception& e) {
        std::cerr << "AN UNEXPECTED ERROR OCCURRED: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}