/* 
 * Stack.cpp
 *
 * Description: 
 *     Implementation of a stack using an int singly linked list in 
 *     which the top of the stack is at the tail of the list
 * 
 * Class Invariant: 
 *     Node in the stack are in LIFO order. Data pushed into nodes
 *     must be of type int. Each not is of type StackNode.
 * 
 *
 * Author: Kai Sackville-Hii 
 * Date: Feb 6, 2019
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

        // Desc: Deconstructor
        // Post: Dynamically allocated heap memory is freed.  
        ~Stack();

        // Desc:  Insert element x to the top of the stack.
        // Post:  New Node will be created and pushed to the tail of the list (top of stack).
        void push(int x);

        // Desc: Remove and return element at the top of the stack.
        // Pre: Stack must not be empty
        // Post: Node at the top of stack will be popped, tail will point to the next 
        //       Node on the stack. The data of the popped node will be returned. 
        int pop();

        // Desc: Return the topmost element of the stack.
        // Pre: Stack must not be empty.
        // Post: Data of the top node of the stack will be returned.
        int peek() const;

        // Desc: Checks if stack is empty or not
        // Post: If the stack is empty will return true, else false
        bool isEmpty() const;

        // Desc: Pretty print for the current stack
        // Post: Stack will be printed in a list form, If the stack is empty you will print error message
        void printStack() const;
};


