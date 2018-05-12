//Semester Assignment with Solution
/*
Department of Computer Science & Software Engineering, FBAS, IIUI.
OOP Assignment I
Deadline: 10-04-2018


Q 1) You are required to maintain database for Cricket players. There are 9 teams in International Cricket Pakistan, India, South Africa, West Indies, Bangladesh, Srilanka, Austrailia, Newzealand, Ingland. You have to keep records of the players. Player should have information i.s.
1.	Name
2.	Country
3.	DOB
4.	Date of dabut
5.	Category i.e. Bowler, Batsman, Fielder, All-rounder

6.	Total Scores
7.	Best Score
8.	Total Wickets
9.	Best Wicket figure
10.	Total Over Bowled
11.	Total Scores given

6-11 Attributes should not be taken by user automatically calculated. user should be allowed to add new player, edit existing player, search player by Nationality, by youngest age, by eldest age, by most no of matches, by best batting average, by best batting record, by besting bowling record, by highest wicket taker. Also the user must be facilitated by to delete the record by combining two attributes i.e., DOB and Name. Each of the user choice must be mapped with an equivalent function.
 
When a new player is added new node is created. When you want to update a player means you want to update record of the player 6-11 should be updated automatically. Linked list should be used to implement the required task.

You may use structure “struct time” for getting system time.

***********************************GOOD LUCK*******************************
*/






//Programed By Bilal Tariq
//3160/BSCS/F15

#include<iostream>
#include<string>
#include <ctime>
#include<iomanip>
#include <sstream>
using namespace std;

string setDate();

struct Player
{
	string name;
	string country;
	string DOB, DOD;
	string cat;
	int Best_Wickets;
	int N_O_Matches;
	int  tot_score;
	int	best_score;
	int tot_wickets;
	int tot_score_given;
	double tot_over_bowled;
	double batAVG;

