[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)


<div align="center">

# Greedy


Greedy(탐욕 알고리즘)를 이용해서 해결하는 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩⬛⬛⬛⬛⬛⬛⬛⬛<br>
_22%_
<br><br><br>

</div>


### 1. 거스름돈<br>
<a href="https://www.acmicpc.net/problem/14916">14916. 거스름돈</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/1_Change.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/188650025-49a1167e-708a-4009-9784-53304c1cb217.png)

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

![image](https://user-images.githubusercontent.com/77655318/188649922-019084d7-84ea-4dc0-84d4-7d8bf5fe9e75.png)

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

![image](https://user-images.githubusercontent.com/77655318/188649765-ab7af6ae-8542-4784-a5ef-7fafac472bb2.png)

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



<br><br>


### 4. 주유소<br>
<a href="https://www.acmicpc.net/problem/13305">13305. 주유소</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/4_Gas_Station.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/188649689-5c5c8dce-63a0-4ecc-9df2-e54d8f27f595.png)


또 작은 실수 때문에 한참을 고민한 그리디 문제...

<br>

알고리즘을 생각하기까지는 오랜 시간이 걸리지 않았지만, 생각한 알고리즘을 코드로 옮기는 데에 문제가 생겼다. **알고리즘 단계를 완벽하게 글로 적었어야 했는데**... 나의 알량한 머리를 믿다가 쓰지 않은 조건문 하나에 오랜 시간을 헤맸다.

<br>

전체적인 알고리즘은 이렇다.

![image](https://user-images.githubusercontent.com/77655318/188652594-8ca24bfc-a3fd-4b56-8180-37592f86b346.png)

열심히 그려왔다.

<br>

정리하자면, 당장 기름이 급하다면 **다음 도시로 갈 때까지의 기름**을 넣는다. 그때, 다음, 다다음... 주유소와 가격 비교를 해서 현재 주유소보다 **적은 가격을 가진** 주유소까지 갈 거리(Km)를 현재 도시에서 미리 기름(L)을 넣는다.

<br>

코드로 보자면...

<br>

``` cpp
for (int i = 0; i < len - 1; i++)
{
	int buyCount = 0;

	// 당장 기름이 없으면 다음 거리까지 충전
	while (curOil + buyCount < distances[i])
		buyCount++;

	// 미리 충전을 해놓은 상태에서 굳이 더 저렴한 가격을 찾을 필요 없으므로
	// 미리 충전을 해놓지 않았다면...
	if (buyCount != 0)
	{
		for (int j = i + 1; j < len - 1; j++)
		{
			// 가장 금액이 적은 주유소가 나올 때까지
			// N리터 충전
			if (costs[i] <= costs[j])
				buyCount += distances[j];
			
			// 내가 한 실수다... break 빼먹기...
			else break;
		}
	}
	
	cost += ((unsigned long long)costs[i] * buyCount);
	curOil += buyCount;
	curOil -= distances[i];
}
````

이렇게 된다.

<br>

사실, **unsigned long long**도 써본 적이 거의 없는데, 아주 큰 범위가 나올 때마다 자동적으로 쓸 수 있게 익숙해져야겠다.

<br>

조금 어려웠지만, 할만하고 재미있는 문제였다. 각오해라 그리디... 조건반사처럼 문제를 완벽하게 풀 날을 기대해라...




<br><br>


### 5. 알바생 강호<br>
<a href="https://www.acmicpc.net/problem/1758">1758. 알바생 강호</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/5_Part_Timer_Kangho.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/188755705-9662c3f2-7d0d-427e-a61f-d889599552be.png)

문제는 정렬로 쉽게 풀 수 있었다.

<br>

등수가 올라갈수록 팁이 깎이는 가격이 늘어나므로 **가장 큰 팁을 줄 손님의 팁을 보존**해야 한다고 생각했다. 따라서 팁을 많이 줄 사람의 등수가 작야아하는 것이다.

<br>

처음엔 정렬 코드 그 한 줄을 쓰기 귀찮아서... **multiset**을 썼더니 시간 초과가 났다. next 함수 때문일 가능성도 있다.

``` cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL);  cin.tie(NULL);

	multiset<int, greater<int>> tips;
	int len;
	long long int kanghoTip = 0;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int input;
		cin >> input;
		tips.insert(input);
	}

	for (int i = 0; i < len; i++)
	{
		// 가장 큰 것부터
		int tip = *next(tips.begin(), i) - i;

		if (tip < 0) tip = 0;
		kanghoTip += tip;
	}

	cout << kanghoTip;
}
```
<br>

슬픈 마음으로 **우선순위 큐**로 구현을 해봤다.

``` cpp
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL);  cin.tie(NULL);

	priority_queue<int> tips;
	
	//...

	for (int i = 0; i < len; i++)
	{
		int tip = tips.top() - i;
		tips.pop();

		if (tip < 0) tip = 0;
		kanghoTip += tip;
	}

	cout << kanghoTip;
}
```

이번에도 예제는 맞았지만, 결과는 틀렸습니다... 나는 이제야 내 알고리즘은 틀린 게 없다는 것을 알게 되었다.

<br>

틀린 이유는 자료형 때문...

``` cpp
N은 100,000보다 작거나 같은 자연수이다.
팁은 100,000보다 작거나 같은 자연수이다.
```

이 조건이라면 한계값으로 테스트했을 때  `100000 * ((100000 - 0) + (100000 - 1) + + (100000 - 2)...)` 형태로 나올 것이다. 그렇게 되면 얻는 팁이 int 범위를 넘어서게 되므로 
**long long int**를 써주어야 하는 것이었다. 자료형을 늘려주니 바로 통과.

<br>

그리고 우선순위 큐를 쓰는 것보다 vector와 알고리즘 헤더의 sort 함수를 쓰는 게 더 빨라서 최종 제출은 vector로 했다.

``` cpp
	vector<int> tips;
	
	//...
	
	sort(tips.begin(), tips.end(), greater<int>());

	for (int i = 0; i < len; i++)
	{
		int tip = tips[i] - i;

		if (tip < 0) tip = 0;
		kanghoTip += tip;
	}

	cout << kanghoTip;
