<div align="center">

# Math


수학을 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩⬛⬛⬛⬛⬛⬛⬛⬛⬛<br>
_11%_
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
