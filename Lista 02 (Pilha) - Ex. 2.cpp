#include <iostream>
#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__
#define E 9

const int STATIC_STACK_CAPACITY = E;

struct StaticStack
{
	int count;
	char values[STATIC_STACK_CAPACITY];
};

StaticStack Create();

bool Push(StaticStack& stack, char elem);

char Pop(StaticStack& stack);

char Top(const StaticStack& stack);

int Size(const StaticStack& stack);

int Count(const StaticStack& stack);

bool IsEmpty(const StaticStack& stack);

bool Clear(StaticStack& stack);

#endif


#include <string>

using namespace std;
int main()
{
	setlocale(LC_ALL, "pt_BR");
	string sdate;
	char slash = '/';
	char reverse[E];
	cout << "Digite uma data (DD/MM/AAAA): ";
	cin >> sdate;

	StaticStack date = Create();
	for (int i = 0; i < sdate.size(); ++i)
		if (sdate[i] != slash)
			Push(date, (char)sdate[i]);

	for (int i = 0; i < E; ++i)
		reverse[i] = date.values[E - 1 - i];

	int count = 0;
	for (int i = 0; i < E; ++i)
		if (date.values[i] == reverse[i])
			count++;
	if (count == E)
		cout << "Data palíndroma.";
	else
		cout << "Data não palíndroma.";
}