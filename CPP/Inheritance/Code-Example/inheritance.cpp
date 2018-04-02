#include<iostream>
using namespace std;
class Base
{
          int x;
          public:
                 Base(int val):x(val)
                 {
                          cout << "Parameterised Base" << endl;
                 }
};
class Derived:public Base
{
      int d;
      public:
             Derived(int val):d(val)
             {
                         cout << "Parameterised Derived" << endl;
             }
};
int main()
{
    Derived obj(9);
    return 0;
}
