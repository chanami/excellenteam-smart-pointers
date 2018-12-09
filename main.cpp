#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "smart_pointer.h"
#include "person.h"
#include "shared_pointer.h"


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

void test_shared_point_arrow(){

    std::cout << "Test shared pointer Arrow"<<std::endl;
    shared_ptr<Person> p(new Person("Shlomit"));
    if (p)
    {
        if(strcmp(p->get_name(), "Shlomit") == 0)
            std::cout << "Test shared pointer Arrow Ok"<<std::endl;
        else
            std::cout << "Test shared pointer Arrow FAILED"<<std::endl;
    }
}

void test_shared_ptr_bool(){
    std::cout << "Test shared pointer Bool"<<std::endl;
    shared_ptr<Person> p(new Person("Shlomit"));
    if (p)
    {
        std::cout << "Test shared pointer Bool Ok"<<std::endl;
    }
    else
        std::cout << "Test shared pointer Bool FAILED"<<std::endl;
}
void test_shared_ptr_star(){
    std::cout << "Test shared pointer Star"<<std::endl;
    shared_ptr<Person> p(new Person("Shlomit"));
    if (p)
    {
        if(strcmp((*p).get_name(), "Shlomit") == 0)
            std::cout << "Test shared pointer Star Ok"<<std::endl;
        else
            std::cout << "Test shared pointer star FAILED"<<std::endl;
    }
}

void test_shared_ptr_equals_and_copy_ctor(){
    std::cout << "Test shared pointer equals"<<std::endl;
    shared_ptr<Person> p(new Person("Shlomit"));
    shared_ptr<Person> p1(p);
    if(p&&p1){
        if (p==p1)
            std::cout << "Test shared pointer equals &copy ctor Ok"<<std::endl;
        else
            std::cout << "Test shared pointer equals &copy ctor FAILED"<<std::endl;
    }

}
void test_shared_ptr_not_equals(){
    std::cout << "Test shared pointer not equals"<<std::endl;
    shared_ptr<Person> p2(new Person("Shlom8"));
    shared_ptr<Person> p4(p2);
    if (p2!=p2)
            std::cout << "Test shared pointer not equals FAILED"<<std::endl;
    else
        std::cout << "Test shared pointer not equals ok "<<std::endl;
}
void test_assignment_opr()
{
    std::cout << "Test shared pointer not equals"<<std::endl;
    shared_ptr<Person> p2(new Person("Shlom8"));
    shared_ptr<Person> p4;
    p4=p2;
    if (p2==p4)
        std::cout << "Test shared pointer not equals ok"<<std::endl;
    else
        std::cout << "Test shared pointer not equals failed"<<std::endl;

}

void test_shared_ptr_dtor()
{
    int  counter;
    shared_ptr<Person> p1(new Person("Shlomit"));
    shared_ptr<Person> p2(p1);
    shared_ptr<Person> p3(p1);

    {
        shared_ptr<Person> p4(p1);

    }

    counter = p3.getCount();
    if(counter == 3)
        std::cout << "dtor is OK" << std::endl;
    else
        std::cout << "dtor test FAILED" << std::endl;

}

void test_shared_ptr_assignment()
{
    int  counter_1,  counter_2;

    shared_ptr<Person> p1(new Person("Shlomit"));
    shared_ptr<Person> p2(new Person("Meir"));
    shared_ptr<Person> p3(p2);
    shared_ptr<Person> p4(p1);

    p1 = p2;

    counter_1 = p1.getCount();
    counter_2 = p4.getCount();

    if(counter_1 == 3 && counter_2 == 1)
        std::cout << "assignment is OK" << std::endl;
    else
        std::cout << "assignment FAILED" << std::endl;

}

int main() {
//    test_shared_ptr_assignment();
//    test_shared_ptr_dtor();
//    test_cpy_shared_ptr();
//    //    test_arrow();
    test_star();
    test_bool();
    test_shared_point_arrow();
    test_shared_ptr_equals_and_copy_ctor();
    test_shared_ptr_not_equals();
    test_shared_ptr_dtor();
    test_shared_ptr_assignment();

    return 0;
}

