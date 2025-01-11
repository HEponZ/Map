#include "Dictionary.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Dictionary map;

	map.load();
	map.print_all();
	cout << "\n\n";
	map.print_most();
	cout << "\n\n";
	map.save();

	return 0;
}