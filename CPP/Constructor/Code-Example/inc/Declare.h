#ifndef DECLARE_H
#define DECLARE_H
#include <iostream>
using namespace std;
class Test
{
private :
int j;

public :
/* default CTOR */
Test();
/* Par CTOR */
Test(int j);
virtual ~Test();
void show() {cout << "\n in func Declare.h ";}
};

#endif

