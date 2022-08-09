// Yandex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int size_Alphabit = 27;

struct Letter {
	char letter;
	int stepen;
};

vector<long long int> digits;
Letter* let = new Letter[size_Alphabit];

void completion_letter() {
	Letter litera;
	int iterator = 0;

	for (char i = 'a'; i <= 'z'; i++)
	{
		litera.letter = i;
		litera.stepen = iterator;
		let[iterator] = litera;
		iterator++;
	}
	
	litera.letter = ' ';
	litera.stepen = iterator;
	let[iterator] = litera;
}

void parser(vector<string> buffers, int& iterator)
{
	string input_string = buffers.at(1);
	string temp;
	
	if (input_string[iterator] == ' ') iterator++;
	while (iterator < input_string.length() && input_string[iterator] != ' ')
	{
		temp += input_string[iterator];
		iterator++;
	}
	digits.push_back(atoi(temp.c_str()));
	temp.clear();
}

char sopostavlenie(int iterator)
{
	for (int i = 0; i < size_Alphabit; i++)
	{
		if (let[i].stepen == iterator) return let[i].letter;
	}
}

int main()
{
	ifstream input("input.txt");
	string buff;
	vector<string> buffers;
	
	while (!input.eof())
	{
		getline(input, buff);
		buffers.push_back(buff);
	}
	input.close();

	int i = 0;
	while (buffers.at(1)[i] != '\0')
	{
		parser(buffers, i);
	}

	int W = 0;
	completion_letter();

	int iterator = 0;
	buff.clear();
	for (int i = 0; i < atoi(buffers.at(0).c_str()); i++)
	{
		if (i > 0)
		{
			int temp = digits.at(i) - digits.at(i - 1);
			while (temp / 2 != 0)
			{
				iterator++;
				temp /= 2;
			}
			buff += sopostavlenie(iterator);
			iterator = 0;
		}
		else {	
			while (digits.at(i) / 2 != 0)
			{
				iterator++;
				digits.at(i) /= 2;
			}
			buff += sopostavlenie(iterator);
			iterator = 0;
		}
	}
	cout << buff;
	return 0;
}
