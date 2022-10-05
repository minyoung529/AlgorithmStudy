[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# Dynamic Programming 1

동적 프로그래밍을 이용하여 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩🟩🟩⬛⬛⬛⬛⬛⬛<br>
_44%_
<br><br><br>

</div>

### 1. 피보나치 수 5<br>

<a href="https://www.acmicpc.net/problem/10870">10870. 피보나치 수 5</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/1_Fibonacci_5">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192141389-acf88c7a-b2ab-49b9-8a9a-1ca8ffe0d2cf.png)

DP 첫 문제! 피보나치 수열이 나왔다. 간단한 문제이지만, 입력값이 **20**이 최대이므로, 단순 재귀를 이용한 피보나치로는 구현이 안 될 거라 생각했다.

메모이제이션을 쓰는 방법도 있지만... 아무래도 DP는 과거에 구한 해를 이용하는 알고리즘이니까... **단순 for문으로 돌리는 것**이 제일 맞을 거라 생각했다.

```cpp
#include<iostream>
using namespace std;

int main()
{
    int len;
    int a = 0, b = 1;
    cin >> len;

    // 1 이하일 경우 
    if (len <= 1)
    {
        cout << len;
        return 0;
    }

    for (int i = 0; i < len - 1; i++)
    {
        // a => b
        // b => a+b
        int temp = b;
        b = a + b;
        a = temp;
    }

    cout << b;
}
```

아주 간단한 DP 문제였지만, 수열의 뜻과 문제 자체가 DP와 너무 잘 맞아서 신기했다. 아직 DP는 감도 안 오지만...

이렇게 차근차근 해나가면 언젠가 어려운 DP 문제도 눈 감고 풀 날이 오게 되겠지...?

<br>
<br>

### 2. 설탕 배달<br>

<a href="https://www.acmicpc.net/problem/2839">2839. 설탕 배달</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/2_Sugar_Delivery">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192142166-a95719d1-71e5-4a19-a821-a18781d17c6f.png)

그리디에서 풀었던 거스름돈 문제랑 거의 똑같은 문제.

그때는 반복문을 돌려서 N과 M 중 **어떤 것을 빼야하는지** 조건문으로 걸러줬다면,

지금은 입력값이 M(더 큰 값)으로 나누어질 때까지 더 작은 N을 빼주었다!

```cpp
#include<iostream>
using namespace std;

int main()
{
    int num, answer = 0;
    cin >> num;

    // 5로 나누어질 때까지 3을 뺀다
    while (num % 5 && num > 0)
    {
        num -= 3;
        answer++;
    }

    // 5로 나누어진다면 정답 출력
    if (num % 5 == 0)
        cout << answer + num / 5;
    else
        cout << -1;
}
```

만약 입력값이 14라고 한다면...

```
input => 14

(5로 나누어질 때까지 3으로 빼기)
1  11
2  8
3  5

answer =>
3+5/5

4
```

<br>

또 입력값이 7이라고 한다면...

```cpp
input => 7

(5로 나누어질 때까지 3으로 빼기)
1  4
2  1
3 -2

(-2%5 != 1)이므로...
answer =>
-1

4
```

간단하고 재미있는 문제이다! 전에 풀었던 문제를 좀 더 효율적이고 예쁘게 풀어서 기분이 좋았다.

<br>
<br>

### 3. 피보나치 수 2<br>

<a href="https://www.acmicpc.net/problem/2748">2748. 피보나치 수 2</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/3_Fibonacci_2">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192142814-9e930296-6f23-4e76-9176-bdd5c324eb9a.png)

1번과 같은 문제이지만... 한계값이 20아니라 **90까지** 늘어난 상황!! 

<br>

하지만 나는 for문을 사용해서 구현했으므로 자료형을 int에서 **unsigned long long int**로 늘려주기만 하면 되는 일이었다.

unsigned long long int를 다 쓰기 귀찮아서 typedef로 ulli로 지정해주었다!

```cpp
#include<iostream>
using namespace std;

typedef unsigned long long int ulli;

int main()
{
    ulli len;
    ulli a = 0, b = 1;
    cin >> len;

    if (len < 1)
    {
        cout << len;
        return 0;
    }

    for (int i = 0; i < len - 1; i++)
    {
        ulli temp = b;
        b = a + b;
        a = temp;
    }

    cout << b;
}
```

익숙함에 속아 DP를 잃지 말자... 이 문제도 과거에 구했던 값을 이용해 입력값에 대한 정답을 구하는 DP 문제라는 것... 잊지 말자...

<br>
<br>

### 4. 다리 놓기<br>

<a href="https://www.acmicpc.net/problem/1010">1010. 다리 놓기</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/4_Lay_Bridge">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192277061-6f0ff448-52cb-4dbf-89df-8574a69e911b.png)

내 한참 모자른 수학 실력을 알 수 있었던 문제...

분명 문제를 보자마자 어? 경우의 수! 어? 팩토리얼! 어? 순열! 까지는 나왔지만... **어? 조합**이 안 나와버렸다...

분명히 순열 문제인데... 하면서 끙끄 앓다가... 

<br>

일단 인터넷을 보지 않고 문제를 풀려고 했지만... 우매한 내 머리에 든 수학 실력으로는 도저히 풀지 못할 것 같아서...

인터넷 대신 수학 선생님께 여쭤보았다.

<br>

선생님이 말씀하신 방법은 **조합**! 서쪽 다리에서 동쪽 다리를 순서 없이 모두 선택하는 방식이니까... 내가 생각했던 건 그냥 순열이지만...

<br>

```
nPr = n! / (n-r)!
```

조합은...

```
nCr = n! / ((n-r)!*r!)
```

<br>

그런데 여기서 문제가 생긴 게... **30 팩토리얼**이 unsigned long long int에도 담아지지 않는다는 것... 나는 선생님께 팩토리얼을 덜 구할 수 있는 조합을 어떻게 구하는지 여쭤보았고...

<br>

순서대로 고르는 게 같다면, 순서대로 버리는 것도 같다는 답을 얻었다.

<br>

따라서 이렇게 되는 것. 

```
nCr = nC(n-r)
```

그렇다면 `서쪽 다리의 개수 > 동다개-서다개`라면 위에 있는 식으로 치환해 계산해주면 되는 것! 그렇다면 최악의 경우가 나오더라도...

```
input => 30 30

30C30이지만...
30C0으로 계산하게 된다.

=> 1
```

<br>

코드!

```cpp
#include<iostream>
using namespace std;

typedef unsigned long long int ulli;

ulli Fac(int n, int cnt)
{
    if (n <= 1 || cnt == 0) return 1;
    return n * Fac(n - 1, cnt - 1);
}

int main()
{
    int tCnt;
    cin >> tCnt;

    while (tCnt--)
    {
        int a, b;
        cin >> a >> b;

        if (b - a < a)
            a = b - a;

        cout << Fac(b, a) / Fac(a, a) << '\n';
    }
}
```

아직 별로 많은 문제를 풀어보진 않았지만... 난 특히 수학에 더 약한 것 같다.

<br>

이런 문제를 푸는 데는 고등과정만으로도 충분하니, 학교에서 배우는 수학을 시험용으로만 배우지 말고, 문제를 푸는데 써먹어봐야겠다...

<br>
<br>

### 5. 돌 게임<br>

<a href="https://www.acmicpc.net/problem/9655">9655. 돌 게임</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/5_Rock_Game">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192318221-6e5df083-3b93-46f9-81a3-adf0f4ecdf93.png)

귀엽고 깜찍한 베스킨라빈스 써리 원 비슷한 문제였다. 

사실 이게 어떻게 DP 문제가 되는지 모르겠다... 난 그리디로 푼 것 같은데... 

<br>

내가 생각한 알고리즘은,

* 현재 마지막 돌이거나
* 내가 해당 돌을 N개 집으면 상대에게 우승을 줄 상황이거나
* 돌이 3개 미만이라 3개를 잡을 수 없을 때

**1개의 돌**을 집고, 그 외에는 3개의 돌을 집었다.

<br>

코드는 이러하다.

```cpp
#include<iostream>
using namespace std;

int main()
{
    int rock;
    bool isSk = false;
    cin >> rock;

    while (rock > 0)
    {
        // 마지막 돌이거나
        // 내가 3개를 가져갔을 때, 상대에게 기회가 오거나
        // 돌이 3개 이하일 때
        if (rock - 1 == 0 || rock - 4 == 0 || rock - 6 == 0 || rock < 3)
            rock -= 1;
        else
            rock -= 3;

        isSk = !isSk;
    }

    (isSk) ? cout << "SK" : cout << "CY";
}
```

구현은 했지만... DP에 대해서는 아직도 잘 모르겠고 막막하다...

<br>
<br>

### 6. Four Squares<br>

<a href="https://www.acmicpc.net/problem/17626">17626. Four Squares</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/6_Four_Squares">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192654101-2cb5228b-db2a-4ad9-9a9f-3b3c8ed25d33.png)

참신하고 재미있었던 문제!

자연수를 넷 이하의 제곱수의 합으로 표현할 수 있는 게 신기했다.

<br>

제곱수를 한 배열에 모으고, DFS를 이용해 탐색했다.

<br>

**알고리즘 설계**

1. 1부터 N까지의 **제곱수**를 벡터에 모은다.

2. 모은 제곱수를 내림차순으로 DFS를 돌려준다!
   
   제곱의 합이 내림차순으로 돌리는 이유는 대부분 큰 값으로 먼저 구성되기 때문!

3. `현재 값 + 추가할 값 > N`이거나 `현재 값 + 추가할 값 * 남은 횟수 < N`이라면. N보다  크거나 N과 같아질 수 없는 크기라면, 탐색할 이유가 없으므로 재귀를 돌려주지 않는다.

4. count가 4가 되거나, 그 전에 N을 만들었다면 재귀를 빠져나온다.

<br>

코드로 구현해보았다.

> DFS

```cpp
void DFS(int curNum = 0, int count = 4)
{
    if (curNum == target)
    {
        answer = min(answer, 4 - count);
        return;
    }

    if (count == 0) return;

    for (int i = sNumbers.size() - 1; i >= 0; i--)
    {
        // 합쳤을 때 타겟의 크기를 넘거나
        // count만큼 곱한 값을 합쳐도 target이 넘지 못할 때는
        // 재귀를 돌리지 않는다!
        if (curNum + sNumbers[i] > target || curNum + sNumbers[i] * count < target)
        {
            continue;
        }

        DFS(curNum + sNumbers[i], count - 1);
    }
}
```

> main

```cpp
int main()
{
    cin >> target;

    // 제곱수 모아주기
    for (int i = 1; i <= sqrt(50000); i++)
    {
        if (i * i > target) break;
        sNumbers.push_back(i * i);
    }

    DFS();

    cout << answer;
}
```

<br>

처음엔, N보다 큰 부분만 재귀를 돌려주지 않았다가, 시간 초과가 났다. 곰곰히 생각해보니, 큰 수가 들어온다면 **작은 제곱수들이 많은 시간을 잡아먹을 것** 같아서 재귀를 돌리는 걸 빼주었더니 시간 초과가 나지 않았다.

제곱수를 저장하는 부분이 DP 문제와 어울리는 풀이법 같다. 재미있었던 문제!

<br>
<br>

### 7. 1로 만들기<br>

<a href="https://www.acmicpc.net/problem/1463">1463. 1로 만들기</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/7_Make_1">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192656807-83b66688-fa32-442e-b304-a8136c896c34.png)

너무나도 그리디 문제 같이 생겼는데...

그리디로 계속 풀다가 결국 포기하고 DP로 푼 문제. 문제만 보면 그리디로 풀 생각을 하는 걸 고쳐야겠다고 생각했다.

<br>

처음 접근들은 앞서 말했다싶이 그리디로 했다. 그리고 생각나는 방법은 모두 해봤다.

* 가장 먼저 3으로 나누고, 2로 나누고, 1 빼기

* 가장 먼저 3으로 나누고, 1 뺀 값이 3의 거듭제곱이라면 1 빼기, 그리고 2 나누기

* N이 3의 거듭제곱이 될 때까지 1 빼기

* N이 3과 2의 공배수가 될 대까지 1 빼기

...

상당히 상당한... 방법들이었지만, 지금 모아보니 질보단 양에 초점을 맞춘 것 같다.

일단 이 로직이 안 되는 이유는 **3에 초점**을 맞췄기 때문!!

또, 나누는 것만이 최적해가 아니라는 것도 알아야 한다... 1로 뺄 때가 더 효율적일 때가 있다는 것. 

그리디 문제가 아니라면, 3과 2의 공배수일 때 2로 나누는 것이 더 최적해일 수 있다는 생각이 들었다.

<br>

그래서 DP로 풀었다. 애초에 DP 문제집에 있는 문제를 왜 그리디로 풀었는지는 모르겠다만...

로직은 이러하다.
<br>

1. 1~10^6까지의 길이의 정수형 배열을 만든다. 배열엔 i로 가기 위한 최소 연산 횟수를 넣어줄 것!

2. 배열의 초깃값을 `check[1] = 0, check[2] = 1, check[3] = 1`로 만들어준다. 연산이 1, 2, 3을 기반으로 하기 때문.

3. 4~N까지 반복문을 돌려가며 배열을 채워간다.
   
   * 2와 3의 공배수일 땐 `check[2/i]+1`와 `check[3/i+1]` 중 더 작은 것을 넣어준다.
     3으로 나누는 것만이 최적해는 아니기 때문!
   
   * 2의 배수일 땐 `check[2/i]+1`와 `check[i-1]` 중 더 작은 것을 넣어준다.
     
     * 3의 배수일 땐 `check[3/i]+1`와 `check[i-1]` 중 더 작은 것을 넣어준다.
     
     * 그 외엔 `check[i-1]`을 넣어준다.

<br>

코드로 구현해봤다.

```cpp
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int check[1000001] = { false, };

int main()
{
    int num;
    cin >> num;

    check[1] = 0;
    check[2] = 1;
    check[3] = 1;

    for (int i = 4; i <= num; i++)
    {
        int prev = check[i - 1];

        if (i % 6 == 0)
        {
            check[i] = min(check[i / 2], check[i / 3]) + 1;
        }
        else if (i % 2 == 0)
        {
            check[i] = min(prev, check[i / 2]) + 1;
        }
        else if (i % 3 == 0)
        {
            check[i] = min(prev, check[i / 3]) + 1;
        }
        else
        {
            check[i] = prev + 1;
        }
    }

    cout << check[num];
}
```

어려웠던 문제였다...

풀고 나니 간단한 문제였는데, DP로 생각하는 방식이 어려웠다... 그래도 DP로 풀어보니 재미있었다!!

<br>
<br>

### 8. 1, 2, 3 더하기<br>

<a href="https://www.acmicpc.net/problem/9095">9095. 1, 2, 3 더하기</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/8_Plus_1_2_3">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192787790-fd5130ac-e99b-4f70-a347-eb8692d8976f.png)

DP가 바로 이거구나! 알게 된 문제.

<br>

조금 고민해보다가... 생각해보니까 `1을 만들 수 있는 연산`, `2를 만들 수 있는 연산`, `3을 만들 수 있는 연산`을 가지고 계속 계속 다른 연산을 만들어가다보면 정답이 나오게 되는 것이었다!

<br>

만약에 4를 만든다고 하면...

```
input => 4

1 =>
1
arr[1] = 1

2 =>
1+1
2
arr[2] = 2

3 =>
1+1+1
1+2
2+1
3
arr[3] = 4

4 =>
4 = arr[1] + 3
4 = arr[2] + 2
4 = arr[3] + 1
이므로...

arr[4] = 1 + 2 + 4!

answer =>
7
```

<br>

코드로 구현해봤다.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tCnt;
    int dp[12] = { 0, };

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    // 현재 값 =
    // dp[i-1] + 1
    // dp[i-2] + 2
    // dp[i-3] + 3

    // 따라서 현재 연산 횟 = dp[i-1] + dp[i-2] + dp[i-3]

    for (int i = 4; i <= 11; i++)
    {
        dp[i] += dp[i - 1];
        dp[i] += dp[i - 2];
        dp[i] += dp[i - 3];
    }

    cin >> tCnt;

    while (tCnt--)
    {
        int input;
        cin >> input;
        cout << dp[input] << '\n';
    }
}
```

<br>

정말 제대로 내가 생각해서 DP 문제를 풀어봐서 기분이 좋았다. 아직은 쉬운 DP 문제이지만... 그래도...

그리고 여담으로 `#include<bits/stdc++.h>` 헤더를 알게 되었다. 친구가 알려줬는데, 헤더를 하나하나 불러오지 않아도 이 친구가 필요한 헤더를 거의 다 가지고 있다고 한다.

