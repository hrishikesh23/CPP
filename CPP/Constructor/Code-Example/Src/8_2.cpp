/* Lecture code 8.2
 *
 * Initializer list versus constructor time trial.
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

const int NUM_TESTS = 1000000;

class ConstructorClass
{
public:
	ConstructorClass();
private:
	int myInt;
	string myString;
	vector<int> myVector;
};

class InitListClass
{
public:
	InitListClass();
private:
	int myInt;
	string myString;
	vector<int> myVector;
};

ConstructorClass::ConstructorClass()
{
	myInt = 137;
	myString = "C++!";
	myVector.resize(10);
}

InitListClass::InitListClass() : myInt(137), myString("C++"), myVector(10)
{
	// Empty constructor
}

template<typename T>
void RunTimeTrial()
{
	
	clock_t start = clock();
	
	for(int h = 0; h < NUM_TESTS; h++)
	{
		T object;
	}

	start = clock() - start;

	cout << "Finished in ";
	cout << ((double)(start) / CLOCKS_PER_SEC);
	cout << " seconds." << endl;
}

int main()
{
	RunTimeTrial<ConstructorClass>();
	RunTimeTrial<InitListClass>();

	return 0;
}