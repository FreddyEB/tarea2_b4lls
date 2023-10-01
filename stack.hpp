#pragma once
#include "node.hpp"

class Stack {
private:
	Node* head;
public:
	Stack();
	void push(std::pair<int,int> val);
	void push(Node* node);
	void pop();
	Node* top();
	bool isEmpty();
	void clear();
	virtual ~Stack();
};
