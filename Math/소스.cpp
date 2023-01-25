//#include<iostream>
//using namespace std;
//
//int arr[1025][1025];
//int leftSums[1025][1025];
//int rightSums[1025][1025];
//
//int main()
//{
//	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
//
//	int n, order;
//	cin >> n >> order;
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			cin >> arr[i][j];
//
//	for (int i = 1; i <= n; i++)
//	{
//		int leftSum = 0, rightSum = 0, sum = 0;
//
//		for (int j = 1; j <= n; j++)
//		{
//			leftSum += arr[i][j];
//			leftSums[i][j] = leftSum;
//
//			rightSum += arr[i][n - (j - 1)];
//			rightSums[i][n - (j - 1)] = rightSum;
//		}
//	}
//
//	while (order--)
//	{
//		int x1, y1, x2, y2, ans = 0;
//		cin >> y1 >> x1 >> y2 >> x2;
//
//		for (int y = y1; y <= y2; y++)
//		{
//			int sub = leftSums[y][x1 - 1] + rightSums[y][x2 + 1];
//			ans += rightSums[y][1] - sub;
//		}
//
//		printf("%d\n", ans);
//	}
//}

//#include<iostream>
//using namespace std;
//typedef unsigned long long ull;
//ull a, b, c;
//
//int main()
//{
//	ull res = 1;
//	cin >> a >> b >> c;
//
//	while (b)
//	{
//		if (b & 1)	// 홀수라면
//			res = (res * a) % c;
//
//		a = ((a % c) * (a % c)) % c;
//		b /= 2;	// 나누기
//	}
//
//	cout << res;
//}