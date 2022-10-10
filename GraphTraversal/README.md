[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# Graph Traversal

그래프 탐색를 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩◼️◼️◼️◼️◼️◼️◼️◼️◼️<br>
_12%_
<br><br><br>

</div>

### 1. 바이러스<br>

<a href="https://www.acmicpc.net/problem/2606">2606. 바이러스</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/1_Virus.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/193617776-ec88ac33-ce1c-44ce-af38-04da423c8805.png)

재귀를 사용한 DFS로 푼 문제.

1부터 시작해서 각 **정점을 방문할 때마다** 변수를 1씩 증가시켜주었다.

<br>

코드는...

```cpp
#include <bits/stdc++.h>
using namespace std;

bool arr[101][101];
bool visited[101];
int cnt, len, answer;

void DFS(int n);

int main()
{
    cin >> cnt >> len;

    while (len--)
    {
        int num1, num2;
        cin >> num1 >> num2;

        arr[num1][num2] = arr[num2][num1] = true;
    }

    DFS(1);
    cout << answer;
}

// DFS
void DFS(int n)
{
    visited[n] = true;

    for (int i = 2; i <= cnt; i++)
    {
        // 방문하지 않았고 연결된 요소를
        if (arr[n][i] && !visited[i])
        {
            DFS(i);
            answer++;
        }
    }
}
```

<br>

![image](https://user-images.githubusercontent.com/77655318/193619133-3043b693-abef-43a0-9b8a-cdda7abcf982.png)

만약 이 코드대로 예제 탐색을 한다면....

```
1
1 2
1 2 3
1 2 3 5
1 2 3 5 6
```

이 순서로 탐색이 될 것이다.

기초적인 그래프 탐색 문제!

<br>

<br>

### 2. DFS와 BFS<br>

<a href="https://www.acmicpc.net/problem/1260">1260. DFS와 BFS</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/2_DFS_And_BFS.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/193619832-158f728d-e10e-4c60-a70b-b5d1375433a6.png)

기초적인 DFS, BFS 문제였다.

DFS는 재귀함수를 사용해서, BFS는 queue를 사용해서 구현했다.

**알고리즘**

> DFS

1. 재귀함수로 start를 매개변수로 넣어 호출한다.

2. 인자로 들어온 start를 방문했음을 bool 배열에서 체크해준다.

3. 1부터 정점의 수까지 방문하지 않았고, 인접한 정점을 재귀함수로 호출해준다.

```cpp
void DFS(int start)
{
    visited[start] = true;
    cout << start << " ";

    for (int i = 1; i <= cnt; i++)
    {
        // 방문하지 않았고 인접한 정점 
        if (arr[start][i] && !visited[i])
        {
            DFS(i);
        }
    }
}
```

<br>

> BFS

1. 함수로 들어온 start를 queue에 넣고, 방문했음을 bool형 배열에서 체크해준다.

2. queue에 top과 인접하고 방문하지 않은 정점을 모두 queue에 넣어주고 pop한다.

3. 2 과정을 queue가 빌 때까지 반복한다.

```cpp
void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 1; i <= cnt; i++)
        {
            // 방문하지 않았고 인접한 정점  
            if (arr[x][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
```

<br>

전체 코드를 보자.

```cpp
#include<bits/stdc++.h>
using namespace std;

bool arr[1001][1001];
bool visited[1001];

void DFS(int start);
void BFS(int start);
int cnt, len, start;

int main()
{
    cin >> cnt >> len >> start;

    while (len--)
    {
        int num1, num2;
        cin >> num1 >> num2;

        arr[num1][num2] = arr[num2][num1] = 1;
    }

    DFS(start);
    cout << endl;

    // 초기화
    fill_n(visited, 1001, false);
    BFS(start);
}

void DFS(int start)
{
    visited[start] = true;
    cout << start << " ";

    for (int i = 1; i <= cnt; i++)
    {
        // 방문하지 않았고 인접한 정점 
        if (arr[start][i] && !visited[i])
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 1; i <= cnt; i++)
        {
            // 방문하지 않았고 인접한 정점  
            if (arr[x][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
```

기본에 맞게 구현한 것 같다. 그래프 탐색은 항상 재미있다!

<br>

<br>

### 4. 쉬운 최단 거리<br>

<a href="https://www.acmicpc.net/problem/14940">14940. 쉬운 최단 거리</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/4_Easy_Shortest_Path.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/194865666-dd746957-5216-4b07-9fe4-282eb07bbff0.png)

모든 지점까지의 최단경로를 구하는 문제.

전에 풀었던 토마토 문제와 미로 찾기 문제처럼 BFS를 사용해서 푸는 문제이다.

<br>

**알고리즘**

1. 시작 위치를 queue에 넣는다.

2. queue가 빌 때까지 while문을 돌린다.

3. queue의 top에 사방에 인접해있는 것들이 방문되지 않은 곳이고, 갈 수 있는 길이라면 queue에 넣는다.

4. 사방을 탐색했다면, queue를 pop한 다음에 다음 좌표를 사방으로 탐색해준다.

