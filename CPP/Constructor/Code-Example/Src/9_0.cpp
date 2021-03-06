/* Lecture Code 9.0
 *
 * The Tracer class.  Note that the messages printed in response to initialization and assignment
 * are generated by the copy constructor and assignment operator.  Experiment around with Tracer
 * if you're interested in seeing how C++ copies and initializes objects.
 */

#include <iostream>
using namespace std;

class Tracer
{
public:
	/* Recall that C++ won't give your classes a default constructor if you define a constructor of your
	 * own.  Here, since we've defined a copy constructor, we'll need to provide our own default constructor.
	 * Since Tracer is empty, we simply define the empty constructor.
	 */
	Tracer() {}
	Tracer(const Tracer & other);
	Tracer &operator =(const Tracer &other);
};

/* The copy constructor simply prints that something was initialized. */
Tracer::Tracer(const Tracer &other)
{
	cout << "Object was initialized." << endl;
}

/* The assignment operator prints out that there was an assignment. */
Tracer &Tracer::operator =(const Tracer &other)
{
	cout << "Object was assigned." << endl;
	return *this;
}


int main()
{


return 0;
}
