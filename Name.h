#ifndef NAME_H
#define NAME_H

#include <string>  

using namespace std;  

class Name {
private:
    string first_name;  
    string last_name;  

public:
   
    Name(const string& first_name, const string& last_name);

   
    string getFirstName() const;

   
    string getLastName() const;
};

#endif 