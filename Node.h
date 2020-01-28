#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
	private:
	Node<T>* next;
	T item;

	public:
	Node<T>(T anItem);
	Node<T>(T anItem, Node<T>* nextNode);

	Node<T>* getNext();
	T getEntry();

	void setNext(Node<T>* nextNode);
	void setEntry(T anItem);
};
#include "Node.cpp"
#endif
