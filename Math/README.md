<div align="center">

# Math


수학을 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩🟩⬛⬛⬛⬛⬛⬛⬛<br>
_27%_
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


### 5. 진법 변환<br>
<a href="https://www.acmicpc.net/problem/2609">2609. 최대공약수와 최소공배수</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/5_GCF_And_LCM.cpp">문제 풀이</a><br>

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
