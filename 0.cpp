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

void print_train(stack<char> a)
{
	stack<char> tmp;
	while (!a.empty())
	{
		tmp.push(a.top());
		a.pop();
	}
	while (!tmp.empty())
	{
		cout << tmp.top() << pr;
		tmp.pop();
	}
	cout << endl;
}

void print_stack(stack<char> a)
{
	while (!a.empty())
	{
		cout << a.top() << pr;
		a.pop();
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string s;
	int n;
	stack<char> train, first, second;
	cin >> s;
	cin >> n;
	vector<pair<char, int>> requests(n);

	for (int i = 0; i < s.length(); i++)
	{
		train.push(s[i]);
	}

	for (int i = 0; i < n; i++)
	{
		char letter;
		int num;
		cin >> letter >> num;
		requests[i] = make_pair(letter, num);
	}

	for (auto request : requests)
	{

		int cnt = 0;
		char letter = train.top();
		while (letter != request.first)
		{
			if (request.second == 1)
				second.push(letter);
			else
				first.push(letter);
			train.pop();
			cnt++;
			letter = train.top();
		}

		if (request.second == 1)
			first.push(train.top());
		else
			second.push(train.top());
		
		train.pop();
		for (int i = 0; i < cnt; i++)
		{
			if (request.second == 1)
			{
				train.push(second.top());
				second.pop();
			}
			else
			{
				train.push(first.top());
				first.pop();
			}
		}
		cout << "Поезд: ";
		print_train(train);
		cout << "Первый тупик: ";
		print_stack(first);
		cout << "Второй тупик: ";
		print_stack(second);
	}

	
	return 0;
}
