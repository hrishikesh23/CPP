
#include "common.h"

/* class defination begins Here */
C_START_(base)

private :
	int local_len;
	int local_attr;

public :
	base() { cout << "def ctor " << endl ;}
	~base() { cout <<" def dtor " << endl ;} 
C_END_


template <typename T>
C_START_(Debugvector)

public : 
     	Debugvector(); /* def ctor */
       ~Debugvector(); /* def dtor */
 	Debugvector(const Debugvector &other); /* Copy CTOR */
	Debugvector &operator =(const Debugvector &other); /*Assign Operator*/
	void clear();
	void Copyother(const Debugvector &other);
private :

	T *array;
	int allocatedlen;
	int logicallen;
	static const int BASE_SIZE = 16;

C_END_

template <typename T>
Debugvector<T> :: Debugvector() : array(new T[BASE_SIZE]),allocatedlen(BASE_SIZE), logicallen(0)
{

cout << " debug vector created " << endl;

}

template <typename T>
Debugvector<T> :: ~Debugvector() 
{

	delete [] array;
	array = NULL;
        allocatedlen = logicallen = 0;
        cout  << " debug vector destroyed " << endl ;

}

template<typename T>
void Debugvector<T> :: clear()
{
cout << "\n Clear Function called" << endl ;
	delete [] array;
	logicallen =allocatedlen = 0;
	array = NULL;

}

template <typename T>
Debugvector<T> :: Debugvector(const Debugvector& other)
{

cout << "Copy Ctor called for debugvector" << endl;

}

template <typename T>
void  Debugvector<T> :: Copyother(const Debugvector &other)
{
	logicallen   = other.logicallen;
 	allocatedlen = other.allocatedlen;
        array = new T[allocatedlen];
	for(int i = 0; i < allocatedlen ; i++)
	array[i] = other.array[i];
}

template <typename T>
Debugvector<T> &  Debugvector<T> :: operator = (const Debugvector &other)
{
	if(this != other)
	{
	clear();
	Copyother(other);
	}
return *this;
}


/* main code begins Here */
START_

//base obj1;

Debugvector<int> obj;

Debugvector<int> obj1 = obj;
obj1  = obj;

//cout << "\n Created an object successfully" << endl;

//cout << "\n My Header Still Works Fine" << endl;

END_



