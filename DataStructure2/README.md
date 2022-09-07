[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/edit/main/README.md)


<div align="center">

# Data Structure 2


Map, Set, Priority Queue(우선순위 큐)를 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩<br>
_100%_
<br><br><br>

</div>


### 1. 나는야 포켓몬 마스터 이다솜<br>
<a href="https://www.acmicpc.net/problem/1620">1620. 나는야 포켓몬 마스터 이다솜</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/1_I'm_Pokemon_Master.cpp">문제 풀이</a><br>

자료구조 1 문제들이 슬슬 어려워지기 시작해서 도피성으로 풀어본 자료구조 2 문제이다.<br><br>
문제 자체는 map을 써서 어렵지 않았지만, **자꾸 시간 초과**가 떴다.

<br>

입출력 동기화도 끄고 시간이 초과될 게 없는데... 생각했었는데

``` cpp
cout << endl;
```

얘가 문제였다. endl을 '\n'으로 바꿔주니 빠르게 통과할 수 있었다. 개행도 '\n'으로 한다는 것을 기억해야겠다.

<br>


### 2. 문자열 집합<br>
<a href="https://www.acmicpc.net/problem/14425">14425. 문자열 집합</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/2_String_Set.cpp">문제 풀이</a><br>

왜 해시 문제일까 고민했는데, C++ map에는 find 함수가 있어서 별다른 헤더를 쓰지 않고도 문자열의 포함 여부를 알 수 있어서 간단하게 풀었다. <br>

``` cpp
if (dict.find(input) != dict.end())
```

이렇게. 리턴값이 end()라면 찾지 못한 것, end가 아니라면 찾은 것. algorithm 헤더에 find랑 비슷하다.

맵을 사용하는 데 더 익숙해져야겠다.


<br>



### 3. 최대 힙<br>
<a href="https://www.acmicpc.net/problem/11279">11279. 최대 힙</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/3_Max_Heap.cpp">문제 풀이1</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/3_Max_Heap_Implementation.cpp">문제 풀이2(우선순위 큐 구현)</a><br>


우선순위 큐를 사용하면 아주 쉬운 문제였지만, 뭔가 날로 먹는 느낌이 들어 우선순위 큐를 자료구조 시간에 배운대로 구현해보았다.

<br>

전체적인 힙은 vector로 구현했다.

* 부모의 인덱스는 [(N-1)/2]
* 왼쪽 자식은 [(N*2)+1]
* 오른쪽 자식은 [(N*2)+2]

를 이용하여 구현했다.

<br>

Push는 가장 마지막 인덱스부터 시작해서 도장깨기 식으로 부모와 계속 스왑하는 형식!

``` cpp
void push(int value)
{
	heap.push_back(value);
	int curIndex = static_cast<int>(heap.size()) - 1;

	while (curIndex >= 0)
	{
		int parent = (curIndex - 1) / 2;

		// 도장깨기
		if (heap[parent] < heap[curIndex])
		{
			swap(heap[parent], heap[curIndex]);
			curIndex = parent;
		}
		else break;
	}
}
```

Pop은 0번째 인덱스를 반환하되, 재정렬을 한다. 재정렬은 가장 마지막에 있는 요소를 첫번째로 만든 다음 아래로 도장깨기를 하면서 정렬한다.

``` cpp
int pop()
{
	int value = heap[0];
	heap[0] = heap.back();
	heap.pop_back();

	int curIndex = 0;
	int next = 1;

	// top부터 시작해서 내려오기
	// => 재정렬
	while (next <= static_cast<int>(heap.size()) - 1)
	{
		if (next < static_cast<int>(heap.size()) - 1)
		{
			// 왼쪽, 오른쪽 자식 비교
			if (heap[next] < heap[next + 1])
				++next;
		}

		// 지금이 더 크다면 끝냄
		if (heap[next] < heap[curIndex]) break;
		else swap(heap[next], heap[curIndex]);

		curIndex = next;
		next = next * 2 + 1;
	}

	return value;
}
```

처음은 다음으로 갈 요소를 왼쪽, 오른쪽 중에 **더 큰 요소**로 결정한다. 

