#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "smart_pointer.h"
#include "person.h"


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

