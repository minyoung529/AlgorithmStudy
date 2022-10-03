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
