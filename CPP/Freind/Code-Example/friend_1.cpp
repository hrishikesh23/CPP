#if 0

#include <iostream>

using namespace std;

class A
{
  int x;int y;
  
  public :
         
         void set(int i)
         {
              x =i;
              y =i;
         }    
      
      int get()
      {
      return x;    
      }
      
      friend class B;      
      
};

class B
{
  int j, k;
  public :
         void set_j(int i,A &b)
         {
             j =  b.x;
             cout << "\n j = " << j;
         }    
      
};

int main()
{
 A ob;
 B ob1;
 ob.set(100);
 ob1.set_j(5,ob);
 
 cin.get();
 return 0;   
}

#endif


#if 0

#include <iostream>
using namespace std;

class MyClass
{
	// Declare a friend class
	friend class SecondClass;

	public:
		MyClass() : Secret(0){}
		void printMember()
		{
			cout << Secret << endl;
		}
	private:
		int Secret;
		
	protected :
              int prot;
};

class SecondClass
{
	public:
		void change( MyClass& yourclass, int x )
		{
			yourclass.prot = x;
		}
};

int test_func( MyClass& yourclass, int x )
{
		//	yourclass.prot = x;
		return 0;
}
int main()
{
	MyClass my_class;
	SecondClass sec_class;
	my_class.printMember();
	sec_class.change( my_class, 5 );
	
	my_class.printMember();
	
	test_func( my_class, 5 );
	cin.get();
	return 0;
}

#endif


#include <iostream>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#include <string>
using namespace std;

class ABCD
{
public: 
    int a;
    int b;
    friend void friend_fun(const ABCD &obj);
};

void fun(const ABCD &obj)
{
    std::cout<<obj.a<<endl;
    std::cout<<obj.b<<endl;
};

void friend_fun(const ABCD &obj)
{
    std::cout<<obj.a<<endl;
    std::cout<<obj.b<<endl;
};


int main () 
{
     ABCD obj;
     obj.a = 20;
     obj.b = 30;
     fun(obj);
     friend_fun(obj);
cin.get();
    return 0;
}
#if 0
const int idle_1 = 0;
//const int idle = 0;
const int use = 0;
class C2;   	//Forward declaration.
/*
this is class prototype which tells the compiler that we are going to declare a class of type C2; without this the compiler will say it doesn't know the class C2 when parsing the protoype for function idle. inside the class C1.
*/
class C1
{
int status;
public:
void set_sts(int state);
friend int idle(C1 a,C2 b);
};
class C2
{
int status;
public:
void set_sts(int state);
friend int idle(C1 a,C2 b);
};
void C1 :: set_sts(int st)
{
status= st;
}
void C2 :: set_sts(int st)
{
status= st;
}
int idle(C1 a,C2 b)
{
if(a.status || b.status)
return 0;
else
return 1;
}

int main()
{
C1 x;
C2 y;
x.set_sts(idle_1);
//x.set_sts(idle);
//y.set_sts(idle);
y.set_sts(idle_1);
if(idle(x,y))
{
cout << "\n Screen can be used";
}
else
{
cout << "\n Screen is in use";
}
cin.get();
return 0;
}

#endif
