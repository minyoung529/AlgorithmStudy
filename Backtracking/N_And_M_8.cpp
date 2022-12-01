#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int numCnt, strSize;
vector<int> vec;

void DFS(string str, int index, int count = 0)
{
	// M�� Ž���ߴٸ� ����
	if (count == strSize)
	{
		cout << str << '\n'; return;
	}

	for (int i = index; i < vec.size(); i++)
	{
		// ���� ���ڿ� + ���ο� ���� + ����
		DFS(str + to_string(vec[i]) + ' ', i, count + 1);
	}
}

int main()
{
	cin >> numCnt >> strSize;

	vec.resize(numCnt);

	for (int i = 0; i < numCnt; i++)
		cin >> vec[i];

	// �������� ���� => curindex~maxindex���� ���ʿ��� ���� ���� Ž���ϱ� ����
	sort(vec.begin(), vec.end());

	DFS("", 0);
}