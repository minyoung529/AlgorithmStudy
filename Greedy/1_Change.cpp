#include <iostream>
using namespace std;

int main()
{
	int change;
	int count = 0;
	cin >> change;

	while (change >= 2)
	{
		if (change >= 5)
		{
			if ((change - 5) % 5 != 0)
				change -= 2;
			else
				change -= 5;
		}
		else
			change -= 2;

		count++;
	}


	if (change > 0 || count == 0)
		cout << -1;
	else
		cout << count;
}
