/*

References: http://www.programmerinterview.com/index.php/c-cplusplus/virtual-destructors/
http://www.gotw.ca/publications/mill18.htm
Understanding the Need of the VIrtual Destructor 

The below Exam_1is simply an Example stating How the derived class Memory is not destructed.
After deleting the Pointer . the derived class is not destructed. 

One More Example is used to Demonstrate ..test case use for Virtual destructor .
\
*/


#include <iostream>

using namespace std;

#define EXAM_1   1

#define EXAM_2   0

#if EXAM_1

class Base{
      
      public:
             //This is the constructor for base class 
             Base(){cout <<"\n Constructing Base class "<< endl;}
             //This is the destructor for the base class
             ~Base() {cout <<"\n Destructing Base class "<< endl;}
                                
           };
           
           
class Derived1 : public Base {
      public :
             //This is the constructor for derived class 
             Derived1(){cout <<"\n Constructing Derived class "<< endl;}
             //This is the destructor for the derived class
             ~Derived1() {cout <<"\n Destructing Derived class "<< endl;}
             
                                };           


int main()
{
 Base *b_Ptr = new Derived1();   
 
 delete b_Ptr;   
 cin.get();   
 return 0;   
}

#endif



#if EXAM_2


class Base{
      
      public:
             //This is the constructor for base class 
             Base(){cout <<"\n Constructing Base class "<< endl;}
             //This is the destructor for the base class
            virtual ~Base() {cout <<"\n Destructing Base class "<< endl;}
                                
           };
           
           
class Derived1 : public Base {
      public :
             //This is the constructor for derived class 
             Derived1(){cout <<"\n Constructing Derived class "<< endl;}
             //This is the destructor for the derived class
             ~Derived1() {cout <<"\n Destructing Derived class "<< endl;}
             
                                };           


int main()
{
 Base *b_Ptr = new Derived1();   
 
 delete b_Ptr;   
 cin.get();   
 return 0;   
}


#endif
