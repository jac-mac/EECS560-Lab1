template <typename T>
Node<T>::Node(T anItem)
{
	item = anItem;
	next = nullptr;
}

template <typename T>
Node<T>::Node(T anItem, Node<T>* nextNode)
{
	item = anItem;
	next = nextNode;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template <typename T>
T Node<T>::getEntry()
{
	return item;
}

template <typename T>
void Node<T>::setNext(Node<T>* nextNode)
{
	next = nextNode;
}

template <typename T>
void Node<T>::setEntry(T anItem)
{
	item = anItem;
}
