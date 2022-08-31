<div align="center">

# Math


수학을 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩🟩🟩🟩🟩⬛⬛⬛⬛<br>
_61%_
<br><br><br>

</div>


### 1. 공약수<br>
<a href="https://www.acmicpc.net/problem/5618">5618. 공약수</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/1_Common_Factor.cpp">문제 풀이</a><br>

아주 간단한 수학 문제였다.

a, b, c 변수 중 (a, b)만 받을 수도, (a, b, c) 모두 받을 수도 있다.<br>

``` cpp
cin >> n;
cin >> a >> b;
if (n > 2) cin >> c;

if (b > a) swap(a, b);
if (c != 0 && b > c) swap(b, c);
```

받은 가장 작은 수를 b로 놓고 **1부터 b까지** for문을 돌리며 입력받은 수 모두 나머지가 0이면 그 수를 출력해주는 로직이다.


<br><br>


### 2. 피로도<br>
<a href="https://www.acmicpc.net/problem/22864">22864. 피로도</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/2_Fatigue_Degree.cpp">문제 풀이</a><br>

간단한 문제였다.<br>

한 시간마다 어떤 행동을 할 것인지 결정되고 하루는 24시간이기 때문에 **24번 반복문**을 돌려주고, 그 안에서 휴식할 것인지 일할 것인지를 **결정하고 이행**했다.

``` cpp
for (int i = 0; i < 24; i++)
{
	// 일했을 때 피로도가 번아웃 지수보다 같거나 작다면
	if (curFatigue + fatigue <= burnout)
	{
		// 일한다
		curFatigue += fatigue;
		result += work;
	}
	else
	{
		// 휴식한다
		curFatigue -= reduce;
		if (curFatigue < 0) curFatigue = 0;
	}
}
```

뭐든지 이렇게 쉽게 수치화가 된다면 좋겠다.


<br><br>


### 3. 진법 변환<br>
<a href="https://www.acmicpc.net/problem/2745">2745. 진법 변환</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/3_Number_Conversion.cpp">문제 풀이</a><br>

오만번쯤은 해봤을 진법 변환...<br>

이지만 지금까지 나는 2, 8, 16진수만 변환해봤지만, 이 문제는 2~36진수까지 변환해야하는 문제였다. 그래도 어렵지는 않았던 문제!<br>

이지만 한 가지 치명적인 실수를 한 나... 그 덕에 10분 정도 고민했다. 실수는 바로 10진수로 변환할 때 **앞자리부터 계산**했다는 것...

