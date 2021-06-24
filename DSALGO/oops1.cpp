#include<iostream>
#include "student.cpp"
using namespace std;

// oops
// oops is a way of programming in which we see our program entities in terms of real world objects

// In real world every object has properties and some function so same in oops

// Two fundamental concepts
// 1. Classes
// 2. Objetcs

/*
 *   classes are the blueprint of objects. Or datatype for particular type of project which has same
 *   same attributes and methods.
 *   Object are the real instance of the class which gets memory.
 *   We can also called class as a user defined datatype
 *
 *   Access modifiers
 *   1. public
 *   2. private
 *   3. protected
 *
 *   public --> used anywhere
 *   private --> used only inside the class
 *   protected --> used everywhere
 * */

// example class

int main(int argc,char **argv){
    // creating static variables and objects
    int a = 10;
    Student s1;
    s1.name ="yogesh";
    s1.age = 21;

    cout<<s1.name<<" "<<s1.age<<" "<<a<<"\n";

    // creating dynamic variables and objects
    int *a1 = new int;
    *a1 = 10;
    Student *s2 = new Student();
    (*s2).name = "poornesh";
    //shortcut of above line syntax s2->name = "poornesh"
    s2->age = 21;
    cout<<s2->name<<" "<<s2->age<<" "<<*a1<<"\n";

    s1.setmarks(20.0,123);
    s2->setmarks(30.0,123);
    cout<<s1.name<<" marks : "<<s1.getMarks()<<" \n";
    cout<<s2->name<<" marks : "<<s2->getMarks()<<" \n";

}