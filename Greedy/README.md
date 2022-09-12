[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# Greedy

Greedy(탐욕 알고리즘)를 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩🟩🟩🟩⬛⬛⬛⬛⬛<br>
_59%_
<br><br><br>

</div>

### 1. 거스름돈<br>

<a href="https://www.acmicpc.net/problem/14916">14916. 거스름돈</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/1_Change.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/188650025-49a1167e-708a-4009-9784-53304c1cb217.png)

간단한 그리디 문제였다. <br>

동전이 2원, 5원 있는데 동전을 최소로 주는 방법을 구하는 것이다.

```cpp
while (change >= 2)
{
    if (change >= 5)
    {
        if ((change - 5) % 5 != 0)
            change -= 2;
        else
            change -= 5;
    }
    else
        change -= 2;

    count++;
}
```

이러한 로직을 짰다. <br>

13이 거스름돈이라고 하면 순서대로 2, 2, 2, 2, 5!<br>
20이면 5, 5, 5, 5!

<br><br>

### 2. 폴리오미노<br>

<a href="https://www.acmicpc.net/problem/1343">1343. 폴리오미노</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/2_Polyomino.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/188649922-019084d7-84ea-4dc0-84d4-7d8bf5fe9e75.png)

간단한 그리디 문제였다. <br>

그래도 한번에 코드를 짜지는 못했는데, 내가 했던 실수는...

```cpp
if (count == 2)
{
    result += "BB";
    count = 0;
}
else if (count == 4)
{
    result += "AAAA";
    count = 0;
}
```

반복문 안에 넣어주었던 코드의 일부이다.

```
input
XXXXXX
```

```
output
=> BBBBBB
answer
=> AAAABB
```

**count가 2가 될 때 가장 먼저 체크**해주고 초기화해주므로 AAAA가 나오지 않는 것이다. 바꿔준 코드는

```cpp
// count가 2이면서
// 마지막 i이거나
// 다음 문자가 '.'일 때
if (count == 2 && ((i == input.size() - 1) || (i + 1 < input.size() && input[i + 1] == '.')))
{
    result += "BB";
    count = 0;
}
else if (count == 4)
{
    result += "AAAA";
    count = 0;
}
```

**마지막 문자가 i**라는 조건은

```
input
=> XX
```

```
answer
=> BB
```

를 충족시키기 위해 넣었고, **다음 문자가 '.'이라는 조건은**

```
input
=> XXXXXX.XX.XXXX
```

```
answer
=> AAAABB.AAAA
```

를 충족시키기 위해 넣었다. '.'이 될 때 2인지 먼저 확인하는 것. <br><br>

-1이 나올 조건은 **'.'이 나왔을 때 count가 2나 4가 아니**거나 **마지막에 count가 0이 아닐 때**이다.

<br><br>

### 3. 로프<br>

<a href="https://www.acmicpc.net/problem/2217">2217. 로프</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/3_Rope.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/188649765-ab7af6ae-8542-4784-a5ef-7fafac472bb2.png)

그리디에 대한 이해를 도와준 문제!<br>

지금까지는 그리디 문제가 어색하고 감이 잘 잡히지 않았는데, 점점 그리디 문제를 풀어보니 완벽하지는 않지만... 그래도 감을 잡은 것 같다. <br>
임의로 선택된 줄들이 버틸 수 있는 **최대 무게**를 계산하기 위해...

```cpp
sort(weights.begin(), weights.end(), greater<int>());
```

먼저 **내림차순**으로 정렬해주었다. 내림차순으로 정렬한 이유는 반복문으로 계산할 때 **증가하는 index** 값인 i와 **맞추기** 편리했기 때문. 그 반복문은...

```cpp
for (int i = 0; i < weights.size(); i++)
{
    // 버티는 최대 무게는 (무게/개수) =>
    // 최솟값 * 개수 
    int value = weights[i] * (i + 1);

    if (value > result)
    {
        result = value;
    }
}
```

이렇게 된다. 시뮬레이션을 돌리면

```
input => 3    5 9 1

// 정렬
=> 9 5 1

// 반복문
// 0   result = 9
// 1   reulst = 10 (MAX!)
// 2   result = 3

// answer
=> 10
```

전체 로직은 이렇다. 간단하지만 재미있는 문제였다!

<br>
<br>

### 4. 주유소

<br>

<a href="https://www.acmicpc.net/problem/13305">13305. 주유소</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/4_Gas_Station.cpp">문제 풀이</a>
<br>

