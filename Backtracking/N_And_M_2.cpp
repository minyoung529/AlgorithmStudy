#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int numCnt, strSize;
vector<int> vec;

void DFS(string str, int index, int count, vector<int> v)
{
	// M번 탐색했다면 종료
	if (v.empty() || count == strSize)
	{
		cout << str << '\n'; return;
	}

	for (int i = index; i < v.size(); i++)
	{
		// 현재 문자열 + 새로운 숫자 + 공백
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