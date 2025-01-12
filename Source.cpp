#include "Dictionary.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Dictionary map;

	try
	{
		map.load();
		map.print_all();
		cout << "\n\n";
		map.print_most();
		cout << "\n\n";
		map.save();
	}
	catch (const logic_error& exc)
	{
		cout << exc.what();
	}

	return 0;
}