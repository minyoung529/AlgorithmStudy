//#include<iostream>
//using namespace std;
//
//int dp[101][100001];
//int w[101];
//int v[101];
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//
//	for (int i = 1; i <= n; i++)
//		cin >> w[i] >> v[i];
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= k; j++)
//		{
//			// ������ i�� ���԰� �賶 �뷮�� �ʰ��ϸ�
//			if (w[i] > j)
//			{
//				// ������ i-1 ����� �� ��ġ�� �ִ´�.
//				dp[i][j] = dp[i - 1][j];
//			}
//			else
//			{
//				// ������ i�� ����� �� ��ġ�� ���� �ʾ��� ���� ��ġ �� ū ���� ����.
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
//			}
//		}
//	}
//
//	cout << dp[n][k];
//}