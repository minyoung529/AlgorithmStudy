#include<bits/stdc++.h>
using namespace std;

int main()
{
	__uint128_t answer = 1;
	vector<int> v;
	int n, m;
	cin >> n >> m;

	// nCm = nC(m-n)
	if (m > n - m)
		m = n - m;

	// ���� ���
	for (int i = 0; i < m; i++)
	{
		answer *= (n - i);
		answer /= (i + 1);
	}

	// ���Ϳ� �������� �ֱ�
	while (answer)
	{
		v.push_back(answer % 10);
		answer /= 10;
	}

	// ������
	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
}