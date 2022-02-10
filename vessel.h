#pragma once
#include "node.h"
#include <iostream>
#include <string>


template <class Type>
class vessel // kontener
{
public:
	/* --------- KONSTRUKTORY I DESTRUKTOR --------- */
	vessel();
	vessel(const Type& copy);
	vessel(vessel<Type>& copy); // konstuktor kopiujacy
	~vessel();


	/* --------- METODY --------- */
	void insert(const Type& new_data);
	void insert(node<Type>* newnode);
	void insert_end(const Type& new_data);
	void insert_end(node<Type>* newnode);
	void insert_element(int i, const Type& new_data);
	void erase();
	void erase_end();
	void erase_element(int i);
	void swap(int first, int second);
	void print_vessel();
	void print_vessel_reverse();
	void save();
	void read();
	int get_counter();


	/* --------- OPERATORY --------- */
	Type& operator[](int i);
	vessel<Type>& operator+=(const vessel<Type>& copy);
	vessel<Type>& operator=(const vessel<Type>& copy);
	bool operator==(const vessel<Type>& copy);


private:
	node<Type>* head = nullptr;
	node<Type>* tail = nullptr;


	node<Type>* temp= nullptr; // pomocniczy wezel 


	int counter = 0; // element zliczajacy ile jest wezlow 


	friend std::ostream& operator<<(std::ostream& s, const node<Type>& v);
	friend std::istream& operator>>(std::istream& s, const node<Type>& v);
};


/* --------- OPERATORY STRUMIENIOWE--------- */
template <class Type>
std::ostream& operator<<(std::ostream& s, const node<Type>& v);
template <class Type>
std::istream& operator>>(std::istream& s, const node<Type>& v);