//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//vector<pair<int, int>> childs[10001];
//int parents[10001], resLevel;
//pair<long long, int> minVals[10001];
//long long res = 0;
//
//int main()
//{
//	int vCnt, lCnt, start, end;
//	cin >> vCnt >> lCnt;
//
//	for (int i = 0; i < lCnt; i++)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//
//		parents[b]++;
//		childs[a].push_back({ b,w });
//	}
//
//	cin >> start >> end;
//
//	queue<pair<int, int>> q;
//	q.push({ start, 1 });
//	parents[start] = 0;
//
//	while (!q.empty())
//	{
//		int top = q.front().first;
//		int level = q.front().second;
//		q.pop();
//
//		for (pair<int, int> child : childs[top])
//		{
//			if (--parents[child.first] == 0)
//				q.push({ child.first, level + 1 });
//
//			if (minVals[child.first].first < minVals[top].first + child.second)
//			{
//				minVals[child.first].first = minVals[top].first + child.second;
//				minVals[child.first].second = level + 1;
//
//				res = max(res, minVals[child.first].first);
//				resLevel /*= max(resLevel, minVals[child.first].second);*/++;
//			}
//
//			//res = max(res, minVals[top].first);
//			//resLevel = max(resLevel, level);
//		}
//	}
//
//	cout << res << '\n' << resLevel;
//}