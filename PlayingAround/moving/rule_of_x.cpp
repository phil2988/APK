
/*
    RULE OF 3 - Classic statement
    
    If you need to supply one ot these 3, you probably need to supply all 3
    - copy constructor
    - assiqnment operator
    - destructor - May be omitted it RAi/ is used

    Important
    - Compiler a/ways supplies a default version if need be
    When do you implement them?
    - When you have some resource that needs special care

    RULE OF 5 - New statement
    
    If you need to one these 5, you probably need to supply all 5
    - copy constructor
    - copy assignment operator
    - move constructor
    - move operator
    - destructor- May be omitted if RAII is used

    Important
    - If copy constructor and/or copy assignment operator implemented
        - Neither move constructor nor move assignment exist - safety measure
        - if move is forced => copy contructor/assignment called
            - If move constructor/assignment is deleted => compile error 
    - If move constructor and/ or move assignment operator implemented
        - NO copy constructor nor copy assignment exist
            - Implicit deleted
            - lf copy construction/assignment is tried => compile error

    
    When do you implement them?
        - When you have some resource that needs special care
    Categories, where none/some/all of these are created and their usages
        - None - Simple and no need - implicits are ok
        - Copy constructor, copy assign and destructor => Copyable, NOT movable
        - Move constructor, move assign and destructor => Movable, NOT copyable
        - All - everything
*/