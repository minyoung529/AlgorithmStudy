#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define TOIDX(x) (x - 'A')
#define INDEX_TO_FRONT	getdist(diff.front(), index, name.size())
#define INDEX_TO_BACK	getdist(diff.back(), index, name.size())

using namespace std;

int answer = 1000000;
string name;

int getdist(int from, int to, int max)
{
	if (from > to) swap(from, to);
	return min(abs(from - to), from + (max - to));
}

void func(vector<int> diff, int index = 0, int sum = 0, int difidx = 0)
{
	sum += getdist(TOIDX('A'), TOIDX(name[index]), 26);	// 알파벳 경로 구하기

	if (name[index] != 'A' && !diff.empty())	// A가 아니고 (diff에 있고), 비어있지 않을 때
	{
		diff.erase(diff.begin() + difidx);
	}

	if (diff.empty())	// 재귀 종료
	{
		answer = min(answer, sum); return;
	}

	// left => right 경로
	sort(diff.begin(), diff.end(), [index](int a, int b)
		{ return abs(index - a) < abs(index - b); });

	func(diff, diff.back(), sum + INDEX_TO_BACK, diff.size() - 1);
	func(diff, diff.front(), sum + INDEX_TO_FRONT);

	// right => left 경로
	sort(diff.begin(), diff.end(), [index](int a, int b)
		{ return index + (name.size() - a) < index + (name.size() - b); });

	func(diff, diff.back(), sum + INDEX_TO_BACK, diff.size() - 1);
	func(diff, diff.front(), sum + INDEX_TO_FRONT);
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