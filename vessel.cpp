#include <iostream>
#include <cstdlib>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "vessel.h"


using namespace std;


template<class Type>
vessel<Type>::vessel() // domyslnie pusty kontener 
{
	head = nullptr;
	tail = nullptr;
}

template <class Type>
vessel<Type>::~vessel()
{
	while (head != nullptr)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <class Type>
vessel<Type>::vessel(const Type& data) // konstukror z parametrem
{
	node<Type>* head = new node<Type>(data);
	head->next= nullptr;
	head->previous = nullptr;
	tail = head;
}

template <class Type>
void vessel<Type>::insert(const Type& new_data)
{
	node<Type>* temp1 = new node<Type>{new_data};
	this->insert(temp1);
	temp1 = nullptr;
}

template <class Type>
void vessel<Type>::insert(node<Type>* newnode)
{
	if (head==nullptr)
	{
		head = newnode;
		newnode->previous = nullptr;
		newnode->next = nullptr;
		tail = newnode;
		this->counter++;
	}
	else
	{
		newnode->next = head;
		newnode->previous = nullptr;
		head->previous = newnode;
		head = newnode;
		this->counter++;
	}
}

template <class Type>
void vessel<Type>::insert_end(const Type& new_data)
{
	node<Type>* temp = new node<Type>(new_data);
	this->insert_end(temp);
	temp = nullptr;
}

template <class Type>
void vessel<Type>::insert_end(node<Type>* newnode)
{
	if (head == nullptr)
	{
		head = newnode;
		newnode->next = nullptr;
		newnode->previous = nullptr;
		tail = newnode;
		this->counter++;
	}
	else
	{
		newnode->previous = tail;
		tail->next = newnode;
		newnode->next = nullptr;
		tail = newnode;
		this->counter++;
	}
}

template <class Type>
void vessel<Type>::erase()
{
	if (head == nullptr)
		throw string("Kontener typu vessel nie posiada zadnych elementow w swojej bazie danych...");

	if (head == tail)
	{
		temp = head;
		head = nullptr;
		tail = nullptr;
		delete temp;
		--(this->counter);
	}
	else
	{
		temp = head;
		head = head->next;
		head->previous = nullptr;

		if (temp != nullptr)
			delete temp;
		--(this->counter);
	}
}

template <class Type>
void vessel<Type>::erase_end()
{
	node<Type>* temp1 = new node<Type>;
	if (head == nullptr)
	throw string("Kontener typu vessel nie posiada zadnych elementow w swojej bazie danych...");

	if (head == tail)
	{
		temp = head;
		head = nullptr;
		tail = nullptr;
		delete temp;
		--(this->counter);
	}
	else
	{
		temp = tail;
		tail = tail->previous;
		tail->next = nullptr; 

		delete temp;
		--(this->counter);
	}
}

template <class Type>
vessel<Type>::vessel(vessel<Type>& copy) // konstruktor kopiujacy
{

	if (copy.head == nullptr)
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->counter = 0;
	}
	else
	{
		temp = copy.head;

		for (int i = 0; i < copy.counter; i++)
		{
			if(temp != nullptr)
				this->insert_end(temp->data);
			temp = temp->next;
		}

		temp = nullptr;
	}
}

template <class Type>
bool vessel<Type>::operator==(const vessel<Type>& copy)
{
	if (copy.head == nullptr && this->head == nullptr)
		throw string("Obie listy sa puste!!!");
	if (copy.head != nullptr && this->head == nullptr)
		return false;
	if (copy.head == nullptr && this->head != nullptr)
		return false;
	if (this->counter != copy.counter)
		return false;
	node<Type>* temp1 = copy.head;
	node<Type>* temp2 = head;

	while (temp1!=nullptr && temp2!=nullptr)
	{
		if (temp1->data != temp2->data)
			return false;

		temp2 = temp2->next;
		temp1 = temp1->next;
	}

	return true;

	temp1 = nullptr;
	temp2 = nullptr;
}

