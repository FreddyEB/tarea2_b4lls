/*
 * queue.hpp
 *
 *  Created on: Aug 18, 2022
 *      Author: jsaavedr
 */
#pragma once
#include "node.hpp"

class Queue {
private:
	Node* head;
	Node* tail;
public:
	Queue();
	void push(std::pair<int,int> val);
	void push(Node* node);
	void pop();
	Node* top();
	bool isEmpty();
	void clear();
	virtual ~Queue();
};
