#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

int numCnt, strSize;
vector<int> vec;

void DFS(string str, int index, bool visited[8], int count = 0)
{
	// M�� Ž���ߴٸ� ����
	if (count == strSize)
	{
		cout << str << '\n'; return;
	}

	int prev = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (visited[i] || prev == vec[i])continue;
		// ���� ���ڿ� + ���ο� ���� + ����

		visited[i] = true;
		DFS(str + to_string(vec[i]) + ' ', i, visited, count + 1);
		visited[i] = false;
		prev = vec[i];
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

	bool visited[8] = { false, };
	DFS("", 0, visited, 0);
}