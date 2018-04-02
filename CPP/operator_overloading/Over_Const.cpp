


#include <iostream>

using namespace std;


#if 0
/* 
Constructors & Destructors Overloading 
Advantages : Allows initialized and uninitialized objects

A constructor has the same name as the class
A destructor has the same name as the class with added sign of negate.

*/



class power 
{
  int x;
  public : 
         power() {cout << "Non Para Constructor"<< endl;x=0;};        // Non Parameterised Constructor
         power(int n) {cout << "Para Constructor"<< endl;x = n;}  // Parameterised constructor 
         ~power() {cout << "Non Para Destructor"<< endl;x=0;};
      int getx() {cout << "X= " << x << endl; return x;}
      void setx(int i) {x =i;}
};

int main()
{
    
 int arr[5] = {12,13,14,15,16};   
 int i = 0;
 /* Create array of objects for the class power */
 power ofTwo[] = {1,2,3,4,5}; // Initialised objects 
 
 /* 
 When an object is created the constructor is called . For noninitialised array of objects 
 The Non Parameterised cconstructor is called 
 */
 power ofThree[5];            // Non initialised 
 
 /*
 Create an Pointer to class
 */
 power *p;
  
 ofThree[0].setx(10);
 ofThree[0].getx();
 
 /*
 Dynamically Allocate Memory 
 */
 
 try {
     /* allocate Memory dynamically here for objects of array */
     p = new power[5];
     }catch(bad_alloc xa)
     {     
     cout << "\n Allocation Failure " ;                
     return 1;                      
     }
     
     #if 1     
     /* Initialise the dynamically allocated array */
     for(i=0;i<5;i++)
     {
     p[i].setx(arr[i]);                                    
     } 
     cout << endl ; 
     for(i=0;i<5;i++)
     cout << "Val = " << p[i].getx() << endl;;
     #endif 


 cin.get();   
 return 0;   
}
#endif


/*
Copy Constructor 
One of the most important form of an overloaded constructor is copy constructor.
The copy constructor can help you to prevent problems that migth occur when one object tries to initialize another.
*/


class array
{
  /*
  
  Private Variables .
  
  */    
  
  int *p;                         // Pointer is Private 
  int size;                       // Private    
  
  public :
         // Constructor : Parameterised 
         array(int sz)
         {
             //Allocate Memory for an array of int of Size.      
             try{
                 
             p = new int[sz];    
             
             }catch(bad_alloc xa)                            
             {
                              
               cout << "\n Alloca Failure ";
               exit(EXIT_FAILURE);               
             }
             // Update size = sz
             size  = sz;                   
         }
         //call a destructor 
         ~array() { delete [] p; } 
      //Copy constructor          
      array(const array &a);
      
      
      void put(int i,int j)
      {
      if((i>=0) && (i<size) ) 
      p[i] = j;    
      }
      
      int get(int i)
      {          
      return p[i];    
      }
};


array :: array(const array &a) {
      
      int i;      
      try{
      p = new int[a.size];    
      }catch (bad_alloc xa){
             cout << "\n Allocation Failure ";
             exit(EXIT_FAILURE);             
             }
      for(i=0;i<a.size;i++)
      p[i] = a.p[i];      
      
      }

int main()
{
    array num(10);
int i;
for(i=0; i<10; i++) num.put(i, i);
for(i=9; i>=0; i--) cout << num.get(i);
cout << "\n";
// create another array and initialize with num
array x(num); // invokes copy constructor
for(i=0; i<10; i++) cout << x.get(i);

cin.get();    
return 0;    
}






