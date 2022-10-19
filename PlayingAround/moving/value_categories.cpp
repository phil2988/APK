/*
    2 main categories
        glvalue (“generalized” lvalue) is an lvalue or an xvalue.
        
        rvalue (so-called, historically, because rvalues could appear on the right-hand side of an assignment expression) 
        is an xvalue, a temporary object or subobject thereof, or a value that is not associated with an object.

    split into 3 -> these 3 being the ones to focus on        
        lvalue (so-called, historically, because lvalues could appear on the left-hand side of an assignment expression) 
        designates a function or an object. [Example: If E is an expression of pointer type, 
        then *E is an lvalue expression referring to the object or function to which E points. 
        As another example, the result of calling a function whose return type is an lvalue reference is an lvalue.]

        xvalue (an “eXpiring” value) also refers to an object, usually near the end of its lifetime 
        (so that its resources may be moved, for example). 
        An xvalue is the result of certain kinds of expressions involving rvalue references. 
        [Example: The result of calling a function whose return type is an rvalue reference is an xvalue.]
        
        prvalue (“pure” rvalue) is an rvalue that is not an xvalue. 
        [Example: The result of calling a function whose return type is not a reference is a prvalue]
*/

#include <iostream>

template<typename X>

int main(int argc, char const *argv[])
{
    // lvalues - cannot be moved from
    int a;
    int* p;
    *p;
    "Hello World!";
    ++a; // is operators
    --a;

    // xvalues - can be moved from
    

    // prvalues - cannot be moved from
    42;
    a++;
    a--;
    X f(); // return value is prvalue

    return 0;
}

void foo(int&& t) {
  // t is initialized with an rvalue expression
  // but is actually an lvalue expression itself
}