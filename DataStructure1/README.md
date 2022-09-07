[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)


<div align="center">

# Data Structure 1


큐, 스택, 덱을 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 진행 상황 ]**<br>
🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩<br>
_100%_
<br><br><br>

</div>

### 1. 스택<br>
<a href="https://www.acmicpc.net/problem/10828">10828. 스택 문제</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/1_Stack.cpp">문제 풀이</a><br>


막혔던 점: 스택을 구현할 때 포인터를 썼는데, 할당할 때 배열 형식으로 할당하지 않아서 오류가 생겼다. 다음부터는 조심해야겠다.
<br><br>
또, c++의 string은 switch문을 쓸 수 없다는 것도 알게되었다. 왜 안 되는 건지는 모르겠지만, 해시코드를 직접 만들어서 쓴다는 사람도 있었다.

```cpp
void foo(const char* str)
{
    switch (HashCode(str))
    {
    case HashCode("HELLO"):
        // 이렇게
        break;
    }
}
```
다음에 해시코드를 반환하는 함수를 간단하게 만들어도 재미있겠다고 생각했다.

<br>

### 2. 괄호<br>
<a href="https://www.acmicpc.net/problem/9012">9012. 괄호</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/2_Bracket.cpp">문제 풀이</a><br>

자료구조 교과시간에 했던 문제라 수월하게 풀 수 있었다. 입력이 '('일 때는 스택에 넣어주고, ')'일 때는 스택에서 빼주면서 예외 경우가 있을 경우 NO를 출력했다. <b>스택</b>을 사용해서 깔끔하게 구현한 것 같다.


<br>

### 3. 큐2<br>
<a href="https://www.acmicpc.net/problem/18258">18258. 큐 2</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/3_Queue2.cpp">문제 풀이</a><br>

스택1에서 막혔던 부분의 해결법을 응용해서 수월하게 풀 수 있었다.
<br><br>

막혔던 점: <b>시간초과</b>로 막혔다. 로직이 문제 없다고 생각했는데 찾아보니 입출력을 하는데 시간을 많이 쓴다는 말이 있었다.

```cpp
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
```

<br>
이 코드를 앞에 적어주니 정답이 나왔다. 찾아봤더니 일반적으로 C++ 컴파일러는 C와 C++ 스타일의 입출력을 혼용하는 것을 허용하는데, 이를 구현하기 위해서 모든 표준 입출력들 또한 <b>동기화</b> 되어있다.
<br><br>
첫번째 줄의 코드로 그러한 동기화를 꺼줌으로써 c++ 입출력시 독립된 자신만의 버퍼를 사용하게 된다고 한다. 그리고 cout과 cin의 tie를 풀어주면 입출력 속도가 줄어들게 된다. 몰랐던 점이라 기억하고 시간 초과가 나올 때 기억해서 써야겠다.

<br>
<br>

### 4. 요세푸스 문제<br>
<a href="https://www.acmicpc.net/problem/1158">1158. 요세푸스</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/4_Josephus.cpp">문제 풀이</a><br>

자료구조 교과시간에 했던 문제라 조금만 생각하면 되는 문제였다. <b>큐</b>를 사용해 pop하고 다시 push하며 꼬리잡기하는 방식이 신선하다.

<br>

### 5. 카드2<br>
<a href="https://www.acmicpc.net/problem/2164">2164. 카드2</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/5_Card2.cpp">문제 풀이</a><br>

요세푸스와 비슷하게 큐를 사용해서 pop과 push를 반복하며 꼬리잡기식으로 구현했다.


<br>

### 6. 덱<br>
<a href="https://www.acmicpc.net/problem/10866">10866. 덱</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/6_Deque.cpp">문제 풀이</a><br>

Queue와 비슷하게 구현하지만, pivot을 설정해 front와 back을 나누어주었다. 시간과 메모리를 엄청엄청... 사용해서 그렇게 효율적이고 깔끔한 코드를 구현하지는 못했지만, 자료구조 시간에 배운 것을 활용해서 Deque를 혼자 구현한 것으로 만족한다.
여전히 전위와 후위 연산자를 적절하게 사용해야하는 걸 상기시킨 문제이다. 


<br>

