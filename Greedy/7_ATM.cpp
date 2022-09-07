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

	// ����
	sort(times.begin(), times.end());
	
	for (int i = 0; i < len; i++)
	{
		// ������ ���� �ð��� ����ؼ� �����ش�
		// => ���� ����� �����ϴµ� �ɸ��� �ð� 
		curWait += times[i];
		waitTime += curWait;
	}

	cout << waitTime;
}