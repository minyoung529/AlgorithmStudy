#include<iostream>
using namespace std;

int main()
{
	int len;
	int a = 0, b = 1;
	cin >> len;

	// 1 이하일 경우 
	if (len <= 1)
	{
		cout << len;
		return 0;
	}

	for (int i = 0; i < len - 1; i++)
	{
		int temp = b;
		b = a + b;
		a = temp;
	}

	cout << b;
}
