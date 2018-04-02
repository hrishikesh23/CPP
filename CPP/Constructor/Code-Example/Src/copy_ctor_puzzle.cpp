

#include <iostream>

using namespace std;

class sample
{
 public :
 sample() { cout << "\n Def CTOR"<< endl; }
 sample(const samp& obj) {};
 ~sample() { cout << "\n Def Dtor" << endl; }
};

int main()
{
sample sam = sample();
return 0;
}
