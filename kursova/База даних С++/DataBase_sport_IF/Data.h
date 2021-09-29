class Trainer
{
public:
	char trainer_name[100];
};
class Kind_of_Sport
{
public:
	char sport_name[100];
	int trainer_count;
	Trainer* trainer;
};
class Sportsman
{
public:
	char sportsman_name[100];
	int place;
	int sport_count;
	Kind_of_Sport* sport;
};
class Competitions
{
public:
	char competitions_name[100];
	int sportsman_quantity;
	int date_start;
	int date_end;
	Sportsman* sportsman;
};
class Sponsor
{
public:
	char sponsor_name[30];
	int competitions_quantity;
	Competitions* competitions;
};
class Buildings
{
public:
	char buildings_name[30];
	int area;
	int sponsor_count;
	Sponsor* sponsor;
};
class Stadion : public Buildings
{
public:
	int capacity;
};
class Gym : public Buildings
{
public:
	int count_simulators;
};
class Court : public Buildings
{
public:
	char type[30];
};

class Functions
{
public:
	static void Menu(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count);
	static void Competitions(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count);
	static void Sportsmans(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count);
	static void Trainers(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count);
	static void Achievement(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count);
	static void Buildings_Sport(Stadion* stadion, int stadion_count, Gym* gym, int gym_count, Court* court, int court_count);
};

class Data {
private:
	Trainer trainer;
	Kind_of_Sport kind_of_sport;
	Sportsman sportsman;
	Competitions competitions;
	Buildings buildings;
	Sponsor sponsor;
	Stadion stadion;
	Gym  gym;
	Court court;
public:
	Data();
	Data(Trainer trainer_, Kind_of_Sport kind_of_sport_, Sportsman sportsman_, Competitions competitions_, Buildings buildings_, Sponsor sponsor_,
		Stadion stadion_, Gym gym_, Court court_);
	~Data();


	void DataEntry(Trainer trainer_, Kind_of_Sport kind_of_sport_, Sportsman sportsman_, Competitions competitions_, Buildings buildings_, Sponsor sponsor_,
		Stadion stadion_, Gym gym_, Court court_);

	Trainer GetTrainer() { return trainer; };
	Kind_of_Sport GetKind_of_Sport() { return kind_of_sport; };
	Sportsman GetSportsman() { return sportsman; };
	Competitions GetCompetitions() { return competitions; };
	Buildings GetBuildings() { return buildings; };
	Sponsor GetSponsor() { return sponsor; };
	Stadion GetStadion() { return stadion; };
	Gym  GetGym() { return gym; };
	Court GetCourt() { return court; };

	Data& operator = (Data d_o);

}; 



