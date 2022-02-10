#pragma once
#include <iostream>
#include "ciasto.h"


class cukiernik
{
public:
	cukiernik(); // konstruktor domyslny
	cukiernik(const cukiernik& ck); // konstruktor kopiujacy
	cukiernik(std::string imie, std::string nazwisko, int wiek, int staz, double wynagrodzenie); // konstruktor z parametrami
	~cukiernik(); // destruktor


	/* --------- OPERATORY --------- */

	cukiernik& operator=(const cukiernik& c); // operator przypisujacy


	/* --------- METODY --------- */

	ciasto upiecz_ciasto(std::string nazwa_ciasta, std::string kolor, std::string rodzaj, double cena);


	static int get_ile_obiektow_cukiernik();


private:
	std::string imie;
	std::string nazwisko;
	int wiek;
	int staz;
	double wynagrodzenie; // kwota w brutto


	static int ile_obiektow_cukiernik;


	friend class cukiernia; // zaprzyjazniam klase glowna
};
