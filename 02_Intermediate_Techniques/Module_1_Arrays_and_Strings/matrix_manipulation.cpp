#include <iostream>
#include <array>
#include <iomanip>

using Matrix3x3 = std::array<std::array<int, 3>, 3>; // Type alias for a 3x3 matrix of integers, and can create others of different sizes as needed. I might create a template later to make it more flexible. Maybe with user input, but not needed now.

// Starting all over again with the lab. Since not all of the info was provided in the lessons, I did some research on std::array of std::array to create a 2D array using std::array and decided that my intuition was correct and just needing to have the one function for the loops to access the elements of all of the matrixes. Tis will allow for safer access with the at() method and other std::array features and can call the function for individual arrays if needed, of the same size. So far, this is not part of the lab, but I am adding it for my own learning and reference so I can continue to improve.

// ============================================================== Start of printMatrix function ============================================================== (seperation done solely for readability) )

Matrix3x3 matrix1 = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
Matrix3x3 matrix2 = {{{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}};


void printMatrix(const Matrix3x3 &mat)
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            // setw is from <iomanip> to format the output neatly which I got the information online.
            std::cout << std::setw(4) << mat.at(row).at(col); // Using at() method for safer access
        }
        std::cout << std::endl;
    }
}

Matrix3x3 addMatrices(const Matrix3x3 &a, const Matrix3x3 &b)
{
    Matrix3x3 localResults;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            localResults.at(row).at(col) =
                a.at(row).at(col) + b.at(row).at(col);
        }
    }

    // 1. Call the function and store the result in a new Matrix
  

    // 2. Print the result
    std::cout << "\nSum of Matrix 1 and Matrix 2:" << std::endl;
    printMatrix(localResults);

    return localResults;
}

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

// ============================================================== End of printMatrix function ==============================================================

// The below is only for reference and is not part of the file matrix_manipulation.cpp. TODO #1: Remove this comment and the code below when you have noted the information you need.
//  int main()
//  {
//      // This did not work as expected as the code helper says to hae std::array of std::array
//      // std::array<int, 9> matrix = {1, 2, 3,
//      //                              4, 5, 6,
//      //                              7, 8, 9};
//      // The correct way to do it is shown below:
//      std::array<std::array<int, 3>, 3> matrix1 = {{{1, 2, 3},
//                                                   {4, 5, 6},
//                                                   {7, 8, 9}}};

//     std::array<std::array<int, 3>, 3> matrix2 = {{{10, 11, 12},
//                                                   {13, 14, 15},
//                                                   {16, 17, 18}}};

//     //This works, but is not the std::array way so it does not include certain features like at method, so it is not as safe.
//     // int matrix1[3][3] = { {1, 2, 3},
//     //                    {4, 5, 6},
//     //                    {7, 8, 9} };
//     // int matrix2[3][3] = { {10, 11, 12},
//     //                    {            13, 14, 15},
//     //                    {16, 17, 18} };

//     // Accessing elements
//     for (int row = 0; row < 3; ++row)
//     {
//         for (int col = 0; col < 3; ++col)
//         {
//             std::cout << matrix1.at(row).at(col) << " ";
//             std::cout << matrix2.at(row).at(col) << " ";
//         }
//         std::cout << std::endl;
//     }

//     return 0;

// }