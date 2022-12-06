#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int numCnt, strSize;
vector<int> vec;

void DFS(string str, int index, int count = 0)
{
	// M번 탐색했다면 종료
	if (count == strSize)
	{
		cout << str << '\n'; return;
	}

	for (int i = index; i < vec.size(); i++)
	{
		DFS(str + to_string(vec[i]) + ' ', i, count + 1);
	}
}

int main()
{
	cin >> numCnt >> strSize;

	vec.resize(numCnt);

	for (int i = 0; i < numCnt; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	DFS("", 0);
}