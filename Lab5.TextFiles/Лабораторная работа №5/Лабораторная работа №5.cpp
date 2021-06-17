#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>

using namespace std;

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};
struct Name {
	string surname;
	string name;
	string patronymic;
};
struct Programmer {
	Name name;
	Date birthdate;
	string gender;
	string nationality;
	string education;
	string phone_number;
	short age = 0;
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
	short action, edu_index, programmer_amount, count = 0;
	do
	{
		cout << "Input a number of people : ";
		cin >> programmer_amount;
		if (programmer_amount <= 0)
			cout << "The number of people must be greater than 0" << endl;
	} while (programmer_amount <= 0);
	vector<Programmer> programmer(programmer_amount);
	Date today;
	today.day = 22, today.month = 4, today.year = 2020;
	for (int i = 0; i < programmer.size(); i++)
	{
		cout << "Input a surname, name and patronymic of the " << i + 1 << " person : ";
		cin >> programmer[i].name.surname >> programmer[i].name.name >> programmer[i].name.patronymic;
		cout << "Input the gender of the " << i + 1 << " person : ";
		do
		{
			cin >> programmer[i].gender;
			if (programmer[i].gender != "male" && programmer[i].gender != "female")
				cout << "Input the gender of the " << i + 1 << " person (male or female) : ";
		} while (programmer[i].gender != "male" && programmer[i].gender != "female");
		do
		{
			cout << "Input a birthdate (in format: DD MM YYYY) of the " << i + 1 << " person : ";
			cin >> programmer[i].birthdate.day >> programmer[i].birthdate.month >> programmer[i].birthdate.year;
		} while (!programmer[i].birthdate.isCorrect());
		cout << "Input the nationality of the " << i + 1 << " person : ";
		cin >> programmer[i].nationality;
		cout << "Input a phone number of the " << i + 1 << " person : ";
		cin >> programmer[i].phone_number;
		cout << "Input an index of the education of the " << i + 1 << " person :" << endl << "Primary(1), Lower Secondary(2), Upper secondary(3), Bachelor(4), Master(5) or Doctoral(6)." << endl;
		do
		{
			cout << "Index : ";
			cin >> edu_index;
			switch (edu_index)
			{
			case 1:
				programmer[i].education = "Primary";
				break;
			case 2:
				programmer[i].education = "Lower Secondary";
				break;
			case 3:
				programmer[i].education = "Upper Secondary";
				break;
			case 4:
				programmer[i].education = "Bachelor";
				break;
			case 5:
				programmer[i].education = "Master";
				break;
			case 6:
				programmer[i].education = "Doctoral";
				break;
			default:
				cout << endl << "Incorrect. Try again." << endl << endl;
				break;
			}
		} while (edu_index < 1 || edu_index > 6);
	}
	cout << endl;
	for (int i = 0; i < programmer.size(); i++)
	{
		for (int j = programmer[i].birthdate.year + 1; j <= today.year; j++)
			programmer[i].age++;
		if (programmer[i].birthdate.month > today.month || programmer[i].birthdate.month == today.month && programmer[i].birthdate.day > today.day)
			programmer[i].age = programmer[i].age - 1;
	}
	ofstream write;
	write.open("Programmers.txt");
	if (write.is_open())
	{
		for (int i = 0; i < programmer.size(); i++)
		{
			write << "The " << i + 1 << " programmer : " << endl;
			write << "Name : " << programmer[i].name.surname << " " << programmer[i].name.name << " " << programmer[i].name.patronymic << endl;
			write << "Gender : " << programmer[i].gender << endl;
			write << "Birthdate : " << programmer[i].birthdate.day << "." << programmer[i].birthdate.month << "." << programmer[i].birthdate.year << " (" << programmer[i].age << " years old)" << endl;
			write << "Nationality : " << programmer[i].nationality << endl;
			write << "Education : " << programmer[i].education << endl;
			write << "Phone number : " << programmer[i].phone_number << endl;
			write << "-------------------------------------" << endl;
		}
	}
	write.close();
	write.open("Young Programmers.txt");
	write << "Information about the programmers who are less than 25 years old:" << endl << endl;
	if (write.is_open())
	{
		for (int i = 0; i < programmer.size(); i++)
		{
			if (programmer[i].age < 25)
			{
				write << "Name : " << programmer[i].name.surname << " " << programmer[i].name.name << " " << programmer[i].name.patronymic << endl;
				write << "Gender : " << programmer[i].gender << endl;
				write << "Birthdate : " << programmer[i].birthdate.day << "." << programmer[i].birthdate.month << "." << programmer[i].birthdate.year << " (" << programmer[i].age << " years old)" << endl;
				write << "Nationality : " << programmer[i].nationality << endl;
				write << "Education : " << programmer[i].education << endl;
				write << "Phone number : " << programmer[i].phone_number << endl;
				write << "-------------------------------------" << endl;
				count++;
			}
		}
		if (count == 0)
			write << "There are no programmers who are less than 25 years old.";
	}
	write.close();
	cout << "Users were successfully recorded." << endl << endl;
	cout << "What do you like to do next?" << endl;
	cout << "1 - Watch an information about all programmers" << endl;
	cout << "2 - Watch an information about programmers who are less than 25 years old" << endl;
	cout << "0 - Exit" << endl;
	string line;
	do
	{
		ifstream readFirst("Programmers.txt");
		ifstream readSecond("Young Programmers.txt");
		cout << "Choose an action : ";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1:
			if (readFirst.is_open())
			{
				while (getline(readFirst, line))
				{
					cout << line << endl;
				}
			}
			readFirst.close();
			cout << endl;
			break;
		case 2:
			if (readSecond.is_open())
			{
				while (getline(readSecond, line))
				{
					cout << line << endl;
				}
			}
			readSecond.close();
			cout << endl;
			break;
		default:
			cout << "Incorrect. Try again." << endl << endl;
			break;
		case 0:
			break;
		}
	} while (action != 0);
	cout << endl;
}

