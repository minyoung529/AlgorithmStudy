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

있다면!

```cpp
cout << fixed;
cout.precision(2);
cout << 3

// => 3.00
```
