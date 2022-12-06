//#include<iostream>
//#include<queue>
//using namespace std;
//
//int field[8][8];
//bool visited[8][8];
//int dx[4] = { 0, -1, 0, 1 };
//int dy[4] = { 1, 0, -1, 0 };
//
//struct virus
//{
//	int x, y, day;
//};
//
//int main()
//{
//	int height, width;
//	int curDay = 0, curWall = 0;
//	queue<virus> q;
//	cin >> height >> width;
//
//	// 입력
//	for (int i = height; i < height; i++)
//	{
//		for (int j = width; j < width; j++)
//		{
//			cin >> field[i][j];
//
//			if (field[i][j] == 2)
//				q.push({ j, i, 0 });
//		}
//	}
//
//	while (!q.empty())
//	{
//		virus v = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = v.x + dx[i];
//			int ny = v.y + dy[i];
//
//			if (nx < 0 || ny < 0 || nx >= width || ny >= height || visited[ny][nx]) continue;
//
//			if (curWall < 3 && field[ny][nx] != 1)	// 현재가 벽이 아니고 만들 벽이 3개 이상 남아있으면
//			{
//				curWall++;
//			}
//			else
//			{
//
//			}
//		}
//	}
//}