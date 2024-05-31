#include<iostream>
using namespace std;

// I do great job by overloading -unary operator

class Complex{

private:
    double real = 0,imag = 0;

public:
    Complex(){}
    Complex(double real,double imag):real{real},imag{imag}{}

    void printComplex(){
         cout<<real<<(imag<0 ? " - ":" + ")<<abs(imag)<<"i"<<" "<<endl;
    }

//    Complex operator-(){
//        Complex c;
//        c.real = -(real);
//        c.imag = -(imag);
//        return c;
//    }

// make a friend
friend Complex operator-(Complex const&);

};

// Now lets try to overload using the global function

Complex operator-(Complex const &c){
    Complex ctemp;
    ctemp.real = -(c.real);
    ctemp.imag = -(c.imag);
    return ctemp;
}

int main(int argc,char** argv){

    Complex num1;
    num1.printComplex();

    Complex num2(3.0,-2.0);
    num2.printComplex();

    // lets overload -unary to make below statement work
    num1 = -(-num2);
    num1.printComplex();

}