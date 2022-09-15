[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# 자료구조 교과과목 연습

학교 수업인 '자료구조와 알고리즘' 시간에 해결했던 문제들이 있습니다.<br><br><br>

</div>

### 1. i love c++<br>

![ILOVEC](https://user-images.githubusercontent.com/77655318/187949276-902da374-5952-4ad2-9ac7-ba1a328335da.png)

처음엔 자료 구조 Queue나 Deque를 써서 **push_front**를 무조건적으로 해주어야 한다고 생각했다. 그래서 string을 **queue**나 **deque**로 옮길까 생각을 하기도 했다.

<br>

하지만, 곰곰이 생각해보니 string에는 **erase**라는 함수가 있고, 이걸로 맨 앞에 있는 문자를 지울 수 있다는 생각이 들었다.

<br>

그래서 설계한 알고리즘! <br>

1. 공백을 포함한 문자열을 입력 받는다.

2. 문자열의 길이만큼 반복문을 돌린다

3. 반복문 안에서는 먼저 문자열의 가장 앞 문자를 넣어준다.
   `ex) i love c++i`

4. 가장 첫번째 문자를 지워준다. (erase 함수 사용)

<br><br>

이 알고리즘으로 짜본 코드는~

```cpp
for (int i = 0; i < s.size(); i++)
{
    s.push_back(s.front());
    s.erase(s.begin());

    cout << s << endl;
}
```

간단한 생각의 단순하고 강한 힘을 알 수 있었다!
<br><br>

### 2. 숫자 문자열과 영단어<br>

<a href="https://school.programmers.co.kr/learn/courses/30/lessons/81301">숫자 문자열과 영단어 문제</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0%20%EA%B5%90%EA%B3%BC%EA%B3%BC%EB%AA%A9%20%EC%97%B0%EC%8A%B5%ED%8C%8C%EC%9D%BC/Number_String_And_English_Word.cpp">문제 풀이</a><br>

<img src = "https://user-images.githubusercontent.com/77655318/187950338-4b8912f0-d6a6-45da-a9df-16e45d520e82.png" width = "400">

문자열을 숫자로 치환하는 문제.<br>

map을 사용하여 각 숫자와 문자를 저장해주었으며, regex_replace를 사용해 문자열을 숫자로 대체하면 된다고 생각했다.<br>

```cpp
map<string, string> map = { {"0", "zero"}, {"1", "one"}, ...}
```

그래서 생각한 알고리즘 설계는...

<br>

1. 위처럼 문자와 숫자를 묶은 **map**을 만든다.
   `ex) key => “0”, value => “zero”`

2. i가 **0부터 9**가 될 때까지 반복문을 돌린다.

3. **i를 string**으로 바꿔 **맵의 키**로 쓰고, 그 값을 저장한다.
   `ex) string value = pair[to_string(i)];`
   `value == “zero”, “one”...`

4. 저장한 값을 숫자로 **대체**한다. (regex_replace 사용)

<br>

그런데 생각해보니... 인덱스대로 값이 정해지므로, 굳이 해시를 쓸 필요가 없었다! 바보...

<br>

최종 코드는...

```cpp
string pair[] =
{
    "zero", "one", "two", "three", "four" , "five", "six" ,"seven", "eight", "nine"
};

for (int i = 0; i < 10; i++)
{
    // value = "zero", "one"...
    string value = pair[i];

    // s 안이 모든 value를 숫자 문자열로 치환
    // ex) "zero" => "0", "one" => "1"...
    s = regex_replace(s, regex(value), to_string(i));
}

return stoi(s);
```

regex_replace를 이용해서 간단하게 풀 수 있었다. 문자열에 관련된 함수를 알아놓고 적재적소에 사용할 수 있게끔 공부해야겠다.

<br><br>

### 3. 신규 아이디 추천<br>

<a href="https://school.programmers.co.kr/learn/courses/30/lessons/72410">신규 아이디 추천 문제</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0%20%EA%B5%90%EA%B3%BC%EA%B3%BC%EB%AA%A9%20%EC%97%B0%EC%8A%B5%ED%8C%8C%EC%9D%BC/New_ID_Recommendation.cpp">문제 풀이</a><br>

각 단계에 따라 사용자의 id를 고쳐야 하는 문제이다. 차근차근 단계를 구현해나가고 문자열에 대한 깊은 이해가 필요할 것 같았다.

<br>

![image](https://user-images.githubusercontent.com/77655318/187952464-7a8bf212-0096-4cc8-a295-f0f13efdc3e9.png)
![image](https://user-images.githubusercontent.com/77655318/187952523-abef3edb-d6cf-4cb8-9fb0-483f7ff79807.png)

> 복잡하고 아름다운 문자열나라...

<br>

차근차근 단계별로 풀어보자!

<br>

1. **모든 영어 문자를 소문자로 치환한다.**

transform이라는 함수를 이용해서 해결했다. 요긴한 코드이다.

```cpp
transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
```

<br>

2. **정해진 문자가 아닌 문자들을 삭제한다.**

조건에 맞는 문자인지, 아닌지 판별하기 위해서 그 기능을 하는 함수를 따로 빼주었다.

```cpp
bool Check(char c)
{
    return!(isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.');
}
```

반복문을 돌려 문자마다 이 함수로 조건문을 써주었고, **True**를 반환했다면 해당 문자를 지워주었다.

<br>

3. **반복문을 이용해 연속된 ‘.’를 하나의 ‘.’로 치환한다.**

간단하게 반복문을 써서 연속된 마침표가 있는지 확인했고, 만약 있으면 그 중 하나를 지워주었다.

```cpp
for (int i = 1; i < new_id.length(); i++)
{
    if (new_id[i] == '.' && new_id[i - 1] == '.')
    {
        new_id.erase(new_id.begin() + i);
        i--;
    }
}
```

<br>

4. **마침표가 문자열 끝에 있다면 제거한다.**

간단한 조건문으로 문자열의 back과 front를 확인하고, 만약 마침표라면 erase 함수를 호출해 제거해주었다.

```cpp
if (new_id.front() == '.')
    new_id.erase(new_id.begin());

if (new_id.back() == '.')
    new_id.pop_back();
```

<br>

5. **빈 문자열이라면 “a”를 대입한다.**

문자열에 있는 empty 함수를 이용해 비어있는지 체크해주었고, 간단히 a를 대입했다.

```cpp
if (new_id.empty())
    new_id = "a";
```

<br>

6. **문자열의 길이가 16자 이상이면 자른다.**
   이때, 문자열의 마지막이 ‘.’이라면 마지막을 제거한다.

<br>

while문을 써서 길이가 16자 이상일 때 pop_back을 해 가장 뒤 문자를 제거했다.

```cpp
while (new_id.size() >= 16)
{
    new_id.pop_back();
}
```

마침표 제거도 pop_back으로 해주었다.

```cpp
if (new_id.back() == '.')
{
    new_id.pop_back();
}
```

<br>

7. **문자열의 길이가 2자 이하라면 3까지 연장한다.**

while문을 써서 길이가 2자 이하일 때만 문자열의 back()을 하나씩 연장해주었다.

```cpp
while (new_id.size() < 3)
{
    new_id += new_id.back();
}
```

<br> <br>

험난한 대장정... 각 단계 자체는 그렇게 어렵지 않았지만, 많은 조건이 모여있으니 답을 확인할 때 어디가 틀렸는지 디버깅이 되지 않아 답답하고 꽤 애먹었던 문제이다.

<br>

그래도 엄청 엄청 재밌었던 문제!

<br><br>

### 3. 미로 탐색<br>

<a href="https://www.acmicpc.net/problem/2178">미로 탐색 문제</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0%20%EA%B5%90%EA%B3%BC%EA%B3%BC%EB%AA%A9%20%EC%97%B0%EC%8A%B5%ED%8C%8C%EC%9D%BC/Search_Maze.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/189790393-6a0d3527-88cd-4ef1-ab81-d6384b24af98.png)

<br>

**문제 풀이 시간**
20분 (선생님의 코드의 빈칸만 채움)

<br>

**문제 분석**

최단거리를 구해야 하므로, BFS 탐색을 해야한다고 생각했다. BFS 탐색은 while문과 queue를 쓰고, 탐색을 하며 (N, M)까지의 거리를 저장해야 한다.

<br>

**알고리즘 설계**

1. 입력을 받을 때 string으로 입력 받고, 문자로 쪼갠다.

2. 처음 queue에 x, y 좌표를 입력한다.
   
   이때, 시작 위치가 **(0,0)** 이므로 pair 변수로 {0, 0}을 넣는다.

3. BFS 탐색을 한다.
   
   이때, 인접한 정점을 모두 queue에 넣을 때는 queue의 front()에 **사방 좌표**를 탐색한다. 사방을 탐색할 때 범위를 넘어가지 않도록 검사한다.
   
   또, 방문하지 않았고, 값이 1인 정점만 간다.
   
   정점을 넣을 때는 (0,0)부터의 거리를 넣는다.

4. (N, M)의 거리를 출력한다.

<br>

**코드**

```cpp
#include<iostream>
#include<queue>
using namespace std;

const int MAX = 100;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m, a[MAX][MAX], visited[MAX][MAX], y, x;

int main()
{
    cin >> n >> m;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            a[i][j] = temp[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({ 0, 0 });

    while (q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위 체크
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            // 방문하지 않고, 1인 길만 탐색한다
            if (visited[ny][nx] > 1 || a[ny][nx] == 0)
                continue;

            // 거리를 저장한다
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }

    cout << visited[n - 1][m - 1];
    return 0;
}
```

<br>

**새로 알게된 것**

BFS에 대해 깊은 이해를 하게 되었다. 또, 사방을 체크하는 방식에 조금이나마 익숙해질 수 있었고 범위 체크, 예외 처리를 하는 것을 배울 수 있었다.

<br><br>

### 4. 유기농 배추 <br>

<a href="https://www.acmicpc.net/problem/1012">유기농 배추 문제</a>

<br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0%20%EA%B5%90%EA%B3%BC%EA%B3%BC%EB%AA%A9%20%EC%97%B0%EC%8A%B5%ED%8C%8C%EC%9D%BC/Organic_Cabbage.cpp">문제 풀이</a>

<br>

![image](https://user-images.githubusercontent.com/77655318/190311152-b30c3c52-63c0-4a57-b953-55735cf30f61.png)

<br>

**문제 풀이 시간**
20분 (선생님의 코드의 빈칸만 채움)

<br>

**문제 분석**
배추흰지렁이는 이어져있는 양배추는 모두 가므로, 처음 양배추를 발견할 때마다 필요한 배추흰지렁이 값을 올려주고, 인접 양배추들을 발견한다. 밭을 탐색하면서 이것을 반복하면 된다.

<br>

**알고리즘 분석**

1. 밭을 탐색하며 발견되지 않은 양배추를 발견한다.

2. 양배추를 발견하면 필요한 흰지렁이 값을 올려주고, DFS 탐색으로인근 양배추를 발견한다.

3. 1~2를 반복한다.

<br>

**코드**

```cpp
#include<iostream>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int width, height, cnt, answer = 0;

int field[51][51];
bool visited[51][51] = { false, };

void DFS(int y, int x);

int main()
{
    int testCnt;
    cin >> testCnt;

    while (testCnt--)
    {
        // 초기화
        fill_n(field[0], 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        answer = 0;

        cin >> width >> height >> cnt;

        for(int i = 0; i < cnt; i++)
        {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                // 발견한 적 없는 양배추를 탐색
                if (!visited[i][j] && field[i][j] == 1)
                {
                    answer++;
                    DFS(i, j);
                }
            }
        }

        cout << answer << endl;
    }
}

// DFS 탐색으로 인접 양배추를 찾는다
void DFS(int y, int x)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx > width || ny > height) continue;

        // 양배추가 있으면서 발견하지 않은 양배추만 탐색
        if (field[ny][nx] == 1 && !visited[ny][nx])
        {
            DFS(ny, nx);
        }
    }

    return;
}
```

<br>

**새로 알게 된 점**

DFS에 대한 더 깊은 이해를 할 수 있게 되었다. fill_n, fill 등 초기화 함수를 알게 되었다.
