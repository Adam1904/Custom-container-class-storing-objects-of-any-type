#include "cukiernia.h"
#include "ciasto.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>


int cukiernia::ile_obiektow_cukierni = 0;

using namespace std;


cukiernia::cukiernia() // konstruktor
{
	ile_obiektow_cukierni++;

	/* Ustawiam domyslne informacje */
	this->nazwa_cukierni = "Cukiernia";
	this->adres = "Nowowiejska";
	this->ile_ciast = 0;
	this->NIP = 4837584937;
	this->telefon = 608293400;
	this->powierzchnia = 100.0;
	podobiekt_ciasto = NULL; // zaalokowanie dynamicznego obiektu
	// domyslnie bez kontenera ciast

	unsigned int powierzchnia_gen = 0;
	do
	{
		powierzchnia_gen *= RAND_MAX;
		powierzchnia_gen += rand();
	} while (powierzchnia_gen < 500);

	this->powierzchnia = powierzchnia_gen % 500;

	unsigned long long int telefon_gen = 0;
	do
	{
		telefon_gen *= RAND_MAX;
		telefon_gen += rand();
	} while (telefon_gen < 100000000);


	this->telefon= telefon_gen % 1000000000;

	unsigned long long int NIP = 0;
	do
	{
		NIP *= RAND_MAX;
		NIP += rand();
	} while (NIP < 1000000000);

	this->NIP = NIP % 10000000000;

	
	int wybor = 0;
	wybor = rand() % 40 + 1;
	switch (wybor)
	{
	case 1:
		this->nazwa_cukierni = "Ciachomania";
		break;
	case 2:
		this->nazwa_cukierni = "Tlusty_Czwartek";
		break;
	case 3:
		this->nazwa_cukierni = "Sowa";
		break;
	case 4:
		this->nazwa_cukierni = "Ptys";
		break;
	case 5:
		this->nazwa_cukierni = "Stare_Miasto";
		break;
	case 6:
		this->nazwa_cukierni = "Na_Blejchu";
		break;
	case 7:
		this->nazwa_cukierni = "Mroczko";
		break;
	case 8:
		this->nazwa_cukierni = "Kastelik";
		break;
	case 9:
		this->nazwa_cukierni = "Zdrowak";
		break;
	case 10:
		this->nazwa_cukierni = "Dobrze_Nadziane";
		break;
	case 11:
		this->nazwa_cukierni = "Mrozek";
		break;
	case 12:
		this->nazwa_cukierni = "Jacek_Placek";
		break;
	case 13:
		this->nazwa_cukierni = "Szczesliwy_Lis";
		break;
	case 14:
		this->nazwa_cukierni = "Sliwa";
		break;
	case 15:
		this->nazwa_cukierni = "Warszawskie_Wypieki";
		break;
	case 16:
		this->nazwa_cukierni = "Zlote_Jabluszko";
		break;
	case 17:
		this->nazwa_cukierni = "Formelo";
		break;
	case 18:
		this->nazwa_cukierni = "Luksus";
		break;
	case 19:
		this->nazwa_cukierni = "Zielona_Oliwka";
		break;
	case 20:
		this->nazwa_cukierni = "Jedyna";
		break;
	case 21:
		this->nazwa_cukierni = "Roza";
		break;
	case 22:
		this->nazwa_cukierni = "Piecuch";
		break;
	case 23:
		this->nazwa_cukierni = "Jagodka";
		break;
	case 24:
		this->nazwa_cukierni = "Cieplak";
		break;
	case 25:
		this->nazwa_cukierni = "Bezowa";
		break;
	case 26:
		this->nazwa_cukierni = "Sosenka";
		break;
	case 27:
		this->nazwa_cukierni = "Mount_Blanc";
		break;
	case 28:
		this->nazwa_cukierni = "Lasuch";
		break;
	case 29:
		this->nazwa_cukierni = "Nowy_Swiat";
		break;
	case 30:
		this->nazwa_cukierni = "Kukulka";
		break;
	case 31:
		this->nazwa_cukierni = "Grycan";
		break;
	case 32:
		this->nazwa_cukierni = "Montag";
		break;
	case 33:
		this->nazwa_cukierni = "Stokrotka";
		break;
	case 34:
		this->nazwa_cukierni = "Szybkie_bistro";
		break;
	case 35:
		this->nazwa_cukierni = "Dawna_kamienica";
		break;
	case 36:
		this->nazwa_cukierni = "Delicje";
		break;
	case 37:
		this->nazwa_cukierni = "Assam";
		break;
	case 38:
		this->nazwa_cukierni = "Klos";
		break;
	case 39:
		this->nazwa_cukierni = "Wislanka";
		break;
	case 40:
		this->nazwa_cukierni = "Ustronie";
		break;
	default:
		this->nazwa_cukierni = "Bajka";
		break;
	}

	int wybor2 = 0;
	wybor2 = rand() % 20 + 1;
	switch (wybor2)
	{
	case 1:
		this->adres = "Zapora_17";
		break;
	case 2:
		this->adres = "Cieszynska_82";
		break;
	case 3:
		this->adres = "Agawy_15";
		break;
	case 4:
		this->adres = "Tartaczna_20";
		break;
	case 5:
		this->adres = "Czolowa_80";
		break;
	case 6:
		this->adres = "Tymiankowa_59";
		break;
	case 7:
		this->adres = "Aksamitna_1";
		break;
	case 8:
		this->adres = "Deszczowa_43";
		break;
	case 9:
		this->adres = "Leszno_18";
		break;
	case 10:
		this->adres = "Jantar_20";
		break;
	case 11:
		this->adres = "Dworcowa_89";
		break;
	case 12:
		this->adres = "Piastowska_37";
		break;
	case 13:
		this->adres = "Prosta_15";
		break;
	case 14:
		this->adres = "Rysia_87";
		break;
	case 15:
		this->adres = "Klamrowa_73";
		break;
	case 16:
		this->adres = "Michalowicza_12";
		break;
	case 17:
		this->adres = "Karpacka_12";
		break;
	case 18:
		this->adres = "Gorska_12";
		break;
	case 19:
		this->adres = "Juliana_Tuwima_12";
		break;
	case 20:
		this->adres = "Mroczna_12";
		break;
	case 21:
		this->adres = "Teodora_Sixta_12";
		break;
	case 22:
		this->adres = "Henryka_Sienkiewicza_12";
		break;
	case 23:
		this->adres = "Mieszka_12";
		break;
	case 24:
		this->adres = "Spokojna_12";
		break;
	case 25:
		this->adres = "Muszlowa_12";
		break;
	default:
		this->adres = "Nowowiejska_25";
		break;
	}
}

