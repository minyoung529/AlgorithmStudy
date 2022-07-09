#include <iostream>
using namespace std;

int elements[15000];
int main()
{
	int elementCnt;
	int targetNumber;
	int result = 0;

	cin >> elementCnt >> targetNumber;

	for (int i = 0; i < elementCnt; ++i)
	{
		int input;
		cin >> input;
		elements[i] = input;
	}

	for (int i = 0; i < elementCnt; ++i)
	{
		for (int j = i + 1; j < elementCnt; ++j)
		{
			if (elements[i] + elements[j] == targetNumber)
				++result;
		}
	}

	cout << result;
}