/* Lecture Code 10.0
 *
 * The full DebugVector template class, including full deep-copying support.
 * Comments have been added to the relevant sections.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int NUM_INTS = 10;

template<typename T>
	class DebugVector
{
public:
	/* default Ctor */
	DebugVector();
	DebugVector(const DebugVector &other); // Copy constructor
	DebugVector& operator =(const DebugVector &other); // Assignment operator
	~DebugVector(); // Destructor - remember the rule of three.

	/* Accessors return references to the element, so we don't need getAt/setAt.
	 * Note that this function is const-overloaded.
	 */
	T& at(int index);
	const T& at(int index) const;

	/* Some utility functions to insert, remove, and append elements. */
	void removeAt(int index);
	void insertAt(const T& value, int index);
	void append(const T& value);

	/* Size functions. */
	int size() const;
	bool isEmpty() const;

	/* Clears the vector out.  This is also invoked by the destructor to clean up memory. */
	void clear();
private:

	void grow();
	void logCreation();
	void copyOther(const DebugVector &other);

	T *array;
	int logicalLength;
	int allocatedLength;
	static const int START_SIZE = 8;
};

/* Logs creation information to cout. */
template<typename T>
	void DebugVector<T>::logCreation()
{
	time_t currTime;
	time(&currTime);

	cout << "DebugVector created at " << ctime(&currTime) << endl;
}

/* Constructor.  Note that most of the variables are set up in the initializer list. */
template<typename T>
	DebugVector<T>::DebugVector() : array(new T[START_SIZE]),
	           logicalLength(0), allocatedLength(START_SIZE)
{
	cout << "Default CTOR" << endl;
	logCreation();
}

/* Unified function to make a deep copy of another object. */
template<typename T>
	void DebugVector<T>::copyOther(const DebugVector &other)
{
	logicalLength = other.logicalLength;
	allocatedLength = other.allocatedLength;

	array = new T[allocatedLength];
	for(int i = 0; i < logicalLength; i++)
		array[i] = other.array[i];
}

/* Copy constructor - we'll copy over the other object, then log creation data. */
template<typename T>
	DebugVector<T>::DebugVector(const DebugVector &other)
{
	cout << "Copy CTOR" << endl;
	copyOther(other);
	logCreation();
}

/* Assignment operator - drop out existing content and replace with a deep copy. */
template<typename T>
DebugVector<T>& DebugVector<T>::operator =(const DebugVector &other)
{
	cout << "Assignment Operator" << endl;
	/* Avoid self-assignment! */
	if(this != &other)
	{
		clear(); // Clear existing state to avoid memory leaks
		copyOther(other); // Duplicate
	}
	return *this;
}

/* Destructor clears out the vector and logs destruction information. */
template<typename T>
	DebugVector<T>::~DebugVector()
{
	clear();
	time_t currTime;
	time(&currTime);
	cout << "DebugVector destroyed at " << ctime(&currTime) << endl;
}

/* Deallocates all memory and zeroes all variables. */
template<typename T>
	void DebugVector<T>::clear()
{
	delete [] array;
	array = NULL;

	allocatedLength = logicalLength = 0;
}

/* Returns the number of elements - note the const modifier here since this doesn't
 * actually change the state of the object.
 */
template<typename T>
	int DebugVector<T>::size() const
{
	return logicalLength;
}

template<typename T>
	bool DebugVector<T>::isEmpty() const
{
	return logicalLength == 0;
}

/* Both versions of the const-overloaded at function. */
template<typename T>
	T& DebugVector<T>::at(int index)
{
	return array[index];
}

template<typename T>
	const T& DebugVector<T>::at(int index) const
{
	return array[index];
}

/* removeAt deletes an element and shuffles things down. */
template<typename T>
	void DebugVector<T>::removeAt(int index)
{
	for(int i = index; i < logicalLength - 1; i++)
		array[i] = array[i + 1];
	
	logicalLength --;
}

/* Inserts a new element, growing if necessary, then shuffles things down. */
template<typename T>
	void DebugVector<T>::insertAt(const T& value, int index)
{
	if(logicalLength == allocatedLength)
		grow();

	for(int i = logicalLength; i > index; i--)
		array[i] = array[i - 1];
		
	array[index] = value;
	logicalLength ++;
}

/* Appends an element - effectively a glorified call to insertAt. */
template<typename T>
	void DebugVector<T>::append(const T& value)
{
	insertAt(value, logicalLength);
}

/* Grows the vector when we need more space. */
template<typename T>
	void DebugVector<T>::grow()
{
	/* In case we were cleared out, reset to the start size. */
	if(allocatedLength == 0)
		allocatedLength = START_SIZE;

	allocatedLength *= 2;
	T *newArray = new T[allocatedLength];

	for(int i = 0; i < logicalLength; i++)
		newArray[i] = array[i];

	delete [] array;
	array = newArray;
}


int main()
{
DebugVector <int> obj1,obj2;
obj1 = obj2;

return 0;
}
