#include<iostream>
#include<string>
using namespace std;

int main()
{
	int len;
	cin >> len;
	cin.ignore();

	while (len--)
	{
		string input;
		getline(cin, input);
		int max = 0, maxCount = 0, maxIndex, alphabets[26] = { 0, };
		
		// �Է� �ޱ�
		for (int j = 0; j < input.size(); j++)
		{
			if (isalpha(input[j]))
			{
				alphabets[input[j] - 'a']++;
			}
		}

		// max�� ����
		for (int j = 0; j < 26; j++)
		{
			if (max < alphabets[j])
			{
				max = alphabets[j];
				maxIndex = j;
			}
		}

		// �ٸ� max���� �ִ��� Ž��
		for (int j = 0; j < 26; j++)
		{
			if (max == alphabets[j])
				maxCount++;
		}

		if (maxCount == 1)
			cout << (char)('a' + maxIndex) << endl;
		else
			cout << "?" << endl;
	}
}