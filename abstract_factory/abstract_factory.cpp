#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abstract_factory.hpp"

using namespace std;

void EC1_Course :: printCourseInfo()
{
    cout << "EC1 course" << endl;
}

void EC2_Course :: printCourseInfo()
{
    cout << "EC2 course" << endl;
}

void CS1_Course :: printCourseInfo()
{
    cout << "CS1 course" << endl;
}

void CS2_Course :: printCourseInfo()
{
    cout << "CS2 course" << endl;
}
Course* CS_Factory :: getCsCourse()
{
    if (this->sr > 855)
        return new CS1_Course();
    else
        return new CS2_Course();
}

Course* EC_Factory :: getEcCourse()
{
    if (this->sr > 755)
        return new EC1_Course();
    else
        return new EC2_Course();
}
Course* CourseAbstractFactory:: getCourse(int score)
{
    if(score > 850)
    {
        CS_Factory* p= new CS_Factory(score);
        return p->getCsCourse();
    }
    else 
    {
        EC_Factory* p= new EC_Factory(score);
        return p->getEcCourse();
    }
}
int main()
{
    Course * p=CourseAbstractFactory ::getCourse(860);
    p->printCourseInfo();
    return 0;
}