비주얼은 헤더를 다운로드해주었어야 했는데, 백준은 그냥 제출해도 되는 것 같다. 

<br>
<br>

### 9. 2xn 타일링<br>

<a href="https://www.acmicpc.net/problem/1463">1463. 1로 만들기</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/9_2xn_Tiling">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192801936-52990b92-a12b-4fa1-b5f5-9cb6383f8f22.png)

앞의 n이 1, 2, 3, 4, 5일 때의 테스트케이스를 구하고 점화식을 세운 문제!

신기하게도 **피보나치 수열**이 나왔다!!!

그림으로 그려본 테스트 케이스.

![제목 없음](https://user-images.githubusercontent.com/77655318/192804560-fd4ed401-aab3-4e6f-ad06-9a92096ce89d.png)

```
1 2 3 5 8...
```

어디서 본 식이다!

난 저 식을 보고 헉했다...

<br>

구현해 본 코드

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    unsigned long long int dp[1001] = { 0,1,2,3,0 };

    for (int i = 4; i <= 1000; i++)
    {
        dp[i] += (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cin >> n;
    cout << dp[n];
}
```

하지만... 사실 조금의 집녑과 운으로 맞춘 문제라... 어떻게 피보나치 식이 나오는지 몰랐다... 고민 고민해도 계속 모르겠어서 질문 검색 탭에서 한 게시물의 댓글을 봤다.

![image](https://user-images.githubusercontent.com/77655318/192805267-b6b4d91f-3326-4526-a0cd-9439afd3fdbc.png)

진짜 천재 같은 사람... 진짜 진짜 천재 같은 사람...

나도 저렇게 논리적으로 점화식을 짤 수 있도록... 다양한 DP 문제를 풀면서 실력을 키워야겠다... 기다려라 DP...

<br>
<br>

### 10. 계단 올라가기<br>

<a href="https://www.acmicpc.net/problem/2579">2579 계단 올라가기</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/10_Climbing_Staits">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192908300-073be677-026c-432e-9069-eda0c99c330c.png)
![image](https://user-images.githubusercontent.com/77655318/192908331-2067bc9f-ebe0-43bb-ac6c-53a1296c2043.png)

정말 무지무지 어렵게 느껴졌던 문제...

결국 혼자서 풀지 못하고 다른 사람의 코드를 보고 이해했다.

<br>

1. 첫번째 계단을 꼭 밟아야 한다고 생각한 것
2. 계단 세 칸 이상을 가면 안 된다는 조건을 고려하지 않은 것

<br>

처음엔 **정렬**을 썼다. 큰 수들의 계단을 먼저 고르고 세 번 연속 고르지 못하도록 bool형 배열을 써서 체크해주었다.

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> stairs;
int scores[300];
bool check[300] = { false, };
bool Check(int i, bool check[300]);

int main()
{
    int len, answer = 0;
    cin >> len;
    stairs.resize(len);

    for (int i = 0; i < len; i++)
    {
        cin >> stairs[i].second;
        stairs[i].first = i;
        scores[i] = stairs[i].second;
    }

    // staits 오름차순 정렬
    sort(stairs.begin(), stairs.end());

    // 첫 계단과  마지막 계단 건너기
    // 여기서 잘못했다... 첫 계단은 꼭 건널 필요가 없다...
    check[0] = check[len - 1] = true;

    // 점수가 큰 계단부터 건너준다
    for (int i = 1; i < stairs.size() - 1; i++)
    {
        int j = stairs[i].first;

        // 3번 연속 있는지 체크
        if (Check(j, check))
        {
            check[j] = true;
            answer += stairs[i].second;
        }
    }

    cout << answer + scores[0] + scores[len - 1] << endl;
}

// 3번 연속 있는지 체크해주는 
bool Check(int index, bool check[300])
{
    check[index] = true;
    int temp = 0, imax = 0;

    for (int i = -2; i <= 2; i++)
    {
        (check[index + i]) ? temp++ : temp = 0;
        imax = max(temp, imax);
    }

    check[index] = false;

    return (imax < 3);
}
```

코드는 나름 짰으나... 조건을 지키는 않은 답안에 정답이 있을리는 없었다.

틀린 이유를 분석하다가, 조건을 지키지 않은 것을 보고 얼른 새로운 로직을 생각해내려고 했다.

<br>

생각해내려고 했는데...

도무지 생각이 나지가 않았다.

정말 야자 시간을 모두 써서 이런 저런 생각도 해보고... 테스트케이스를 만들어 그럴듯한 코드도 짜봤지만... 역시 모두 실패였다.

<br>

그래서 결국 다른 사람의 코드를 보고, 이해하고 분석해서 내 것으로 만들기로 했다. ㅠㅠ

[[ 백준 2579 ] 계단오르기 (C++) :: 얍문's Coding World..](https://yabmoons.tistory.com/20)

이 분의 DP 코드를 참고했다.

<br>

점화식을 분석해보자면...

```
DP[1] = Stairs[1]
DP[2] = DP[1] + Stairs[2]
DP[3] = max(Stairs[1], Stairs[2]) + Stairs[3];

// 2 => 1>2
// 3 => 1>3 or 2>3

그럼 4, 5, 6... N은?

DP[N] = max(DP[N-2], Stairs[N-1] + DP[N-3]) + Stairs[N]
```

<br>

어렵지 않은 문제였는데...... 이상한 데에서 자꾸 뭘 추가하고 삽질을 하느라 시간이 오래 걸렸다...

분석한 걸 그림으로 정리해봤다.

![s](https://user-images.githubusercontent.com/77655318/192967321-dcade4cc-ce8c-4000-9b5a-808dc56d9525.png)

그림으로 정리하니 더 이해가 잘 된다.

나중에 다시 한 번 더 풀어볼 문제 같다...

<br>
<br>

### 11. 2xn 타일링 2<br>

<a href="https://www.acmicpc.net/problem/11727">11727 2×n 타일링 2</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/11_2xn_Tiling_2">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/192968936-f3280b70-4e86-4ded-a0c7-74abdafb4111.png)

9번 문제를 최근에 풀어서 쉽게 풀 수 있었던 문제!!

<br>

![image](https://user-images.githubusercontent.com/77655318/192805267-b6b4d91f-3326-4526-a0cd-9439afd3fdbc.png)

다시 꺼내보는 이 분의 말씀대로 `l가 온다면 n-1의 가로 길이를 가진 2*n 타일의 경우의 수`, `=일 경우는 n-2`이다.

그런데 지금은 =를 합친 것 같은 네모가 있으므로 `n-2`의 경우가 하나 더 증가하는 것이다! 그러므로 식은

![ffffs](https://user-images.githubusercontent.com/77655318/192969902-b6595b78-59d9-47cd-98f7-73c7bec392bb.png)

```
Arr[1] = 1
Arr[2] = 3

Arr[3] = 5

Arr[N] = Arr[N-1] + 2 * Arr[N-2]
```

역시 전 문제를 풀고 오니까 확실히 유사한 문제는 쉬웠다!!

이게 많은 문제를 풀어보고 공부해야 하는 이유 같다... 재미있었다.

<br>
<br>

### 12. 조합<br>

<a href="https://www.acmicpc.net/problem/2407">2407 조합</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/12_Combination">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/193183014-57323b88-96e6-48d4-9624-653f2f211a35.png)

조합을 쓰는 문제! 다리 놓기랑 비슷한 문제라고 생각했지만...

```
(5 ≤ n ≤ 100, 5 ≤ m ≤ 100, m ≤ n)
```

많이 커진 입력값이 문제였다. 

```
nCm = nC(n-m)
```

이 공식도 고려해봤을 때... 가장 큰 출력을 일으키는 입력은 `n=100, m=50`이다. 이걸 조합으로 계산해봤을 땐...

![image](https://user-images.githubusercontent.com/77655318/193183220-a4120bba-6b44-44cd-8c43-e4f5b2288a50.png)

```
unsigned long long int
=> 18446744073709551615

100C50
=> 100891344545564193334812497256
```

망했다고 볼 수 있었다. 

<br>

설마 해서 분수를 나누고 어떻게 해서 몇 번을 코드를 써서 제출해봤지만 결과는 실패...

<br>

c++에 더 큰 자료형을 찾아보다가, 백준의 채점 컴파일러 **gcc**에서는 **__uint128_t**라는 128비트의 정수 자료형을 제공해준다는 이야기를 들었다.

비주얼 스튜디오에서 실행해봤더니... 오류가 떴다.

![image](https://user-images.githubusercontent.com/77655318/193184134-18dad35b-c15e-416d-9010-e5f949737008.png)

비주얼 스튜디오는 gcc 컴파일러를 지원하지 않는 건가?

<br>

난 그래서 웹 컴파일러로 찾아서 돌렸고, 애석하게도 저 자료형은 **바로 출력이 지원되지 않는다는 것**을 알았다.

그리 치명적인 문제는 아니었다. 배열에 뒤에서부터 각 자리의 숫자를 int형으로 담아준 다음에, 리버스를 해서 출력했다.

<br>

**알고리즘 설계**

1. m이 n-m보다 크면 m에 n-m을 대입한다.
   
   ```
   5C3 = 5C2
   ```

2. 분모는 오름차순, 분자는 내림차순으로 곱해준다.

```
5 x 4     5       4
----- = --- x ---
2 x    1     1     2

= 10
```

3. 128바이트의 자료형이 0이 될 때까지 10으로 나눈 값을 벡터에 넣고, 10으로 나눈다.

4. 벡터를 역순 출력한다!

<br>

**코드**

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    __uint128_t answer = 1;
    vector<int> v;
    int n, m;
    cin >> n >> m;

    // nCm = nC(m-n)
    if (m > n - m)
        m = n - m;

    // 조합 계산
    for (int i = 0; i < m; i++)
    {
        answer *= (n - i);
        answer /= (i + 1);
    }

    // 벡터에 역순으로 넣기
    while (answer)
    {
        v.push_back(answer % 10);
        answer /= 10;
    }

    // 리버스
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}
```

어려웠던 문제... __uint128_t... 기억해놔야겠다...

<br>
<br>

### 13. 가장 긴 증가하는 부분 수열<br>

<a href="https://www.acmicpc.net/problem/11053">11053 가장 긴 증가하는 부분 수열</a><br>

<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/13_Longest_Increasing_Subsequence">문제 풀이</a><br>


---

<div align="center">

## 📒 문제집 외 문제 📒

<br>

</div>

### 파스칼의 삼각형<br>

<a href="https://www.acmicpc.net/problem/16395">16395. 파스칼의 삼각형</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DP1/Pascal's_Triangle.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/193612241-e729b999-cb86-4121-8bca-89dbcd255ab1.png)

파스칼의 삼각형 문제!

파스칼의 삼각형 개념을 로직으로 옮기면 되는 간단한 문제였다.

<br>

**알고리즘 설계**

1. N층에 있다면, 1번째와 N번째 요소는 1로 만들어준다.

2. 현재 M번째라고 하면, 그 외에 요소는 arr[N-1][M-1] + arr[N-1][M]

3. 입력 층까지 반복한다.

<br>

**코드**

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dp[30][30], y, x;
    cin >> y >> x;

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i > 0 && j > 0 && j != i)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = 1;
            }
        }
    }

    cout << dp[y - 1][x - 1];
}
```