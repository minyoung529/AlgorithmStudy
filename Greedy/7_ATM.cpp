#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL);  cin.tie(NULL);

	vector<int> times;
	int len, curWait = 0;
	long long int waitTime = 0;

	cin >> len;
	
	for (int i = 0; i < len; i++)
	{
		int input;
		cin >> input;
		times.push_back(input);
	}

	// 정렬
	sort(times.begin(), times.end());
	
	for (int i = 0; i < len; i++)
	{
		// 각자의 인출 시간을 계속해서 더해준다
		// => 현재 사람이 인출하는데 걸리는 시간 
		curWait += times[i];
		waitTime += curWait;
	}

	cout << waitTime;
}