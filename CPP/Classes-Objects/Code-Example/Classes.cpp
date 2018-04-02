

#include <iostream>

using namespace std;

/*
Understanding Classes and its Syntax :

Head :

--> Name of the class.   

Body :

--> We have Data Members.
	Local data members can be declared.

--> We have Data functions.
	This binds the functions and data members together.

--> we have Access Specifiers.
	This helps in Providing data abstraction.

--> we can have static members.
	we can have this for specific requirements

--> We can have CTOR/DTOR.
	This will overcome the initialisation and de-initialisation issues.

--> class is a Logical structure.

--> Class cannot be virtual.


*/


//Head of the class
class Employee
{
//By default we have private access Specifier

private :

int Emp_sts;
int Emp_ID;
char Emp_name[80];


public :

//Ctor is member function
Employee() 
{

cout << "constructing the class " << endl;

}
//destructor is member function
~Employee()
{

cout << " destructing the class " << endl;

}
void set_ID(int i)
{

cout << " setting iD " << endl;

}

void setname()
{

cout << " setting name " << endl;

}

//just a declaration
void Display_sts();


};//ends with semicolon.
//class declaration ends here . the above is called logical binding

void Employee :: Display_sts()
{

cout << " Sts of Employee" << endl;

}



//Main Program


int main()
{

cout << "\n\n" << endl;

Employee Hrishi;

cout << " In Main Program " << endl;

Hrishi.Display_sts();

}

