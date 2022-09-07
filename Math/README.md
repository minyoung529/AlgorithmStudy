[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)


<div align="center">

# Math


기초 수학을 이용하여 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩<br>
_100%_
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


<br><br>


### 12. 다음 소수<br>
<a href="https://www.acmicpc.net/problem/4134">4134. 다음 소수</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/12_Next_Prime_Number.cpp">문제 풀이</a><br>

또 소수를 구하는 문제다. 또수... <br>

그러나 이번 문제는 조건이 악독했다... 나는 지금까지 모든 소수 구하기 문제의 만병통치약은 에라토스테네스의 체인 줄 알고 맹신했지만...

```
n(0 ≤ n ≤ 4*10^9)
```

라는 조건에 머리가 텅 비어버렸다...

```
bool check[4000000000] = {false,}

for(int i = 0; i <= 4000000000; i++)...
```

이런 이상스러운 짓을 할 수는 없었으므로 완전 탐색을 하는 것이 유일한 방법이라고 생각했지만... <br>

내가 아는 소수구하기는 1부터 N까지 약수의 개수를 구하는 것이라... 1부터 40억까지 약수인지 아닌지 판별하는 것은 무리라고 생각했다. <br>

짧은 인터넷 검색 끝에 1부터 N이 아닌 **2부터 N 제곱근이 N의 약수인가**를 판별해도 소수를 구할 수 있다는 것을 알게 되었다.

``` cpp
bool is_prime_number(long long num)
{
	long long sqrtNum = sqrt(num);

	for (long long i = 2; i <= sqrtNum; i++)
	{
		if (num % i == 0)
			return false;
	}

	return (num > 1);
}
```

0이나 1이 아닌 수들을 걸러주는 거로 함수를 만들었다. 재밌는 문제였다.


<br><br>


### 13. 서로소 평균<br>
<a href="https://www.acmicpc.net/problem/21920">21920. 서로소 평균</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/13_Coprime.cpp">문제 풀이</a><br>

여러 수들 사이에서 기준이 되는 수와 서로소인지 찾고, 서로소들끼리의 평균을 구하는 문제.<br>

1초 안에 서로소임을 빠르게 체크해야 하는 문제였다. <br>

서로소의 정의는 **공약수가 1뿐인 두 정수**이므로 두수의 **최대 공약수가 1이라면** 그 두 수는 서로소인 것이다!

<br>

나는 최대공약수를 빠르게 구할 수 있는 유클리드 호제법을 이용하여 문제를 풀 수 있었다.


``` cpp
for (int i = 0; i < len; i++)
{
	int a = arr[i];
	int b = x;

	if (a > b) swap(a, b);

	// 최대공약수를 유클리드 호제법으로 구함
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	// 두 수의 최대 공약수가 1이라면
	if (a == 1)
	{
		coprimeCount++;
		sum += arr[i];
	}
}

// 평균 출력
cout << sum / (double)coprimeCount;
```

최대공약수나 최소공배수 모두 기초 수학 알고리즘 문제를 풀 때는 요긴하게 잘 쓰이는 것 같다! <br>

최대공약수를 구할 수 있는 유클리드 호제법`GCD(a, b) == GCD(b, a%b)`이나, 최소공배수를 구할 수 있는 공식 `LCM(a,b) = a*b / GCD(a,b)`을 머릿속에 잘 저장해두어야겠다.



<br><br>


### 14. GCD 합<br>
<a href="https://www.acmicpc.net/problem/9613">9613. GCD 합</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/14_GCD_Sum.cpp">문제 풀이</a><br>


가능한 모든 쌍의 GCD의 합을 구하는 문제. <br>

킹클리드 호제법과 재귀함수를 써서 풀수 있었다.

