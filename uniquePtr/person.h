#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_PERSON_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_PERSON_H
#include <iostream>
#include <cstring>

class Person {
public:

    Person(){};
    Person(const char *);
    ~Person() {};

    const char* get_name()const;

private:
    char full_name[32];
};

#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_PERSON_H
