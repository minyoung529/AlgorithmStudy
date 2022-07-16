# AlgorithmStudy

여러 코딩 테스트 문제를 푸는 저장소입니다.

### 1. 스택<br>
<a href="https://www.acmicpc.net/problem/10828">10828. 스택 문제</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/1_Stack.cpp">문제 풀이</a><br>


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
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/2_Bracket.cpp">문제 풀이</a><br>

자료구조 교과시간에 했던 문제라 수월하게 풀 수 있었다. 입력이 '('일 때는 스택에 넣어주고, ')'일 때는 스택에서 빼주면서 예외 경우가 있을 경우 NO를 출력했다. <b>스택</b>을 사용해서 깔끔하게 구현한 것 같다.


<br>

### 3. 큐2<br>
<a href="https://www.acmicpc.net/problem/18258">18258. 큐 2</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/3_Queue2.cpp">문제 풀이</a><br>

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
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/4_Josephus.cpp">문제 풀이</a><br>

자료구조 교과시간에 했던 문제라 조금만 생각하면 되는 문제였다. <b>큐</b>를 사용해 pop하고 다시 push하며 꼬리잡기하는 방식이 신선하다.

<br>

### 5. 카드2<br>
<a href="https://www.acmicpc.net/problem/2164">2164. 카드2</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/5_Card2.cpp">문제 풀이</a><br>

요세푸스와 비슷하게 큐를 사용해서 pop과 push를 반복하며 꼬리잡기식으로 구현했다.


<br>

### 6. 덱<br>
<a href="https://www.acmicpc.net/problem/10866">10866. 덱</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/6_Deque.cpp">문제 풀이</a><br>

Queue와 비슷하게 구현하지만, pivot을 설정해 front와 back을 나누어주었다. 시간과 메모리를 엄청엄청... 사용해서 그렇게 효율적이고 깔끔한 코드를 구현하지는 못했지만, 자료구조 시간에 배운 것을 활용해서 Deque를 혼자 구현한 것으로 만족한다.
여전히 전위와 후위 연산자를 적절하게 사용해야하는 걸 상기시킨 문제이다. 


<br>

### 7. 주몽<br>
<a href="https://www.acmicpc.net/problem/1940">1940. 주몽</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/7_Jumong.cpp">문제 풀이</a><br>

자료구조 시간에 풀어본 문제이다. for문을 3개나 써서 시간초과가 걸릴까 다른 방법을 모색했지만, for문을 3개 써도 시간 초과가 걸리지는 않았다. 수월하게 풀 수 있었던 문제이다.


<br>

### 8. 스택 수열<br>
<a href="https://www.acmicpc.net/problem/1874">1874. 스택 수열</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/8_StackSequence.cpp">문제 풀이</a><br>

정말 너무너무 어려웠던 문제... 풀고 나니 별 거 아니지만, 문제도 잘 이해 못한채로 생각을 너무 어렵게 많이 해서 시간이 오래 걸리고 어려웠다. 핵심은 **오름차순으로만 push**였는데... 이걸 눈으로만 읽고 이해하지 못해서 어려웠던 것 같다. 문제의** 핵심을 파악하고 정확하게 이해**해야하는 중요성에 대해서 다시금 깨달았다. 
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
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/9_Postfix_Notation2.cpp">문제 풀이</a><br>

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
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/10_IronRod.cpp">문제 풀이</a><br>

괄호가 나왔다고 해서 무조건 스택!! 이라 생각한 나를 다시 돌아보게 했던 문제. 물론 스택을 써도 되지만, 스택에 push, pop, size를 자꾸 호출해주는 것보다는 변수 하나로 하는 게 좋을 것 같았다. 처음에 삽질을 30분 정도 했지만...

<img width="267" alt="1" src="https://user-images.githubusercontent.com/77655318/178150541-661491b6-1828-4287-97a4-9148e28eb431.png">

이 예시 사진을 보고 머리 속으로 시뮬레이션을 돌리며 ')'가 나올 때마다 쇠막대기 개수가 어떻게 변하는지를 상상하니 머리속으로 코드가 그려졌다. 문제를 잘 이해하는 것만큼이나, **문제 해결 과정**을 잘 이해하는 것도 중요하다는 것을 알게 되었다.
<br><br>
막히는 문제가 나오면 문제 해결 과정을 자세하게 상상해야겠다.

<br>

### 11. 프린터 큐<br>
<a href="https://www.acmicpc.net/problem/1966">1966. 프린터 큐</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/11_PrinterQueue.cpp">문제 풀이</a><br>

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

### 12. 풍선 터E뜨리기<br>
<a href="https://www.acmicpc.net/problem/2346">2346. 풍선 터뜨리기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/12_Popping_Balloon.cpp">문제 풀이</a><br>

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
