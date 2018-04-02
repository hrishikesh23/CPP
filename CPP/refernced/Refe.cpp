#include <iostream>


#define Interface class

#define DeclareInterface(name) Interface name { \
                               public : \
                               virtual ~name(){}
                               

                               
#define EndInterface      };

#define Implements public                               


DeclareInterface(IBar)
virtual int GetBarData() const=0;
virtual void SetBarData() = 0;
EndInterface 

using namespace std;

int main()
{
    
 int i = 20;
 int j = 30;
 
 cout << "\n Initializing ref variable "<<endl;
 
 int& ref = i;
 
 cout << "\n Ref = " << ref  << endl
      << "\n i   = " << i    << endl;       
 cout << "\n performing operation on Variabel++..Reflects to Ref variable " <<endl; 
 i++;

  cout << "\n Ref = " << ref << endl
       << "\n i   = " << i    << endl;
 cout << "\n performing operation on ref++..Reflects to variable "<<endl;       
 ref++;      
 
   cout << "\n Ref = " << ref << endl
        << "\n i   = " << i    << endl;
        
 cout << "\n Reset the Reference pointing to var1 to var2" << endl;
 
 ref = j;
 
 cout << "\n Ref = " << ref << endl
        << "\n j   = " << j    << endl;
 
 
        
    
    cin.get();
return 0;    
}
