#pragma once
#include "ciasto.h"
#include "cukiernik.h"
#include <iostream>
#include <vector>
#include <string>
#include "vessel.h"


class cukiernia 
{
public:
	cukiernia(); // deklaracja konstruktora
	cukiernia(const cukiernia& c); // deklaracja konstuktora kopiujacego
	~cukiernia(); // deklaracja destruktora
	cukiernia(std::string nazwa_cukierni, std::string adres, int ile_ciast, long long int NIP, int telefon, double powierzchnia); // konstruktor z parametrem


	cukiernik podobiekt_cukiernik; // Podobiekt tworzony automatycznie
	ciasto* podobiekt_ciasto; // Podobiekt tworzony dynamicznie 
	std::vector<ciasto> podobiekt_lepszych_ciast; // kontener ciast



	/* --------- OPERATORY --------- */
	ciasto& operator[](int i); // operator indeksowy, zwracajacy obiekt typu ciasto
	bool operator==(const cukiernia& c); // operator porownujacy obiekty typu cukiernia
	cukiernia& operator=(const cukiernia& c); // operator przypisujacy obiekt lewy, referencja na lewy argument
	cukiernia& operator++(); // operator jednoargumentowy (preinkrementacja)
	operator int(); // operator konwersji (double na int)


	/* --------- METODY --------- */
	void ustaw_nazwa(std::string nazwa_cukierni);
	void ustaw_adres(std::string adres);
	void ustaw_ile_ciast(int ile_ciast);
	void ustaw_NIP(long long int NIP);
	void ustaw_telefon(int telefon);
	void zatrudnij_cukiernika(std::string imie, std::string nazwisko, int wiek, int staz, int wynagrodzenie);
	void zwolnij_cukiernika(cukiernik& cukiernik);
	void wyswietl_powierzchnia();
	void wyswietl_ile_ciast();


	/* --------- METODY ZAPISU I ODCZYTU --------- */
	void zapisz_cukiernie();
	void wczytaj_cukiernie();


	static int get_ile_obiektow_cukierni();

private:
	double powierzchnia; // w m^2 
	std::string nazwa_cukierni;
	std::string adres;
	long long int NIP;
	int telefon;
	int ile_ciast = 0; // domyslnie na 0
	int ile_cukiernikow = 1;


	static int ile_obiektow_cukierni;


	friend std::ostream& operator<<(std::ostream& s, cukiernia& c); // zaprzyjaznam operator strumieniowy
	friend std::istream& operator>>(std::istream& s, cukiernia& c);
	friend vessel<cukiernia>;
};


std::ostream& operator<<(std::ostream& s, cukiernia& c); // operator strumieniowy
std::istream& operator>>(std::istream& s, cukiernia& c);
