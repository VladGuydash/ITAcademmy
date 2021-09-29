#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

void Functions::Buildings_Sport(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "������ ������ ������� ����: 1" << endl;
	cout << "������ ������ � ���� ���������� ������� �� ������� ������� ����: 2" << endl << endl;

	string building_name;
	int number, start_of_competitions, end_of_competitions, count = 0;
	cout << "������ �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������ ��� (������, �������� ��� ����): ";
		cin >> building_name;
		cout << endl;

		if (building_name == "������")
		{
			cout << "����� �������:" << endl;
			for (int i = 0; i < stadion_count; i++)
				cout << i + 1 << ". " << stadion[i].buildings_name << endl;
			cout << endl;
		}
		else if (building_name == "��������")
		{
			cout << "����� ���������:" << endl;
			for (int i = 0; i < gym_count; i++)
				cout << i + 1 << ". " << gym[i].buildings_name << endl;
			cout << endl;
		}
		else if (building_name == "����")
		{
			cout << "����� ����� ��� �����:" << endl;
			for (int i = 0; i < court_count; i++)
				cout << i + 1 << ". " << court[i].buildings_name << endl;
			cout << endl;
		}
		else
			cout << "�������! ��������� �� ���" << endl << endl;
		break;
	case 2:
		cout << "������ ���� ������� ��������: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "������ ���� ��������� ��������: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "��������, �������� �� ������:" << endl;
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
							cout << "������ � " << i + 1 << ": " << stadion[i].buildings_name << endl;
							cout << "����� ��������: " << stadion[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "���� ������� ��������: " << stadion[i].sponsor[j].competitions[m].date_start << endl;
							cout << "���� ��������� ��������: " << stadion[i].sponsor[j].competitions[m].date_end << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "�� �������� �������, �� ���� ����������� �������� � ������� ����� ����" << endl << endl;
		count = 0;
		//////////////////////////////////////////////////////////////////////////
		cout << "�������� � ����������:" << endl;
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
							cout << "�������� � " << i + 1 << ": " << gym[i].buildings_name << endl;
							cout << "����� ��������: " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "���� ������� ��������: " << gym[i].sponsor[j].competitions[m].date_start << endl;
							cout << "���� ��������� ��������: " << gym[i].sponsor[j].competitions[m].date_end << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "�� �������� ���������, �� ���� ����������� �������� � ������� ����� ����" << endl << endl;
		count = 0;

		cout << "�������� �� ������:" << endl;
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
							cout << "���� � " << i + 1 << ": " << court[i].buildings_name << endl;
							cout << "����� ��������: " << court[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "���� ������� ��������: " << court[i].sponsor[j].competitions[m].date_start << endl;
							cout << "���� ��������� ��������: " << court[i].sponsor[j].competitions[m].date_end << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "�� �������� �����, �� ���� ����������� �������� � ������� ����� ����" << endl << endl;
		count = 0;
		break;
	default:
		cout << "�������! ��������� �� ���" << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
void Functions::Competitions(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "�������� ������ �������, ���������� �� ������� ������� ����: 1" << endl;
	cout << "�������� ������ �������, ���������� � ������� ����������� ��������: 2" << endl << endl;

	string buildings_name;
	int start_of_competitions, end_of_competitions, number, count = 0;
	cout << "������ �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������ ���� ������� ��������: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "������ �� ��������� ��������: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "�������� �� ��������:" << endl;
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
			cout << "�� �������� �������, ���������� � ����� ������� ���� �� ��������" << endl;
		cout << endl;
		count = 0;
		//////////////////////////////////////////////////////////////////////////////////////////////////
		cout << "�������� � ����������:" << endl;
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
			cout << "�� �������� �������, ���������� � ����� ������� ���� � ����������." << endl;
		cout << endl;
		count = 0;
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		cout << "�������� �� ������ ��� �����:" << endl;
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
			cout << "�� �������� �������, ���������� � ����� ������� ���� �� ������ ��� �����" << endl;
		cout << endl;
		count = 0;
		break;

	case 2:
		cout << "������ ����� �������: ";
		cin >> buildings_name;
		cout << endl;

		cout << "�������� �� ��������:" << endl;
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
			cout << "�� �������� �������, ����������  �� ������  ������" << endl;
		cout << endl;
		count = 0;

		cout << "�������� � ����������:" << endl;
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
			cout << "�� �������� �������, ����������  � ������  ��������" << endl;
		cout << endl;
		count = 0;

		for (int i = 0; i < court_count; i++)
		{
			cout << "�������� �� ������ ��� �����:" << endl;
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
			cout << "�� �������� �������, ����������  �� ������ ����" << endl;
		cout << endl;
		count = 0;
		break;
	default:
		cout << "�������! ��������� �� ���" << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
void Functions::Sportsmans(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "�������� ������ ����������, �� ���������� ����� ����� ������: 1" << endl;
	cout << "�������� ������ ����������, �� ���������� � ������� ������� � ������: 2" << endl;
	cout << "�������� ������ ����������, �� ���������� ����� � ����� ����� ������: 3" << endl << endl;

	string sport_type, trainer_name;
	int number, count = 0;
	cout << "������ �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������ ��� ������: ";
		cin >> sport_type;
		cout << endl;

		cout << "����������, �� ���������� �� ��������:" << endl;
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
			cout << "�� �������� ����������, �� ���������� �� ������ ������ �������� ����� ������" << endl;
		cout << endl;
		count = 0;
		//////////////////////////////////////////////////////////////////////////////////
		cout << "����������, �� ���������� � ����������:" << endl;
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
			cout << "�� �������� ����������, �� ���������� � ������ �������� �������� ����� ������" << endl;
		cout << endl;
		count = 0;
		/////////////////////////////////////////////////////////////////////////////////////
		cout << "����������, �� ���������� �� ������ ��� �����:" << endl;
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
			cout << "�� �������� ����������, �� ���������� �� ������ ���� �������� ����� ������" << endl;
		cout << endl;
		count = 0;
		break;

	case 2:
		cout << "������ �������: ";
		cin >> trainer_name;
		cout << endl;

		cout << "����������, �� ���������� �� ��������:" << endl;
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
			cout << "�� �������� ����������, �� ���������� �� ������ ������ � �������" << endl;
		cout << endl;
		count = 0;

		cout << "����������, �� ���������� � ����������:" << endl;
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
			cout << "�� �������� ����������, �� ���������� � ������ �������� � �������" << endl;
		cout << endl;
		count = 0;

		cout << "����������, �� ���������� �� ������ ��� �����:" << endl;
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
			cout << "�� �������� ����������, �� ���������� �� ������ ���� � �������" << endl;
		cout << endl;
		count = 0;
		break;
	case 3:
		cout << "����������, �� ���������� �� ��������:" << endl;
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
							cout << "���� ������: " << endl;
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
			cout << "�� �������� ����������, �� ���������� ����� �� ������ ����� ������ �� ������" << endl << endl;
		count = 0;

		cout << "����������, �� ���������� � ����������:" << endl;
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
							cout << "���� ������: " << endl;
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
			cout << "�� �������� ����������, �� ���������� ����� �� ������ ����� ������ � ����������" << endl << endl;
		count = 0;

		cout << "����������, �� ���������� �� ������:" << endl;
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
							cout << "���� ������: " << endl;
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
			cout << "�� �������� ����������, �� ���������� ����� �� ������ ����� ������ �� ������" << endl << endl;
		count = 0;
		break;
	default:
		cout << "�������! ��������� �� ���." << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
void Functions::Trainers(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "�������� ������ ������� ��������� ����������: 1" << endl;
	cout << "�������� ������ ������� ������� ���� ������:  2" << endl << endl;

	string sportsman_name, sport_name;
	int number, count = 0;
	cout << "������ �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������ ����������: ";
		cin >> sportsman_name;
		cout << endl;

		cout << "�������, �� ���������� ���������� �� ��������:" << endl;
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
								cout << "��� ������: " << stadion[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
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
			cout << "�� �������� �������, ���� ��������� ���������� � ������ ���������� �� ��������" << endl << endl;
		count = 0;

		cout << "�������, �� �������� ���������� � ����������:" << endl;
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
								cout << "��� ������: " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
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
			cout << "�� �������� �������, ���� ��������� ���������� � ������ ���������� � ����������" << endl << endl;
		count = 0;

		cout << "�������, �� �������� ���������� �� ������:" << endl;
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
								cout << "��� ������: " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
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
			cout << "�� �������� �������, ���� ��������� ���������� � ������ ����������  �� ������" << endl << endl;
		count = 0;
		break;

	case 2:
		cout << "������ ��� ������: ";
		cin >> sport_name;
		cout << endl;

		cout << "�������, �� ��������� ������� �� ��������:" << endl;
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
			cout << "�� �������� �������, ���� ������� �� ����� ��� ������ �� ��������" << endl;
		cout << endl;
		count = 0;

		cout << "�������, �� �������� ���������� � ����������" << endl;
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
			cout << "�� �������� �������, ���� ������� �� ����� ��� ������ � ����������" << endl;
		cout << endl;
		count = 0;

		cout << "�������, �� ���������� ���������� �� ������:" << endl;
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
			cout << "�� �������� �������, ���� ������� �� ����� ��� ������ �� ������" << endl;
		cout << endl;
		count = 0;
		break;
	default:
		cout << "�������! ��������� �� ���" << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
void Functions::Achievement(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count)
{
	cout << "�������� ������ ������� ������ ��������: 1" << endl;
	cout << "�������� ������ ����������� ������� � ����� ���������� ���� ������� �������� ������� ���� : 2" << endl << endl;

	string competition_name;
	int start_of_competitions, end_of_competitions, number, count = 0;
	cout << "������ �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������ ����� ��������: ";
		cin >> competition_name;
		cout << endl;

		cout << "���������� �� ��������:" << endl;
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
			cout << "������ ��������, ����������� �� ��������, �� ����, ��� ������� ������" << endl;
		cout << endl;
		count = 0;

		cout << "���������� � ����������:" << endl;
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
			cout << "������ ��������, ����������� � ����������, �� ����, ��� ������� ������" << endl;
		cout << endl;
		count = 0;

		cout << "���������� �� ������ ��� �����:" << endl;
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
			cout << "������ ��������, ����������� �� ������, �� ����, ��� ������� ������" << endl;
		cout << endl;
		count = 0;
		break;

	case 2:
		cout << "���� ������� ��������: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "���� ��������� ��������: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "�������� �������:" << endl;
		for (int i = 0; i < stadion_count; i++)
		{
			for (int j = 0; j < stadion[i].sponsor_count; j++)
			{
				cout << "�������: " << stadion[i].sponsor[j].sponsor_name << endl;
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
					cout << "� ������ �������� ������ ��������, �� ����������� � ����� ����� ����" << endl;
				cout << endl;
			}
		}
		count = 0;

		cout << "�������� ���������:" << endl;
		for (int i = 0; i < gym_count; i++)
		{
			for (int j = 0; j < gym[i].sponsor_count; j++)
			{
				cout << "�������: " << gym[i].sponsor[j].sponsor_name << endl;
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
					cout << "� ������ �������� ������ ��������, �� ����������� � ����� ����� ����" << endl;
				cout << endl;
			}
		}
		count = 0;

		cout << "�������� ����� ��� �����:" << endl;
		for (int i = 0; i < court_count; i++)
		{
			for (int j = 0; j < court[i].sponsor_count; j++)
			{
				cout << "�������: " << court[i].sponsor[j].sponsor_name << endl;
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
					cout << "� ������ �������� ������ ��������, �� ����������� � ����� ����� ����" << endl;
				cout << endl;
			}
		}
		count = 0;
		break;
	default:
		cout << "�������! ��������� �� ���" << endl << endl;
		break;
	}

	Functions::Menu(stadion, stadion_count, gym, gym_count, court, court_count);
}
