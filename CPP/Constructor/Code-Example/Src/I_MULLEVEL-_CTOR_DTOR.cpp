//http://www.umsl.edu/~subramaniana/inherit2.html
#include <iostream>
/* An example of multi-level inheritance hierarchy -
** Here a derived class inherits a base class
** and then serves as base class for a second
** derived class
*/

using namespace std;

class B1 {
     int a;
public:
     B1(int x) : a(x) {};
     int geta() { return a; }
};

// Inherit direct base class B1
class D1 : public B1 {
     int b;
public:
     D1(int x, int y) : B1(y),   // pass y to base class B1
                        b(x) {}; // pass x to data member b
     int getb() { return b; }
};

// Inherit a derived class D1 and indirect base class B1
class D2 : public D1 {
     int c;
public:
     D2(int x, int y, int z) : D1(y, z), c(x) {}; // pass args to D1

/* Because bases are inherited as public, D2 has access to
** public members of B1 and D1
*/
     void show() {
          cout << geta() << ' ' << getb() << ' ';
          cout << c << '\n';
     }
};

int main()
{
     D2 ob(1, 2, 3);
     ob.show();
     // geta() and getb() are still public here
     cout << ob.geta() << ' ' << ob.getb() << '\n';

     return 0;
}


