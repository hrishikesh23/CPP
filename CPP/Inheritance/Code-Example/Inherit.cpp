#include <iostream>
#include <conio.h>

using namespace std;

class A
{
int i;
public :
virtual void set(int i);
int  get(int i)
{
return i;
}
};//Class defination ends here

class B : public A
{
int j;
public:
void set_b(int i)
{
cout << "\n In Set func Class B";
}
//Create an object of class A here..to access elements of class A from B
//A x;
};

/* Implementation of functions */
void A :: set(int i)
{
cout << "\n In set Function Class A";
}
int main()
{
/* create an onject of class B*/
B obj;
/* How to access the elements of class A using object x */
obj.set(5);

getch();
return 0;
}

#if 0

class A
{
int i;
public :
void set(int i);
int  get(int i)
{
return i;
}
};//Class defination ends here
class B
{
int j;
public:
void set_b(int i)
{
cout << "\n In Set func Class B";
}
//Create an object of class A here..to access elements of class A from B
A x;
};
/* Implementation of functions */
void A :: set(int i)
{
cout << "\n In set Function Class A";
}
int main()
{
/* create an onject of class B*/
B obj;
/* How to access the elements of class A using object x */
obj.x.set(5);
getch();
return 0;
}

#endif
