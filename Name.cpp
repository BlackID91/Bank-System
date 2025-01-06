#include "Name.h"  

Name::Name(const string& first_name, const string& last_name)
    : first_name(first_name), last_name(last_name) {}


string Name::getFirstName() const {
    return first_name;
}

string Name::getLastName() const {
    return last_name;
}