#include "node.h"

template <class Type>
node<Type>::node()
{
}

template <class Type>
node<Type>::~node() // powinien sam naprawiac powiazania listy powstale po ich usunieciu
{
	if (previous == nullptr && next != nullptr)
		next->previous = nullptr;
	if (previous != nullptr && next == nullptr)
		previous->next = nullptr;
	if(next!=nullptr && previous!= nullptr)
		next->previous = previous;
	if (previous != nullptr && next != nullptr)
		previous->next = next;

	next = nullptr;
	previous = nullptr;
}

template <class Type>
node<Type>::node(const Type& data)
{
	this->data = data;
}

template <class Type>
Type node<Type>::getitem()
{
	return this->data;
}