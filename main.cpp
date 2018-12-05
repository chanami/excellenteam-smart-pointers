#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "smart_pointer.h"

class Person {
public:

    Person(const char * full_name){
        strcpy(Person::full_name,full_name);
    };
    ~Person() { std::cout << "Person::~Person()\n"; };
private:
    char full_name[32];
};

int main() {
    UniquePtr<Person> p(new Person("Shlomit"));
    if (p)
    {
        std::cout << "Hello, Worlpd!"<<std::endl;
    }

    std::cout << "Hello, World!" <<std::endl;
    return 0;
}