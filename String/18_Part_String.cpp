#include<iostream>
#include<string.h>
using namespace std;

char part[1000001], total[1000001];

int main()
{
	bool isPart = false;
	cin >> total >> part;

	cout << (strstr(total, part) != nullptr);
}