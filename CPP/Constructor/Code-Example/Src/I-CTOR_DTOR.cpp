//http://www.umsl.edu/~subramaniana/inherit2.html

#include <iostream>
/* This program illustrates the sequence in which
** base class and derived class constructors and 
** destructors are executed
*/

/*
This Program Illustrates what a derived class contains from the base class :  
when a class is derived from the base class . the derived class inherits the Member functions 
and data members of the derived class. 
When an object of the derived class is created following is the Sequence :
1. CTOR of the base class is called 
2. CTOR of the derived class is called 
3. DTOR of the derived class is called 
4. DTOR of the base class is called
*/

using namespace std;

class base {
public:
     base() { cout << "Constructing base ... \n"; }
     ~base() { cout << "Destroying base ... \n"; }
};

class derived : public base {
public:
     derived() { cout << "Constructing derived... \n"; }
     ~derived() { cout << "Destroying derived... \n"; }
};

int main()
{
     derived ob;
     return 0;
}
