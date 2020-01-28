#include <string>
#include <cmath>

template <typename T>
LinkedList<T>::LinkedList()
{
	firstPtr = nullptr;
	itemCount = 0;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	if(firstPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
int LinkedList<T>::getLength() const
{
	return itemCount;
}

template <typename T>
void LinkedList<T>::insert(int position, T entry) throw (std::runtime_error)
{
	if(isEmpty())
	{
		firstPtr = new Node<T>(entry);
		itemCount = itemCount + 1;
	}

	else if(!(isEmpty()) && position == 1)
	{
		Node<T>* current = firstPtr;
		Node<T>* previous = nullptr;
		for(int i = 1; i < position; i++)
		{
			previous = current;
			current = current->getNext();
		}
		previous = new Node<T>(entry);
		itemCount = itemCount + 1;
		previous->setNext(current);
		firstPtr = previous;
	}

	else if(!(isEmpty()) && position > 1 && position <= itemCount + 1)
	{
		Node<T>* current = firstPtr;
		Node<T>* previous = nullptr;
		Node<T>* newNode;
		for(int i = 1; i < position; i++)
		{
			previous = current;
			current = current->getNext();
		}
		newNode = new Node<T>(entry);
		itemCount = itemCount + 1;
		newNode->setNext(current);
		previous->setNext(newNode);
	}

	else if(!(isEmpty()) && (position < 1 || position > itemCount + 1))
	{
		throw std::runtime_error("ERROR. Invalid position!\n");
	}
}

template <typename T>
void LinkedList<T>::remove(int position) throw (std::runtime_error)
{
	if(isEmpty() || position < 1 || position > itemCount)
	{
		throw std::runtime_error("List is empty or the position you inserted is invalid!");
	}

	else if(!(isEmpty()) && position == 1)
	{
		Node<T>* current = nullptr;
		if(firstPtr->getNext() != nullptr)
		{
			current = firstPtr->getNext();
		}
		delete firstPtr;
		itemCount = itemCount - 1;
		firstPtr = current;
	}

	else if(!(isEmpty()) && position > 1 && position <= itemCount)
	{
		Node<T>* current = firstPtr;
		Node<T>* previous = nullptr;
		for(int i = 1; i < position; i++)
		{
			previous = current;
			current = current->getNext();
		}
		previous->setNext(current->getNext());
		delete current;
	}
}

template <typename T>
void LinkedList<T>::clear()
{
	Node<T>* current;
	while(firstPtr->getNext() != nullptr)
	{
		current = firstPtr;
		firstPtr = firstPtr->getNext();
		delete current;
	}
	delete firstPtr;
}

template <typename T>
T LinkedList<T>::getEntry(int position) const throw (std::runtime_error)
{
	if(isEmpty())
	{
		throw std::runtime_error("List is empty!\n");
	}

	else if(!(isEmpty()) && position > 0 && position <= itemCount)
	{
		Node<T>* current = firstPtr;
		for(int i = 1; i < position; i++)
		{
			current = current->getNext();
		}
		return current->getEntry();
	}

	else if(position < 1 || position > itemCount)
	{
		throw std::runtime_error("None.");
	}

}

template <typename T>
void LinkedList<T>::replace(int position, T newEntry) throw (std::runtime_error)
{
	if(isEmpty())
	{
		throw std::runtime_error("List is empty!\n");
	}

	else if(!(isEmpty()) && position > 0 && position <= itemCount)
	{
		Node<T>* current = firstPtr;
		for(int i = 1; i < position; i++)
		{
			current = current->getNext();
		}
		current->setNext(newEntry);
	}

	else if(position < 1 || position > itemCount)
	{
		throw std::runtime_error("Invalid position!\n");
	}
}

template <typename T>
void LinkedList<T>::reverse() throw (std::runtime_error)
{
	int numOfSwaps = floor(itemCount/2);
	Node<T>* swapBack = firstPtr;
	Node<T>* swapFront = firstPtr;
	if(isEmpty())
	{
		throw std::runtime_error("List is empty!\n");
	}
	else
	{
		for(int i = 0; i < numOfSwaps; i++)
		{
			for(int j = 0; j < (itemCount-1)-i; j++)
			{
				swapBack = swapBack->getNext();
			}

			for(int j = 0; j < i; i++)
			{
				swapFront = swapFront->getNext();
			}
			T front = swapFront->getEntry();
			T back = swapBack->getEntry();

			swapFront->setEntry(back);
			swapBack->setEntry(front);
		}
	}
}
