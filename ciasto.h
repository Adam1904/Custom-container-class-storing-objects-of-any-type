#pragma once
#include <iostream>
#include <string>


class ciasto
{
public:
	ciasto(); // konstruktor domyslny
	ciasto(std::string nazwa_ciasta, std::string kolor, std::string rodzaj, double cena); // konstruktor z parametrem
	ciasto(const ciasto& ci); // konstruktor kopiujacy
	~ciasto(); // destruktor


	/* --------- OPERATORY --------- */

	bool operator!=(const ciasto& ci); // operator porownujacy obiekty typu ciasto
	/* jak sa rozne to zwraca true */
	operator int(); // operator konwersji na typ int
	ciasto& operator+(double dodaj_kwote); // operator dodawania
	ciasto& operator=(const ciasto& c); // operator przypisania


	/* --------- METODY --------- */

	double getcena() { return cena; };
	void ustaw_cene(double nowa_cena);
	void ustaw_nazwa_ciasta(std::string nazwa_cukierni);
	void ustaw_rodzaj(std::string rodzaj);
	void ustaw_kolor(std::string kolor);
	void wyswietlcene();


	static int get_ile_obiektow_ciasto();



private:
	std::string nazwa_ciasta;
	std::string rodzaj;
	std::string kolor;
	double cena;


	static int ile_obiektow_ciasto;


	// zaprzyjazniam klasy 
	friend class cukiernia;
	friend class cukiernik;
	friend std::ostream& operator<<(std::ostream& s, ciasto& c);
};

std::ostream& operator<<(std::ostream& s, ciasto& c); // operator strumieniowy