cukiernia::~cukiernia() // destruktor
{
	ile_obiektow_cukierni--;

	delete[] podobiekt_ciasto; // wyczyszczenie pamieci po dynamicznym obiekcie

	this->podobiekt_lepszych_ciast.clear(); // wyczyszczenie kontenera
}

cukiernia::cukiernia(const cukiernia& c) // konstuktor kopiujacy
{
	ile_obiektow_cukierni++;
	this->nazwa_cukierni = c.nazwa_cukierni;
	this->ile_ciast = c.ile_ciast;
	this->adres = c.adres;
	this->NIP = c.NIP;
	this->telefon = c.telefon;
	this->powierzchnia = c.powierzchnia;

	this->podobiekt_cukiernik = c.podobiekt_cukiernik; // kopiowanie podklasy cukiernik

	if (c.podobiekt_ciasto) // wszystko rozne od 0 jest prawda
	{
		this->podobiekt_ciasto = new ciasto[c.ile_ciast];

		for (int i = 0; i < c.ile_ciast; i++) // petla z postinkrementacja
		{
			this->podobiekt_ciasto[i] = c.podobiekt_ciasto[i]; // przepisuje tablice na nowa klase
		}
	}
	else
	{
		this->podobiekt_ciasto = nullptr;
	}

	this->podobiekt_lepszych_ciast = c.podobiekt_lepszych_ciast;
}

