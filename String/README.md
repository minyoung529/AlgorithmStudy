[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# String

문자열과 관련된 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛<br>
_0%_
<br><br><br>

</div>

### 1. 경고

<br>

<a href="https://www.acmicpc.net/problem/3029">3029. 경고</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/1_Warning.cpp">문제 풀이</a><br>

[image](https://user-images.githubusercontent.com/77655318/190933196-6a046448-5170-47f3-86c5-67662555c5df.png)

던질 시간과 현재 시간의 차를 구하는 문제. 어렵지 않게 풀 수 있었다만, `적어도 1초, 많아야 24시간을 기다린다`는 조건 때문에 조금 헤맸다.
<br>
예를 들어,

```
input =>
08:00:00
08:00:00

answer =>
24:00:00

wrong answer =>
00:00:00
```

1초 이상을 기다려야 하므로 24시간을 기다려야 하는데, 코드로는 0초를 기다리게 나온 것이다. **h, m, s 모두 0이라면 24시간**을 출력해주는 것으로 해결했다.

```cpp
int ch, cm, cs;            // current time
int wh, wm, ws;            // wait time
int h = 0, m = 0, s = 0;    // answer

scanf_s("%d:%d:%d %d:%d:%d", &ch, &cm, &cs, &wh, &wm, &ws);

s = (ws - cs);

if (s < 0)
{
    // 받아내림 
    s += 60;
    cm++;
}

m = (wm - cm);

if (m < 0)
{
    // 받아내림 
    m += 60;
    ch++;
}

h = wh - ch;
if (h < 0)
    h += 24;

// 1초 이상 기다려야 하므로 24시간 기다림  
if (h == 0 && m == 0 && s == 0)
{
    h = 24;
}

printf("%02d:%02d:%02d", h, m, s);
```

간단하게 구현해봤다. 

조건의 중요성을 다시 상기시켜주었던 문제. 

<br><br>

### 2. 숫자의 합

<br>

<a href="https://www.acmicpc.net/problem/11720">11720. 숫자의 합</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/2_Sum_Of_Number.cpp">문제 풀이</a><br>