그림으로 보자면...

![제목 없음f](https://user-images.githubusercontent.com/77655318/194868291-dd6bfd8c-433c-474f-849b-60d2b7d372fb.png)

문제에 나온 장애물이나 -1을 출력하는 건 넣지 않았지만... 아무튼 기본 최단 거리 알고리즘이다.

<br>

코드로 보자!!

```cpp
#include<bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

int field[1000][1000];
int visited[1000][1000];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
    FASTIO;
    int width, height;
    queue <pair<int, int>> q;

    cin >> height >> width;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cin >> field[y][x];

            if (field[y][x] == 2)
            {
                // 시작 블록이면 queue에 넣고 방문 처리
                q.push({ y, x });
                visited[y][x] = 1;
            }
        }
    }

    // BFS
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        // 사방 검사
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
            if (visited[ny][nx] != 0 || field[ny][nx] == 0) continue;

            // 전에 있던 블록 + 1
            // 길이 연장
            visited[ny][nx] = visited[y][x] + 1;

            q.push({ ny, nx });
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (field[y][x] > 0)
            {
                // 갈 수 있고 방문한 길은 그냥 출력
                if(visited[y][x])
                    cout << visited[y][x] - 1 << ' ';

                // 갈 수 있지만 방문하지 못한 길은  -1 출력
                else
                    cout << - 1 << ' ';
            }
            else
                cout << 0 << ' ';
        }
        cout << '\n';
    }
}
```

재밌는 문제였다!!

BFS에서 최단거리를 구하는 아이디어는 항상 신기하고 멋지다 @^__^@

<br>
<br>

### 9. 토마토<br>

<a href="https://www.acmicpc.net/problem/1260">1260. DFS와 BFS</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/9_Tomato.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/193796207-f3d82da0-4b70-4a69-a6db-5514eef4eb1b.png)

토마토 전염병이 모두 퍼지는 최소 일수를 구하는 문제.

자료구조 시간에 배웠던 BFS로 풀 수 있었다. 

<br>

**알고리즘 설계**

1. 입력받을 때 이미 익은 토마토의 좌표`(y, x)`를  queue에 넣어준다.
   
   이 때 **익지 않은 토마토의 전체 개수**를 센다.

2. queue가 empty가 될 때까지 현재 queue의 top에 인접한 좌표`(사방)`에 토마토들을 모두 익은 상태로 만들어준다.
   
   이 때 토마토들을 방문할 때 **가장 중앙 토마토**의 값 + 1을 대입해주고 queue에 넣어준다.
   
   그리고 익힌 토마토의 개수를 센다.

3. queue가 empty라면, 처음에 구했던 익지 않은 토마토의 전체 개수와 익힌 토마토의 개수가 같은지 확인한다.
   
   **같지 않다면, 모든 토마토를 익히지 못한 것!**
   
   같다면 토마토 배열에 있는 값의 최댓값 - 1을 출력한다! (최단거리)

<br>

https://www.acmicpc.net/problem/2178

배열의 값을 중앙+1로 하는 아이디어는 미로 탐색 문제를 풀 때를 이용했다!

<br>

**코드**

```cpp
#include<iostream>
#include<queue>
using namespace std;

int width, height;

// 토마토 
int field[1000][1000];
// 방문 체크 배 
bool visited[1000][1000];

int curTomato, tomatoSum = 0;

// 사방 
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

queue<pair<int, int>> q;

void Tomato(int x, int y);


int main()
{
    int answer = 0;
    cin >> width >> height;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cin >> field[y][x];
            visited[y][x] =열 false;

            // 익혀야하는 토마토 저장 
            if (field[y][x] == 0) tomatoSum++;
            // 이미 익은 토마토는 queue에 넣어준다 
            else if (field[y][x] == 1) q.push({ x,y });
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 익은 토마토이고 방문하지 않았을 때 
        if (field[y][x] > 0 && !visited[y][x])
        {
            Tomato(x, y);
        }

        answer = field[y][x];
    }

    // 익혀야하는 토마토를 익히지 못했을 때 -1 
    if (tomatoSum == curTomato)
    {
        cout << answer - 1;
    }
    else
    {
        cout << -1;
    }
}

void Tomato(int x, int y)
{
    visited[y][x] = true;

    // 사방 검사 
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;

        // 방문하지 않았고 익지 않았다면 
        if (!visited[ny][nx] && field[ny][nx] == 0)
        {
            curTomato++;
            field[ny][nx] = field[y][x] + 1;
            q.push({ nx, ny });
        }
    }
}
```

재밌는 BFS 문제였다!!

<br>

<br>

### 10. 토마토<br>

<a href="https://www.acmicpc.net/problem/7569">7569. 토마토</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/10_Tomato_2.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/193973596-8fd6e5d4-107a-4cff-a76e-c4b7f952855d.png)

지난번에 푼 토마토 판이 3D가 된 문제. 

메인 로직은 별로 차이가 없었고, **y와 x뿐만이 아니라 z값**까지 queue에 보관해주었다. 인접해있는 사방뿐만이 아니라 **위 아래**까지 비교했다. 

