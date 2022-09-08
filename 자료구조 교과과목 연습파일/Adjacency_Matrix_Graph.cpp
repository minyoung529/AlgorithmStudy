#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VTXS	50

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

	void insertEdge(int u, int v)
	{
		if (isEmpty()) return;

		adj[u][v] = 1;
		adj[v][u] = 1;
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
				setEdge(i, j, 0);
	}
};

class SearchGraph : public AdjMatGraph
{
	bool visited[MAX_VTXS];

public:
	void resetVisited()
	{
		for (int i = 0; i < size; i++)
		{
			visited[i] = false;
		}
	}

	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	void DFS(int v)
	{
		visited[v] = true;
		cout << vertices[v] << " ";

		for (int i = 0; i < size; i++)
		{
			if (isLinked(v, i) && !visited[i])
			{
				DFS(i);
			}
		}
	}

	void BFS(int v)
	{
		visited[v] = true;

		queue<char> q;
		q.push(v);

		while (!q.empty())
		{
			int i = q.front();
			cout << vertices[i] << " ";
			q.pop();

			for (int j = 0; j < size; j++)
			{
				if (isLinked(j, i) && !visited[j])
				{
					q.push(j);
					visited[j] = true;
				}
			}
		}
	}
};

int main()
{
	SearchGraph g;

	for (int i = 0; i < 4; i++)
	{
		g.insertVertex('A' + i);
	}

	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);

	cout << "인접 행렬로 표현한 그래프" << endl;
	g.display();

	cout << "DFS 탐색 = > ";
	g.resetVisited();
	g.DFS(0);

	cout << endl;

	cout << "BFS 탐색 = > ";
	g.resetVisited();
	g.BFS(0);
}