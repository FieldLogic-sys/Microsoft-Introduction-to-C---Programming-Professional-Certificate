
#include <iostream>
#include <string>
#include <vector>

class Student
{
private:
    std::string name;
    int studentId;
    std::vector<double> grades;

public:
    // Constructor
    Student(std::string studentName, int id) : name(studentName), studentId(id)
    {
        
    }

    // Adding grades
    void addGrade(double grade) {
        if (grade >= 0.0 && grade <= 100.0) {
            grades.push_back(grade);
            } else {
                std::cout << "Invalid grade. Must be between 0 and 100." <<std::endl;
            }
    }


    // Grade calculation average
    double calculateAverage() const {
        if (grades.empty()) return 0.0;

        double sum = 0.0;

        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }


    void displayStudents() const {
        std::cout << "Student: " << name << " (ID: " << studentId << ")" << std::endl;
    }
};


// Full Implementation
int main() {
    // Student 1: Your original "No One"
    Student student1("No One", 42);
    student1.addGrade(95.5);
    student1.addGrade(88.0);
    student1.addGrade(105.0); // Validation will reject this

    // Student 2: Field Specialist
    Student student2("Alpha Tech", 101);
    student2.addGrade(75.0);
    student2.addGrade(82.5);

    // Student 3: Senior Engineer
    Student student3("Bravo Lead", 202);
    student3.addGrade(98.0);
    student3.addGrade(99.5);

    // --- Interaction Phase ---
    
    std::cout << "--- Site Registry Report ---" << std::endl;
    
    student1.displayStudents();
    std::cout << "Average: " << student1.calculateAverage() << std::endl << std::endl;

    student2.displayStudents();
    std::cout << "Average: " << student2.calculateAverage() << std::endl << std::endl;

    student3.displayStudents();
    std::cout << "Average: " << student3.calculateAverage() << std::endl << std::endl;

    return 0;
}