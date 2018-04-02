#ifndef CLASS_H
#define CLASS_H
using namespace std;
class aTestClass
{
  private:
    /* Private CTOR defination */      
    aTestClass()
    {
        cout<<"Object created\n";
    }
    /* Static Pointer */
    static aTestClass* Instance;    
    public:
    /* Public Method to GetInstance */       
    aTestClass* getAnObject();   
};

#endif
