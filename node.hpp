/*
 * node.hpp
 *
 */

#pragma once

class position
{
private:
	int x;
	int y;
public:
	position();
	position(int x, int y);
	int getX();
	int getY();
};

class Node {
private:
	position data;
	Node* ptrNext;
public:
	Node();
	Node(position _data, Node* next = nullptr);
	void setData(position _data);
	void setNext(Node* _next);
	position getData();
	Node* getNext();
	void print();
	virtual ~Node();
};



