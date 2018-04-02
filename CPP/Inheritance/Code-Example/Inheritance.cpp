

/*
Include Header File
*/
#include <iostream>

using namespace std;



#define SAMPLE_1   0
#define SAMPLE_2   0
#define SAMPLE_3   0
#define SAMPLE_4   1



#if SAMPLE_1

#define SIZE 100

/* 
Class syntax 

class class_name
{
  private: 
           Variables
           Functions    
           
  public:         
           Variables
           Functions
      
};

*/

class stk
      {
      int stack[SIZE];
      int tos;      
  //    int func();
      public :
      void init();
      void push(int i);
      int pop();       
      };




//int func()
//{
//cout << " \n Calling the Private Function " << " \n ";    
//}

/*
Using Scope Resolution Operator.
The Scope resolution operator says the function belongs to the class.
*/

void stk :: init()
{
 
 tos = 0;    
  
}

void stk :: push(int i)
{
     
     if(tos == SIZE)
     {
     cout << "\n Stack Is Full " ;
     return ;
     }
     
 stack[tos] = i;
 tos++;         
  
}

int stk :: pop()
{
    if(tos == 0)
    {
    cout << "\n Stack Underflow " ;
    return 0;
    }
 cout << "\n Element Poped out of Stack = %d" << stack[tos];   
 return stack[tos--];   
     
}


int main()
{ 
    stk stk1,stk2;
 
    stk1.init();
    stk2.init();      
   
        
 return 0;   
}

#endif


#if SAMPLE_2

/*

One Way C++ Acheives Polymorphism is through the use of function overloading. 
Two or More functions can share the same name as long as there parameters declaration differs.
In this situation the functions that share the same name are said to be overloaded and the process is 
referred to as function overloading.

*/

int abs(int i);
double abs(double d);
long abs(long l);

int main()
{
    
 cout << abs(-10) << "\n" ;   
 
 cout << abs(-11.0) << "\n" ;   
 
 cin.get();
 
 return 0;
    
}


int abs(int i)
{
 
 cout << "Using int abs()\n";
 
 return i<0 ? -i : i;   
    
}

double abs(double d)
{
  cout << "Using double abs() \n ";

  return d < 0.0 ? -d : d;     
}


long abs(long l)
{
  cout << "Using long abs() \n";     

  return l < 0 ? -l : l ;     
     
}


#endif


/*

Polymorphism is also acheived through Operator Overloading. As you know in C++
it is possible to use the << & >> operators to perform conole I?O 
operations. They can perform these extra operations because in the IOStream
header these operators are overloaded.

*/


/*

Classes are created using keyword class.
A class declaration defines a new type tat links code and data
This new type is then used to declare objects of that class

class clas_name {      
      private data and functions.
      access-specifier:
                       data and function.
      access-specifier:
                       data and function.      
                 }obj_list;
                 
                 The obj-list is optional.                 


       Public,Private & Protected.                 
       #By default functions and data are declared within a class are private to that 
       Class and may be accessed only by other members of the class
                 
       The public access specifier allows function or data to be accessible to other parts of your program.
       The protected access specifier is needed only when inheritance is involved.                

*/

#if SAMPLE_3

class employee
{
 /* This are Private variables  */     
 char name[80];     
 
 /* 
 Private variable to hold Wage
 Can be accessed within the Public Function
 */ 
 double wage;
 
 public :
        void putname(char *n);
        void getname(char *n);
        void putwage(double w);
        double getwage();     
};

void employee :: putname(char *n)
{
strcpy(name,n);  
cout << "\n String = " << name << "\n";
}


void employee :: getname(char *n)
{
strcpy(n,name);     
cout << "\n String = " << n << "\n";     
}

void employee :: putwage(double d)
{
  wage = d;        
}

double employee :: getwage()
{
  return (wage);         
}

int main()
{
 char name[80];   
 double lwage;
 employee emp1,emp2;   
 cout << "\n Getting Started with C++ " ;  
 emp1.putname("Jones");
 emp1.getname(name);
 emp1.putwage(7500);
 lwage = emp1.getwage();
 cout << "\n Salary of Mr " << name << " is " << lwage << endl;
 
 cin.get();   
 return 0;   
}

#endif

/*
  
  Functions that are declared within the class are called member function.
  Member functions may access any element of the class of which they are a part.
  This includes all private elements.
  Variables that are elements of a class are called member variables or data members. 
  There are few restrictions that apply to class members. A non static member variable cannot have an initializer.  
  No member Can be declared as auto,extern or register.
                              
*/

/*

Structures and Classes

    The difference between class and struct is closer.                 
    By default all members are public in a struct and private in a class.
    

*/


#if SAMPLE_4

class building
{
/* Private variables of the class */
      
int rooms;
int floors;
int area;

public :
       
       int getfloors();
       void setfloors(int floor);
       int getarea();
       void setarea(int are);
       void setrooms(int room);
       int getrooms();             
      
};

/* data_type base_class name :: ( scope resolution operator ) func_name */
int building :: getfloors()
{
 return floors;       
}



void building :: setfloors(int floor)
{
 floors = floor;       
}


int building :: getarea()
{
 return area;       
}


void building :: setarea(int are)
{
  area = are;       
}

void building :: setrooms(int room)
{
  rooms = room;       
}


int building :: getrooms()
{
 return rooms;       
}


/*

class derived-class : access_specifier base_class
class house : public building

{                  
};

*/

/* House is derived from building */

class house : public building
{
  int bedrooms;
  int bathroom;
  
  public :         
         void set_bathroom(int num);
         int get_bathroom();
         void set_bedroom(int numm);
         int get_bedroom();    
      
};


void house :: set_bathroom(int num)
{
     bathroom = num;
}


int house :: get_bathroom()
{
    return bathroom;
}

void house :: set_bedroom(int numm)
{
    bedrooms = numm; 
}

int house :: get_bedroom()
{
    return bedrooms;
}



/* School is derived from building */

class school : public building 
{
  int classrooms;
  int offices;
  
  public :
         int set_offcies(int off);
         void get_office();    
         int set_classrooms(int cl_ro);
         void get_classroom();
      
};





int main()
{
 house h1;
 
 h1.set_bathroom(50);  
 h1.set_bedroom(25); 
 cout << "\n Bath room = " << h1.get_bathroom() << endl;  
 cout << "\n Bed room  = " << h1.get_bedroom() << endl;  
 cin.get();   
 return 0;   
}




#endif

























