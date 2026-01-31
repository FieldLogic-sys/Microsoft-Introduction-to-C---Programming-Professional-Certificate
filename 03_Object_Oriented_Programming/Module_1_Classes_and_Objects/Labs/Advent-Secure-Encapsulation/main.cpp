class Character
{
public:
    std::string name;
    int hitPoints;
    int attackStrength;
    void displayInfo()
    {
        std::cout << "Name: " << name << ", HP: " << hitPoints
                  << ", Attack: " << attackStrength << std::endl;
    }
};