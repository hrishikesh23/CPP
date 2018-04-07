
/*
In the below Program we will simplify the use of static variable in CPP.
-> Static Variable is class level variable
-> Static Varibale Can be Private
-> If variable declared as Private cannot be access outside the class and needs methods to be declared to access
-> Variable cannot be declared and initialized at same time
-> Variable can be even Public We have other example to explain accessing methods and rules.
*/


#include <iostream>


using namespace std;

// Static Variable for test
class SVarTest
{

// Private variable Declaration
private:

	int x;
	int y;
// We here have public variable/methods declaration
public:

	static int z;	// We can only have decalration of static variable inside class
			// We cannot define static variable as well as declare it at one time

	// Constructor for Class
	SVarTest(int x,int y)
	{
	cout << "Ctor of the class" << endl;
	this->x = x;
	this->y = y;
	z = 0; 			// you can initialize static variable inside class
	}

	
	// Constructor for Class
	~SVarTest()
	{
	cout << "\n Dtor for the class \n" << endl;
	}

	// Display the contents of the Private and static Variable
	void Display()
	{
	cout << " X = y = z =" << x << y << z <<endl;
	}


}; // End of class 

// We need to have declaration of the static variable here with class level declaration
int SVarTest:: z;


int main()
{

SVarTest Var(10,11);
Var.Display();
SVarTest::z = 20;     // Here we can access the static variable using class level access specifier
		      		
Var.Display();
}
