#include<iostream>
using namespace std;

int main()
{
	while (true)
	{
		string part, total;
		int checkIdx = 0;
		cin >> part >> total;

		if (cin.eof()) break;

		for (int i = 0; i < total.size(); i++)
		{
			// �κ� ������ i��°�� ���ٸ� ���� ������ i+1���縦 �˻�
			if (total[i] == part[checkIdx])
			{
				checkIdx++;
			}
		}

		// �κ� ���ڸ� ��� üũ�ߴٸ� ����!
		(checkIdx == part.size()) ? cout << "Yes" << endl : cout << "No" << endl;
	}
}