#include<iostream>
using namespace std;

int gcd(int num1,int num2){
    if(num1 == 0){
        return num2;
    }

    if(num2 == 0){
        return num1;
    }

    if(num1 == num2){
        return num1;
    }

    if(num1>num2){
        return gcd(num1-num2,num2);
    }
    return gcd(num1,num2-num1);
}

int lcm(int num1,int num2){
     return (num1*num2)/gcd(num1,num2);
}

class Fraction{
private:
    int numerator = 0,denominator = 0;
public:
    Fraction(){}
    Fraction(int num,int den):numerator{num},denominator{den}{}

    void printFraction(){
        cout<<numerator<<"/"<<denominator<<" "<<"\n";
    }

    void simplify(){
        int tempNumerator = numerator;
        numerator = numerator/gcd(numerator,denominator);
        denominator = denominator/gcd(tempNumerator,denominator);
    }

    Fraction operator+(Fraction const &f){
        Fraction temp;
        int lcmOfDen = lcm(denominator,f.denominator);
        temp.numerator = (numerator * (lcmOfDen/denominator))+(f.numerator*(lcmOfDen/f.denominator));
        temp.denominator = lcmOfDen;
        temp.simplify();
        return temp;
    }

    // preincrement operator is chainable
//    Fraction& operator++(){
//        Fraction f1(1,1);
//        *this =  *this+f1;
//        return *this;
//    }
//
//    // post increment operators are not chainable
//    void operator++(int){
//        Fraction f1(1,1);
//        *this =  *this+f1;
//    }
};

//  overload preincrement operator using global function
    Fraction& operator++(Fraction &f){
        Fraction f1(1,1);
        f =  f+f1;
        return f;
    }
//  overload post-increment operator using global function
Fraction& operator++(Fraction &f,int){
    Fraction f1(1,1);
    f =  f+f1;
}


int main(int argc,char** argv){
    int a = 5;
    ++(++a);
    Fraction f1(1,2);
    f1.printFraction();
    Fraction f2(1,2);
    f2.printFraction();
    Fraction f3 = f1+f2;
    f3.printFraction();
    Fraction f4 = ++(++f1);
    f4.printFraction();
    f1++;
    f1.printFraction();
}