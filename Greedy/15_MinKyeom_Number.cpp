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
			// MAX�� 5 * 10^(mCount)�� ��� 
			max.push_back('5');

			if (mCount > 0)
			{
				for (int j = 0; j < mCount; j++)
				{
					// MIN�� 1�̳� 10^(mCount)�� ��� ��
					if (j == 0)
						min.push_back('1');
					else
						min.push_back('0');

					max.push_back('0');
				}

				mCount = 0;
			}

			// MIN�� M ���� K ����
			min.push_back('5');
		}
	}

	// ���� M ó��
	for (int j = 0; j < mCount; j++)
	{
		// MIN�� 1�̳� 10^(mCount)�� ���
		if (j == 0)
			min.push_back('1');
		else
			min.push_back('0');

		// MAX�� ��� 1�� ��� 
		max.push_back('1');
	}

	cout << max << endl << min;
}