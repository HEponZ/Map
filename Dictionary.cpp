#include "Dictionary.h"

void Dictionary::load()
{
	fstream stream(PATH, ios::in); //Создание потока для получения текста
	string new_word;
	int count;
	
	//Проверка на открытие потока
	if (!stream)
	{
		throw logic_error("Файл не удалось открыть\n");
	}

	//Получение слов, запись их в словарь и подсчет повторений
	while (!stream.eof())
	{
		stream >> new_word;
		words[new_word]++;
	}
	//Закрываем поток
	stream.close();
}
void Dictionary::print_all()noexcept
{
	//Вывод словаря
	for (auto pair : words)
	{
		cout << "Слово: " << pair.first << "\tКол-во раз: " << pair.second << "\n";
	}
}
void Dictionary::print_most()noexcept
{
	string most_word;
	int count = 0;

	//Пробегаемся по словарю
	for (auto pair : words)
	{
		//Ищем самое большое кол-во повторений
		if (pair.second > count)
		{
			most_word = pair.first;
			count = pair.second;
		}
	}
	//Выводим это слово
	cout << "Наиболее встречающееся слово: " << most_word << " Кол-во раз: " << count;
}
void Dictionary::save()
{
	//Создаем новый поток в новый файл
	fstream stream(NEWPATH, ios::out);

	//Проверка на открытие потока
	if (!stream)
	{
		throw logic_error("Файл не удалось открыть\n");
	}

	//Записываем в поток статистику
	for (auto pair : words)
	{
		stream << pair.first << "\n" << pair.second;
	}
	//Закрываем поток
	stream.close();
}