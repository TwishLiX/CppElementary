#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

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

	/* 1. Ввести дату и выполнить ее форматирование: день с начальным нулем (01-31),
	месяц в виде полного названия (Январь – Декабрь) и год в виде двух последних цифр.
	2. Реализовать часть программного комплекса «Бухгалтерский учет», которая для введенной даты
	выдает информацию, к какому отчетному периоду (кварталу) она принадлежит,
	и сколько прошло дней от начала года до введенной даты. */

	int sum = 0;
	Date date;
	struct tm* entered;
	char formatted[80];
	time_t entered_time = time(NULL); //определение текущего календарного времени
	entered = localtime(&entered_time);
	cout << endl;
	do
	{
		cout << "Input a date (in format: DD MM YYYY): ";
		cin >> date.day >> date.month >> date.year;
	} while (!date.isCorrect());
	entered->tm_mday = date.day;
	entered->tm_mon = date.month - 1;
	entered->tm_year = date.year;
	strftime(formatted, sizeof(formatted), "%d %B %g", entered);
	cout << "Entered time: " << formatted << endl;
	if (date.month >= 1 && date.month <= 3)
		cout << "1 Quarter";
	if (date.month >= 4 && date.month <= 6)
		cout << "2 Quarter";
	if (date.month >= 7 && date.month <= 9)
		cout << "3 Quarter";
	if (date.month >= 10 && date.month <= 12)
		cout << "4 Quarter";
	for (int i = 1; i < date.month; i++)
	{
		if (i == 1)
			sum += 31;
		if (i == 2 && date.year % 4 != 0)
			sum += 28;
		if (i == 2 && date.year % 4 == 0)
			sum += 29;
		if (i == 3)
			sum += 31;
		if (i == 4)
			sum += 30;
		if (i == 5)
			sum += 31;
		if (i == 6)
			sum += 30;
		if (i == 7)
			sum += 31;
		if (i == 8)
			sum += 31;
		if (i == 9)
			sum += 30;
		if (i == 10)
			sum += 31;
		if (i == 11)
			sum += 30;
		if (i == 12)
			sum += 31;
	}
	sum = sum + date.day - 1;
	cout << endl << "There are " << sum << " days have passed since the year beginning";
	cout << endl << endl;
}

void medium()

{
	/* Написать программу ввода и обработки данных структуры для индивидуального варианта задания.
	Все указанные в заданиях даты и время должны быть представлены по шаблону: ДДММГГГГ и ЧЧ:ММ:СС соответственно.

	Поликлиника:
	- название кабинета;
	- номер кабинета;
	- ФИО врача;
	- день приема (формат: 1_Понедельник – 7_Воскресенье);
	- время начала приема;
	- время окончания.

	- Вывести информацию по всем записям с указанием длительности приема;
	- Ввести значение времени и дня недели приема; определить, принимает ли кабинет флюорографии в это время. */

	cout << endl << endl;
}

void hard()

{

	/* Написать программу записи структуры в файл (поля структуры взять из таблицы предыдущего задания в соответствии с индивидуальным вариантом).
	Организовать чтение из файла и выполнение указанных заданий.
	Все даты и время должны быть представлены по шаблону: ДДММГГГГ и ЧЧ:ММ:СС соответственно.
	
	- Подсчитать количество врачей, начинающих прием в пятницу во второй половине дня (после 12:00) и вывести сведения о них;
	- Вывести сведения о терапевте, последним заканчивающим сегодня прием;
	- Подготовить информацию обо всех сотрудниках, начинающих прием завтра в первой половине дня (до 12:00) и заканчивающих во второй (после 12:00).

	Результат предоставить в виде файла. */


	cout << endl << endl;
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
		cout << "1 - Basic level" << endl;
		cout << "2 - Medium level" << endl;
		cout << "3 - High level" << endl;
		cout << "0 - Exit" << endl;
		cout << "Input a number please: ";
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