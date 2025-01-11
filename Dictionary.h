#pragma once
#include <iostream>
#include <map>
#include <fstream>
#define PATH "C:\\Users\\Azerty\\Desktop\\TEST.txt"
#define NEWPATH "C:\\Users\\Azerty\\Desktop\\NEWTEST.txt"

using namespace std;

class Dictionary
{
private:
	map<string, int> word;
public:
	Dictionary() = default;
	Dictionary(map<string, int> word_S) : word{ word_S } {}

	map<string, int> get_word() { return word; }
	void set_word(map<string, int> word_S) { word = word_S; }

	void load()
	{
		fstream stream(PATH, ios::in);
		string new_word;
		int count;

		if (!stream)
		{
			/*throw*/
		}

		while (!stream.eof())
		{
			stream >> new_word;
			word[new_word]++;
		}
		stream.close();
	}
	void print_all()
	{
		for (auto pair : word)
		{
			cout << "Слово: " << pair.first << "\tКол-во раз: " << pair.second << "\n";
		}
	}
	void print_most()
	{
		string most_word;
		int count = 0;

		for (auto pair : word)
		{
			if (pair.second > count)
			{
				most_word = pair.first;
				count = pair.second;
			}
		}
		cout << "Наиболее встречающееся слово: " << most_word << " Кол-во раз: " << count;
	}
	void save()
	{
		fstream stream(NEWPATH, ios::out);

		if (!stream)
		{
			/*throw*/
		}

		for (auto pair : word)
		{
			stream << pair.first << "\n" << pair.second;
		}
		stream.close();
	}
};

