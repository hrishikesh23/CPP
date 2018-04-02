/* Lecture Code 8.0
 *
 * Integer class, version 1
 */

#include <iostream>
using namespace std;

class Integer
{
public:
	Integer (int val);

	int getValue() const;
	void setValue(int val);

private:
	int value;
};

Integer::Integer(int val)
{
	value = val;
}

int Integer::getValue() const
{
	return value;
}

void Integer::setValue(int val)
{
	value = val;
}