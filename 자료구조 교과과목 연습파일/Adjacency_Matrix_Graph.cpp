#include <iostream>
#include <vector>
using namespace std;

#define MAX_VTXS	256

class AdjMatGraph
{
protected:
	int						size;
	vector<char>			vertices;
	vector<vector<int>>		adj;
	const int				MAX_SIZE;

public:
	AdjMatGraph() : MAX_SIZE(MAX_VTXS)
	{
		reset();
	}

	AdjMatGraph(int maxSize) : MAX_SIZE(maxSize)
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

		vertices.resize(MAX_SIZE);

		adj.resize(MAX_SIZE);

		for (int i = 0; i < MAX_SIZE; i++)
			adj[i].resize(MAX_SIZE);

		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				setEdge(i, j, 0);
	}
};

int main()
{
	AdjMatGraph g(50);

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
}