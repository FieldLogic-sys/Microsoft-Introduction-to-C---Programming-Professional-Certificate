#include <iostream>
#include <array>
#include <iomanip>

using Matrix3x3 = std::array<std::array<int, 3>, 3>; 


//Global Variables for the lab Start

Matrix3x3 matrix1 = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
Matrix3x3 matrix2 = {{{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}};


// ============================================================== Start of printMatrix function ==============================================================


void printMatrix(const Matrix3x3 &mat)
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            // setw is from <iomanip> to format the output neatly which I got the information online.
            std::cout << std::setw(4) << mat.at(row).at(col); 
        }
        std::cout << std::endl;
    }
}

// ============================================================== End of printMatrix function ==============================================================


// ============================================================== Start of addMatrices function ==============================================================
Matrix3x3 addMatrices(const Matrix3x3 &a, const Matrix3x3 &b)
{
    Matrix3x3 localResults; //Empty matrix to store results
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            localResults.at(row).at(col) =
                a.at(row).at(col) + b.at(row).at(col);
        }
    }

  
    return localResults;
}

// ============================================================== End of addMatrices function ==============================================================


// Start of main function
int main()
{

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1);

    std::cout << "\nMatrix 2:" << std::endl;
    printMatrix(matrix2);

    // 1. Call the function and store the result in a new Matrix
    Matrix3x3 sumMatrix = addMatrices(matrix1, matrix2);

    // 2. Print the result
    std::cout << "\nSum of Matrix 1 and Matrix 2:" << std::endl;
    printMatrix(sumMatrix);

    return 0;
}
