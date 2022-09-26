[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# Dynamic Programming 1

동적 프로그래밍을 이용하여 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩⬛⬛⬛⬛⬛⬛⬛⬛⬛<br>
_11%_
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