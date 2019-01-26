/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
 */
 
class Stack {

    private:

        // Desc:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        

        // Desc:  head = ptr to the first StackNode (NULL if empty)
        //        tail = ptr to the last StackNode (NULL if empty)
        //  Inv:  Follows the A2 Spec, namely that the implementation 
        //        is a singly-linked list, with insert/remove 
        //        operations at the list's tail.
        StackNode * head;
        StackNode * tail;

    public:

        // Desc:  Constructor
        // Post:  Stack is empty
        Stack();


        // Desc:  
        // Post:  
        ~Stack();


        // Desc:  Insert element x to the top of the stack.
        // Post:  
        void push(int x);


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  
        // Post:  
        int pop();


        // Desc:  Return the topmost element of the stack.
        //  Pre:  
        // Post:  
        int peek() const;


        // Desc:  
        // Post:  
        bool isEmpty() const;
};


