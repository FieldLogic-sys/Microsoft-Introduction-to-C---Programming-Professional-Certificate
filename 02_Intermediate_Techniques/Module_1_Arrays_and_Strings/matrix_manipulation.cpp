#include <iostream>
#include <array>

int main()
{
    // This did not work as expected as the code helper says to hae std::array of std::array
    // std::array<int, 9> matrix = {1, 2, 3,
    //                              4, 5, 6,
    //                              7, 8, 9};
    // The correct way to do it is shown below:
    std::array<std::array<int, 3>, 3> matrix = {{{1, 2, 3},
                                                 {4, 5, 6},
                                                 {7, 8, 9}}};


    std::array<std::array<int, 3>, 3> matrix2 = {{{10, 11, 12},
                                                  {13, 14, 15},
                                                  {16, 17, 18}}};




    //This works, but is not the std::array way so it does not include certain features like at method, so it is not as safe.
    // int matrix1[3][3] = { {1, 2, 3},
    //                    {4, 5, 6},
    //                    {7, 8, 9} };
    // int matrix2[3][3] = { {10, 11, 12},
    //                    {            13, 14, 15},
    //                    {16, 17, 18} };


    
}