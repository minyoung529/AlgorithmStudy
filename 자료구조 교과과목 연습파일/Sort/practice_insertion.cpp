#include<iostream>
using namespace std;
int main()
{
	int a[100], n, tmp, i, j;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (i = 1; i < n; i++)
	{
		tmp = a[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (tmp < a[j])
			{
				swap(a[j + 1], a[j]);
			}

			else break;
		}

		a[j + 1] = tmp;
	}

	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
