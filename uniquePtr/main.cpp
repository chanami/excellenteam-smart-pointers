#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "smart_pointer.h"
#include "person.h"


void test_arrow(){
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
    UniquePtr<Person> p(new Person("Shlomit"));
    if (p)
    {
        std::cout << "Test Bool Ok"<<std::endl;
    }
    else
        std::cout << "Test Bool FAILED"<<std::endl;
}
void test_star(){
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
    test_bool();
    test_star();
    return 0;
}

