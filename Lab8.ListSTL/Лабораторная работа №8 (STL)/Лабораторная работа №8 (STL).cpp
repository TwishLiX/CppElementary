#include <iostream>
#include <windows.h>
#include <forward_list>
#include <list>
#include <iterator>
#include <vector>

using std::forward_list;
using std::list;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

void basic()

{

	/* Создать линейный однонаправленный список из целых чисел.
	Удалить из списка два элемента после каждого элемента с нечетным значением. */

	forward_list<short> numbers;
	forward_list<short>::iterator pos;
	short amount;
	do
	{
		cout << endl << "Input an amount of elements in list: ";
		cin >> amount;
		if (amount <= 0)
			cout << "Amount of elements must be greater than 0.";
	} while (amount <= 0);
	vector<short> temp_array(amount);
	cout << endl << "Elements in list in the beginning:" << endl;
	for (int i = 0; i < amount; i++)
	{
		short temp;
		temp = -20 + rand() % 40;
		numbers.push_front(temp);
		cout << temp << " ";
		temp_array[i] = temp;
	}
	for (int i = 0; i < temp_array.size(); i++)
	{
		vector<short>::iterator pos1 = temp_array.begin();
		vector<short>::iterator pos2 = pos1;
		vector<short> indeces;
		short j = 0, k = 0;
		if (temp_array[i] % 2 != 0)
		{
			j++;
			indeces.resize(j);
			indeces[k++] = i;
			if (i + 3 > temp_array.size())
			{
				if (temp_array.back() % 2 != 0 && (temp_array.size() - 1) - indeces[indeces.size() - 1] < 1) //разность между последним индексом вектора и индексом последнего неудаленного элемента
					continue;
				else
				{
					temp_array.pop_back();
					break;
				}
			}
			advance(pos1, i + 1);
			advance(pos2, i + 3);
			temp_array.erase(pos1, pos2);
		}
	}
	numbers.clear();
	for (int i = 0; i < temp_array.size(); i++)
		numbers.push_front(temp_array[temp_array.size() - i - 1]);
	cout << endl << endl << "Elements in list in the end:" << endl;
	for (pos = numbers.begin(); pos != numbers.end(); pos++)
		cout << *pos << " ";
	cout << endl << endl;
}

void medium()

{

	/* Создать линейный двунаправленный список из символов.
	Удалить из списка элемент после каждого символа &. */

	list<char> characters;
	list<char>::iterator pos;
	short amount, i = 0;
	do
	{
		cout << endl << "Input an amount of characters in list: ";
		cin >> amount;
		if (amount <= 0)
			cout << "Amount of characters must be greater than 0.";
	} while (amount <= 0);
	cout << endl << "Your string in the beginning:" << endl;
	for (int i = 0; i < amount; i++)
	{
		char temp;
		temp = 35 + rand() % 15;
		characters.push_back(temp);
		cout << temp;
	}
	for (pos = characters.begin(); pos != characters.end(); pos++)
	{
		list<char>::iterator del = characters.begin();
		if (*pos == '&')
		{
			advance(del, i + 1);
			characters.erase(del);
		}
		i++;
	}
	cout << endl << endl << "Your string in the end :" << endl;
	for (pos = characters.begin(); pos != characters.end(); pos++)
		cout << *pos;
	cout << endl << endl;
}

void hard()

{

	/* Дан непустой двусвязный список, первый, последний и текущий элементы которого имеют адреса P1, P2 и P3. Также даны пять чисел.
	Описать процедуру InsertBefore(L,D), которая вставляет новый элемент со значением D перед текущим элементом списка L.
	Вставленный элемент становится текущим. С помощью этой процедуры вставить пять данных чисел
	в исходный список и вывести новые адреса его первого, последнего и текущего элементов. */

	list<short> L;
	vector<short> D(5);
	short amount, current, * P1, * P2, * P3;
	do
	{
		cout << endl << "Input an amount of elements in list: ";
		cin >> amount;
		if (amount <= 0)
			cout << "Amount of elements must be greater than 0.";
	} while (amount <= 0);
	cout << endl << "Elements in list in the beginning:" << endl;
	for (int i = 0; i < amount; i++)
	{
		short temp;
		temp = -20 + rand() % 40;
		L.push_back(temp);
		cout << temp << " ";
	}
	for (int i = 0; i < D.size(); i++)
	{
		D[i] = -20 + rand() % 40;;
	}
	do
	{
		cout << endl << endl << "Select current element (from 1 to " << amount << "): ";
		cin >> current;
		if (current <= 0 || current > amount)
			cout << "Selected element is out of range.";
	} while (current <= 0 || current > amount);
	P1 = &L.front();
	P2 = &L.back();
	list<short>::iterator curr = L.begin();
	advance(curr, current - 1);
	P3 = &(*curr);
	cout << endl << "Old address of P1 (Beginning): " << P1;
	cout << endl << "Old address of P2 (End): " << P2;
	cout << endl << "Old address of P3 (Current): " << P3;
	for (int i = 0; i < D.size(); i++)
	{
		L.insert(curr, D[i]);
		advance(curr, -1);
	}
	P1 = &L.front();
	P2 = &L.back();
	P3 = &(*curr);
	cout << endl << endl << "Elements in list in the end:" << endl;
	for (curr = L.begin(); curr != L.end(); curr++)
		cout << *curr << " ";
	cout << endl << endl << "New address of P1 (Beginning): " << P1;
	cout << endl << "New address of P2 (End): " << P2;
	cout << endl << "New address of P3 (Current): " << P3;
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