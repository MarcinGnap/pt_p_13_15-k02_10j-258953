#include "Lista.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include <chrono>
#include <ratio>

using namespace std;

Lista::Lista()
{
	nHead = NULL;
	nTail = NULL;
}

Lista::~Lista()
{

}

void Lista::listMenu()									//	Menu główne listy dwukierunkowej.
{
	for (;;)
	{
		shL.cls();										//	"Wyczyszczenie" konsoli.

		short sLChoiceListMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Menu dodawania.\n"
				"\t2.Menu usuwania.\n"
				"\t3.Menu wyswietlania.\n"
				"\t4.Menu testow.\n"
				"\t5.Powrot.\n";
		cin >> sLChoiceListMenu;

		switch (sLChoiceListMenu)
		{
		case 1:
		{
			pushMenu();									//	Menu dodawania elementów do listy.
			break;
		}
		case 2:
		{
			popMenu();									//	Menu usuwania elementów z listy.
			break;
		}
		case 3:
		{
			displayMenu();								//	Menu Wyświetlania zawartości listy.
			break;
		}
		case 4:
		{
			testMenu();
			break;
		}
		case 5:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();								//	Wyświetlenie komunikatu o wybraniu nieistniejącej opcji.
			break;
		}
		}
	}
}

void Lista::pushMenu()											//	Menu dodawania elementów do listy.
{
	for (;;)
	{
		shL.cls();												//	"Wyczyszczenie" konsoli.

		short sLChoicePushMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Dodanie na poczatek struktury.\n"
				"\t2.Dodanie na koniec struktury.\n"
				"\t3.Dodanie w okreslonie miejsce w strukturze (po wartosci).\n"
				"\t4.Dodanie w okreslonie miejsce w strukturze (do indeksu).\n"
				"\t5.Odczytanie danych z pliku tekstowego.\n"
				"\t6.Wygenerowanie okreslonej ilosci danej do struktury.\n"
				"\t7.Powrot.\n";
		cin >> sLChoicePushMenu;

		switch (sLChoicePushMenu)
		{
		case 1:
		{
			int iLNewFrontElement;

			cout << "Podaj liczbe jaka ma byc dodana do listy:\n";
			cin >> iLNewFrontElement;							//	Wybranie wartości dodawanego elementu.

			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			pushFront(iLNewFrontElement);						//	Dodanie elementu na początek listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu zadania oraz czekanie na naciśnięcie klawisza przez użytkownika.
			break;
		}
		case 2:
		{
			int iLNewEndElement;

			cout << "Podaj liczbe jaka ma byc dodana do listy:\n";
			cin >> iLNewEndElement;								//	Wybór wartości dodawanego elementu.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			pushEnd(iLNewEndElement);							//	Dodanie elementu na koniec listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu zadania oraz czekanie na naciśnięcie klawisza przez użytkownika.
			break;
		}
		case 3:
		{
			int iLPushValue, iLPushElement;
			cout << "Wybierz, po ktorym elemencie ma zostac wstawiony twoj element:\n";
			cin >> iLPushValue;									//	Wybranie po jakim elemencie ma zostać wstawiony nowy element.
			cout << "Wybierz wartosc wstawianego elementu:\n";
			cin >> iLPushElement;								//	Wybranie wartości wstawianego elementu.
			cout << "Wybrany element zostanie wstawiony po elemencie: " << iLPushValue << " i bedzie mial wartosc: " << iLPushElement << ".\n";
			
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			if (pushMiddleValue(iLPushValue, iLPushElement) == true)	//	Dodanie elementu w określone miejsce listy.
			{
				cout << "Udalo sie dodac element...\n";
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu zadania oraz czekanie na naciśnięcie klawisza przez użytkownika.
			break;
		}
		case 4:
		{
			int iLPushPosition, iLPushElement;
			cout << "Wybierz pozycje, na ktorej ma zostac wstawiony element:\n";
			cin >> iLPushPosition;								//	Wybranie po jakim elemencie ma zostać wstawiony nowy element.
			cout << "Wybierz wartosc wstawianego elementu:\n";
			cin >> iLPushElement;								//	Wybranie wartości wstawianego elementu.
			int iLRightPush = iLPushPosition - 1;
			
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			if (pushMiddleIndex(iLRightPush, iLPushElement) == true)	//	Dodanie elementu w określone miejsce listy.
			{
				cout << "Wybrany element zostal na pozycje: " << iLPushPosition << " i ma ma wartosc: " << iLPushElement << ".\n";
			}
			else
			{
				shL.away();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu zadania oraz czekanie na naciśnięcie klawisza przez użytkownika.
			break;
		}
		case 5:
		{
			readFromFileL();									//	Wczytanie elementów z pliku tekstowego.

			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu wykonywania operacji.

			break;
		}
		case 6:
		{
			int iLNumberOfGen;
			cout << "Ile elementow ma zostac wygenerowanych?\n";
			cin >> iLNumberOfGen;								//	Wybór ilości wylosowanych elementów.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.
			srand(time(0));

			generateElements(iLNumberOfGen);					//	Wygenerowanie określonej liczby elementów.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia wykonywania operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonywania operacji.

			displayAll();
			shL.done();											//	Wyświetlenie komuniaktu o zakończeniu wykonywania operacji.

			break;
		}
		case 7:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();										//	Wyświetlenie komunikatu o wybraniu nieistniejącej opcji.
			break;
		}
		}
	}
}

void Lista::popMenu()									//	Menu usuwania elementów z listy.
{
	for (;;)
	{
		shL.cls();										//	"Wyczyzczenie" konsoli.

		short sLChoicePopMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Usuniecie elementu z poczatku struktury.\n"
				"\t2.Usuniecie elementu z konca struktury.\n"
				"\t3.Usuniecie elementu o okreslonej wartosci ze struktury.\n"
				"\t4.Usuniecie elementu z okreslonego miejsca ze struktury.\n"
				"\t5.Usuniecie wszytkich elementow w strukturze.\n"
				"\t6.Powrot.\n";
		cin >> sLChoicePopMenu;

		switch (sLChoicePopMenu)
		{
		case 1:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			popFront();											//	Usunięcie głowy listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu zadania oraz czekanie na naciśnięcie klawisza przez użytkownika.
			break;
		}
		case 2:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			popEnd();											//	Usunięcie ogona listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu zadania oraz czekanie na naciśnięcie klawisza przez użytkownika.
			break;
		}
		case 3:
		{
			int iLPopValue;
			cout << "Wybierz, ktory element ma zostac usuniety:\n";
			cin >> iLPopValue;									//	Wybranie usuwanej wartości.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			if (popMiddleValue(iLPopValue) == true)				//	Usunięcie wskazanego elementu listy.
			{
				cout << "Wybrany element zostal usuniety ze struktury.\n";
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu zadania oraz czekanie na naciśnięcie klawisza przez użytkownika.
			break;
		}
		case 4:
		{
			int iLPopIndex;
			cout << "Wybierz, ktory element ma zostac usuniety:\n";
			cin >> iLPopIndex;									//	Wybranie usuwanej wartości.
			int iTRightPop = iLPopIndex - 1;					//	Zmienna zawierająca poprawną pozycję usuwanego elementu.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			if (popMiddleIndex(iTRightPop) == true)				//	Usunięcie wskazanego elementu listy.
			{
				cout << "Wybrany element zostal usuniety ze struktury.\n";
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia programu.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu zadania oraz czekanie na naciśnięcie klawisza przez użytkownika.
			break;
		}
		case 5:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			clearAll();											//	Wyświetlenie całej zawartości listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			displayAll();
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu zadania oraz czekanie na naciśnięcie klawisza przez użytkownika.
			break;
		}
		case 6:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();								//	Wyświetlenie kounikatu o wybraniu nieistniejącej opcji.
			break;
		}
		}
	}
}

