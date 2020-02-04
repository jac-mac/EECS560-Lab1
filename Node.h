#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
	private:
	Node<T>* next; //points to a "next" Node
	T item; //item to be stored in the Node

	public:
		/*
	   *@pre None.
	   *@post Creates a Node containing anItem
	   *@param anItem is some type to be stored in this Node
	   *@return None.
	   */
	Node<T>(T anItem);

	/*
   *@pre None.
   *@post Creates a Node containing anItem and a pointer pointing to the next Node
   *@param anItem is some type to be stored in this Node
	 *@param nextNode is the pointer to the "next" Node
   *@return None.
   */
	Node<T>(T anItem, Node<T>* nextNode);

	/*
	 *@pre A Node must have a "next" Node to point to and retrieve.
	 *@post None.
	 *@param None.
	 *@return Returns the pointer to the "next" Node.
	 */
	Node<T>* getNext();

	/*
   *@pre A Node must be created and with some type and value passed into the Node.
   *@post None.
   *@param None.
   *@return Returns the value stored inside of the *this* Node.
   */
	T getEntry();

	/*
	 *@pre Some Node has to have been created beforehand.
	 *@post Sets the next pointer to another pointer pointing to a Node.
	 *@param nextNode points to either null or another Node.
	 *@return None.
	 */
	void setNext(Node<T>* nextNode);

	/*
   *@pre Some Node has to have been created beforehand.
   *@post Sets the value of item to anItem
   *param anItem is a value of templated type T to be stored in.0
   *return None.
   */
	void setEntry(T anItem);
};
#include "Node.cpp"
#endif
