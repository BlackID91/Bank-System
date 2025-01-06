#include "Depositor.h"


Depositor::Depositor(const Name& name, const string& ssn)
    : name(name), social_security_number(ssn) {}


const Name& Depositor::getName() const {
    return name;
}


 string Depositor::getSocialSecurityNumber() const {
   return social_security_number;
 
 }