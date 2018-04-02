#include <iostream.h>
#include <string.h>
/* This program illustrates how derived classes
** redefine member functions of their base class
*/

class Employee {
     char name[20];
public:
     Employee(char* str){ strcpy(name, str); }
     int Print() { cout << name << endl; }
};

class Secretary : public Employee {
     char designation[20];
public:
     Secretary(char* str): Employee("Jane Doe"){ strcpy(designation, str); }
     int Print() { 
	  	 Employee::Print(); // Access Base class member Print()  
     		 cout << designation << endl;
     }
};

int main()
{
     Employee EmpObject("John Doe"); // object of type Employee
     Secretary SecObject("Wordprocessor II"); // object of type Secretary

     EmpObject.Print(); // access Employee object's member function
     cout << endl;
     SecObject.Print(); // access Secretary object's member function
     cout << endl;
     SecObject.Employee::Print(); // access Secretary object's base member function
 
     return 0;
}

Output:

John Doe

Jane Doe
Wordprocessor II

Jane Doe