void Lista::displayMenu()										//	Menu wyświatlania.
{
	for (;;)
	{
		shL.cls();												//	"Wyczyszczenie" ekranu.

		short sLChoiceDisplayMenu;

		cout << "Prosze wybrac:\n"
				"\t1.Wyswietlenie calej zawartosci struktury.\n"
				"\t2.Wyswietlenie okreslonego elementu struktury (szukajac wartosci).\n"
				"\t3.Wyswietlenie okreslonego elementu struktury (szukajac indeksu).\n"
				"\t4.Powrot.\n";
		cin >> sLChoiceDisplayMenu;

		switch (sLChoiceDisplayMenu)
		{
		case 1:
		{
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			displayAll();										//	Wyświetlenie całej zawartości listy.

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			shL.done();
			break;
		}
		case 2:
		{
			int iLDisplayChoice;
			cout << "Wybierz, ktory element ma zostac wyswietlony:\n";
			cin >> iLDisplayChoice;								//	Wybór wartości, która ma zostać wyświetlona.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			if (displayOneValue(iLDisplayChoice) == true)		//	Wyświetlenie określonego elementu listy.
			{
				cout << "Wybrany element znajduje sie w strukturze." << endl;
			}
			else
			{
				shL.noIn();
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu wykonywania operacji.

			break;
		}
		case 3:
		{
			int iLDisplayIndex;
			cout << "Wybierz, ktory element ma zostac wyswietlony:\n";
			cin >> iLDisplayIndex;								//	Wybór elementu, który ma zostać wyświetlony.
			auto o1 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie rozpoczęcia operacji.

			int iLIndex = displayOneIndex(iLDisplayIndex);
			if (iLIndex == NULL)								//	Wyświetlenie określonego elementu listy.
			{
				shL.noIn();
			}
			else
			{
				cout << "Wybrany element: " << iLDisplayIndex << " ma wartosc rowna " << iLIndex << endl;
			}

			auto o2 = chrono::high_resolution_clock::now();		//	Pomiar czasu w momencie zakończenia operacji.
			outcomeList.tMOutcome(o1, o2);						//	Wyświetlenie czasu wykonania operacji.
			shL.done();											//	Wyświetlenie komunikatu o zakończeniu wykonywania operacji.

			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();										//	Wyświetlenie komunikatu o wybraniu nieistniejącej opcji.
			break;
		}
		}
	}
}

void Lista::testMenu()
{
	for (;;)
	{
		shL.cls();								

		short sLChoiceTestMenu;

		cout << "Prosze wybrac:\n"
			"\t1.Testy dodawania.\n"
			"\t2.Testy usuwania.\n"
			"\t3.Testy wyszukiwania.\n"
			"\t4.Powrot.\n";
		cin >> sLChoiceTestMenu;

		switch (sLChoiceTestMenu)
		{
		case 1:
		{
			testPush();
			break;
		}
		case 2:
		{
			testPop();
			break;
		}
		case 3:
		{
			testSearch();
			break;
		}
		case 4:
		{
			return;
			break;
		}
		default:
		{
			shL.noOption();
			break;
		}
		}
	}
}

void Lista::pushFront(int iLNewFrontElement)			//	Dodanie elementu na początek listy.
{
	Node *newNode = new Node(iLNewFrontElement);		//	Stworzenie nowej "komórki" listy dla dodawanego elementu.

	if (nHead != NULL)									//	Sprawdzenie czy listy jest pusta.
	{
		newNode->nNext = nHead;							//	Wskaźnik nowej komórki na następny element zostaje przypisany poprzedniej głowie.
		nHead->nPrev = newNode;							//	Wskaźnik poprzedniej głowy na poprzedni element zostaje przypisany nowemu elementowi.
		nHead = newNode;								//	Zmiana głowy na nowy element.
	}
	else
	{
		nHead = newNode;								//	Przypisanie nowego elementu jako głowy.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.
	}
}

void Lista::pushEnd(int iLNewEndElement)				//	Dodanie elementu na koniec listy.
{
	Node *newNode = new Node(iLNewEndElement);			//	Stworzenie nowej komórki z wybraną wartością.
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		newNode->nPrev = nTail;							//	Wskaźnik nowej koórki na element poprzedni zostaje przypisany do ogona.
		nTail->nNext = newNode;							//	Wskaźnik ogona na następny element zostaje przypisany do nowej komórki.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.
	}
	else
	{
		nHead = newNode;								//	Przypisanie nowego elementu jako głowy.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.
	}
}

