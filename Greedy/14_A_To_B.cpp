#include<iostream>
#include<queue>
using namespace std;

#define LIMIT	500000000
int a, b;
bool check[LIMIT];
queue<pair<long long int, int>> numbers;

bool Correct(long long int value, int count);

int main()
{
	cin >> a >> b;

	numbers.push({ a, 1 });

	while (!numbers.empty())
	{
		if (numbers.empty()) break;

		pair<long long int, int> val = numbers.front();
		int level = val.second + 1;

		// queue에 넣으려 하는 수가
		// 이미 넣어진 게 아니고, b보다 크지 않을 때 넣음
		// b와 같을 땐 횟수 반환해서 반복문 종료
		if (Correct(val.first * 10 + 1, level) || Correct(val.first * 2, level))
		{
			cout << level;
			return 0;
		}

		numbers.pop();
	}

	cout << -1;
}

bool Correct(long long int value, int level)
{
	// value와 b가 같다면 true 반환
	if (value == b)
		return true;

	// 크다면 queue에 넣지 않음
	if (value > b)
		return false;

	// 탐색하지 않은 value이면 queue에 넣음
	if (value >= LIMIT || check[value] != true)
		numbers.push({ value, level });

	// 탐색 완료
	if (value < LIMIT)
		check[value] = true;

	return false;
}