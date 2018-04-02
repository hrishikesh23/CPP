
#include <conio.h>
/*
http://books.google.co.in/books?id=8uszuvNpFy0C&pg=PA154&lpg=PA154&dq=restriction+with+references+in+c%2B%2B&source=bl&ots=p0KRbz0J-a&sig=qmd-sYZce9x4dmEXP1F2S-6-Rqc&hl=en&sa=X&ei=mUuLUa3dF4eFrAfcs4HQAg&ved=0CCwQ6AEwAA#v=onepage&q=restriction%20with%20references%20in%20c%2B%2B&f=false

C++ contains an feature that is related to pointer : reference.
Reference is an implicit pointer that for all intents and purposes acts like another name for variable.

Three ways reference can be used 
1. Reference can be passed to a function.
2. Reference can be returned by a function.
3. Finally an independent refernce can be created.

1. You cannot have NULL reference.
2. Once a reference is initialized to an object, it cannot be changed to refer to another object. Pointers can be pointed to another object at any time.
3. You cannot reference another refernce
4. You cannot obtain addres of reference[True] 
5. You cannot create an array of reference[True]
6. You cannot reference a bit field[True]
7. References Must be initialised unless they are members of a class or are return values or function parameters.

*/

#if 0
using namespace std;
//to declare a reference value or parameter you precede the variable name 
//with &. This is how n is declared as a parameter to f().
void f(int &n);

/*
why there is no need to write & when you are passing a variable
when you declare an function to receive reference . there is no need 
necessity to apply * or &.
instead each time n is used within f() it is automatically treated as pointer
to the argument used to call f(). this means that the statement 
n = 100;
actually puts the value 100 into the variable used to callf() which 
in this case is i.
further when f() is called there is no need to precede the argument 
with the &. f() is declared as taking a reference parameter, the address 
to the argument is automatically passed to f();

To review when you use a reference parameter. the compiler automatically passes the 
address of the variable used as argument. There is no need to generate manually the 
address of the argument preceding it with an &(in fact it is not allowed)
reference parameter thus fully automate the call by reference parameter 
mechanism.

***************************
it is important to understand that you cannot change what reference is pointing
to 
n++;


where put inside f() in the preceding program n would still be pointing 
to i in main. Instead of increamenting n. this statement increaments the value of the va
variable being referenced.

Reference parameter offer several advantages over the pointer alternative
> No need to remain the address of the variable to be passed 
> when object is passed to a function as a reference no copy is made.

this is one way to eleminate the trouble associated with copy of an argument
damaging something needed.

when a object is passed to a function by use of the default call-by-val parameter 
passing mechanism. A copy of that object is made. Althoug the parameter construtor 
fucntion is not called its detructor function is called.[calls the default copy ctor
internally if default copy ctor is not written can lead into serioous problem]

when you pass the object by reference no copy is made and hence no dtor funciton is called

its critical to undertand that the reference is not pointer. therefore when object is
is passed by reference the member access operator remains the dot operator.






****************************




*/ 


int main()
{
    
  int i = 0;
  f(i);
    
  cout << "\n here is new value " << i << endl;   
return 0;    
}

void f(int &n)
{
n = 100;     
}


#endif


#if 0
#include<iostream>

using namespace std;


int main()
{
 int i = 20;
 int y = 30;
 
 /* Creating an array of reference */

 
 /* You cannot intialise a reference to NULL [ Works : No Manipulation observed ] */
 /* when a reference is declared and initialised with object. the object contains the value pointed to the reference [Manipulation observed in the Rule ]*/
 /* A reference must be initialised when it is created [ Works : No Manipulation observed ]*/
 
 
 int& x = i;  //Creating an independent reference and intialised it.
 
// cout << "\n Printing array content " << endl;
// cout << "Arr[0]" << arr[0] << endl;
 
 cout << "\n Address of Ref = " << &x << endl;
 cout << "\n Address of i   = " << &i << endl;
 cout << "\n Data of Ref    = " << x << endl;
 cout << "\n Data of i      = " << i << endl;
 cout << "\n Trying to Modify refernced object (x=y) " << endl;
 x =y;
 //The independent reference x serves as the different name for y. 

 cout << "\n Address of Ref = " << &x << endl;
 cout << "\n Address of y   = " << &y << endl;
 cout << "\n Data of Ref    = " << x << endl;
 cout << "\n Data of y      = " << y << endl;
 cout << "\n Data of Z      = " << *z << endl;
 
 
 
 cin.get();   
 return 0;   
}
#endif

