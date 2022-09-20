//#include<iostream>
//using namespace std;
//
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { 1,0,-1,0 };
//int arr[100][100];
//bool visited[100][100];
//
//int maxCount = 0, answer = 0;
//
//int n;
//void DFS(int height, int y, int x);
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//
//	for (int h = 1; h <= 100; h++)
//	{
//		fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
//
//		for (int y = 0; y < n; y++)
//		{
//			for (int x = 0; x < n; x++)
//			{
//				if (!visited[y][x] && arr[y][x] > h)
//				{
//					DFS(h, y, x);
//					maxCount++;
//				}
//			}
//		}
//
//		if (answer < maxCount)
//			answer = maxCount;
//
//		maxCount = 0;
//	}
//
//	cout << answer;
//}
//
//void DFS(int height, int y, int x)
//{
//	visited[y][x] = true;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
//		if (arr[ny][nx] <= height || visited[ny][nx]) continue;
//
//		DFS(height, ny, nx);
//	}
//}