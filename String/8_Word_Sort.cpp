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

		// ���ڼ����� �ٸ� �迭 �ε����� �ֱ�
		str[input.size()].insert(input);
	}

	for (int i = 1; i < 51; i++)
	{
		// �ܾ� ����� ����, ���� ������ ����Ѵ�.
		for (string s : str[i])
		{
			cout << s << '\n';
		}
	}
}