#include<iostream>

using namespace std;

#if 0
int main()
{
 int i = 20;
 int y = 30;
 
 /* You cannot intialise a reference to NULL [ Works : No Manipulation observed ] */
 /* when a reference is declared and initialised with object. the object contains the value pointed to the reference [Manipulation observed in the Rule ]*/
 /* A reference must be initialised when it is created [ Works : No Manipulation observed ]*/
 
 //declare const to restrict from modifying the reference 
 const int& x = i;  //Creating an independent reference and intialised it.

 cout << "\n Address of Ref = " << &x << endl;
 cout << "\n Address of i   = " << &i << endl;
 cout << "\n Data of Ref    = " << x << endl;
 cout << "\n Data of i      = " << i << endl;
 cout << "\n Trying to Modify refernced object (x=y) " << endl;
 
 //Now using the const_cast to change the value pointed by reference
 int *z = const_cast<int*>(&x);   
 (*z)++; 


 cout << "\n Address of Ref = " << &x << endl;
 cout << "\n Address of i   = " << &i << endl;
 cout << "\n Data of Ref    = " << x << endl;
 cout << "\n Data of i      = " << i << endl;
 cout << "\n Address of Z   = " << &z << endl;
 cout << "\n Data of Z      = " << *z << endl;
 
 
 
 cin.get();   
 return 0;   
}

#endif 

#if 0
//Reference cannot be initialised with Const
int main()
{
 const int i = 20;
 int y = 30;
 
 /* You cannot intialise a reference to NULL [ Works : No Manipulation observed ] */
 /* when a reference is declared and initialised with object. the object contains the value pointed to the reference [Manipulation observed in the Rule ]*/
 /* A reference must be initialised when it is created [ Works : No Manipulation observed ]*/
 
 //declare const to restrict from modifying the reference 
 int& x = i;  //Creating an independent reference and intialised it.

 cout << "\n Address of Ref = " << &x << endl;
 cout << "\n Address of i   = " << &i << endl;
 cout << "\n Data of Ref    = " << x << endl;
 cout << "\n Data of i      = " << i << endl;
 cout << "\n Trying to Modify refernced object (x=y) " << endl;
 
 //Now using the const_cast to change the value pointed by reference
 int *z = const_cast<int*>(&x);   
 (*z)++; 


 cout << "\n Address of Ref = " << &x << endl;
 cout << "\n Address of i   = " << &i << endl;
 cout << "\n Data of Ref    = " << x << endl;
 cout << "\n Data of i      = " << i << endl;
 cout << "\n Address of Z   = " << &z << endl;
 cout << "\n Data of Z      = " << *z << endl;
 
 
 
 cin.get();   
 return 0;   
}
#endif


class A
{
  int i;
  public :
         A() {cout << "\n Def Ctor called " << endl ;}
         A(const A& n) {cout << "\n Copy ctor called " << endl;}
         void set_val(int i){cout << "\n In set val" << endl;}           
         ~A() {cout << " Def Dtor called " << endl; }
};


#define ENABLE 0
void Func_obj(A d)
{
     cout << "\n Pass By Obj" << endl;
}


void Func_ref(A& c)
{
//c.set_val(7);   
     cout << "\n Pass By Ref" << endl;
#if 0
c = c*3;
cout << "\n What's Wrong " << c << endl;  
#endif

}