![image](https://user-images.githubusercontent.com/77655318/188649689-5c5c8dce-63a0-4ecc-9df2-e54d8f27f595.png)

또 작은 실수 때문에 한참을 고민한 그리디 문제...

<br>

알고리즘을 생각하기까지는 오랜 시간이 걸리지 않았지만, 생각한 알고리즘을 코드로 옮기는 데에 문제가 생겼다. **알고리즘 단계를 완벽하게 글로 적었어야 했는데**... 나의 알량한 머리를 믿다가 쓰지 않은 조건문 하나에 오랜 시간을 헤맸다.

<br>

전체적인 알고리즘은 이렇다.

![image](https://user-images.githubusercontent.com/77655318/188652594-8ca24bfc-a3fd-4b56-8180-37592f86b346.png)

열심히 그려왔다.

<br>

정리하자면, 당장 기름이 급하다면 **다음 도시로 갈 때까지의 기름**을 넣는다. 그때, 다음, 다다음... 주유소와 가격 비교를 해서 현재 주유소보다 **적은 가격을 가진** 주유소까지 갈 거리(Km)를 현재 도시에서 미리 기름(L)을 넣는다.

<br>

코드로 보자면...

<br>

```cpp
for (int i = 0; i < len - 1; i++)
{
    int buyCount = 0;

    // 당장 기름이 없으면 다음 거리까지 충전
    while (curOil + buyCount < distances[i])
        buyCount++;

    // 미리 충전을 해놓은 상태에서 굳이 더 저렴한 가격을 찾을 필요 없으므로
    // 미리 충전을 해놓지 않았다면...
    if (buyCount != 0)
    {
        for (int j = i + 1; j < len - 1; j++)
        {
            // 가장 금액이 적은 주유소가 나올 때까지
            // N리터 충전
            if (costs[i] <= costs[j])
                buyCount += distances[j];

            // 내가 한 실수다... break 빼먹기...
            else break;
        }
    }

    cost += ((unsigned long long)costs[i] * buyCount);
    curOil += buyCount;
    curOil -= distances[i];
}
```

이렇게 된다.

<br>

사실, **unsigned long long**도 써본 적이 거의 없는데, 아주 큰 범위가 나올 때마다 자동적으로 쓸 수 있게 익숙해져야겠다.

<br>

조금 어려웠지만, 할만하고 재미있는 문제였다. 각오해라 그리디... 조건반사처럼 문제를 완벽하게 풀 날을 기대해라...

<br>
<br>

### 5. 알바생 강호

<br>

<a href="https://www.acmicpc.net/problem/1758">1758. 알바생 강호</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/5_Part_Timer_Kangho.cpp">문제 풀이</a>
<br>

![image](https://user-images.githubusercontent.com/77655318/188755705-9662c3f2-7d0d-427e-a61f-d889599552be.png)

문제는 정렬로 쉽게 풀 수 있었다.

<br>

등수가 올라갈수록 팁이 깎이는 가격이 늘어나므로 **가장 큰 팁을 줄 손님의 팁을 보존**해야 한다고 생각했다. 따라서 팁을 많이 줄 사람의 등수가 작야아하는 것이다.

<br>

처음엔 정렬 코드 그 한 줄을 쓰기 귀찮아서... **multiset**을 썼더니 시간 초과가 났다. next 함수 때문일 가능성도 있다.

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL);  cin.tie(NULL);

    multiset<int, greater<int>> tips;
    int len;
    long long int kanghoTip = 0;

    cin >> len;

    for (int i = 0; i < len; i++)
    {
        int input;
        cin >> input;
        tips.insert(input);
    }

    for (int i = 0; i < len; i++)
    {
        // 가장 큰 것부터
        int tip = *next(tips.begin(), i) - i;

        if (tip < 0) tip = 0;
        kanghoTip += tip;
    }

    cout << kanghoTip;
}
```

<br>

슬픈 마음으로 **우선순위 큐**로 구현을 해봤다.

```cpp
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL);  cin.tie(NULL);

    priority_queue<int> tips;

    //...

    for (int i = 0; i < len; i++)
    {
        int tip = tips.top() - i;
        tips.pop();

        if (tip < 0) tip = 0;
        kanghoTip += tip;
    }

    cout << kanghoTip;
}
```

이번에도 예제는 맞았지만, 결과는 틀렸습니다... 나는 이제야 내 알고리즘은 틀린 게 없다는 것을 알게 되었다.

<br>

틀린 이유는 자료형 때문...

```cpp
N은 100,000보다 작거나 같은 자연수이다.
팁은 100,000보다 작거나 같은 자연수이다.
```

이 조건이라면 한계값으로 테스트했을 때  `100000 * ((100000 - 0) + (100000 - 1) + + (100000 - 2)...)` 형태로 나올 것이다. 그렇게 되면 얻는 팁이 int 범위를 넘어서게 되므로 
**long long int**를 써주어야 하는 것이었다. 자료형을 늘려주니 바로 통과.

<br>

그리고 우선순위 큐를 쓰는 것보다 vector와 알고리즘 헤더의 sort 함수를 쓰는 게 더 빨라서 최종 제출은 vector로 했다.

```cpp
    vector<int> tips;

    //...

    sort(tips.begin(), tips.end(), greater<int>());

    for (int i = 0; i < len; i++)
    {
        int tip = tips[i] - i;

        if (tip < 0) tip = 0;
        kanghoTip += tip;
    }

    cout << kanghoTip;
```

한계값을 정말로 테스트할 수는 없지만, 머릿속으로라도 테스트해서 내 코드의 결점을 발견하는 습관을 들여야겠다. 

<br>
<br>

### 6. 2+1 세일

<br>

<a href="https://www.acmicpc.net/problem/11508">11508. 2+1 세일</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/5_2+1_Sale.cpp">문제 풀이</a>
<br>

![image](https://user-images.githubusercontent.com/77655318/188772704-f6c2c677-cd08-4ffe-9a5a-8ae9570c2f05.png)

앞 문제와 같이, 정렬과 가까운 문제였다. 

<br>

처음에 구상한 알고리즘은

1. 가격들이 모두 있는 배열을 내림차순으로 정렬한다.

```
 (9 8 7) (6 5 4) 3 2
```

2. 인덱스대로 3개씩 묵어 첫번째와 두번째 값만 더해준다.

```
 (9 8 7) (6 5 4) 3 2
 result = 9 + 8 + 6 + 5
```

3. 3개로 묶어지지 않은 나머지들을 전부 더해준다.

```
 (9 8 7) (6 5 4) 3 2
 result += 3 + 2
```

<br>

배열을 내림차순으로 정렬한 이유는, 3개로 묶었을 때 **가장 저렴한 유제품**의 가격이 할인되므로, 되도록 **가격이 나가는 유제품을 할인받는 것**이 최소 가격으로 구매하는데 적절하다.

![image](https://user-images.githubusercontent.com/77655318/188779447-74448774-f33e-4a4e-af1f-152464421b06.png)

더 원활한 이해를 위해 테스트 케이스를 그려봤다.

<br>

아무튼... 알고리즘으로 코드를 짰는데...

```cpp
int main()
{
    vector<int> prices;
    int len, i;
    long long int myCost = 0;

    cin >> len;
    prices.resize(100000);

    for (i = 0; i < len; i++)
        cin >> prices[i];

    sort(prices.begin(), prices.end(), greater<int>());

    // 현재 인덱스: 0부터 시작함
    i = 0;

    if (len / 3 > 0)
    {
        for (i = 0; i < len; i += 3)
        {
            // 세 개로 묶인 것들 중에 첫번째, 두번째만 더함
            myCost += (long long int)prices[i] + prices[i + 1];
        }
    }

    // 묶이지 않은 가격들을 더함
    while (i < prices.size())
    {
        myCost += prices[i++];
    }

    cout << myCost;
}
```

이렇게 짜니... index를 나타내는 i가 자꾸 눈에 걸려서 깔끔하지가 않은 것 같아서 아쉬웠다.

<br>

그래서 비용을 더하는 방식을  바꿨다.

1. 가격들이 모두 있는 배열을 내림차순으로 정렬하고, 모두 더한 값을 result에 넣어준다..

```
 (9 8 7) (6 5 4) 3 2
 result = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2
```

2. 인덱스대로 3개씩 묵어 세번째 값만 빼준다..

```
 (9 8 7) (6 5 4) 3 2
 result -= (7 + 4)
