#include<iostream>
using namespace std;

int main()
{
	int len, answer = 0;
	int alphabets[26] = { 0, };
	cin >> len;
	answer = len;

	while (len--)
	{
		string input;
		cin >> input;

		// �ʱ�ȭ
		for (int i = 0; i < 26; i++)
			alphabets[i] = -1;

		for (int i = 0; i < input.size(); i++)
		{
			int alpha = input[i] - 'a';

			// ó�� ���� ���� �ƴϰ�
			// ���� �ֱٿ� �ִ� �ڸ��� ���� 1 �̻��̶��
			// �׷��� �ƴ� ��!
			if (alphabets[alpha] != -1 && i - alphabets[alpha] > 1)
			{
				answer--;
				break;
			}

			// ��ġ ����
			alphabets[alpha] = i;
		}
	}

	cout << answer;
}