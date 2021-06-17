#include <iostream>
#include <string>

using namespace std;

int first()

{
	int number;
	cout << "Variant 18." << endl;
	cout << "Please enter a number" << endl;
	cout << "(1 - basic level, 2 - medium level, 3 - hard level, 4 - exit) : ";
	cin >> number;
	cout << endl;
	return number;
}

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day >= 1) && (day <= 31) && (year < 2021))
			result = true;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day > 0) && (day <= 30) && (year < 2021))
			result = true;
		break;
	}
	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day > 0) && (day <= 28) && (year < 2021))
				result = true;
		}
		else
		{
			if ((day > 0) && (day <= 29) && (year < 2021))
				result = true;
		}
		break;
	}

	default:
		result = false;
	}
	return result;
}

void basic()

{
	struct Goods {
		string name;
		int quantity;
		int price;
		string manufacturer;
		Date release;
	};
	const int amount = 3;
	Goods product[amount];
	double average_cost = 0;
	cout << "Determine the average cost of goods and goods with minimum cost." << endl << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << "Input a name of " << i + 1 << " product : ";
		cin.ignore();
		getline(cin, product[i].name);
		cout << "Input a quantity of " << i + 1 << " product : ";
		cin >> product[i].quantity;
		cout << "Input a price of " << i + 1 << " product (in $) : ";
		cin >> product[i].price;
		average_cost += product[i].price;
		cout << "Input a manufacturer of " << i + 1 << " product : ";
		cin.ignore();
		getline(cin, product[i].manufacturer);
		do
		{
			cout << "Input a production date (in format: DD MM YYYY) of " << i + 1 << " product : ";
			cin >> product[i].release.day >> product[i].release.month >> product[i].release.year;
		} while (!product[i].release.isCorrect());
	}
	cout << endl << "Average cost of goods : " << average_cost / double(amount) << endl;
	int min_cost_good = product[0].price, imin = 0;
	for (int i = 0; i < amount; i++)
	{
		if (product[i].price < min_cost_good)
		{
			min_cost_good = product[i].price;
			imin = i;
		}
	}
	cout << endl << "Information about a product with minimum cost : " << endl;
	cout << "Name : " << product[imin].name << endl;
	cout << "Quantity : " << product[imin].quantity << endl;
	cout << "Price : " << product[imin].price << "$" << endl;
	cout << "Production date : " << product[imin].release.day << "." << product[imin].release.month << "." << product[imin].release.year << endl;
	cout << "Manufacturer : " << product[imin].manufacturer << endl;
	cout << endl;
}

void medium()

{
	struct Goods {
		string name;
		int price;
		Date manufacture;
		int shelflife;
		int quantity;
		string manufacturer;
	};
	int shelflife_count = 0;
	const int amount = 3;
	Goods product[amount];
	cout << "Display information about products whose shelf life is less than 20 days. Determine the number of expired goods." << endl << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << "Input a name of " << i + 1 << " product : ";
		cin.ignore();
		getline(cin, product[i].name);
		cout << "Input a price of " << i + 1 << " product (in $) : ";
		cin >> product[i].price;
		do
		{
			cout << "Input a production date (in format: DD MM YYYY) of " << i + 1 << " product : ";
			cin >> product[i].manufacture.day >> product[i].manufacture.month >> product[i].manufacture.year;
		} while (!product[i].manufacture.isCorrect());
		cout << "Input an expiration date (in days) of " << i + 1 << " product : ";
		cin >> product[i].shelflife;
		if (product[i].shelflife < 20)
			shelflife_count++;
		cout << "Input a quantity of " << i + 1 << " product : ";
		cin >> product[i].quantity;
		cout << "Input a manufacturer of " << i + 1 << " product : ";
		cin.ignore();
		getline(cin, product[i].manufacturer);
	}
	cout << endl;
	if (shelflife_count == 0)
	{
		cout << "There are no goods which have less than 20 day expiration date" << endl << endl;
	}
	else
	{
		cout << "Information about goods which have less than 20 day expiration date :" << endl << endl;
		for (int i = 0; i < amount; i++)
		{
			if (product[i].shelflife < 20)
			{
				cout << "Name : " << product[i].name << endl;
				cout << "Price : " << product[i].price << "$" << endl;
				cout << "Production date : " << product[i].manufacture.day << "." << product[i].manufacture.month << "." << product[i].manufacture.year << endl;
				cout << "Expiration date : " << product[i].shelflife << " day(s)" << endl;
				cout << "Quantity : " << product[i].quantity << endl;
				cout << "Manufacturer : " << product[i].manufacturer << endl << endl;
			}
		}
	}
	Date today;
	do
	{
	cout << "Enter today's date (in format: DD MM YYYY) : ";
	cin >> today.day >> today.month >> today.year;
	} while (!today.isCorrect());
	long todaydate_in_days = 0;
	for (int i = 0; i <= today.year; i++)
	{
		if (i % 4 == 0)
			todaydate_in_days += 366;
		else
			todaydate_in_days += 365;
	}
	for (int i = 1; i <= today.month; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			todaydate_in_days += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			todaydate_in_days += 30;
		else if (i == 2)
			if (today.year % 4 == 0)
				todaydate_in_days += 29;
			else
				todaydate_in_days += 28;
	}
	todaydate_in_days += today.day;

	long manufacturedate_in_days[amount];
	int result[amount];
	int overduecount = 0;
	for (int i = 0; i < amount; i++)
	{
		manufacturedate_in_days[i] = 0;
		result[i] = 0;
		for (int j = 0; j <= product[i].manufacture.year; j++)
		{
			if (j % 4 == 0)
				manufacturedate_in_days[i] += 366;
			else
				manufacturedate_in_days[i] += 365;
		}
		for (int j = 1; j <= product[i].manufacture.month; j++)
		{
			if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
				manufacturedate_in_days[i] += 31;
			else if (j == 4 || j == 6 || j == 9 || j == 11)
				manufacturedate_in_days[i] += 30;
			else if (j == 2)
				if (product[i].manufacture.year % 4 == 0)
					manufacturedate_in_days[i] += 29;
				else
					manufacturedate_in_days[i] += 28;
		}
		manufacturedate_in_days[i] += product[i].manufacture.day;
		result[i] = todaydate_in_days - manufacturedate_in_days[i];
	}
	for (int i = 0; i < amount; i++)
	{
		if (result[i] > product[i].shelflife)
			overduecount++;
	}
	cout << "Amount of expired goods : " << overduecount;
	cout << endl << endl;
}

