#ifndef COURSE_H
#define COURSE_H
#include "Common.h"
#include <string>
#include <vector>
class Course
{
private:
    std::string courseCode;
    int credits;
    int curGradeIdx;
    char grades[NO_OF_SEMS];

public:
    Course();
    Course(std::string courseCode, char grade, int semIdx, int credits);
    ~Course();
    void setCourse(std::string courseCode, char grade, int semIdx, int credits);
    std::string getCourseCode();
    char getCurGrade();
    char* getGrades();
    int getCredits();
    char getSemGrade(int semIdx);
};

#endif