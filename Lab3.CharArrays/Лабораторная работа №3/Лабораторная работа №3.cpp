#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void basic()

{
	int i = 0, j, count, length;
	cout << endl << "From the given character string, select those characters that occur in it only once, in the order in which they occur in the text." << endl;
	do
	{
		cout << "Input an amount of characters in your string : ";
		cin >> length;
		if (length < 2)
			cout << "String length is too short" << endl;
	} while (length < 2);
	char* string = new char[length];
	cout << "Input your string :" << endl;
	cin.ignore();
	cin.getline(string, length);
	cout << "Characters that occur only once : ";
	while (string[i] != '\0')
	{
		j = count = 0;
		while (string[j] != '\0')
		{
			if (string[i] == string[j]) count++;
			j++;
		}
		if (count == 1 && string[i] != ' ') cout << string[i] << " ";
		i++;
	}
	cout << endl << endl;
}

void medium()

{
	char string[11];
	cout << endl << "Enter a character array. Determine the most common symbol and the number of its repetitions." << endl;
	cout << "Input a string: " << endl;
	cin.ignore();
	cin.getline(string, 11);
	short max = 0;
	const int size = 128;
	int characters[size] = { 0 };
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (++characters[string[i]] > max)
			max = characters[string[i]];
	}
	cout << endl << "Result:" << endl;
	for (int i = 0; i < 128; i++)
	{
		if (characters[i] == max)
			cout << char(i) << " - " << max << " times." << endl;
	}
	cout << endl;
}

void hard()

{
	int count = 0, length;
	cout << endl << "Given an array of characters containing words separated by a semicolon(;). The set ends with a colon(:). Determine how many words in it end with the letter 'a'.";
	do
	{
		cout << "Input an amount of characters in your string : ";
		cin >> length;
		if (length < 2)
			cout << "String length is too short" << endl;
	} while (length < 2);
	char* string = new char[length];
	char colon[] = ":";
	cout << "Input a string separating the words with ';'. To complete the entry, input ':'  and press 'Enter'." << endl;
	cout << "Text : ";
	cin.ignore();
	cin.getline(string, length, ':');
	strcat(string, colon);
	for (int i = 0; string[i] != '\0'; i++)
	{
		if ((string[i] == 'a' && string[i + 1] == ';') || (string[i] == 'a' && string[i + 1] == ':'))
			count++;
	}
	cout << "The letter 'a' is at the end of the word " << count << " times.";
	cout << endl << endl;
}

int main()
{
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
