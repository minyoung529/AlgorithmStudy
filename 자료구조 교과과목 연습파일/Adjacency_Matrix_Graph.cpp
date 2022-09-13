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

	// ���� ����
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
		cout << "������ ���� : " << size << endl;

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
	int visited[MAX_VTXS];

public:
	void resetVisited()
	{
		for (int i = 0; i < size; i++)
		{
			visited[i] = -1;
		}
	}

	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	void DFS(int v)
	{
		visited[v] = 0;
		cout << vertices[v] << " ";

		for (int i = 0; i < size; i++)
		{
			if (isLinked(v, i) && visited[i] < 0)
			{
				DFS(i);
			}
		}
	}

	void BFS(int v)
	{
		resetVisited();
		visited[v] = 0;

		queue<char> q;
		q.push(v);

		while (!q.empty())
		{
			int i = q.front();
			cout << getVertex(i) << " ";
			q.pop();

			for (int j = 0; j < size; j++)
			{
				if (isLinked(j, i) && visited[j] < 0)
				{
					visited[j] = visited[i] + 1;
					q.push(j);
				}
			}
		}

		cout << endl << "A���� �� ���������� �Ÿ� : ";

		for (int j = 0; j < size; j++)
		{
			cout << visited[j] << " ";;
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

	cout << "���� ��ķ� ǥ���� �׷���" << endl;
	g.display();

	cout << "DFS Ž�� = > ";
	g.resetVisited();
	g.DFS(0);

	cout << endl << "BFS Ž�� = > ";
	g.BFS(0);
}