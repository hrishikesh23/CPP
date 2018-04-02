#include <iostream>
#include "Daimond.h"

using namespace std;
int main()
{
Base1 Ob;
Base1 Ob1(1);
Derived1 Dob;
Base1 *ptr = &Dob;
Ob.show();
ptr->show();

Dob.show();

return 0;
}