int main()
{
 int *p; //hold the address of reference   
 int i = 20;
 int y = 30;
 int& num = y;
 int ch = 0;
 //
 A B;
 /* You cannot intialise a reference to NULL [ Works : No Manipulation observed ] */
 /* when a reference is declared and initialised with object. the object contains the value pointed to the reference [Manipulation observed in the Rule ]*/
 /* A reference must be initialised when it is created [ Works : No Manipulation observed ]*/

 //int& arr[10] = {&i,&y};
 
 cout << " \t : Restrictions With Reference :" << endl;
 cout << " > You cannot get an address of reference " << endl;
 cout << " > You cannot create an Array of reference int& arr[10] Not allowed " << endl;
 cout << " > You cannot have NULL references ==> int& p = 0;" << endl;
 cout << " > References should be intialised when they are declared " << endl;
 cout << " > You cannot reference another refernce " << endl;
 cout << " > When Reference is Init it cannot be changed to refer to another object [Manipulated]" << endl; 
 cout << " > Declaring const reference and amnipulating it through const_cast " << endl;
 cout << " > References Must be initialised unless they are members of a class or are return values or function parameters " << endl;
 //declare const to restrict from modifying the reference 
 
 #if !ENABLE
 /*  reference variable should not be initialised with const . As they may perform operation on reference and which may lead to exception */
 const int& x = i;  //Creating an independent reference and intialised it.
// int &const x = i;  //Creating an independent reference and intialised it.
 cout << "\n Enabling the Const Part "<< endl;
 #else
 cout << "\n Disbling the Const Part "<< endl;
 int& x = i;
 #endif 
 cout << "\n Address of Ref Var x = " << &x << endl;
 cout << "\n Address of i         = " << &i << endl;
 cout << "\n Data of Ref Var x    = " << x << endl;
 cout << "\n Data of i            = " << i << endl;

 #if !Enable
 cout << "Removing the Constant ness and Modifying "<<endl;  
 //Now using the const_cast to change the value pointed by reference
 int *z = const_cast<int*>(&x);   
 (*z)++; 
 cout << "\n Address of Ref Var x = " << &x << endl;
 cout << "\n Address of i         = " << &i << endl;
 cout << "\n Data of Ref Var x    = " << x << endl;
 cout << "\n Data of i            = " << i << endl;
 cout << "\n Address of Z         = " << &z << endl;
 cout << "\n Data of Z            = " << *z << endl; 
 #else 
 x =y;
 cout << "\n Trying to Modify refernced object (x=y) " << endl; 
 cout << "\n Address of Ref Var x = " << &x << endl;
 cout << "\n Address of y         = " << &y << endl;
 cout << "\n Data of Ref Var x    = " << x << endl;
 cout << "\n Data of y            = " << y << endl;  
 #endif
  
 cout << "\n Can i hold the address of ref "<< endl;
 p = (int*)&x;
 if(p == &i)
 {
 cout << "\n No You can't" << endl;     
 cout << "\n Address of reference  = " << p << endl;
 }
 else
 {
 cout << "\n Address of reference  = " << p << endl;
 }
 Func_ref(B);
 
 cin >>  ch;
 cout << " \n Choice " << ch;
 switch(ch)
 {
 case 1 :
      {
      cout << "\n Illustrating Example Pass by value" << endl;
      Func_obj(B);
      }
      break;
      
 case 2 :
      {
      Func_ref(B);      
      cout << "\n Illustrating Example Pass by reference" << endl;
      }
      break;
      
 case 3 :
      {
      /*
      A function can return a refrence . Returning refernce can be very useful when you are overloading 
      certain types of operator. however
      */      
      cout << "\n Illustrating Example returning reference" << endl;      
      }
      break;            
            
 }
 getch();
 cin.get();   
 return 0;   
}



#if 0

/* Modifying a const reference */
#include <iostream>
using namespace std;

void f(const int& x) {
  int* y = const_cast<int>(&x);
  (*y)++;
}

int main() {
  int a = 5;
  f(a);
  cout << a << endl;
}
#endif



#if 0
References ::
http://publib.boulder.ibm.com/infocenter/lnxpcomp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8l.doc%2Flanguage%2Fref%2Fcplr233.htm 
#endif
