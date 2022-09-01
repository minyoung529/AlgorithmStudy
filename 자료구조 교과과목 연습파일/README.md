<div align="center">

# 자료구조 교과과목 연습


학교 수업인 '자료구조와 알고리즘' 시간에 해결했던 문제들이 있습니다.<br><br><br>

</div>


### 1. i love c++<br>
![ILOVEC](https://user-images.githubusercontent.com/77655318/187949276-902da374-5952-4ad2-9ac7-ba1a328335da.png)

처음엔 자료 구조 Queue나 Deque를 써서 **push_front**를 무조건적으로 해주어야 한다고 생각했다. 그래서 string을 **queue**나 **deque**로 옮길까 생각을 하기도 했다.

<br>

하지만, 곰곰이 생각해보니 string에는 **erase**라는 함수가 있고, 이걸로 맨 앞에 있는 문자를 지울 수 있다는 생각이 들었다.

<br>

그래서 설계한 알고리즘! <br>

1. 공백을 포함한 문자열을 입력 받는다.

2. 문자열의 길이만큼 반복문을 돌린다

3. 반복문 안에서는 먼저 문자열의 가장 앞 문자를 넣어준다.
`ex) i love c++i`

4. 가장 첫번째 문자를 지워준다. (erase 함수 사용)


<br><br>

이 알고리즘으로 짜본 코드는~
``` cpp
for (int i = 0; i < s.size(); i++)
{
	s.push_back(s.front());
	s.erase(s.begin());

	cout << s << endl;
}
```

간단한 생각의 단순하고 강한 힘을 알 수 있었다!
<br><br>




### 2. 피로도<br>
<a href="https://www.acmicpc.net/problem/22864">22864. 피로도</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Math/2_Fatigue_Degree.cpp">문제 풀이</a><br>

간단한 문제였다.<br>

한 시간마다 어떤 행동을 할 것인지 결정되고 하루는 24시간이기 때문에 **24번 반복문**을 돌려주고, 그 안에서 휴식할 것인지 일할 것인지를 **결정하고 이행**했다.
