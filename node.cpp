/*
 * nodo.cpp
 */

#include "node.hpp"
#include <iostream>

Node::Node(): data({-1, -1}), ptrNext(nullptr) {
}

Node::Node(std::pair<int,int> val, Node* next): data(val), ptrNext(next) {

}

void Node::setData(std::pair<int,int> _data){
	data = _data;
}

void Node::setNext(Node* next){
	ptrNext = next;
}

std::pair<int,int> Node::getData(){
	return data;
}
Node* Node::getNext(){
	return ptrNext;
}

void Node::print(){
	std::cout << data.first << ' ' << data.second ;
}

Node::~Node() {

}
