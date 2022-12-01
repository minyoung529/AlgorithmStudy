#include<iostream>
#include<queue>
using namespace std;
#define MAX 500000

int n, input, arr[MAX + 1];
bool grade[MAX + 1];
unsigned long long result = 0;

int main()
{
	queue<int> remain;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr[input]++;
	}

	for (int i = 1; i <= MAX; i++)
	{
		if (arr[i])	// 예상등수 == 현재등수
		{
			grade[i] = true;		// 등수 정했음을 표시
			if (i > n) arr[i]++;	// 예상등수 > 인원수라면 남은 예상 등수 배열에 N번 삽입

			// 그렇지 않다면 N-1 삽입
			// -1? => 하나는 이미 등수가 정해짐
			while (--arr[i]) remain.push(i);	
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!grade[i])	// 등수가 정해져있지 않다면
		{
			// 오름차순으로 등수 정함
			result += abs(remain.front() - i);
			remain.pop();
		}
	}

	cout << result;
}