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
		
		// 입력 받기
		for (int j = 0; j < input.size(); j++)
		{
			if (isalpha(input[j]))
			{
				alphabets[input[j] - 'a']++;
			}
		}

		// max값 지정
		for (int j = 0; j < 26; j++)
		{
			if (max < alphabets[j])
			{
				max = alphabets[j];
				maxIndex = j;
			}
		}

		// 다른 max값이 있는지 탐색
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