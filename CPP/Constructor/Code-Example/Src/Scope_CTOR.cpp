#include <iostream>
#include "Declare.h"
using namespace std;

Test :: Test()
{
cout << "\n DCTOR Called " << endl;
j=0;
cout << "\n Val J= " << j << endl;
}

Test :: Test(int i)
{
cout << "\n PCTOR Called " << endl;
this->j = i;
cout << "\n Val J= " <<this->j << endl;
}

virtual Test :: ~Test()
{
cout << "\n V DTOR Called " << endl;
}

int main()
{
Test Ob;
Test Ob1(2);



return 0;
}
