#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

FILE* f_out, * f_in;

void medium1()

{

	/* Создать бинарный файл с информацией о продовольственных товарах, хранящихся на складе:
	- наименование товара;
	- год поступления на склад;
	- количество;
	- производитель;
	- цена.
	Определить сумму потерь при списании товаров, срок хранения которых превышает 5 лет. */

	struct Goods {
		string name;
		short year;
		short quantity;
		string manufacturer;
		int price;
	};
	short amount, now_year;
	int max = 0;
	do
	{
		cout << "Input an amount of goods: ";
		cin >> amount;
		if (amount <= 0)
			cout << "Amount of goods must be greater than 0." << endl;
	} while (amount <= 0);
	Goods *goods = new Goods[amount];
	for (int i = 0; i < amount; i++)
	{
		cout << "Input a name of the " << i + 1 << " item: ";
		cin.ignore();
		getline(cin, goods[i].name);
		do
		{
			cout << "Input a year when the " << i + 1 << " item arrived at the storage: ";
			cin >> goods[i].year;
			if (goods[i].year <= 1900 || goods[i].year > 2020)
				cout << "Error. Try again." << endl;
		} while (goods[i].year <= 1900 || goods[i].year > 2020);
		do
		{
			cout << "Input a quantity of the " << i + 1 << " item: ";
			cin >> goods[i].quantity;
			if (goods[i].quantity <= 0)
				cout << "Quantity of the item must be greater than 0." << endl;
		} while (goods[i].quantity <= 0);
		cout << "Input the manufacturer of the " << i + 1 << " item: ";
		cin.ignore();
		getline(cin, goods[i].manufacturer);
		do
		{
			cout << "Input the price per item: ";
			cin >> goods[i].price;
			if (goods[i].price < 1)
				cout << "Error. Try again." << endl;
		} while (goods[i].price < 1);
	}
	for (int i = 0; i < amount; i++)
	{
		do
		{
			cout << "Input the year that is right now: ";
			cin >> now_year;
			if (now_year < goods[i].year || now_year > 2020)
				cout << "Incorrect. Try again." << endl;
		} while (now_year < goods[i].year || now_year > 2020);
		break;
	}
	f_out = fopen("Goods.bin", "wb");
	fwrite(goods, sizeof(Goods), amount, f_out);
	fclose(f_out);
	delete[] goods;
	goods = nullptr;
	Goods* restored = new Goods[amount];
	f_in = fopen("Goods.bin", "rb");
	fread(restored, sizeof(Goods), amount, f_in);
	fclose(f_in);
	cout << endl << "Information about all goods:" << endl << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << "The " << i + 1 << " item : " << endl;
		cout << "Name: " << restored[i].name << " " << endl;
		cout << "Year of receipt: " << restored[i].year << endl;
		cout << "Quantity: " << restored[i].quantity << endl;
		cout << "Manufacturer: " << restored[i].manufacturer << endl;
		cout << "Price per one item: " << restored[i].price << "UAH" << endl;
		cout << "-------------------------------------" << endl;
	}
	for (int i = 0; i < amount; i++)
	{
		if (now_year - restored[i].year >= 5)
			max = max + restored[i].price * restored[i].quantity;
	}
	cout << endl << "Loss amount: " << max << "UAH" << endl << endl;
}

void medium2()