```

한계값을 정말로 테스트할 수는 없지만, 머릿속으로라도 테스트해서 내 코드의 결점을 발견하는 습관을 들여야겠다. 


<br><br>


### 6. 2+1 세일<br>
<a href="https://www.acmicpc.net/problem/11508">11508. 2+1 세일</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/Greedy/5_2+1_Sale.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/188772704-f6c2c677-cd08-4ffe-9a5a-8ae9570c2f05.png)

앞 문제와 같이, 정렬과 가까운 문제였다. 

<br>

처음에 구상한 알고리즘은

1. 가격들이 모두 있는 배열을 내림차순으로 정렬한다.

``` 
 (9 8 7) (6 5 4) 3 2
```

2. 인덱스대로 3개씩 묵어 첫번째와 두번째 값만 더해준다.

``` 
 (9 8 7) (6 5 4) 3 2
 result = 9 + 8 + 6 + 5
```

3. 3개로 묶어지지 않은 나머지들을 전부 더해준다.

``` 
 (9 8 7) (6 5 4) 3 2
 result += 3 + 2
```


<br>


배열을 내림차순으로 정렬한 이유는, 3개로 묶었을 때 **가장 저렴한 유제품**의 가격이 할인되므로, 되도록 **가격이 나가는 유제품을 할인받는 것**이 최소 가격으로 구매하는데 적절하다.

![image](https://user-images.githubusercontent.com/77655318/188779447-74448774-f33e-4a4e-af1f-152464421b06.png)


더 원활한 이해를 위해 테스트 케이스를 그려봤다.


<br>

아무튼... 알고리즘으로 코드를 짰는데...

``` cpp
int main()
{
	vector<int> prices;
	int len, i;
	long long int myCost = 0;

	cin >> len;
	prices.resize(100000);

	for (i = 0; i < len; i++)
		cin >> prices[i];

	sort(prices.begin(), prices.end(), greater<int>());
	
	// 현재 인덱스: 0부터 시작함
	i = 0;

	if (len / 3 > 0)
	{
		for (i = 0; i < len; i += 3)
		{
			// 세 개로 묶인 것들 중에 첫번째, 두번째만 더함
			myCost += (long long int)prices[i] + prices[i + 1];
		}
	}

	// 묶이지 않은 가격들을 더함
	while (i < prices.size())
	{
		myCost += prices[i++];
	}

	cout << myCost;
}
```

이렇게 짜니... index를 나타내는 i가 자꾸 눈에 걸려서 깔끔하지가 않은 것 같아서 아쉬웠다.

<br>

그래서 비용을 더하는 방식을  바꿨다.

1. 가격들이 모두 있는 배열을 내림차순으로 정렬하고, 모두 더한 값을 result에 넣어준다..

``` 
 (9 8 7) (6 5 4) 3 2
 result = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2

```

2. 인덱스대로 3개씩 묵어 세번째 값만 빼준다..

``` 
 (9 8 7) (6 5 4) 3 2
 result -= (7 + 4)
```

<br>

이것을 코드로 짜봤다.

``` cpp
int main()
{
	//...
	
	// 모든 가격을 더해준다.
	for (int i = 0; i < len; i++)
	{
		cin >> prices[i];
		myCost += prices[i];
	}

	sort(prices.begin(), prices.end(), greater<int>());

	if (len / 3 > 0)
	{
		// 세 개로 묶어 세번째 것만 빼준다.
		for (int i = 2; i < len; i += 3)
		{
			myCost -= prices[i];
		}
	}

	cout << myCost;
}
```

코드도 짧아지고 훨씬 깔끔해진 것 같아 마음에 든다.

<br>

그리디와 정렬 문제는 아직까지는 항상 풀만 하고 재미있는 것 같다.
