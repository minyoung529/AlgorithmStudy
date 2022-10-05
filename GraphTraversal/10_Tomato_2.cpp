#include<bits/stdc++.h>
using namespace std;
// 쓰기 귀찮아서 Define 처리... 
#define ELEMENT(p)	[p.d][p.h][p.w]

struct pos { int d, h, w; };

void Tomato(pos);

// 전방좌우상하 모두 비교 
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1, 0,-1,0,0,0 };
int dz[6] = { 0, 0,0,0,1,-1 };

int width, height, depth, curTomato = 0, tomatoSum = 0, answer = 0;
int field[100][100][100];
bool visited[100][100][100];
queue<pos> q;

int main()
{
	cin >> width >> height >> depth;

	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < height; j++)
		{
			for (int k = 0; k < width; k++)
			{
				pos temp = { i,j,k };
				cin >> field ELEMENT(temp);

				if (field ELEMENT(temp) == 1)
					q.push(temp);

				else if (field ELEMENT(temp) == 0)
					tomatoSum++;
			}
		}
	}

	while (!q.empty())
	{
		pos pos = q.front();

		if (field ELEMENT(pos) > 0 && !visited ELEMENT(pos))
		{
			Tomato(pos);
		}

		q.pop();
		answer = field ELEMENT(pos);
	}

	if (curTomato == tomatoSum)
		cout << answer - 1;
	else
		cout << -1;
}

void Tomato(pos position)
{
	for (int i = 0; i < 6; i++)
	{
		pos nPos = position;
		nPos.d += dz[i];
		nPos.h += dy[i];
		nPos.w += dx[i];

		// 영억을 넘으면 방문 X 
		if (nPos.d < 0 || nPos.h < 0 || nPos.w < 0) continue;
		if (nPos.d >= depth || nPos.h >= height || nPos.w >= width)continue;

		// 방문했거나 익지 않은 토마토가 아니면 방문 X 
		if (visited ELEMENT(nPos) || field ELEMENT(nPos) != 0) continue;

		field ELEMENT(nPos) = field ELEMENT(position) + 1;
		q.push(nPos);
		curTomato++;
	}
}