![image](https://user-images.githubusercontent.com/77655318/188029687-1ea05675-ffb9-4fda-b37b-a345428f7365.png)


이러한 알고리즘을 설계했다.

<br>

> 짜본 재귀 함수의 코드
``` cpp
int GetGCD(int curIndex, int nextIndex, vector<int> arr, int sum)
{
	// 비교할 값이 없으면 멈춘다
	if (nextIndex >= arr.size())
	{
		return 0;
	}

	int a = arr[curIndex];
	int b = arr[nextIndex];

	// 유클리드 호제법
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	// 각 GCD를 합해서 반환
	return a + GetGCD(curIndex, nextIndex + 1, arr, a);
}
```

> 재귀 호출

``` cpp
for (int j = 0; j < count - 1; j++)
	answer += GetGCD(j, j + 1, arr);
```

재미있었던 문제이다. 오랜만에 재귀함수를 써서 더 재밌었다... ㅎㅎ


<br><br>


### 15. 폰 호석만<br>
<a href="https://www.acmicpc.net/problem/21275">21275. 폰 호석만</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/15_Pon_Hoseogman.cpp">문제 풀이</a><br>


![image](https://user-images.githubusercontent.com/77655318/188271808-179a6bc3-1c96-460c-903a-7d2f183d0524.png)

폰 호석만보다 더 뛰어난 진법 변환 장인이 된 느낌이었다.

<br>

문제를 풀기 위한 알고리즘 설계는...

1. 2진수부터 36진수까지의 A와 B를 **10진수로 변환한 값**을 **배열**에 넣는다.


> 변환 코드
``` cpp
long long Converter(int base, string number)
{
	long long result = 0;

	for (int i = number.size() - 1; i >= 0; i--)
	{
		int count = number.size() - i - 1;

		// alphabet
		if (isalpha(number[i]))
			result += (long long)((number[i] - 'a' + 10) * pow(base, count));

		// digit
		else
			result += (long long)((number[i] - '0') * pow(base, count));
	}

	return result;
}
```

> 2진수부터 36진수까지 계산해서 배열에 넣음
``` cpp
void Calculate(vector<long long>& arr, string str)
{
	// 최댓값 M
	char max = *max_element(str.begin(), str.end());

	// 2 ~ 36진법
	for (int i = 2; i <= 36; i++)
	{
		// M진수 이하일 때는 계산하지 않음
		if (isalpha(max) && i <= max - 'a' + 10)
			arr.push_back(-1);

		else if (isdigit(max) && i <= max - '0')
			arr.push_back(-1);

		else arr.push_back(Converter(i, str));
	}
}
```
 
A와 B의 각 숫자의 최댓값이 M이라고 하면, M + 1부터 36진수까지만 10진수로 변환한다.

2. A와 B 배열 중 서로 **같은 수**가 있는지 확인한다.

> 비교 코드
``` cpp
for (int i = 0; i < 35; i++)
{
	// 조건에 맞지 않으면 비교 X
	if (aArr[i] == -1 || aArr[i] >= pow(2, 63)) continue;

	auto bFind = find(bArr.begin(), bArr.end(), aArr[i]);

	// 같은 수를 발견하고 같은 진수가 아닐 때
	if (bFind != bArr.end() && i != bFind - bArr.begin())
	{
		results.push_back({ aArr[i], i + 2, bFind - bArr.begin() + 2 });
	}
}
```

X가 2^63 이상이거나 a를 N진수를 비교할 수 없을 때는 비교하지 않는다.

<br>

같은 수가 있다면 **정답 배열**에 저장한다.

4. 정답 배열의 길이가 0이면 **"Impossible"**, 1이면 그 값을, 1 이상이면 **"Multiple"**을 출력한다.

``` cpp
if (results.empty())
	cout << "Impossible";

else if (results.size() > 1)
	cout << "Multiple";

else
	cout << results.front().x << " " << results.front().a << " " << results.front().b;
```

좀 복잡했지만, 진법 변환 마스터 폰 호석만만큼 진법 변환에 익숙해진 것 같다. 재밌는 문제!


<br><br>


### 16. 소수 최소공배수<br>
<a href="https://www.acmicpc.net/problem/21919">21919. 소수 최소공배수</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/16_Prime_Number_LCM.cpp">문제 풀이</a><br>


![image](https://user-images.githubusercontent.com/77655318/188278644-80c64e9f-e9a8-480c-9e81-296a17407d0b.png)


어려운 문제도 아닌데 작은 실수 때문에 꽤 애먹었던 문제...


<br>


소수는 **에라토스테네스의 체**로, 최소공배수는 공식`LCM(a,b) = a*b / GCD(a,b)`으로 풀 수 있었다. <

<br>

소수를 구할 땐 같은 수를 배제하는 set을 사용했다. 3개 이상의 최소공배수를 구할 때는 **재귀함수**를 이용해서 1번째와 2번째의 최소 공배수, 그 최소 공배수와 3번째의 최소 공배수... 이렇게 구했다.

``` cpp
void CalculateLCM(long long lcm, int index)
{
	if (index >= v.size() || v.size() == 1)
	{
		cout << lcm;
		return;
	}

	// GCD
	long long a = lcm;
	long long b = *next(v.begin(), index);

	if (a > b) swap(a, b);

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	// LCM
	lcm = (*next(v.begin(), index) * lcm / a);
	CalculateLCM(lcm, ++index);
}
```

<br>

여기까지는 좋았는데, 문제는 에라토스테네스의 체와 내 멍청한 실수 때문에 문제 푸는데 걸리는 시간이 두 배가 된 것 같다.

<br>

첫번째 에라토스테네스의 체는...

``` cpp
for (int i = 2; i <= sqrt(LIMIT); i++)
{
	if (check[i])
	{
		// ...
	}
}
```

LIMIT의 제곱근까지만 돌려주어야 했었는데...

``` cpp
for (int i = 2; i <= sqrt(LIMIT); i++)
```

바보 같이 LIMIT까지 돌려준 것이다... 정말 바보...

<br>

두 번째는 한계값 문제였다. 전처리기로 한계값 상수를 정해주었다. 문제 조건이 `X < 1,000,000`였으므로...

``` cpp
#define LIMIT 1000000
```

이렇게 해주었어야 했는데...

``` cpp
#define LIMIT 100000
```

0 하나를 빼먹은 것이다! 진짜 진짜 바보... 

<br>

이런 자잘자잘자잘자잘한 실수 하지 않도록 노력해야겠다. 정신 꽉 잡고 문제 풀자!



<br><br>


### 17. 소수&팰린드롬<br>
<a href="https://www.acmicpc.net/problem/1747">1747. 소수&팰린드롬</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/17_Prime_Number_And_Palindrome.cpp">문제 풀이</a><br>


![image](https://user-images.githubusercontent.com/77655318/188318692-725a060f-8ab0-46ed-b6bf-2b1c5aea9aa5.png)

소수 구하기는 에라토스테네스의 체로, 팰린드롬은 int형 변수를 string으로 바꾸어서 각각의 문자를 비교해주었다.

<br>

에라토스테네스의 체로 입력값 이상의 수들을 **모두 소수인지, 아닌지 판별**해야했기 때문이다. 한계값`1 <= N <= 1000000`이 확실한 조건을 이용해서 길이가 1000001인 bool형 배열을 만들고, 완전 탐색으로 소수를 찾았다.

<br>

라는 생각은 좋았지만... 문제는 **1000000이상인 소수 & 팰린드롬**을 충족해야했기 때문에 소수를 배열의 길이가 1000001으로 부족했던 것!

<br>

그래서 배열의 길이를 임의로 늘리고 한계값을 넣어본 결과...

![image](https://user-images.githubusercontent.com/77655318/188318940-b1059132-7c8e-4046-92ff-cc313b7719af.png)

**1003001**이 나온 것이다. 그래서 배열의 길이는 1003002가 되었다.

``` cpp
#define LIMIT 1003001
bool check[LIMIT + 1];
```

<br>

**회문 판별**은 앞에서 말했듯이 int형 변수를 **string**으로 바꾸어서 했다. 그렇게 하는 편이 구성된 **문자 하나하나를 접근**할 수 있어서 편하다고 생각했기 때문!

> 회문인지 아닌지 판별하는 함수

``` cpp
bool IsPalindrome(int number)
{
	string str = to_string(number);

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != str[str.size() - i - 1])
		{
			return false;
		}
	}

	return true;
}
```

간단하고 재미있었던 문제!



<br><br>


### 18. 수<br>
<a href="https://www.acmicpc.net/problem/22943">22943. 수</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/18_Number.cpp">문제 풀이</a><br>

문제 이름은 한 글자인데..... 난이도가 별 하나가 아니었다!!!! 어렵게 느꼈던 문제...

<br>

다 풀어보니 사실 그렇게 어려운 문제는 아니었지만... **여러 단계**를 걸쳐서 수를 추려내는 문제였기 때문에 어느 한 코드라도 구멍이 나지 않게 디버깅하고 코드를 짜는 게 어려웠다...

<br>

실수도 많이 했는데, 했던 실수 리스트를 적어보자면

* memset 써놓고 string.h 헤더 안 쓰기
* 소수 잘못 추려내기...

이건 진짜 진짜 진짜 찐 바보같은 짓인데... 에라토스테네스의 체의 반복문 안에서 소수만 담는 배열에 넣으려고 했다.

``` cpp
	for (int i = 2; i * i < LIMIT; i++)
	{
		if (check[i])
		{
			// 이렇게 담음
			pNums.push_back(i);
			
			for (int j = i * i; j < LIMIT; j += i)
				check[j] = NONE;
		}
	}
```

무슨 생각이었는진 모르겠지만... 이렇게 코드를 쓴다고 소수가 모두 담아질 거라 생각한 내가 정말 바보인 것 같다.

<br>

하필이면 예제가 작은 수였기 때문에... 예제는 모두 맞은 상태로 **"이게 왜 안 돼!"** 상태가 되는 것이었다. 어쩐지 범위가 커질 수록 오차가 벌어지더라니...

<br>

``` cpp
for (int i = 2; i < LIMIT; i++)
{
	if (check[i])
		pNums.push_back(i);
}
```

이렇게 고치니 소수가 모두 담아졌다 ^_^!!


* 구해진 숫자마다 소수끼리의 곱셈인지 일일이 구하기

``` cpp
bool CheckM(int number)
{
	while (number % m == 0)
		number /= m;

	for (int i = 0; i < pNums.size(); i++)
	{
		for (int j = i; j < pNums.size(); j++)
		{
			long long result = ((long long)pNums[j] * (long long)pNums[i]);
			
			if(result > number)
				break;
				
			if (result == number)
				return true;
		}
	}
}
```

요 2중 반복문을 1부터 9로 구성된 최대 다섯자리 수들로 돌린다니. 말도 안 되는 생각이었다.

<br>

에라토스테네스의 체에서 슨 bool형 배열을 개조해서 이용해보았다.


<br>


최종적으로 구현된 알고리즘을 살펴보겠다.

<br>

먼저, 소수만을 판별하던 bool형 변수는 **소수인지 아닌지**, **소수끼리 곱해지는 수인지 아닌지**에 대한 정보를 모두 담기 위해서 **비트 플래그**를 이용했다.

![image](https://user-images.githubusercontent.com/77655318/188575964-0d9e10bd-c26e-4db1-8dae-b1c9eadfdc74.png)

이렇게! 

<br>

그래서 에라토스테네스의 체로 거르기 전에는 **모두 소수**(1)였다가 거르고 나면 소수 여부에 따라서 0과 1이 되고, 소수끼리 곱해지는지 판별해 **2를 OR 연산**을 해주면 된다.

``` cpp
#define LIMIT		100000
#define NONE		0
#define PNUMBER		1
#define MULTIPLY	2

short check[LIMIT + 1];
vector<int> pNums;

// ...

// int main...

// 모두 소수(PNUMBER) 상태로 만들어 놓는다.
memset(&check, PNUMBER, sizeof(check));

// 에라토스테네스 체로 NONE 상태를 만들어 놓는다.
for (int i = 2; i * i < LIMIT; i++)
{
	if (check[i])
	{
		for (int j = i * i; j < LIMIT; j += i)
			check[j] = NONE;
	}
}

// 소수를 모아놓은 배열을 추가한다.
for (int i = 2; i < LIMIT; i++)
{
	if (check[i])
		pNums.push_back(i);
}

// 소수 배열을 차례대로 돌아가며 곱한다.
for (int i = 0; i < pNums.size(); i++)
{
	for (int j = i; j < pNums.size(); j++)
	{
		long long result = ((long long)pNums[j] * (long long)pNums[i]);

		if (result > LIMIT) break;

		// 곱한 값을 MULTIPLY(2)를 OR 연산을 해준다.
		check[result] |= MULTIPLY;
	}
}
```

이렇게 배열의 값을 설정해준 다음에, **DFS**를 이용해서 0부터 9까지 구성된 K자리의 숫자를 순회한다.

<br>

``` cpp
// DFS 함수
// len => K, len자릿수의 수를 만들어 순회한다
// v => 0~9까지의 숫자 중 이미 쓴 숫자를 제외하는 벡터
// num => 만들고 있는 숫자
void Check(int len, vector<int> v, int num)
{	
	// 목표 길이가 되면
	if (v.size() == 10 - len)
	{
		// 서로두 수의 덧셈인지, 두 소수의 곱셈인지 체크
		if (CheckM(num) && CheckPlusPrimeNumber(num))
		{
			result++;
		}

		return;
	}

	// 첫 수가 0이면 안되므로 (0143 X)
	int start = (v.size() == 10) ? 1 : 0;

	for (int i = start; i < v.size(); i++)
	{
		vector<int> tempVec = v;

		// 연장할 임시 변수
		int temp = num;

		// 다음 수를 연장함
		// ex) 34 => 340 => 341
		num *= 10;
		num += v[i];
		
		// 연장한 숫자를 벡터에서 지우고 재귀를 불러 매개변수로 입력해줌
		tempVec.erase(tempVec.begin() + i);
		Check(len, tempVec, num);

		// 다시 원래 숫자로 돌아온다
		num = temp;
	}
}
```

<br>

좀 복잡하고 가독성이 없는 코드이긴 하지만, 그래도 열심히 풀어낸 것 같다. 

<br>

기초 수학 문제들을 모두 풀고 나서 에라토스테라스의 체, 유클리드 호제법, 최소공배수, 최대공약수 구하는 법 등 많은 기초 수학을 알게 된 것 같다.  앞으로 알고리즘 문제에서도 이런 기초 수학들을 이용해서 효율적이고 다양하게 풀어봐야겠다.
