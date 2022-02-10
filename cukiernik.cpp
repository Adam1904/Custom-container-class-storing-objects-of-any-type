#include "cukiernik.h"


int cukiernik::ile_obiektow_cukiernik = 0;

cukiernik::cukiernik()
{
	ile_obiektow_cukiernik++;
	this->imie = "brak";
	this->nazwisko = "brak";
	this->staz = 0;
	this->wiek = 0;
	this->wynagrodzenie = 0;
}

cukiernik::cukiernik(const cukiernik& ck)
{
	ile_obiektow_cukiernik++;
	this->imie = ck.imie;
	this->nazwisko = ck.nazwisko;
	this->staz = ck.staz;
	this->wiek = ck.wiek;
	this->wynagrodzenie = ck.wynagrodzenie;
}

cukiernik::cukiernik(std::string i, std::string n, int w, int s, double wy)
{
	ile_obiektow_cukiernik++;
	this->imie = i;
	this->nazwisko = n;
	this->wiek = w;
	this->staz = s;
	this->wynagrodzenie = wy;
}

cukiernik::~cukiernik()
{
	ile_obiektow_cukiernik--;
}

cukiernik& cukiernik::operator=(const cukiernik& c)
{
	this->imie = c.imie;
	this->nazwisko = c.nazwisko;
	this->staz = c.staz;
	this->wiek = c.wiek;
	this->wynagrodzenie = c.wynagrodzenie;

	return *this;
}

ciasto cukiernik::upiecz_ciasto(std::string nazwa_ciasta, std::string kolor, std::string rodzaj, double cena)
{
	ciasto nowe_ciasto;
	nowe_ciasto.cena = cena;
	nowe_ciasto.nazwa_ciasta = nazwa_ciasta;
	nowe_ciasto.kolor = kolor;
	nowe_ciasto.rodzaj = rodzaj;
	return nowe_ciasto;
}

int cukiernik::get_ile_obiektow_cukiernik()
{
	return ile_obiektow_cukiernik;
}
