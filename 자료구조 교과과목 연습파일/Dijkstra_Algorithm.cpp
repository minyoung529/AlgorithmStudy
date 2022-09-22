//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//#define MAX_VTXS	50
//#define INF			9999
//
//class AdjMatGraph
//{
//protected:
//	int						size;
//	char					vertices[MAX_VTXS];
//	int						adj[MAX_VTXS][MAX_VTXS];
//	const int				MAX_SIZE;
//
//public:
//	AdjMatGraph() : MAX_SIZE(MAX_VTXS)
//	{
//		reset();
//	}
//
//	char getVertex(int i) { return vertices[i]; }
//	int getEdge(int i, int j) { return adj[i][j]; }
//	void setEdge(int i, int j, int val) { adj[i][j] = val; }
//	bool isEmpty() { return (size == 0); }
//	bool isFull() { return size >= MAX_SIZE; }
//
//	// 직접 구현
//	void insertVertex(char name)
//	{
//		if (isFull()) return;
//
//		vertices[size++] = name;
//	}
//
//	void insertEdge(int u, int v, int weight)
//	{
//		if (isEmpty()) return;
//
//		adj[u][v] = weight;
//		adj[v][u] = weight;
//	}
//
//	void display()
//	{
//		cout << "정점의 개수 : " << size << endl;
//
//		for (int i = 0; i < size; i++)
//		{
//			cout << vertices[i] << " ";
//
//			for (int j = 0; j < size; j++)
//			{
//				cout << adj[i][j] << " ";
//			}
//
//			cout << endl;
//		}
//	}
//
//	void reset()
//	{
//		size = 0;
//
//		for (int i = 0; i < MAX_SIZE; i++)
//			for (int j = 0; j < MAX_SIZE; j++)
//				setEdge(i, j, INF);
//	}
//};
//
//class ShortestPath : public AdjMatGraph
//{
//	int dist[MAX_VTXS];
//	bool found[MAX_VTXS];
//
//	void printDistance()
//	{
//		for (int i = 0; i < size; i++)
//			cout << dist[i] << " ";
//		cout << endl;
//	}
//
//	int chooseVertex()
//	{
//		int min = INF, minPos = -1;
//
//		for (int i = 0; i < size; i++)
//		{
//			if (!found[i] && dist[i] < min)
//			{
//				min = dist[i];
//				minPos = i;
//			}
//		}
//
//		return minPos;
//	}
//
//public:
//	void dijkstra(int start)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			dist[i] = getEdge(start, i);
//			found[i] = false;
//		}
//
//		found[start] = true;
//		dist[start] = 0;
//
//		for (int i = 0; i < size; i++)
//		{
//			cout << "Step " << i + 1 << " : ";
//			printDistance();
//			int u = chooseVertex();
//			found[u] = true;
//
//			for (int w = 0; w < size; w++)
//			{
//				if (getEdge(u, w) < dist[w] && !found[w])
//				{
//					dist[w] = getEdge(u, w);
//				}
//			}
//		}
//	}
//};
//
//int main()
//{
//	ShortestPath g;
//
//	for (int i = 0; i < 7; i++)
//	{
//		g.insertVertex('A' + i);
//	}
//
//	g.reset();
//
//	g.insertEdge(0, 1, 2);
//	g.insertEdge(1, 2, 7);
//	g.insertEdge(1, 2, 1);
//	g.insertEdge(1, 3, 3);
//	g.insertEdge(2, 4, 4);
//	g.insertEdge(2, 5, 5);
//	g.insertEdge(3, 2, 2);
//	g.insertEdge(3, 4, 3);
//	g.insertEdge(4, 5, 4);
//	g.insertEdge(4, 6, 1);
//	g.insertEdge(5, 6, 5);
//
//	g.dijkstra(0);
//}