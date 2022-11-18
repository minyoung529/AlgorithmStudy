#include<stdio.h>
#define LEN	100

int main()
{
	char str[LEN];
	char star[4] = { 's', 't', 'a', 'r' };
	scanf("%s", str);
	int curStar = 0;
	int starCount = 0;

	for (int i = 0; i < LEN; i++)
	{
		if (str[i] == NULL) break;

		if (star[curStar] == str[i] || star[curStar] - ('a' - 'A') == str[i])
		{
			curStar++;

			if (curStar == 4)
			{
				starCount++;
				curStar = 0;
			}
		}
		else if (star[i] == '*')
		{
			continue;
		}
		else
		{
			curStar = 0;

			if (star[curStar] == 'S' || star[curStar] == 's')
				i--;
		}
	}

	printf("The number of STAR is %d", starCount);
}