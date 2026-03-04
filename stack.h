#ifndef stack_h
#define stack_h
#include "node.h"
#include <iostream>
using namespace std;

class Stack {
	NodePtr top;
	int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
};

Stack::Stack(){
    top = NULL;
    size = 0;
}

void Stack::push(int x){
    NodePtr new_node = new NODE(x);
    if(new_node){
        // link to the previous top->set_next
        new_node->set_next(top);

        //change the top
        top = new_node;

        //increases the size
        size++;
        // Left missing for exercises…
    }
}

int Stack::pop(){
    if(top == NULL){
        return -1;   // be careful of the empty stack!!!
    }

    NodePtr t = top;
    int value;
    value = t->get_value();

    // Left missing part for exercises
    top = t->get_next();

    delete t;
    size--;

    return value;
    //be careful of the empty stack!!!
}

Stack::~Stack(){
    cout<<"Clearing all nodes"<<endl; 
    while(size>0) pop();
    //delete all remaning stack (i.e. pop all)
}

#endif
