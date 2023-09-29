/*
 * stack.hpp
 *
 *  Created on: Aug 18, 2022
 *      Author: jsaavedr
 */

#pragma once

#include "node.hpp"

class Stack {
private:
	Node* head;
public:
	Stack();
	void push(Node* node);
	void pop();
	Node* top();
	bool isEmpty();
	void clear();
	virtual ~Stack();
};