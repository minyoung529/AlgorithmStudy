//#include<iostream>
//#include<queue>
//using namespace std;
//
//int main()
//{
//	int n, target, k;
//	pair<int, int> ans;
//	priority_queue<pair<int, int>> queue;
//
//	cin >> n >> target >> k;
//
//	for (int i = 0; i < k; i++)
//	{
//		int preference, level;
//		cin >> preference >> level;
//		queue.push({ -level, preference });
//	}
//
//	while (n-- && !queue.empty())
//	{
//		ans.first = max(ans.first, -queue.top().first);
//		ans.second += queue.top().second;
//
//		if (n == 0 && ans.second < target)
//		{
//			ans.second -= queue.top().second;
//			n++;
//		}
//
//		queue.pop();
//	}
//
//	if (ans.second >= target)
//	{
//		cout << ans.first;
//	}
//	else
//	{
//		cout << -1;
//	}
//}