#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
int BeeBeeHoney(vector<int> v, int sum);

int main()
{
	int len, honey, sum = 0;
	int answer = 0;
	cin >> len;
	arr.resize(len);

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	// CASE 1
	// BEE HONEY BEE
	// 두 벌의 시작 자리 제외
	answer = sum - arr[0] - arr[len - 1];

	// max index
	honey = max_element(arr.begin() + 1, arr.end() - 1) - arr.begin();
	answer += arr[honey];

	// CASE 2
	// BEE BEE HONEY
	int temp = BeeBeeHoney(arr, sum);

	if (temp > answer)
		answer = temp;

	// CASE 3
	// HONEY BEE BEE
	reverse(arr.begin(), arr.end());
	temp = BeeBeeHoney(arr, sum);

	if (temp > answer)
		answer = temp;

	cout << answer;
}

int BeeBeeHoney(vector<int> v, int sum)
{
	int exception = -2147483647;

	for (int i = 1, honeySum = 0; i < v.size(); i++)
	{
		int minus = -(arr[0] * 2) - (arr[i] * 2) - honeySum;

		if (exception < minus)
			exception = minus;

		honeySum += arr[i];
	}

	return sum * 2 + exception;
}