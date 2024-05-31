#include<iostream>
using namespace std;

//  what we learn
// friend function use
// binary operator overloading using the global function
// binary operator overloading using non static member function
// And explore rules of overloading

 class Point{

 private:
     double x = 0;
     double y = 0;
 public:
     Point(){}
     Point(double x,double y):x{x},y{y}{}

     double getX(){
         return x;
     }

     double getY(){
         return y;
     }

     void setX(double x){
         this->x = x;
     }

     void setY(double y){
         this->y = y;
     };

     void printPoint(){
         cout<<"x:"<<x<<" "<<"y:"<<y<<" \n";
     }
/*
 * Simplest form
     void add(Point const &p){
         x = x + p.x;
         y = y + p.y;
     }*/

 /*   Point add(Point const &p){
        Point ptemp;
        ptemp.x = x + p.x;
        ptemp.y = y + p.y;
        return ptemp;
    }*/

/* Not so useful overloading
 * void operator+(Point const &p){
      x = x + p.x;
      y = y + p.y;
 }*/

// most used binary overloading

//Point operator+(Point const &p){
//    Point ptemp;
//    ptemp.x = x + p.x;
//    ptemp.y = y + p.y;
//    return ptemp;
//}

friend Point operator+(Point const&,Point const&);
friend ostream& operator<<(ostream&,Point&);

 };

 Point operator+(Point const &p1,Point const &p2){
     Point ptemp;
     ptemp.x = p1.x + p2.x;
     ptemp.y = p1.y + p2.y;
     return ptemp;
 }

 // lets  overload << operator , as << works on cout which is object of pre built class
 // thats why << can not be overloaded using  non static member method but it is overloaded
 // using global function

 ostream& operator<<(ostream& output,Point &p){
     output<<"x:"<<p.x<<" ""y:"<<p.y<<" "<<endl;
     return output;
 }

int main(int argc,char** argv){
    // Before Overloading
  /*  Point p1;
    p1.printPoint();
    Point p2(2,3);
    p2.printPoint();
    p1.add(p2);
    p1.printPoint();
    Point p3 = p1.add(p2);
    p3.printPoint();*/

  // After overloading

  Point p1(2,3);
  Point p2(1,2);
  Point p3 = p1 + p2;
  cout<<p3;



}
