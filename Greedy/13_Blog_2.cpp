#include <iostream>
using namespace std;

#define RED		1
#define BLUE	2

int main()
{
	int len, red = 0, blue = 0;
	int state = 0;
	char input;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> input;

		if (input == 'R')
		{
			// 이전 색이 빨강이 아니라면
			// 색을 바꾸는 작업 횟수 증가
			if (state != RED) red++;
			state = RED;
		}
		else
		{
			if (state != BLUE) blue++;
			state = BLUE;
		}
	}

	// 1(처음에 모두 칠한 횟수) + (더 적은 작업 횟수)
	if (red >= blue)
		cout << 1 + blue;
	else
		cout << 1 + red;
}