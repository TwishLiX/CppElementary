#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void basic()

{
	string text;
	int count = 0;
	cout << endl << "For a given string, determine whether at least one Russian letter is included in it." << endl << "Text: ";
	cin.ignore();
	getline(cin, text);
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] >= 'а' && text[i] <= 'я' || text[i] >= 'А' && text[i] <= 'Я' || text[i] == 'ё' || text[i] == 'Ё')
			count++;
	}
	cout << "Russian letters occur in a string " << count << " times.";
	cout << endl << endl;
}

void medium()

{
	string text, temp;
	cout << endl << "In a given line, in front of each capital Latin letter, put a dot and space." << endl << "Text: ";
	cin.ignore();
	getline(cin, text);
	for (int i = 0; i < text.length(); i++)
	{
		if (i > 0 && isupper(text[i]))
		{
			temp += ". ";
			temp += text[i];
		}
		else
			temp += text[i];
	}
	text = temp;
	cout << "Result: " << text;
	cout << endl << endl;
}

void hard()

{
	string text, temp;
	cout << endl << "In the given line, arrange in the reverse order all the words. Word separators are spaces." << endl << "Text: ";
	cin.ignore();
	getline(cin, text);
	text.insert(0, " ");
	int start = text.length();
	for (int i = start; i >= 0; i--)
	{
		if (text[i] == ' ')
		{
			temp += text.substr(i + 1, start - i) + ' ';
			start = i - 1;
		}
	}
	text = temp;
	cout << "Result: " << text;
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