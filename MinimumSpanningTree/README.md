[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# Minimum Spanning Tree

그래프 탐색를 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩◼️◼️◼️◼️◼️◼️◼️◼️<br>
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

---

<div align="center">

## 📒 문제집 외 문제 📒

<br>

</div>