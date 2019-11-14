#pragma once
#include <string>
#include <iostream>
using namespace std;

template<typename E> class Stack; // forward declare

template <typename E>
class Node			// linked list node
{
private:
     E elem;			// linked lst element value
     Node<E>* next;	     // next item on list
     friend class Stack<E>;
};

template <typename E>
class Stack			// stack using linked lst
{
private:
     int n;		     // number of elements
     Node<E>* head;
public:
     Stack();		        // constructor
     int size() const;	   // number of items on stack
     bool empty() const;    // checks if stack empty
     const E& top();	   // top element
     void push(const E& e); // push element onto stack
     void pop();	    	// pop stack
};


/////////////////////////////////////////////////
// FUNCTIONS PLACED BELOW DUE TO LINKING ISSUE //
/////////////////////////////////////////////////


template <typename E>
Stack<E>::Stack()
{
     n = 0;
     head = NULL;
}

template <typename E>
void Stack<E>::push(const E& e)	// insert element at beginning
{
     Node<E>* temp = new Node<E>;	// new node temp and allocate memory

     if (!temp)				// check if stack full.
     {
          cout << "Stack Overflow.\n";
          exit(1);
     }

     temp->elem = e;		// initialize data into temp data field
     temp->next = head;	    // put top pointer ref into temp next
     head = temp;		 	// make temp as top of stack
     n++;
}

template <typename E>
bool Stack<E>::empty() const			// check is stack empty
{
     return head == NULL;
}

template <typename E>
const E &Stack<E>::top()		// returns top element on stack
{
     if (!empty())			// checks for empty stack
     {
          return head->elem;
     }
     cout << "Top of empty stack.\n";
}

template <typename E>
void Stack<E>::pop()
{
     Node<E>* temp = new Node<E>;	// new node temp and allocate memory

     if (head == NULL)		     // checks for stack underflow
     {
          cout << "Stack Underflow.\n";
          exit(1);
     }

     temp = head;		     // top assign into temp
     head = head->next;		// assign second node to top
     temp->next = NULL;		// destroy connection between first and second
     delete temp;
     n--;
}

template <typename E>
int Stack<E>::size() const
{
     return n;
}



