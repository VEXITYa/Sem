#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

#define pr " "
#define ll long long
const double eps = 1e-5;

using namespace std;

void print_vector(vector<int> a)
{
	for (auto x : a)
	{
		cout << x << pr;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<int> a = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };
	vector<int> b = { 2, 4, 6, 8, 10, 12, 14, 16, 18 };
	vector<int> c;

	print_vector(a);
	print_vector(b);
	cout << endl;

	transform(a.begin(), a.end(), b.begin(), back_inserter(c),
		[](int a, int b) {return a + b * 2; }
	);
	/*
	transform может выполн€ть унарные операции над элементами однго контейнера и записывать в него же,
	или записывать в другой контейнер. “ак же может выполн€ть бинарные операции с элементами двух
	контейнеров, и записывать в один из них, или же в другой. ‘ункци€, выполн€ема€ над элементами
	контейнеров, должна возвращать значение и никак не измен€ть сами контейнеры.
	*/

	print_vector(a);
	print_vector(b);
	print_vector(c);

	cout << "----------------------------------" << endl;

	print_vector(a);

	for_each(a.begin(), a.end(), [](int& a) {a *= 2; });

	print_vector(a);

	/*
	for_each работает только с элементами контейнера, дл€ которого вызываетс€, функци€ должна не
	возвращать значение, а измен€ть элемент самого контейнера.
	*/

	return 0;
}
