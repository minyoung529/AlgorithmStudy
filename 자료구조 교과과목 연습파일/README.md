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




### 2. 숫자 문자열과 영단어<br>
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/81301">숫자 문자열과 영단어 문제</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0%20%EA%B5%90%EA%B3%BC%EA%B3%BC%EB%AA%A9%20%EC%97%B0%EC%8A%B5%ED%8C%8C%EC%9D%BC/Number_String_And_English_Word.cpp">문제 풀이</a><br>

<img src = "https://user-images.githubusercontent.com/77655318/187950338-4b8912f0-d6a6-45da-a9df-16e45d520e82.png" width = "400">

문자열을 숫자로 치환하는 문제.<br>

map을 사용하여 각 숫자와 문자를 저장해주었으며, regex_replace를 사용해 문자열을 숫자로 대체하면 된다고 생각했다.<br>

``` cpp
map<string, string> map = { {"0", "zero"}, {"1", "one"}, ...}
```

그래서 생각한 알고리즘 설계는...

<br>

1. 위처럼 문자와 숫자를 묶은 **map**을 만든다.
`ex) key => “0”, value => “zero”`

2. i가 **0부터 9**가 될 때까지 반복문을 돌린다.

3. **i를 string**으로 바꿔 **맵의 키**로 쓰고, 그 값을 저장한다.
`ex) string value = pair[to_string(i)];`
`value == “zero”, “one”...`

4. 저장한 값을 숫자로 **대체**한다. (regex_replace 사용)

<br>

그런데 생각해보니... 인덱스대로 값이 정해지므로, 굳이 해시를 쓸 필요가 없었다! 바보...

<br>

최종 코드는...

``` cpp
string pair[] =
{
	"zero", "one", "two", "three", "four" , "five", "six" ,"seven", "eight", "nine"
};

for (int i = 0; i < 10; i++)
{
	// value = "zero", "one"...
	string value = pair[i];

	// s 안이 모든 value를 숫자 문자열로 치환
	// ex) "zero" => "0", "one" => "1"...
	s = regex_replace(s, regex(value), to_string(i));
}

return stoi(s);
```

regex_replace를 이용해서 간단하게 풀 수 있었다. 문자열에 관련된 함수를 알아놓고 적재적소에 사용할 수 있게끔 공부해야겠다.
