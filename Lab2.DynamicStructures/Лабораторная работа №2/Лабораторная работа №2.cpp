#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};
struct Name {
	char surname[35];
	char name[35];
	char patronymic[35];
};
struct Address {
	long postcode;
	string country;
	string region;
	string district;
	string city;
	string street;
	unsigned short house;
	unsigned short flat;
};
struct Person {
	Name name;
	Date date;
	string gender;
	string nationality;
	short height;
	short weight;
	long long phone_number;
	short age = 0;
	Address address;
};
short people_amount;
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

void sort(vector<Person>& person)

{
	Person* sort = new Person[people_amount];
	for (int i = 0; i <= person.size(); i++)
	{
		for (int j = person.size() - 1; j > i; j--)
		{
			if (strcmp(person[j].name.surname, person[j - 1].name.surname) < 0)
			{
				sort[0] = person[j];
				person[j] = person[j - 1];
				person[j - 1] = sort[0];
			}
		}
	}
	delete[] sort;
}

void view(vector<Person>& person)

{
	cout << endl << "Information about people in alphabetical order : " << endl << endl;
	for (int i = 0; i < person.size(); i++)
	{
		cout << "The " << i + 1 << " person : " << endl;
		cout << "Name : " << person[i].name.surname << " " << person[i].name.name << " " << person[i].name.patronymic << endl;
		cout << "Gender : " << person[i].gender << endl;
		cout << "Birthdate : " << person[i].date.day << "." << person[i].date.month << "." << person[i].date.year << " (" << person[i].age << " years old)" << endl;
		cout << "Nationality : " << person[i].nationality << endl;
		cout << "Height : " << person[i].height << endl;
		cout << "Weight : " << person[i].weight << endl;
		cout << "Phone number : " << person[i].phone_number << endl;
		cout << "Address : " << person[i].address.country << ", " << person[i].address.region << ", " << person[i].address.city << ", " << person[i].address.district << " district, " << person[i].address.street << " street, house : " << person[i].address.house << ", flat : " << person[i].address.flat << ", postcode : " << person[i].address.postcode << endl << endl;
	}
}

void search(vector<Person>& person)

{
	string gender_search;
	short min_age = 0;
	short max_age = 0;
	unsigned short found_counter = 0;
	cout << endl << "Input a gender and age range of people you would like to find." << endl;
	cout << "Input the gender : ";
	do
	{
		cin >> gender_search;
		if (gender_search != "male" && gender_search != "female")
			cout << "Input the gender (male or female) : ";
	} while (gender_search != "male" && gender_search != "female");
	do
	{
		cout << "Input a minimum age : ";
		cin >> min_age;
		if (min_age < 0)
			cout << "Error" << endl;
	} while (min_age < 0);
	do
	{
		cout << "Input a maximum age : ";
		cin >> max_age;
		if (max_age < 0 || max_age < min_age)
			cout << "Error" << endl;
	} while (max_age < 0 || max_age < min_age);
	cout << endl;
	sort(person);
	for (int i = 0; i < person.size(); i++)
	{
		if (person[i].age >= min_age && person[i].age <= max_age && gender_search == person[i].gender)
		{
			cout << "Name : " << person[i].name.surname << " " << person[i].name.name << " " << person[i].name.patronymic << endl;
			cout << "Gender : " << person[i].gender << endl;
			cout << "Birthdate : " << person[i].date.day << "." << person[i].date.month << "." << person[i].date.year << " (" << person[i].age << " years old)" << endl;
			cout << "Nationality : " << person[i].nationality << endl;
			cout << "Height : " << person[i].height << endl;
			cout << "Weight : " << person[i].weight << endl;
			cout << "Phone number : " << person[i].phone_number << endl;
			cout << "Address : " << person[i].address.country << ", " << person[i].address.region << ", " << person[i].address.city << ", " << person[i].address.district << " district, " << person[i].address.street << " street, house : " << person[i].address.house << ", flat : " << person[i].address.flat << ", postcode : " << person[i].address.postcode << endl << endl;
			found_counter++;
		}
	}
	if (found_counter == 0)
		cout << "People with these parameters aren't registered" << endl << endl;
}

void add(vector<Person>& person, Date today)

