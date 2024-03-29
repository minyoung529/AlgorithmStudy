[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# Graph Traversal

그래프 탐색를 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩◼️◼️◼️◼️◼️◼️◼️◼️<br>
_25%_
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

### 4. 효율적인 해킹<br>

<a href="https://www.acmicpc.net/problem/1325">1325. 효율적인 해킹</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/5_Effective_Hacking.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/195346284-efb7d1d8-2f0a-4f40-a851-dc5652aecd93.png)

DFS로 풀자고 생각한 문제! 

DFS는 그렇다 치고... `10000 * 10000`의 인접 행렬로 구현하려고 했지만... 메모리를 너무 많이 쓰는 것도 같고 탐색할 때 시간이 오래 걸릴 것 같아서 **vector의 배열**로 만들어주었다.

신뢰하는 컴퓨터의 번호만 넣어주는 vector이다.

<br>

**알고리즘 설계**

1. A와 B 컴퓨터를 받을 때, B번째 vector에 A를 넣어준다.

( B가 신뢰하는 컴퓨터가 A라는 뜻 )

2. 1번부터 컴퓨터의 수까지 **DFS**를 돌린다.

3. vector에 있는 노드를 방문하지 않았다면, count를 1씩 늘리고 **다시 그 노드의 컴퓨터 번호가 신뢰하는, 즉 연결되어있는 노드**들을 탐색해준다.

4. DFS 함수는 연결되어있는 모든 노드들을 탐색한 후 **해킹한 컴퓨터 수를 반환**한다.

5. **최댓값**을 뽑아내어 해당 컴퓨터 번호들을 **배열로 묶고** 출력한다.

<br>

알고리즘 설계를 제대로 쓰지 못한 것 같은데... 코드를 보면 바로 이해가 된다.

<br>

**코드**

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> maxes;
vector<int> m[10001];
bool visited[10001];

int DFS(int n)
{
    int count = 0;
    visited[n] = true;

    for (int i = 0; i < m[n].size(); i++)
    {
        int node = m[n][i];

        // 해킹하지 않은 곳만 방문
        // 해킹할 때마다 count를 올린다
        if (!visited[node])
        {
            count += DFS(node);
            count++;
        }
    }

    // 최종 해킹 횟수 반환
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int cnt, len, maxValue = 0;
    cin >> cnt >> len;

    for (int i = 0; i < len; i++)
    {
        int a, b;
        cin >> a >> b;

        m[b].push_back(a);
    }

    for (int i = 1; i <= cnt; i++)
    {
        int temp = DFS(i);

        if (maxValue <= temp)
        {
            // 최댓값 구하기
            if (maxValue < temp)
            {
                maxValue = temp;
                maxes.clear();
            }

            // 최대 배열에 넣는다
            maxes.push_back(i);
        }

        fill_n(visited, 10001, false);
    }

    for (int i : maxes)
        cout << i << ' ';
}
```

결과는 성공이었지만!! 

아무래도 비효율적인 것 같아서... 메모이제이션을 이용해서 구현해보았다.

```cpp
void DFS(int n)
{
    visited[n] = true;

    for (int i = 0; i < m[n].size(); i++)
    {
        int node = m[n][i];

        if (!visited[node])
        {
            if (memo[node] == 0)
            {
                DFS(node);
                temp++;
            }
            else
            {
                temp += memo[node];
            }
        }
    }

    if (memo[n] != 0)
        memo[n] = temp;
}
```

결과는 더 느려졌다...
왜일까...??

<br>

아무튼 더 좋은 코드를 위해서 맞았지만 계속 노력해서 뿌듯했다. 재밌는 문제!

<br>
<br>

### 6. 단지번호붙이기<br>

<a href="https://www.acmicpc.net/problem/1325">2667. 단지번호붙이기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/6_Numbering_Apartment_Complex.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/195350703-24e9f0a3-8dce-4c3b-9160-f48d25a0b7cd.png)

아무래도 [유기농 배추](https://www.acmicpc.net/problem/1012)를 풀고 나니 이런 DFS 문제는 수월하게 풀 수 있었다.

<br>

**알고리즘 설계**

1. 입력이 붙어있기 때문에 **string**으로 받아 각각 2차원 배열에 '0'이면 false, '1'이면 true를 대입해준다.

2. 2차원 배열을 (0,0)부터, (N-1, N-1)까지 순회한다. (2중 반복문)
   
    이때, **방문되지 않았고 좌표의 값이 1**이면 **DFS 함수**를 호출한다.

3. DFS는 매개변수로 받은 지역 주위의 **사방**을 검사한다. 각 방향의 좌표가 방문되지 않았고 좌표의 값이 1이면 **DFS를 재귀 호출**해준다.
   
    **방문할 때마다 count**를 올려** 마지막에 반환**해준다.

4. 반환된 값은 **우선순위 큐**에 삽입한다.

5. 탐색이 끝나면, 우선순위 큐의 **사이즈**와 같이 우선순위 큐가 빌 때까지 **top**을 출력하고, pop을 한다.

<br>

**코드**

```cpp
#include<bits/stdc++.h>
using namespace std;

