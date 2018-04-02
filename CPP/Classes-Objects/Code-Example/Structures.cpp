

#include <iostream>
#include <cstring>

using namespace std;

//Let's declare a structur here

struct Employee
{

int Emp_Id;
char Name[80];
void Display();

};


struct Employee Hrishi;

//usage of the function : dispay the content of instance hrishi
void Display()
{

cout << "employee ID is " << Hrishi.Emp_Id << endl;

}

int main()
{


//Now lets start creating an instance of the structure 

//struct Employee Hrishi;

Hrishi.Emp_Id = 23;

Display();

cout << " hello world " << endl;

}
