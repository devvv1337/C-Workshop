#ifndef PERSON_HH
#define PERSON_HH
#include <iostream>
#include <string>

class Person
{
public:
    Person(const std::string& name, unsigned int age);
    std::string name_get() const;
    unsigned int age_get() const;
    void name_set(const std::string& name);
    void age_set(unsigned int age);

private:
    std::string name_;
    unsigned int age_;
};

#endif
