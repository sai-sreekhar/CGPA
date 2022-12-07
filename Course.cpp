#include "Course.h"

Course::Course()
{
    courseCode = "";
    credits = 0;
    curGradeIdx = 0;
}

Course::~Course()
{
}

Course ::Course(std::string courseCode, char grade, int semIdx, int credits)
{
    this->credits = credits;
    this->courseCode = courseCode;
    grades[semIdx] = grade;
    if (curGradeIdx < semIdx)
    {
        curGradeIdx = semIdx;
    }
}

std::string Course::getCourseCode()
{
    return this->courseCode;
}
char Course::getCurGrade()
{
    return grades[curGradeIdx];
}
char* Course::getGrades()
{
    return grades;
}

int Course::getCredits()
{
    return credits;
}

void Course ::setCourse(std::string courseCode, char grade, int semIdx, int credits)
{
    this->credits = credits;
    this->courseCode = courseCode;
    grades[semIdx] = grade;
    if (curGradeIdx < semIdx)
    {
        curGradeIdx = semIdx;
    }
}

char Course::getSemGrade(int semIdx)
{
    return grades[semIdx];
}