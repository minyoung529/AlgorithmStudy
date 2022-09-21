#include<iostream>
#include<map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len;
	map<string, int> extensions;
	cin >> len;

	while (len--)
	{
		string input, extension = "";
		int curIndex = 0;
		cin >> input;

		// '.'일 때까지 돌린다
		while (input[++curIndex] != '.');

		// 구한 curIndex부터 끝까지 새 문자열에 넣어준다
		while (++curIndex < input.size())
			extension.push_back(input[curIndex]);

		// 만든 새 문자열을 key로 등록하고, value를 1씩 올려준다
		extensions[extension]++;
	}

	// 사전순 출력
	for (auto pair : extensions)
	{
		cout << pair.first << ' ' << pair.second << '\n';
	}
}