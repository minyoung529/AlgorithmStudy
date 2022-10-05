#include<iostream>
#include<math.h>

using namespace std;

#define ERROR_RANGE	0.001

double GetFunc(double x);

int main()
{
	double min, max;
	cin >> min >> max;

	if (GetFunc(min) * GetFunc(max) < 0)
	{
		while (max - min > ERROR_RANGE)
		{
			float mid = (min + max) / 2;

			if (GetFunc(mid) * GetFunc(max) < 0)
			{
				min = mid;
			}
			else
			{
				max = mid;
			}
		}

		cout << min << "~" << max << endl;
		cout << "오차범위 : " << max - min;
	}
}

double GetFunc(double x)
{
	return (pow(x, 3) - 3 * x + 1);
}