### 7. 주몽<br>
<a href="https://www.acmicpc.net/problem/1940">1940. 주몽</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/7_Jumong.cpp">문제 풀이</a><br>

자료구조 시간에 풀어본 문제이다. for문을 3개나 써서 시간초과가 걸릴까 다른 방법을 모색했지만, for문을 3개 써도 시간 초과가 걸리지는 않았다. 수월하게 풀 수 있었던 문제이다.


<br>

### 8. 스택 수열<br>
<a href="https://www.acmicpc.net/problem/1874">1874. 스택 수열</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/8_StackSequence.cpp">문제 풀이</a><br>

정말 너무너무 어려웠던 문제... 풀고 나니 별 거 아니지만, 문제도 잘 이해 못한채로 생각을 너무 어렵게 많이 해서 시간이 오래 걸리고 어려웠다. 핵심은 **오름차순으로만 push**였는데... 이걸 눈으로만 읽고 이해하지 못해서 어려웠던 것 같다. 문제의 **핵심을 파악하고 정확하게 이해**해야하는 중요성에 대해서 다시금 깨달았다. 
<br>
그리고 

```cpp
cout << endl;
```
보다

```cpp
cout << '\n';
```
이 더 빠르다는 걸 알게되었다. 이유는 endl은 flush 함수(출력 버퍼를 비우는 함수)를 호출하기 때문이라고 한다. 알고리즘 문제를 풀 때는 '\n'을 써야겠다.

<br>

### 9. 후위 표기식2<br>
<a href="https://www.acmicpc.net/problem/1874">1935. 후위 표기식2</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/9_Postfix_Notation2.cpp">문제 풀이</a><br>

자료구조 시간에 스택을 활용해서 풀어봤던 문제라 그렇게 어렵지는 않았다. 우선순위 처리는 어떻게 해야하는지 엄청... 고민했다가 변환이 아니라 계산이라 고민할 필요가 없다는 것을 깨달았다. 

<br>

그리고 항상 사용하지만... 항상 까먹고 구글링하는 소수점 자리 제한은...

```cpp
cout << fixed;
cout.precision(N);
```

**fixed**는 **소수점을 고정**시키겠다는 뜻, **precision**은 **정밀도**라는 뜻을 가져 매개변수의 소수점 자리만큼 보여주겠다는 뜻이다.
<br><br>

만약 fixed가 없다면...

```cpp
cout.precision(2);
cout << 3

// => 3
```

```cpp
cout.precision(2);
cout << 3.278

// => 3.3
// > fixed가 없어 정수자리까지 포함한 자리수, 반올림 함
```


있다면!

```cpp
cout << fixed;
cout.precision(2);
cout << 3

// => 3.00
```

```cpp
cout << fixed;
cout.precision(2);
cout << 3.278

// => 3.28
// > fixed가 있어 정수자리까지 포함하지 않은 자리수, 반올림 함
```

<br>

### 10. 쇠막대기<br>
<a href="https://www.acmicpc.net/problem/10799">10799. 쇠막대기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/10_IronRod.cpp">문제 풀이</a><br>

괄호가 나왔다고 해서 무조건 스택!! 이라 생각한 나를 다시 돌아보게 했던 문제. 물론 스택을 써도 되지만, 스택에 push, pop, size를 자꾸 호출해주는 것보다는 변수 하나로 하는 게 좋을 것 같았다. 처음에 삽질을 30분 정도 했지만...

<img width="267" alt="1" src="https://user-images.githubusercontent.com/77655318/178150541-661491b6-1828-4287-97a4-9148e28eb431.png">

이 예시 사진을 보고 머리 속으로 시뮬레이션을 돌리며 ')'가 나올 때마다 쇠막대기 개수가 어떻게 변하는지를 상상하니 머리속으로 코드가 그려졌다. 문제를 잘 이해하는 것만큼이나, **문제 해결 과정**을 잘 이해하는 것도 중요하다는 것을 알게 되었다.
<br><br>
막히는 문제가 나오면 문제 해결 과정을 자세하게 상상해야겠다.

<br>

### 11. 프린터 큐<br>
<a href="https://www.acmicpc.net/problem/1966">1966. 프린터 큐</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/11_PrinterQueue.cpp">문제 풀이</a><br>

