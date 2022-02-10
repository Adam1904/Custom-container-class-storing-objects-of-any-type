#pragma once

template <class Type>
class node
{
public:
	node* next = nullptr;
	node* previous = nullptr;

	node();
	~node();
	node(const Type& data); // konstruktor z parametrem

	Type getitem();

	Type data;
};

