#include <iostream>

using namespace std;

class base_tricky1
{
private :
char *tricky1;
public:
	base_tricky1()  { cout << "\n def Ctor" << endl ;}
	~base_tricky1() { cout << "\n def Dtor" << endl ;}

};


int main()
{
base_tricky1 obj1;
base_tricky1 obj2 = obj1;

return 0;
}

/*
//output

linux@linux-HP-G42-Notebook-PC:~/Practise/C++/CTOR$ g++ tricky1.cpp
linux@linux-HP-G42-Notebook-PC:~/Practise/C++/CTOR$ ./a.out 

 def Ctor

 def Dtor

 def Dtor
*/
/*
http://www.keithschwarz.com/cs106l/winter20072008/handouts/170_Copy_Constructor_Assignment_Operator.pdf 
Because we havent provided a copy ctor , c++ will initialize obj2.tricky1 to obj1.tricky1. tricky1 is a char ptr instead of getting a deep copy of the string we will end up with the two pointers to the same C string. thus changes to one will show up in two and vice versa. this is dangerous, especially when the destructors for both one and two try to deallocate the memory for tricky1 ptr.

In such cases you need to override c++ default behaviour by providing your own copy ctor & assignment operator.

The rule of three :

 If a class has destructor it should have copy ctor & assignment operator



Problem statement :

1. On Execution of "base_tricky1 obj1;" def ctor will be called memory will be allocated to pointer . some location "0x100".
2. On execution of "base_tricky1 obj2 = obj1;" def copy ctor will be called and hence the copy operation will be performed. 

i.e obj2.trick1 = obj1.tricky1 will be performed.
Now both obj points to same pointer location i.e 0x100 .
when dtor of one object is called, the memory is freed & hence when second time dtor is called again the same location is tried to destruct.
which is dangling pointer.

*/

