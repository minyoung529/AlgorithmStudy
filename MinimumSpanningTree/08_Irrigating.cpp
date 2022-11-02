//#include<bits/stdc++.h>
//#define FASTIO			ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
//using namespace std;
//typedef pair<float, float> pos;
//
//struct edge
//{
//	int a, b;
//	float dist;
//
//	bool operator < (const edge& e) const
//	{
//		return dist < e.dist;
//	}
//};
//
//int parents[100];
//
//int find(int v)
//{
//	while (v != parents[v])
//	{
//		v = parents[v];
//	}
//
//	return v;
//}
//
//int main()
//{
//	FASTIO;
//
//	int vCnt, lCnt;
//	double result = 0;
//
//	vector<pair<int, pos>> positions;	// ��带 ����
//	vector<edge> edges;					// ������ ����
//	cin >> vCnt;
//
//	// ����� ���� �Է¹ޱ�
//	for (int i = 0; i < vCnt; i++)
//	{
//		float x, y;
//		cin >> x >> y;
//		positions.push_back({ i, {x, y} });
//		parents[i] = i;
//	}
//
//	// ���� �����
//	for (int i = 0; i < vCnt; i++)
//	{
//		for (int j = 0; j < vCnt; j++)
//		{
//			if (i == j) continue;
//
//			pos p1 = positions[i].second;
//			pos p2 = positions[j].second;
//			float dist = sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
//
//			edges.push_back({ i, j, dist });
//		}
//	}
//
//	// ũ�罺Į
//	sort(edges.begin(), edges.end());
//
//	for (int i = 0; i < edges.size(); i++)
//	{
//		int fa = find(edges[i].a);
//		int fb = find(edges[i].b);
//
//		if (fa != fb)
//		{
//			result += edges[i].dist;
//			parents[fa] = fb;
//		}
//	}
//
//	cout << result;
//}