namespace stack
{

    template <typename T>
    struct Stack
    {

        // TODO - think about automatic type deduction Stack<int>
        Stack();
        //~Stack();  // manage proper with RAII resources

        /**
         *  @brief copy constructor
         *  @param ref reference to Stack<T> object
         */
        Stack(Stack const &ref);

        /**
         *  @brief assignement operator
         *  @param ref reference to Stack<T> object
         *  @return reference to Stack<T>
         */
        Stack &operator=(Stack const &ref);

        /**
         *  @brief move constructor
         *  @param mv r-reference to Stack<T> object
         */
        Stack(Stack &&mv) noexcept;

        /**
         *  @brief move operator
         *  @param mv r-reference to Stack<T> object
         *  @return reference to Stack<T> object
         */
        Stack &operator=(Stack &&mv) noexcept;

        // think about good API

        /**
         *  @brief gets top value from Stack
         *  @returns reference to T type
         */
        T &top() const;


        /**
         *  @brief inserts elements at the top
         *  @param elem elemet to be pushed on top
         * 
         *  Rationale for declaring function parameter as pass by copy:
         *  Due to fact that passing argument by value is only expensive if 
         *  we pass an lvalue and compilator tries to make copying cheap.
        */
        void push(T elem); // create template function for push 

        /**
         *  @brief removes the top element
         */
        void pop();

        /**
         *  @brief checks whether the underlying container is empty
         */
        bool empty();

        /**
         *  @brief returns the number of elements
         */
        std::size_t size();
    };

} // stack
