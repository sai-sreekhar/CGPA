#ifndef STRINGHASH_H
#define STRINGHASH_H
#include "Common.h"
#include "Student.h"
class StringHash
{
private:
    int keysPresent;
    Student *hashTable[MAX_NO_OF_STUDENTS];
    int computeHash(std::string s);
    bool isFull();

public:
    StringHash();
    void insert(std::string rollNo, std::string name);
    void display();
    Student *search(std::string s);
};

#endif