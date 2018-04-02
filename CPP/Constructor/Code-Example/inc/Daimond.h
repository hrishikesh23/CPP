#ifndef DAIMOND_H
#define DAIMOND_H
using namespace std;


/* Disable this Macro to check Daimond Problem */
#define DAIMOND_ISSUE 0


class Base1
{
private :
int i;
char *BPtr;
public :
/* Declaration-Defination BC Default CTOR */
Base1() : i(0) {cout << "\n BC DCTOR called ";}
/* Declaration-Defiantion BC Parametrised CTOR */
Base1(int n) : i(n),BPtr(NULL) {
				cout << "\n BC PCTOR Called";				
			       } 

virtual ~Base1()
{
cout << "\n V DTOR called ";
}
void show()
{
cout << "\n BC Func";
}
};

class Derived1 : public Base1
{
private :
int k;
char *D1ptr;
public:
/* Derived1 Class DCTOR */
Derived1() : k(0) {cout << "\n D1C CTOR";}
/* Derived1 Class PCTOR */
Derived1(int n) : k(n),D1ptr(NULL) {
				    cout << "\n D1C PCTOR";
				   } 
#if DAIMOND_ISSUE
void show()
{
cout << "\n D1 Func";
}
#endif


};


class Derived2 : public Base1
{
private :
int j;
char *D2ptr;
public :
/* Derived2 Class DCTOR */
Derived2() : j(0) {cout << "\n DC2 DCTOR";} 
/* Derived2 Class PCTOR*/
Derived2(int p) : j(p) , D2ptr(NULL) {cout << "\n DC2 PCTOR";}
#ifndef DAIMOND_ISSUE
void show()
{
cout << "\n D2 Func";
}
#endif
};

class Derived3 : public Derived1, public Derived2 
{
private :
int m;
char *D3ptr;

public :

/* Derived3 Class DCTOR */
Derived3() : m(0) {cout << "\n DC3 DCTOR";} 
/* Derived3 Class PCTOR*/
Derived3(int l) : m(l) , D3ptr(NULL) {cout << "\n DC3 PCTOR";}

#if DAIMOND_ISSUE
void show()
{
cout << "\n D3 Func";
}
#endif
};


#endif