{
	short quantity;
	cout << endl;
	do
	{
		cout << "Input a quantity of people you would like to add : ";
		cin >> quantity;
		if (quantity <= 0)
			cout << "Quantity must be greater than 0" << endl;
	} while (quantity <= 0);
	people_amount += quantity;
	person.resize(people_amount);
	for (int i = people_amount - quantity; i < person.size(); i++)
	{
		cout << "Input a surname, name and patronymic of the " << i + 1 << " person : ";
		cin >> person[i].name.surname >> person[i].name.name >> person[i].name.patronymic;
		cout << "Input the gender of the " << i + 1 << " person : ";
		do
		{
			cin >> person[i].gender;
			if (person[i].gender != "male" && person[i].gender != "female")
				cout << "Input the gender of the " << i + 1 << " person (male or female) : ";
		} while (person[i].gender != "male" && person[i].gender != "female");
		do
		{
			cout << "Input a birthdate (in format: DD MM YYYY) of the " << i + 1 << " person : ";
			cin >> person[i].date.day >> person[i].date.month >> person[i].date.year;
		} while (!person[i].date.isCorrect());
		cout << "Input the nationality of the " << i + 1 << " person : ";
		cin >> person[i].nationality;
		do
		{
			cout << "Input a height of the " << i + 1 << " person (in cm) : ";
			cin >> person[i].height;
			cout << "Input a weight of the " << i + 1 << " person (in kg) : ";
			cin >> person[i].weight;
			cout << "Input a phone number of the " << i + 1 << " person : ";
			cin >> person[i].phone_number;
			if (person[i].height < 1 || person[i].weight < 1 || person[i].phone_number < 1)
				cout << "Error" << endl;
		} while (person[i].height < 1 || person[i].weight < 1 || person[i].phone_number < 1);
		cout << "Input an address of the " << i + 1 << " person : " << endl;
		cout << "Country : ";
		cin.ignore();
		getline(cin, person[i].address.country);
		cout << "Region : ";
		getline(cin, person[i].address.region);
		cout << "City : ";
		getline(cin, person[i].address.city);
		cout << "District : ";
		getline(cin, person[i].address.district);
		cout << "Street : ";
		getline(cin, person[i].address.street);
		cout << "House : ";
		cin >> person[i].address.house;
		cout << "Flat : ";
		cin >> person[i].address.flat;
		cout << "Postcode : ";
		cin >> person[i].address.postcode;
	}
	for (int i = people_amount - quantity; i < person.size(); i++)
	{
		for (int j = person[i].date.year + 1; j <= today.year; j++)
			person[i].age++;
		if (person[i].date.month > today.month || person[i].date.month == today.month && person[i].date.day > today.day)
			person[i].age = person[i].age - 1;
	}
	cout << endl << "New people were successfully added." << endl << endl;
}

void choise(vector<Person>& person, Date today)

{
	short action;
	do
	{
		cout << "What do you like to do?" << endl;
		cout << "1 - view an information about the people in alphabetical order" << endl;
		cout << "2 - find people by gender and age" << endl;
		cout << "3 - add an information about new people" << endl;
		cout << "0 - exit" << endl;
		cout << "Please input a number : ";
		cin >> action;
		switch (action)
		{
		case 1:
			sort(person);
			view(person);
			break;
		case 2:
			search(person);
			break;
		case 3:
			add(person, today);
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Error" << endl << endl;
			break;
		}
	} while (action != 0);
}

void input()

{
	do
	{
		cout << "Input a number of people : ";
		cin >> people_amount;
		if (people_amount <= 0)
			cout << "The number of people must be greater than 0" << endl;
	} while (people_amount <= 0);
	vector<Person> person(people_amount);
	Date today;
	today.day = 20, today.month = 3, today.year = 2020;
	for (int i = 0; i < person.size(); i++)
	{
		cout << "Input a surname, name and patronymic of the " << i + 1 << " person : ";
		cin >> person[i].name.surname >> person[i].name.name >> person[i].name.patronymic;
		cout << "Input the gender of the " << i + 1 << " person : ";
		do
		{
			cin >> person[i].gender;
			if (person[i].gender != "male" && person[i].gender != "female")
				cout << "Input the gender of the " << i + 1 << " person (male or female) : ";
		} while (person[i].gender != "male" && person[i].gender != "female");
		do
		{
			cout << "Input a birthdate (in format: DD MM YYYY) of the " << i + 1 << " person : ";
			cin >> person[i].date.day >> person[i].date.month >> person[i].date.year;
		} while (!person[i].date.isCorrect());
		cout << "Input the nationality of the " << i + 1 << " person : ";
		cin >> person[i].nationality;
		do
		{
			cout << "Input a height of the " << i + 1 << " person (in cm) : ";
			cin >> person[i].height;
			cout << "Input a weight of the " << i + 1 << " person (in kg) : ";
			cin >> person[i].weight;
			cout << "Input a phone number of the " << i + 1 << " person : ";
			cin >> person[i].phone_number;
			if (person[i].height < 1 || person[i].weight < 1 || person[i].phone_number < 1)
				cout << "Error" << endl;
		} while (person[i].height < 1 || person[i].weight < 1 || person[i].phone_number < 1);
		cout << "Input an address of the " << i + 1 << " person : " << endl;
		cout << "Country : ";
		cin.ignore();
		getline(cin, person[i].address.country);
		cout << "Region : ";
		getline(cin, person[i].address.region);
		cout << "City : ";
		getline(cin, person[i].address.city);
		cout << "District : ";
		getline(cin, person[i].address.district);
		cout << "Street : ";
		getline(cin, person[i].address.street);
		cout << "House : ";
		cin >> person[i].address.house;
		cout << "Flat : ";
		cin >> person[i].address.flat;
		cout << "Postcode : ";
		cin >> person[i].address.postcode;
	}
	cout << endl;
	for (int i = 0; i < person.size(); i++)
	{
		for (int j = person[i].date.year + 1; j <= today.year; j++)
			person[i].age++;
		if (person[i].date.month > today.month || person[i].date.month == today.month && person[i].date.day > today.day)
			person[i].age = person[i].age - 1;
	}
	choise(person, today);
}

int main()
{
	input();
	return 0;
}
