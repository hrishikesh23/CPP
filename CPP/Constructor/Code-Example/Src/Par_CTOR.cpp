#include <iostream>
#include "Basic.h"

int main()
{
/* create An Object of Class Test declared in Basic.h */
Test Ob;  	/* Will call Default CTOR   */

/* 
Questions :

Can i write 
Test Ob;
Test Ob(5);

	> No ... Compiler Will Throw and Error Saying
	  "Redeclaration of Test Ob..Test Ob declared here"

*/

Test Ob1(99); 	/* Will Call Parameterised CTOR */


return 0;
}
