//#include<iostream>
//#include<stack>
//using namespace std;
//
//int aCnt[26], bCnt[26];
//
//int main()
//{
//	string a, b;
//	int res = 0;
//	cin >> a >> b;
//
//	// 입력
//	for (int i = 0; i < a.size(); i++)
//	{
//		aCnt[a[i] - 'A']++;
//		bCnt[b[i] - 'A']++;
//	}
//
//	// 잘못된 값인지 판별
//	for (int i = 0; i < 26; i++)
//	{
//		if (aCnt[i] != bCnt[i])
//		{
//			cout << -1; return 0;
//		}
//	}
//
//	int idx = a.size() - 1;
//
//	while (a != b)
//	{
//		if (a[idx] == b[idx])
//		{
//			idx--;
//			continue;
//		}
//
//		int temp = idx;
//		while (temp >= 0 && a[temp--] != b[idx]);
//
//	}
//
//	cout << res;
//}