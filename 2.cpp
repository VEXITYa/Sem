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

	//Vector
	cout << "Vector manually:" << endl;

	vector<int> vector_a, vector_b;

	for (int i = 1; i <= 20; i++)
	{
		vector_a.push_back(i);
		vector_b.push_back(i);
	}
	print_vector(vector_a);

	int l = 0, r = vector_a.size() - 1;
	while (l <= r)
	{
		while (isPrime(vector_a[l])) l++;
		while (!isPrime(vector_a[r])) r--;
		swap(vector_a[l], vector_a[r]);
	}

	print_vector(vector_a);
	cout << sep << endl;
	cout << "Vector algorithm:" << endl;

	print_vector(vector_b);
	partition(vector_b.begin(), vector_b.end(), isPrime);
	print_vector(vector_b);
	
	cout << sep << endl;
	cout << "List manually:" << endl;

	//List

	list<int> list_a, list_b;
	for (int i = 1; i <= 20; i++)
	{
		list_a.push_back(i);
		list_b.push_back(i);
	}

	/*print_list(list_a);
	auto list_l = list_a.begin();
	auto list_r = --list_a.end();
	while (list_l != list_r)
	{
		while (isPrime(*list_l) && list_l != list_a.end()) list_l++;
		while (!isPrime(*list_r) && list_r != list_a.begin()) list_r--;
		swap(list_l, list_r);
	}
	print_list(list_a);*/

	cout << sep << endl;
	cout << "List algorithm:" << endl;

	print_list(list_b);
	partition(list_b.begin(), list_b.end(), isPrime);
	print_list(list_b);

	return 0;
}