bool Lista::pushMiddleValue(int iLPushValue, int iLPushElement)		//	Dodanie elementu w określone miejsce w liście.
{
	Node *tempNode = nHead;								//	Stworzenie tyczasowego wskaźnika przechowującego adres głowy.
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		while (tempNode->nNext != NULL)					//	Pętla wykonująca się od początkowego elementu listy do ostatniego.
		{
			if (tempNode->iNData == iLPushValue)		//	Sprawdzenie czy wartość elementu zgadza się z elementem, po którym użytkownik chce wstawić nowy element.
			{
				if (tempNode == nTail)					//	Sprawdzenie czy znaleźiony element jest ogonem.
				{
					pushEnd(iLPushElement);
				}
				else
				{
					Node *newNode = new Node(iLPushElement);//	Stworzenie nowego elementu.
					tempNode->nNext->nPrev = newNode;	//	Wskaźnik następnego elementu po znaleźionej komórce na poprzedni element zostaje przypisany do nowej komórki.
					newNode->nNext = tempNode->nNext;	//	Wskaźnik nowej komórki na następny element zostaje przypisany do następnej komórki po znaleźionej.
					newNode->nPrev = tempNode;			//	Wskaźnik nowej komórki na porzedni element zostaje przypisany do znaleźionej komórki.
					tempNode->nNext = newNode;			//	Wskaźnik znaleźionej komórki na następny element zostaje przypisany do nowej komórki.
				}
				return true;;							//	Etykieta, dzięki Której program wychodzi z pętli po znaleźieniu odpowiedniej wartośći.
			}
			tempNode = tempNode->nNext;					//	Przypisanie tymczasowego elementu do następnego.
		}
	}
	else
	{
		shL.empty();									//	Wyświetlenie komunikatu o braku zawartości struktury.
	}
	return false;
}

