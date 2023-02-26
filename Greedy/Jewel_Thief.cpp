//#include<iostream>
//#include<vector>
//#include<queue>
//#include<list>
//#include<algorithm>
//using namespace std;
//
//struct jewel
//{
//	int m, v;
//
//	bool operator < (const jewel& j) const
//	{
//		return v < j.v;
//	}
//};
//
//priority_queue<jewel> jewels;
//vector<int> backpack;
//
//int main()
//{
//	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
//
//	int n, k, m, v, cur = 0;
//	unsigned long long res = 0;
//	cin >> n >> k;
//	backpack.resize(k);
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> m >> v;
//		jewels.push({ m,v });
//	}
//
//	for (int i = 0; i < k; i++)
//		cin >> backpack[i];
//
//	for (int i = 0; i < k; i++)
//	{
//
//	}
//
//	cout << res;
//}