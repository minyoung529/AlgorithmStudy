//#include <bits/stdc++.h>
//using namespace std;
//#define INF	98765432
//
//vector<pair<int, int>> nodes[1001];
//int dist[1001];
//vector<int> path[1001];
//
//void dijkstra(int start);
//
//int main()
//{
//	int vCnt, lCnt, freeCnt;
//	cin >> vCnt >> lCnt >> freeCnt;
//
//	for (int i = 0; i < lCnt; i++)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//
//		nodes[a].emplace_back(b, w);
//		nodes[b].emplace_back(a, w);
//	}
//
//	for (int i = 0; i <= vCnt; i++)
//		dist[i] = INF;
//
//	dijkstra(1);
//
//	if (dist[vCnt] != INF)
//	{
//		for (int i : path[vCnt])
//			cout << i << ' ';
//
//		cout << dist[vCnt];
//	}
//	else
//	{
//		cout << -1;
//	}
//}
//
//void dijkstra(int start)
//{
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQueue;
//	pQueue.push({ 0, start });
//	dist[start] = 0;
//
//	while (!pQueue.empty())
//	{
//		int d = pQueue.top().first; // 현재 노드까지의 비용
//		int now = pQueue.top().second;
//		pQueue.pop();
//
//		if (dist[now] < d)	// 이미 최단 경로의 노드일 경우 패스
//			return;
//
//		for (int i = 0; i < nodes[now].size(); i++)
//		{
//			int cost = d + nodes[now][i].second;	// 현재 노드 비용 + 다음 노드 비용
//			int idx = nodes[now][i].first;
//
//			if (cost < dist[idx])
//			{
//				dist[idx] = cost;
//				cout << now << '>' << idx << ' ' << cost << endl;
//
//				for (int i : path[now])
//				{
//					path[idx].push_back(i);
//				}
//				path[idx].push_back(nodes[now][i].second);
//
//				pQueue.push({ cost, idx });
//			}
//		}
//	}
//}