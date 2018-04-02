

#if 0
Reference : http://www.learncpp.com/cpp-tutorial/125-the-virtual-table/
#endif


#include <iostream>
using namespace std;

class Base
{
public:
    virtual void function1() {cout << "\n BC FUNC1" << endl;}
    virtual void function2() {cout << "\n BC FUNC2" << endl;}
};
 
class D1: public Base
{
public:
    virtual void function1() {cout << "\n DC1 FUNC1" << endl;}
};
 
class D2: public Base
{
public:
    virtual void function2() {cout << "\n DC2 FUNC1" << endl;}
};


int main()
{
  Base ob1;
  D1 ob2;
  D2 ob3;
  /* 
  Base Class : Virtual Table has Two Funcitons
  */
  ob1.function1();
  ob1.function2();

  /* 
  D1 Class : Virtual Table has Two Funcitons of Base class and Its own dervied class function
  */
  
  ob2.function1();
  ob2.function2();

  /* 
  D2 Class : Virtual Table has Two Funcitons of Base class and Its own dervied class function
  */
  
  ob3.function1();
  ob3.function2();
  
cin.get();    
    
return 0;    
}