<br>

> 비교 배열

```cpp
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

>>

int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1, 0,-1,0,0,0 };
int dz[6] = { 0, 0,0,0,1,-1 };
```

>  비교 코드

```cpp
void Tomato(pos position)
{
    for (int i = 0; i < 6; i++)
    {
        pos nPos = position;
        nPos.d += dz[i];
        nPos.h += dy[i];
        nPos.w += dx[i];

        if (nPos.d < 0 || nPos.h < 0 || nPos.w < 0) continue;
        if (nPos.d >= depth || nPos.h >= height || nPos.w >= width)continue;

        if (visited ELEMENT(nPos) || field ELEMENT(nPos) != 0) continue;

        field ELEMENT(nPos) = field ELEMENT(position) + 1;
        q.push(nPos);
        curTomato++;
    }
}
```

<br>

**전체 코드**

```cpp
#include<bits/stdc++.h>
using namespace std;
// 쓰기 귀찮아서 Define 처리... 
#define ELEMENT(p)    [p.d][p.h][p.w]

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
```

<br>

처음엔 어려울까봐 무서웟지만, 2차원 토마토와 로직이 비슷하니 정말 쉽게 풀 수 있었다. 엄청 재미있었던 탐색 문제!!!

<br><br>

---

<div align="center">

## 📒 문제집 외 문제 📒

<br>

</div>

### 숨바꼭질<br>

<a href="https://www.acmicpc.net/problem/1697">1697. 숨바꼭질</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/Hide_And_Seek.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/194364961-99bed391-bb46-4d13-ac0f-a6ec9b88c71b.png)

BFS를 사용해서 푼 문제! 보자마자 BFS라고 생각했지만... 작은 실수들 때문에 메모리가 초과되거나 틀렸던 문제이다.

<br>

DFS로 탐색하지 않은 이유는  **+1**을 DFS로 하고 0에서 100000까지 간다고 하면 처음부터 100000개의 수를 거쳐야 하기 때문이다.

한 문장으로 비효율적이라는 이야기!

<br>

**알고리즘 설계**

1. queue에 `{ start, 0 }`을 넣어준다.

2. queue가 빌 때까지 반복문을 돌려준다.
   
   `first => 현재 수, second => 연산 횟수`
   
   queue에 `{ queue.top().first + 1, queue.top().second + 1 }`을 삽입한다.
   queue에 `{ queue.top().first - 1, queue.top().second + 1 }`을 삽입한다.
   queue에 `{ queue.top().first * 1, queue.top().second + 1 }`을 삽입한다.

3. queue의 top이 도착지점과 같다면 top의 second(연산 횟수)를 출력한다.

<br>

코드는

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<pair<int, int>> queue;
    int start, target, answer = 0;;
    cin >> start >> target;

    queue.push({ start, 0 });

    while (!queue.empty())
    {
        pair<int, int> pair = queue.front();

        if (pair.first == target)
        {
            break;
        }

        queue.pop();

        if (pair.first + 1 <= target)
        {
            queue.push({ pair.first + 1, pair.second + 1 });
        }
        if (pair.first - 1 <= target)
        {
            queue.push({ pair.first - 1, pair.second + 1 });
        }
        if (pair.first * 2 <= target)
        {
            queue.push({ pair.first * 2, pair.second + 1 });
        }
    }

    cout << queue.front().second;
}
```

나름 깔끔하게 짰다고 생각했는데 구멍 투성이인 코드였다.

놓친 부분을 정리해보자면...

<br>

1. queue에 **중복값**이 들어오는 경우 (메모리 초과의 이유!!)

2. **큰 좌표 > 작은 좌표**를 고려하지 않은 것

<br>

이 부분을 고려하여 코드를 새로 짜봤다.

```cpp
#include<bits/stdc++.h>
using namespace std;

bool arr[100001];

int main()
{
    queue<pair<int, int>> queue;
    int start, target, answer = 0;;
    cin >> start >> target;

    // first > 현재 값, second > 연산 횟수
    queue.push({ start, 0 });

    while (!queue.empty())
    {
        pair<int, int> pair = queue.front();

        arr[pair.first] = true;

        // 찾았다면 종료
        if (pair.first == target)
        {
            break;
        }

        queue.pop();

        // 큰 > 작은일 땐 실행 X
        if (pair.first <= target && !arr[pair.first + 1] && start < target)
        {
            queue.push({ pair.first + 1, pair.second + 1 });
        }

        if (pair.first - 1 >= 0 && !arr[pair.first - 1])
        {
            queue.push({ pair.first - 1, pair.second + 1 });
        }

        // 큰 > 작은일 땐 실행 X
        // +1 이유: -1을 할 수 있는 범위를 만드려고!!
        if (pair.first * 2 <= target + 1 && !arr[pair.first * 2] && start < target)
        {
            queue.push({ pair.first * 2, pair.second + 1 });
        }
    }

    cout << queue.front().second;
}
```

중복값을 제거하는 아이디어가 곧바로 생각나서 다행이었다!
재미있었던 문제 ^__^!!!!
