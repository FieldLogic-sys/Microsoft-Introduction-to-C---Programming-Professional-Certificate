#include <iostream>
#include <limits> 

int main()
{
    // Create a 5x5 seating chart (0 = available, 1 = occupied) (Coursera provided project lab.)
    int OCCUPIED = 1;
    int AVAILABLE = 0;
    int occupiedSeats = 0;
    int availableSeats = 0;
    int seating[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0}};

    std::cout << "Theater seating chart initialized!" << std::endl;
    std::cout << "0 = Available, 1 = Occupied" << std::endl;
    for (int row = 0; row < 5; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            std::cout << seating[row][col] << " ";
            if (seating[row][col] == 1)
            {
                ++occupiedSeats;
            }
            else
            {
                ++availableSeats;
            }
        }
        std::cout << std::endl;
    }
    // ===================== A 4x6 seating chart with your own availability pattern. =====================
    std::cout << "Occupied seats: " << occupiedSeats << std::endl;
    std::cout << "Available seats: " << availableSeats << std::endl;

    int auto_seating[4][6] = {
        {0, 1, 0, 1, 0, 1},
        {1, 1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 0},
    };


  
    int user_row;

    int user_col;
  

    do
    {

        std::cout << "which row do you want to check? (1-4): ";
        std::cin >> user_row;

        if (std::cin.fail())
        {
            std::cin.clear(); // clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            user_row = 0; // set to an invalid value to continue the loop
            continue;
        }

        if (user_row < 1 || user_row > 4)
        {
            std::cout << "Invalid row number." << std::endl;
            }

    } while (user_row < 1 || user_row > 4);

   do {
        std::cout << "Which column do you want to check? (1-6): ";
        std::cin >> user_col;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Please enter a number." << std::endl;
            user_col = 0; // Force loop to continue
            continue;
        }

        if (user_col < 1 || user_col > 6) {
            std::cout << "Error: Column must be between 1 and 6." << std::endl;
        }
    } while (user_col < 1 || user_col > 6);
    
    

    // I think that this might be duplicating a bit below
    auto &row_ref = auto_seating[user_row - 1];
    ;

    
    // ===============================================================

    std::cout << "Status of seat at row " << user_row << ", column " << user_col << ": ";
    if (row_ref[user_col - 1] == 1)
    {
        std::cout << "Occupied" << std::endl;
    }
    else
    {
        std::cout << "Available" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Full row availability check for row " << user_row << ": ";
    for (const auto &seat : row_ref)
    {
        std::cout << seat << " ";
    }

    return 0;
}