#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool IsTouching(pair<int, int> a, pair<int, int> b)
{
	int dist = abs(a.first - b.first);

	// 내부 동심원
	if (dist < abs(a.second - b.second) || dist == 0)
		return false;

	// 외부
	if (a.second + b.second < dist)
		return false;

	return true;
}

bool Check(vector<pair<int, int>> vec)
{
	while (vec.size() >= 2)
	{
		if (IsTouching(vec.back(), *(vec.end() - 2)))
		{
			cout << "NO";
			return false;
		}

		vec.erase(vec.end() - 2);
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int len;
	vector<pair<int, int>> vec;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int posX, radius;
		cin >> posX >> radius;
		vec.push_back({ posX , radius });
	}

	// 중앙+반지름이 큰 순서대로 정렬 => 작은 것부터 오른쪽으로 비교
	sort(vec.begin(), vec.end(), [](auto p1, auto p2) {return p1.first + p1.second > p2.first + p2.second; });

	if (Check(vec))
	{
		// 중앙-반지름이 작은 순서대로 정렬 => 큰 것부터 왼쪽으로 비교
		sort(vec.begin(), vec.end(), [](auto p1, auto p2) {return p1.first - p1.second < p2.first - p2.second; });

		if (Check(vec))
		{
			cout << "YES";
		}
	}
}

/*

6
-12 3
-11 1
-5 3
-5 1
-4 1
-2 1
NO

*/