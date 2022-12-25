#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = n;
	int reserveArr[31] = { 0, };

	for (int i = 0; i < reserve.size(); i++)
	{
		if (find(lost.begin(), lost.end(), reserve[i]) == lost.end())	// 잃어버린 애가 아니면 빌려줄 수 있음!
		{
			reserveArr[reserve[i]] = 1;
		}
		else
		{
			reserveArr[reserve[i]] = -1;
		}
	}

	sort(lost.begin(), lost.end());

	for (int i = 0; i < lost.size(); i++)
	{
		if (reserveArr[lost[i]] != -1)	// 본인 여분이 없다면
		{
			if (reserveArr[lost[i] - 1] == 1)
			{
				reserveArr[lost[i] - 1] = false;
			}
			else if (reserveArr[lost[i] + 1] == 1)
			{
				reserveArr[lost[i] + 1] = false;
			}
			else answer--;
		}
	}

	return answer;
}

#include <iostream>
int main()
{
	cout << solution(4, { 2, 3 }, { 3, 4 });
}