```

<br>

이것을 코드로 짜봤다.

```cpp
int main()
{
    //...

    // 모든 가격을 더해준다.
    for (int i = 0; i < len; i++)
    {
        cin >> prices[i];
        myCost += prices[i];
    }

    sort(prices.begin(), prices.end(), greater<int>());

    if (len / 3 > 0)
    {
        // 세 개로 묶어 세번째 것만 빼준다.
        for (int i = 2; i < len; i += 3)
        {
            myCost -= prices[i];
        }
    }

    cout << myCost;
}
```

코드도 짧아지고 훨씬 깔끔해진 것 같아 마음에 든다.

<br>

그리디와 정렬 문제는 아직까지는 항상 풀만 하고 재미있는 것 같다.

<br>

<br>

### 7. ATM

[11508. ATM](https://www.acmicpc.net/problem/11399)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/7_ATM.cpp)

![image](https://user-images.githubusercontent.com/77655318/188799354-695b80ca-ba65-401b-b87b-dacb06059b96.png)

<br>

또 정렬과 그리드가 같이 있는 문제!

<br>

각 사람이 **앞 사람들의 인출 시간을 기다리는 시간**을 더하는 값의 **총합**을 구하는 것이다. 그렇기 때문에 **앞 쪽에 있는 사람이 인출 시간이 적을수록** 총합의 최솟값이 되는 것이다. 

![2022-09-07-15-45-52-image](https://user-images.githubusercontent.com/77655318/188915215-30ff60b6-6e58-48c3-83fa-8aec19103d3a.png)

오름차순으로 정렬해야하는 이유를 그려봤다. 열심히.

<br>

따라서 내가 생각한 알고리즘은...

<br>

1. 인출 시간들이 들어있는 배열을 **오름차순**으로 정렬한다.
   
   `앞 사람들의 인출 시간이 적을 수록 뒷 사람들의 기다리는 시간도 적어지기 때문`

2. 반복문을 돌려 사람들의 인출하기까지의 걸린 시간을 모두 구한다.

<br>

이걸 구상한 코드는...

```cpp
vector<int> times;
int len, curWait = 0;
long long int waitTime = 0;

cin >> len;

for (int i = 0; i < len; i++)
{
    int input;
    cin >> input;
    times.push_back(input);
}

// 오름차순 정렬
sort(times.begin(), times.end());

for (int i = 0; i < len; i++)
{
    // 각자의 인출 시간을 계속해서 더해준다
    // => 현재 사람이 인출하는데 걸리는 시간 
    curWait += times[i];
    waitTime += curWait;
}

cout << waitTime;
```

간결하게 구현해봤다. 

<br>

아직까지는 어렵지 않고 재미있다.

<br>

<br>

### 8. 에너지 드링크

[20115. 에너지 드링크](https://www.acmicpc.net/problem/20115)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/8_Energy_Drink.cpp)

<br>

![image](https://user-images.githubusercontent.com/77655318/188905362-a278ea40-3766-4d83-b372-08e1161fea35.png)

시간 초과로 고생했던 문제...

<br>

임의의 두 에너지 드링크를 합칠 때, 한쪽 에너지 드링크는 1/2만 합칠 수 있으므로 **가장 큰 에너지 드링크와 가장 작은 에너지 드링크**를 합쳐 **작은 쪽을 버리는 것이 효율적**이라고 생각했다.

<br>

그래서 처음 생각했던 알고리즘은 이렇다.

<br>

1. 에너지 드링크들이 있는 배열을 **오름차순**으로 정렬한다.

2. `(가장 큰 요소 + 가장 작은 요소/2)`한 값을 저장한다.

3. 앞뒤에 있는 요소를 제거하고, 대신에 **저장한 요소**를 배열에 저장한다.

4. 배열의 크기가 1이 될 때까지 1~3을 반복한다.

<br>

앞뒤에 있는 요소를 원활하게 불러오고 제거할 수 있도록 deque를 사용했고, algorithm 헤더의 sort 함수를 사용했다.

<br>

```cpp
while (drinks.size() != 1)
{
    // 오름차순 정렬
    sort(drinks.begin(), drinks.end());

    // (가장 큰 요소 + 가장 작 요소/2)
    double drink = drinks.back() + (double)(drinks.front() / 2);

    drinks.pop_back();
    drinks.pop_front();

    drinks.push_back(drink);
}

cout << drinks.front();
```

<br>
<br>

### 9. 서강근육맨

[20300. 서강근육맨](https://www.acmicpc.net/problem/20300)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/9_Seogang_Muscle_Man.cpp)
<br>

![image](https://user-images.githubusercontent.com/77655318/189001211-2bdb64c8-5451-413a-84d7-88ca462c731b.png)

큰 자료형을 써야하는 것 이외에는 쉽게 풀 수 있었던 문제이다.

<br>

두개의 운동기구에 일어나는 근손실의 합이 최대한 적어야하므로 **오름차순으로 정렬**해서 가장 큰 값과 작은 값의 합을 구하면 근손실의 합이 적어질 것이다.

<br>

그래서 생각해본 알고리즘은

1. 근손실을 담은 배열을 오름차순으로 정렬한다.

2. `i부터 배열 사이즈/2`까지 반복문을 돌린다.
   
   **배열 사이즈가 짝수**일 경우, `배열[i]와 배열[size - i - 1]`의 합을 구하고
   
   **홀수일 경우** `배열[i]와 배열[size - i - 2]`의 합을 구한다.
   
   <br>
   
   이렇게 하는 이유는 가장 마지막에 있는 값은 큰 값이므로, 되도록이면 무엇과도 더하지 않는 것이 좋기 때문이다.
   
   <br>
   
   쉽게 이미지로 표현해봤다.
   
   ![image](https://user-images.githubusercontent.com/77655318/189004968-c1811add-ef43-4d20-b112-6f199f220121.png)

3. 합을 구한 값 중 **가장 큰 값**을 근손실 값으로 한다.

4. 배열 사이즈가 홀수일 경우, **배열의 마지막 요소와 근손실값을 비교**해 더 큰 값이 근손실 값이 되게 한다.

```cpp
// 오름차순 정렬
sort(losings.begin(), losings.end());

// 홀수인 경우 가장 큰 수는 합치지 않는다
int offset = (losings.size() % 2 == 1) ? -2 : -1;

for (int i = 0; i < len / 2; i++)
{
    unsigned long long int loss = losings[i] + losings[losings.size() - i + offset];

    // 최댓값으로 갱신
    if (answer < loss)
        answer = loss;
}

// 계산 안 했던 가장 큰 수와 비교
if (answer < losings.back())
{
    answer = losings.back();
}

