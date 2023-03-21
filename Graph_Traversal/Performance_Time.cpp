//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//unordered_map<string, int> parents;
//unordered_map<string, float> weights;
//unordered_map<string, pair<string, string>> dParents;
//unordered_map<string, vector<string>> childs;
//
//int main()
//{
//	int len, count;
//	string king;
//	cin >> len >> count >> king;
//
//	weights[king] = 1.f;
//
//	for (int i = 0; i < len; i++)
//	{
//		string p1, p2, c;
//		cin >> c >> p1 >> p2;
//
//		parents[c] = 0;
//		dParents[c] = { p1, p2 };
//		childs[p1].push_back(c);
//		childs[p2].push_back(c);
//	}
//
//	queue<string> q;
//
//	for (auto& pair : parents)
//	{
//		if (parents.find(dParents[pair.first].first) == parents.end() && parents.find(dParents[pair.first].second) == parents.end())
//		{
//			parents[pair.first] = 0;
//			q.push(pair.first);
//		}
//		else if (parents.find(dParents[pair.first].first) != parents.end() && parents.find(dParents[pair.first].second) != parents.end())
//		{
//			parents[pair.first] = 2;
//		}
//		else
//		{
//			parents[pair.first] = 1;
//		}
//	}
//
//	while (!q.empty())
//	{
//		string top = q.front();
//		q.pop();
//
//		float p1 = weights[dParents[top].first], p2 = weights[dParents[top].second];
//
//		weights[top] = p1 * 0.5f + p2 * 0.5f;
//		//cout << top << ' ' << weights[top] << endl;
//
//		for (auto& i : childs[top])
//		{
//			string parent = dParents[top].first, parent2 = dParents[top].second;
//
//			if (--parents[i] == 0)
//				q.push(i);
//		}	
//	}
//
//	float minval = 0.f;
//	string res;
//
//	for (int i = 0; i < count; i++)
//	{
//		string str;
//		cin >> str;
//
//		//cout << weights[str] << endl;
//
//		if (weights[str] > minval)
//		{
//			//cout << weights[str] << endl;
//			res = str;
//			minval = weights[str];
//		}
//	}
//
//	cout << res;
//}