bool field[25][25];
bool visited[25][25];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int len;

priority_queue<int, vector<int>, greater<int>> pQueue;

int DFS(int y, int x);

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    cin >> len;

    for (int i = 0; i < len; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < len; j++)
        {
            field[i][j] = (str[j] == '1');
        }
    }

    // DFS
    for (int y = 0; y < len; y++)
    {
        for (int x = 0; x < len; x++)
        {
            if (!visited[y][x] && field[y][x])
            {
                // 방문 횟수를 우선순위 큐에 넣음
                pQueue.push(DFS(y, x));
            }
        }
    }

    // 사이즈 출력
    cout << pQueue.size() << '\n';

    // 우선순위 큐 요소 출력
    while (!pQueue.empty())
    {
        cout << pQueue.top() << '\n';
        pQueue.pop();
    }
}

int DFS(int y, int x)
{
    int count = 1;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= len || nx >= len) continue;

        if (field[ny][nx] && !visited[ny][nx])
        {
            // 방문 횟수를 센다
            count += DFS(ny, nx);
        }
    }

    return count;
}
```

count를 재귀 안에서 세는 아이디어는 항상 좋은 것 같다. 재미있는 문제였다!

<br>
<br>

### 8. 쉬운 최단 거리<br>

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

<br>
<br>

### 13. 숨바꼭질 3<br>

<a href="https://www.acmicpc.net/problem/13549">13549. 숨바꼭질 3</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/13_Hide_And_Seek_3.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/197342489-6868aeec-a3ab-42d2-8afe-884b75b0a656.png)

기존 숨바꼭질에서 조건 하나만 바뀐 문제. `2 * X`로 순간 이동할 때 1초가 아닌 **0초** 걸리는 것으로 바꿨다.

기존 코드에서 `2*x`하는 부분과 min값을 구하는 부분만 수정하면 되어서 쉬웠다.

```cpp
#include<iostream>
#include<queue>
using namespace std;

#define MAX 100000
bool visited[100001];
int start, endV, answer = 10000000;

void set(int f, int s, queue<pair<int, int>>& q)
{
    if (f < 0 || f > MAX || visited[f]) return;

    visited[f] = true;
    q.push({ f , s });
}

int main()
{
    cin >> start >> endV;

    queue<pair<int, int>> q;
    q.push({ start, 0 });

    if (start >= endV)
    {
        cout << start - endV;
        return 0;
    }

    while (!q.empty())
    {
        pair<int, int> top = q.front();

        // 찾았다면 종료  
        if (top.first == endV)
        {
            answer = min(top.second, answer);
        }

        q.pop();

        if (top.first != 0)
            set(top.first * 2, top.second, q);

        set(top.first - 1, top.second + 1, q);
        set(top.first + 1, top.second + 1, q);
    }

    cout << answer;
}
```

재미있는 BFS 문제였다!!

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

<br>

며칠 뒤에 중복되는 코드가 너무 많아서... 함수로 빼어서 코드를 좀 더 깔끔하게 바꾸었다.
메모이제이션도 사용해서 중복되는 숫자를 줄였다.

```cpp
#include<iostream>
#include<queue>
using namespace std;

