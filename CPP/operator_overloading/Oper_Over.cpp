#include <iostream>

using namespace std;

/*

http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Logical_operators
http://www.cs.ucr.edu/~lyan/c++interviewquestions.pdf
http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm#examples


  Understanding Operator overloading 
  Understanding Friend Function 
  

  Syntax :
       
       ret_type class_name :: operator#(arg-list)
       Operator functions return an object of the class they operate on but return type can be of valid type.
       The # is the place holder. When you create an operator function substitute the # with the operator.
       If you are declaring the operator overloading for / then write operator/
              
       when you are overloading operator with unary operator arg_list will be empty.
       when you are overloading with binary oparators. arg_list will contain one parameter              

*/
#if 0

class loc{
      int latitude,longitude;
      
      public :
             /* Constructor Needed for Temporary variables */
             loc() {};
             /* Parameterised Constructor */
             loc(int lat,int log)
             {
             cout << "\n Parameter " ;       
             latitude = lat;       
             longitude = log;       
             }
             /* Display the value of Lat & Long*/
             void show()
             {
             cout << endl;     
             cout << " Long " << longitude <<  endl;
             cout << " Lat " << latitude <<  endl;                                   
             }
             
             loc operator+(loc op2);                          

      };      
      
      loc loc :: operator+(loc op2)
      {
      loc temp;
      //op2.longitude points to ob3      
      temp.longitude = op2.longitude + longitude;
      //op2.lotitude points to ob3
      temp.latitude = op2.latitude + latitude;
      return temp;              
      }

int main()
{
 loc ob1(10, 20), ob2( 5, 30), ob3(90, 90);   //Invokes parameterised constructor 
 
 //ob3 is passed as argument 
 //ob2 is used as this operator 
 ob1 = ob2+ob3; 
 ob1.show();
 cin.get();   
 return 0;   
}
#endif

#if 0

// friend functions

class CRectangle {
    int width, height;
  public:
    void set_values (int, int);
    int area () {return (width * height);}
    friend CRectangle duplicate (CRectangle);
};

void CRectangle::set_values (int a, int b) {
  width = a;
  height = b;
}

CRectangle duplicate (CRectangle rectparam)
{
  CRectangle rectres;
  rectres.width = rectparam.width*2;
  rectres.height = rectparam.height*2;
  return (rectres);
}

int main () {
  CRectangle rect, rectb;
  rect.set_values (2,3);
  rectb = duplicate (rect);
  cout << rectb.area();
  cin.get();
  return 0;
}

#endif


/*

Operator overloading restriction 
1. You cannot alter the precedence of operator .
2. You cannot change the number of operands that an operator takes 
3. You cannot overload this operators : . :: .* ?

*/
#if 0
#include <iostream>
using namespace std;
 
class Box
{
   double length;      // Length of a box
   double breadth;     // Breadth of a box
   double height;      // Height of a box
public:
 
   double getVolume(void)
   {
      return length * breadth * height;
   }
   void setLength( double len )
   {
       length = len;
   }
 
   void setBreadth( double bre )
   {
       breadth = bre;
   }
 
   void setHeight( double hei )
   {
       height = hei;
   }
   // Overload + operator to add two Box objects.
   Box operator+(const Box& b)
   {
      Box box;
      box.length = this->length + b.length;
      box.breadth = this->breadth + b.breadth;
      box.height = this->height + b.height;
      return box;
   }
};
// Main function for the program
int main( )
{
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // box 2 specification
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
 
   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;
 
   // Add two object as follows:
   // Box1 is passed as this operator.       
   Box3 = Box1 + Box2;
 
   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;
   cin.get();
   return 0;
}

#endif

#if 0

class Distance
{
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
   public:
      // required constructors
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      // method to display distance
      void displayDistance()
      {
         cout << "F: " << feet << " I:" << inches <<endl;
      }
      // overloaded minus (-) operator
      Distance operator- ()  
      {
         feet = -feet;
         inches = -inches;
         return Distance(feet, inches);
      }
};

