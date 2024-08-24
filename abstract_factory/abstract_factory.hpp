#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Course
{
    public:
        virtual void printCourseInfo() = 0;
};

class EC1_Course : public Course
{
    public:
        void printCourseInfo();
};

class EC2_Course : public Course
{
    public:
        void printCourseInfo();
};

class CS1_Course : public Course
{
    public:
        void printCourseInfo();
};

class CS2_Course : public Course
{
    public:
        void printCourseInfo();
};

class CourseAbstractFactory
{
    public:
        static Course* getCourse(int score);
};

class EC_CourseFactory 
{
    public:
        Course* get_EC_DeptCourse(int score);
};

class CS_CourseFactory 
{
    public:
        Course* get_CS_DeptCourse(int score);
};