현재 요소가 다음에 갈 요소보다 크다면 그 자리에서 끝내고, 아니라면 현재 요소는 더 내려간다.

이것을 반복하며 재정렬해주면 우선순위 큐의 pop을 구현할 수 있다.

<br>

오랜만에 최대 힙을 통해 우선순위 큐를 만드는 것을 공부해서 유익했다. stl을 쓰더라도 그 안에 구현 방식을 까먹지 않게 자꾸자꾸 복습해야겠다.


<br>



### 4. 절댓값 힙<br>
<a href="https://www.acmicpc.net/problem/11286">11286. 절댓값 힙</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/4_Absolute_Value_Heap.cpp">문제 풀이</a><br>


pair을 요소로 가진 우선순위 큐를 사용하여 푼 문제이다. <br>

문제의 조건이 **pair의 정렬**과 같아 pair의 **first에는 절댓값**, **second에는 입력값**을 넣어주었다. 정렬은 first 기준으로, fist끼리 같다면 second를 기준으로 정렬하므로 꺼내주기만 했다.



### 4. 절댓값 힙<br>
<a href="https://www.acmicpc.net/problem/11286">11286. 절댓값 힙</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/4_Absolute_Value_Heap.cpp">문제 풀이</a><br>


pair을 요소로 가진 우선순위 큐를 사용하여 푼 문제이다. <br>

문제의 조건이 **pair의 정렬**과 같아 pair의 **first에는 절댓값**, **second에는 입력값**을 넣어주었다. 정렬은 first 기준으로, fist끼리 같다면 second를 기준으로 정렬하므로 꺼내주기만 했다.


<br>


### 5. N번째로 큰 수<br>
<a href="https://www.acmicpc.net/problem/2075">2075. 절댓값 힙</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/5_Nth_Largest_Number.cpp">문제 풀이</a><br>

자꾸자꾸 메모리 초과가 나서 어려웠던 문제... 효율적인 코딩의 중요성을 느꼈다.<br>

처음 구현은 입력값을 **모두 우선순위 큐에** 넣고, 다 넣은 다음에 **N-1번 반복**해서 우선순위 큐를 **Pop**해주고, queue의 Top 값을 출력하는 것이었다. <br>

사실 이때 메모리도 계산을 했었는데, 입력 최댓값이 1500, int는 4byte...
```
> 1500^2 * 4 = 9000000 (byte)
>> 9000000 byte = 9MB
```
9MB이니 괜찮겠지, 하는 행복회로를 돌리고 있었다. 계산이 잘못된 건지... 메모리는 초과가 났고 방법을 고민했고 별 이상하고 복잡한 방법들로 문제를 풀어가려던 차에...
<br>
**queue의 size를 N으로 유지**시키자는 생각이 떠올랐다. <br>

방법은 생각보다 간단했고, queue의 size가 N이 넘어갈 때마다 가장 작은 값을 pop해주는 것이다. 마지막에는 queue에 첫번째, 두번째... N번째로 큰 값이 들어갔으며 queue의 top을 출력해주는 것이 정답이었다. <br>

괜히 복잡하게 생각하는 것보다, 단순하지만 명확한 해답을 찾는 것이 중요하다고 느꼈다.

<br>


### 6. 생태학<br>
<a href="https://www.acmicpc.net/problem/4358">4358. 생태학</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/6_Ecology.cpp">문제 풀이</a><br>

EOF에서 입력을 멈추는 건 처음 해봐서 생소했고 실수가 많아서 많이 틀렸던 문제...<br>
	
일단 배운 EOF에서 입력을 멈추는 방법.<br>
	
1.
``` cpp
while(getline(cin, input))
{
	// 반복할 문장
}
```
	
2.
``` cpp
while(1)
{
	getline(cin, input);
	if(cin.eof()) break;
}
```
콘솔에서는 Ctrl + Z를 누르면 EOF가 입력된다고 한다. <br><br>
	
**내 실수들을 성찰해보기...**
	
1. EOF 받았을 때 break가 아닌 return 하기
2. pair<string, int>가 아닌 pair<string, char>로 쓰기...
	
