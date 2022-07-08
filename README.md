# AlgorithmStudy

여러 코딩 테스트 문제를 푸는 저장소입니다.

<details markdown="1">
<summary>1. 스택</summary>
<a href="https://www.acmicpc.net/problem/10828">10828. 스택</a>
</details>

<details markdown="1">
<summary>2. 괄호</summary>
<a href="https://www.acmicpc.net/problem/9012">9012. 괄호</a>

</details>

<details markdown="1">
<summary>3. 큐2</summary>
<a href="https://www.acmicpc.net/problem/18258">18258. 큐 2</a>
<br><br>

막혔던 점: 시간초과로 막혔다. 로직이 문제 없다고 생각했는데 찾아보니 입출력을 하는데 시간을 많이 쓴다는 말이 있었다.

<pre>
<code> 
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
</code>
</pre>

<br>
이 코드를 앞에 적어주니 정답이 나왔다. 찾아봤더니 일반적으로 c++ 컴파일러는 c와 c++ 스타일의 입출력을 혼용하는 것을 허용하는데, 이를 구현하기 위해서 모든 표준 입출력들 또한 <b>동기화</b> 되어있다. 첫번째 줄의 코드로 그러한 동기화를 꺼줌으로써 c++ 입출력시 독립된 자신만의 버퍼를 사용하게 된다고 한다. 그리고 cout과 cin의 tie를 풀어주면 입출력 속도가 줄어들게 된다. 몰랐던 점이라 기억하고 시간 초과가 나올 때 기억해서 써야겠다.

</details>
