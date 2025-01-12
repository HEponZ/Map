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
	//�������� ������� ��� ���� - �����, �������� - ������� ��� ��� ����������� � ������
	map<string, int> words;
public:
	Dictionary() = default; //����������� �� ���������
	//����������� � ����������� ��� ������������� ������� ��� ��������
	Dictionary(map<string, int> word_S) noexcept : words{ word_S } {}

	//������������ � ��������� ��� ��������� � ������������ �������
	map<string, int> get_word() const noexcept { return words; }
	void set_word(map<string, int> word_S) noexcept { words = word_S; }

	//�������� ������ �� �����
	void load();
	//����� ���� ���������� ����
	void print_all() noexcept;
	//����� ������ ����������� �����
	void print_most() noexcept;
	//�������� ���������� � ����� ����
	void save();
};