#define MAX 100000
bool visited[100001];
int start, endV, answer = 0;

void set(int f, int s, queue<pair<int, int>>& q)
{
    if (f < 0 || f > MAX || visited[f]) return;

    visited[f] = true;
    q.push({ f , s });
}

int main()
{
    cin >> start >> endV;

    queue<pair<int, int>> q;

    q.push({ start, 0 });

    if (start < endV)
    {
        while (!q.empty())
        {
            pair<int, int> top = q.front();

            // 찾았다면 종료  
            if (top.first == endV)break;
            q.pop();

            // 1초 후에 좌표 변경 
            set(top.first + 1, top.second + 1, q);
            set(top.first - 1, top.second + 1, q);
            set(top.first * 2, top.second + 1, q);
        }
    }
    else
    {
        cout << start - endV;
        return 0;
    }

    cout << q.front().second;
}
```

더 깔끔하게 고친 것 같아서 기분이 좋다 `^__^`!!!!

<br>
<br>

### 경쟁적 전염<br>

<a href="https://www.acmicpc.net/problem/18405">18405. 경쟁적 전염</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/Competitive_Contagion.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/194364961-99bed391-bb46-4d13-ac0f-a6ec9b88c71b.png)
![image](https://user-images.githubusercontent.com/77655318/195989035-e5add5e3-0448-48d2-ada8-8d351a1eb307.png)

나 BFS로 풀어주세요!! 라고 외치고 있는 문제... 친히 BFS로 풀어주었다.

<br>

처음 생각한 알고리즘은...

1. (0,0)부터 (n,n)까지 **차례대로 바이러스인지 검사**를 한다.

2. `좌표(x, y), 바이러스 번호, 감염된 날`을 queue에 넣어준다.
   
   새로 감염된 아이를 queue에 넣어줄 때 중앙에 있는 기존 바이러스(queue.top())의 **감염된 날 + 1**을 넣어주었다.

3. queue의 top의 날이 S day가 넘어간다면 전염을 중지했다. 즉, while문을 나갔다.

4. field[x-1][y-1]에 있는 상태를 출력한다.

<br>

다만... 문제를 잘 안 읽은 나는... 코드를 다 쓰고 제출을 하고서야

![image](https://user-images.githubusercontent.com/77655318/195989131-a0ee6d9a-d038-4049-a984-87d93ac33a12.png)

이 조건을 읽게 되었다.

<br>

그래서 while과 pair과 queue를 사용한 기존 코드에서, struct와 priority_queue를 사용했다. 우선 순위 큐를 사용할 때는 감염된 날짜를 먼저, 그 다음에 감염 번호대로 정렬해주었다.

<br>

**코드**

```cpp
#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int field[200][200];

struct virus
{
    int y, x, virus, day;

    // 날짜순, 바이러스 번호 순으로 정렬
    bool operator>(const struct virus& v) const
    {
        if (day == v.day)
            return virus > v.virus;

        return day > v.day;
    }
};

priority_queue<virus, vector<virus>, greater<virus>> q;