프로그래머스에서 한번 풀어봤던 문제라서 어렵지는 않았다. 그때 내가 어떻게 풀었는지는 모르겠지만... 전보단 더 깔끔하게 짠 것 같지만, 메모리를 좀 많이 쓴 것 같다.

``` cpp
int PrinterQueue(int len, int target, vector<int> printer)
{
	queue<int> pq;

	for (int i : printer) pq.push(i);
	sort(printer.begin(), printer.end(), less<int>());

	while (!printer.empty())
	{
		if (pq.front() < printer.back())
		{
			pq.push(pq.front());
			pq.pop();

			if (target == 0)
				target = pq.size();
		}
		else
		{
			pq.pop();
			printer.pop_back();

			if (target == 0)
				return (len - pq.size());
		}

		target--;
	}

	return 0;
}
```

우선순위 큐를 쓸 수도 있었지만, 직접 풀어보고 싶었다. 메인 로직은 이렇다. target이 0일 때 더 큰게 있다면 뒤로 넘겨주고, 아니라면 현재 몇번째인지 리턴하는 함수로 구현했다. targetPtr로 해서 해당 주소를 가리키는 방법도 해봤지만, 시간 초과가 났다.


<br>

### 12. 풍선 터뜨리기<br>
<a href="https://www.acmicpc.net/problem/2346">2346. 풍선 터뜨리기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/12_Popping_Balloon.cpp">문제 풀이</a><br>

꽤 고생했던 문제이다. 사실 처음에 Deque를 써서 풀어보려고 했는데, for문을 계속 돌리는 구조라 시간 초과가 날 것 같아서 다른 방법을 썼다. 그렇게 계속 고민하고 돌고 돌아 다시 Deque를 이용하자고 마음 먹었다.
<br><br>

결국 처음에 구상했던 로직으로 갔다. 가고자 하는 방향이 오른쪽일 때는 front를 뒤로, 왼쪽일 때는 back을 앞으로 보냈다. 회전하도록.
<br><br>

빼내고자 하는 값이 Deque의 front여야 했기 때문에 아래 한 줄을 추가했다.
```cpp
int offset = count > 0 ? -1 : 0;
```

