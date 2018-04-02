


/*
Understanding :
              
              When i create an object of derived class without creating an object of base class/vice versa the 
              Constructor of base class is called and the virtual function within the base class is only called and not from
              the derived class.
              Output :
    
                     Base::B()
                     Virt Base
                     Der::C()
                     Virt Der                 

*/

#include <stdio.h>

#include <conio.h>

#include <iostream>

using namespace std;

class B
{

int i;

public :
       B() {cout << "\n Base::B()"; virt(); }
       virtual void virt()
       {
        cout << "\n Virt Base";       
       }
      
};

class C : public B
{
int x;
public :
       C() {cout << "\n Der::C()"; virt(); }      
       virtual void virt()
       {
        cout << "\n Virt Der";       
       }
      
};



int main()
{
   C D1; 
   getch(); 
return 0;    
}
