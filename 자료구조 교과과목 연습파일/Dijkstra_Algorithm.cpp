#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VTXS	50
#define INF			9999

class AdjMatGraph
{
protected:
	int						size;
	char					vertices[MAX_VTXS];
	int						adj[MAX_VTXS][MAX_VTXS];
	const int				MAX_SIZE;

public:
	AdjMatGraph() : MAX_SIZE(MAX_VTXS)
	{
		reset();
	}

	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return (size == 0); }
	bool isFull() { return size >= MAX_SIZE; }

	// 직접 구현
	void insertVertex(char name)
	{
		if (isFull()) return;
		vertices[size++] = name;
	}

	void insertEdge(int u, int v, int weight)
	{
		if (isEmpty()) return;

		adj[u][v] = weight;
		adj[v][u] = weight;
	}

	void display()
	{
		cout << "정점의 개수 : " << size << endl;

		for (int i = 0; i < size; i++)
		{
			cout << vertices[i] << " ";

			for (int j = 0; j < size; j++)
			{
				cout << adj[i][j] << " ";
			}

			cout << endl;
		}
	}

	void reset()
	{
		size = 0;

		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				setEdge(i, j, INF);
	}
};

class ShortestPath : public AdjMatGraph
{
	int dist[MAX_VTXS];
	int parent[MAX_VTXS];
	bool found[MAX_VTXS];

	void printDistance()
	{
		for (int i = 0; i < size; i++)
			cout << dist[i] << " ";
		cout << endl;
	}

	int chooseVertex()
	{
		int min = INF, minPos = -1;

		for (int i = 0; i < size; i++)
		{
			if (!found[i] && dist[i] < min)
			{
				min = dist[i];
				minPos = i;
			}
		}

		return minPos;
	}

public:
	void dijkstra(int start)
	{
		for (int i = 0; i < size; i++)
		{
			dist[i] = getEdge(start, i);
			found[i] = false;
		}

		found[start] = true;
		dist[start] = 0;

		for (int i = 0; i < size; i++)
		{
			cout << "Step " << i + 1 << " : ";
			printDistance();
			int u = chooseVertex();
			found[u] = true;

			for (int w = 0; w < size; w++)
			{
				if (dist[u] + getEdge(u, w) < dist[w] && !found[w])
				{
					dist[w] = dist[u] + getEdge(u, w);
				}
			}
		}
	}

	void dijkstra(int start, int end)
	{
		for (int i = 0; i < size; i++)
		{
			dist[i] = getEdge(start, i);
			found[i] = false;
		}

		fill_n(parent, size, -1);

		found[start] = true;
		dist[start] = 0;
		parent[start] = start;

		int next, current = start;

		cout << start << " 정점에서 시작!" << endl;

		for (int i = 0; i < size; i++)
		{
			if (current == end)
			{
				cout << "목적 정점" << end << "에 도착!" << endl;
				break;
			}

			cout << "Step " << i + 1 << " : ";
			printDistance();
			next = chooseVertex();

			cout << next << " 정점에 안착! " << endl;

			found[next] = true;

			for (int w = 0; w < size; w++)
			{
				if (!found[w])
				{
					if (dist[next] + getEdge(next, w) < dist[w])
					{
						dist[w] = dist[next] + getEdge(next, w);
						parent[w] = next;
					}
				}
			}

			current = next;
		}

		vector <int> shortestPath;

		while (current != start)
		{
			shortestPath.push_back(current);
			current = parent[current];
			if (current == -1) break;
		}

		shortestPath.push_back(start);
		reverse(shortestPath.begin(), shortestPath.end());

		cout << start << "에서 " << end << "까지의 최단경로 : ";
		for (auto i : shortestPath)
		{
			cout << i << " ";
		}
	}
};

int main()
{
	ShortestPath g;

	for (int i = 0; i < 7; i++)
	{
		g.insertVertex('A' + i);
	}

	g.insertEdge(0, 1, 2);
	g.insertEdge(0, 2, 7);
	g.insertEdge(1, 2, 1);
	g.insertEdge(1, 3, 3);
	g.insertEdge(2, 4, 4);
	g.insertEdge(2, 5, 5);
	g.insertEdge(3, 2, 2);
	g.insertEdge(3, 4, 3);
	g.insertEdge(4, 5, 4);
	g.insertEdge(4, 6, 1);
	g.insertEdge(5, 6, 5);

	g.dijkstra(0, 5);
}