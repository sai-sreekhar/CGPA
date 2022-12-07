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
    Semester allSems[NO_OF_SEMS];
    std::vector<Course *> allCourses;
    double cgpa;
    int totalCredits;

public:
    Student();
    ~Student();
    void addCourse(Course *course, int semIdx);
    double getCgpa();
    void setCgpa(double cgpa);
    void calculateCgpa();
};

#endif