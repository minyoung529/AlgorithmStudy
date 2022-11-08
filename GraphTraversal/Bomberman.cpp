#include<iostream>
using namespace std;

#define COUNT	3

// key => isBomb, value => remain second
pair<bool, int> fields[200][200];
int width, height, second;
bool visited[200][200];
void bomb(int y, int x);
void print();

int main()
{
	cin >> height >> width >> second;

	for (int i = 0; i < height; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < width; j++)
		{
			// second-1번 돌기 때문에 COUNT-1을 넣어준다
			fields[i][j] = { (str[j] == 'O'), COUNT };
		}
	}

	// 시뮬레이션
	while (--second)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				// 이미 방문했다면 실행 X
				if (visited[i][j])continue;

				
				if (!fields[i][j].first)			// 폭탄이 아니라면
				{
					fields[i][j] = { true, COUNT };	// 폭탄으로 만들어준다.
				}
				else
				{
					if (--fields[i][j].second == 0)	// 폭탄이고 남은 시간이 0초라면
					{
						bomb(i, j);					// 인접한 곳들을 빈 공간으로 만들어준다.
					}
				}
			}
		}

		memset(visited, false, sizeof(visited));	// 방문 체크 2차원 배열 초기화
	}

	print();
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bomb(int y, int x)
{
	visited[y][x] = true;
	fields[y][x] = { false, -1 };

	// 인접 노드 방문
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 범위를 넘거나, 방문했거나, 곧 폭발할 폭탄은 빈 공간으로 바꿔주지 않는다
		if (nx < 0 || ny < 0 || nx >= width || ny >= height)continue;
		if (visited[ny][nx] || (fields[ny][nx].second == 1))continue;

		visited[ny][nx] = true;
		fields[ny][nx] = { false, -1 };
	}
}

void print()	// 출력
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			char c = (fields[i][j].first) ? 'O' : '.';
			cout << c;
		}
		cout << endl;
	}
}