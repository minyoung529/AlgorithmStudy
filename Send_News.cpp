//#include<iostream>
//#include<queue>
//#include<vector> 
//#include<algorithm> 
//using namespace std;
//
//bool visited[10001];
//bool already[10001];
//vector<int> nodes[10001];
//
//vector<int> BFS(int start, int target);
//
//int main()
//{
//	int vCnt, lCnt, start, end, answer;
//	cin >> vCnt >> lCnt;
//
//	for (int i = 0; i < lCnt; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//
//		nodes[a].push_back(b);
//		nodes[b].push_back(a);
//	}
//
//	for (int i = 1; i <= vCnt; i++)
//	{
//		sort(nodes[i].begin(), nodes[i].end());
//	}
//
//	cin >> start >> end;
//
//	vector<int> visit = BFS(start, end);
//
//	for (int i : visit)
//		already[i] = true;
//
//	for (int i = 0; i <= vCnt; i++)
//		visited[i] = false;
//
//	cout << visit.size() + BFS(end, start).size() - 2;
//}
//
//vector<int> BFS(int start, int target)
//{
//	queue<pair<int, vector<int>>> queue;
//	int count = 0;
//	queue.push({ start, {start} });
//
//	while (!queue.empty())
//	{
//		int v = queue.front().first;
//		visited[v] = true;
//
//		if (v == target)
//			return queue.front().second;
//
//		for (int i : nodes[v])
//		{
//			if (!visited[i] && (!already[i] || i == target))
//			{
//				vector<int> vec = queue.front().second;
//				vec.push_back(i);
//				queue.push({ i, vec });
//			}
//		}
//
//		queue.pop();
//		count++;
//	}
//	return {};
//}
