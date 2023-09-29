/*
 * node.hpp
 *
 */

#pragma once

class Node {
private:
	char data;
	Node* ptrNext;
public:
	Node();
	Node(char _data, Node* next = nullptr);
	void setData(char _data);
	void setNext(Node* _next);
	char getData();
	Node* getNext();
	void print();
	virtual ~Node();
}; 