bool Lista::pushMiddleIndex(int iLRightPush, int iLPushElementI)
{
	int i = 0;
	Node *tempNode = nHead;								//	Stworzenie nowego wskaźnika i przypisanie do niego głowy.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartość.
	{
		while (tempNode != NULL)						//	Pętla wykonująca się od początkowego do ostatniego elementu listy.
		{
			if (i == iLRightPush)						//	Sprawdzenie czy index aktualnie "przeglądanej" komórki jest taki sama jak wybrany.
			{
				if (tempNode == nHead)
				{
					pushFront(iLPushElementI);
				}
				else if (tempNode == nTail)
				{
					pushEnd(iLPushElementI);
				}
				else
				{
					Node *newNode = new Node(iLPushElementI);
					tempNode->nNext->nPrev = newNode;	//	Wskaźnik następnego elementu po znaleźionej komórce na poprzedni element zostaje przypisany do nowej komórki.
					newNode->nNext = tempNode->nNext;	//	Wskaźnik nowej komórki na następny element zostaje przypisany do następnej komórki po znaleźionej.
					newNode->nPrev = tempNode;			//	Wskaźnik nowej komórki na porzedni element zostaje przypisany do znaleźionej komórki.
					tempNode->nNext = newNode;			//	Wskaźnik znaleźionej komórki na następny element zostaje przypisany do nowej komórki.

				}
				return true;
			}
			i++;
			tempNode = tempNode->nNext;					//	Przypisanie wskaźnikowi tyczasowej komórki adresu elementu następnego.
		}
	}
	else
	{
		shL.empty();									//	Wyświetlenie komunikatu o braku zawartości listy.
	}
	return false;
}

void Lista::readFromFileL()								//	Odczytanie i zapisanie elementów z pliku tekstowego.
{
	ifstream ifLFile("dane.txt", ios::in);				//	Otworzenie pliku tekstowego o nazwie "dane.txt" w trybie odczytu.
	if (ifLFile.good())									//	Sprawdzenie czy plik został pomyślnie otwarty.
	{
		shL.opened();									//	Wyświetlenie komunikatu o pomyślnym otwarciu pliku tekstowego.

		auto o1 = chrono::high_resolution_clock::now();	//	Pomiar czasu w momencie rozpoczęcia operacji.

		string sLLineCountBuffer;
		getline(ifLFile, sLLineCountBuffer);			//	Odczytanie pierwszej linii do wcześniej utworzonej zmiennej. Docelowo linia ta ma przechowywać ilość elementów odczytywanych z pliku.
		int iLLineCount = stoi(sLLineCountBuffer);		//	Zmienienie typu odczytanej zmiennej na typ całkowyti 4-bajtowy.
		cout << "Ilosc elementow przekazanych do struktury: " << iLLineCount << endl;

		string sLFileHead;
		getline(ifLFile, sLFileHead);					//	Odczytanie pierwszego elementu z pliku tekstowego.
		int iLFileHead = stoi(sLFileHead);				//	Zmienienie typu odczytanej zmiennej na typ całkowyti 4-bajtowy.
		Node *tempNode = new Node(iLFileHead);			//	Stworzenie nowego elementu.
		nHead = tempNode;								//	Przypisanie nowego elemtnu jako głowy.

		for (int i = 1; i <= iLLineCount - 2; i++)		//	Pętla wykonująca się od drugiego elementu odczytanego do przedostatniego.
		{
			string sLLineValueBuffer;
			getline(ifLFile, sLLineValueBuffer);		//	Odczytanie elementu.
			int iLLineValue = stoi(sLLineValueBuffer);	//	Zmienienie typu odczytanej zmiennej na typ całkowyti 4-bajtowy.

			Node *newNode = new Node(iLLineValue);		//	Stworzenie nowego elemntu z odczytaną wartością.
			tempNode->nNext = newNode;					//	Wskaźnik porpzedniego elementu na następny element zostaje przypisany do nowego elementu.
			newNode->nPrev = tempNode;					//	Wskaźnik nowego elementu na poprzedni element zostaje przypisany do porzedniego elementu.
			tempNode = newNode;							//	Nowy element zostaje uznany za tymczasowy element.
		}
		string sLFileTail;
		getline(ifLFile, sLFileTail);					//	Odczytanie ostatniego elementu.
		int iLFileTail = stoi(sLFileTail);				//	Zmienienie typu odczytanej zmiennej na typ całkowyti 4-bajtowy.
		Node *newNode = new Node(iLFileTail);			//	Stworzenie nowego elementu z odczytanymi danymi.
		tempNode->nNext = newNode;						//	Wskaźnik porpzedniego elementu na następny element zostaje przypisany do nowego elementu.
		newNode->nPrev = tempNode;						//	Wskaźnik nowego elementu na poprzedni element zostaje przypisany do porzedniego elementu.
		nTail = newNode;								//	Przypisanie nowego elementu jako ogona.

		ifLFile.close();								//	Zamknięcie pliku.

		auto o2 = chrono::high_resolution_clock::now();	//	Pomiaer czasu w momencie zakończenia operacji.

		outcomeList.tMOutcome(o1, o2);					//	Wyświetlenie czasu wykonywania operacji.
	}
	else
	{
		shL.noFile();									//	Wyświetlenie komunikatu o problemie z plikiem.
	}
}

