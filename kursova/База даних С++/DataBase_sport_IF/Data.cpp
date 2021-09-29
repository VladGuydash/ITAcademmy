#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

void Functions::Buildings_Sport(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "Список споруд певного типу: 1" << endl;
	cout << "Список споруд і дати проведення змагань на певному проміжку часу: 2" << endl << endl;

	string building_name;
	int number, start_of_competitions, end_of_competitions, count = 0;
	cout << "Введіть номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Введіть тип (стадіон, спортзал или корт): ";
		cin >> building_name;
		cout << endl;

		if (building_name == "стадіон")
		{
			cout << "Назва стадіонів:" << endl;
			for (int i = 0; i < stadion_count; i++)
				cout << i + 1 << ". " << stadion[i].buildings_name << endl;
			cout << endl;
		}
		else if (building_name == "спортзал")
		{
			cout << "Назва спортзалів:" << endl;
			for (int i = 0; i < gym_count; i++)
				cout << i + 1 << ". " << gym[i].buildings_name << endl;
			cout << endl;
		}
		else if (building_name == "корт")
		{
			cout << "Назва кортів для тенісу:" << endl;
			for (int i = 0; i < court_count; i++)
				cout << i + 1 << ". " << court[i].buildings_name << endl;
			cout << endl;
		}
		else
			cout << "Помилка! Спробуйте ще раз" << endl << endl;
		break;
	case 2:
		cout << "Введіть дату початку змагання: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "Введіть дату закінчення змагання: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "Змагання, проведені на стадіоні:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
				{
					if (stadion[i].sponsor[j].competitions[m].date_start >= start_of_competitions)
					{
						if (stadion[i].sponsor[j].competitions[m].date_end <= end_of_competitions)
						{
							cout << "Стадіон № " << i + 1 << ": " << stadion[i].buildings_name << endl;
							cout << "Назва змагання: " << stadion[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "Дата початку змагання: " << stadion[i].sponsor[j].competitions[m].date_start << endl;
							cout << "Дата закінчення змагання: " << stadion[i].sponsor[j].competitions[m].date_end << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено стадіонів, на яких проводились змагання в певному періоді часу" << endl << endl;
		count = 0;
		//////////////////////////////////////////////////////////////////////////
		cout << "Змагання у спортзалах:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					if (gym[i].sponsor[j].competitions[m].date_start >= start_of_competitions)
					{
						if (gym[i].sponsor[j].competitions[m].date_end <= end_of_competitions)
						{
							cout << "Спортзал № " << i + 1 << ": " << gym[i].buildings_name << endl;
							cout << "Назва змагання: " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "Дата початку змагання: " << gym[i].sponsor[j].competitions[m].date_start << endl;
							cout << "Дата закінчення змагання: " << gym[i].sponsor[j].competitions[m].date_end << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортзалів, на яких проводились змагання в певному періоді часу" << endl << endl;
		count = 0;

		cout << "Змагання на кортах:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					if (court[i].sponsor[j].competitions[m].date_start >= start_of_competitions)
					{
						if (court[i].sponsor[j].competitions[m].date_end <= end_of_competitions)
						{
							cout << "Корт № " << i + 1 << ": " << court[i].buildings_name << endl;
							cout << "Назва змагання: " << court[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "Дата початку змагання: " << court[i].sponsor[j].competitions[m].date_start << endl;
							cout << "Дата закінчення змагання: " << court[i].sponsor[j].competitions[m].date_end << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено кортів, на яких проводились змагання в певному періоді часу" << endl << endl;
		count = 0;
		break;
	default:
		cout << "Помилка! Спробуйте ще раз" << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
void Functions::Competitions(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "Отримати список змагань, проведених на певному проміжку часу: 1" << endl;
	cout << "Отримати список змагань, проведених в певному спортивному комплексі: 2" << endl << endl;

	string buildings_name;
	int start_of_competitions, end_of_competitions, number, count = 0;
	cout << "Введіть номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Введіть дату початку змагання: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "Введіть рік закінчення змагання: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "Змагання на стадіонах:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
				{
					if (stadion[i].sponsor[j].competitions[m].date_start >= start_of_competitions)
					{
						if (stadion[i].sponsor[j].competitions[m].date_end <= end_of_competitions)
						{
							cout << "- " << stadion[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено змагань, проведених в даний проміжок часу на стадіонах" << endl;
		cout << endl;
		count = 0;
		//////////////////////////////////////////////////////////////////////////////////////////////////
		cout << "Змагання в спортзалах:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					if (gym[i].sponsor[j].competitions[m].date_start >= start_of_competitions)
					{
						if (gym[i].sponsor[j].competitions[m].date_end <= end_of_competitions)
						{
							cout << "- " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено змагань, проведених в даний проміжок часу в спортзалах." << endl;
		cout << endl;
		count = 0;
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		cout << "Змагання на кортах для тенісу:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					if (court[i].sponsor[j].competitions[m].date_start >= start_of_competitions)
					{
						if (court[i].sponsor[j].competitions[m].date_end <= end_of_competitions)
						{
							cout << "- " << court[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено змагань, проведених в даний проміжок часу на кортах для тенісу" << endl;
		cout << endl;
		count = 0;
		break;

	case 2:
		cout << "Введіть назву споруди: ";
		cin >> buildings_name;
		cout << endl;

		cout << "Змагання на стадіонах:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{

			if (buildings_name == stadion[i].buildings_name)
			{
				for (int j = 0; j < stadion[i].sponsor_count; j++)
				{
					for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
						cout << "- " << stadion[i].sponsor[j].competitions[m].competitions_name << endl;
				}
				count++;
			}
		}
		if (count == 0)
			cout << "Не знайдено змагань, проведених  на даному  стадіоні" << endl;
		cout << endl;
		count = 0;

		cout << "Змагання у спортзалах:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			if (buildings_name == gym[i].buildings_name)
			{
				for (int j = 0; j < gym[i].sponsor_count; j++)
				{
					for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
						cout << "- " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
				}
				count++;
			}
		}
		if (count == 0)
			cout << "Не знайдено змагань, проведених  в даному  спортзалі" << endl;
		cout << endl;
		count = 0;

		for (int i = 0; i < court_count; i++)
		{
			cout << "Змагання на кортах для тенісу:" << endl;
			if (buildings_name == court[i].buildings_name)
			{
				for (int j = 0; j < court[i].sponsor_count; j++)
				{
					for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
						cout << "- " << court[i].sponsor[j].competitions[m].competitions_name << endl;
				}
				count++;
			}
		}
		if (count == 0)
			cout << "Не знайдено змагань, проведених  на даному корті" << endl;
		cout << endl;
		count = 0;
		break;
	default:
		cout << "Помилка! Спробуйте ще раз" << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
void Functions::Sportsmans(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "Отримати список спортсменів, які займаються даним видом спорту: 1" << endl;
	cout << "Отримати список спортсменів, які тренуються у якогось тренера в цілому: 2" << endl;
	cout << "Отримати список спортсменів, які займаються одним і більше видом спорту: 3" << endl << endl;

	string sport_type, trainer_name;
	int number, count = 0;
	cout << "Введіть номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Оберіть вид спорту: ";
		cin >> sport_type;
		cout << endl;

		cout << "Спортсмени, які тренуються на стадіонах:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadion[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
						{
							if (sport_type == stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								cout << "- " << stadion[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортсменів, які тренуються на даному стадіоні вибраним видом спорту" << endl;
		cout << endl;
		count = 0;
		//////////////////////////////////////////////////////////////////////////////////
		cout << "Спортсмени, які тренуються в спортзалах:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
						{
							if (sport_type == gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортсменів, які тренуються в даному спортзалі вибраним видом спорту" << endl;
		cout << endl;
		count = 0;
		/////////////////////////////////////////////////////////////////////////////////////
		cout << "Спортсмени, які тренуються на кортах для тенісу:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
						{
							if (sport_type == court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортсменів, які тренуються на даному корті вибраним видом спорту" << endl;
		cout << endl;
		count = 0;
		break;

	case 2:
		cout << "Введіть тренера: ";
		cin >> trainer_name;
		cout << endl;

		cout << "Спортсмени, які тренуються на стадіонах:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadion[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
						{
							for (int b = 0; b < stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
							{
								if (trainer_name == stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name)
								{
									cout << "- " << stadion[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
									count++;
								}
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортсменів, які тренуються на даному стадіоні у тренера" << endl;
		cout << endl;
		count = 0;

		cout << "Спортсмени, які тренуються в спортзалах:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
						{
							for (int b = 0; b < gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
							{
								if (trainer_name == gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name)
								{
									cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
									count++;
								}
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортсменів, які тренуються в даному спортзалі у тренера" << endl;
		cout << endl;
		count = 0;

		cout << "Спортсмени, які тренуються на кортах для тенісу:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
						{
							for (int b = 0; b < court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
							{
								if (trainer_name == court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name)
								{
									cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
									count++;
								}
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортсменів, які тренуються на даному корті у тренера" << endl;
		cout << endl;
		count = 0;
		break;
	case 3:
		cout << "Спортсмени, які тренуються на стадіонах:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadion[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count > 1)
						{
							cout << "- " << stadion[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
							cout << "Види спорта: " << endl;
							for (int a = 0; a < stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
								cout << a + 1 << "; " << stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
							cout << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортсменів, які займаються більше ніж одниим видом спорту на стадіоні" << endl << endl;
		count = 0;

		cout << "Спортсмени, які тренуються у спортзалах:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (gym[i].sponsor[j].competitions[m].sportsman[n].sport_count > 1)
						{
							cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
							cout << "Види спорту: " << endl;
							for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
								cout << a + 1 << "; " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
							cout << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортсменів, які займаються більше ніж одниим видом спорту в спортзалах" << endl << endl;
		count = 0;

		cout << "Спортсмени, які тренуються на кортах:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (court[i].sponsor[j].competitions[m].sportsman[n].sport_count > 1)
						{
							cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
							cout << "Види спорту: " << endl;
							for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
								cout << a + 1 << "; " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
							cout << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено спортсменів, які займаються більше ніж одниим видом спорту на кортах" << endl << endl;
		count = 0;
		break;
	default:
		cout << "Помилка! Спробуйте ще раз." << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
void Functions::Trainers(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "Отримати список тренерів вказаного спортсмена: 1" << endl;
	cout << "Отримати список тренерів певного виду спорту:  2" << endl << endl;

	string sportsman_name, sport_name;
	int number, count = 0;
	cout << "Введіть номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Введіть спортсмена: ";
		cin >> sportsman_name;
		cout << endl;

		cout << "Тренери, які тренерують спортсменів на стадіонах:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadion[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (sportsman_name == stadion[i].sponsor[j].competitions[m].sportsman[n].sportsman_name)
						{
							for (int a = 0; a < stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
							{
								cout << "Вид спорту: " << stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
								for (int b = 0; b < stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
									cout << b + 1 << ". " << stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								cout << endl;
							}
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено тренера, який проводять тренування в даного спортсмена на стадіонах" << endl << endl;
		count = 0;

		cout << "Тренера, які тренують спортсменів в спортзалах:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (sportsman_name == gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name)
						{
							for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
							{
								cout << "Вид спорту: " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
								for (int b = 0; b < gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
									cout << b + 1 << ". " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								cout << endl;
							}
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено тренера, який проводять тренування в даного спортсмена в спортзалах" << endl << endl;
		count = 0;

		cout << "Тренера, які тренують спортсменів на кортах:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (sportsman_name == court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name)
						{
							for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
							{
								cout << "Вид спорту: " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
								for (int b = 0; b < court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
									cout << b + 1 << ". " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								cout << endl;
							}
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено тренера, який проводять тренування в даного спортсмена  на кортах" << endl << endl;
		count = 0;
		break;

	case 2:
		cout << "Введіть вид спорту: ";
		cin >> sport_name;
		cout << endl;

		cout << "Тренера, які проводять заняття на стадіонах:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadion[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
						{
							if (sport_name == stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								for (int b = 0; b < stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
									cout << "- " << stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено тренера, який відповідає за даний вид спорту на стадіонах" << endl;
		cout << endl;
		count = 0;

		cout << "Тренера, які тренують спортсменів в спортзалах" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
						{
							if (sport_name == gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								for (int b = 0; b < gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
									cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено тренера, який відповідає за даний вид спорту в спортзалах" << endl;
		cout << endl;
		count = 0;

		cout << "Тренера, які тренерують спортсменів на кортах:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
						{
							if (sport_name == court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								for (int b = 0; b < court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
									cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Не знайдено тренера, який відповідає за даний вид спорту на кортах" << endl;
		cout << endl;
		count = 0;
		break;
	default:
		cout << "Помилка! Спробуйте ще раз" << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
void Functions::Achievement(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "Отримати список призерів даного змагання: 1" << endl;
	cout << "Отримати список організаторів змагань і число проведених ними змагань протягом певного часу : 2" << endl << endl;

	string competition_name;
	int start_of_competitions, end_of_competitions, number, count = 0;
	cout << "Введіть номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Введіть назву змагання: ";
		cin >> competition_name;
		cout << endl;

		cout << "Тренування на стадіонах:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
				{
					if (competition_name == stadion[i].sponsor[j].competitions[m].competitions_name)
					{
						for (int n = 0; n < stadion[i].sponsor[j].competitions[m].sportsman_quantity; n++)
						{
							if (stadion[i].sponsor[j].competitions[m].sportsman[n].place < 4)
							{
								cout << "- " << stadion[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Даного змагання, проведеного на стадіонах, не існує, або призери відсутні" << endl;
		cout << endl;
		count = 0;

		cout << "Тренування в спортзалах:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					if (competition_name == gym[i].sponsor[j].competitions[m].competitions_name)
					{
						for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
						{
							if (gym[i].sponsor[j].competitions[m].sportsman[n].place < 4)
							{
								cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Даного змагання, проведеного в спортзалах, не існує, або призери відсутні" << endl;
		cout << endl;
		count = 0;

		cout << "Тренування на кортах для тенісу:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					if (competition_name == court[i].sponsor[j].competitions[m].competitions_name)
					{
						for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
						{
							if (court[i].sponsor[j].competitions[m].sportsman[n].place < 4)
							{
								cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Даного змагання, проведеного на кортах, не існує, або призери відсутні" << endl;
		cout << endl;
		count = 0;
		break;

	case 2:
		cout << "Дата початку змагання: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "Дата закінчення змагання: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "Спонсори стадіонів:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				cout << "Спонсор: " << stadion[i].sponsor[j].sponsor_name << endl;
				for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
				{
					if (stadion[i].sponsor[j].competitions[m].date_start >= start_of_competitions)
					{
						if (stadion[i].sponsor[j].competitions[m].date_end <= end_of_competitions)
						{
							cout << "- " << stadion[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
				if (count == 0)
					cout << "У даного спонсора відсутні змагання, що проводяться в даний період часу" << endl;
				cout << endl;
			}
		}
		count = 0;

		cout << "Спонсори спортзалів:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				cout << "Спонсор: " << gym[i].sponsor[j].sponsor_name << endl;
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					if (gym[i].sponsor[j].competitions[m].date_start >= start_of_competitions)
					{
						if (gym[i].sponsor[j].competitions[m].date_end <= end_of_competitions)
						{
							cout << "- " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
				if (count == 0)
					cout << "У даного спонсора відсутні змагання, що проводяться в даний період часу" << endl;
				cout << endl;
			}
		}
		count = 0;

		cout << "Спонсори кортів для тенісу:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				cout << "Спонсор: " << court[i].sponsor[j].sponsor_name << endl;
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					if (court[i].sponsor[j].competitions[m].date_start >= start_of_competitions)
					{
						if (court[i].sponsor[j].competitions[m].date_end <= end_of_competitions)
						{
							cout << "- " << court[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
				if (count == 0)
					cout << "У даного спонсора відсутні змагання, що проводяться в даний період часу" << endl;
				cout << endl;
			}
		}
		count = 0;
		break;
	default:
		cout << "Помилка! Спробуйте ще раз" << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