	Player *next;
	Player()
	{
		name="ABC";
		country="No Provided";
		DOB="No Provided";
		DOD="No Provided";
		cat="Not Set yet";
		Best_Wickets = 0;
		N_O_Matches = 0;
		tot_score = best_score = tot_wickets = tot_score_given = batAVG= 0.0;
		tot_over_bowled = 0.0;
	}
	void setData()
	{
		char ch;
		bool check;
		cin.ignore(1, '\n');
		do{
			check = true;
			cout << "ENTER THE NAME  [ONLY A-Z AND SPACE ARE ALLOW]:  ";
			//cin.clear();
			getline(cin,name);
			//cin >> name;
				for (int j = 0; j<name.length(); j++)
				{
					name.at(j) = toupper(name.at(j));
					if (isdigit(name[j]))
					{
						cout << "\n\t\t\tINVILAD ONLY A-Z CHARACTERS ARE ALLOW\n";
						check = false;
						break;
					}
				}
		} while (check == false);

	countryJump:							//for goto statment

		cout << "\n          Select Country From List       ";
		cout << "\n\n          1.Pakistan"
			 << "\n          2.India"
			 << "\n          3.South Africa"
			 << "\n          4.West Indies"
			 << "\n          5.Bangladesh"
			 << "\n          6.Srilanka"
			 << "\n          7.Austrailia"
			 << "\n          8.Newzealand"
			 << "\n          9.England";
		cout << "\n\nEnter Choice:";
		cin >> ch;
		switch (ch)
		{
		case '1':
			country = "Pakistan";
			break;
		case '2':
			country = "India";
			break;
		case '3':
			country = "South Africa";
			break;
		case '4':
			country = "West Indies";
			break;
		case '5':
			country = "Bangladesh";
			break;
		case '6':
			country = "Srilanka";
			break;
		case '7':
			country = "Austrailia";
			break;
		case '8':
			country = "Newzealand";
			break;
		case '9':
			country = "England";
			break;
		default:
			cout << "			\n <---INVALID INPUT--->";
			cin.clear();								//Clearing Buffer
			cout << "\nPress Any Key To Try Again:";
			cin >> ch;
			goto countryJump;							//Again Input
		}

		cout << "            Date of Birth\n";
		DOB = setDate();
		cout << "            Date of Debut \n";
		DOD = setDate();


		catJump:
		cout << "\n          1.Batsman"
			 << "\n          2.Bowler"
			 << "\n          3.Fielder"
			 << "\n          4.All-rounder";
		cout << "\n	Select Category:";
		cin >> ch;
		switch (ch)
		{
		case '1':
			cat = "Batsman";
			break;
		case '2':
			cat = "Bowler";
			break;
		case '3':
			cat = "Fielder";
			break;
		case '4':
			cat = "All-rounder";
			break;
		default:
			cout << "			\n <---INVALID INPUT--->";
			cin.clear();			//Clearing Buffer
			cout << "\nPress Any Key To Try Again:";
			cin >> ch;
			goto catJump;             //For Again Input
		}
	}
	void showData()
	{
		cout << "\n------------------------------------------------------------------------------------\n";
		cout << "\n*       NAME                    " << name
			<< "\n*       Country                 " << country
			<< "\n*       Date Of Birth           " << DOB
			<< "\n*       Date Of Debut           " << DOD
			<< "\n*       Category                " << cat
			<< "\n*       Total Matches Played    " << N_O_Matches
			<< "\n------------------------------------------------------------------------------------\n"
			<< setw(20) << "       SCORE       |" << setw(20) << "      WICKETS      |" << setw(21) << "       OVERS       |" << setw(20) << "      AVERAGE      |" << endl
			<< setw(10) << "  Total  |" << setw(10) << "   Best  |" << setw(10) << "  Total  |" << setw(10) << "   Best  |" << setw(10) << "  Total |" << setw(10) << "ScoreGiven|" << setw(20) << "  Batting Average  |\n"
			<< setw(5) << tot_score << setw(5)
			<< setw(10) << best_score
			<< setw(10)<< tot_wickets
			<< setw(10) << Best_Wickets
			<< setw(10) << tot_over_bowled
			<< setw(10) << tot_score_given
			<< setw(15) << batAVG;
		cout << "\n------------------------------------------------------------------------------------\n";
	}
	void updateData()
	{
		int tempScore;
		int tempWick, tempGscore;
		double tempOver;
		N_O_Matches++;
		cout << "ENTER SCORE:";
		cin >> tempScore;
		tot_score += tempScore;
		batAVG = tot_score / N_O_Matches;
		if (tempScore > best_score)
			best_score = tempScore;
		if (cat == "Bowler" || cat == "All-rounder")
		{
			cout << "ENTER Wickets:";
			cin >> tempWick;
			tot_wickets += tempWick;
			if (tempWick > Best_Wickets)
				Best_Wickets = tempWick;
			cout << "ENTER No of Overs:";
			cin >> tempOver;
			tot_over_bowled += tempOver;
			cout << "ENTER No of Score Given:";
			cin >> tempGscore;
			tot_score_given += tempGscore;
		}

	}
	int cal_age()
	{
		time_t t = time(NULL);
		tm* timePtr = localtime(&t);
		int now = timePtr->tm_year + 1900;
		cout << "now" << now;
		int age= now-getYear();

		cout << age;
		return age;
		
	}
	int	getYear()
	{
		string year;
		for (int i = (DOB.length() - 4); i < DOB.length(); i++)
			year += DOB[i];
		cout << "get year" << atoi(year.c_str());
		return (atoi(year.c_str()));
	}
	

};

string setDate()
{
	bool check;
	string DOB;
	string temp;
	int day,month,year;
	do{
		check = true;
		cout << "Enter Date [Format (DD/MM/YYYY) 1950 - 2018 ]\n";
		cin >> DOB;
		if (DOB.length() == 10)
		{
			for (int j = 0; j<DOB.length(); j++)
			{
				if (((j == 2) || (j == 5)) && (DOB[j] != '/'))
				{
					check = false;
					break;
				}
				if ((!(isdigit(DOB[j]))) && ((j != 2) && (j != 5)))
				{

					cout << "\n\t\t\tINVILAD ONLY Digits or '/' ARE ALLOW\n";
					check = false;
					break;
				}



				if (j == 0)
				{
					temp = DOB[j];
					temp += DOB[j + 1];
					stringstream geek(temp);
					geek >> day;
					if (day < 1 || day > 31)
					{
						cout << "\n\t\t\tINVILAD Date\n";
						check = false;
						break;
					}
				}
				if (j == 3)
				{
					temp = DOB[j];
					temp += DOB[j + 1];
					stringstream geek(temp);
					geek >> month;
					if (month < 1 || month > 12)
					{
						cout << "\n\t\t\tINVILAD Date\n";
						check = false;
						break;
					}
				}
				if (j == 6)
				{
					temp = DOB[j];
					temp += DOB[j + 1];
					temp += DOB[j + 2];
					temp += DOB[j + 3];
					stringstream geek(temp);
					geek >> year;
					if (year < 1950 || year > 2018)
					{
						cout << "\n\t\t\tINVILAD Date\n";
						check = false;
						break;
					}
				}

			}
		}
		else
		{
			cout << "\nINVILAD LENGTH";
			check = false;
		}

	} while (check == false);

	return DOB;
}

