[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# Binary Search

이분탐색을 이용해 해결하는 문제들이 있습니다.

<br><br>

</div>

### 1. 숫자 카드 2<br>

<a href="https://www.acmicpc.net/problem/10816">10816. 숫자 카드 2</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/BinarySearch/Number_Card_2.cpp">문제 풀이</a><br>

사실 이분 탐색은 아직은 잘 감이 오지 않아서 어떻게 풀지 몰라 처음에는 배열로 count를 세어 해시로 풀었던 문제이다.

<br>

### 해시로 알고리즘 설계

1. 20000001 크기의 int형 배열을 만들어준다.
   
   * **20000001**: -10000000 ~ 10000000까지이므로 
   
   * int: 각 숫자의 개수를 세야하므로! 

2. 넣을 수를 입력을 받고 `각 숫자+10000000`을 index로 사용해 그 값을 1씩 올려준다.

3. 출력할 수를 입력을 받고 `각 숫자+10000000`을 해시로 사용한다.

4. string으로 각 수를 공백과 넣어서 마지막에 출력한다

### 해시로 짠 코드

```cpp
#include<bits/stdc++.h>
using namespace std;
int arr[20000001];

vector<int> vec;

int main()
{
    string str;
    int cnt, input;
    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        // -10000000 ~ 10000000까지이므로 input에 10000000를 더해준다
        cin >> input;
        input += 10000000;
        arr[input]++;
    }

    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        cin >> input;
        // 해시로 찾기
        str += to_string(arr[input + 10000000]);
        str.push_back(' ');
    }

    cout << str;
}
```

이렇게 해시를 이용해서 풀어봤다. 범위가 그렇게 많지 않아서 가능했다!

<br>

그래도 이분탐색 알고리즘이 써있으니 이분 탐색으로도 한 번 풀어볼까, 하다가 어떻게 해야할지 모르겠어 포기한 문제를 자료구조 시간에 우연히 배웠다!

바로 **upper_bound**와 lower_bound이다.

```
upper_bound => 특정 값을 초과하는 index의 주소값 반환
lower_bound => 특정 값과 같거나 큰 수 중에서 가장 작은 값의 index 주소값 반환
```

이 두 함수 이진탐색으로 구현이 되어있다고 한다.

`upper_bound - lower_bound`를 한다면 해당 원소의 개수를 알 수 있을 것이다.

예시를 보자.

```
1 1 2 2 2 2 4 4 4 4 5 5 5
```

이 수열에서 2의 개수를 알고 싶다면...

```
upper_bound == 6
lower_bound == 2


6-2 = 4
```

2의 개수가 정확하게 나온다!

<br>

3의 개수도 구할 수 있다.

```
upper_bound == 6
lower_bound == 6

6-6 = 0
```

아예 없는 3의 개수 또한 0으로 잘 나오는 것을 볼 수 있다.

### 이분탐색 함수를 이용한 코드

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int len, input;
    vector<int> vec;
    cin >> len;

    for (int i = 0; i < len; i++)
    {
        cin >> input;
        vec.push_back(input);
    }

    // 이분탐색을 하려면 정렬이 필요하다  
    sort(vec.begin(), vec.end());
    cin >> len;

    for (int i = 0; i < len; i++)
    {
        cin >> input;
        // input 초과 주소 - input 크거나 같은 주소  
        cout << upper_bound(vec.begin(), vec.end(), input) - lower_bound(vec.begin(), vec.end(), input) << ' ';
    }
}
```

사실 해시를 이용하면 O(1)로 탐색을 할 수 있어 이분탐색인 O(log N)보다 빠르지만... 함수라도 이분탐색으로 구현해서 뿌듯했다.

앞으로는 이분탐색 함수도 좋지만, 여러 이분탐색 문제들을 직접 구현해나가면서 감을 익혀야겠다!

<br>

<br>

### 게임

<br>

<a href="https://www.acmicpc.net/problem/1072">1072. 게임</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/BinarySearch/Game.cpp">문제 풀이</a><br>





이분 탐색