#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str = "ILOVEYONSEI";
	char start;
	int result = 0;
	cin >> start;

	for (int i = 0; i < str.size(); i++)
	{
		result += abs(start - str[i]);
		
		// 현재 자리 갱신  
		start = str[i];
	}

	cout << result;
}
