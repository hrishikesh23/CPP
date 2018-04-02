
#include <iostream>
#include <conio.h>
using namespace std;
class Box
{
double width;
public :
double length;
friend void print(Box box);  /* declare freind function */
void SetWidth(double Wid);
};
/* 
SetWidth is A Member function and hence need to be defined through ::(scope resolution operator) using syntax return_type  class_name : : func_name(){}
*/
void Box :: SetWidth(double wid)
{
width = wid;
}
//Note print is not a member function
void print(Box box)
{
cout << "\n width =  " <<box. width << endl;
}
int main()
{
Box box;
box.SetWidth(800);
print(box);
cin.get();
return 0;
}
