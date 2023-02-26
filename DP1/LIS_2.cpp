#include<iostream>
using namespace std;

int lengths[1000001];
int index[1000001];
int ans[1000001];

int main()
{
	int cnt = 0;
	int len, input;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> input;

		if (cnt == 0)
		{
			lengths[i] = input;
			index[cnt++] = 0;	// first location
		}
		else if (lengths[cnt] < input)
		{
			index[i] = cnt;
			lengths[cnt++] = input;
		}
		else
		{
			int lowerIdx = lower_bound(lengths, lengths + cnt, input) - lengths;

			index[i] = lowerIdx;
			lengths[lowerIdx] = input;
		}
	}
}