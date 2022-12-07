#ifndef NO_OF_SEMS
#define NO_OF_SEMS 9
#endif

#ifndef SEMESTER_H
#define SEMESTER_H
#include "Course.h"
#include <string>
#include <vector>

class Semester
{
private:
    int semIdx;
    std::vector<Course *> coursesArr;
    double gpa;
    int semCredits;

public:
    Semester();
    ~Semester();
    double getGpa();
    void addCourse(Course *course);
    void setGpa(double gpa);
    void getCourses();
    void calculateGpa();
    void setSemIdx(int semIdx);
    int getSemIdx();
};

#endif