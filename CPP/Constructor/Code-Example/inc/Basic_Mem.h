#ifndef BASIC_MEM_H
#define BASIC_MEM_H

#include <iostream>
using namespace std;



/*
How to demonstrate :

1. Disable Both Macros : Issue ...Delete Pointer called twice
2. Enable TECHNIQUE :2 Macro. .... Problem Resolved
3. Now Enable Bothe macros...Show how destructor Holds the address of both pointer independently and demonstrate the sequence of releasing.

*/

/*
There is also some dependency with the order of object being created and called...defaul/parameter.
Working on it.

*/

/*
Disable both macros : Problem ..Memory allocated Once ..but delete called twice..here Lies Issue.
This Issue can be overcome by...Enabling MACRO : TECHNIQUE_2. when TECHNIQUE_1 is disabled
*/

/*
Enable Macro to demonatrate Memory allocation in both Default/Parameter constructor..where the virtual destructor will
release memory twice. being Luck..this works fine.
*/
#define TECHNIQUE_1 1

/*
Enable this Macro with the Previous one to demonstrate memory allcoation in both CTOR ..where virtual destructor puts a check if Memory was allaocted or Not.
And then tries to release Memory. Perfect way to work out.
*/
#define TECHNIQUE_2 1



class Test
{
private :
int j;
char *ptr;


public :

Test() : j(0) {
		cout << "\n Def CTOR BASIC_MEM T1";
#if TECHNIQUE_1
		ptr = new char[20];
		cout << "\n Address of Ptr " << static_cast<void *>(ptr) << endl;
		if(ptr != NULL)
                cout << "\n Memory Allocation done Successful in DCTOR";
		else
		cout << "\n Memory Allcoation Failed in Def CTOR";
#endif
	      }

Test(int i) : j(i),ptr(NULL) {

				cout << "\n Para CTOR BASIC_MEM";				
				ptr = new char[10];
				cout << "\n Address of Ptr " << static_cast<void *>(ptr) << endl;
				if(ptr != NULL)
				cout << "\n Memory Allocation done Successful in PCTOR" << endl;
				else
				cout << "\n Unable To allocate Memory" << endl;

			     }

virtual ~Test()
{
static int k =0;
k++;

#if TECHNIQUE_2
if(ptr != NULL)
{
delete [] ptr;
cout << "\n Deleting Ptr " << static_cast<void *>(ptr) << endl;
}
#else
{
delete [] ptr;
cout << "\n Deleting Ptr " << static_cast<void *>(ptr) << endl;
}
#endif


cout << "\n DTOR Count K = " << k <<endl;


}

 

void show() {
		cout << "\n In function show";
	    }


};
#endif