cout << answer;
```

이렇게 구현했다. 

<br>

처음엔 answer만 unsigned long long으로 했다가... 벡터 요소들과 합친 값`loss`도 **long long**이나 **unsigned long long**을 해줘야 함을 깨달았다.

<br>

항상 자료형에 주의하자!

<br>
<br>

### 10. 동전 0

[11047. 동전 0](https://www.acmicpc.net/problem/11047)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/10_Coin_0.cpp)
<br>

![image](https://user-images.githubusercontent.com/77655318/189137436-27a2123b-41ba-41bf-80f7-92768cbcecbe.png)

처음 이 문제를 봤을 땐...

![image](https://user-images.githubusercontent.com/77655318/189137937-127a90b4-38db-4ded-b86f-2afcf1f5ed90.png)

이 예제를 보고 **"그냥 큰 거 나누고... 작은 거 나누면 되는 거 아니야?"** 하는 안일한 생각을 잠시 동안 했다가 `2 19 3 7`이라던가... `2 9 3 7`  등의 예외가 있는 예제가 머리를 스쳐 지나가서 생각을 고쳐먹었다.

<br>

섣불리 사용할 수 있는 동전을 사용했다가, 다음 동전들이 **나누어지지 못해 K를 만들지 못하는 불상사**가 생길 수 있으므로...

<br>

내가 생각한 방법은 **사용할 수 있는 동전 - 1**까지만 사용을 하고, **다음 동전들을 검사**해서 사용하지 않았던 **하나의 동전을 사용할지, 말지**의 여부를 계속 결정하는 것이다.

<br>

자세한 알고리즘을 구성해봤다.

<br>

1. `사용할 수 있는 동전 - 1`을 사용한다.
   
   목표 금액인 K에서 방금 사용한 동전 금액을 차감해준다.

2. 만약 **위에서 모든 동전을 사용했더라면**, 위에 사용한 동전보다 작은 동전들이 **남은 K로 나누어 떨어지는지** 검사한다.
   
   <br>
   
   나누어 떨어진다면, **K가 만들어지지 않은 일**은 일어나지 않으므로, 1에서 사용하지 않은 **하나의 동전을 사용**해도 되기 때문이다.
   
   이때, K를 동전 금액만큼 차감한다.

3. 1~2를 K가 만들어질 때까지 **반복**한다.

<br>

두서없이 쓴 것 같아서... 예제를 가져와봤다.

![image](https://user-images.githubusercontent.com/77655318/189148835-e1c833d8-bb92-479d-962b-47a670176874.png)

```cpp
for (int i = len - 1; i >= 0; i--)
{
    // 목표 금액 달성 했다면 반복문 나가기
    if (k == 0) break;

    // 동전이 목표 남은 목표 금액보다 크다면 다음 동전으로
    if (coins[i] > k) continue;

    int div = k / coins[i];

    // 마지막 동전이라면 합이 k가 될 때까지 모두 사용하고,
    // 그렇지 않다면 최대한 사용할 수 있는 바로 전 단계까지만
    int offset = (i == 0) ? 0 : -1;

    k -= (div + offset) * coins[i];
    answer += div + offset;

    for (int j = i - 1; j >= 0; j--)
    {
        if (j < 0) break;

        // 만약 사용할 수 있는 만큼 사용할 때
        // 후에 남기지 않고 사용할 수 있으면
        if ((k - coins[i]) % coins[j] == 0)
        {
            // 사용하지 않은 하나의 코인도 바꿔준다
            k -= coins[i];
            answer++;
            break;
        }
    }
}

cout << answer;
```

<br>

조금 길고 가독성이 떨어지는 코드이긴 하다...

<br>

재미있고 유익한 문제였다. 그리디를 푸는 사고력이 점점 느는 것 같아서 기분이 좋다. 

<br>
<br>

### 11. 회의실 배정

[1931. 회의실 배정](https://www.acmicpc.net/problem/1931)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/11_Meeting_Room_Assignment.cpp)
<br>

![image](https://user-images.githubusercontent.com/77655318/189164837-93dc90ce-6eae-4bae-900b-d6be7da6c461.png)

<br>

사실은... 생각하지 않고 풀어낸 문제이다... 왜냐하면

![image](https://user-images.githubusercontent.com/77655318/189164206-24148600-75a8-42da-b921-233ea5099e35.png)

예제에서 끝나는 시간이 오름차순으로 정렬된 것을 보고... 

<br>

1. **끝나는 시간을 오름차순으로 정렬**한 다음에...

2. 방금 시간한 회의의 끝나는 시간보다
   
   **크거나 같은 다른 회의 시작 시간**을 찾는다.

3. 시작할 회의가 없을 때까지 1~2를 반복한다.

<br>

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;

int main()
{
    int len, answer = 0;
    ulli endTime = 0;
    // first => end Time, second => start Time
    // end Time을 주축으로 정렬할 것이기 때문에
    vector<pair<ulli, ulli>> times;

    cin >> len;

    for (int i = 0; i < len; i++)
    {
        ulli startTime, endTime;
        cin >> startTime;
        cin >> endTime;
        times.push_back({ endTime, startTime });
    }

    // endTime을 기준으로 정렬
    sort(times.begin(), times.end());

    for (int i = 0; i < len; i++)
    {
        // 회의가 끝나는 시간보다 같거나 늦을 때는 회의를 시작할 수 있다
        if (endTime <= times[i].second)
        {
            // 끝나는 시간 갱신
            endTime = times[i].first;
            answer++;
        }
    }

    cout << answer;
}
```

일단 코드의 가독성이 좀 꽝이다... 구조체를 만들고 연산자 정의까지 하기가 귀찮아서 pair을 썼는데... `start Time이 pair의 second`, `end Time이 pair의 first`이기 때문에...

<br>

제출할 때는 설마 맞을 거라 생각하지는 않았지만... 맞았다. **끝나는 시간 오름차순 정렬**이 중요한 문제였던 것 같은데... 

날로 먹은 것 같다는 생각이 들었다.

<br>

그렇다면 **왜 끝나는 시간이 오름차순일까?** 를 생각해서 죄책감을 덜기로 했다.

<br>

내 생각엔, 빠른 시작시간보다 빠른 끝나는 시간이 더 중요하기 때문이다.

만약 시작 시간이 오름차순이었다면, **끝나는 시간이 최댓값인데도 시작 시간과 계속 비교**하며 최악의 경우 한 번의 회의밖에 하지 못한다.

