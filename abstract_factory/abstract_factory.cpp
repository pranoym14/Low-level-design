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

Course* CourseAbstractFactory:: getCourse(int score)
{
    if(score > 850)
        return new CS1_Course();
    else if (score > 800)
        return new CS2_Course();
    else if (score > 750)
        return new EC1_Course();
    else 
        return new EC2_Course();
}
int main()
{
    Course * p=CourseAbstractFactory ::getCourse(752);
    p->printCourseInfo();
    return 0;
}