얘네 때문에 30분은 더 고생하고 10번은 더 틀린 것 같다... 바보...<br><br>
	
시간을 의미없게 낭비하지 않도록 계속 문제를 접하면서 단순한 실수를 줄여야겠다.


<br>


### 7. 이중 우선순위 큐<br>
<a href="https://www.acmicpc.net/problem/7662">7662. 이중 우선순위 큐</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/7_Double_Priority_Queue.cpp">문제 풀이</a><br>

여러가지 방법으로 고민하는 게 재미있었던 문제<br>

처음 접근은 우선순위 큐 하나를 만들고 Pop에 따라서 **less<int>에서 greater<int>로** 쇽쇽 바꿔주자고 생각했다. 이렇게...

``` cpp
// 최댓값 없애야할 때
if(value == 1)
{
	if(!isMax)
		pQueue = priority_queue<int, vector<int>, less<int>>(pQueue);
}
else
{
	if(isMax)
		pQueue = priority_queue<int, vector<int>, greater<int>>(pQueue);
}

pQueue.pop();
```

행복 회로를 돌려봤지만, class의 템플릿이므로 이미 정해진 정렬을 바꿀 수는 없었다. <br>

다음 방법은 **vector**를 사용한 단순한 방법이었다.

``` cpp
// 최댓값 없애야할 때
sort(vec.begin(), vec.end());

if(value == 1)
{
	vec.erase(vec.end() - 1);
}
else
{
	vec.erase(vec.begin());
}
```

단순하고 나쁘지 않은 접근이었던 것 같지만, 제출해보니 시간 초과가 나왔다. 아마 저 sort 함수 때문이 아닐까 생각했다.<br>


다음 접근은 **set**을 쓰는 것이었다. sort 함수로 인한 시간초과가 문제라면, 자동으로 정렬이 되는 set은 정렬을 더 빠르게 만들지 않았을까...? 하는 안일한 생각에서부터 찾아온 접근이었다.<br>

다만, 중복 제거를 허용하면 안되는 문제라, **multiset**을 사용하였고, 기본적인 로직은 vector와 똑같았지만, sort 함수만 사용하지 않았다. 결과는 성공! <br>

sort 함수를 호출하는 것과 multiset을 쓰는 게 무슨 차이인지 찾아봐야겠다.


<br>


### 8. 문제 추천 시스템 Version 1<br>
<a href="https://www.acmicpc.net/problem/21939">21939. 문제 추천 시스템 Version 1</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/8_Problem_Recommendation_System_1.cpp">문제 풀이</a><br>

이중 우선순위 큐를 푼 것을 응용한 문제이다. 재미있었다!<br>

기본적인 구조는 이중 우선순위 큐의 풀이와 비슷했다. 제출해보니 **특정 값을 지워주어야** 하는데, set을 사용해 이터레이터로 문제를 찾을 때까지 돌리니 시간 초과가 났다...

그래서 map을 써서 한번에 찾은 값을 set에서 지우게 해주었다.

``` cpp
// 삽입할 때
set.insert({ difficulty, problem });
map.insert({ problem, { difficulty, problem } });
```

``` cpp
// 삭제할 때
set.erase(map[problem]);
```

재밌는 문제였다.


<br>


### 9. 중앙값 구하기<br>
<a href="https://www.acmicpc.net/problem/2696">2696. 중앙값 구하기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/9_Find_Median.cpp">문제 풀이</a><br>

multiset을 이용해서 푼 문제. 어렵지 않게 풀 수 있었다.<br>

홀수 번째 수가 입력될 때마다 배열의 중앙값을 구하는 것. 자동으로 배열이 정렬되고, 중복 제거가 없는 multiset을 사용하여 풀었다. <br>

multiset의 **size/2**번째 인덱스를 구해야 하므로, 처음 알게 된 함수인 next 함수를 이용하였다.



``` cpp
// 중앙값을 찾을 때
int median = numbers.size() / 2;
answer += to_string(*next(numbers.begin(), median));
```

직접 iterator를 돌릴 필요가 없어서 편리했다.


<br>