{

	/* Ввести некоторое количество как положительных, так и отрицательных целых чисел и записать их в бинарный файл.
	Переписать бинарный файл так, чтобы каждое отрицательное значение было увеличено на 3, а положительное – уменьшено на 3.
	Распечатать числа до и после изменения данных в файле. */

	short amount;
	do
	{
		cout << "Input an amount of numbers in file: ";
		cin >> amount;
		if (amount <= 0)
			cout << "Amount of numbers must be greater than 0" << endl;
	} while (amount <= 0);
	cout << "Input all numbers and press <Enter> :" << endl;
	short* numbers = new short[amount];
	for (int i = 0; i < amount; i++)
	{
		cin >> numbers[i];
	}
	f_out = fopen("numbers.bin", "wb");
	fwrite(numbers, sizeof(short), amount, f_out);
	fclose(f_out);
	delete[] numbers;
	numbers = nullptr;
	short* restored = new short[amount];
	f_in = fopen("Numbers.bin", "rb");
	fread(restored, sizeof(short), amount, f_in);
	fclose(f_in);
	cout << endl << "Numbers in file before they were edited:" << endl;
	for (int i = 0; i < amount; i++)
		cout << restored[i] << " ";
	for (int i = 0; i < amount; i++)
	{
		if (restored[i] < 0)
			restored[i] += 3;
		if (restored[i] > 0)
			restored[i] -= 3;
	}
	f_out = fopen("Numbers.bin", "wb");
	fwrite(restored, sizeof(short), amount, f_out);
	fclose(f_out);
	cout << endl << endl << "Numbers in file after they were edited:" << endl;
	for (int i = 0; i < amount; i++)
		cout << restored[i] << " ";
	cout << endl << endl;
	delete[] restored;
	restored = nullptr;
}

void medium3()

