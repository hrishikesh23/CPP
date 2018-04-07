#include <iostream>



// Virtual function declaration looks like function overloading 
// But it is not the same. Here we cannot have function with different arguments
// Virtual function should be non-static members of the class
// They cannot be friends
// Finally ctor function cannot be virtual and destructor can be
// if we do not over ride function of base class in derived then the base class virtual function will be called

using namespace std;

// We have a base class with Virtual function declarationa and defination 
class base {

	// Public Member functions
	public:
	// Virtual function declared and defined with virtual keyword
	virtual void vfunc() {
	cout << "This is base's vfunc().\n";
	}

}; // End of Class


// Derived class from base class with access specifier as public
class derived1 : public base {

	public:
	// We have Virtual function modified in derived class 
	void vfunc() {
	cout << "This is derived1's vfunc().\n";
	}

};// End of class

// Derived class from base class with access specifier as public
class derived2 : public base {

	public:
	// We have Virtual function modified in derived class 
	void vfunc() {
	cout << "This is derived2's vfunc().\n";
	}

};// End of class



int main()
{

// Now let's declare the required variables for demo
// Declare a base class pointer and create an instance of base class

base *p1,obj;
derived1  d1;
derived2  d2;
// Assign base pointer with base class object
p1 = &obj;
p1->vfunc();

// Assign base derived1 class object to base pointer 
p1 = &d1;
p1->vfunc();

// Assign base derived2 class object to base pointer
p1 = &d2;
p1->vfunc();


}


