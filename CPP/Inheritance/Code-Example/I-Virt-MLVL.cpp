
#include <iostream.h>
/* This program illustrates the use
** of a virtual class
*/
class base {
     int i;
public:
	base(int x) : i(x) {}
	int geti() { return i; }
};

class derived1 : virtual public base {
     int j;
public:
	derived1(int x, int y) : base(x), j(y) {}
	int getj() { return j; }
};

class derived2 : virtual public base {
     int k;
public:
	derived2(int x, int y) : base(x), k(y) {}
	int getk() { return k; }
};

/* Here derived3 inherits base from derived1 and derived2
** however, only one copy of base is inherited by derived3
** Also, derived3 must initialize its two immediate base
** classes - derived1 and derived2.  In addition, it must
** also initialize base, because the shared virtual base class
** must be initialized by the most derived class in the
** hierarchy
*/
class derived3 : public derived1, public derived2 {
public:
	derived3(int x, int y, int z) : derived1(x, y), derived2(x, z), base(x) {}
        int product() { return (geti()*getj()*getk()); }
};

int main()
{
	derived3 ob(10, 20, 30);
	cout << "Product is: " << ob.product() << "\n";

	return 0;
}

Output:

Product is: 6000


