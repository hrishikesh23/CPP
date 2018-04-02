

/*


					CLASS B1	CLASS B2
					   |               |
					   |               |
					   |		   | 
					   |               |
					   |               |
					   ---> CLASS D <---
					   
*/


#include <iostream.h>
/* An example of multiple inheritance -
** Here a derived class inherits two base classes
*/

/* The first base class */ 
class B1 {
     /* By default this will be private member */		
     int a;
public:
     /* CTOR */	
     B1(int x) :  a(x) {}
     /* Public member function */
     int geta() { return a; }
};


/* The second base class */ 
class B2 {
     int b;
public:
     B2(int x) : b(x) {}
     int getb() { return b; }
};

/* Directly inherit base classes B1 and B2 */ 
class D : public B1, public B2 {
     int c;
public:
     /* Here z and y are passed directly to B1 and B2 */ 
     D(int x, int y, int z) : B1(z), B2(y), c(x) {}
     
/* Because bases are inherited as public, D has access to
** public members of B1 and B2
*/
     void show() {
          cout << geta() << ' ' << getb() << ' ';
          cout << c << '\n';
     }
};

int main()
{
     D ob(1, 2, 3);
     ob.show();
     
     return 0;
}

Output:

3 2 1




