#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <exception>
#define PATH "C:\\Users\\Azerty\\Desktop\\TEST.txt"
#define NEWPATH "C:\\Users\\Azerty\\Desktop\\NEWTEST.txt"

using namespace std;

class Dictionary
{
private:
	//Создание словоря где ключ - слово, значение - сколько раз оно встречается в тексте
	map<string, int> words;
public:
	Dictionary() = default; //Конструктор по умолчанию
	//Конструктор с параметрами для инициализации обьекиа при создании
	Dictionary(map<string, int> word_S) noexcept : words{ word_S } {}

	//Модификаторы и аксессоры для получения и установления словаря
	map<string, int> get_word() const noexcept { return words; }
	void set_word(map<string, int> word_S) noexcept { words = word_S; }

	//Выгрузка текста из файла
	void load();
	//Вывод всей статистики слов
	void print_all() noexcept;
	//Вывод самого популярного слова
	void print_most() noexcept;
	//Загрузка статистики в новый файл
	void save();
};

