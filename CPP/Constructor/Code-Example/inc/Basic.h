#ifndef BASIC_H

#define BASIC_H

#include <iostream>

using namespace std;


#define TECHNIQUE_1  0
#define TECHNIQUE_2  0
#define TECHNIQUE_3  1


class Test
{
private :
int j;
char *ptr;

public :

/* Default CTOR */

#if TECHNIQUE_1
Test() {
	cout << "\n Def CTOR Basic.h T1";
        /* Performing Initialisation */
	j=0;
       }
#endif

#if TECHNIQUE_2
Test() : j(0) {
	      cout << "\n Def Ctor Basic.h T2" << endl;		
              }
#endif


#if TECHNIQUE_3
Test() : j(0) {
	      cout << "\n Def Ctor Basic.h T3" << endl;		
              }


#endif

/* Parameterised Ctor */

#if TECHNIQUE_1
Test(int i) {
		cout << "\n Para CTOR Basic.h T1";
		/* Assigning Value */
		j=i;
		cout << "\n Val j= "<< j << endl;
	    }
#endif


#if TECHNIQUE_2
Test(int i) : j(i) {
			cout << "\n Para CTOR Basic.h T2";
			cout << "\n Val j= " << j << endl;
		   }
#endif


#if TECHNIQUE_3
Test(int i) : j(i),ptr(NULL)
			{
			cout << "\n Para CTOR Basic.h T3" << endl;
			cout << "\n Val j= " << j << endl;
			cout << "\n Ptr =  " << ptr << endl;
			}

/* 
Comment the virtual Destructor part when using T3
To simulate that def destructor does not get called
when ctor operates on Pointers

Why ????

virtual dtor cannot be overloaded 

*/

virtual ~Test() {
		cout << "\n Virtual DTOR Basic.h T3" << endl;
		}


#endif


/* Default DTOR */

#if (TECHNIQUE_1 || TECHNIQUE_2)

~Test() {
	cout << "\n Def DTOR Basic.h " << endl;
        }
#endif



/*

Why DTOR is Common...How it is Managed !!!! :(
This Pointer....

*/

void show()
{
cout << "\n In Func Show of Basic.h" << endl;
}

};

#endif
