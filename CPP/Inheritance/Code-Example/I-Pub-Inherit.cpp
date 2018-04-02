
#include <iostream.h>
/* An example of class inheritance:
** The derived class inherits the members of the 
** base class as public members
*/

class base{
     int x;
public:
     void setx(int n) { x=n; };
     void showx(void) { cout << "x = " << x << endl; }
};

// Public Inheritance 
class derived : public base{
     int y;
public:
     void sety(int n) { y=n; }; 
     void showy(void) { cout << "y = " << y << endl; }
};

int main()
{
     derived ob;
     ob.setx(10);  // access member of base class
     ob.sety(20);  // access member of derived class
     ob.showx();   // access member of base class
     ob.showy();   // access member of derived class
     return 0;
}

Output:

x = 10
y = 20