template <class Type>
vessel<Type>& vessel<Type>::operator=(const vessel<Type>& copy)
{
	if (copy.counter != this->counter)
	{
		int roznica;
		if (copy.counter > this->counter)
		{
			roznica = copy.counter - this->counter;
			for (int i = 0; i < roznica; i++)
				this->insert(Type());
		}
		else if (copy.counter < this->counter)
		{
			roznica = this->counter - copy.counter;
			for (int i = 0; i < roznica; i++)
				this->erase();
		}
		else
			throw string("Nie da sie wczytac listy!!!!, pojawil sie blad");
	}

	node<Type>* temp = this->head;
	node<Type>* temp2 = copy.head;
	while (temp!=nullptr && temp2 != nullptr)
	{
		temp->data = temp2->data;
		temp2 = temp2->next;
		temp = temp->next;
	}

	return *this;
}

template <class Type>
void vessel<Type>::swap(int first, int second) // poprawiona metoda
{
	node<Type>* temp1 = new node<Type>; // pomocnicze ktore beda wskazywac na elementy ktore chcemy ze soba zamienic
	node<Type>* temp2 = new node<Type>;
	temp1 = this->head;
	temp2 = this->head;

	if (this->counter < second || this->counter < first || second < 1 || first < 1)
		throw string("Nie ma takiego elementu w kontenerze");

	int pomocnicza = 1; 
	int pomocnicza2 = 1;

	while (pomocnicza != (first))
	{
		temp1 = temp1->next;
		pomocnicza++;
	}
	while (pomocnicza2 != (second))
	{
		temp2 = temp2->next;
		pomocnicza2++;
	}
	
	if(temp1==temp2)
		throw string("Wybrano takie same elementy do zamiany!");

	if (temp1 == nullptr && temp2 == nullptr)
		throw string("Oba elementy sa puste!");

	if (temp1!=nullptr && temp2!=nullptr)
	{
		Type kopia = temp1->data;
		temp1->data = temp2->data;
		temp2->data = kopia;
	}

	temp1 = nullptr;
	temp2 = nullptr;
}

template <class Type>
void vessel<Type>::print_vessel()
{
	temp = head;
	cout << "\n\nZawartosc listy dwukierunkowej typu [vessel]:" << endl;


	for (int i = 0; i < this->counter; i++)
	{
		if (temp==nullptr)
			throw string("Element poza zakresem!!!, wystapil blad ze zmienna zliczajaca elementy listy!!!");
		if(i<9)
			cout << (i+1) << "_element:  " << std::setw(2) << temp->data << endl;
		else if(i>9)
			cout << (i + 1) << "_element: " << std::setw(2) << temp->data << endl;
		temp = temp->next;
	}
}

template <class Type>
void vessel<Type>::print_vessel_reverse()
{
	temp = tail;
	cout << "\n\nZawartosc listy dwukierunkowej OD KONCA typu [vessel]:" << endl;


	for (int i = 0; i < this->counter; i++)
	{
		if (temp == nullptr)
			throw string("Element poza zakresem!!!, wystapil blad ze zmienna zliczajaca elementy listy!!!");

		cout << (this->counter - i) << "-ego element: " << temp->data << endl;
		temp = temp->previous;
	}
}

template <class Type>
std::ostream& operator<<(std::ostream& s, const node<Type>& v)
{
	s << v.data;
	return s;
}

template <class Type>
std::istream& operator>>(std::istream& s, const node<Type>& v)
{
	s >> v.data;
	return s;
}

template <class Type>
void vessel<Type>::save()
{
	temp = this->head;
	if(head == nullptr)
		throw string("Nie ma co zapisywac, lista jest pusta!");

	fstream plik;
	plik.open("zapis.txt", ios_base::out);

	if (plik.good())
	{
		plik << this->counter << " " << endl;
		while (temp != nullptr)
		{
			plik << temp->data << endl;
			temp = temp->next;
		}
	}
	else
		throw string("Nie udalo siê otworzyc pliku zapis.txt!!!");

	plik.close();
}