![제목 없음](https://user-images.githubusercontent.com/77655318/183007264-ddb78579-54af-4913-959d-013603c21513.png)

엉엉 하필이면 또 예제가...

```
ZZZZZ 36,
1111 2
```

같은 앞뒤가 똑같은 것들이라 왜 틀린지 몰랐었다... 바보...

``` cpp
for (int i = 0; i < input.size(); i++)
{
	// 거꾸로 계산
	// etc) 8 4 2 1
	int index = input.size() - i - 1;

	if (isalpha(input[index]))
	{
		// A = 10, B = 11...
		result += (input[index] - 'A' + 10) * pow(offsetNum, i);
	}
	else
	{
		result += (input[index] - '0') * pow(offsetNum, i);
	}
}
```

이렇게 간단하게 풀었다. 간단하게 보이는 문제라도 정신 똑디 잡고 문제를 풀어야겠다. 


<br><br>


### 4. 더하기 사이클<br>
<a href="https://www.acmicpc.net/problem/1110">1110. 진법 변환</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/4_Plus_Cycle.cpp">문제 풀이</a><br>

간단한 수학 문제!<br>

계속해서 이어지는 사이클을 **Queue**를 통해서 해결했다.

``` cpp
do 
{
	int val1 = queue.front() - '0';
	queue.pop();
	int val2 = queue.front() - '0';

	queue.push(to_string(val1 + val2).back());
	++count;

} while (queue.front() != input[0] || queue.back() != input[1]);
```

사이클의 메인 로직은 이러한데, 이해하기 쉽게 이미지로 표현하자면...

![제목 없음](https://user-images.githubusercontent.com/77655318/183276769-778a52a8-772c-45b5-94d9-9bbde8db6af4.png)

이렇게 된다. 그림은 좀 못그렸지만...

<br>

```
input
=> 26

process...
1  	68
2	84
3	42
4	26 same!

answer
=> 4
```

이런 과정을 거치는 것! 쉽지만 재미있는 문제였다.


<br><br>


### 5. 최대공약수와 최소공배수<br>
<a href="https://www.acmicpc.net/problem/2609">2609. 최대공약수와 최소공배수</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/5_GCD_And_LCM.cpp">문제 풀이</a><br>

간단한 수학 문제<br>

``` cpp
if (b>a)
	swap(a, b);
```

무조건 a가 b보다 크게 만들어준 다음, <br>

``` cpp
for (int i = 2; i <= b; i++)
	if (a % i == 0 && b % i == 0)
```
**최대공약수**는 기본값을 1로 해놓고, 2부터 b까지 차례대로 반복문을 돌려 구하고,


``` cpp
for (int i = a; i <= a * b; i++)
	if (i % a == 0 && i % b == 0)
```
**최소공배수**는 a부터 a * b까지 반복문을 돌려서 구했다!


<br><br>


### 6. 최소공배수<br>
<a href="https://www.acmicpc.net/problem/1934">1934. 최소공배수</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/6_Least_Common_Multiple.cpp">문제 풀이</a><br>

위 문제를 응용... (복붙)해서 풀어야지! 라고 생각했던 문제지만, 보기 좋게 **시간 초과**가 났다.<br>

a부터 a * b까지 계속 돌리는 방식이다 보니... 어쩌면 시간 초과가 날 수밖에 없었다.<br>

그래서 **아래 공식**을 이용하기로 했다!
```
LCM(a,b) = a*b / GCD(a, b)
```

그리고 GCD(최대공약수)를 구하기 위한 최적의 방법은 **유클리드 호제법**이라고 생각했기 때문에...

![image](https://user-images.githubusercontent.com/77655318/185903914-33e954f0-01de-4ce3-b9fb-8c40cd2b4fa0.png)

GDC를 구할 수 있는 알고리즘이다. 즉,

```
GCD(a, b) == GCD(b, a%b)
```

인 것!<br>

재귀함수를 이용해서 풀 수 있었지만, 재귀보다 while문이 좋을 거라고 판단해 while문으로 GCD를 구했다.

``` cpp
while (b != 0)
{
	int r = a % b;
	a = b;
	b = r;
}
// a == GCD(a,b)
```

그리고 성공! 유클리드 호제법에 대해서 처음 알게된 문제였고, 그게 효율적이라고 생각하게 한 문제였다.


<br><br>


### 7. 소수<br>
<a href="https://www.acmicpc.net/problem/2581">2581. 소수</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/7_Prime_Number.cpp">문제 풀이</a><br>

소수를 구할 때 2중 for문을 써도 되는 문제라 간단하게 풀 수 있었다!

<br>

``` cpp
for (int i = m; i <= n; i++)
{
	int count = 0;
	
	for (int j = 1; j <= i; j++)
	{
		if (count > 2) break;
		if (i % j == 0) ++count;
	}
	
	if (count == 2)
	{
		if (sum == 0) min = i;
		sum += i;
	}
}
```

소수는 **약수의 개수**가 **1과 자신을 포함해 2개**뿐이다. 따라서 count가 2일 때 소수 체크를 해주었다. <br>

그리고 불필요한 연산을 줄이기 위해 count가 2가 넘으면 바로 반복문을 나가게 해주었다. <br>

곧 에라토스테네스체를 활용한 소수 구하기 문제가 나올 텐데, 그때도 잘 풀어보고 싶다!!


<br><br>


### 8. 소인수분해<br>
<a href="https://www.acmicpc.net/problem/11653">11653. 소인수분해</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/8_Factorization.cpp">문제 풀이</a><br>

지금 생각하면 엄청 간단하지만 생각하기 조금 어려웠던 문제... <br>

내 얕고도 좁은 수학 머리가 흔들거렸다... <br>

처음에는 소수로만 나누어야 하니까 2, 3, 5, 7... 등 **소수만 배열**로 미리 만들어 for문을 돌릴 생각을 했지만... 그건 아무래도 진짜 아닌 것 같았다. <br>


그래서 곰곰히 생각해보니 4나 6같은 합성 수들 굳이 **걸러야 할 이유**가 없다는 걸 알게 된 나...


``` cpp
while (number > 1)
{
	for (int i = 2; i <= number; i++)
	{
		if (number % i == 0)
		{
			cout << i << '\n';
			number /= i;
			break;
		}
	}
}
```

2부터 number까지 돌게 만들었다. 조건에만 얽매이지 말고 코드의 흐름을 볼 수 있도록 노력해야겠다.



<br><br>


### 9. 소수 찾기<br>
<a href="https://www.acmicpc.net/problem/1978">1978. 소수 찾기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/9_Find_Prime_Number.cpp">문제 풀이</a><br>

7번 문제인 소수 찾기 문제와 비슷해서 간단하게 풀 수 있었다. <br>

입력 값이 적어 2중 for문으로도 시간 초과가 나지 않을 거라 생각했고, 저장할 데이터가 많지 않아 배열을 굳이 쓰지 않았다. 소수를 구하는 코드를 함수로 빼서 간단하게 for문으로 소수임을 판단했다.<br>

``` cpp
for (int i = 0; i < len; i++)
{
	int input;
	cin >> input;
	
	// 함수 내용은 7번 문제 코드와 같음
	if (is_prime(input))
		answer++;
}
```

다음 문제인 에라토스테네스의 체를 빨리 풀어보고 싶다!!


<br><br>


### 10. 에라토스테네스의 체<br>
<a href="https://www.acmicpc.net/problem/2960">2960. 소수 찾기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/10_Sieve_of_Eratosthenes.cpp">문제 풀이</a><br>

기대하고 고대하던 **에라토스테네스의 체**를 이용해서 푸는 문제!! <br>

1학년 때 엄청 어려워하면서 풀었던 기억이 있었는데, 알고리즘이 자세히 설명되어있어서 간단하게 풀 수 있는 문제였다. 아무리 간단한 문제라고 해도, 처음에 소수만 체로 거를 생각을 한 에라토스테네스가 천재 같다... <br>

![image](https://user-images.githubusercontent.com/77655318/187479775-b9b90a69-9d71-4250-b73a-801ee3b4ba25.png)

신기해서 코드가 돌아가는 흐름을 담은 동영상을 가져와봤다.

![Sieve_of_Eratosthenes_animation](https://user-images.githubusercontent.com/77655318/187480130-61a934ec-1332-4130-a210-038e521ab7de.gif)

천재 만재 에라토스테네스<br>

문제에 나와있는대로 구현해봤다.


``` cpp
for (int i = 2; i <= n; i++)
{
	// 이미 체크한 숫자면 continue
	if (check[i]) continue;

	int p = i;

	while (p <= n)
	{
		// 이미 체크한 숫자면 체크하지 않는다
		if (!check[p])
		{
			check[p] = true;

			// K번째 지울 수일 때
			if (--k == 0)
			{
				cout << p << endl;
				return 0;
			}
		}

		// p의 배수를 순서대로 (ex) 3, 6, 9...)
		p += i;
	}
}
```

작년과 비슷하게 구현한 것 같다. 비록 구현 방법이 문제에 다 나와있지만, 작년보다 크게 성장한 것 같아서 기분이 좋다. 꾸준히 알고리즘 문제를 풀어나가서 지금 푸는 문제 정도는 눈 감고도 간단히 풀 수 있을 실력이 되고 싶다. 파이팅!


<br><br>


### 11. LCM<br>
<a href="https://www.acmicpc.net/problem/5347">5347. LCM</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/11_LCM.cpp">문제 풀이</a><br>

기본기에 중요성을 알게 해준 문제<br>

6번에서 최소공배수를 구하는 공식으로 문제를 풀어봤다.

```
LCM(a,b) = a*b / GCD(a, b)
```

GCD를 구할 때는 유클리드 호제법을 이용했고, 모든 게 순조롭다고 생각했지만... <br>

입력값이 1000000, 1000000인 최댓값일 때 오버플로우가 발생하는 것을 생각하지 못했다... <br>

```
LCM(100000, 100000) = 100000 ^ 2 / GCD(100000, 100000)
// 무려 천억...
```

이기 때문에 짱짱하고 안전한 long long을 반환하는 것으로 해결했다. 예제에 있는 테스트케이스만을 보지 말고 한계값을 테스트해보는 시도를 해봐야겠다.
