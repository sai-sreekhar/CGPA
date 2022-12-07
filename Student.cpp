#include "Student.h"
#include "Common.h"

Student::Student(std:: string regNo)
{
    this->regNo = regNo;
    cgpa = 0;
    totalCredits = 0;
    for (int i = 0; i < NO_OF_SEMS; i++)
    {
        allSems[i].setSemIdx(i);
    }
}

Student::~Student()
{
    for (int i = 0; i < allCourses.size(); i++)
    {
        delete allCourses[i];
    }
}

void Student::addCourse(Course *course, int semIdx)
{
    allSems[semIdx].addCourse(course);
    for (int i = 0; i < allCourses.size(); i++)
    {
        if (allCourses[i]->getCourseCode() == course->getCourseCode())
        {
            allCourses[i]->setCourse(course->getCourseCode(), course->getCurGrade(), semIdx, course->getCredits());

            return;
        }
    }
    totalCredits += course->getCredits();
    allCourses.push_back(course);
}

double Student::getCgpa()
{
    return cgpa;
}

void Student::setCgpa(double cgpa)
{
    this->cgpa = cgpa;
}

void Student::calculateCgpa()
{
    double totalGradePoints = 0;
    for (int i = 0; i < allCourses.size(); i++)
    {
        totalGradePoints += allCourses[i]->getCredits() * getGradePoint(allCourses[i]->getCurGrade());
    }
    cgpa = totalGradePoints / totalCredits;
}

void Student::getSemsGpa()
{
    for (int i = 1; i < NO_OF_SEMS; i++)
    {
        allSems[i].calculateGpa();
        std::cout << "Semester " << i << " GPA: " << allSems[i].getGpa() << std::endl;
    }
}

void Student::setNextStudent(Student* nextStudent)
{
    this->next = next;
}

Student* Student::getNextStudent()
{
    return next;
}

std::string Student::getRegNo()
{
    return regNo;
}