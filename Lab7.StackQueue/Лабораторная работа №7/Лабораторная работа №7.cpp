#include <iostream>
#include <windows.h>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void basic()

{

	/* Создать стек из целых чисел.
	Вычислить среднее арифметическое чётных значений элементов стека.
	Организовать просмотр данных стека. */

	stack <short> numbers;
	short amount, number, count = 0;
	double average = 0;
	do
	{
		cout << endl << "Input an amount of stack elements : ";
		cin >> amount;
		if (amount <= 0)
			cout << "Amount of stack elements must be greater than 0";
	} while (amount <= 0);
	cout << endl << "Elements of stack :" << endl;
	for (int i = 0; i < amount; i++)
	{
		number = -10 + rand() % 20;;
		numbers.push(number);
		cout << number << " ";
		if (number % 2 == 0)
		{
			average += number;
			count++;
		}
	}
	average = average / count;
	cout << endl << endl << "Average of even stack elements : " << average << endl << endl;
}

void medium()

{

	/* Создать стек строковых значений. Реализовать операции добавления (push) и удаления (pop) элемента  из  стека.
	Добавьте  в  стек  строки «Students», «of»,  «the», «group», «TE», «3»  и  распечатайте  содержимое  стека.
	Удалите  один элемент из стека, и распечатайте содержимое стека еще раз.
	Напечатайте все строки, которые состоят из двух символов из стека. */

	stack <string> text;
	vector <string> strings;
	string temp;
	short action, amount, j, count = 0;
	cout << endl << "Choose an action :" << endl << endl;
	do
	{
		cout << "1 - Add elements to stack" << endl;
		cout << "2 - Delete elements from stack" << endl;
		cout << "3 - Watch the elements of stack" << endl;
		cout << "4 - Find out how many elements are in stack" << endl;
		cout << "5 - Print all strings that are have 2 symbols" << endl;
		cout << "0 - Exit" << endl << endl;
		cout << "Action : ";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1:
			cout << "How many elements would you like to add? : ";
			do
			{
				cin >> amount;
				if (amount <= 0)
					cout << "Incorrect. Try again : ";
			} while (amount <= 0);
			cin.ignore();
			for (int i = 0; i < amount; i++)
			{
				cout << "Input the " << i + 1 << " string : ";
				getline(cin, temp);
				text.push(temp);
			}
			cout << endl << "Elements were successfully added.";
			cout << endl << endl;
			break;
		case 2:
			if (text.empty())
				cout << "There are no any elements in stack.";
			else
			{
				cout << "How many elements would you like to delete? : ";
				do
				{
					cin >> amount;
					if (amount <= 0 || amount > text.size())
						cout << "Incorrect. Try again : ";
				} while (amount <= 0 || amount > text.size());
				for (int i = 0; i < amount; i++)
					text.pop();
				cout << endl << "Elements were successfully deleted.";
			}
			cout << endl << endl;
			break;
		case 3:
			if (text.empty())
				cout << "There are no any elements in stack." << endl;
			else
			{
				j = text.size();
				strings.resize(j);
				for (int i = 0; i < j; i++)
				{
					if (!text.empty())
					{
						cout << j - i << " element of stack : " << text.top() << endl;
						strings[i] = text.top();
						text.pop();
					}
				}
				for (int i = 0; i < j; i++)
					text.push(strings[j - i - 1]);
			}
			cout << endl;
			break;
		case 4:
			cout << "There are " << text.size() << " elements in stack." << endl << endl;
			break;
		case 5:
			if (text.empty())
				cout << "There are no any elements in stack.";
			else
			{
				j = text.size();
				strings.resize(j);
				cout << "Strings with two symbols : ";
				for (int i = 0; i < j; i++)
				{
					if (!text.empty())
					{
						strings[i] = text.top();
						if (strings[i].length() == 2)
						{
							cout << text.top() << " ";
							count++;
						}
						text.pop();
					}
				}
				if (count == 0)
					cout << "none.";
				for (int i = 0; i < j; i++)
					text.push(strings[j - i - 1]);
			}
			cout << endl << endl;
			break;
		default:
			cout << "Incorrect. Try again." << endl << endl;
			break;
		case 0:
			break;
		}
	} while (action != 0);
}

void hard()

{

	/* Даны указатели P1 и P2 на начало и конец непустой очереди. Извлекать из очереди элементы,
	пока значение начального элемента очереди не станет четным, и выводить значения извлеченных элементов
	(если очередь не содержит элементов с четными значениями, то извлечь все её элементы).
	Вывести также новые адреса начала и конца очереди (для пустой очереди дважды вывести NULL).
	После извлечения элементов из очереди освобождать память, которую они занимали. */

	queue <short> q;
	vector <int> temp;
	short amount, *P1, *P2, count = 0;
	do
	{
		cout << endl << "Input an amount of elements in the queue: ";
		cin >> amount;
		if (amount <= 0)
			cout << "Amount of elements must be greater than 0";
	} while (amount <= 0);
	cout << endl << "All elements :" << endl;
	for (int i = 0; i < amount; i++)
	{
		int temp;
		temp = -10 + rand() % 20;
		q.push(temp);
		cout << temp << " ";
	}
	P1 = &q.front();
	P2 = &q.back();
	cout << endl << endl << "Old address of P1 : " << P1;
	cout << endl << "Old address of P2 : " << P2;
	cout << endl << endl << "Deleted odd elements : " << endl;
	do
	{
		if (!q.empty() && q.front() % 2 != 0)
		{
			cout << q.front() << " ";
			q.pop();
			count++;
		}
		if (!q.empty() && q.front() % 2 == 0)
			break;
	} while (!q.empty());
	if (count == 0)
		cout << "none.";
	if (q.empty())
		cout << endl << endl << "NULL NULL";
	else
	{
		cout << endl << endl << "New queue :" << endl;
		for (int i = 0; i < amount - count; i++)
		{
			temp.resize(amount - count);
			cout << q.front() << " ";
			temp[i] = q.front();
			q.pop();
		}
		for (int i = 0; i < amount - count; i++)
			q.push(temp[i]);
		P1 = &q.front();
		P2 = &q.back();
		cout << endl << endl << "New address of P1 : " << P1;
		cout << endl << "New address of P2 : " << P2;
	}
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