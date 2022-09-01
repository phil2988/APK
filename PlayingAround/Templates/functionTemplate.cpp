namespace templates{
    template<typename T>
    void splice(T t1, T t2){
        while (!t1.empty())
        {
            t2.push(t1.pop());
        }
    }

    // Type can explicitly be specified - Done if compiler cannot guess
    // Type U can be deduced
    // T cannot - since it is not an input parameter
    // Needs specification

    template<typename T, typename U>
    T implicit_cast(U u){
        return u;
    }   
}