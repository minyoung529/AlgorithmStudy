#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int check[1000001] = { false, };

int main()
{
	int num;
	cin >> num;

	check[1] = 0;
	check[2] = 1;
	check[3] = 1;

	for (int i = 4; i <= num; i++)
	{
		int prev = check[i - 1];

		if (i % 6 == 0)
		{
			check[i] = min(check[i / 2], check[i / 3]) + 1;
		}
		else if (i % 2 == 0)
		{
			check[i] = min(prev, check[i / 2]) + 1;
		}
		else if (i % 3 == 0)
		{
			check[i] = min(prev, check[i / 3]) + 1;
		}
		else
		{
			check[i] = prev + 1;
		}
	}

	cout << check[num];
}