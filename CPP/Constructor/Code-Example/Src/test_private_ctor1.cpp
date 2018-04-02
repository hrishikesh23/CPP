
#include <iostream>
#include "class_1.h"
#include <conio.h>
using namespace std;

/* Access Static Pointer using Class Name [Scope Resolution Operator ]*/
aTestClass* aTestClass::Instance = NULL;

aTestClass* aTestClass::getAnObject()
{
    char flag = 0;        
    if(!Instance)
    {
        flag = 1;           
        cout << "Creating New Instance " << endl;             
        Instance = new aTestClass;
    }
    if(!flag)
    cout << "Returning Same Instance" << endl;
    return Instance;
}

void aTestClass::ResetAnObject()
{
   cout << "Free Instance" << endl;         
   delete Instance;            
}

int main()
{
    aTestClass *anObject=NULL;
    for(int i = 0;i<7;i++)
    {
    anObject = anObject->getAnObject();
    }            
    anObject->ResetAnObject();
    cout << "Creating Derived Class Object" << endl;
    bTestClass obj1;            
    cin.get();
}


