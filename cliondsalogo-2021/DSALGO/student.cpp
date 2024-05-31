#include<iostream>
using namespace  std;

// getters and setters for accessing and setting the private fields
// if we get and set the private fields then what is benefit of making it private see the setMethod and
// you get the benefit.

/*
 *  Constructor
 *
 *  constructor is a special method
 *  whose name is same as classname
 *  no return type
 *  only called once when object is declared
 *  it initialises the object properties
 *
 *  Types of constructor
 *
 *  Default constructor  -->  no parameter
 *  Parameterised constructor  --> has parameters (function overloading)(but rember only
 *  one constructor is called and only once for each object)
 *
 * */

class Student{
public:
    string name;
    int rollNo;
    int age;

    // default constructor (automatically declared if we not define)
    Student(){}

    //parameterised constructor
    Student(int age){
        this->age = age;
    }


//    (if  parameter is passed then by using functions overloading parameterised constructor is called)


    void setmarks(double marks,int  pass){
        if(pass != 123){
            return;
        }
        this->marks = marks;
    }

    double getMarks(){
        return marks;
    }


private:
    double marks;
};