<나중에 까먹을까봐 그린 위 코드의 -1의 의미>
![제목 없음](https://user-images.githubusercontent.com/77655318/179353314-7d241a89-3d85-48bc-9ba9-c0163fdb4580.png)


회전하다가 해당 자리에 오면 index가 저장된 **pair의 first**를 꺼내 배열에 저장해주었다. Deque는 자료구조 시간에 배우지 않아서 익숙하지 않았는데, 이 문제로 Deque의 쓰임새와 사용법을 잘 알게 되었다.



<br>

### 13. 괄호의 값<br>
<a href="https://www.acmicpc.net/problem/2504">2504. 괄호의 값</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/13_Value_In_Parentheses.cpp">문제 풀이</a><br>

엄청엄청 어려웠던 문제... 내 힘으로 전부 풀어낸 문제는 아니라서 부끄럽기도 하다.<br><br>

처음 접근은 **스택** 자료구조를 써서 괄호가 열릴 때는 push, 닫힐 때는 pop을 해서 계산을 해보자!
<br>라고 막연하게 생각하고 있었다.
<br><br>문제의 **예제 입력**인 '(()[[]])([])'에만 집중하고 있다보니 '()()()'나 '((()))'같은 간단한 입력도, 복잡한 입력도 풀어내지 못했다.<br><br>

오랫동안 고민한 나는 어떤 글에서 **분배법칙**이라는 단어를 힌트로 발견하게 된다. 

```
// (()[[]])([])
// = 2 * (2 + 3*3)
// = 2*2 + 2*3*3
```

그리고 분배법칙을 어떻게 적용시킬까 고민했다.<br><br>

* 생각하게 된 사실 하나는 () 안에 있는 아이들은 **무조건 2배**, []는 **무조건 3배**라는 것이다.<br>
* 그렇다면 소괄호가 열릴 때는 2를, 대괄호는 3을 곱하고. 닫힐 때는 각각 나눠주면 되는 일이었다.<br>
* 모든 괄호가 닫히는 부분을 계산하지 않고, ()이나 []등 괄호에 **가장 안쪽에** 있는 아이들만 계산하니 문제가 풀렸다.
<br><br>
풀어보니 그리 어렵지 않은 문제였지만, 사고가 정답으로 향하기가 매우 어려운 문제인 것 같았다.
<br>앞으로 이런 사고를 혼자서 할 수 있게 더 노력해야겠다.


<br>

### 14. 괄호 제거<br>
<a href="https://www.acmicpc.net/problem/2800">2800. 괄호 제거</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/14_Remove_Parentheses.cpp">문제 풀이</a><br>

좀 어려웠지만, 충분히 할만했고 재미있었던 문제이다.<br><br>

처음엔 괄호에 쌍을 맞춰서 순서대로 제거하는 것부터 시작하고자 했는데, 접근이 틀렸었다.

``` cpp
(0/(0))
(2+(2*2)+2)
(1+(2*(3+4)))
```

예제 식에는 이러한 괄호들만 있다 보니, 단순하게 처음 나오는 (와 마지막에 나오는 )가 서로 짝이라고 생각했지만,

```
()()()
```

이러한 모양의 괄호도 있다는 것을 깨달아 **스택**을 이용해서 괄호의 쌍을 구했다.

``` cpp
stack<int> stack;

for (int i = 0, count = 0; i < input.size(); ++i)
{
	if (input[i] == '(')
	{
		startPos[count] = i;
		stack.push(count++);
	}

	else if (input[i] == ')')
	{
		endPos[stack.top()] = i;
		stack.pop();
	}
}
```

스택을 통해 (의 위치가 있는 sartPos, )의 위치가 있는 endPos를 설정해주었다.
<br><br>
그리고 자료구조 시간에 배웠던 **DFS**를 활용해서 경우의 수를 구했다. 괄호가 닫히는 경우도, 닫히지 않는 경우도 있으므로 재귀함수에서 부를 때 true와 false값을 주어서 두 번 호출했다.

``` cpp
GetParenthese(input, index + 1, true);
GetParenthese(input, index + 1, false);

```

이때 문자열이 줄어들수록, 괄호의 위치도 바뀌므로 erase가 아닌 replace를 해서 원래 괄호의 자리를 공백으로 만들어주었다.

``` cpp
input.replace(startPos[index], 1, " ");
input.replace(endPos[index], 1, " ");
```

중복되지 않고, 사전순으로 정렬되도록 **set 자료구조**를 사용해 공백제거한 문자열을 넣어주고, 후에 set에 있던 모든 문자열을 출력했다.

```cpp
input.erase(remove(input.begin(), input.end(), ' '), input.end());
results.insert(input);
```

문자열과 스택을 동시에 다뤄서 재미있었던 문제였다.


<br>

### 15. 탑<br>
<a href="https://www.acmicpc.net/problem/2493">2493. 괄호의 값</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/15_Tower.cpp">문제 풀이</a><br>

할만한 문제라고 생각했지만... 시간 초과로 꽤 고생했던 문제이다.<br><br>

처음에는 완전탐색을 이용하여 풀었지만, 시간 초과가 났다. **스택**을 써보라는 말에 써봤지만, 그마저도 시간 초과가 났다.<br>

이유는 Pop을 할 때 안에 있는 데이터가 날아가면 안된다고 생각해 **클론한 스택**을 써서 탐색한 것이 문제였다. 문제를 읽어보면 탐색할 때 원래 스택에서 Pop을 해도 상관 없는 문제였다. 가장 큰 값을 탐색하기 때문에.<br><br>

자료구조로 풀이하도록 접근하는 사고, 자료구조를 완벽히 이해하고 응용하는 사고가 중요한 것 같다.


<br>

### 16. 데이터 체커<br>
<a href="https://www.acmicpc.net/problem/22942">22942. 데이터 체커</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/16_Data_Checker.cpp">문제 풀이</a><br>

엄청엄청엄청 고생했던 문제.<br><br>

지금까지 풀어본 문제 중에 제일 어려웠던 것 같지만, 스스로 풀어내서 되게 뿌듯했다.<br><br>

처음 접근은 원들을 (x + 반지름)값 오름차순으로 **정렬**하고 벡터에 넣어 비교하는 코드였다.

``` cpp
sort(vec.begin(), vec.end(), [](auto p1, auto p2) {return p1.first + p1.second > p2.first + p2.second; });
```

벡터는 **스택**처럼 사용해 닿지 않았다면 **Pop_Back**을 해주었다. 그런데 이때 원본 벡터를 건드리면 문제가 생길 것 같아 복사한 벡터를 스택처럼 사용해주었다.

<br>

겹치는 원을 발견하지 못했다면 원본 벡터에서 pop_back을 수행해주고 다시 while문을 도는 2중 while문을 구상했다.


``` cpp
// 가장 
while(vec.size() >= 2)
{
	vector<pair<int, int>> temp = vec;
	while(temp.size() >= 2)
	{
		if(IsTouching(temp.back(), *(temp.end() - 2));)
		{
			cout << "NO";
			return 0;
		}
		temp.erase(temp.end() - 2);
	}
}
```

문제는 시간이 너무 오래 걸린다는 것이었다. 거진 완전탐색이라 정확했지만, 시간이 오래 걸려 **그냥 원본 벡터를 건들면 어떨까?**라는 생각이 들었다.

<br>

그래서

``` cpp
while (vec.size() >= 2)
	{
		int result = IsTouching(vec.back(), *(vec.end() - 2));

		if (IsTouching(vec.back(), *(vec.end() - 2)))
		{
			cout << "NO";
			return false;
		}

		vec.erase(vec.end() - 2);
	}
```

하나의 while문으로 원본 벡터를 건드리는 도장깨기식 코드를 써보았다. 긴가민가한 마음에 제출해보니, 정답이 표시되었다. <br><br>

![화면 캡처 2022-07-22 192301](https://user-images.githubusercontent.com/77655318/180419722-afb09efe-a529-4577-a82e-19939d906ae8.png)

맞은 건 기분이 좋지만, 아무리봐도 이 코드가 왜 맞는지 이해가 안 되어서 30분 동안 고민하다가, 새로운 테스트케이스를 만들어내었다.

![제목 없음](https://user-images.githubusercontent.com/77655318/180417419-b2e43e04-9583-45f2-ad89-d70e1be1abef.png)<br>
이 테스트 케이스인데, 표시한 지점부터 오른쪽으로 비교를 하다 보면 YES가 나오게 되는데, 원래 답은 NO이다. <br><br>

결국 이 테스트 케이스까지 충족한 새로운 코드는 while문을 두 번 써서 비교하는 것이었다.

![제목 없음](https://user-images.githubusercontent.com/77655318/180420288-d326038c-256c-4f37-99a3-c229d9672441.png)

이렇게 두 번 탐색. 내가 만든 테스트케이스를 충족했다.<br><br>

맞았다고 해서 무작정 좋아할 게 아니라, 왜 맞았는지에 대해 정확히 알고 내가 쓴 코드를 정확히 이해하는 것이 중요한 것 같다. 


<br>

### 17. 후위 표기식<br>
<a href="https://www.acmicpc.net/problem/1918">1918. 후위표기식</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure1/17_Postfix_Notation.cpp">문제 풀이</a><br>

자료 구조 시간에 배웠다만, 좀 헤맸던 문제.<br><br>

중위 표기식에서 후위 표기식으로 바꾸는 것은 교과 시간에 배워서 수월하게 할 수 있었다. 문제는 **괄호의 처리**였다. <br>

괄호를 어떻게 처리할까 고민하다가, **열리는 괄호 다음**에 만나는 연산자는 무조건 **스택에 삽입** 되게 했다. 또, 닫히는 괄호가 나오면 열리는 괄호가 나올 때까지의 **모든 연산자를 출력**하는 것으로 했다.

``` cpp
// A*B+(C+D*E+F)+G
```

이 테스트 케이스가 나를 살렸다... 다음에 푼다면 꼭 이 입력을 먼저 충족시켜야겠다...<br>

또, [후위표기식 시뮬레이션 링크](https://blog.naver.com/PostView.naver?blogId=tipsware&logNo=222560727262&categoryNo=0&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=menu)가 많은 도움이 되었다. 올바른 정답을 알 수 있었고, 시뮬레이션과 내 코드 로직의 다른 점을 찾으며 올바른 정답을 찾아갈 수 있었다.
