//#include<iostream>
//#include<vector>
//#include<queue>
//#include<map>
//#include<algorithm>
//using namespace std;
//
//struct node
//{
//	string name;
//	vector<string> childs;
//	int parentCnt;
//};
//
//map<string, node> nodes;
//map<int, vector<string>> res;
//
//int main()
//{
//	int len;
//	cin >> len;
//
//	for (int i = 0; i < len; i++)
//	{
//		string a, b;
//		cin >> a >> b;
//
//		nodes[a].name = a;
//		nodes[b].name = b;
//
//		nodes[b].parentCnt++;
//		nodes[a].childs.push_back(b);
//	}
//
//	queue<pair<string, int>> q;
//
//	for (auto& pair : nodes)
//	{
//		if (pair.second.parentCnt == 0)
//		{
//			q.push({ pair.second.name, 0 });
//		}
//	}
//
//	int cnt = 0;
//
//	while (!q.empty())
//	{
//		cnt++;
//		string name = q.front().first;
//		int level = q.front().second;
//		q.pop();
//
//		res[level].push_back(name);
//		//cout << name << endl;
//		for (string child : nodes[name].childs)
//		{
//			if (--nodes[child].parentCnt == 0)
//			{
//				q.push({ child, level + 1 });
//			}
//		}
//	}
//
//	if (cnt != nodes.size())
//	{
//		cout << -1;
//	}
//	else
//	{
//		for (auto& strs : res)
//		{
//			sort(strs.second.begin(), strs.second.end());
//
//			for (string element : strs.second)
//			{
//				cout << element << '\n';
//			}
//		}
//	}
//}