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
	if (count == strSize)
	{
		cout << str << '\n'; return;
	}

	for (int i = 0; i < v.size(); i++)
	{
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
		cin >> vec[i];

	// 오름차순 정렬 => curindex~maxindex까지 불필요한 것을 빼고 탐색하기 위해
	sort(vec.begin(), vec.end());

	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	DFS("", 0, 0, vec);
}