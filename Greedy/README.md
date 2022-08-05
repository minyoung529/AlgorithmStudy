<div align="center">

# Greedy


Greedy(탐욕 알고리즘)를 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩⬛⬛⬛⬛⬛⬛⬛⬛⬛<br>
_11%_
<br><br><br>

</div>


### 1. 거스름돈<br>
<a href="https://www.acmicpc.net/problem/14916">14916. 거스름돈</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/1_Change.cpp">문제 풀이</a><br>

간단한 그리디 문제였다. <br>

동전이 2원, 5원 있는데 동전을 최소로 주는 방법을 구하는 것이다.

``` cpp
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

간단한 그리디 문제였다. <br>

그래도 한번에 코드를 짜지는 못했는데, 내가 했던 실수는...

``` cpp
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

``` cpp
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

그리디에 대한 이해를 도와준 문제!<br>

지금까지는 그리디 문제가 어색하고 감이 잘 잡히지 않았는데, 점점 그리디 문제를 풀어보니 완벽하지는 않지만... 그래도 감을 잡은 것 같다. <br>
임의로 선택된 줄들이 버틸 수 있는 **최대 무게**를 계산하기 위해...

``` cpp
sort(weights.begin(), weights.end(), greater<int>());
```

먼저 **내림차순**으로 정렬해주었다. 내림차순으로 정렬한 이유는 반복문으로 계산할 때 **증가하는 index** 값인 i와 **맞추기** 편리했기 때문. 그 반복문은...

``` cpp
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
