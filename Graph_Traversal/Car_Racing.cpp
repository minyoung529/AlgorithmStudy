//#include<iostream>
//#include<queue>
//#include<vector>
//#include<string>
//using namespace std;
//
//vector<pair<int, int>> childs[1001];
//int parents[1001];
//long long minVals[1001];
//long long res = 0;
//
//int main()
//{
//	int vCnt, lCnt;
//	cin >> vCnt >> lCnt;
//
//	for (int i = 0; i < lCnt; i++)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//
//		childs[a].push_back({ b, w });
//		parents[b]++;
//	}
//
//	queue<pair<int, string>> q;
//	q.push({ 1, "1 " });
//
//	while (!q.empty())
//	{
//		int top = q.front().first;
//		string path = q.front().second;
//
//		for (pair<int, int> p : childs[top])
//		{
//			if (--parents[p.first] == 0)
//			{
//				q.push()
//			}
//
//			if (minVals[top])
//		}
//	}
//}