

#include <iostream>

using namespace std;

/* 
Basic Example Demonstration for CTOR : DTOR

Constructor :
	> Is called Automatically.
 	> When object is created.
	> Performs Initialisation of Variables.
	> Ctor Does Not return Anything
	> Types of CTOR : Default - Copy - Assignment Operator
	> There is No virtual CTOR
	> Cannot be called Explicitly by Programmer

Destructor : 
 	> Is called when object goes out of Scope 
	> or can be called Explicitly
	> DTOR does not return anything
	> there is a Virtual DTOR



1. Create A Class 
2. Declare & Define A CTOR / DTOR in Public scope
3. Create an Object in Main : whicl calls CTOR. 

	> Perform Initialisation
	> Calls DTOR when out of Scope



*/

class A
{
private :
int j;

	public :
	A() {cout << "\n In Def CTOR";}
	~A() {cout << "\n Def DTOR";}
};


int main()
{
/* Create An obj of class A */
	A B;

}
