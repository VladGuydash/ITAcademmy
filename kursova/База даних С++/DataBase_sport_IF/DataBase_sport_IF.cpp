#include "Data.h"
#include <iostream>
#include "windows.h"

using namespace std;


void Functions::Menu(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	int _stateMenu;
	cout
		<< "\t\t\t    |-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|" << endl
		<< "\t\t\t    |    База даних організацій    |" << endl
		<< "\t\t\t    |------------------------------|" << endl
		<< "\t\t\t    |Виберiть дiю:                 |" << endl
		<< "\t\t\t    |(0) Вихiд iз програми         |" << endl
		<< "\t\t\t    |(1) Спортивна інфраструктура  |" << endl
		<< "\t\t\t    |(2) Дані про змагання         |" << endl
		<< "\t\t	    |(3) Дані про спортсменів      |" << endl
		<< "\t\t\t    |(4) Дані про тренерів         |" << endl
		<< "\t\t\t    |(5) Дані про призерів змагань |" << endl
		<< "\t\t\t    |(6) Ввід даних                |" << endl
		<< "\t\t\t    |-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|" << endl
		<< "\t\t\t: ";

	cout << "Введіть номер: " << endl;
	cin >> _stateMenu;

	while (_stateMenu != 0) {


		switch (_stateMenu)
		{
		case 1:
			system("cls");
			Functions::Buildings_Sport(stadion, stadion_count, gym, gym_count, court, court_count);
			break;
		case 2:
			system("cls");
			Functions::Competitions(stadion, stadion_count, gym, gym_count, court, court_count);
			break;
		case 3:
			system("cls");
			Functions::Sportsmans(stadion, stadion_count, gym, gym_count, court, court_count);
			break;
		case 4:
			system("cls");
			Functions::Trainers(stadion, stadion_count, gym, gym_count, court, court_count);
			break;
		case 5:
			system("cls");
			Functions::Achievement(stadion, stadion_count, gym, gym_count, court, court_count);
			break;
		case 0:
			system("cls");
			cout << "Завершення роботи" << endl << endl;
			break;
		default:
			system("cls");
			Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
			cout << "Помилка! Спробуйте ще раз" << endl << endl;
			break;
		}
	}
};
