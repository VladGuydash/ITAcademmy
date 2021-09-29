#include <iostream>
#include <string>
#include "Data.h" 
#include "windows.h"

using namespace std;


void main() {
	system("color 3f");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int stadion_count, gym_count, court_count;
	Stadion* stadion;
	Gym* gym;
	Court* court;


	do {
		cout << "������ ������� �������(> 0): ";
		cin >> stadion_count;
		cout << endl;
		system("cls");
	} while (stadion_count <= 0);
	do {
		cout << "������ ������� ���������(> 0): ";
		cin >> gym_count;
		cout << endl;
		system("cls");
	} while (gym_count <= 0);
	do {
		cout << "������ ������� ����� ��� �����(> 0): ";
		cin >> court_count;
		cout << endl;
		system("cls");
	} while (court_count <= 0);

	stadion = new Stadion[stadion_count];
	gym = new Gym[gym_count];
	court = new Court[court_count];

	for (int i = 0; i < stadion_count; i++)
	{
		cout << "������ ����� ������� � " << i + 1 << ": ";
		cin.ignore();
		cin.getline(stadion[i].buildings_name, 30);
		cout << endl;
		system("cls");
		do {
			cout << "������ ����� (> 0): ";
			cin >> stadion[i].area;
			cout << endl;
			system("cls");
		} while (stadion[i].area <= 0);

		do {
			cout << "������ ��������� �������(> 0): ";
			cin >> stadion[i].capacity;
			cout << endl;
			system("cls");
		} while (stadion[i].capacity <= 0);

		do {
			cout << "ʳ������ �������� �������(> 0): ";
			cin >> stadion[i].sponsor_count;
			cout << endl;
			system("cls");
		} while (stadion[i].sponsor_count <= 0);

		stadion[i].sponsor = new Sponsor[stadion[i].sponsor_count];
		for (int j = 0; j < stadion[i].sponsor_count; j++)
		{
			cout << "������ ��'� �������� � " << j + 1 << ": ";
			cin.ignore();
			cin.getline(stadion[i].sponsor[j].sponsor_name, 30);
			cout << endl;
			system("cls");
			do {
				cout << "ʳ������ �������, ���������� �� ���������(> 0): ";
				cin >> stadion[i].sponsor[j].competitions_quantity;
				cout << endl;
				system("cls");
			} while (stadion[i].sponsor[j].competitions_quantity <= 0);

			stadion[i].sponsor[j].competitions = new Competitions[stadion[i].sponsor[j].competitions_quantity];


			for (int m = 0; m < stadion[i].sponsor[j].competitions_quantity; m++)
			{
				cout << "����� �������� �" << m + 1 << ": ";
				cin.ignore();
				cin.getline(stadion[i].sponsor[j].competitions[m].competitions_name, 30);
				cout << endl;
				system("cls");
				cout << "���� ������� ��������: ";
				cin >> stadion[i].sponsor[j].competitions[m].date_start;
				cout << endl;
				system("cls");
				do {
					cout << "���� ��������� ��������: ";
					cin >> stadion[i].sponsor[j].competitions[m].date_end;
					cout << endl;
					system("cls");
				} while (stadion[i].sponsor[j].competitions[m].date_start > stadion[i].sponsor[j].competitions[m].date_end);

				do {
					cout << "ʳ������ ����������, �� ����� ������ � ���������: ";
					cin >> stadion[i].sponsor[j].competitions[m].sportsman_quantity;
					cout << endl;
					system("cls");
				} while (stadion[i].sponsor[j].competitions[m].sportsman_quantity <= 0);

				stadion[i].sponsor[j].competitions[m].sportsman = new Sportsman[stadion[i].sponsor[j].competitions[m].sportsman_quantity];


				for (int n = 0; n < stadion[i].sponsor[j].competitions[m].sportsman_quantity; n++)
				{
					cout << "������ ��'� ���������� � " << n + 1 << ": ";
					cin.ignore();
					cin.getline(stadion[i].sponsor[j].competitions[m].sportsman[n].sportsman_name, 30);
					cout << endl;
					system("cls");
					do {
						cout << "̳���, ��� ����� ����� ���������: ";
						cin >> stadion[i].sponsor[j].competitions[m].sportsman[n].place;
						cout << endl;
						system("cls");
					} while (stadion[i].sponsor[j].competitions[m].sportsman[n].place <= 0);

					do {
						cout << "ʳ������ ���� ������, ����� ��������� ���������: ";
						cin >> stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count;
						cout << endl;
						system("cls");
					} while (stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count <= 0);

					stadion[i].sponsor[j].competitions[m].sportsman[n].sport = new Kind_of_Sport[stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count];


					for (int a = 0; a < stadion[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
					{
						cout << "����� ���� ������ � " << a + 1 << ", ���� ��������� ���������: ";
						cin.ignore();
						cin.getline(stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name, 30);
						system("cls");
						cout << endl;

						do {
							cout << "ʳ������ �������, � ���� ��������� ��������� ����� ����� ������: ";
							cin >> stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count;
							cout << endl;
							system("cls");
						} while (stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count <= 0);

						stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer = new Trainer[stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count];

						for (int b = 0; b < stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
						{
							cout << "������ ��'� ������� � " << b + 1 << ": ";
							cin.ignore();
							cin.getline(stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name, 30);
							cout << endl;
							system("cls");
						}
					}
				}
			}
		}
	}
	cout << endl;
	///////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < gym_count; i++)
	{
		cout << "������ ����� ��������� � " << i + 1 << ": ";
		cin.ignore();
		cin.getline(gym[i].buildings_name, 30);
		cout << endl;
		system("cls");
		do {
			cout << "����� ���������(> 0): ";
			cin >> gym[i].area;
			cout << endl;
			system("cls");
		} while (gym[i].area <= 0);

		do {
			cout << "ʳ������ ��������� � ���(> 0): ";
			cin >> gym[i].count_simulators;
			cout << endl;
			system("cls");
		} while (gym[i].count_simulators <= 0);

		do {
			cout << "ʳ������ �������� ���������(> 0): ";
			cin >> gym[i].sponsor_count;
			cout << endl;
			system("cls");
		} while (gym[i].sponsor_count <= 0);

		gym[i].sponsor = new Sponsor[gym[i].sponsor_count];
		for (int j = 0; j < gym[i].sponsor_count; j++)
		{
			cout << "������ �������� � " << j + 1 << ": ";
			cin.ignore();
			cin.getline(gym[i].sponsor[j].sponsor_name, 30);
			cout << endl;
			system("cls");
			do {
				cout << "ʳ������ �������, �� �� ������� �������(> 0): ";
				cin >> gym[i].sponsor[j].competitions_quantity;
				cout << endl;
				system("cls");
			} while (gym[i].sponsor[j].competitions_quantity <= 0);

			gym[i].sponsor[j].competitions = new Competitions[gym[i].sponsor[j].competitions_quantity];
			for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
			{
				cout << "����� �������� � " << m + 1 << ": ";
				cin.ignore();
				cin.getline(gym[i].sponsor[j].competitions[m].competitions_name, 30);
				cout << endl;
				system("cls");
				cout << "���� ������� ��������: ";
				cin >> gym[i].sponsor[j].competitions[m].date_start;
				cout << endl;
				system("cls");
				do {
					cout << "���� ��������� ��������: ";
					cin >> gym[i].sponsor[j].competitions[m].date_end;
					cout << endl;
					system("cls");
				} while (gym[i].sponsor[j].competitions[m].date_start > gym[i].sponsor[j].competitions[m].date_end);

				do {
					cout << "ʳ������ ����������, �� ����� ������ � ���������: ";
					cin >> gym[i].sponsor[j].competitions[m].sportsman_quantity;
					cout << endl;
					system("cls");
				} while (gym[i].sponsor[j].competitions[m].sportsman_quantity <= 0);

				gym[i].sponsor[j].competitions[m].sportsman = new Sportsman[gym[i].sponsor[j].competitions[m].sportsman_quantity];
				for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
				{
					cout << "������ ��'� ���������� � " << n + 1 << ": ";
					cin.ignore();
					cin.getline(gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name, 30);
					cout << endl;
					system("cls");
					do {
						cout << "������ ����, ��� ����� ���������: ";
						cin >> gym[i].sponsor[j].competitions[m].sportsman[n].place;
						cout << endl;
						system("cls");
					} while (gym[i].sponsor[j].competitions[m].sportsman[n].place <= 0);

					do {
						cout << "ʳ������ ���� ������, ����� ��������� ���������: ";
						cin >> gym[i].sponsor[j].competitions[m].sportsman[n].sport_count;
						cout << endl;
						system("cls");
					} while (gym[i].sponsor[j].competitions[m].sportsman[n].sport_count <= 0);

					gym[i].sponsor[j].competitions[m].sportsman[n].sport = new Kind_of_Sport[gym[i].sponsor[j].competitions[m].sportsman[n].sport_count];
					for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
					{
						cout << "����� ���� ������ � " << a + 1 << ", ���� ��������� ����� ���������: ";
						cin.ignore();
						cin.getline(gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name, 30);
						cout << endl;
						system("cls");
						do {
							cout << "ʳ������ �������, � ���� ��������� ���������� ����� ����� ������: ";
							cin >> gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count;
							cout << endl;
							system("cls");
						} while (gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count <= 0);

						gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer = new Trainer[gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count];
						for (int b = 0; b < gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
						{
							cout << "��'� ������� � " << b + 1 << ": ";
							cin.ignore();
							cin.getline(gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name, 30);
							cout << endl;
							system("cls");
						}
					}
				}
			}
		}
	}
	cout << endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < court_count; i++)
	{
		cout << "������ ����� ����� ��� ����� � " << i + 1 << ": ";
		cin.ignore();
		cin.getline(court[i].buildings_name, 30);
		cout << endl;
		system("cls");
		do {
			cout << "����� �����(> 0): ";
			cin >> court[i].area;
			cout << endl;
			system("cls");
		} while (court[i].area <= 0);

		cout << "��� �������� �����: ";
		cin.ignore();
		cin.getline(court[i].type, 30);
		cout << endl;
		system("cls");
		do {
			cout << "ʳ������ �������� �����(> 0): ";
			cin >> court[i].sponsor_count;
			cout << endl;
			system("cls");
		} while (court[i].sponsor_count <= 0);

		court[i].sponsor = new Sponsor[court[i].sponsor_count];
		for (int j = 0; j < court[i].sponsor_count; j++)
		{
			cout << "������ ��'� �������� � " << j + 1 << ": ";
			cin.ignore();
			cin.getline(court[i].sponsor[j].sponsor_name, 30);
			cout << endl;
			system("cls");
			do {
				cout << "ʳ������ �������, ���������� �� ���������(> 0): ";
				cin >> court[i].sponsor[j].competitions_quantity;
				cout << endl;
				system("cls");
			} while (court[i].sponsor[j].competitions_quantity <= 0);

			court[i].sponsor[j].competitions = new Competitions[court[i].sponsor[j].competitions_quantity];
			for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
			{
				cout << "����� �������� � " << m + 1 << ": ";
				cin.ignore();
				cin.getline(court[i].sponsor[j].competitions[m].competitions_name, 30);
				cout << endl;
				system("cls");
				cout << "���� ������� ��������: ";
				cin >> court[i].sponsor[j].competitions[m].date_start;
				cout << endl;
				system("cls");
				do {
					cout << "���� ��������� ��������: ";
					cin >> court[i].sponsor[j].competitions[m].date_end;
					cout << endl;
					system("cls");
				} while (court[i].sponsor[j].competitions[m].date_start > court[i].sponsor[j].competitions[m].date_end);

				do {
					cout << "ʳ������ ����������, �� ����� ������ � �������: ";
					cin >> court[i].sponsor[j].competitions[m].sportsman_quantity;
					cout << endl;
					system("cls");
				} while (court[i].sponsor[j].competitions[m].sportsman_quantity <= 0);

				court[i].sponsor[j].competitions[m].sportsman = new Sportsman[court[i].sponsor[j].competitions[m].sportsman_quantity];
				for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
				{
					cout << "��'� ���������� �" << n + 1 << ": ";
					cin.ignore();
					cin.getline(court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name, 30);
					cout << endl;
					system("cls");
					do {
						cout << "̳���, ��� ����� ��������� � ������ �������: ";
						cin >> court[i].sponsor[j].competitions[m].sportsman[n].place;
						cout << endl;
						system("cls");
					} while (court[i].sponsor[j].competitions[m].sportsman[n].place <= 0);

					do {
						cout << "ʳ������ ���� ������, ����� ��������� ���������: ";
						cin >> court[i].sponsor[j].competitions[m].sportsman[n].sport_count;
						cout << endl;
						system("cls");
					} while (court[i].sponsor[j].competitions[m].sportsman[n].sport_count <= 0);

					court[i].sponsor[j].competitions[m].sportsman[n].sport = new Kind_of_Sport[court[i].sponsor[j].competitions[m].sportsman[n].sport_count];
					for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_count; a++)
					{
						cout << "����� ���� ������ � " << a + 1 << ", ���� ��������� ���������: ";
						cin.ignore();
						cin.getline(court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name, 30);
						cout << endl;
						system("cls");
						do {
							cout << "ʳ������ �������, � ���� ���������� ���������� ����� ����� ������: ";
							cin >> court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count;
							cout << endl;
							system("cls");
						} while (court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count <= 0);

						court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer = new Trainer[court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count];
						for (int b = 0; b < court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_count; b++)
						{
							cout << "������ ��'� ������� � " << b + 1 << ": ";
							cin.ignore();
							cin.getline(court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name, 30);
							cout << endl;
							system("cls");
						}
					}
				}
			}
		}
	}
	cout << endl;
	system("cls");

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}