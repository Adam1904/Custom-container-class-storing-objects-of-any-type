#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include "vessel.h"
#include "vessel.cpp"
#include "node.cpp"
#include "cukiernia.h"


using namespace std;


void funkcja_interaktywna();


int main()
{
	funkcja_interaktywna();

	
	return 0;
}

void funkcja_interaktywna()
{
	/* --------- PROGRAM INTERAKTYWNY --------- */
	/*  OBSLUGA 2 list dwukierunkowych          */

	vessel<cukiernia> naczynie; // nasza lista
	vessel<cukiernia> naczynie2; // tworze druga liste na potrzeby testow operatorow

	for(int i=0;i<5;i++)
		naczynie.insert(cukiernia()); // wstawiam 5 losowych cukierni do pierwszego naczynia
	for (int i = 0; i < 5; i++)
		naczynie2.insert(cukiernia()); // wstawiam 5 losowych cukierni do drugiego naczynia

	int n = 0; // pomocnicza zmienna wyboru do instrukcji switch case

	do
	{
		system("cls");
		cout << "Wybierz opcje do uruchomienia:" << endl;
		cout << "1. Dodaj element do kontenera" << endl;
		cout << "2. Usun element z kontenera" << endl;
		cout << "3. Zamien kolejnosc podanych elementow" << endl;
		cout << "4. Zapisz kontener" << endl;
		cout << "5. Wczytaj kontener" << endl;
		cout << "6. Sprawdz status kontenerow" << endl;
		cout << "7. Test operatora == " << endl;
		cout << "8. Test operatora = " << endl;
		cout << "9. Test operatora += " << endl;
		cout << "10. Test operatora [] " << endl;
		cout << "11. Generacja n-losowych cukierni" << endl;
		cout << "12. Usuniecie n cukierni" << endl;
		cout << "13. Wyjdz" << endl;
		cout << "Wprowadz (1-13):";

		cin >> n;
		while (cin.fail() || n > 13 || n < 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "Wybierz opcje do uruchomienia:" << endl;
			cout << "1. Dodaj element do kontenera" << endl;
			cout << "2. Usun element z kontenera" << endl;
			cout << "3. Zamien kolejnosc podanych elementow" << endl;
			cout << "4. Zapisz kontener" << endl;
			cout << "5. Wczytaj kontener" << endl;
			cout << "6. Sprawdz status kontenerow" << endl;
			cout << "7. Test operatora == " << endl;
			cout << "8. Test operatora = " << endl;
			cout << "9. Test operatora += " << endl;
			cout << "10. Test operatora [] " << endl;
			cout << "11. Generacja n-losowych cukierni" << endl;
			cout << "12. Usuniecie n cukierni" << endl;
			cout << "13. Wyjdz" << endl;
			cout << "PODANO BLEDNA LICZBE!!! Sprobuj ponownie (1-13):" << endl;
			cin >> n;
		}

		char pomocnicza;
		switch (n)
		{
		case 1:
			do
			{
				pomocnicza = 't';
				int ile_elementow = naczynie.get_counter();
				system("cls");
				cout << "Naczynie ma: " << ile_elementow << " elementow" << endl;
				naczynie.print_vessel();
				cout << "\n\nPodaj na ktore miejsce chcialbys dodac element (1 TO GLOWA):" << endl;
				int liczba = 0;
				cin >> liczba;
				while (cin.fail())
				{
					system("cls");
					cout << "Naczynie ma: " << ile_elementow << " elementow" << endl;
					naczynie.print_vessel();
					cin.clear();
					cout << "\n\nBLAD!!!!!!" << endl;
					cin.ignore(INT_MAX, '\n');
					cout << "Jezeli naczynie jest puste to mozesz dodac element na pierwsze miejsce" << endl;
					cout << "Podaj na ktore miejsce chcialbys dodac element (1 TO GLOWA): od (1 do " << ile_elementow << ")!!!" << endl;
					cin >> liczba;
				}

				try
				{
					naczynie.insert_element(liczba, cukiernia());
				}
				catch (string s)
				{
					cout << "\n\n\n";
					cout << s << endl;
				}

				naczynie.print_vessel();

				cout << "\n\n\nCzy chcesz dodac kolejne elementy?" << endl;
				cout << "Wpisz 't' lub 'T' aby uruchomic ponownie funkcje (inna wartosc powoduje powrot do menu):";
				cin >> pomocnicza;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
			} while (pomocnicza == 't' || pomocnicza == 'T');

			break;
		case 2:
			do
			{
				pomocnicza = 't';
				int ile_elementow = naczynie.get_counter();
				system("cls");
				cout << "Naczynie ma: " << ile_elementow << " elementow" << endl;
				naczynie.print_vessel();
				cout << "\n\nPodaj ktory element chcialbys usunac (1 TO GLOWA):" << endl;
				int liczba = 0;
				cin >> liczba;
				while (cin.fail())
				{
					system("cls");
					cout << "Naczynie ma: " << ile_elementow << " elementow" << endl;
					naczynie.print_vessel();
					cin.clear();
					cout << "\n\nBLAD!!!!!!" << endl;
					cin.ignore(INT_MAX, '\n');
					cout << "Podaj na ktore miejsce chcialbys dodac element (1 TO GLOWA): od (1 do " << ile_elementow << ")!!!" << endl;
					cin >> liczba;
				}

				try
				{
					naczynie.erase_element(liczba);
				}
				catch (string s)
				{
					cout << "\n\n\n";
					cout << s << endl;
				}

				naczynie.print_vessel();

				cout << "\n\n\nCzy chcesz dodac kolejne elementy?" << endl;
				cout << "Wpisz 't' lub 'T' aby uruchomic ponownie funkcje (inna wartosc powoduje powrot do menu):";
				cin >> pomocnicza;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
			} while (pomocnicza == 't' || pomocnicza == 'T');

			break;
		case 3:
			do
			{
				system("cls");
				naczynie.print_vessel();
				cout << "\n\nPodaj jaki element chcialbys zamienic:" << endl;
				int pierwsza;
				int druga;
				cin >> pierwsza;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				cout << "A teraz z ktorym:" << endl;
				cin >> druga;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				
				try
				{
					naczynie.swap(pierwsza, druga);
				}
				catch (string s)
				{
					cout << "\n\n\n";
					cout << s << endl;
				}

				naczynie.print_vessel();

				cout << "\n\n\nCzy chcesz zamienic kolejne elementy?" << endl;
				cout << "Wpisz 't' lub 'T' aby uruchomic ponownie funkcje (inna wartosc powoduje powrot do menu):";
				cin >> pomocnicza;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
			} while (pomocnicza == 't' || pomocnicza == 'T');

			break;
		case 4:
			system("cls");

			naczynie.print_vessel();

			try
			{
				naczynie.save();
			}
			catch (string s)
			{
				cout << "\n\n\n";
				cout << s << endl;
			}

			cout << "\n\n\nWpisz dowolna wartosc aby powrocic do menu:";
			cin >> pomocnicza;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();

			break;
		case 5:
			system("cls");

			cout << "LISTA PRZED WCZYTANIEM " << endl;
			naczynie.print_vessel();

			try
			{
				naczynie.read();
			}
			catch (string s)
			{
				cout << "\n\n\n";
				cout << s << endl;
			}

			cout << "\n\n\nLISTA PO WCZYTANIU " << endl;
			naczynie.print_vessel();

			cout << "\n\n\nWpisz dowolna wartosc aby powrocic do menu:";
			cin >> pomocnicza;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();

			break;
		case 6:
			system("cls");
			cout << "Pierwsze naczynie: " << endl;
			naczynie.print_vessel();
			cout << "\n\nDrugie naczynie: " << endl;
			naczynie2.print_vessel();
			if (naczynie.get_counter() == 0)
				cout << "LISTA JEST PUSTA!!!!" << endl;

			cout << "\n\n\nWpisz dowolna wartosc aby powrocic:";
			cin >> pomocnicza;
			cin.clear();

			break;
		case 7:
			system("cls");
			if (naczynie.get_counter() == 0)
			{
				cout << "LISTA JEST PUSTA, WROC DO MENU I STWORZ NOWE ELEMENTY! " << endl;
				cout << "\n\n\nWpisz dowolna wartosc aby powrocic do menu:";
				cin >> pomocnicza;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				break;
			}
			cout << "Pierwsze naczynie: " << endl;
			naczynie.print_vessel();
			cout << "\n\nDrugie naczynie: " << endl;
			naczynie2.print_vessel();
			cout << "\n\n\nCzy naczynie i naczynie2 sa takie same?" << endl;
			try
			{
				if (naczynie == naczynie2)
					cout << "TAK SA TAKIE SAME" << endl;
				else
					cout << "NIE SA TAKIE SAME" << endl;
			}
			catch (string s)
			{
				cout << "\n\n\n";
				cout << s << endl;
			}
			
			cout << "\n\n\nWpisz dowolna wartosc aby powrocic do menu:";
			cin >> pomocnicza;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();

			break;
		case 8:
			system("cls");

			try
			{
				cout << "Naczynia przed dzialaniem przypisania = (PIERWSZE = DRUGIE)" << endl;
				cout << "\n\nPierwsze: " << endl;
				naczynie2.print_vessel();
				cout << "\n\nDrugie:" << endl;
				naczynie.print_vessel();

				naczynie2 = naczynie;

				cout << "Naczynia przed dzialaniem przypisania = (PIERWSZE = DRUGIE)" << endl;
				cout << "\n\nPierwsze: " << endl;
				naczynie2.print_vessel();
				cout << "\n\nDrugie:" << endl;
				naczynie.print_vessel();
			}
			catch (string s)
			{
				cout << "\n\n\n";
				cout << s << endl;
			}

			cout << "\n\n\nWpisz dowolna wartosc aby powrocic do menu:";
			cin >> pomocnicza;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();

			break;
		case 9:
			system("cls");

			try
			{
				cout << "Naczynia PRZED dzialaniem przypisania += (PIERWSZE += DRUGIE)" << endl;
				cout << "\n\nPierwsze: " << endl;
				naczynie2.print_vessel();
				cout << "\n\nDrugie:" << endl;
				naczynie.print_vessel();

				naczynie2 += naczynie;

				cout << "\n\nNaczynia PO dzialaniu przypisania += (PIERWSZE += DRUGIE)" << endl;
				cout << "\n\nPierwsze: " << endl;
				naczynie2.print_vessel();
				cout << "\n\nDrugie:" << endl;
				naczynie.print_vessel();
			}
			catch (string s)
			{
				cout << "\n\n\n";
				cout << s << endl;
			}

			cout << "\n\n\nWpisz dowolna wartosc aby powrocic do menu:";
			cin >> pomocnicza;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();

			break;
		case 10:
			system("cls");
			do
			{ 
			if (naczynie.get_counter() == 0)
			{
				cout << "LISTA JEST PUSTA, WROC DO MENU I STWORZ NOWE ELEMENTY! " << endl;
				cout << "\n\n\nWpisz dowolna wartosc aby powrocic do menu:";
				cin >> pomocnicza;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
				break;
			}

			int element;
			int ile_elementow = naczynie.get_counter();
			cout << "Podaj ktory element z listy chcialbys wypisac na ekran?: " << endl;
			cin >> element;

			while (cin.fail() || element > ile_elementow || element < 0)
			{
				system("cls");
				cout << "Naczynie ma: " << ile_elementow << " elementow" << endl;
				cin.clear();
				cout << "\n\nBLAD!!!!!!" << endl;
				cin.ignore(INT_MAX, '\n');
				cout << "Podaj ktory element z listy chcialbys wypisac na ekran?: (1 TO GLOWA): od (1 do " << ile_elementow << ")!!!" << endl;
				cin >> element;
			}
			try
			{
				cout << naczynie[element];

			}
			catch (string s)
			{
				cout << "\n\n\n";
				cout << s << endl;
			}

			cout << "\n\n\nCzy chcesz wyswietlic kolejne elementy?" << endl;
			cout << "Wpisz 't' lub 'T' aby uruchomic ponownie funkcje (inna wartosc powoduje powrot do menu):";
			cin >> pomocnicza;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();

			} while (pomocnicza == 't' || pomocnicza == 'T');
			break;
		case 11:
			do
			{
				pomocnicza = 't';
				system("cls");
				cout << "Podaj ile elementow chcialbys dodac:" << endl;
				int liczba;
				cin >> liczba;
				while (cin.fail() || liczba > 100 || liczba < 1)
				{
					cout << "Podano bledna wartosc!!!  Sprobuj ponownie:" << endl;
					cin >> liczba;
				}

				for (int i = 0; i < liczba; i++)
					naczynie.insert(cukiernia());

				naczynie.print_vessel();

				cout << "\n\n\nCzy chcesz dodac kolejne elementy?" << endl;
				cout << "Wpisz 't' lub 'T' aby uruchomic ponownie funkcje (inna wartosc powoduje powrot do menu):";
				cin >> pomocnicza;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
			} while (pomocnicza == 't' || pomocnicza == 'T');

			break;
		case 12:
			do
			{
				system("cls");
				cout << "Podaj ile elementow chcialbys usunac:" << endl;
				int liczba2;
				cin >> liczba2;
				int pomocniczal;
				pomocniczal = naczynie.get_counter();

				while (cin.fail() || liczba2 > pomocniczal)
				{
					if (liczba2 == pomocniczal && pomocniczal == 0)
						break;
					system("cls");
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "BLAD!!!!!!" << endl;
					cout << "Naczynie ma: " << pomocniczal << " elementow" << endl;
					cout << "Jezeli naczynie ma 0 elementow wprowadz 0" << endl;
					cout << "Podano bledna wartosc!!!  Sprobuj ponownie:";
					cin >> liczba2;
				}

				try
				{
					for (int i = 0; i < liczba2; i++)
						naczynie.erase();
					naczynie.print_vessel();
				}
				catch (string s)
				{
					cout << "\n\n\n";
					cout << s << endl;
				}
				cout << "\n\n\nCzy chcesz usunac kolejne elementy?" << endl;
				cout << "Wpisz 't' lub 'T' aby uruchomic ponownie funkcje (inna wartosc powoduje powrot do menu):";
				cin >> pomocnicza;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.clear();
			} while (pomocnicza == 't' || pomocnicza == 'T');

			break;
		case 13:
			break;
		}
	} while (n != 13);
}