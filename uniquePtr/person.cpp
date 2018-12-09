#include "person.h"

Person::Person(const char * full_name)
{
    strcpy(Person::full_name,full_name);
}

const char* Person::get_name() const
{
    return full_name;
}


