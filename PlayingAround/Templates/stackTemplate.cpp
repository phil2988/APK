#include <iostream>
namespace templates{
    template<typename T>
    class Stack
    {
    public:
        Stack(): top_(0){}

        Stack(size_t capacity) 
        : top_( 0 ) 
        { 
            elem_ = new T[capacity];
        }
        
        /* Need to access private data */
        template<typename T2> friend class Stack;

        template<typename T2>
        Stack(const Stack<T2>& otherStack){
            for( int i=0; i<otherStack.top_; i++ ) {
                /* Conversion _may_ happen */
                elem_[ i ] = otherStack.elem_[ i ];
            }
            top_ = otherStack.top_;
        }

        bool empty() { 
            return top_== 0; 
        }
        
        void push( const T& t ) { 
            elem_[ top_++ ] = t; 
        }
        
        T pop() { 
            return elem_[top_];
        }
    private:
        int top_;
        T elem_[10];
    };
    
    /*
    Most specified definition is always used

    template<typename T>
    class Stack<T*>{

    };

    template<>
    class Stack<int>{

    };
    */
}