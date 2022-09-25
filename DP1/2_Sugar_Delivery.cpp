#include<iostream>
using namespace std;

int main()
{
	int num, answer = 0;
	cin >> num;

	// 5로 나누어질 때까지 3을 뺀다
	while (num % 5 && num > 0)
	{
		num -= 3;
		answer++;
	}

	// 5로 나누어진다면 정답 출력
	if (num % 5 == 0)
		cout << answer + num / 5;
	else
		cout << -1;
}