template <class Type>
void vessel<Type>::read()
{
	ifstream plik;
	plik.open("zapis.txt");

	if (plik.good())
	{
		int pomocnicza;
		plik >> pomocnicza;
		if (pomocnicza != this->counter)
		{
			int roznica;
			if (pomocnicza > this->counter)
			{
				roznica = pomocnicza - this->counter;
				for (int i = 0; i < roznica; i++)
					this->insert(Type());
			}
			else if(pomocnicza < this->counter)
			{
				roznica = this->counter - pomocnicza;
				for (int i = 0; i < roznica; i++)
					this->erase();
			}
			else
				throw string("Nie da sie wczytac listy!!!!, pojawil sie blad");
		}

		node<Type>* temp = head;
		while (temp != nullptr)
		{
			plik >> temp->data;
			temp = temp->next;
		}
	}
	else
		throw string("Nie udalo siê otworzyc pliku zapis.txt");

	plik.close();
}

template <class Type>
int vessel<Type>::get_counter()
{
	return this->counter;
}

template <class Type>
void vessel<Type>::erase_element(int i)
{
	if (i > counter || i < 0)
		throw string("Kontener typu vessel nie posiada takich elementow w swojej bazie danych...");
	else if (head == nullptr && i != 1)
		throw string("Kontener typu vessel nie posiada takich elementow w swojej bazie danych...");
	else if (i == 1 && head!=nullptr &&(head->next == nullptr))
	{
		this->erase();
	}
	else if (i == 1 && head!=nullptr && head->next != nullptr)
	{
		this->erase();
	}
	else if (i == this->counter)
	{
		this->erase_end();
	}
	else if(i>1)
	{
		node<Type>* temp = new node<Type>;
		temp = head;
		int pomocnicza = 1;
		while (pomocnicza != i)
		{
			temp = temp->next;
			pomocnicza++;
		}

		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
		
		temp->next = nullptr;
		temp->previous = nullptr;
		delete temp;
		temp = nullptr;

		this->counter--;
	}
}

template <class Type>
void vessel<Type>::insert_element(int i, const Type& new_data)
{
	if (counter==0 && i == 1)
		this->insert(new_data);
	else if(i > counter || i < 0)
	{
		throw string("Nie mozna dodac elementu na to miejsce");
	}
	else if (head == nullptr && i!=1)
		throw string("testKontener typu vessel nie posiada takich elementow w swojej bazie danych...");
	else if (i == 1)
	{
		node<Type>* newnode = new node<Type>(new_data);
		this->insert(newnode);
	}
	else if (i>1)
	{
		node<Type>* newnode = new node<Type>(new_data);
		temp = head;
		int pomocnicza = 1;
		while (pomocnicza != i)
		{
			temp = temp->next;
			pomocnicza++;
		}

		if (temp == tail)
		{
			newnode->next = nullptr;
			temp->next = newnode;
			newnode->previous = temp;
		}
		else
		{
			temp->previous->next = newnode;
			newnode->previous = temp->previous;
			temp->previous = newnode;
			newnode->next = temp;
		}

		this->counter++;
	}
}

template <class Type>
vessel<Type>& vessel<Type>::operator+=(const vessel<Type>& copy)
{
	node<Type>* temp = copy.head;

	for (int i = 0; i < copy.counter; ++i)
	{
		node<Type>* newnode = new node<Type>;
		newnode->data = temp->data;
		this->insert(newnode);
		temp = temp->next;
	}

	return *this;
}

template <class Type>
Type& vessel<Type>::operator[](int i)
{
	if (i > (this->counter) || i < 1)
		throw string("Kontener typu vessel nie posiada takich elementow w swojej bazie danych...");


	node<Type>* temp = head;
	int pomocnicza = 1; // poprawione :)
	while (pomocnicza != i)
	{
		temp = temp->next;
		pomocnicza++;
	}

	return temp->data;
}