void Lista::generateElements(int iLNumberOfGen)			//	Wygenerowanie określonej liczby elemetów do listy.
{
	if (iLNumberOfGen == 0)
	{
		shL.noOption();
	}
	else if (iLNumberOfGen == 1)
	{
		int iLGenerated = rand();							//	Pseudo wylosowanie nowej wartości.
		Node *newNode = new Node(iLGenerated);				//	Stworzenie nowego elementu z nową wartością.
		nHead = newNode;									//	Przypisanie nowego elementu jako głowy.
		nTail = newNode;									//	Przypisanie nowego elementu jako ogona.
	}
	else if (iLNumberOfGen == 2)
	{
		int iLGeneratedHead = rand();						//	Pseudo wylosowanie elementu.
		Node *tempNode = new Node(iLGeneratedHead);			//	Stworzenie nowego elementu z nowymi danymi.
		nHead = tempNode;									//	Przypisanie nowego elementu jako głowy.

		int iLGeneratedTail = rand();						//	Pseudo wylosowanie nowej wartości.
		Node *newNode = new Node(iLGeneratedTail);			//	Stworzenie nowej komórki z nową wartością.
		tempNode->nNext = newNode;							//	Wskaźnik tymczasowej komórki na następny element zostaje przypisany do nowego elementu.
		newNode->nPrev = tempNode;							//	Wskaźnik nowego elementu na poprzedni element zostaje przypisany do tymczasowego elementu.
		nTail = newNode;									//	Nowy element zostaje przypisany jako ogon.
	}
	else
	{
		int iLGeneratedHead = rand();						//	Pseudo wylosowanie elementu.
		Node *tempNode = new Node(iLGeneratedHead);			//	Stworzenie nowego elementu z nowymi danymi.
		nHead = tempNode;									//	Przypisanie nowego elementu jako głowy.

		for (int i = 0; i < iLNumberOfGen - 2; i++)			//	Pętla wykonująca się od drugiego do przedostatniego elementu.
		{
			int iLGenerated = rand();						//	Pseudo wylosowanie nowej wartości.
			Node *newNode = new Node(iLGenerated);			//	Stworzenie nowego elementu z nową wartością.
			tempNode->nNext = newNode;						//	Wskaźnik tymczasowego elementu na następny element zostaje przypisany do nowego elementu.
			newNode->nPrev = tempNode;						//	Wskaźnik nowego elementu na poprzedni element zostaje przypisany do tymczasowego elementu.
			tempNode = newNode;								//	Nowy element zostaje przypisany jako tymczasowy element.
		}
		int iLGeneratedTail = rand();						//	Pseudo wylosowanie nowej wartości.
		Node *newNode = new Node(iLGeneratedTail);			//	Stworzenie nowej komórki z nową wartością.
		tempNode->nNext = newNode;							//	Wskaźnik tymczasowej komórki na następny element zostaje przypisany do nowego elementu.
		newNode->nPrev = tempNode;							//	Wskaźnik nowego elementu na poprzedni element zostaje przypisany do tymczasowego elementu.
		nTail = newNode;									//	Nowy element zostaje przypisany jako ogon.
	}
}

