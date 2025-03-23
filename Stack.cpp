#include "Stack.h"
#include <iostream>

Person::Person()
{
	lastName = "";
	firstName = "";
	patronymic = "";


}

Person::Person(const string ln, const string& fn, const string& pn)
{
	lastName = ln;
	firstName = fn;
	patronymic = pn;
}

void Person::Show()
{
	cout << "Фамилия - " << lastName << endl;
	cout << "Имя - " << firstName << endl;
}

void Person::ShowFormal()
{
	cout << "ФИО - " << lastName << " " <<  firstName << " " << patronymic << endl;
}
