/* Lecture Code 8.1
 *
 * Integer class, version 2
 */

#include <iostream>
using namespace std;

class Integer
{
public:
	Integer (int val);

	/* Getters that return a reference - note two versions. */
	int &num();
	const int &num() const;

private:
	int value;
};

Integer::Integer(int val)
{
	value = val;
}

int &Integer::num()
{
	return value;
}

const int &Integer::num() const
{
	return value;
}