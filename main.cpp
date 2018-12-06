#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "smart_pointer.h"

class Person {
public:

    Person(){};
    Person(const char *);
    ~Person() { std::cout << "Person::~Person()\n"; };

    const char* get_name()const;

private:
    char full_name[32];
};

Person::Person(const char * full_name)
{
    strcpy(Person::full_name,full_name);
}

const char* Person::get_name() const
{
    return full_name;
}


void test_arrow(){

    std::cout << "Test Arrow"<<std::endl;
    UniquePtr<Person> p(new Person("Shlomit"));
    if (p)
    {
       if(strcmp(p->get_name(), "Shlomit") == 0)
           std::cout << "Test Arrow Ok"<<std::endl;
       else
           std::cout << "Test Arrow FAILED"<<std::endl;
    }
}

void test_bool(){
    std::cout << "Test Bool"<<std::endl;
    UniquePtr<Person> p(new Person("Shlomit"));
    if (p)
    {
        std::cout << "Test Bool Ok"<<std::endl;
    }
    else
        std::cout << "Test Bool FAILED"<<std::endl;
}
void test_star(){
    std::cout << "Test Star"<<std::endl;
    UniquePtr<Person> p(new Person("Shlomit"));
    if (p)
    {
        if(strcmp((*p).get_name(), "Shlomit") == 0)
            std::cout << "Test Star Ok"<<std::endl;
        else
            std::cout << "Test star FAILED"<<std::endl;
    }
}
int main() {
    test_arrow();
    test_star();
    test_bool();

    return 0;
}

