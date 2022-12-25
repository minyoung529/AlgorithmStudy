#include<iostream>
using namespace std;

int arr[300][300];
int arr2[300][300];

int main()
{
	int n, result = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr2[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				// c[i][j] = a[i][N] * b[N][j]
				if (arr[i][k] && arr2[k][j])
				{
					result++;
					break;
				}
			}
		}
	}

	cout << result;
}