int main()
{
    int n, k, x, y, s;
    cin >> n >> k;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            int v;
            cin >> v;
            field[y][x] = v;

            if (v > 0)
            {
                q.push({ y,x,v,1 });
            }
        }
    }

    cin >> s >> x >> y;

    // BFS
    while (!q.empty())
    {
        // s day가 지나면 전염을 멈춘다
        if (q.top().day > s) break;

        virus front = q.top();
        q.pop();

        // 사방으로 인접한 요소들을 전염시킨다
        for (int i = 0; i < 4; i++)
        {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n || field[ny][nx] > 0) continue;

            field[ny][nx] = front.virus;

            q.push({ ny, nx, front.virus, front.day + 1 });
        }
    }

    cout << field[x - 1][y - 1];
}
```

재미있었던 문제 ^~^
이제 연산자 오버로딩에 익숙해진 것 같아서 기분이 좋다!!

<br>
<br>

### MooTube (Silver)<br>

<a href="https://www.acmicpc.net/problem/15591">15591. MooTube (Silver)</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/MooTube.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/200039345-2e23d3c0-bf7b-4b7e-8b21-e93f43f59312.png)

유사도란 말에 겁먹었지만... 사실은 가중치라고 표현해도 무방할 정도였다.

또 겁먹은 것은,

```
존은 임의의 두 쌍 사이의 동영상의 USADO를 그 경로의 모든 연결들의 USADO 중 최솟값으로 하기로 했다.
```

이 최솟값이라는 말이었다. 최솟값과 N-1... 스패닝 트리를 생각했지만, 예제와 출력을 보니 없어도 될 듯한 말이라서 불안하지만 저 조건을 제외하고 풀었다.

스패닝 트리를 탐색하고, **조건에 맞지 않는다면 탐색을 즉시 중단**하는 문제이므로 **BFS**로 구현해 조건에 맞지 않는다면 queue에 노드를 넣지 않는다는 아이디어로 출발했다.

<br>

### 알고리즘 설계

1. 2개의 노드와 유사도를 입력받고 서로가 연결되어있는 노드임을 체크한다 (삽입).

2. Q번 BFS 탐색을 한다.

3. BFS 탐색을 하는 동안, Enque할 때마다 카운트를 하나씩 세준다.

4. 탐색이 끝난 다음에 카운트를 출력한다.

<br>

문제가 장황하고 긴 것에 비해서 기본적인 탐색이라 진이 빠졌다...

<br>

### 코드

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

struct node
{
    int a; ull w;
};

// index에 연결된 노드를 모아놓는 변수
vector<node> arr[5001];

int main()
{
    int vCnt, lCnt;
    cin >> vCnt >> lCnt;

    for (int i = 0; i < vCnt - 1; i++)
    {
        int a, b;
        ull w;
        cin >> a >> b >> w;

        // 양방향 간선
        arr[a].push_back({ b,w });
        arr[b].push_back({ a,w });
    }

    for (int i = 0; i < lCnt; i++)
    {
        // BFS
        bool visited[5001];
        fill_n(visited, 5001, false);

        queue<int> q;
        int target, count = 0;
        ull usado;

        // 처음 탐색할 노드를 queue에 넣는다
        cin >> usado >> target;
        q.push(target);

        // queue가 빌 때까지
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // 탐색하지 않은 곳이라면 => 탐색
            if (!visited[node])
            {
                visited[node] = true; // 방문했음을 체크

                // 인접한 노드들을 모두 탐색
                for (int j = 0; j < arr[node].size(); j++)
                {
                    if (arr[node][j].w >= usado)
                    {
                        int n = arr[node][j].a;

                        // 방문하지 않았다면 enque & count++
                        if (!visited[n])
                        {
                            q.push(n);
                            count++;
                        }
                    }
                }
            }
        }

        cout << count << endl;
    }
}
```

아 맞다. 앞으로 문제를 풀고 푼 코드의 시간 복잡도를 써보려고 한다. 많은 문제의 시간을 줄이는 데 도움이 될 것 같아서...

이 코드의 시간 복잡도는 `Q개의 테스트케이스` + `인접 행렬로 구현한 BFS`이므로 `O(Q*N)`이다. 앞으로 시간 복잡도를 쓰는 걸 습관 들여야지!!

<br>
<br>

### 봄버맨<br>

