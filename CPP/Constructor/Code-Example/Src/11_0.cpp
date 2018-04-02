/* Lecture Code 11.0
 *
 * The final DebugVector template class, including bracket operators, operator <, and operator <<.
 * Comments have been added to the relevant sections.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template<typename T>
	class DebugVector
{
public:
	DebugVector();
	DebugVector(const DebugVector &other); // Copy constructor
	DebugVector & operator =(const DebugVector &other); // Assignment operator
	~DebugVector(); // Destructor - remember the rule of three.

	/* The overloaded brackets operator for accessing. */
	T& operator[] (int index);
	const T& operator[](int index) const;

	/* Some utility functions to insert, remove, and append elements. */
	void removeAt(int index);
	void insertAt(const T& value, int index);
	void append(const T& value);

	/* Size functions. */
	int size() const;
	bool isEmpty() const;

	/* Clears the vector out.  This is also invoked by the destructor to clean up memory. */
	void clear();
	
	/* Stream insertion operator. */
	template <typename T> friend ostream& operator <<(ostream &stream, const DebugVector &vec);
	
	/* Relational operator, for using with STL. */
	bool operator <(const DebugVector &other) const
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
	copyOther(other);
	logCreation();
}

/* Assignment operator: Clear out, then copy over the other object. */
template<typename T>
	DebugVector<T> & DebugVector<T>::operator =(const DebugVector &other)
{
	/* Avoid self-assignment! */
	if(this != &other)
	{
		clear(); // Release any memory we have allocated.
		copyOther(other); // Copy over the object.
	}
	return *this; // To allow chained assignments, return a reference to ourself.
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

/* The overloaded [] operator is exactly the same as the former "at" function. */
template<typename T>
	T& DebugVector<T>::operator [](int index)
{
	return array[index];
}

template<typename T>
	const T& DebugVector<T>::operator [](int index) const
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

/* Compares two vectors by number of elements and then element-by-element. */
template<typename T>
	bool DebugVector<T>::operator <(const DebugVector &other) const
{
	/* Compare the number of entries.  This is slightly condensed from lecture. */
	if(logicalLength != other.logicalLength)
		return logicalLength < other.logicalLength;
	
	/* Compare each element.  Note that this only requires the < operator to work correctly. */
	for(int i = 0; i < logicalLength; i++)
	{
		if(array[i] < other.array[i])
			return true;
		else if(other.array[i] < array[i])
			return false;
	}
	
	/* Completely equal, so return false. */
	return false;
}

/* Stream insertion operator. */
template<typename T>
	ostream& operator <<(ostream& stream, const DebugVector<T> &vec)
{
	/* Note the friend access. */
	for(int i = 0; i < vec.logicalLength; i++)
		stream << vec.array[i] << ' ';
	
	/* For chained operations. */
	return stream;
}
