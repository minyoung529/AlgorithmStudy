#include<iostream>
using namespace std;

int arr[1000000], sorted[1000000];
void merge(int start, int end);

int main()
{
	int len;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}

	merge(0, len - 1);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << '\n';
	}
}

void merge(int start, int end)
{
	if (start >= end)return;

	int mid = (start + end) / 2;

	merge(start, mid);
	merge(mid + 1, end);

	int aStart = start;
	int bStart = mid + 1;
	int idx = start;

	while (aStart <= mid && bStart <= end)
	{
		if (arr[aStart] < arr[bStart])
		{
			sorted[idx++] = arr[aStart++];
		}
		else
		{
			sorted[idx++] = arr[bStart++];
		}
	}

	while (aStart <= mid)
	{
		sorted[idx++] = arr[aStart++];
	}

	while (bStart <= end)
	{
		sorted[idx++] = arr[bStart++];
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = sorted[i];
	}
}