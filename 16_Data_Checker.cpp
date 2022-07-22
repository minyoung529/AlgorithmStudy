#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool IsTouching(pair<int, int> a, pair<int, int> b)
{
	int dist = abs(a.first - b.first);

	// ���� ���ɿ�
	if (dist < abs(a.second - b.second) || dist == 0)
		return false;

	// �ܺ�
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

	// �߾�+�������� ū ������� ���� => ���� �ͺ��� ���������� ��
	sort(vec.begin(), vec.end(), [](auto p1, auto p2) {return p1.first + p1.second > p2.first + p2.second; });

	if (Check(vec))
	{
		// �߾�-�������� ���� ������� ���� => ū �ͺ��� �������� ��
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