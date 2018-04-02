
/* 

Reference : http://www.cplusplus.com/doc/tutorial/inheritance/


freind  : 
        
        Freinds are functions or classes defined with freind keyword
        If we want to declare an external function as friend of a class, thus allowing 
        this function to have access to the private and protected members of this class, 
        we do it by declaring a prototype of this external function within the class, and preceding it with the keyword friend:

*/

#if 0

#include <iostream>

using namespace std;

class CRect
{
int ht,wd;

public:
       /* Default constructor to be called */
       CRect()
       {
       cout << endl;       
       cout << "Default Constructor";              
       ht = 0;
       wd = 0;       
       }
       /* Parameterised constructor to be called */
       CRect(int i,int j)
       {
       ht = i;
       wd = j;                           
       }
       /* Function to be calculate area */
       int area()
       {
       return (ht*wd);    
       }
       
       /* Set Ht and Wd of the rectangle */
       void set_val(int i,int j)
       {
       /* ht = 2 */     
       ht = i;
       /* wd = 3 */     
       wd = j;                 
       }             
       
       /* Declaring the freind class */
       /* freind[keyword] Class_Name freind_func_name(Class_Name) */
       /* return type and the parameter passed to the duplocate function can be void */
       friend CRect duplicate(CRect);
             
};

/* Collect the Updated values in the object */

CRect duplicate(CRect rectP)
{
    /* Creating an object Calls default constructor */      
    CRect rex;
    
    /* update the temporary object */
    /* rex.wd = 0 initialised in constructor */
    /* rectP.wd = 3 hence 2*3 = 6*/
    rex.wd = rectP.wd*2;  
    /* rex.ht = 0 initialised in constructor */
    /* rectP.ht = 2 hence 2*2 = 4*/    
    rex.ht = rectP.ht*2;
    
    /* Hence Resulting calculation 6*4 = 24 area */
    
    /* Return the temporary object */
    return rex;          
}

int main()
{
/* Create an  object calls the default construtor */    
CRect rect, rectb;

cout << endl;
cout << " After Creating Objects " << endl;
  /* Set the values of Ht & Wd variable */ 
  rect.set_val(2,3);
cout << " After Setting Values  " << endl;  
  /* Collect the temporary return object in rectb */ 
  /* Pass the object rect through function duplicate */
  rectb = duplicate (rect);
  
cout << " Display " << endl;
  cout << " Area = "<< rectb.area();
cin.get();    
return 0;    
}
#endif 

#if 0

The duplicate function is a friend of CRectangle. From within that function we have been able to access the members width and height of 
different objects of type CRectangle, which are private members. Notice that neither in the declaration of duplicate() nor in its later 
use in main() have we considered duplicate a member of class CRectangle. It isn't! It simply has access to its private and protected 
members without being a member.

The friend functions can serve, for example, to conduct operations between two different classes. Generally, the use of friend functions 
is out of an object-oriented programming methodology, so whenever possible it is better to use members of the same class to perform 
operations with them. Such as in the previous example, it would have been shorter to integrate duplicate() within the class CRectangle.

#endif


/*
Just as we have possiblity of defining a freind function . We can also define a class as freind of another.
Granted that the first class access to the Private and protected members of the second class. 
*/


// friend class
#include <iostream>
using namespace std;
/* Declaration of Class */
class CSquare;

/*
 CRectangle :           
           Class to calculate Area
           Contains a function to convert to Square.      
*/

class CRectangle {
    int width, height;
  public:
    int area ()
      {return (width * height);}
    void convert (CSquare a);
};


/*

CSquare :
        Class set side of square
        And contains a declarationn for freind class. the rectangle freind class can access private
        variables of square class .        

*/
class CSquare {
      
  private:
    int side;
    
  public:
    void set_side (int a)
      {
      side=a;
      }            
    /* declare freind class */  
    friend class CRectangle;
};

void CRectangle::convert (CSquare a) {
  /* Accessing the Private variables of CSquare */   
  width = a.side;
  height = a.side;
}
  
int main () {
  /* Create An Instance */  
  CSquare sqr;
  /* Create An Instance */    
  CRectangle rect;
  /* Set the Side */
  sqr.set_side(4);
  /* Assign Ht = wd*/
  rect.convert(sqr);
  /* Square */
  cout << rect.area();
  
  cin.get();
  return 0;
}

/*


http://www.cplusplus.com/doc/tutorial/inheritance/

In this example, we have declared CRectangle as a friend of CSquare so that CRectangle member functions could have access to 
the protected and private members of CSquare, more concretely to CSquare::side, which describes the side width of the square.

You may also see something new at the beginning of the program: an empty declaration of class CSquare. This is necessary because 
within the declaration of CRectangle we refer to CSquare (as a parameter in convert()). The definition of CSquare is included later, 
so if we did not include a previous empty declaration for CSquare this class would not be visible from within the definition of CRectangle.

Consider that friendships are not corresponded if we do not explicitly specify so. In our example, CRectangle is considered as a 
friend class by CSquare, but CRectangle does not consider CSquare to be a friend, so CRectangle can access the protected and private 
members of CSquare but not the reverse way. Of course, we could have declared also CSquare as friend of CRectangle if we wanted to.

Another property of friendships is that they are not transitive: The friend of a friend is not considered to be a friend unless 
explicitly specified.


*/
