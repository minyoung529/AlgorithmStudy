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
	// M번 탐색했다면 종료
	if (count == strSize)
	{
		cout << str << '\n'; return;
	}

	int prev = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (visited[i] || prev == vec[i])continue;
		// 현재 문자열 + 새로운 숫자 + 공백

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

	// 오름차순 정렬 => curindex~maxindex까지 불필요한 것을 빼고 탐색하기 위해
	sort(vec.begin(), vec.end());

	bool visited[8] = { false, };
	DFS("", 0, visited, 0);
}