{

	/* Создать бинарный файл, компонентами которого является структура, содержащая следующие поля:
	- фамилия и инициалы работника предприятия;
	- год рождения;
	- образование;
	- год поступления на работу;
	- должность;
	- заработная плата. 
	Переписать бинарный файл так, чтобы увеличить размер заработной платы на 10%, если сотрудник проработал на предприятии более 10 лет. */

	struct Name {
		string surname;
		string name;
		string patronymic;
	};
	struct Worker {
		Name name;
		short birth_year;
		string education;
		string position;
		short employment_year;
		double salary;
	};
	short amount, edu_index, post_index, now_year;
	do
	{
		cout << "Input an amount of workers: ";
		cin >> amount;
		if (amount <= 0)
			cout << "Amount of numbers must be greater than 0." << endl;
	} while (amount <= 0);
	Worker* worker = new Worker[amount];
	for (int i = 0; i < amount; i++)
	{
		cout << "Input a surname, name and patronymic of the " << i + 1 << " worker: ";
		cin >> worker[i].name.surname >> worker[i].name.name >> worker[i].name.patronymic;
		do
		{
			cout << "Input the year of birth of the " << i + 1 << " worker: ";
			cin >> worker[i].birth_year;
			if (worker[i].birth_year <= 1900 || worker[i].birth_year > 2004)
				cout << "Error. Try again." << endl;
		} while (worker[i].birth_year <= 1900 || worker[i].birth_year > 2004);
		cout << endl << "Choose an education of the " << i + 1 << " worker:" << endl << "Primary (1)" << endl << "Lower Secondary (2)" << endl << "Upper secondary (3)" << endl << "Bachelor (4)" << endl << "Master (5)" << endl << "Doctoral (6)" << endl;
		do
		{
			cout << "Education: ";
			cin >> edu_index;
			switch (edu_index)
			{
			case 1:
				worker[i].education = "Primary";
				break;
			case 2:
				worker[i].education = "Lower Secondary";
				break;
			case 3:
				worker[i].education = "Upper Secondary";
				break;
			case 4:
				worker[i].education = "Bachelor";
				break;
			case 5:
				worker[i].education = "Master";
				break;
			case 6:
				worker[i].education = "Doctoral";
				break;
			default:
				cout << endl << "Incorrect. Try again." << endl << endl;
				break;
			}
		} while (edu_index < 1 || edu_index > 6);
		cout << endl << "Choose a position of the " << i + 1 << " worker in company:" << endl << "Sysadmin (1)" << endl << "QA Engineer (2)" << endl << "Junior Software Engineer (3)" << endl << "Middle Software Engineer (4)" << endl << "Senior Software Engineer (5)" << endl << "Team Lead (6)" << endl;
		do
		{
			cout << "Position: ";
			cin >> post_index;
			switch (post_index)
			{
			case 1:
				worker[i].position = "Sysadmin";
				break;
			case 2:
				worker[i].position = "QA Engineer";
				break;
			case 3:
				worker[i].position = "Junior Software Engineer";
				break;
			case 4:
				worker[i].position = "Middle Software Engineer";
				break;
			case 5:
				worker[i].position = "Senior Software Engineer";
				break;
			case 6:
				worker[i].position = "Team Lead";
				break;
			default:
				cout << endl << "Incorrect. Try again." << endl << endl;
				break;
			}
		} while (post_index < 1 || post_index > 6);
		do
		{
			cout << endl << "Input the year of employment of the " << i + 1 << " worker: ";
			cin >> worker[i].employment_year;
			if (worker[i].employment_year < worker[i].birth_year || worker[i].employment_year > 2020)
				cout << "Error. Try again." << endl;
		} while (worker[i].employment_year < worker[i].birth_year || worker[i].employment_year > 2020);
		do
		{
			cout << "Input salary of the " << i + 1 << " person (per month, in $): ";
			cin >> worker[i].salary;
			if (worker[i].salary < 400)
				cout << "Error. Try again." << endl;
		} while (worker[i].salary < 400);
		cout << endl;
	}
	for (int i = 0; i < amount; i++)
	{
		do
		{
			cout << "Input the year that is right now: ";
			cin >> now_year;
			if (now_year < worker[i].employment_year || now_year > 2020)
				cout << "Incorrect. Try again." << endl;
		} while (now_year < worker[i].employment_year || now_year > 2020);
		break;
	}
	f_out = fopen("Workers.bin", "wb");
	fwrite(worker, sizeof(Worker), amount, f_out);
	fclose(f_out);
	f_in = fopen("Workers.bin", "rb");
	fread(worker, sizeof(Worker), amount, f_in);
	fclose(f_in);
	cout << endl << "Information about workers before they were raised:" << endl << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << "The " << i + 1 << " worker: " << endl;
		cout << "Name: " << worker[i].name.surname << " " << worker[i].name.name << " " << worker[i].name.patronymic << endl;
		cout << "Year of birth: " << worker[i].birth_year << endl;
		cout << "Education: " << worker[i].education << endl;
		cout << "Position: " << worker[i].position << endl;
		cout << "Year of employment: " << worker[i].employment_year << endl;
		cout << "Salary: " << worker[i].salary << "$" << endl;
		cout << "-------------------------------------" << endl;
	}
	for (int i = 0; i < amount; i++)
	{
		if (now_year - worker[i].employment_year > 10)
			worker[i].salary = (worker[i].salary / 100) * 10 + worker[i].salary;
	}
	f_out = fopen("Workers.bin", "wb");
	fwrite(worker, sizeof(Worker), amount, f_out);
	fclose(f_out);
	f_in = fopen("Workers.bin", "rb");
	fread(worker, sizeof(Worker), amount, f_in);
	fclose(f_in);
	cout << endl << "Information about workers after they were raised:" << endl << endl;
	for (int i = 0; i < amount; i++)
	{
		cout << "The " << i + 1 << " worker: " << endl;
		cout << "Name: " << worker[i].name.surname << " " << worker[i].name.name << " " << worker[i].name.patronymic << endl;
		cout << "Year of birth: " << worker[i].birth_year << endl;
		cout << "Education: " << worker[i].education << endl;
		cout << "Position: " << worker[i].position << endl;
		cout << "Year of employment: " << worker[i].employment_year << endl;
		cout << "Salary: " << worker[i].salary << "$" << endl;
		cout << "-------------------------------------" << endl;
	}
	cout << endl;
	delete[] worker;
	worker = nullptr;
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
		cout << "1 - First task" << endl;
		cout << "2 - Second task" << endl;
		cout << "3 - Third task" << endl;
		cout << "0 - Exit" << endl;
		cout << "Input a number please : ";
		cin >> number;
		switch (number)
		{
		case 1:
			medium1();
			break;
		case 2:
			medium2();
			break;
		case 3:
			medium3();
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