void Lista::popFront()									//	Usunięcie elementu z początki listy.
{
	if (nHead != NULL)									//	Sprawdzenie czy lista jest pusta.
	{
		if (nHead->nNext != NULL)						//	Sprawdzenie czy lista jest jedno elementowa.
		{
			nHead = nHead->nNext;						//	Zmiana głowy na element poprzedni.
			delete nHead->nPrev;						//	Usunięcie starej głowy.
			nHead->nPrev = nullptr;						//	Wyzerowanie wskaźnika na poprzedni element przed nową głową.
		}
		else
		{
			delete nHead;								//	Usunięcie głowy.
			nTail = nullptr;
			nHead = nullptr;
		}
	}
	else
	{
		shL.empty();									//	Wyświetlenie kounikatu o braku zawartości listy.
	}
}

void Lista::popEnd()									//	Usunięcie elementu z końca listy.
{
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartość.
	{
		if (nTail->nPrev != NULL)						//	Sprawdzenie czy lista nie jest jednoelementowa.
		{
			nTail = nTail->nPrev;						//	Zmiana ogona na element poprzedni.

			delete nTail->nNext;						//	Usunięcie starego ogona.
			nTail->nNext = nullptr;						//	Wyzerowanie wskaźnika na następny element po nowym ogonie.
		}
		else
		{
			delete nTail;								//	Uusnięcie ogona.
			nTail = nullptr;
			nHead = nullptr;
		}
	}
	else
	{
		shL.empty();									//	Wyświetlenie kounikatu o braku zawartości listy.
	}
}

bool Lista::popMiddleValue(int iLPopValue)				//	Usunięcie wskazanego elementu.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wskaźnika i przypisanie do niego głowy.
	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (tempNode->nNext != NULL)					//	Pętla wykonująca się od pierwszego do ostatniego elementu listy.
		{
			if (tempNode->iNData == iLPopValue)			//	Sprawdzenie czy wartość przechowywana przez komórkę jest identyczna jak wartość wybrana.
			{
				tempNode->nNext->nPrev = tempNode->nPrev;	//	Wskaźnik komórki następnej po elemencie tymczasowym na element następny zostaje przypisany do wskaźnika komórki tymczasowej na komórkę poprzednią od następnej.
				tempNode->nPrev->nNext = tempNode->nNext;	//	Wskaźnik komórki poprzedniej od elementu usuwanego na komórkę następną zostaje przypisany do wskaźnika usuwanej komórki na element następny.
				delete tempNode;						//	Usunięcie elementu.
				return true;
			}
			tempNode = tempNode->nNext;					//	Zmienienie wskaźnika komórki tymczasowej na element następny.
		}
	}
	else
	{
		shL.empty();									//	Wyświetlenie komunikatu o braku zawartości listy.
	}
	return false;
}

bool Lista::popMiddleIndex(int iLPopIndex)
{
	int i = 0;
	Node *tempNode = nHead;								//	Stworzenie nowego wskaźnika i przypisanie do niego głowy.
	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (tempNode != NULL)						//	Pętla wykonująca się od początkowego do ostatniego elementu listy.
		{
			if (i == iLPopIndex)						//	Sprawdzenie czy index aktualnie "przeglądanej" komórki jest taki sama jak wybrany.
			{
				if (tempNode == nHead)
				{
					popFront();
				}
				else if (tempNode == nTail)
				{
					popEnd();
				}
				else
				{
					tempNode->nNext->nPrev = tempNode->nPrev;	//	Wskaźnik komórki następnej po elemencie tymczasowym na element następny zostaje przypisany do wskaźnika komórki tymczasowej na komórkę poprzednią od następnej.
					tempNode->nPrev->nNext = tempNode->nNext;	//	Wskaźnik komórki poprzedniej od elementu usuwanego na komórkę następną zostaje przypisany do wskaźnika usuwanej komórki na element następny.
					delete tempNode;							//	Usunięcie elementu.
				}
				return true;
			}
			i++;
			tempNode = tempNode->nNext;							//	Przypisanie wskaźnikowi tyczasowej komórki adresu elementu następnego.
		}
	}
	else
	{
		shL.empty();											//	Wyświetlenie komunikatu o braku wybranej pozycji w liście.
	}
	return false;
}

void Lista::clearAll()									//	Usunięcie wszystkich elementów listy.
{
	Node *tempNode = nHead;								//	Stworzenie tymczasowego wskaźnika i przypisanie do niego głowy.

	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		while (nHead != NULL)							//	Pętla wykonująca się dopóki głowa ma wartość.
		{
			tempNode = nHead->nNext;					//	Przypisanie do wskaźnika tymczasowego elementu następnego po głowie.
			delete nHead;								//	Usunięcie głowy.
			nHead = tempNode;							//	Przypisanie do głowy następnej komórki.
		}
	}
	else
	{
		shL.empty();									//	Wyświetlenie komunikatu o braku zawartości listy.
	}
}

