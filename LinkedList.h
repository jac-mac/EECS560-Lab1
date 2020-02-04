#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class LinkedList
{
	private:
	Node<T>* firstPtr;
	int itemCount;

	public:
		/*
	   *@pre None.
	   *@post Creates an empty LinkedList.
	   *@param None.
	   *@return None.
	   */
	LinkedList();

	/*
   *@pre A LinkedList has to be created.
   *@post Checks to see if the LinkedList has any Nodes occupying it.
   *@param None.
   *@return True if no Nodes present, False otherwise.
   */
  bool isEmpty() const;

	/*
   *@pre None.
   *@post Calculates how many Nodes are occupying the LinkedList.
   *@param None.
   *@return Returns the int value of how many Nodes there are.
   */
 	int getLength() const;

	/*
   *@pre A LinkedList, whether it's empty or not, has to be created.
   *@post Inserts a Node into the LinkedList
   *@param position is the position in the LinkedList to insert the Node
	 *@param entry is the value you want to pass into the Node
   *@return None.
   */
 	void insert(int position, T entry) throw (std::runtime_error);

	/*
   *@pre A LinkedList, whether it's empty or not, has to be created.
   *@post Removes a Node from the LinkedList
   *@param entry is the value you want to remove from the LinkedList
	 *@param dummy is some unused parameter needed to "overload" the remove function.
	 *Having only one parameter entry would not work since it's templated, so any overload
	 *of the function remove with only one parameter would essentially act the same as this
	 *one if only entry is the one parameter.
   *@return
   */
	void remove(T entry, int dummy) throw (std::runtime_error);

	/*
   *@pre A LinkedList, whether it's empty or not, has to be created.
   *@post Removes a Node from the LinkedList
   *@param position is the position in the LinkedList from which you want to remove.
   *@return None.
   */
	void remove(int position) throw (std::runtime_error);

	/*
   *@pre A LinkedList, whether it's empty or not, has to be created.
   *@post Deletes all Nodes in a LinkedList
   *@param None.
   *@return None.
   */
	void clear();

	/*
   *@pre A LinkedList must exist, and the position must be greater than 1 and less than itemCount
   *@post Hands back the entry of a particular Node at position position
   *@param position is an int, 1<=position<=itemCount.
   *@return Returns the entry of the Node at position position.
   */
	T getEntry(int position) const throw (std::runtime_error);

	/*
   *@pre A LinkedList must exist, and the position must be greater than 1 and less than itemCount
   *@post Replaces a value of a Node with another at a certain position.
   *@param position is the position of the Node in the LinkedList you want to modify
	 *@param newEntry is the value you want to replace in that Node
   *@return None.
   */
  void replace(int position, T newEntry) throw (std::runtime_error);

	/*
   *@pre A LinkedList must exist and have some Nodes populating it.
   *@post Reverses the order of the LinkedList
   *@param None.
   *@return None.
   */
	void reverse() throw (std::runtime_error);
};
#include "LinkedList.cpp"
#endif
