

/*
>> Private CTOR is used in Classes that contains static Members only.
>> If a class has one or more private constructors and no public constructors, other classes (except nested classes) cannot create instances of this class.


>> Private constructors are used to prevent creating instances of a class when there are no instance fields or methods, such as the Math<http://msdn.microsoft.com/en-us/library/system.math.aspx>[http://msdn.microsoft.com/en-us/library/system.math.aspx] class, or when a method is called to obtain an instance of a class. If all the methods in the class are static, consider making the complete class static. For more information see Static Classes and Static Class Members (C# Programming Guide)<http://msdn.microsoft.com/en-us/library/79b3xss3.aspx>.[ http://msdn.microsoft.com/en-us/library/79b3xss3.aspx].

>> Your class is a singleton. This means, not more than one instance of your class exists in the program.



Examples : Inheriting Base Class with Private CTOR.
 Why Private CTOR ? 
 >> Restricing an Object Creation
 >> For Singleton Patterns
 >> Restricting Certain type of CTOR
*/


#include <iostream>
#include "class.h"
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

int main()
{
    for(int i = 0;i<7;i++)
    {
    aTestClass *anObject=NULL;
    anObject=anObject->getAnObject();
    }
    cin.get();
}


