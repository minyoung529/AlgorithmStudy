#include<iostream>
using namespace std;

int len, orderCnt;
bool arr[100];

void boy(int num);
void girl(int num);

int main()
{
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}

	cin >> orderCnt;

	for (int i = 0; i < orderCnt; i++)
	{
		int gender, number;
		cin >> gender >> number;

		if (gender == 1)
		{
			boy(number - 1);
		}
		else
		{
			girl(number - 1);
		}
	}

	for (int i = 0, idx = 19; i < len; i++)
	{
		cout << arr[i] << ' ';

		if (i != 0 && i % idx == 0)
		{
			idx += 20;
			cout << '\n';
		}
	}
}

void boy(int num)
{
	for (int i = num; i < len; i += num + 1)
	{
		arr[i] = !arr[i];
	}
}

void girl(int num)
{
	int left = num, right = num;

	while (left >= 0 && right < len)
	{
		if (arr[left] == arr[right])
		{
			bool reverse = !arr[left];
			arr[left] = reverse;
			arr[right] = reverse;
		}
		else break;

		left--; right++;
	}
}