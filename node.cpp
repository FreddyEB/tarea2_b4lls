/*
 * nodo.cpp
 */

#include "node.hpp"
#include <iostream>

position ::position(): x(0), y(0) {

}

position::position(int x, int y) {
	this->x = x;
	this->y = y;
}

int position::getX() {
	return this->x;
}

int position::getY() {
	return this->y;
}

Node::Node(): data(position()), ptrNext(nullptr) {
}

Node::Node(position pos, Node* next): data(pos), ptrNext(next) {

}

void Node::setData(position _data){
	data = _data;
}

void Node::setNext(Node* next){
	ptrNext = next;
}

position Node::getData(){
	return data;
}
Node* Node::getNext(){
	return ptrNext;
}

void Node::print(){
	std::cout << data.getX() << ',' << data.getY();
}

Node::~Node() {

}