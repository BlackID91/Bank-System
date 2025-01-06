#ifndef DEPOSITOR_H
#define DEPOSITOR_H
#include "Name.h"    
#include <string>    
using namespace std;

class Depositor {
private:
    Name name;                      
    string social_security_number;  

public:
 
    Depositor(const Name& name, const string& ssn);

   
    const Name& getName() const;

   
    string getSocialSecurityNumber() const;
};

#endif  