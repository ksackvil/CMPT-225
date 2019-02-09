
class Stack {
    private:

        // Desc:  Implemented by a static array arr[].
        //        Stack contains len elements.
        //        Top of the stack is at index len-1.
        static const unsigned S_CAP = 20;
        int arr[S_CAP];
        unsigned len;


    public:

        // Desc:  Constructor
        Stack();
        bool isEmpty() const;


        // Desc:  Insert element x to the top of the stack.
        void push(int x);


        // Desc:  Remove and return element at the top of the stack.
        int pop();


        // Desc:  Removes and returns the max element.
        //        In case of duplicated max, take the one closest to the top.
        //  Pre:  Stack nonempty
        // Post:  Order of remaining elements is preserved
        int removeMax();

};