void Lista::displayAll()								//	Wyświetlenie całej zawartości listy.
{
	if (nHead != NULL)									//	Sprawdzenie czy lista nie jest pusta.
	{
		int i = 1;
		Node *tempNode = nHead;							//	Stworzenie tyczasowego wskaźnika i przypisanie do niego głowy.
		cout << "Zawartosc listy (od glowy):\n";
		while (tempNode != NULL)						//	Pętla wykonująca się dopóki wartość tyczasowego wskaźnika nie jest pusta.
		{
			cout << "Element nr " << i << " ma wartosc rowna: " << tempNode->iNData << endl;	//	Wyświetlenie zawartości komórki.
			tempNode = tempNode->nNext;					//	Przypisanie do wskaźnika tyczasowej komórki element następny po danej komórce.
			i++;										//	Iteracja ziennej odpowiadającej za wyświetlanie "numeru" elementu.
		}
		cout << "Head = " << nHead->iNData << endl << "Tail = " << nTail->iNData << endl;	//	Wyświetlenie wartości głowy i ogona.
	}
	else
	{
		shL.empty();									//	Wyświetlenie komunikatu o braku zawartości listy.
	}
}

bool Lista::displayOneValue(int iLDisplayChoice)		//	Wyświtlenie wybranego elementu listy.
{
	Node *tempNode = nHead;								//	Stworzenie nowego wskaźnika i przypisanie do niego głowy.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartość.
	{
		while (tempNode != NULL)						//	Pętla wykonująca się od początkowego do ostatniego elementu listy.
		{
			if (tempNode->iNData == iLDisplayChoice)	//	Sprawdzenie czy wartość aktualnie "przeglądanej" komórki jest taka sama jak wybrana wartość.
			{
				cout << "Ilosc pozycji od glowy: " << endl;	//	Wyświetlenie, na której pozycji od głowy "leży" wybrana wartość.
				return true;
			}
			tempNode = tempNode->nNext;					//	Przypisanie wskaźnikowi tyczasowej komórki adresu elementu następnego.
		}
		return false;
	}
	else
	{
		shL.empty();									//	Wyświetlenie komunikatu o braku zawartości listy.
	}
	return false;
}

int Lista::displayOneIndex(int iLDisplayIndex)
{
	int i = 0;
	Node *tempNode = nHead;								//	Stworzenie nowego wskaźnika i przypisanie do niego głowy.
	if (nHead != NULL)									//	Sprawdzenie czy lista ma zawartość.
	{
		while (tempNode != NULL)						//	Pętla wykonująca się od początkowego do ostatniego elementu listy.
		{
			if (i == iLDisplayIndex)					//	Sprawdzenie czy index aktualnie "przeglądanej" komórki jest taki sama jak wybrany.
			{
				return tempNode->iNData;
			}
			i++;
			tempNode = tempNode->nNext;					//	Przypisanie wskaźnikowi tyczasowej komórki adresu elementu następnego.
		}
		return NULL;
	}
	else
	{
		shL.empty();									//	Wyświetlenie komunikatu o braku zawartości listy.
	}
	return NULL;
}

