#include <iostream.h>
/* An example of class inheritance:
** The derived class inherits the members of the 
** base class as private members - This program has errors!!
*/

class base{
     int x;
public:
     void setx(int n) { x=n; } 
     void showx(void) { cout << x << "\n"; }
};

// Private Inheritance
class derived : private base{
     int y;
public:
     void setxy(int n) { y=n; x=n; } // Error: private member of base
     void showxy(void) {
	cout << x  << "\n"; // Error: private member of base
	cout << y << "\n";
     }
};

int main()
{
     derived ob;
     ob.setxy(20);  // access member of derived class
     ob.showxy();   // access member of derived class
     return 0;
}

Output: 
jinx> g++ prog25.C
prog25.C: In method `void derived::setxy(int)':
prog25.C:18: member `x' is private
prog25.C: In method `void derived::showxy()':
prog25.C:20: member `x' is private

