#include <iostream>
#include <string.h>

using namespace std;


class Maruti_Suzi
{
   
   char Model[50];   
   
   public :
          int car_num;
          void Update_Num(int num);
          void Update_Model(char *name);
          int get_num();             
      
};

void Maruti_Suzi :: Update_Num(int num)
{
cout << "\n Car Num BC" ; 
car_num = 230;        
} 

void Maruti_Suzi :: Update_Model(char *name)
{  
cout << "\n Car Name BC" ;    
}

int Maruti_Suzi :: get_num()
{
cout << "\n Get Num BC" ;    
return 0;
}

class Alto : public Maruti_Suzi
{

  char color[20];
  
  public :
         int rank;
         void set_rank(int num);
         void set_color(char *cl);
         int get_rank();                     
         void Update_Num(int num);
               
};

void Alto :: Update_Num(int num)
{
 cout << "\n CAR NUM DC" ;         
}

void Alto :: set_rank(int num)
{
cout << "\n Set Rank Derived Class" ;     
}

void Alto :: set_color(char *cl)
{
//strcpy(color,cl);     
cout << "\n Set Color Derived Class " << cl;     
}

int Alto :: get_rank()
{
cout << "\n Get Rank DC" ;             
return 0;
}



int main()
{
    
#if 0 

  /* Understanding Pointers to Class */   
  char name[20] = "RED BLUE";  
    
  Maruti_Suzi ob_base;
  Maruti_Suzi *base_ptr;  
  Alto ob_der;
  Alto *der_ptr;
  
  
  /* Access With Base Class object */
  
  /* Base Class object can access only base class public function */ 
  ob_base.Update_Num(3695);
  /*  Base Pointer  can access only base class member function and not derived class */
  base_ptr->get_num();
  
  /* Base pointer accessing the functions of derived class */
  /* Why base pointer cannot access member functions of derived class */
  //base_ptr->set_rank(1);
  
  /* derived object can access function of base class : initially looks into derived class if member function is available else goes into base class */
  
  ob_der.Update_Num(9635);
  
  der_ptr->set_color(name); 
  
  /* base Pointer accessing the derived class member functions : Needs Type cast */  
  /* What is upcast/downcast*/
  ((Alto *)base_ptr)-> get_rank();
#endif  

#if 0

/* Understanding Pointer to member data / member function  */
  /* Syntax to point to data pointer */
  /* Data_type base_class name :: pointer*/
  int Alto :: *data; 
  
  /* Create a Pointer to member function */
  /* data type  base class :: func_pointer */
  int (Maruti_Suzi :: *func)();
  
  /* Create objects of base class */
  Maruti_Suzi base_ob1,base_ob2;
  Alto der_ob1;
  /* Now update the member pointer & function Pointer with the corresponding addresses */
  /* Assign Address of the data member to the Pointer to Member  */
  data = (&Alto :: rank);
  /* Assign Address of the member function to the Pointer to function */
  /* pointer = address of base class :: func_name */
  func = (&Maruti_Suzi :: get_num);
  
  
  /* Now call the function and address the data member using the pointer & base class object  */
  
  cout << "\n Data mem " << der_ob1.*data ;
  
  cout << "\n Func " << (base_ob1.*func)();
  
#endif


#if 0
      /* understanding Pointer to member functions and data members using pointer to class */   
      
      int Maruti_Suzi :: *data;
      int (Maruti_Suzi :: *func)();
      
      Maruti_Suzi *bc_ptr1,*bc_ptr2;
      
      data = &Maruti_Suzi :: car_num;
      
      func = &Maruti_Suzi :: get_num;
      
      
      cout << "\n Get Num " << (bc_ptr1->*func)();
      
      //cout << "\n Get Data " << bc_ptr1->*data;
             
#endif

/* Reference */   
/*
There are three ways the reference can be used 
1. As a Function Parameter
2. Function return value 
3. Standalone Reference 
*/


#if 0
  
int a;
int c = 5000;
int &ref = a;
int &ref1 = ref;
int *b;
a =10;
 
ref = ref1;
cout << "\n A = " <<  a << endl;  
a =30;
cout << "\n ref1 = " <<  ref1 << endl;  


ref = 20;
b = (int *)&ref;  
  
cout << "\n Ref = " <<  ref << endl;    

cout << "\n A = " <<  a << endl;  

cout << "\n B ref Add = " <<  b << endl;  

*b = 60;

cout << "\n Pointer B = " <<  *b << endl;  

cout << "\n Ref = " <<  ref << endl;    

#endif

/*
Restrictions to references 
1. You cannot reference another reference 
2. You cannot obtain address of reference
3. You cannot create arrays of reference 
4. You Cannot create a Pointer to reference
*/


/*
C Dynamic Memory Allocation 
*/
    
#if 0    
  int *p ;
  

  try
  {
     p =new int;            // Allocate space for int             
      }catch(bad_alloc xa)
      {
        cout << "Alloca Failure";
        return 1;      
      }  

*p = 100;   
   
            cout << "At " << p << " ";
            cout << "is the value " << *p << "\n";
            delete p;
            
#endif

#if 0

/* Allocate Memory to Array */            

 Maruti_Suzi *p;
 
 try
 {
 /* Allocating Memory to object of a class */
 p = new Maruti_Suzi;        
         
 }catch(bad_alloc xa)           
 {                
 cout << "\n Unable to allocate Error ";
 return 1;
 }
 /* Free Memory */
 delete p;
#endif

   

 cin.get();   
 return 0;   
}
