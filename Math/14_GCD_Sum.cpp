#include<iostream>
#include<vector>
using namespace std;

int GetGCD(int curIndex, int nextIndex, vector<int> arr, int sum = 0);

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		vector<int> arr;
		long long answer = 0;
		int count;
		cin >> count;

		for (int j = 0; j < count; j++)
		{
			int input;
			cin >> input;
			arr.push_back(input);
		}

		for (int j = 0; j < count - 1; j++)
			answer += GetGCD(j, j + 1, arr);

		cout << answer << '\n';
	}
}

int GetGCD(int curIndex, int nextIndex, vector<int> arr, int sum)
{
	if (nextIndex >= arr.size())
	{
		return 0;
	}

	int a = arr[curIndex];
	int b = arr[nextIndex];

	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a + GetGCD(curIndex, nextIndex + 1, arr, a);
}