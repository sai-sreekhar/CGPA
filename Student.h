#ifndef STUDENT_H
#define STUDENT_H
#include "Common.h"
#include "Semester.h"
#include "Course.h"
#include <string>
#include <vector>

class Student
{
private:
    std::string regNo;
    Semester allSems[NO_OF_SEMS];
    std::vector<Course *> allCourses;
    double cgpa;
    int totalCredits;
    Student* next = nullptr;

public:
    Student(std::string regNo);
    ~Student();
    void addCourse(Course *course, int semIdx);
    double getCgpa();
    void setCgpa(double cgpa);
    void calculateCgpa();
    void getSemsGpa();
    void setNextStudent(Student* next);
    Student* getNextStudent();
    std::string getRegNo();
};

#endif