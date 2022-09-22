#include<iostream>
using namespace std;

string part, total;

int main()
{
	int checkIdx = 0;
	cin >> total >> part;

	for (int i = 0; i < total.size(); i++)
	{
		if (checkIdx == part.size()) break;

		if (total[i] == part[checkIdx])
		{
			checkIdx++;
		}
		else
		{
			checkIdx = 0;

			if (total[i] == part[checkIdx])
			{
				checkIdx++;
			}
		}
	}

	cout << (checkIdx == part.size());
}