void hard()

{
	struct Name {
		string surname;
		char name[30];
		char patronymic[30];
	};
	struct NOTE {
		Name NAME;
		long long TELE;
		Date DATE;
	};
	const int amount = 2;
	NOTE BLOCKNOTE[amount];
	NOTE sort[amount];
	for (int i = 0; i < amount; i++)
	{
		cout << "Input a surname and initials of the " << i + 1 << " user : ";
		cin >> BLOCKNOTE[i].NAME.surname >> BLOCKNOTE[i].NAME.name >> BLOCKNOTE[i].NAME.patronymic;
		cout << "Input a phone number of the " << i + 1 << " user : ";
		cin >> BLOCKNOTE[i].TELE;
		do
		{
			cout << "Input a birthdate (in format: DD MM YYYY) of the " << i + 1 << " user : ";
			cin >> BLOCKNOTE[i].DATE.day >> BLOCKNOTE[i].DATE.month >> BLOCKNOTE[i].DATE.year;
		} while (!BLOCKNOTE[i].DATE.isCorrect());
	}
	for (int i = 0; i < amount - 1; i++)
	{
		for (int j = i + 1; j < amount; j++)
		{
			if (BLOCKNOTE[i].DATE.year > BLOCKNOTE[j].DATE.year || BLOCKNOTE[i].DATE.year == BLOCKNOTE[j].DATE.year && BLOCKNOTE[i].DATE.month > BLOCKNOTE[j].DATE.month || BLOCKNOTE[i].DATE.year == BLOCKNOTE[j].DATE.year && BLOCKNOTE[i].DATE.month == BLOCKNOTE[j].DATE.month && BLOCKNOTE[i].DATE.day > BLOCKNOTE[j].DATE.day)
			{
				sort[1] = BLOCKNOTE[i];
				BLOCKNOTE[i] = BLOCKNOTE[j];
				BLOCKNOTE[j] = sort[1];
			}
		}
	}
	cout << endl << "Users in ascending order of their birhdate :" << endl << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << "Name : " << BLOCKNOTE[i].NAME.surname << " " << BLOCKNOTE[i].NAME.name << " " << BLOCKNOTE[i].NAME.patronymic << endl;
		cout << "A phone number : " << BLOCKNOTE[i].TELE << endl;
		cout << "Birthdate : " << BLOCKNOTE[i].DATE.day << "." << BLOCKNOTE[i].DATE.month << "." << BLOCKNOTE[i].DATE.year << endl << endl;
	}
	long long user_search = 0;
	int user_count = 0;
	cout << "Input a phone number of the person you would like information about : ";
	cin >> user_search;
	cout << endl;
	for (int i = 0; i < amount; i++)
	{
		if (user_search == BLOCKNOTE[i].TELE)
		{
			cout << "Name : " << BLOCKNOTE[i].NAME.surname << " " << BLOCKNOTE[i].NAME.name << " " << BLOCKNOTE[i].NAME.patronymic << endl;
			cout << "A phone number : " << BLOCKNOTE[i].TELE << endl;
			cout << "Birthdate : " << BLOCKNOTE[i].DATE.day << "." << BLOCKNOTE[i].DATE.month << "." << BLOCKNOTE[i].DATE.year << endl << endl;
			user_count++;
		}
	}
	if (user_count == 0)
		cout << "A person with this number isn't registered" << endl;
	cout << endl;
}

int main()
{
	int number;
	do
	{
		number = first();
		switch (number)
		{
		case 1:
			basic();
			break;
		case 2:
			medium();
			break;
		case 3:
			hard();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Task doesn't exist" << endl << endl;
			break;
		}
	} while (number != 4);
	return 0;
}
