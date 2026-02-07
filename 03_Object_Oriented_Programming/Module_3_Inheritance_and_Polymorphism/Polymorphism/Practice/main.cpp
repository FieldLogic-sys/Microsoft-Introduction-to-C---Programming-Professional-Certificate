#include <iostream>
#include <vector>
#include <string>

// Base Class
class Person
{
    protected:
    std::string tool;
    std::string name;
    std::string job;
    


    public:
     Person(const std::string& n, const std::string j, const std::string& t):
        name(n), job(j), tool(t) {}
    

    virtual ~Person() {};

    virtual void greet()
    {
        std::cout << name << " says: Hello! ";
    }
    std::string getName() const { return name; }
    std::string getTool() const { return tool; }
};

// A Dervied Class
class Technician : public Person
{

public:

 Technician(const std::string& n, const std::string j, const std::string& t):
        Person(n,j,t){}


    void greet() override
    {
        std::cout << name << " (Tech) says: Maybe I need a pocket protector for my " << tool << std::endl;
    };



};


class Guest : public Person{

    public:
Guest(const std::string& n, const std::string j, const std::string& t):
        Person(n,j,t){}


    void greet() override {
        std::cout << name << " (Guest) says: Maybe I am in the wrong place since I only have a " << tool << std::endl;
    }


};

int main()
{
    
    std::vector<Person*> database;

    database.push_back(new Person("Person", "Accountant", "Pocket Protector"));
    // How can I use tool here?
    database.push_back(new Technician("Tony", "Technician", "Oscilloscope"));
    database.push_back(new Guest("Herr Guest", "vacationer", "sunglasses"));


    std::cout << "--- Testing ---" << std::endl;


    for (Person* p: database) {
        // p->greet();
   


    Technician* tempTech = dynamic_cast<Technician*>(p);
    Guest* tempGuest = dynamic_cast<Guest*>(p);

    if (tempTech){
        std::cout << "I am a tech. " << std::endl;
        tempTech->greet();
    }
    // Should this be !Person || !Tech ?
  
    else if (tempGuest) {
        std::cout <<"Hello, my name is: " << p->getName() << " and I have no idea why I am here all I have is my " << tempGuest->getName() << "." << std::endl;
    }   
      else {
        std::cout << "Hello, I am " << p->getName() << "  from the if/else in the loop and my favorite tool is a " << p->getTool() << "."  <<std::endl; 
        
    }

}
    for (Person* p : database) delete p;
    return 0;

}