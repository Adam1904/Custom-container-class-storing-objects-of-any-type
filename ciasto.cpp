#include "ciasto.h"
#include <iostream>
#include <string>

int ciasto::ile_obiektow_ciasto = 0;

ciasto::ciasto()
{
	ile_obiektow_ciasto++;
	this->nazwa_ciasta = "brak";
	this->cena = 0.01;
	this->kolor = "brak";
	this->rodzaj = "brak";
}
ciasto::ciasto(const ciasto& ci) // konstruktor kopiujacy
{
	ile_obiektow_ciasto++;
	this->nazwa_ciasta = ci.nazwa_ciasta;
	this->cena = ci.cena;
	this->kolor = ci.kolor;
	this->rodzaj = ci.rodzaj;
}
ciasto::ciasto(std::string nazwa_ciasta, std::string kolor, std::string rodzaj, double cena)
{
	ile_obiektow_ciasto++;
	this->nazwa_ciasta = nazwa_ciasta;
	this->cena = cena;
	this->kolor = kolor;
	this->rodzaj = rodzaj;
}

ciasto::~ciasto()
{
	ile_obiektow_ciasto--;
}

bool ciasto::operator!=(const ciasto& ci)
{
	if (this->cena != ci.cena)
		return true;
	if (this->kolor != ci.kolor)
		return true;
	if (this->nazwa_ciasta != ci.nazwa_ciasta)
		return true;
	if (this->rodzaj != ci.rodzaj)
		return true;
	else
		return false;
}

ciasto::operator int() // definicja operatora konwersji na typ int
{
	return (int)cena; // zwraca cene calkowita
}

ciasto& ciasto::operator+(double dodaj_kwote) // operator dodawania
{
	this->cena += dodaj_kwote; // dodaje do ceny ciasta wartosc "dodaj_kwote"
	return *this;
}

ciasto& ciasto::operator=(const ciasto& cia)
{
	this->cena = cia.cena;
	this->kolor = cia.kolor;
	this->nazwa_ciasta = cia.nazwa_ciasta;
	this->rodzaj = cia.rodzaj;

	return *this;
}

void ciasto::wyswietlcene()
{
	std::cout << "Cena ciasta " << this->nazwa_ciasta << " wynosi: " << this->cena << " PLN" << std::endl;
}

void ciasto::ustaw_cene(double nowa_cena)
{
	this->cena = nowa_cena;
}

void ciasto::ustaw_nazwa_ciasta(std::string nazwa_cukierni)
{
	this->nazwa_ciasta = nazwa_cukierni;
}

void ciasto::ustaw_rodzaj(std::string rodzaj)
{
	this->rodzaj = rodzaj;
}

void ciasto::ustaw_kolor(std::string kolor)
{
	this->kolor = kolor;
}

int  ciasto::get_ile_obiektow_ciasto()
{
	return ile_obiektow_ciasto;
}

std::ostream& operator<<(std::ostream& s, ciasto& c)
{
	s << "\n\n\n" << "Informacje na temat ciasta: " << c.nazwa_ciasta << "\nCena:   " << c.cena << "\nKolor:  ";
	s << c.kolor << "\nRodzaj: " << c.rodzaj << "\n\n\n";
	return s;
}