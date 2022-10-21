[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# Minimum Spanning Tree

그래프 탐색를 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩🟩🟩🟩:black_large_square::black_large_square::black_large_square::black_large_square::black_large_square:<br>
_25%_
<br><br><br>

</div>

### 1. 최소 스패닝 트리    <br>

<a href="https://www.acmicpc.net/problem/1197">1197. 최소 스패닝 트리</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/MinimumSpanningTree/1_Minimum_Spanning_Tree_Kruskal.cpp">문제 풀이 (크루스칼)</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/MinimumSpanningTree/1_Minimum_Spanning_Tree_Prim.cpp">문제 풀이 (프림)</a><br>

![image](https://user-images.githubusercontent.com/77655318/196394412-cbede0a5-f5ae-47a4-ad63-b9b56cc72bb9.png)

자료구조와 알고리즘 시간에 **최소 스패닝 트리** 개념과 **크루스칼**, **프림** 알고리즘을 배워서 풀어본 문제!

크루스칼은 **메모이제이션**을 이용해야 통과가 되었고, 프림은 구현만 해도 통과가 되는 문제였다!

<br>

첫 문제니까... 알고리즘 설명을 해보자 하면

<br>

### 1. 크루스칼

간선들을 **가중치** 기준으로 **오름차순** 정렬해서 선택하는 알고리즘!

쉬워 보이지만, **사이클**이 생기지 않도록 주의해야 한다.

![image](https://user-images.githubusercontent.com/77655318/196395797-89179eb6-17e3-46b4-938d-168d28c27e1c.png)

그래서 선택하면 사이클이 생기는 간선은 제외하고 선택하면 된다.

![image](https://s1.md5.ltd/image/6ba2b746f1df641d0b1f326b15e2a4d3.gif)

[인터넷 페이지](https://intrepidgeeks.com/tutorial/kruskal-algorithm-minimum-spanning-tree-mst)에 크루스칼을 잘 설명하는 GIF가 있어서 가져와봤다.

사이클을 제외하는 게 보인다!!

<br>

### 2. 프림

프림은 **방문했던 정점의 인접한 정점들**의 가중치 중 최솟값을 가진 간선에 방문하는 알고리즘이다.

크루스칼은 모든 간선을 정렬했다면, 인접했던 정점들만을 정렬해 선택한다!

![image](https://velog.velcdn.com/images%2Fhwi_chance%2Fpost%2F52280d0f-4a55-4c1d-95d1-517e585a93c6%2FPrim%20algorithm.gif)

이번에도 [인터넷 페이지](https://velog.io/@hwi_chance/CS-Algorithm-Part.4-Minimum-Spanning-Tree)에 프림을 잘 설명하는 gif가 있어서 가져와봤다.

<br>

나는 첫 문제이고, 자료구조 수행평가를 준비하느라 크루스칼과 프림 알고리즘을 모두 구현해봤다.

### 크루스칼

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parents[1001];

// 간선 
struct Edge
{
    int a, b, w;

    bool operator < (const Edge& e) const
    {
        return w < e.w;
    }
};

//
int find(int v)
{
    vector<int> vec;

    // 최상위 부모 찾기 
    while (v != parents[v])
    {
        vec.push_back(v);
        v = parents[v];
    }

    // 거쳤던 부모들의 부모를  최상위 노드로 
    for (int i : vec)
    {
        parents[i] = v;
    }

    return v;
}

int main()
{
    int vCnt, lCnt;
    long long int result = 0;
    vector<Edge> edges;

    cin >> vCnt >> lCnt;

    // parents 초기화 
    for (int i = 0; i <= vCnt; i++)
        parents[i] = i;

    for (int i = 0; i < lCnt; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        edges.push_back({ a,b,w });
    }

    // 가중치를 기준으로 오름차순 정렬 
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++)
    {
        // fN => N의 최상위 부모 
        int fa = find(edges[i].a), fb = find(edges[i].b);

        // 둘의 부모가 같지 않다면 
        // = 사이클이 생기지 않는다면  
        if (fa != fb)
        {
            // 비용을 증가시키고
            // union
            result += edges[i].w;
            parents[fa] = fb;
        }
    }

    cout << result;
}
```

사이클을 검사할 때는 **union-find** 알고리즘을 사용하였다.

또, **메모이제이션**을 사용하여 **find**할 때 거쳐간 모든 부모들의 부모를 최상위 부모로 만들어주었다!

### 프림

```cpp
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 방문했는지 체크 
bool check[10001];
// 노드들에 각 연결된 노드, 가중치를 저장 
vector<pair<int, int>> nodes[10001];
// 인접했던 노드, 가중치를 저장 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    int vCnt, lCnt, result = 0;
    cin >> vCnt >> lCnt;

    for (int i = 0; i < lCnt; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        // a, b와 연결된 간선을 각각 저장해준다  
        nodes[a].push_back({ w,b });
        nodes[b].push_back({ w,a });
    }

    // 임의의 시작점 
    // pq.top().first => 가중치
    // pq.top().second => 노드 
    pq.push({ 0,1 });

    while (vCnt)
    {
        int cost = pq.top().first;
        int n = pq.top().second;
        pq.pop();

        // 방문하지 않은 노드이면 
        if (!check[n])
        {
            // 방문하고 cost값 올려준다 
            check[n] = true;
            result += cost;
            --vCnt;

            for (int i = 0; i < nodes[n].size(); i++)
            {
                // 방문하지 않은 노드들은 
                if (!check[nodes[n][i].second])
                {
                    // 가중치를 first로 우선순위 큐에 넣어준다 
                    pq.push({ nodes[n][i].first, nodes[n][i].second });
                }
            }
        }
    }

    cout << result;
}
```

처음엔 어렵다고 생각했지만, 꽤 재미있었던 알고리즘이다!
새로운 걸 배운 것 같아서 기쁘다 ^__^

<br>
<br>

### 2. 네트워크 연결<br>

<a href="https://www.acmicpc.net/problem/1922">1922. 네트워크 연결</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/MinimumSpanningTree/2_Connecting_Network.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/196399921-53f08d23-9e53-42a5-976b-8d101062f6ff.png)

단순 최소 스패닝 트리를 구하는 문제!

위 문제처럼 크루스칼이나 프림을 사용하면 된다고 생각해, 좀 더 쓰기 번거롭지 않은 **크루스칼** + 메모이제이션을 이용했다.

**코드**

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parents[1001];

// 간선 
struct Edge
{
    int a, b, w;

    bool operator < (const Edge& e) const
    {
        return w < e.w;
    }
};

// 최상위 부모 찾기 
int find(int v)
{
    vector<int> vec;

    while (v != parents[v])
    {
        vec.push_back(v);
        v = parents[v];
    }

    // 메모이제이션 
    for (int i : vec)
    {
        parents[i] = v;
    }

    return v;
}

int main()
{
    int vCnt, lCnt;
    long long int result = 0;
    vector<Edge> edges;

    cin >> vCnt >> lCnt;

    for (int i = 0; i <= vCnt; i++)
        parents[i] = i;

    for (int i = 0; i < lCnt; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        edges.push_back({ a,b,w });
    }

    // 가중치 기준 오름차순 정렬 
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++)
    {
        int fa = find(edges[i].a), fb = find(edges[i].b);

        // 사이클이 생기지 않는다면
        // 간선 선택  
        if (fa != fb)
        {
            result += edges[i].w;
            parents[fa] = fb;
        }
    }

    cout << result;
}
```

단순하게 최소 스패닝 트리 구현 문제였지만, 다음에는 최소 스패닝 트리를 이용한 응용 문제를 풀어보고 싶다!!!!

<br>
<br>

### 3. 도시 분할 계획<br>

<a href="https://www.acmicpc.net/problem/1647">1647. 도시 분할 계획</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/MinimumSpanningTree/3_City_Division_Plan.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/196988757-1baa5928-3c8e-4656-9e36-63e03dd93191.png)

문제가 길지만... 해석해보면 하나의 최소 신장 트리를 **두 개로 나눴을 때**, 최소 간선의 수를 구하는 것이다.

사실 처음에는 조금 어렵다고 느꼈지만... 

<br>

시각적으로 최소 스패닝 트리를 보니 어떻게 구현해야할지 바로 알 수 있었다!

![image](https://user-images.githubusercontent.com/77655318/196989232-e03fcdbd-1444-4ae9-b2fd-988147007a69.png)

이 트리를 보니, 확실히 알았다.

<br>

이 트리에서 **두 개의 최소 신장 트리로 분할하려면** 어떻게 해야할까?

일단, **간선 하나를 제거**해야할 것이다. 그래야 두 개로 나누어지기 때문에.

<br>

그럼 이젠, **어떤 간선**을 제거해야할까?

답은 간단하다. 합한 가중치가 가장 적어야하기 때문에, **가중치가 가장 큰 간선**을 제거하면 되는 일이다!

<br>

**알고리즘**

1. 크루스칼 알고리즘으로 최소 신장 트리의 간선의 **가중치의 합**을 구한다.

2. 최소 신장 트리의 간선으로 선택된 간선 중, **가장 큰 가중치를 합에서 빼준다**.

**코드**

```cpp
#include<bits/stdc++.h>
using namespace std;

int parents[100001];

struct Edge
{
    int a, b, w;

    bool operator < (const Edge& e) const
    {
        return w < e.w;
    }
};

int find(int v)
{
    vector<int> vec;

    while (v != parents[v])
    {
        vec.push_back(v);
        v = parents[v];
    }

    for (int i : vec)
        parents[i] = v;

    return v;
}

int main()
{
    int vCnt, lCnt;
    int maxVal = 0;
    long long int result = 0;
    vector<Edge> edges;

    cin >> vCnt >> lCnt;

    for (int i = 0; i <= vCnt; i++)
        parents[i] = i;

    for (int i = 0; i < lCnt; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        edges.push_back({ a,b,w });
    }

    // 크루스칼
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++)
    {
        int fa = find(edges[i].a), fb = find(edges[i].b);

        if (fa != fb)
        {
            result += edges[i].w;

            // 가중치 MAX값 구하기
            maxVal = max(maxVal, edges[i].w);
            parents[fa] = fb;
        }
    }

    // 전체 비용 - MAX 가중치
    cout << result - maxVal;
}
```

어려워 보였지만, 조금만 생각하면 답이 나오는 간단한 응용 문제였다!!

재미있었다 `d(^__^)b`

<br>
<br>

### 4. 행성 연결<br>

<a href="https://www.acmicpc.net/problem/16398">16398. 행성 연결</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/MinimumSpanningTree/4_Planet_Connection.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/197072874-cb4662a1-71e8-4505-874c-f1ee16202ab0.png)

갑자기 N x N 행렬이 나와서 당황했지만... 문제를 천천히 알고보니 각 노드들을 서로 서로 잇는 간선의 **가중치**값이 있는 행렬이었고...

이런 구조는 **프림 알고리즘**에서 잘 볼 수 있는 구조이다!

![image](https://user-images.githubusercontent.com/77655318/197073893-37060c9f-98b5-4d5b-bc1c-2f451247d2e4.png)

만약 이런 트리가 있다고 한다면, 프림 알고리즘에서는...

![image](https://user-images.githubusercontent.com/77655318/197073912-7a1c6e31-fff2-46c3-81ad-5f869f0fc874.png)

이렇게 한 노드를 중심으로 연결된 노드와 그 간선의 가중치를 저장해주기 때문에!!

가중치를 저장한 행렬과 비슷하다고 볼 수 있었다.

<br>

그래서 프림 알고리즘을 이용해 풀어봤다.

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

// 가중치를 저장하는 2차원 배열
vector<int> weights[1000];
// 선택했는지 체크하는 배열
bool visited[1000];
long long int result = 0;

int main()
{
    int vCnt;
    cin >> vCnt;

    for (int i = 0; i < vCnt; i++)
    {
        weights[i].resize(vCnt);

        for (int j = 0; j < vCnt; j++)
        {
            cin >> weights[i][j];
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> pQueue;
    pQueue.push({ 0, 0 });

    // 프림 알고리즘
    while (vCnt)
    {
        int cost = pQueue.top().first;
        int node = pQueue.top().second;
        pQueue.pop();

        // 연결되지 않은 노드들만
        if (!visited[node])
        {
            visited[node] = true;
            result += cost;
            vCnt--;

            for (int i = 0; i < weights[node].size(); i++)
            {
                if (!visited[i])
                {
                    pQueue.push({ weights[node][i], i });
                }
            }
        }
    }

    cout << result;
}
```

N x N 2차원 배열이 나와 어려워 보였지만, 사실은 프림 알고리즘에 대한 힌트였고, 그렇게 어렵지 않았던 문제!

<br>
<br>

### 5. 도시 건설<br>

<a href="https://www.acmicpc.net/problem/21924">21924. 행성 연결</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/MinimumSpanningTree/05_City_Building.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/197086728-41cce71c-3b6a-4b2a-8123-7f3d36ea8c3a.png)
![image](https://user-images.githubusercontent.com/77655318/197086745-ef34e9f7-7fe8-4bb2-938b-75ed8e397625.png)

`전체 간선의 가중치 수 - MST의 가중치 합`을 구하는 문제!

쉬워 보이는 문제였다만, 다만... 모든 노드가 연결되어있지 않으면 `-1`을 출력해야 하는 조건 때문에 조금 고민을 했다.

<br>
**알고리즘**

간선의 수가 꽤 많았기 때문에, **프림 알고리즘**을 사용하였다.

모든 노드가 연결되지 않을 때를 처리해주기 위해, 그때 발생하는 일을 확인해보았다.

![image](https://user-images.githubusercontent.com/77655318/197087799-6d835e82-788c-41dc-a58b-036e1fd57351.png)

![image](https://user-images.githubusercontent.com/77655318/197087844-52ca1f8e-0a2d-4037-a4f3-79d30f1c4852.png)

이 줄에서 **top**이 없어서 오류가 났다.

즉, V-1개의 간선을 구하기 전에 **우선순위 큐가 빈다는 것**이다!

<br>

그래서 우선순위 큐 비어있는지 체크해주고, 마지막에 **V-1개의 간선**이 선택되지 않았다면 `-1`을 출력하기로 했다.

<br>

**코드**

```cpp
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> nodes[100001];
bool visited[100001];

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int vCnt, lCnt;
    int temp = 0;
    long long int total = 0, mstSum = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pQueue;
    cin >> vCnt >> lCnt;

    for (int i = 0; i < lCnt; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        nodes[a].push_back({ w,b });
        nodes[b].push_back({ w,a });

        // 모든 간선의 가중치 더함
        total += w;
    }

    pQueue.push({ 0,1 });

    // 프림 알고리즘
    while (vCnt && !pQueue.empty())
    {
        int cost = pQueue.top().first;
        int node = pQueue.top().second;
        pQueue.pop();

        if (!visited[node])
        {
            mstSum += cost;
            vCnt--;
            visited[node] = true;

            for (int i = 0; i < nodes[node].size(); i++)
            {
                if (!visited[nodes[node][i].second])
                {
                    pQueue.push({ nodes[node][i].first, nodes[node][i].second });
                }
            }
        }
    }

    // 모든 노드를 연결하지 못했다면
    if (vCnt > 0)
        cout << -1;
    else
        cout << total - mstSum;
}
```

모든 노드가 연결되지 않은 상태를 체크할 수 있어서 재미있었다! 

---

<div align="center">

## 📒 문제집 외 문제 📒

<br>

</div>