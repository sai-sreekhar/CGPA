#include  <iostream>
#include "Student.h"
#include "Course.h"

int main()
{
    Student* s1 = new Student();
    s1->addCourse(new Course("CS101", 'S', 0, 4), 0);
    s1->addCourse(new Course("CS102", 'S', 0, 4), 0);
    s1->addCourse(new Course("CS103", 'S', 0, 4), 0);
    s1->addCourse(new Course("CS104", 'A', 0, 4), 0);
    s1->addCourse(new Course("CS104", 'S', 0, 4), 0);
    s1->calculateCgpa();
    std:: cout << s1->getCgpa();

}