![image](https://user-images.githubusercontent.com/77655318/189173056-bfda2d4f-67af-4b0a-bc00-d0c4f1bd25fc.png)

그렇지만, 끝나는 시간이 오름차순이면 최대한 **빨리 끝나는 것**에 집중했기 때문에, 회의를 최대한 많이 돌릴 수 있다.

![image](https://user-images.githubusercontent.com/77655318/189173828-3f117123-6cd2-4d17-83f5-c1a27822ca67.png)

<br>

간단하지만, 유익한 문제였다.

<br>
<br>

### 12. 잃어버린 괄호

[1541. 잃어버린 괄호](https://www.acmicpc.net/problem/1541)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/12_Lost_Parenthese.cpp)
<br>

![image](https://user-images.githubusercontent.com/77655318/189327973-a7ccf740-7137-4b6d-b0fe-0db8719e4ee3.png)

처음에는 괄호 문제라 조금 무서웠지만... 조금만 생각하면 쉽게 풀 수 있는 문제였다.

<br>

```
inpupt =>
30+20-50+40-30+30
```

만약, 이런 입력이 있다면, 괄호를 어떻게 묶어야 최솟값이 나올까?

```
30+20-(50+40)-(30+30)

output =>
-100
```

무려 원래 답보다 140이나 작은 결과값이 나왔다!

<br>

예제를 토대로 알고리즘 설계를 해봤다.

<br>

1. 마이너스 연산자가 나올 때까지의 **모든 수들을 더한다**.

2. **마이너스 연산자**가 나오면 앞으로 나오는 모든 수들을 빼준다.
   
   마이너스 연산자가 나오면서부터, **다음 연산자가 어떤 것이든**, 앞으로 나올 모든 수들은 **마이너스로 묶이기** 때문이다.

이것을 토대로 짜본 코드는...

```cpp
#include <iostream>
using namespace std;

int main()
{
    string formula;
    int num = 0, answer = 0;
    bool isMinus = false;

    cin >> formula;

    for (int i = 0; i < formula.size(); i++)
    {
        if (isdigit(formula[i]))
        {
            num *= 10;
            num += formula[i] - '0';
        }
        else
        {
            // '-'가 한 번도 나온 적 없다면 그냥 연산값 더함
            if (!isMinus)
                answer += num;

            // 나온 적 있다면 괄호로 묶이기 때문에
            // 무엇이든지 빼줌
            else
                answer -= num;

            if (!isMinus && formula[i] == '-')
                isMinus = true;

            num = 0;
        }
    }

    // 마지막 숫자를 마저 더한다
    if (isMinus) num *= -1;
    answer += num;

    cout << answer;
}
```

간단하게 짜봤다.

<br>

신선하고 재미있는 문제였다. 해결 방법이 빠르게 생각나서 기분이 좋았다.

<br>
<br>

### 13. 블로그 2

[1931. 블로그2](https://www.acmicpc.net/problem/20365)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/13_Blog_2.cpp)
<br>

![image](https://user-images.githubusercontent.com/77655318/189358487-8ff786bd-649d-4c83-90da-4fc3bf8c6f23.png)

간단하고 귀여운 문제였다.

<br>

형광팬 색깔을 바꾸는 작업을 최대한 덜 해야하므로, 처음에 **모든 글을 하나의 색으로** 칠한 다음, **칠한 색과 다른 부분을 부분을 작업**하면 된다고 생각했다.

그러려면, 최대한 **작업량이 많은 색을 처음에 한꺼번에** 칠해야 한다.

<br>

이를 토대로 알고리즘을 설계해봤다.

1. 파란색으로 바꾸는 작업, 빨간색으로 바꾸는 **작업의 수를 각각 계산**한다.

2. 위에 구한 둘을 비교해서 더 많은 작업이 필요한 색을 처음에 한꺼번에 칠한다.
   
   이때 작업량은 1이다.

3. 칠하지 않은 색을 모두 칠한다.
   
   작업량은 1+해당 색의 작업량의 수

<br>

알기 쉽게 경우를 따져서 그림으로 표현해봤다.

<br>

![image](https://user-images.githubusercontent.com/77655318/189366118-0cf7205e-4a9c-4b52-b6dc-10e9cf71b2e8.png)

코드!

```cpp
#include <iostream>
using namespace std;

#define RED        1
#define BLUE    2

int main()
{
    int len, red = 0, blue = 0;
    int state = 0;
    char input;

    cin >> len;

    for (int i = 0; i < len; i++)
    {
        cin >> input;

        if (input == 'R')
        {
            // 이전 색이 빨강이 아니라면
            // 색을 바꾸는 작업 횟수 증가
            if (state != RED) red++;
            state = RED;
        }
        else
        {
            if (state != BLUE) blue++;
            state = BLUE;
        }
    }

    // 1(처음에 모두 칠한 횟수) + (더 적은 작업 횟수)
    if (red >= blue)
        cout << 1 + blue;
    else
        cout << 1 + red;
}
```

간단하게 구현한 것 같다.

<br>

처음, 한번에 색을 모두 칠하는 방법이 신기하고 효율적인 해결법이라고 생각한다. 재미있었다!

<br><br>

### 14. A → B

[1931. A → B](https://www.acmicpc.net/problem/16953)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/14_A_To_B.cpp)
<br>

![image](https://user-images.githubusercontent.com/77655318/189474760-9829e9e0-7c5b-4168-939f-fe4b302fbde7.png)

나의 어마어마한 무지와 부족함을 알려주었던 문제... 

<br>

![image](https://user-images.githubusercontent.com/77655318/189474813-5ca696da-a195-4374-8820-55d4a3cd1619.png)

예제를 봐도, 그리디로는 풀 생각이 나지 않았다. 1을 추가하는 경우나, 2를 곱하는 경우의 조건이 전혀 떠오르지가 않았다.

<br>

문제의 제한 시간은 2초. **조건이 생각나지 않으므로** 모든 경우의 수를 탐색을 할 생각을 했다.

<br>

1. 처음은 내가 가장 익숙한 **DFS**를 이용해서 문제를 풀 생각이었다.
   
   늘 그렇듯재귀 함수를 이용해서.

```cpp
void AToB(int a, int count)
{
    if (a > b) return;

    else if (a == b)
    {
        if (result < count)
            result = count;
    }

    AToB(a * 10 + 1, count + 1);
    AToB(a * 2, count + 1);
}
```

이렇게 해서 DFS를 구현해봤지만... 생각해보니 `a의 최솟값이 1, b의 최댓값이 10^9`... DFS로는 시간상으로 너무너무 오래 걸리는 것이었다.

<br>

라고 생각했지만... 지금 보니 `AToB(AToB(a * 10 + 1, count + 1))` 이 아니라... `AToB(a + 1, count + 1)`  무슨 이런 말도 안 되는 코드를 쓰고 있었다.

애초에 처음부터 1부터 10^9번까지 도는데 시간이 초과가 되지 않을 리가...

<br>

애석하게도 이때는 코드의 문제점을 알지 못했고, DFS는 너무 오래 걸린다... **BFS**로 구현해보자는 생각만 하고 있었다.

2. **BFS**로 구현해봤다.
   
   While문과 queue를 이용해서 구현해봤다. **탐색할 노드의 자식**들을 queue에 집어놓고, 부모의 노드가 조건에 맞는지 확인한 다음에 pop하는 형식이었다.
   
   이때, queue에 이미 들어왔던 노드가 들어오면, 시간만 차지할뿐 의미가 없으므로 **메모이제이션**을 사용해 이미 queue에 들어온 노드는 들어갈 수 없게 해주었다.
   
   BFS를 사용할 때도 실수 때문에 많이 틀렸었는데, 
+ 메모이제이션에 사용할 bool형 배열의 크기를 10^9로 해서 **메모리 초과**

+ 문제 조건인 `횟수 + 1`이 아니라 `횟수`를 출력했기 때문에 **실패**

+ bool형 배열 크기를 10^9/2로 줄였기 때문에 **인덱스 오류**
  
  <br>
  
  이 하고 많은 실패를 딛고 짠 코드이다.
  
  ```cpp
  #define LIMIT    500000000
  int a, b;
  bool check[LIMIT];
  queue<pair<long long int, int>> numbers;
  
  bool Correct(long long int value, int count);
  
  int main()
  {
    cin >> a >> b;
  
    numbers.push({ a, 1 });
  
    while (!numbers.empty())
    {
        if (numbers.empty()) break;
  
        pair<long long int, int> val = numbers.front();
        int level = val.second + 1;
  
        // queue에 넣으려 하는 수가
        // 이미 넣어진 게 아니고, b보다 크지 않을 때 넣음
        // b와 같을 땐 횟수 반환해서 반복문 종료
        if (Correct(val.first * 10 + 1, level) || Correct(val.first * 2, level))
        {
            cout << level;
            return 0;
        }
  
        numbers.pop();
    }
  
    cout << -1;
  }
  
  bool Correct(long long int value, int level)
  {
    // value와 b가 같다면 true 반환
    if (value == b)
        return true;
  
    // 크다면 queue에 넣지 않음
    if (value > b)
        return false;
  
    // 탐색하지 않은 value이면 queue에 넣음
    if (value >= LIMIT || check[value] != true)
        numbers.push({ value, level });
  
    // 탐색 완료
    if (value < LIMIT)
        check[value] = true;
  
    return false;
  }
  ```

        길고 지저분하긴 하지만... 아무렴... 구현에 만족했다.

    ![image](https://user-images.githubusercontent.com/77655318/189475980-b9f1ac14-f9c2-4326-b6a3-15e17e2c4231.png)

        대충 그리긴  했지만... 이 순서로 돌아간다고 볼 수 있다.

<br>

하지만 **그리디 문제**라고 가져온 문제를 **BFS**로 겨우겨우 풀었으니... 좀 죄책감이 들었다. 생각이 나지 않는데 어쩔 수 없다는 마음 가짐으로... 그리디로 푼 다른 사람들의 코드를 봤다.

> 제출번호 44366838님의 코드 (https://www.acmicpc.net/source/44366838)

```cpp
#include <stdio.h>
int a, b, r = 1;
int main()
{
    scanf("%d%d", &a, &b);

    while(b > a)
    {
        if(b % 2 == 0)
        {
            b /= 2;
            r++;
        }
        else if(b % 10 == 1)
        {
            b = (b - 1) / 10;
            r++;
        }
        else break;
    }

    printf("%d", a == b ? r : -1);
}
```

진짜 무슨 말도 안 되게 간단하고 쉽고 가독성 있게 풀어놓으셨다...

연산을 반대로 할 생각을 하다니......

으엉엉엉

<br>

생각이 주말만큼 짧은 내 자신을 미워하게 되었다...

그래도... 열심히 했으면 된 거 아닐까.

생각을 **한쪽으로만 고정하지 말고**, 이렇게도 해보고, 저렇게도 해보고 반대로도 해봐야겠다. 난 아직 시간이 많으니까.

<br>

기대해라... 다음에 비슷한 문제가 다시 온다면 세상 간단하고 쉽게 풀어주겠다.

<br><br>

### 15. 민겸 수

[21314. 민겸 수](https://www.acmicpc.net/problem/21314)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/15_Minkyeom_Number.cpp)
<br>

![image](https://user-images.githubusercontent.com/77655318/189477607-c8617e01-0d9e-4593-b4c3-84797b26bb0d.png)

민겸 수를 10진수로 바꿨을 때 가장 큰 값과 가장 작은 값을 출력하는 것. 민겸아, 참으로도 요상한 짓을 했구나.

<br>

처음엔 어려워 보였지만, 생각보다 간단한 문제였다. 예제를 보면 알 수 있다.

![image](https://user-images.githubusercontent.com/77655318/189477660-e82d2efe-4e9f-4a06-8ccc-415709784942.png)

**최댓값은 505500**, **최솟값은 155105**, 최댓값과 최솟값이 나온 알고리즘을 따라가보고 최댓값을 구할 때, 최솟값을 구할 때의 규칙을 정의해보았다.

<br>

1. 일단 최댓값은 M과 K가 붙어있다면 **절대 따로 계산하지 않는다.**
   
   ```cpp
   input =>
   MMMMMK
   
   output =>
   // 따로 계산한다면... 
   111115
   100005
   
   // 같이 계산한다면... (10^M의 개수  * 5)
   500000
   ```

        앞자리부터가 1에서 5로 달라지니, `10^M의 개수 * 5` 꼴로 계산해야 한다.

2. 마지막 **남은 M은 모두 1로** 처리한다.
   
   ```cpp
   input => MMMKMMM
   
   // 1대로 한다면
   
   output =>
   5000...
   
   // M을 K와 처리할 수 없으니 경우의 수를 구해보자
   5000100
   5000101
   5000111
   ```

        이렇게 남은 M을 모두 1로 처리하는 것이

        일의자리, 십의 자리, 백의 자리... 등에 있는 수를 **0에서 1로** 올려주게 된다.

<br>

이 규칙을 기반으로 최댓값을 구하는 코드를 짜보았다.

```cpp
string max = "", number;
int mCount = 0;
cin >> number;

// MAX
for (int i = 0; i < number.size(); i++)
{
    if (number[i] == 'M') mCount++;

    else
    {
        // K는 5 * 10^(mCount)로 계산
        max.push_back('5');

        if (mCount > 0)
        {
            for (int j = 0; j < mCount; j++)
                max.push_back('0');

            mCount = 0;
        }
    }
}

// 남은 M 처리
for (int j = 0; j < mCount; j++)
{
    // MAX는 모두 1로 계산 
    max.push_back('1');
}
```

<br>

최솟값은...

1. M은 혼자 계산하거나, M이 여러개이면 `10^(M 개수)` 형태로 M끼리만 계산한다.
   
   ```cpp
   input =>
   MKMMK
   
   output =>
   // M을 K와 계산했을 때
   50500
   
   // 1대로 계산했을 때
   15105
   ```
   
   이렇게 계산하게 되면, **50, 500**으로 계산하게 될 것을 **15, 105**로 줄일 수 있다.

2. 남은 M도 위와 같이 계산한다.
   
   ```c
   input =>
   MKMMM
   
   output =>
   15100
   15110
   15111
   ```
   
   위와 같은 형식으로 계산하면, 일의자리, 십의자리 등등을 **1에서 0으로** 줄일 수 있다. 

<br>

이를 구현해본 최솟값을 구하는 코드이다.

```cpp
string min = "", number;
int mCount = 0;
cin >> number;

// MIN
for (int i = 0; i < number.size(); i++)
{
    if (number[i] == 'M') mCount++;

    else
    {
        if (mCount > 0)
        {
            for (int j = 0; j < mCount; j++)
            {
                // MIN은 1이나 10^(mCount)로 계산 후
                if (j == 0)
                    min.push_back('1');
                else
                    min.push_back('0');
            }

            mCount = 0;
        }

        // MIN은 M 따로 K 따로
        min.push_back('5');
    }
}

// 남은 M 처리
for (int j = 0; j < mCount; j++)
{
    // MIN은 1이나 10^(mCount)로 계산
    if (j == 0)
        min.push_back('1');
    else
        min.push_back('0');
}
```

최종 구현 코드는 위 두 코드를 합쳐놔서 가독성이 조금 떨어지긴 한다만... 그래도 잘 풀어낸 것 같아서 기분이 좋다.

<br>

민겸... 다음엔 더 어려운 민겸수2를 만들어 와라...

<br><br>

### 16. 꿀 따기

[21758. 꿀 따기](https://www.acmicpc.net/problem/21758)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/16_Picking_Honey.cpp)
<br>

![image](https://user-images.githubusercontent.com/77655318/189526392-a51140a8-a91a-4714-8a5a-4b5fe8998899.png)

![image](https://user-images.githubusercontent.com/77655318/189526410-3ca8fc3a-b2d0-4a54-bcce-dff16c7b59a6.png)

장장 2시간을 넘게 푼 문제... 처음 본 그리디 골드 문제에 기강을 세게 잡혔다...

풀어보니 생각보다는 어렵지 않았다는 게 화가 난다... 으엉엉 

<br>

처음 접근은 **양 끝 수를 비교**해서 더 작은 쪽에 벌을 몰아놓고, 반대쪽에 꿀통을 넣을 생각이었다. 하지만, 이 접근은 반례가 너무 많았고... 신경쓸 조건들이 참 많았다.

<br>

양 끝 수만 비교해서 **최적의 결과가 나오는 것도 아닐뿐**더러, 두번째 벌의 위치를 정하는 것도 생각이 나지 않아서 머리가 뱅뱅 돌았다.

<br>

문제의 알고리즘 분류를 보고 힌트를 얻을 수 있었다.  `그리디`, `누적합`, `많은 조건 분기`가 있었는데... 사실 난 그리디를 제외하고 아무것도 몰랐다...

그래도 한국인이니 **많은 조건 분기**가 눈에 띄었다.

<br>

많은 조건에서 정답을 구하고, 그 중 가장 최적의 값을 답으로 쓰자고 생각했다.

생각한 조건은 3개이다.

<br>

```
1. 벌 꿀통 벌 (벌 사이에 꿀통이 있을 때)
2. 벌 벌 꿀통 (벌이 왼쪽에 몰려있고, 꿀통이 오른쪽에 있을 때)
3. 꿀통 벌 벌 (벌이 오른쪽에 몰려있고, 꿀통이 오른쪽에 있을 )
```

<br>

이 중 1번을 구하는 것은 매우 쉬웠다. 벌은 양 끝에, 꿀통은 유일하게 **두 벌이 모두 지나갈수 있는 자리**이므로 벌의 자리를 제외하고 가장 큰 값을 넣어주면 된다.

<br>

코드로 짜본다면

```cpp
// 두 벌의 시작 자리 제외
answer = sum - arr[0] - arr[len - 1];

// max index
honey = max_element(arr.begin() + 1, arr.end() - 1) - arr.begin();
answer += arr[honey];
```

벌이 시작한 자리들을 제외하고, 꿀통은 두 벌이 모두 가므로 한 번 더 더해준다.

<br>

2~3번을 생각하는 건 시간이 조금 걸렸다.

간단하게 반복문을 돌려서 **꿀 손해가 가장 적은 곳**을 골랐다.

```
input =>
5 A B C D E

// 왼쪽 벌을 몰려있고, 오른쪽에 꿀통이 있을 때
// SUM = A + B + C + D + E

// A, B에 벌이 있다면
// EXCEPTION = -A-A-B-B

// A, C
// EXCEPTION = -A-C-A-B-C

// A, D
// EXCEPTION = -A-D-A-B-C-D

// A, N
// EXCEPTION = -2A-2N-(B~N-1)
```

**Exception이 가장 적을 때**의 두번째 벌의 자리를 지정했다.

<br>

```cpp
int BeeBeeHoney(vector<int> v, int sum)
{
    int exception = -2147483647;

    for (int i = 1, honeySum = 0; i < v.size(); i++)
    {
        int minus = -(arr[0] * 2) - (arr[i] * 2) - honeySum;

        if (exception < minus)
            exception = minus;

        honeySum += arr[i];
    }

    return sum * 2 + exception;
}
```

<br>

**오른쪽에서 벌이 오는 상황**이면, 매개변수의 벡터를 **리버스**해주었다.

<br>

지금까지 푼 그리디 문제 중에 가장 어려웠다... 이제 슬슬 어려운 문제가 많이 나올 것 같다. 포기하지 말고 열심히 끝까지 풀어봐야지. 

<br>

하나의 최적의 방법이 아니라, 여러가지 답을 산출할 수 있는 **여러 조건**을 생각하고 최적의 결과를 내는 법을 배웠다. 비슷한 문제가 나온다면, 시간을 날리지 않고 이 방법을 고려해봐야겠다.

<br><br>

### 17. 강의실 배정

[11000. 강의실 배정](https://www.acmicpc.net/problem/11000)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/17_Classroom_Assignment.cpp)
<br>

![image](https://user-images.githubusercontent.com/77655318/189529930-a723eb7e-af82-4423-a05c-3031d5e51756.png)

간단하게 푼 문제.

<br>

1. 시작 시간, 끝나는 시간을 **오름차순으로 정렬**한다.

2. 반복문을 강의 수만큼 돌린다.
   
   돌아가는 중에 우선순위 **큐의 top**이 현재 시작 시간보다 **작거나 같다면** 큐를 **pop**하고 다시 현재 끝나는 시간을 넣어준다.
   
   그렇지 않다면 pop을 하지 않고 현재 끝나는 시간을 넣어준다.

3. queue의 길이가 강의실의 개수이다.

<br>
코드로 구현해봤다.
<br>

```cpp
sort(times.begin(), times.end());

for (int i = 0; i < len; i++)
{
    if (!rooms.empty() && rooms.top() <= times[i].first)
    {
        rooms.pop();
    }

    rooms.push(times[i].second);

}

cout << rooms.size();
```

<br><br>

### 18. 행복 유치원

[13164. 행복유치원](https://www.acmicpc.net/problem/13164)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/18_Happpy_Kindergarten.cpp)
<br>
![image](https://user-images.githubusercontent.com/77655318/189606011-b2fdf055-4410-4973-9867-f1caffa3368a.png)
어이가 없이 어려웠던 문제... 문제 자체도 어려웠지만 유치원생의 최대 키가 10^9라는 것도 황당했다...
<br>
처음엔 도대체 어떻게 접근해야할지 몰라서 나의 그리디 문제 빅데이터를 사용해서 **처음부터 차근차근 조를 정해가는** 방법을 떠올렸다.

하지만... 아무리 생각해도 아무 정보도 없는 채로 처음부터 수를 탐색하는 건... 시간도 시간이고, 답도 나오지 않을 것 같았다.

원생의 키 차이는 **절대적이지 않고, 상대적**이므로 `1과 3`이 묶일 수도 있지만, `1의 키와 100`이 묶일 가능성도 없지 않다.

<br>

이 생각을 기반으로 알고리즘을 생각해봤다.

1. 인접한 학생들의 **키 차이와 인덱스**를 **배열**에 저장한다.
   
   ```
   input =>
   9 3
   1 2 3 100 101 102 300 301 302
   ```
   
   차만 배열에 저장하면...
   
   ```
   array (diff, index)=>
   [{2-1, 0}, {3-2, 1}, {100-3, 2}, {101-100, 3}...]
   
   [{1, 0}, {1, 1}, {97, 2}, {1, 3}, {1, 4}, {198, 5}, {1, 6}, {1, 7}]
   ```

2. **키 차이**를 기준으로 **내림차순**으로 정렬한다.
   
   ```
   [{198, 5}, {97, 2}, {1, 7}, ...]
   ```

3. 배열의 0~K(그룹의 수 - 1)까지를 **인덱스를 기준**으로 다시 **오름차순** 정렬한다.
   
   ```
   [{97, 2}, {198, 5}]
   ```

4. 배열의 인덱스 순으로 조를 끊어주고, 최단신과 최장신의 차를 구한다.
   
   ```
   1 2 3 100 101 102 300 301 302
   
   * 2번째 인덱스 => 3과 100 사이
   * 5번째 인덱스 => 102과 300 사이
   
   1 2 3 | 100 101 102 | 300 301 302
   ```
   
   ```
   (3-1) + (102-100) + (302-300)
   = 2 + 2 + 2
   = 6
   ```

이렇게 완벽하게 나누어 진다!! 

코드로 구현해봤다.

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct diff
{
 int index;
 int diff;
};

typedef long long int lli;

int arr[300000];
vector<struct diff> diff;

int main()
{
 int len, group, startIdx = 0;
 long long int answer = 0;
 cin >> len >> group;

 for (int i = 0; i < len; i++)
     cin >> arr[i];

 // 숫자 사이의 차(구조체)를 모두 배열에 넣어준다
 for (int i = 0; i < len - 1; i++)
     diff.push_back({ i, arr[i + 1] - arr[i] });

 if (!diff.empty())
 {
     // 차를 내림차순으로 정렬한다
     sort(diff.begin(), diff.end(), [](auto a, auto b) {return (a.diff > b.diff); });

     // 쓸 부분 말고 제거
     if (len != group)
         diff.erase(diff.begin() + group - 1, diff.end());

     // 정렬한 차이를 인덱스 순으로 오름차순 정렬한다
     sort(diff.begin(), diff.end(), [](auto a, auto b) {return (a.index < b.index); });
 }

 // 마지막 인덱스도 넣어준다.
 // 반복문 계산을 위해
 diff.push_back({ len - 1,0 });

 for (int i = 0; i < diff.size(); i++)
 {
     // 0부터 a1, a1+1부터 a2, a2+1부터 a3...
     // 그룹으로 묶어 최댓값과 최솟값의 합을 저장한다.
     answer += (lli)arr[diff[i].index] - arr[startIdx];
     startIdx = diff[i].index + 1;
 }

 cout << answer;
}
```

조금 가독성 없고 길긴 하지만...

나름 구현은 잘 해낸 것 같다. 엄청 어렵고... 생각도 필요한 문제였지만, 찬찬히 생각해서 답을 도출해낸 게 뿌듯하다. 나중에 다시 풀어봐야겠다.

<br><br>

### 19. 최소 회의실 개수

[19598. 최소 회의실 개수](https://www.acmicpc.net/problem/19598)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/19_Minimum_Rooms_Number.cpp)
<br>
17번 강의실 배정과 너무 똑같았던 문제... 한계값인 `2^31` 때문에 `unsinged long long int`를 쓴 것을 제외하면 다를 게 없다.
<br>

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef unsigned long long int ulli;

vector<pair<ulli, ulli>> times;
priority_queue<ulli, vector<ulli>, greater<ulli>> rooms;

int main()
{
    int len;
    cin >> len;

    for (int i = 0; i < len; i++)
    {
        ulli start, end;
        cin >> start >> end;
        times.push_back({ start,end });
    }

    sort(times.begin(), times.end());

    for (int i = 0; i < len; i++)
    {
        // 강의실을 이용할 수 있다면
        if (!rooms.empty() && rooms.top() <= times[i].first)
        {
            rooms.pop();
        }

        rooms.push(times[i].second);
    }

    cout << rooms.size();
}
```

새로운 문제를 원해...

<br><br>

### 20. 센서

[2212. 센서](https://www.acmicpc.net/problem/2212)  
[문제 풀이](https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/20_Sensor.cpp)
<br>
![image](https://user-images.githubusercontent.com/77655318/189776849-fc0d7af5-6f77-4d26-876c-b1007703e663.png)

보자마자... 어! 행복유치원! 이 생각났던 문제... 알고리즘 또한 행복유치원과 완전 동일하게 구상해도 맞다. 문제집의 창의력이 떨어지나보다.

다만, **집중국의 개수가 센서보다 많을 수** 있므로, 그 예외 처리는 0을 출력하는 으로 주었다.
<br>
같은 코드지만, 그래도 복습 겸 써봤는데... 자꾸 자꾸 틀렸다...
<br>
하루를 꼬박 고민했는데, 문제는 vector의 **resize**를 **reserve**로 썼기 때문... 진짜 어이가 없고 허무하다... 이런 실수... 다시는 안 해...



```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct diff
{
	int diff, index;
};

vector<int> sensors;
vector<struct diff> diffs;

int main()
{
	int len, count, start = 0;
	long long int answer = 0;
	cin >> len >> count;

	sensors.resize(len);

	for (int i = 0; i < len; i++)
		cin >> sensors[i];

	// 센서 오름차순 정렬
	sort(sensors.begin(), sensors.end());

	// 센서보다 집중국의 개수가 더 많다면
	// 0으로 처리 (거리 차이가 나지 않게 되므로)
	if (count >= sensors.size())
	{
		cout << 0;
		return 0;
	}

	// 각 센서의 거리의 차와 인덱스를 넣어준다
	for (int i = 0; i < sensors.size() - 1; i++)
		diffs.push_back({ sensors[i + 1] - sensors[i], i });

	if (!diffs.empty())
	{
		// 차를 기준으로 오름차순 정렬
		sort(diffs.begin(), diffs.end(), [](auto a, auto b) {return a.diff > b.diff; });

		// (집중국 위치 - 1)개만 남기고 모두 지운다.
		diffs.erase(diffs.begin() + count - 1, diffs.end());

		// 인덱스 순으로 오름차순 정렬
		sort(diffs.begin(), diffs.end(), [](auto a, auto b) {return a.index < b.index; });
	}

	// 마지막 인덱스를 넣어 모든 센서가 수신 영역에 들어가게
	diffs.push_back({ 0, len - 1 });

	for (int i = 0; i < count; i++)
	{
		// 묶여진 거리의 합과 차를 구한다.
		int curIndex = diffs[i].index;
		answer += (long long int)sensors[curIndex] - sensors[start];
		start = curIndex + 1;
	}

	cout << answer;
}
```