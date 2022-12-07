#include "Semester.h"
#include "Common.h"
Semester::Semester()
{
    semIdx = 0;
    gpa = 0;
    semCredits = 0;
}

Semester::~Semester()
{
    for (int i = 0; i < coursesArr.size(); i++)
    {
        delete coursesArr[i];
    }
}

double Semester::getGpa()
{
    return gpa;
}

void Semester::addCourse(Course *course)
{
    coursesArr.push_back(course);
    semCredits += course->getCredits();
}

void Semester::setGpa(double gpa)
{
    this->gpa = gpa;
}

void Semester::getCourses()
{
    for (int i = 0; i < coursesArr.size(); i++)
    {
        std::cout << coursesArr[i]->getCourseCode() << " " << coursesArr[i]->getCredits() << " " << coursesArr[i]->getCurGrade() << std::endl;
    }
    std::cout << std::endl;
}

void Semester::calculateGpa()
{
    double totalGradePoints = 0;
    for (int i = 0; i < coursesArr.size(); i++)
    {
        totalGradePoints += coursesArr[i]->getCredits() * getGradePoint(coursesArr[i]->getSemGrade(this->getSemIdx()));
    }
    gpa = totalGradePoints / semCredits;
}

void Semester::setSemIdx(int semIdx)
{
    this->semIdx = semIdx;
}

int Semester::getSemIdx()
{
    return semIdx;
}