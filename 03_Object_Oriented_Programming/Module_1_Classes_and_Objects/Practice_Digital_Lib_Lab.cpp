#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int pages;
    bool isAvailable;

public:
    //Parameterized constructor
    Book(std::string bookTitle, std::string bookAuthor, int pageCount)
    :title(bookTitle), author(bookAuthor), pages(pageCount), isAvailable(true) {

    }

    // Getter methods
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPages() const { return isAvailable; }

    // Setters
    void setPages (int newPages) {
        if (newPages > 0) {
            pages = newPages;
        }
    }
    void setAvailability(bool status) {
        isAvailable = status;
    }

    // Displaying book information

    void displayInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author; " << author << std::endl;
        std::cout << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
        std::cout << "------------------------" << std::endl;

    }

};

int main() {
    // Book creation creation
    Book book1("The C++ Programming Language", "Bjarne Strougrup", 1376);
    Book book2("Clean Code", "Robert c Martin", 464);
    Book book3("Steal the Network", "Multiple", 100);

    book1.displayInfo();
    book2.displayInfo();
    book3.displayInfo();

    // Object Interation

    std::cout << "Checking out: " << book1.getTitle() << std::endl;
    book1.setAvailability(false);
    book1.displayInfo();
    return 0;

}
