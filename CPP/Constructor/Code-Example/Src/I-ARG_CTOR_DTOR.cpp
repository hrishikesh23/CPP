//http://www.umsl.edu/~subramaniana/inherit2.html
#include <iostream>
/* This program illustrates how to pass arguments
** to a base class's constructor and a derived 
** class's constructor - here different values are passed
** to the base class and the derived class
*/

using namespace std;

class base {
     int i;
public:
     base(int n) : i(n)
     {
          cout << "Constructing base ...:\n";
          cout << "i = " << i << "\n";
     }
     ~base() { cout << "Destroying base ...:\n"; }
     void showi() { cout << i << "\n"; }
};

class derived : public base {
     int j;
public:
     derived(int n, int m) : base(m), j(n) /* pass arg to base class
                                           ** and data member of derived */
     {
           cout << "Constructing derived class...:\n";
           cout << "j = " << j << "\n";
     }

     ~derived() { cout << "Destroying derived class...:\n"; }
     void showj() { cout << j << "\n"; }
 };

int main()
{
     derived ob(10, 20);
     ob.showi();
     ob.showj();

     return 0;
}
