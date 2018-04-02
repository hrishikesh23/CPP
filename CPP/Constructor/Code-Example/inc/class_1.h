#ifndef CLASS_H
#define CLASS_H
using namespace std;

/* Base Class */
class aTestClass
{
  protected:
    aTestClass()
    {
        cout<<"Object created\n";
    }
    virtual ~aTestClass()
    {
        cout<<"Object destructed\n";  
        Instance = NULL;           
    }
    static aTestClass* Instance;
    
    public:
    aTestClass* getAnObject();
    void ResetAnObject();   
};

/* Derived Class */
class bTestClass : public aTestClass
{
  
  public : 
          bTestClass()  {cout << "default B class CTOR" << endl ;}   
          virtual ~bTestClass() {cout << "default B class DTOR" << endl ;}
      
};

#endif
