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
		// 현재 문자열 + 새로운 숫자 + 공백
		DFS(str + to_string(vec[i]) + ' ', i, count + 1);
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

	DFS("", 0);
}