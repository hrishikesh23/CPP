

#include <iostream>


/*
What is an Interface ?

An Interface defines the behaviour or capabilities of a C++ class without committing to a particular implementation of that class.
A C++ interface is implemented using an abstract class and these abstract class should not be confused with data abstraction which is a concept of keeping implementation detail seperate from associated data.

==> A class is made abstract by declaring atleast one Pure virtual function.

E:g virtual void get_volume() = 0;

==> Abstract class cannot be used to instantiate objects and serves only as interface.

==> If a subclass of an ABC needs to be instantiated, it has to  implement each of the virtual functions. which means that it supports the interface declared by the ABC.

==> Failure to override an Pure virtual function in the derived class,then attempting to instantiate objects of that class is a compilation ERROR.


Classes that can be used to instantiate objects are called concrete objects.

Abstract class Example :


*/



int main()
{


return 0;
}