int main()
{
Distance D1(11, 10), D2(-5, 11);
 
   -D1;                     // apply negation
   D1.displayDistance();    // display D1

   -D2;                     // apply negation
   D2.displayDistance();    // display D2


cin.get();    
return 0;    
}


#endif

#if 0

class Distance
{
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
   public:
      // required constructors
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      // method to display distance
      void displayDistance()
      {
         cout << "F: " << feet << " I:" << inches <<endl;
      }
      // overloaded minus (-) operator
      Distance operator- ()  
      {
         feet = -feet;
         inches = -inches;
         return Distance(feet, inches);
      }
      // overloaded < operator
      bool operator <(const Distance& d)
      {
         if(feet < d.feet)
         {
            return true;
         }
         if(feet == d.feet && inches < d.inches)
         {
            return true;
         }
         return false;
      }
};
int main()
{
   Distance D1(11, 10), D2(5, 11);
   /* 
   D1 is passes as this operator 
   Right Side operator is passed as reference object
   */ 
   if( D1 < D2 )
   {
      cout << "D1 is less than D2 " << endl;
   }
   else
   {
      cout << "D2 is less than D1 " << endl;
   }
   
   cin.get();
   return 0;
}


#endif

#if 0

class Time
{
   private:
      int hours;             // 0 to 23
      int minutes;           // 0 to 59
   public:
      // required constructors
      Time(){
         hours = 0;
         minutes = 0;
      }
      Time(int h, int m){
         hours = h;
         minutes = m;
      }
      // method to display time
      void displayTime()
      {
         cout << "H: " << hours << " M:" << minutes <<endl;
      }
      // overloaded prefix ++ operator
      Time operator++ ()  
      {
         ++minutes;          // increment this object
         if(minutes >= 60)  
         {
            ++hours;
            minutes -= 60;
         }
         return Time(hours, minutes);
      }
      // overloaded postfix ++ operator
      Time operator++( int )         
      {
         // save the orignal value
         Time T(hours, minutes);
         // increment this object
         ++minutes;                    
         if(minutes >= 60)
         {
            ++hours;
            minutes -= 60;
         }
         // return old original value
         return T; 
      }
};
int main()
{
   Time T1(11, 59), T2(10,40);
 
   ++T1;                    // increment T1
   T1.displayTime();        // display T1
   ++T1;                    // increment T1 again
   T1.displayTime();        // display T1
 
   T2++;                    // increment T2
   T2.displayTime();        // display T2
   T2++;                    // increment T2 again
   T2.displayTime();        // display T2
   
   cin.get();
   return 0;
}

#endif

#if 0

class Distance
{
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
   public:
      // required constructors
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      void operator=(const Distance &D )
      { 
         feet = D.feet;
         inches = D.inches;
      }
      // method to display distance
      void displayDistance()
      {
         cout << "F: " << feet <<  " I:" <<  inches << endl;
      }
      
};
int main()
{
   Distance D1(11, 10), D2(5, 11);

   cout << "First Distance : "; 
   D1.displayDistance();
   cout << "Second Distance :"; 
   D2.displayDistance();

   // use assignment operator
   D1 = D2;
   cout << "First Distance :"; 
   D1.displayDistance();
   cin.get();
   return 0;
}


#endif


/*
Overloading New & Delete 
It is Possible to overload new & delete . You might chose to do this if you want
to use some special allocation method. You may want allocation routines that 
automatically begin using a disk file as virtual memory when the heap has been exhausted.

Skeleton :
         
         Returns a void pointers 
         
         void *operator new(size_t size)
         {
         Perform allocation.
         Throw bad_alloc on error
         return pointer_to_memory;                   
         }
         
         //delete an object
         void operator delete(void *p)
         {
         free(pointer);     
         }


*/

int main()
{
 cin.get();   
 return 0;   
}
