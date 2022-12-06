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
//			// 아이템 i의 무게가 배낭 용량을 초과하면
//			if (w[i] > j)
//			{
//				// 물건을 i-1 담았을 때 가치를 넣는다.
//				dp[i][j] = dp[i - 1][j];
//			}
//			else
//			{
//				// 아이템 i를 담았을 때 가치와 담지 않았을 때의 가치 중 큰 값을 고른다.
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
//			}
//		}
//	}
//
//	cout << dp[n][k];
//}