#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <fstream>

#define pr " "
#define ll long long
#define sep "--------------------------------------------------"
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

void print_list(list<int> a)
{
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}


bool isPrime(int n)
{
	if (n > 1)
	{
		for (int i = 2; i < n; i++)
			if (n % i == 0)
				return false;
		return true;
	}
	else
		return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<int> a;
	list<int> b;
	int n;
	cout << "Shift: ";
	cin >> n;

	for (int i = 1; i <= 20; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}

	cout << "Vector algorithm:" << endl;
	print_vector(a);
	rotate(a.begin(), a.begin() + n, a.end());
	print_vector(a);
	cout << sep << endl;

	cout << "List algorithm" << endl;
	print_list(b);
	auto it = b.begin();
	advance(it, n);
	rotate(b.begin(), it, b.end());
	print_list(b);



	return 0;
}