### 10. 부품 대여장<br>
<a href="https://www.acmicpc.net/problem/21942">21942. 부품 대여장</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/DataStructure2/10_Parts_Rental.cpp">문제 풀이</a><br>

흘러가는 로직은 나쁘지 않았지만, 안에서 예상치 못한 실수가 자꾸자꾸 있었던 문제. 문자열과 해시를 다루어서 재미있는 문제였다.<br>

	
로직은 이렇다.
	
* 대출이라면 이름과 현재 시간을 분으로 바꾼 값을 저장한다.<br>
이때 같은 사람이 똑같은 부품을 빌렸는지 확인.
	
* 반납이라면 대출 목록에서 같은 이름을 꺼낸다.<br>
이때 대여 기간이 입력된 대여 기간보다 크다면 벌금!
	
* 벌금은 **(현재 대여 기간 - 지켜야할 대여 기간) x 벌금**이다.
	


<br><br>
	
	
그리고 내가 한 다채로운 실수들을 소개하자면...
	
	
**1. 오버플로우**

(벌금 * 초과 대여 기간(분))은 벌금의 최댓값이 4000이고, 기간의 단위가 분이기 때문에 int로 담을 수 없었다. 그래서 오버플로우가 발생했다...
``` cpp
	// int를...
	map<string, int> fineReports;
	
	// long long으로! =>
	map<string, long long> fineReports;
```
	
**2. +1월**

![화면 캡처 2022-08-01 005910](https://user-images.githubusercontent.com/77655318/182034909-43bc2303-228c-4f4f-9449-1a23193670d0.png)

처음엔 아무 생각 없이 구글에 **month to minute**을 검색해서 43800을 복사해서 붙여놨지만... 저 미심쩍은 **근삿값**이라는 달마다 일이 다를 수도 있다는 당연한 사실을 깨달은 뒤에...
	
``` cpp	
int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int MonthToDay(int month)
{
	int days = 0;

	for (int i = 0; i < month; i++)
		days += monthDays[i];

	return days;
}	
```

달을 입력하면 일수를 주는 간단한 함수를 만들었는데... 여기서 또 오류가 있었다.<br><br>
예를 들어 1월 23일을 입력하면 31 + 23 = **52**일이 되는 것. 2월 23일이 되버린 것이다. 그리고 이걸 눈치채지 못해서 삼십 여분을 날린...
	
``` cpp
int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int MonthToDay(int month)
{
	if (month == 1)return 0;

	int days = 0;

	for (int i = 0; i < month - 1; i++)
		days += monthDays[i];

	return days;
}	
```
				 
예쁘게 고쳐주었다.
												
**3. 한 부품만 빌릴 수 있다!**

처음엔 대여할 수 있는 부품이 하나인 줄 알고 부품의 이름을 Key 값으로 map을 만들어서 썼지만...
``` cpp
struct user
{
	string name;
	int rentalTime;
};
				 
// key => 부품의 이름
// value => 사용자 정보
map<string, map<string, user>> rentals;
```
	
분명 위 실수를 다 고치고 반례 출력값까지 맞았는데... 생각하고 있다가 그 어디에도 **부품이 하나다!**라는 말이 없다는 것을 깨달았다.
	
``` cpp
// key => 부품의 이름
// value => key => 사용자 이름
// value => value => 사용자 정보
map<string, map<string, user>> rentals;	
```
	
그래서 map을 이중으로 써주었다. 부품을 여러 개 빌려갈 수는 있지만, 한 부품을 한 사람이 반납하지 않고 여러번 빌려가는 것은 안되기 때문에 부품마다 유저를 키값으로 한 맵을 만들었다. <br>
시각적으로 표현하자면...
	
![제목 없음](https://user-images.githubusercontent.com/77655318/182035679-2bba7445-f563-4778-bcd8-dfee96df8cfd.png)

여기서...
	
![제목 없음](https://user-images.githubusercontent.com/77655318/182035665-1cca0766-f98f-452e-b32a-02f6c02eb69b.png)

이렇게 된 것! <br>
문자열이랑 해시를 같이 다룰 수 있어서 재미있었던 문제였다.
