#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[31], input;
vector<int> vec;

int main()
{
	for (int i = 0; i < 28; i++)
	{
		cin >> input;
		arr[input]++;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (arr[i] == 0)
			vec.push_back(i);
	}

	sort(vec.begin(), vec.end());

	cout << vec[0] << '\n' << vec[1];
}