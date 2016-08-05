#include <iostream>

using namespace std;

struct Demo
{
  int x;
};

int main()
{
  Demo demo;

  demo.x = 5;

  Demo *p_demo = &demo;

  new(p_demo) Demo;

  cout << p_demo->x << endl; //prints 5

  new(p_demo) Demo();

  cout << p_demo->x << endl; //prints 0
}

/*
I use placement new. I can not make the demonstration otherwise, because it seems that the free store (the part of the heap that new uses) is automatically zero-initialized by the OS or by the run-time and it appears as if you always have zero initialized structs. Placement new has the syntax new(ptr) Type(args) and has the effect of invoking the constructor of Type with the supplied args on the memory pointed by ptr. It is like the ordinary new, but does not allocate memory. It uses the memory that you provide with ptr instead. I use this form of new, because the allocation is not related to your question, only the initialization. And this helps me to show the effect I want to demonstrate. As a side note, what I do, to construct one object where another already resides, is generally illegal, but since this is POD type (plain old data - C like struct) I believe it is ok.

The first constructor - without parenthesis - provides what is called default initialization (do not confuse with default constructor). Default initialization leaves the values of fundamental types (int, double, etc) uninitialized, i.e. arbitrary. Therefore, with new Demo; you get uninitialized chunk of memory with arbitrary values in the fields.

The second constructor - with parenthesis - provides what is called value initialization. Value initialization zeros fundamental types. Therefore, with new Demo(); you get zero-initialized chunk of memory - all fields in this case will be zeros.

In general, the rules are defined recursively, and you may need to think deep to anticipate what will happen. I address your case. Specifically, you provide no constructor for Demo. The trick with leaving arbitrary values with default initialization (which is supposed to provide performance gain if you believe it) works only when the struct/class does not have constructor defined by the programmer.

The same techniques apply to automatic variables, but I rather say no more. My answer is already too bloated.
*/
