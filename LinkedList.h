#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <stdexcept>

template <typename T>
class LinkedList
{
	private:
	Node<T>* firstPtr;
	int itemCount;

	public:
	LinkedList();
  bool isEmpty() const;
 	int getLength() const;
 	void insert(int position, T entry) throw (std::runtime_error);
	void remove(int position) throw (std::runtime_error);
	void clear();
	T getEntry(int position) const throw (std::runtime_error);
  void replace(int position, T newEntry) throw (std::runtime_error);
	void reverse() throw (std::runtime_error);
};
#include "LinkedList.cpp"
#endif