<a href="https://www.acmicpc.net/problem/16918">16918. 봄버맨</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/Bomberman.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/200587700-255be799-092e-4e80-a87c-c15182ed2df6.png)
![image](https://user-images.githubusercontent.com/77655318/200587795-e6df8280-9079-473b-8fde-9b9eb2cfd2f2.png)

그래프 탐색을 이용해서 푼 문제이다. 

사실 문제 하단에 있는 힌트를 잘 살펴보면, 일정한 규칙이 있다는 것을 알 수 있었다.

```
.......
...O...
....O..
.......
OO.....
OO.....

<초기 상태, 1초 후>

OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO

<2초 후>

OOO.OOO
OO...OO
OOO...O
..OO.OO
...OOOO
...OOOO

<3초 후>

OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO

<4초 후>

.......
...O...
....O..
.......
OO.....
OO.....

<5초 후>
```

1초 후에는 폭탄이 잠잠한 상태이다가, 2초 후에 터지고 또 잔잔한 상태이다가... 를 반복한다.

2개의 2차원 배열을 써서 그래프 탐색을 하지 않을 수 있었지만, 아무래도 요즘에 그래프 탐색을 안 한 것 같아 탐색으로 풀어보았다.

<br>

## 알고리즘 설계

1. 2차원 배열을 만들어 폭탄인지 아닌지 입력받는다.

2. 폭탄이라면 2차원 배열에 true와 `3-1`을 넣어준다.
* 3-1인 이유: 후에 반복문을 second번이 아닌 `second-1`번 돌기 때문에 초기값은 `3-1 = 2`일이다.
3. second-1번 반복문을 돈다.
* 폭탄이라면 현재 초를 1씩 깎아준다.
    => 1씩 깎았을 때 남은 시간이 0초라면, 인접한 폭탄들을 빈 영역으로 만들어준다.
    => 이때 인접 지역 중 방문하지 않은 지역만 방문한 다음 **방문했음을 체크**해준다.

* 그렇지 않다면 빈 영역을 폭탄으로 만들어주고 **3초**를 저장한다. (후에 3초 뒤에 터지도록)

* 위 두 행동 모두 **이미 방문한 지역에 대해서는 실행하지 않는다**.
4. 반복문이 끝난 후 2차원 배열의 값이 true면 폭탄을, 아니면 빈 공간을 출력한다.

<br>

알고리즘 설계를 쓸 땐 항상 내가 어휘력이 부족하다는 것을 느낀다.

코드를 보기 전 정리하자면, 2차원 배열은 pair로 이루어져 있어 bool값과 int값이 있다.

```
bool => 폭탄인지 아닌지
int => 남은 폭발 시간
```

N-1번 반복문을 돌며 위 알고리즘 설계처럼 시뮬레이션해주는 코드이다.

## 코드

```cpp
#include<iostream>
using namespace std;

#define COUNT    3

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
            fields[i][j] = { (str[j] == 'O'), COUNT - 1 };
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


                if (!fields[i][j].first)            // 폭탄이 아니라면
                {
                    fields[i][j] = { true, COUNT };    // 폭탄으로 만들어준다.
                }
                else
                {
                    if (--fields[i][j].second == 0)    // 폭탄이고 남은 시간이 0초라면
                    {
                        bomb(i, j);                    // 인접한 곳들을 빈 공간으로 만들어준다.
                    }
                }
            }
        }

        memset(visited, false, sizeof(visited));    // 방문 체크 2차원 배열 초기화
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

void print()    // 출력
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
```

길고 썩 예쁘지는 않은 코드이지만...

나름 그래프 탐색을 써서 구현을 해서 기분은 좋다 ㅎ_ㅎ 내일은 다익스트라를 완전히 마스터해서 최단경로 문제들을 많이 풀어보고 싶다!!

<br>
<br>

### 저울<br>

<a href="https://www.acmicpc.net/problem/10159">10159. 저울</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/Scale.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/200838333-5be8408f-348f-4998-bfce-6ddf457e64c9.png)

사실 문제를 보고 나서도 그래프 탐색일 거라는 상상은 절대 못했지만...