cukiernia::cukiernia(std::string na, std::string ad, int ile_cia, long long int NI, int tele, double powierzchnia)
{
	ile_obiektow_cukierni++;
	this->nazwa_cukierni = na;
	this->adres = ad;
	this->NIP = NI;
	this->telefon = tele;
	this->powierzchnia = powierzchnia;

	if (ile_cia > 0)
	{
		this->ile_ciast = ile_cia;
		podobiekt_ciasto = new ciasto[ile_cia];
	}
	else
	{
		this->ile_ciast = 0;
		ciasto* podobiekt_ciasto = nullptr;
	}


	for (int i = 0; i < ile_ciast; i++)
		podobiekt_lepszych_ciast.push_back(ciasto()); // wstawiam obiekty typu ciasta (domyslne) do kontenera
}

bool cukiernia::operator==(const cukiernia& c)
{
	if (this->nazwa_cukierni != c.nazwa_cukierni)
		return false;
	else if (this->adres != c.adres)
		return false;
	else if (this->NIP != c.NIP)
		return false;
	else if (this->ile_ciast != c.ile_ciast)
		return false;
	else if (this->telefon != c.telefon)
		return false;
	else if (this->powierzchnia != c.powierzchnia)
		return false;
	else if (c.podobiekt_ciasto)
	{
		for (int i = 0; i < ile_ciast; i++)
		{
			if (podobiekt_ciasto[i] != c.podobiekt_ciasto[i])
				return false;
		}
	}
	else if (this->podobiekt_lepszych_ciast.size() != c.podobiekt_lepszych_ciast.size())
		return false;

	return true;
}

ciasto& cukiernia::operator[](int i)
{
	if (i >= this->ile_ciast)
		std::cerr << "nie ma takiego ciasta" << std::endl;
	return this->podobiekt_ciasto[i];
}

cukiernia& cukiernia::operator=(const cukiernia& c)
{
	this->nazwa_cukierni = c.nazwa_cukierni;
	this->ile_ciast = c.ile_ciast;
	this->podobiekt_cukiernik = c.podobiekt_cukiernik;
	this->adres = c.adres;
	this->NIP = c.NIP;
	this->telefon = c.telefon;
	this->powierzchnia = c.powierzchnia;

	delete[] this->podobiekt_ciasto;

	if (c.podobiekt_ciasto)
	{
		podobiekt_ciasto = new ciasto[c.ile_ciast];

		for (int i = 0; i < c.ile_ciast; i++)
			podobiekt_ciasto[i] = c.podobiekt_ciasto[i]; // przpisuje kazda klase typu ciasta operatorem =
	}
	else
		podobiekt_ciasto = NULL;


	this->podobiekt_lepszych_ciast = c.podobiekt_lepszych_ciast; // kopiuje kontener 

	return *this;
}

void cukiernia::ustaw_adres(std::string a)
{
	this->adres = a;
}

void cukiernia::ustaw_nazwa(std::string na)
{
	this->nazwa_cukierni = na;
}

void cukiernia::ustaw_telefon(int tele)
{
	this->telefon = tele;
}

void cukiernia::ustaw_NIP(long long int ni)
{
	this->NIP = ni;
}

void cukiernia::wyswietl_ile_ciast()
{
	std::cout << "\n\nCukiernia aktualnie posiada w ofercie " << this->ile_ciast;
	if (ile_ciast > 4)
		std::cout << " roznych wypiekow.\n\n" << std::endl;
	else
		std::cout << " rozne wypieki.\n\n" << std::endl;
}

void cukiernia::zatrudnij_cukiernika(std::string imie, std::string nazwisko, int wiek, int staz, int wynagrodzenie)
{
	cukiernik nowy_cukiernik;
	nowy_cukiernik.imie = imie;
	nowy_cukiernik.nazwisko = nazwisko;
	nowy_cukiernik.wiek = wiek;
	nowy_cukiernik.staz = staz;
	nowy_cukiernik.wynagrodzenie = wynagrodzenie;
	ile_cukiernikow++;
}

