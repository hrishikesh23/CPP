#include <iostream>

/*
http://publib.boulder.ibm.com/infocenter/lnxpcomp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8l.doc%2Flanguage%2Fref%2Fkeyword_dynamic_cast.htm
http://stackoverflow.com/questions/6857245/when-is-dynamic-cast-required
http://www.cpp-home.com/tutorials/2_1.htm
*/


using namespace std;

class Base
{
      public:             
            void func(){cout << "\n BC Func " <<endl;}
            
};

class Der : public Base
{
      public :
            void func1() { cout << "\n DC Func " << endl;}
};

int main()
{
 /* Cannot access functions in the derived class ..needs downcast to dervied */
 Base *bp;
 Der D1;
 /* Cannot access functions in the base class ..needs to typecast to base i.e Upcast */
 Der *D2;
 
 bp = &D1;
 bp->func();
 /* A base pointer does not point to the derived class & hence needs to be typecated to derived i.e downcasting*/
 ((Der*)bp)->func1();
 /* Upcast */
 ((Base*)D2)->func(); 
 
 cin.get();
 return 0;   
}
