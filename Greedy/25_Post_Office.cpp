//#include<iostream>
//#include<queue>
//using namespace std;
//
//int main()
//{
//	int len;
//	pair<int, int> max;
//	double answer = 0;
//	priority_queue<pair<int, int>> pQueue;
//	cin >> len;
//
//	for (int i = 0; i < len; i++)
//	{
//		int country, people;
//		cin >> country >> people;
//		pQueue.push({ people, country });
//	}
//
//	max = pQueue.top();
//	answer = max.second;
//	pQueue.pop();
//
//	while (!pQueue.empty())
//	{
//		answer += (double)pQueue.top().first / max.first / max.second;
//		pQueue.pop();
//	}
//
//	cout << (int)answer;
//}