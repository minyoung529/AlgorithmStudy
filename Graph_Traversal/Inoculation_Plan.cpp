//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int parents[10001];
//long long minVals[10001][10001];
//vector<pair<int, int>> nodes[10001];
//queue<pair<int, int>> q;
//
//int main()
//{
//	queue<long long> q;
//	int vCnt, lCnt, a, b, w;
//	long long res = 0;
//	cin >> vCnt >> lCnt;
//
//	for (int i = 1; i <= lCnt; i++)
//	{
//		cin >> a >> b >> w;
//		nodes[a].push_back({ b, w });
//		minVals[i];
//
//		parents[b]++;
//	}
//
//	for (int i = 1; i <= vCnt; i++)
//	{
//		if (parents[i] == 0)
//		{
//			q.push(i);
//		}
//	}
//
//	while (!q.empty())
//	{
//		int top = q.front();
//		q.pop();
//
//		for (pair<int, int> i : nodes[top])
//		{
//			if (--parents[i.first] == 0)
//			{
//				q.push(i.first);
//			}
//
//			minVals[i.first] = max(minVals[top] + i.second, minVals[i.first]);
//			res = max(minVals[i.first], res);
//		}
//
//		res = max(minVals[top], res);
//	}
//
//	cout << res;
//}