![image](https://user-images.githubusercontent.com/77655318/200838497-83683732-242c-43bb-8efe-1ac5c6bf95e5.png)

예제가 너무 그래프 탐색 같이 생겨서 한 번 그래프 탐색으로 풀어보자고 생각한 문제였다.

<br>

그리고 진짜 문제는 여기였다. 어떻게 그래프를 만들고, 어떤 탐색을 해야 할까?

그리고 나는 세 문자의 대소 관계를 알 수 있는 경우와 없는 경우를 나누고 그래프로 나타내보기로 했다.

![image](https://user-images.githubusercontent.com/77655318/200839028-4d82d145-6a88-4554-8f4c-96eb26685dcc.png)

n, m, p를 통하여 대소 관계를 알 수 있는 경우, 없는 경우를 정리해보았다.

m, p가 **n과의 대소 관계가 같다면** 대소 관계를 알 수 없는 것을 알아내었다.

<br>

이때 `n > m`을 `n -> m`으로 생각해 n이 m을 가리키고 있다고 생각해본다면... 전자(대소 관계 알 수 없을 때)의 경우

![image](https://user-images.githubusercontent.com/77655318/200839476-726aab4b-af25-4a7c-addd-bed994e0383b.png)

이러한 그래프가 그려진다. m과 p는 연결되어있지 않으므로 대소 관계가 없음이 입증된다!

후자의 경우는 어떨까?

![image](https://user-images.githubusercontent.com/77655318/200840310-44681a80-fff1-470c-a725-586009d77a3b.png)

세 수 모두 연결이 잘 되는 걸 확인할 수 있다!!!!

<br>

그래서 `전체 정점 개수 - 연결 되어있는 정점 개수`를 출력하기로 했다. 코드를 짜고 예제를 실행해보는데 올바른 정답이 나오지 않는 것이다 ㅠ_ㅠ

따라서 예제의 그래프도 한번 그려보았다.

![image](https://user-images.githubusercontent.com/77655318/200843778-d96623f0-cc2a-400c-8490-d491273bc60f.png)

예제에서 2번째 노드가 대소 관계를 모르는 노드는 5와 6이다. 3과 4 사이에 연결되어있는 간선이 2를 향해있지 않으므로 둘의 대소 관계는 모르게 되는 것이다!!

따라서 탐색을 할 때, 정방향을 선택했다면 계속 정방향만, 역방향이라면 계속 역방향만. 이렇게 두 번 탐색을 해주어야 한다는 것을 알게 되었다!!

<br>

### 알고리즘 설계

1. N과 M의 대소 관계를 입력받고 인접 행렬로` arr[N][M]`이 `N->M`으로 연결되어있음을 표시한다.

2. 1부터 정점의 개수까지 반복문을 돈다.
* 이때 DFS로 **대소 관계를 알 수 있는 정점의 개수**를 구할 것이다.

* DFS를 호출할 때 정방향으로 탐색하는지의 여부에 따라 인자를 달리해 두 번 호출해준다.
3. DFS에서는 매개변수로 들어온 정점을 방문했음을 표시해준다.
* 현재 설정된 방향으로 연결되어있는 정점을 DFS로 재귀 호출해준다.
4. `전체 정점의 개수 - DFS를 호출한 값 + 1`을 각 정점마다 출력한다.
* +1을 하는 이유는 자기 자신의 대소 관계는 알기 때문이다.

<br>

### 코드 설계

```cpp
#include<iostream>
#include<vector>
using namespace std;

bool arr[2001][2001];
bool visited[2001];
void DFS(int v, bool fromTo);
int vCnt, lCnt, answer = 0;

int main()
{
    cin >> vCnt >> lCnt;

    for (int i = 0; i < lCnt; i++)
    {
        int from, to;
        cin >> from >> to;

        arr[from][to] = true;
    }

    for (int i = 1; i <= vCnt; i++)
    {
        // 정방향, 역방항 화살표를 모두 계산
        DFS(i, true); DFS(i, false);

        // +1 => 자기 자신의 대소관계는 알기 때문에
        cout << vCnt - answer + 1 << '\n';

        fill_n(visited, vCnt+1, false);
        answer = 0;
    }
}

// v => 방문한 정점
// fromTo => 정방향 화살표인지 역방향 화살표인지
void DFS(int v, bool fromTo)
{
    visited[v] = true;
    answer++;

    for (int i = 1; i <= vCnt; i++)
    {
        // 정방향은 정방향으로만, 역방향은 역방향으로만
        // 방문하지 않은 곳만 간다
        if (!visited[i] && ((fromTo && arr[v][i]) || !fromTo && arr[i][v]))
        {
            DFS(i, fromTo);
        }
    }
}
```

구현은 어렵지 않았지만, 아이디어 부분에서 많이 애를 먹었던 문제이다...

이런 문제는 나오면 바로 바로 생각해낼 수 있도록, 문제의 조건과 핵심을 잘 분석해야겠다는 생각이 들었다.

<br>
<br>

### 조이스틱<br>

<a href="https://school.programmers.co.kr/learn/courses/30/lessons/42860">42860. 조이스틱</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/GraphTraversal/Joystick.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/203694458-442f8788-9b13-415c-b9a6-e8a017282735.png)

조이스틱의 최소 움직임을 구하는 문제였다. 

![image](https://user-images.githubusercontent.com/77655318/203694373-67fc82b2-3701-41e9-9540-fb529f2d5c72.png)

그리디라며... 그리디라며!!!!!!!

그리디 문제답게 단순히 순간의 최소 움직임이 최적해가 될 거라고 생각했지만... 테스트케이스는 그리디로 산출한 최적해만을 쓰지 않는 모양이었다... ㅠ_ㅠ

아니면 내 로직이 문제에서 이야기한 그리디가 아니었거나......

<br>

### 그리디로 푼 (풀진 못한) 알고리즘 설계

0. A가 아닌 모든 요소들의 index를 diff 배열에 넣어준다! 

1. 0부터 시작해 해당 문자를 A로 바꾸는 최소움직임을 계산한다.
   
    계산한 값은 answer에 더해준다.
   
    **계산 방법**
   
   1. 직선상의 거리
      
      ```
      return abs(from-to)
      ```
   
   2. 돌아가는 거리
      
      ```
      return max - abs(from-to))
      ```
      
      직선상의 거리는 수직선에서 점과 점 사이의 거리를 구할 때와 동일하다.
      
      돌아가는 거리는...
      
        ![image](https://user-images.githubusercontent.com/77655318/203696583-50575caf-b7fe-42c1-b7db-43440c520d43.png)
      
        `A + MAX - B`는 A와 B의 대소관계에 영향을 받는 식이므로, `MAX - abs(from - to)`를 이용해 계산했다.
      
      A부터 Z까지를 구하는 것이므로, `0('A')부터 해당 문자 - 'A'`의 길이를 구해주는 방법을 사용하였다. MAX는 알파벳의 개수인 26개로! 

2. 해당 문자에서 다음 문자로 가는 최소 움직임을 계산한다.

    최소 움직임을 계산한 요소는 배열에서 없애주고 새로 갈 곳을 구해야 한다!!!

    최소 움직임 계산 또한 위 로직과 똑같았다. 
    
    algorithm 헤더의 sort 함수를 이용해서 diff 배열에 있는 요소들 중 현재 index에서 최단거리 오름차순으로 정렬했다.
    
    새로 갈 곳은 diff[0]이고, 현재에서 diff[0]까지의 거리를 answer에 추가한다.

3. 1~2를 diff 배열이 없어질 때까지 반복해준다면 최소 움직임이 나오게 된다!!

<br>

라고 생각했지만... 테스트 케이스도 잘 통과가 된 코드인데 77점을 맞았다... 아무래도 내가 뭘 놓친 것 같아서 꼼꼼하게 확인해봤는데도...!!!!

그렇게 고민 중이었는데 미리 이 문제를 푼 친구가 **"뒤로 갔다가 도로 돌아가는 경우가 있다"** 는 말에... 테스트케이스를 찾아보았다.

<br>

```
ABABAAAAABA
```

바로 이 테스트 케이스이다! 내 코드대로 한다면 같은 거리라도 왼쪽이 아닌 **오른쪽**으로 갔다.

이 테스트 케이스를 오른쪽으로 갔다가 (돌아간다가) 다시 왼쪽으로 간다면 11번 이동하지만,

왼쪽으로 갔다가 오른쪽으로 간다면 10번 이동하게 된다!!!!

<br>

그래서 위 알고리즘에서 DFS를 이용해 최단 거리가 같을 경우 모두 탐색해주는 알고리즘을 설계하였다.

<br>

### 알고리즘 설계

1. A가 아닌 모든 요소들의 index를 diff 벡터에 넣어준다!

2. 함수를 돌린다. (재귀)
   
   * 현재 위치를 매개변수로 받아 (초깃값 0) A를 만드는 최소 움직임을 구해 매개변수로 받은 sum에 더한다.
   
   * 현재 자리가 A가 아니었고, 배열이 비어있지 않다면 매개변수로 받은 diff 배열에서 현재 위치를 나타내는 요소를 삭제한다.
     
     ```
     A가 아니어야 하는 이유: A는 diff 배열에 애초에 넣어주지 않았기 때문에!
     ```
   
   * diff가 비어있다면, 재귀를 종료한다. 이때, answer과 sum을 비교해 더 작은 값을 answer에 넣어준다.
     (최소값을 구해야 하기 때문)
   
   * 현재 위치와 가장 가까운 거리를 기준으로 diff 배열을 오름차순 정렬한다.
   
   * diff 배열의 첫번째, 마지막 요소를 각각 재귀의 매개변수로 놓고 돌린다.

<br>

코드를 말로 설명하기 어려워서 자세히 설명하지는 못했는데, 코드를 보면 잘 이해할 것이다.

<br>

### 코드

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
#define DIST(x)    getdist(x, index, name.size())
using namespace std;

int answer = 400;
string name;

// 최소 이동거리 구하기
int getdist(int from, int to, int max)
{
    return min(abs(from - to), max - abs(from - to));
}

// diff        > A가 아닌 숫자들의 인덱스를 모아놓은 배열
// index    > 현재 위치
// sum        > 총 이동 횟수
// difidx    > 현재 위치의 diff vector 인덱스 값
void func(vector<int> diff, int index = 0, int sum = 0, int difidx = 0)
{
    sum += getdist(0, name[index] - 'A', 26);    // 알파벳 경로 구하기

    if (name[index] != 'A' && !diff.empty())    // A가 아니고 (diff에 있고), 비어있지 않을 때
    {
        diff.erase(diff.begin() + difidx);
    }

    if (diff.empty())    // 재귀 종료
    {
        answer = min(answer, sum); return;
    }

    // 정상 거리 경로(돌아가기 X) 오름차순 정렬
    sort(diff.begin(), diff.end(), [index](int a, int b)
        { return abs(index - a) < abs(index - b); });

    func(diff, diff.front(), sum + DIST(diff.front()));                    // 최단경로
    func(diff, diff.back(),  sum + DIST(diff.back()), diff.size() - 1);    // 최장경로 ( 돌아가는 최단거리 )
}

int solution(string n)
{
    vector<int> diff;
    name = n;

    for (int i = 0; i < n.size(); i++)
    {
        if (name[i] != 'A')
        {
            diff.push_back(i);
        }
    }

    func(diff);

    return answer;
}
```

나름 간단하게 DFS로 재귀를 이용해 잘 짠 것 같다!

<br>

문제를 풀면서, **여러가지 테스트 케이스**를 생각하는 게 정말 중요하다고 느꼈다. 또, 단순 **알고리즘 분류에만 너무 의존하지 않는 것**이 좋을 것 같다.

 그리디라는 문제의 카테고리만 보고 문제를 푸는 것은... 정말 그릇되었다고 생각한다...

<br>

카테고리 없이 나와도 모든 테스트 케이스를 만족시킬 수 있도록 빅데이터를 많이 쌓고 성장해나가야겠다. 카테고리가 전부가 아니다!!!

**네 빅데이터와 실력만을 믿어야 해 이민영!!!!**
