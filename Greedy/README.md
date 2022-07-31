<div align="center">

# Greedy


Greedy(탐욕 알고리즘)를 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛<br>
_4%_
<br><br><br>

</div>


### 1. 거스름돈<br>
<a href="https://www.acmicpc.net/problem/14916">14916. 거스름돈</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/1_Change.cpp">문제 풀이</a><br>

간단한 Greedy 문제였다. <br>

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
