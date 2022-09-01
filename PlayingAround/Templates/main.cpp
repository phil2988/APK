#include "functionTemplate.cpp"
#include "stackTemplate.cpp"
namespace templates{}
using namespace templates;

int main(int argc, char const *argv[])
{
    Stack<int> stack;
    stack.push(25);
    int i = stack.pop();

    stack.push(2.1);

    Stack<int> otherStack;
    splice<Stack<int>>(stack, otherStack);

    int i2 = 5;
    double d = implicit_cast<double>(i2);

    Stack<int> intStack;
    Stack<double> doubleStack(intStack);

    // TEMPLATE ALIASES
    using IntStack = Stack<int>;
    using DoubleStack = Stack<double>;

    DoubleStack ds;
    IntStack is;

    return 0;
}
