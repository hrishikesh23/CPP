


#include <iostream>

using namespace std;
class date 
    {
    /* Private Variables */
    int day,month,year;
    public :
           /* parameterised Constructor */
           date(char *d);
           /* Functions overloading ...with parameterised constructors */
           date(int m,int d,int y);
           
           void show_date();                
          
    };
    
#if 1   
    /* Defining the cosntructor */
  date::date(char *d)
  {
    cout<< "\n Single parameter Constructor ";     
  }
    
    date :: date(int m,int d, int y)
    {
        day = d;
        month = m;
        year =  y;
    }
    
    void date :: show_date()
    {
    cout << "\n Month " << month ;//<< " Date " << date ;//<< " Year " << year;               
    }
#endif    
    

int main()
{
    /* 
    Understanding Function Overloading 
    Function Overlaoding is the process of using same name for two or more functions. 
    The Secret to overlaoding is using same name for the two functions with different parameters
    Each redefination of the function must use different number of parameters
    Each redefination should differ in there return type as well         
    */
    
    /*
    Overloading Constructor 
    1. To gain flexibility 
    2. To allow both initialized and uninitialized objects to be created.
    3. define copy constructors
    
    */
    
    
    cin.get();
return 0;    
}
