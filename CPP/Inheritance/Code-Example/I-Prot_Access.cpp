#include <iostream.h>
/* This program illustrates how public, private
** and protected members may be accessed
*/
 
class samp {
     int a;
protected:
     int b;
public:
     int c;
     samp(int n, int m, int p=0) :  a(n), b(m), c(p) {};
     int geta() { return a; }
     int getb() { return b; }
};

main()
{
     samp ob(10, 20);
     ob.b = 99; // Error! b is protected, thus inaccessible from main() 

     cout << ob.geta() << "\n";
     cout << ob.getb() << "\n";
     cout << ob.c << "\n";
}

Output:
jinx> g++ prog27.C
prog27.C: In function `int main()':
prog27.C:20: member `b' is a protected member of class `samp'

