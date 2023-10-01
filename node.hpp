/*
 * node.hpp
 *
 */

#pragma once

#include <iostream>

class Node {
private:
	std::pair<int,int> data;
	Node* ptrNext;
public:
	Node();
	Node(std::pair<int,int> _data, Node* next = nullptr);
	void setData(std::pair<int,int> _data);
	void setNext(Node* _next);
	std::pair<int,int> getData();
	Node* getNext();
	void print();
	virtual ~Node();
};