void Lista::testPush()
{
	int iLTPuChoice;
	int iLTTrial;
	long long llLTPushFrontAvg = 0;
	long long llLTPushEndAvg = 0;
	long long llLTPushMiddletAvg = 0;
	cout << "Ile razy maja zostac przeprowadzone pomiary?";
	cin >> iLTTrial;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iLTPuChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Dodawanie na poczatek:\n";
	for (int i = 0; i < iLTTrial; i++)
	{
		generateElements(iLTPuChoice);

		int iLTNewFrontElement = ((rand() * rand() * rand()) % 2147483647);
		auto o1 = chrono::high_resolution_clock::now();

		pushFront(iLTNewFrontElement);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);
		llLTPushFrontAvg = llLTPushFrontAvg + outcomeList.tMShort(o1, o2);

		clearAll();
	}
	cout << "------------------------------------------\n"
		"Dodawanie na koniec:\n";
	for (int i = 0; i < iLTTrial; i++)
	{
		generateElements(iLTPuChoice);

		int iLTNewEndElement = ((rand() * rand() * rand()) % 2147483647);
		auto o1 = chrono::high_resolution_clock::now();

		pushEnd(iLTNewEndElement);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);
		llLTPushEndAvg = llLTPushEndAvg + outcomeList.tMShort(o1, o2);

		clearAll();
	}
	cout << "------------------------------------------\n"
		"Dodawanie w srodek:\n";
	for (int i = 0; i < iLTTrial; i++)
	{
		generateElements(iLTPuChoice);

		int iLTNewMiddleIndex = (rand() % iLTPuChoice + 0);
		int iLTNewMiddleElement = ((rand() * rand() * rand()) % 2147483647);
		auto o1 = chrono::high_resolution_clock::now();

		pushMiddleIndex(iLTNewMiddleIndex, iLTNewMiddleElement);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);
		llLTPushMiddletAvg = llLTPushMiddletAvg + outcomeList.tMShort(o1, o2);

		clearAll();
	}

	cout << "\n* Dodawanie na poczatek zajmuje srednio: " << llLTPushFrontAvg / iLTTrial << " nanosekund.\n";
	cout << "\n* Dodawanie na koniec zajmuje srednio: " << llLTPushEndAvg / iLTTrial << " nanosekund.\n";
	cout << "\n* Dodawanie w srodek zajmuje srednio: " << llLTPushMiddletAvg / iLTTrial << " nanosekund.\n\n";

	shL.done();
}

void Lista::testPop()
{
	int iLTPoChoice;
	int iLTTrial;
	long long llLTPopFrontAvg = 0;
	long long llLTPopEndAvg = 0;
	long long llLTPopMiddletAvg = 0;
	cout << "Ile razy maja zostac przeprowadzone pomiary?";
	cin >> iLTTrial;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iLTPoChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Usuwanie z poczatku:\n";
	for (int i = 0; i < iLTTrial; i++)
	{
		generateElements(iLTPoChoice);

		auto o1 = chrono::high_resolution_clock::now();

		popFront();

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);
		llLTPopFrontAvg = llLTPopFrontAvg + outcomeList.tMShort(o1, o2);

		clearAll();
	}
	cout << "------------------------------------------\n"
		"Usuwanie z konca:\n";
	for (int i = 0; i < iLTTrial; i++)
	{
		generateElements(iLTPoChoice);

		auto o1 = chrono::high_resolution_clock::now();

		popEnd();

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);
		llLTPopEndAvg = llLTPopEndAvg + outcomeList.tMShort(o1, o2);

		clearAll();
	}
	cout << "------------------------------------------\n"
		"Usuwanie ze srodka:\n";
	for (int i = 0; i < iLTTrial; i++)
	{
		generateElements(iLTPoChoice);

		int iLTPopIndex = (rand() % (iLTPoChoice - 1) + 0);
		auto o1 = chrono::high_resolution_clock::now();

		popMiddleIndex(iLTPopIndex);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);
		llLTPopMiddletAvg = llLTPopMiddletAvg + outcomeList.tMShort(o1, o2);

		clearAll();
	}

	cout << "\n* Usuwanie z poczatku zajmuje srednio: " << llLTPopFrontAvg / iLTTrial << " nanosekund.\n";
	cout << "\n* Usuwanie z konieca zajmuje srednio: " << llLTPopEndAvg / iLTTrial << " nanosekund.\n";
	cout << "\n* Usuwanie ze srodka zajmuje srednio: " << llLTPopMiddletAvg / iLTTrial << " nanosekund.\n\n";

	shL.done();
}

void Lista::testSearch()
{
	int iLTDChoice, iLTTrial;
	long long llLTSearchAvg = 0;
	cout << "Ile razy maja zostac przeprowadzone pomiary?";
	cin >> iLTTrial;
	cout << "Dla ilu elementow maja zostac przeprowadzone testy?";
	cin >> iLTDChoice;

	srand(time(0));

	cout << "------------------------------------------\n"
		"Szukanie elementu:\n";
	for (int i = 0; i < iLTTrial; i++)
	{
		generateElements(iLTDChoice);

		int iLTSearchValue = ((rand() * rand() * rand()) % 2147483647);
		auto o1 = chrono::high_resolution_clock::now();

		displayOneValue(iLTSearchValue);

		auto o2 = chrono::high_resolution_clock::now();
		outcomeList.tMShort(o1, o2);
		llLTSearchAvg = llLTSearchAvg + outcomeList.tMShort(o1, o2);

		clearAll();
	}
	cout << "\n* Wyszukiwanie zajmuje srednio: " << llLTSearchAvg / iLTTrial << " nanosekund.\n\n";
	shL.done();
}