void cukiernia::zwolnij_cukiernika(cukiernik& cukiernik)
{
	cukiernik.imie = "brak";
	cukiernik.nazwisko = "brak";
	cukiernik.wiek = 0;
	cukiernik.staz = 0;
	cukiernik.wynagrodzenie = 0;
	ile_cukiernikow--;
}

cukiernia& cukiernia::operator++()
{
	ciasto* nowa_tablica = new ciasto[ile_ciast + 1];

	for (int i = 0; i < ile_ciast; i++)
	{
		nowa_tablica[i] = this->podobiekt_ciasto[i];
	}
	delete[] this->podobiekt_ciasto;
	this->podobiekt_ciasto = nowa_tablica;

	this->ile_ciast++;

	podobiekt_lepszych_ciast.push_back(ciasto()); // wstawiam ciasto do kontenera

	return *this;
}

void cukiernia::ustaw_ile_ciast(int ile)
{
	if (ile > ile_ciast)
	{
		int pomocnicza = this->ile_ciast;

		while (ile > this->ile_ciast)
		{
			ciasto* kopia = new ciasto[ile_ciast];

			for (int i = 0; i < ile_ciast; i++)
			{
				kopia[i] = this->podobiekt_ciasto[i];
			}

			delete[] this->podobiekt_ciasto;
			this->ile_ciast++;
			podobiekt_ciasto = new ciasto[ile_ciast];

			for (int i = 0; i < ile_ciast - 1; i++)
			{
				podobiekt_ciasto[i] = kopia[i];
			}
			delete[] kopia;
		}

		for (int i = pomocnicza; i < ile; i++)
			this->podobiekt_lepszych_ciast.push_back(ciasto());

	}
	if (ile < ile_ciast && ile >0)
	{
		ciasto* kopia = new ciasto[ile_ciast];

		for (int i = 0; i < ile_ciast; i++)
		{
			kopia[i] = podobiekt_ciasto[i];
		}

		delete[] podobiekt_ciasto;
		ciasto* podobiekt_ciasto = new ciasto[ile];
		this->ile_ciast = ile;

		for (int i = 0; i < ile; i++)
		{
			podobiekt_ciasto[i] = kopia[i];
		}
		delete[] kopia;
		this->podobiekt_ciasto = podobiekt_ciasto;

		this->podobiekt_lepszych_ciast.erase(this->podobiekt_lepszych_ciast.begin(), (this->podobiekt_lepszych_ciast.begin() + ile));
	}
}

cukiernia::operator int() // definicja operatora konwersji
{
	return (int)this->powierzchnia;
}

void cukiernia::wyswietl_powierzchnia()
{
	std::cout << "\nPowierzchnia lokalu wynosi: " << this->powierzchnia << "\n" << std::endl;
}

int cukiernia::get_ile_obiektow_cukierni()
{
	return ile_obiektow_cukierni;
}

std::istream& operator>>(std::istream& s, cukiernia& c)
{
	std::string p = " ";
	s >> c.nazwa_cukierni >> c.adres >> c.NIP >> c.telefon >> c.ile_ciast >> c.ile_cukiernikow >> c.powierzchnia;

	return s;
}

std::ostream& operator<<(std::ostream& s, cukiernia& c)
{
	std::string p = " ";
	s << c.nazwa_cukierni << p << c.adres << p << c.NIP << p << c.telefon << p << c.powierzchnia;


	return s;
}

void cukiernia::zapisz_cukiernie()
{
	ofstream plik;
	plik.open("zapis_cukiernia.txt", ios_base::out);

	if (plik.good())
	{
		plik << (*this);
	}
	else
		std::cerr << "Nie udalo sie otworzyc pliku [zapis_cukiernia.txt]" << endl;

	plik.close();
}

void cukiernia::wczytaj_cukiernie()
{
	ifstream plik;
	plik.open("zapis_cukiernia.txt", ios_base::in);

	if (plik.good())
	{
		plik >> (*this);
	}
	else
		std::cerr << "Nie udalo sie otworzyc pliku [zapis_cukiernia.txt]" << endl;

	plik.close();
}