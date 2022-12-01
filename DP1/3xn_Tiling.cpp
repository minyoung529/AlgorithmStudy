//#include<math.h>
//#define VAL 1000000007
//using namespace std;
//long long dp[5001];
//#include<iostream>
//
//int modular_mul(int a, int b, int m)
//{
//	return ((a % m) * (b % m)) % m;
//}
//
//int modular_sub(int a, int b, int m)
//{
//	return ((a % m) - (b % m)) % m;
//}
//
//
//int solution(int n)
//{
//	dp[1] = 0; dp[2] = 3; dp[4] = 11;
//
//	for (int i = 6; i <= n; i++)
//	{
//		//dp[i] = modular_sub(modular_mul(dp[i - 2], 4, 1000000007), dp[i - 4], 1000000007);4
//
//		cout << i << ": " << modular_mul(dp[i - 2], 4, VAL) << endl;
//		dp[i] = ((dp[i - 2] % VAL) * (4 % VAL)) - dp[i - 4] % VAL;
//	}
//
//	return dp[n];
//}
//
//
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	cout << solution(n);
//
//	//cout << solution(6) << endl;
//	//cout << solution(7) << endl;
//	//cout << solution(8) << endl;
//	//cout << solution(9) << endl;
//	//cout << solution(10) << endl;
//}