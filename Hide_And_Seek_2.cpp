//#include<iostream>
//#include<queue>
//using namespace std;
//
//#define MAX 100000
//bool visited[100001];
//int start, endV, answer = 0;
//
//void set(int f, int s, queue<pair<int, int>>& q)
//{
//	if (f < 0 || f > endV + 1 || visited[f]) return;
//
//	visited[f] = true;
//	q.push({ f , s });
//}
//
//int main()
//{
//	cin >> start >> endV;
//
//	queue<pair<int, int>> q;
//	int ans = 0, same = 0;
//	q.push({ start, 0 });
//
//	if (start < endV)
//	{
//		while (!q.empty())
//		{
//			pair<int, int> top = q.front();
//
//			if (top.first == endV)
//			{
//				if (ans == 0 || ans == top.second)
//				{
//					ans = top.second;
//					same++;
//				}
//				else break;
//			}
//
//			q.pop();
//
//			set(top.first + 1, top.second + 1, q);
//			set(top.first - 1, top.second + 1, q);
//			set(top.first * 2, top.second + 1, q);
//		}
//	}
//	else
//	{
//		cout << start - endV << '\n' << 1;
//		return 0;
//	}
//
//	cout << ans << '\n' << same;
//}