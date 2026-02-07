#include <string>
#include <iostream>


class User
{
    private:
        std::string name;
        std::string email;
        std::string password;
        std::string role;
        std::string userIdNumber;
    public:
        User(const std::string& n,const std::string& e, const std::string& p, const std::string& r, const std::string& uid): name(n), email(e), password(p), role(r), userIdNumber(uid) {
            std::cout << "[SYSTEM] User base created for " << name << std::endl;
        }

        virtual ~User() {}  

        void displayEmail() {
            std::cout << "Welcome " << email << std::endl;
        }

       


};


class Admin : public User
{

 
    protected:
            bool isSuperUser;
    public:


       Admin(const std::string& n,const std::string& e,const std::string& p, const std::string& r, const std::string& uid, bool super) : User(n, e, p, r, uid),isSuperUser(super) {}


       void displayRoll() {
           
            if (isSuperUser) {
                std::cout << "Welcome, Admin: " << std::endl;
            }
            else {
                std::cout << "Standard Admin Access" << std::endl;
            }
       }


    };



    int main() {
       Admin tony("Tony", "tony@cyber.com", "P@ssword123", "Admin", "UID-001", true);



tony.displayEmail();
tony.displayRoll();
    
    }





