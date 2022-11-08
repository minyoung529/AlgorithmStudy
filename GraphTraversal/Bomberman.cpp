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
			// second-1�� ���� ������ COUNT-1�� �־��ش�
			fields[i][j] = { (str[j] == 'O'), COUNT };
		}
	}

	// �ùķ��̼�
	while (--second)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				// �̹� �湮�ߴٸ� ���� X
				if (visited[i][j])continue;

				
				if (!fields[i][j].first)			// ��ź�� �ƴ϶��
				{
					fields[i][j] = { true, COUNT };	// ��ź���� ������ش�.
				}
				else
				{
					if (--fields[i][j].second == 0)	// ��ź�̰� ���� �ð��� 0�ʶ��
					{
						bomb(i, j);					// ������ ������ �� �������� ������ش�.
					}
				}
			}
		}

		memset(visited, false, sizeof(visited));	// �湮 üũ 2���� �迭 �ʱ�ȭ
	}

	print();
}

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bomb(int y, int x)
{
	visited[y][x] = true;
	fields[y][x] = { false, -1 };

	// ���� ��� �湮
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// ������ �Ѱų�, �湮�߰ų�, �� ������ ��ź�� �� �������� �ٲ����� �ʴ´�
		if (nx < 0 || ny < 0 || nx >= width || ny >= height)continue;
		if (visited[ny][nx] || (fields[ny][nx].second == 1))continue;

		visited[ny][nx] = true;
		fields[ny][nx] = { false, -1 };
	}
}

void print()	// ���
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