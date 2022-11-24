#include <vector>
#include <iostream>
#include <algorithm>
#define DIST(x)	getdist(x, index, name.size())
using namespace std;

int answer = 400;
string name;

// 최소 이동거리 구하기
int getdist(int from, int to, int max)
{
	return min(abs(from - to), max - abs(from - to));
}

// diff		> A가 아닌 숫자들의 인덱스를 모아놓은 배열
// index	> 현재 위치
// sum		> 총 이동 횟수
// difidx	> 현재 위치의 diff vector 인덱스 값
void func(vector<int> diff, int index = 0, int sum = 0, int difidx = 0)
{
	sum += getdist(0, name[index] - 'A', 26);	// 알파벳 경로 구하기

	if (name[index] != 'A' && !diff.empty())	// A가 아니고 (diff에 있고), 비어있지 않을 때
	{
		diff.erase(diff.begin() + difidx);
	}

	if (diff.empty())	// 재귀 종료
	{
		answer = min(answer, sum); return;
	}

	// 정상 거리 경로(돌아가기 X) 오름차순 정렬
	sort(diff.begin(), diff.end(), [index](int a, int b)
		{ return abs(index - a) < abs(index - b); });

	func(diff, diff.front(), sum + DIST(diff.front()));					// 최단경로
	func(diff, diff.back(),  sum + DIST(diff.back()), diff.size() - 1);	// 최장경로 ( 돌아가는 최단거리 )
}

int solution(string n)
{
	vector<int> diff;
	name = n;

	for (int i = 0; i < n.size(); i++)
	{
		if (name[i] != 'A')
		{
			diff.push_back(i);
		}
	}

	func(diff);

	return answer;
}