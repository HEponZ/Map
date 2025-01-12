#include "Dictionary.h"

void Dictionary::load()
{
	fstream stream(PATH, ios::in); //�������� ������ ��� ��������� ������
	string new_word;
	int count;
	
	//�������� �� �������� ������
	if (!stream)
	{
		throw logic_error("���� �� ������� �������\n");
	}

	//��������� ����, ������ �� � ������� � ������� ����������
	while (!stream.eof())
	{
		stream >> new_word;
		words[new_word]++;
	}
	//��������� �����
	stream.close();
}
void Dictionary::print_all()noexcept
{
	//����� �������
	for (auto pair : words)
	{
		cout << "�����: " << pair.first << "\t���-�� ���: " << pair.second << "\n";
	}
}
void Dictionary::print_most()noexcept
{
	string most_word;
	int count = 0;

	//����������� �� �������
	for (auto pair : words)
	{
		//���� ����� ������� ���-�� ����������
		if (pair.second > count)
		{
			most_word = pair.first;
			count = pair.second;
		}
	}
	//������� ��� �����
	cout << "�������� ������������� �����: " << most_word << " ���-�� ���: " << count;
}
void Dictionary::save()
{
	//������� ����� ����� � ����� ����
	fstream stream(NEWPATH, ios::out);

	//�������� �� �������� ������
	if (!stream)
	{
		throw logic_error("���� �� ������� �������\n");
	}

	//���������� � ����� ����������
	for (auto pair : words)
	{
		stream << pair.first << "\n" << pair.second;
	}
	//��������� �����
	stream.close();
}