Player* search_del(Player *start, Player*& prev)
{
	Player *cur = start;
	Player *ref = NULL;
	prev = start;
	string tempNam;
	string tempDOB;
	cin.ignore(1, '\n');
	cout << "ENTER THE NAME  [ONLY A-Z AND SPACE ARE ALLOW]:  ";
	//cin.clear();
	getline(cin, tempNam);
	for (int j = 0; j<tempNam.length(); j++)
		tempNam.at(j) = toupper(tempNam.at(j));
	tempDOB=setDate();

	while (cur != NULL)
	{
		if ((cur->name == tempNam) && (cur->DOB == tempDOB))
		{
			ref = cur;
			break;
		}
		prev = cur;
		cur = cur->next;

	}
	return ref;
}
void MyDel(Player*& start)
{
	Player *cur;
	Player *ref;
	Player *prev = start;
	if (start == NULL)
		cout << "\nLIST IS EMPTY:";
	else
	{
		ref = search_del(start, prev);

		if (ref == NULL)
			cout << "Not Found in List:";
		else
		{
			cur = ref;
			if ((cur == start)){
				start = start->next;
				delete cur;
			}
			else if (cur->next == NULL){
				delete cur;
				prev->next = NULL;
			}
			else{
				prev->next = cur->next;
				delete cur;
			}
			cout << "\n:Deletion Completed:\n";
		}
	}
}

