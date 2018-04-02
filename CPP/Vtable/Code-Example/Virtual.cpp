#include <iostream>
using namespace std;


/*


Virtual Function is a member function that is declared wihtin the base class and redefined 
by a derived class.

How to create virtual function ?
To create virtual function precede the function's declaration in th base class with 
the keyword virtual.
When a class containing virtual function is inherited, the derived class redefines 
the virtual function to fit its own needs.

*/


class base 
{
  int var;
  public :
         virtual void vfunc()
         {
         cout << " \n Base Class Virtual function " ;        
         }    
      
};

class derived1 : public base {
      
                             void vfunc()
                             {
                             cout << " \n Derived1 Class Virtual function " ;        
                             }    
      
                             };


class derived2 : public base {
      
                             void vfunc()
                             {
                             cout << " \n Derived2 Class Virtual function " ;        
                             }    
      
                             };                             
       // Base class reference is used to access virtual funciton                       
       void func(base &r)
       {
       r.vfunc();                 
       }                             
                             
#if 0
int main()
{
 base *p,b;
 derived1 d1;
 derived2 d2;
 
 p = &b;
 
 p->vfunc();
 
 p = &d1;
 
 p->vfunc();
 
 p = &d2;
 
 p->vfunc();
 cin.get();   
 return 0;   
}
#endif

#if 0

int main()
{
 
 base b;
 derived1 d1;
 derived2 d2;
 
 func(b);
 func(d1);
 func(d2);   
    
 cin.get();   
 return 0;   
}

#endif



//Pure Virtual Funciton
// Virtual function practical example.
#include <iostream>
using namespace std;
class convert {
protected:
double val1; // initial value
double val2; // converted value
public:
convert(double i) {
val1 = i;
}
double getconv() { return val2; }
double getinit() { return val1; }
virtual void compute() = 0;
};
// Liters to gallons.
class l_to_g : public convert {
public:
l_to_g(double i) : convert(i) { }
void compute() {
val2 = val1 / 3.7854;
}
};
// Fahrenheit to Celsius
class f_to_c : public convert {
      
      public:
f_to_c(double i) : convert(i) { }
void compute() {
val2 = (val1-32) / 1.8;
}
};
int main()
{
convert *p; // pointer to base class
l_to_g lgob(4);
f_to_c fcob(70);
// use virtual function mechanism to convert
p = &lgob;
cout << p->getinit() << " liters is ";
p->compute();
cout << p->getconv() << " gallons\n"; // l_to_g
p = &fcob;
cout << p->getinit() << " in Fahrenheit is ";
p->compute();
cout << p->getconv() << " Celsius\n"; // f_to_c
cin.get();
return 0;
}


