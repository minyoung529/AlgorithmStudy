#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	string max = "", min = "", number;
	int mCount = 0;
	cin >> number;

	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] == 'M') mCount++;

		else
		{
			// MAX는 5 * 10^(mCount)로 계산 
			max.push_back('5');

			if (mCount > 0)
			{
				for (int j = 0; j < mCount; j++)
				{
					// MIN은 1이나 10^(mCount)로 계산 후
					if (j == 0)
						min.push_back('1');
					else
						min.push_back('0');

					max.push_back('0');
				}

				mCount = 0;
			}

			// MIN은 M 따로 K 따로
			min.push_back('5');
		}
	}

	// 남은 M 처리
	for (int j = 0; j < mCount; j++)
	{
		// MIN은 1이나 10^(mCount)로 계산
		if (j == 0)
			min.push_back('1');
		else
			min.push_back('0');

		// MAX는 모두 1로 계산 
		max.push_back('1');
	}

	cout << max << endl << min;
}