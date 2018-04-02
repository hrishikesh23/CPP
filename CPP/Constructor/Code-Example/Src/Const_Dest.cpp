#include <iostream>
using namespace std;

class A {
  virtual void f() { cout << "void A::f()" << endl; }
  virtual void g() { cout << "void A::g()" << endl; }
  virtual void h() { cout << "void A::h()" << endl; }
  #if 0
  /* Constructor for A */
  A() {
    /* Looks for the function within the block or goes higher */  
    f();
    g();
    h();
  }
  #endif
};

class B : A {
  virtual void f() { cout << "void B::f()" << endl; }
  
    B() {
    /* Looks for the function within the block or goes higher */  
    f();
    g();
    h();
  }

  
};

class C : B {
  virtual void f() { cout << "void C::f()" << endl; }
  virtual void g() { cout << "void C::g()" << endl; }
  virtual void h() { cout << "void C::h()" << endl; }
};

int main() {
  C obj;
  cin.get();
  
  return 0;
}


#if 0
The constructor of B does not call any of the functions overridden in C 
because C has been derived from B, although the example creates an object of 
type Cnamed obj.
#endif
/*
OUTPUT

void B::f()
void A::g()
void A::h()
*/
