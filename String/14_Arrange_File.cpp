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

		// '.'�� ������ ������
		while (input[++curIndex] != '.');

		// ���� curIndex���� ������ �� ���ڿ��� �־��ش�
		while (++curIndex < input.size())
			extension.push_back(input[curIndex]);

		// ���� �� ���ڿ��� key�� ����ϰ�, value�� 1�� �÷��ش�
		extensions[extension]++;
	}

	// ������ ���
	for (auto pair : extensions)
	{
		cout << pair.first << ' ' << pair.second << '\n';
	}
}