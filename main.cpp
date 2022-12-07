#include <iostream>
#include "Student.h"
#include "Course.h"

int main()
{
    Student *s1 = new Student();
    s1->addCourse(new Course("CS101", 'S', 1, 4), 1);
    s1->addCourse(new Course("CS102", 'S', 1, 4), 1);
    s1->addCourse(new Course("CS103", 'S', 1, 4), 1);
    s1->addCourse(new Course("CS104", 'A', 1, 4), 1);
    s1->addCourse(new Course("CS104", 'S', 2, 4), 2);
    s1->addCourse(new Course("CS104", 'F', 3, 4), 3);
    s1->calculateCgpa();
    std::cout << "CGPA: " << s1->getCgpa() << std::endl;
    s1->getSemsGpa();
}