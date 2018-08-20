#include"Declaration.h"
#include<iostream>


DateType::DateType()
{
	day = NULL;
	month = NULL;
	year = NULL;
}

bool DateType::operator!=(DateType d2)
{
	if ((day != d2.day) && (month != d2.month) && (year != d2.month))
		return true;
	else
		return false;
};

bool DateType::operator>(DateType d2)
{
	if (year > d2.year)
		return true;
	else if (year == d2.year && month > d2.month)
		return true;
	else if (year == d2.year && month == d2.month && day > d2.day)
		return true;
	else
		return false;
}

bool DateType::operator<(DateType d2)
{
	if (year < d2.year)
		return true;
	else if (year == d2.year && month < d2.month)
		return true;
	else if (year == d2.year && month == d2.month && day < d2.day)
		return true;
	else
		return false;
}


void DateType::set()
{
	do
	{
		cout << "Enter Day:";
		cin >> day;
		if (day >= 1 && day <= 31)
			break;
	} while (1);
	do
	{
		cout << "Enter Month:";
		cin >> month;

		if (month >= 1 && month <= 12)
			break;
	} while (1);
	do
	{
		cout << "Enter Year:";
		cin >> year;
		if (year >= 1900 && year <= 2025)
			break;
	} while (1);
}

string DateType::disp()
{
	string date =""+to_string(day)+":"+to_string(month)+":"+to_string(year);
	return date;
}

int DateType::getDay()
{
	return day;
}

int DateType::getMon()
{
	return month;
}

int DateType::getYear()
{
	return year;
}