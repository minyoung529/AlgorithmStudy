#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int numCnt, strSize;
vector<int> vec;

void DFS(string str, int index, int count, vector<int> v)
{
	// M�� Ž���ߴٸ� ����
	if (v.empty() || count == strSize)
	{
		cout << str << '\n'; return;
	}

	for (int i = index; i < v.size(); i++)
	{
		// ���� ���ڿ� + ���ο� ���� + ����
		vector<int> temp = v;
		temp.erase(temp.begin() + i);
		DFS(str + to_string(v[i]) + ' ', i, count + 1, temp);
	}
}

int main()
{
	cin >> numCnt >> strSize;

	vec.resize(numCnt);

	for (int i = 0; i < numCnt; i++)
	{
		vec[i] = i + 1;
	}

	DFS("", 0, 0, vec);
}