#include<iostream>
#include<set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);  cout.tie(NULL); cin.tie(NULL);

	int len;
	set<string> str[51];

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		string input;
		cin >> input;

		// 글자수별로 다른 배열 인덱스에 넣기
		str[input.size()].insert(input);
	}

	for (int i = 1; i < 51; i++)
	{
		// 단어 수대로 먼저, 사전 순으로 출력한다.
		for (string s : str[i])
		{
			cout << s << '\n';
		}
	}
}