void search_Nat(Player *start)
{
	bool flag = false;
	Player *cur = start;
	char ch;
	string value;
	countryJump:							//for goto statment

	cout << "\n          Select Country From List       ";
	cout << "\n\n          1.Pakistan"
		<< "\n          2.India"
		<< "\n          3.South Africa"
		<< "\n          4.West Indies"
		<< "\n          5.Bangladesh"
		<< "\n          6.Srilanka"
		<< "\n          7.Austrailia"
		<< "\n          8.Newzealand"
		<< "\n          9.England";
	cout << "\n\nEnter Choice:";
	cin >> ch;
	switch (ch)
	{
	case '1':
		value = "Pakistan";
		break;
	case '2':
		value = "India";
		break;
	case '3':
		value = "South Africa";
		break;
	case '4':
		value = "West Indies";
		break;
	case '5':
		value = "Bangladesh";
		break;
	case '6':
		value = "Srilanka";
		break;
	case '7':
		value = "Austrailia";
		break;
	case '8':
		value = "Newzealand";
		break;
	case '9':
		value = "England";
		break;
	default:
		cout << "			\n <---INVALID INPUT--->";
		cin.clear();								//Clearing Buffer
		cout << "\nPress Any Key To Try Again:";
		cin >> ch;
		goto countryJump;							//Again Input
	}
	

	while (cur != NULL)
	{
		if (cur->country == value)
		{
			cur->showData();
			flag = true;
		}
		cur = cur->next;
	}
	if (flag == false)
		cout << "\n	No Record Found for Country " << value;
}
void search_YAGE(Player *start)
{
	int minage = 0;
	Player *cur = start;
	minage = start->cal_age();
	Player *ref = start;
	while (cur != NULL)
	{
		if (cur->cal_age()<minage)
		{
			minage = cur->cal_age();
			ref = cur;
		}
		cur = cur->next;
	}

	cout << "\n   Age == :" << minage;
	cout << "\n   DATA ";
	ref->showData();
}
void search_OAGE(Player *start)
{
	int maxage = 0;
	Player *cur = start;
	maxage = start->cal_age();
	Player *ref = start;
	while (cur != NULL)
	{
		if (cur->cal_age()>maxage)
		{
			maxage = cur->cal_age();
			ref = cur;
		}
		cur = cur->next;
	}

	cout << "\n   Age == :" << maxage;
	cout << "\n   DATA ";
	ref->showData();
}
void search_M_Match(Player *start)
{
	int max_mat = 0;
	Player *cur = start;
	max_mat = start->N_O_Matches;
	Player *ref = start;
	while (cur != NULL)
	{
		if (cur->N_O_Matches>max_mat)
		{
			max_mat = cur->N_O_Matches;
			ref = cur;
		}
		cur = cur->next;
	}

	cout << "\n   Age == :" << max_mat;
	cout << "\n   DATA ";
	ref->showData();
}
void search_M_Wick(Player *start)
{
	int max_wick = 0;
	Player *cur = start;
	max_wick = start->tot_wickets;
	Player *ref = start;
	while (cur != NULL)
	{
		if (cur->tot_wickets>max_wick)
		{
			max_wick = cur->tot_wickets;
			ref = cur;
		}
		cur = cur->next;
	}

	cout << "\n   Age == :" << max_wick;
	cout << "\n   DATA ";
	ref->showData();
}
void search_bestBatAVG(Player *start)
{
	double max_Avg = 0.0;
	Player *cur = start;
	max_Avg = start->batAVG;
	Player *ref = start;
	while (cur != NULL)
	{
		if (cur->batAVG>max_Avg)
		{
			max_Avg = cur->batAVG;
			ref = cur;
		}
		cur = cur->next;
	}

	cout << "\n   Best Batting Avg == :" << max_Avg;
	cout << "\n   Player DATA ";
	ref->showData();
}
void search_bestBatRecord(Player *start)
{
	int max_score = 0;
	Player *cur = start;
	max_score = start->best_score;
	Player *ref = start;
	while (cur != NULL)
	{
		if (cur->best_score>max_score)
		{
			max_score = cur->best_score;
			ref = cur;
		}
		cur = cur->next;
	}

	cout << "\n   Best Batting Record == :" << max_score;
	cout << "\n   Player DATA ";
	ref->showData();
}
void search_bestBolRecord(Player *start)
{
	int max_wick = 0;
	Player *cur = start;
	max_wick = start->Best_Wickets;
	Player *ref = start;
	while (cur != NULL)
	{
		if (cur->Best_Wickets>max_wick)
		{
			max_wick = cur->Best_Wickets;
			ref = cur;
		}
		cur = cur->next;
	}

	cout << "\n   Best Bowling Record == :" << max_wick;
	cout << "\n   Player DATA ";
	ref->showData();
}
void mysearch(Player *start)
{
	int ch;
	Player *ref;
	string stemp;
	if (start == NULL)
	{
		cout << "Empty List";
		return;
	}
	else
	{
		cout << "\n		1.By Nationality"
			<< "\n		2.By youngest age"
			<< "\n		3.By eldest age"
			<< "\n		4.By most no of matches"
			<< "\n		5.By best batting average"
			<< "\n		6.By best batting record"
			<< "\n		7.By best bowling record"
			<< "\n		8.By highest wicket taker"
			<< "\n\n Enter Your Choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			search_Nat(start);
			break;
		case 2:
			search_YAGE(start);
			break;
		case 3:
			search_OAGE(start);
			break;
		case 4:
			search_M_Match(start);
			break;
		case 5:
			search_bestBatAVG(start);
			break;
		case 6:
			search_bestBatRecord(start);
			break;
		case 7:
			search_bestBolRecord(start);
			break;
		case 8:
			search_M_Wick(start);
			break;
		default:
			cout << "\n		****Invalid Choice****";

		}
	}

}




int main()
{
	Player *start = NULL;
	Player *temp = NULL;
	Player *cur = NULL;
	int ch;
	do
	{
		cout << "\n------------------------------------------------------------------------------------\n";
		cout<< "\n  *                         Menu                         *"
			<< "\n  *                      1. Add New Player               *"
			<< "\n  *                      2. Update Record                *"
			<< "\n  *                      3. Search Player                *"
			<< "\n  *                      4. Delete Player                *"
		    << "\n  *                      5. Exit                         *";
		cout << "\n------------------------------------------------------------------------------------\n"
			<< "\nEnter Your Choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			temp = new Player;
			if (start == NULL)
			{
				start = temp;
				temp->next = NULL;
			}
			else
			{
				cur = start;
				while (cur->next != NULL)
				{
					cur = cur->next;
				}
				cur->next = temp;
				temp->next = NULL;
			}
			temp->setData();
			break;
		case 2:
			if (start == NULL)
				cout << "Empty List";
			else
			{
				cur = search_del(start, temp);
				if (cur == NULL)
					cout << "NOT FOUND IN LIST";
				else
					cur->updateData();
			}
			break;
		case 3:
			mysearch(start);
			break;
		case 4:
			MyDel(start);
			break;
		case 5:
			exit(-1);
			break;
		default:
			cout << "\n Invalid Input";
		}


	} while (1);
	return 0;
}

