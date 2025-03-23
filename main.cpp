#include <iostream>
#include "Stack.h"
#include "windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person person;
	Person person1("Мефёд ", "Иван ", "Евгеньевич ");
	person.Show();
	person.ShowFormal();
	person1.Show();
	person1.ShowFormal();
	return 0;
}