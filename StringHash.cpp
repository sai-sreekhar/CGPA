#include <bits/stdc++.h>
#include "Student.h"
#include "Common.h"
#include "StringHash.h"

int StringHash::computeHash(std::string s)
{
    int hash = 0;

    for (int i = 0; i < s.length(); i++)
    {
        hash += s[i];
    }
    return (hash % MAX_NO_OF_STUDENTS);
}

bool StringHash::isFull()
{
    return (MAX_NO_OF_STUDENTS == keysPresent);
}

StringHash ::StringHash()
{
    keysPresent = 0;
    memset(hashTable, 0, sizeof(hashTable));
}

void StringHash::insert(std::string rollNo, std::string name)
{
    if (isFull())
    {
        std::cout << ("ERROR : Hash Table Full\n");
        return;
    }

    if (search(rollNo) != nullptr)
    {
        std::cout << "Roll Number Already Present" << std::endl;
        return;
    }

    int hashVal = computeHash(rollNo);

    Student *newStudent = new Student(rollNo);
    newStudent->setNextStudent(nullptr);

    if (hashTable[hashVal] == nullptr)
    {
        hashTable[hashVal] = newStudent;
        keysPresent += 1;
        return;
    }

    Student *pvsStudent = hashTable[hashVal];
    Student *presentStudent = hashTable[hashVal]->getNextStudent();

    while (presentStudent != NULL)
    {
        pvsStudent = presentStudent;
        presentStudent = presentStudent->getNextStudent();
    }

    presentStudent = newStudent;
    pvsStudent->setNextStudent(presentStudent);
    keysPresent += 1;

    return;
}

Student* StringHash::search(std::string s)
{
    int hashVal = computeHash(s);

    if (hashTable[hashVal] == nullptr)
    {
        return nullptr;
    }
    else
    {
        Student *presentStudent = hashTable[hashVal];
        while (presentStudent != nullptr)
        {
            if ((presentStudent->getRegNo()) == s)
            {
                return presentStudent;
            }
            else
            {
                presentStudent = presentStudent->getNextStudent();
            }
        }
    }
    return nullptr;
}

void StringHash::display()
{
    for (int i = 0; i < MAX_NO_OF_STUDENTS; i++)
    {
        Student *presentStudent = hashTable[i];
        while (presentStudent != nullptr)
        {
            std::cout << "Roll Number: " << (presentStudent->getRegNo()) << std::endl;
            presentStudent = presentStudent->getNextStudent();
        }
    }
}