void medium()

{
	int amount, min = 0;
	cout << endl << "Given a file 'f' whose components are real numbers. Find the smallest component value with even numbers." << endl;
	do
	{
		cout << "Input an amount of numbers in file : ";
		cin >> amount;
		if (amount <= 0)
			cout << "An amount of numbers must be greater than 0" << endl;
	} while (amount <= 0);
	cout << endl;
	int* numbers = new int[amount];
	for (int i = 1; i <= amount; i++)
	{
		numbers[i] = -100 + rand() % 200;
	}
	ofstream write;
	write.open("Real Numbers.txt");
	if (write.is_open())
	{
		write << "All numbers:" << endl;
		for (int i = 1; i <= amount; i++)
		{
			write << numbers[i] << " ";
		}
		if (amount == 1)
			write << endl << endl << "There are no numbers with even indeces.";
		else
		{
			write << endl << endl << "Numbers with even indeces: " << endl;
			for (int i = 2; i <= amount; i+=2)
			{
				write << numbers[i] << " ";
				if (numbers[i] < min)
					min = numbers[i];
			}
			write << endl << endl << "Minimum of the numbers with even indeces: " << min;
		}
	}
	write.close();
	string line;
	ifstream read("Real Numbers.txt");
	if (read.is_open())
	{
		while (getline(read, line))
		{
			cout << line << endl;
		}
	}
	read.close();
	cout << endl;
}

void hard()

{
	int amount, columns, rows, count = 0;
	cout << endl << "The file contains k matrices, which have m x n dimension. For each matrix from" << endl << "the file, calculate the sum of its negative odd elements. All matrices with odd" << endl << "sums are written to another file, replacing them in the original file with unit" << endl << "matrices. Display the contents of the first and second files." << endl;
	do
	{
		cout << "Input an amount of matrices : ";
		cin >> amount;
		if (amount < 1)
			cout << "An amount of matrices must be greater than 0" << endl;
	} while (amount < 1);
	do
	{
		cout << "Input an amount of rows in matrices : ";
		cin >> rows;
		cout << "Input an amount of columns in matrices : ";
		cin >> columns;
		if (rows < 1 || columns < 1 || (rows == 1 && columns == 1))
			cout << "Incorrect. Try again." << endl;
	} while (rows < 1 || columns < 1 || (rows == 1 && columns == 1));
	vector<vector<vector<int>>>matrix(amount, vector<vector<int>>(rows, vector<int>(columns)));
	vector<int>sums(amount);
	ofstream write;
	write.open("Matrices.txt");
	if (write.is_open())
	{
		for (int k = 0; k < amount; k++)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					matrix[k][i][j] = -10 + rand() % 20;
					write << matrix[k][i][j] << "\t";
					if (matrix[k][i][j] % 2 != 0 && matrix[k][i][j] < 0)
					{
						sums[k] += matrix[k][i][j];
						count++;
					}
				}
				write << endl << endl;
			}
			write << endl << endl << endl;
		}
	}
	write.close();
	write.open("Matrices with odd sums.txt");
	if (write.is_open())
	{
		if (count == 0)
			write << "There are no matrices with odd sums." << endl << endl;
		else
		{
			for (int k = 0; k < amount; k++)
			{
				if (sums[k] % 2 != 0)
				{
					for (int i = 0; i < rows; i++)
					{
						for (int j = 0; j < columns; j++)
						{
							write << matrix[k][i][j] << "\t";
							if (i != j)
								matrix[k][i][j] = 0;
							else
								matrix[k][i][j] = 1;
						}
						write << endl << endl;
					}
					write << endl << endl << endl;
				}
			}
		}
	}
	write.close();
	ofstream rewrite("Matrices.txt");
	rewrite.write("", 0);
	rewrite.close();
	write.open("Matrices.txt");
	if (write.is_open())
	{
		for (int k = 0; k < amount; k++)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					write << matrix[k][i][j] << "\t";
				}
				write << endl << endl;
			}
			write << endl << endl << endl;
		}
		write << "Sums of negative odd matrix elements:" << endl;
		for (int k = 0; k < amount; k++)
		{
			write << "matrix[" << k + 1 << "] = " << sums[k] << ", ";
		}
	}
	write.close();
	string line;
	ifstream readFirst("Matrices.txt");
	cout << endl << "Content of the 1st file :" << endl << endl;
	if (readFirst.is_open())
	{
		while (getline(readFirst, line))
		{
			cout << line << endl;
		}
	}
	readFirst.close();
	ifstream readSecond("Matrices with odd sums.txt");
	cout << endl << "Content of the 2nd file :" << endl << endl;
	if (readSecond.is_open())
	{
		while (getline(readSecond, line))
		{
			cout << line << endl;
		}
	}
	readSecond.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	short number;
	cout << "Variant 18." << endl;
	do
	{
		cout << "What task do you like to run?" << endl;
		cout << "1 - basic level" << endl;
		cout << "2 - medium level" << endl;
		cout << "3 - high level" << endl;
		cout << "0 - exit" << endl;
		cout << "Input a number please : ";
		cin >> number;
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
		case 0:
			exit(0);
			break;
		default:
			cout << "Task doesn't exist." << endl << endl;
			break;
		}
	} while (number != 0);
	return 0;
}