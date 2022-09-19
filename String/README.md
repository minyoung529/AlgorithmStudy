[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# String

문자열과 관련된 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩🟩⬛⬛⬛⬛⬛⬛⬛<br>
_31%_
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

<br>
<br>

### 2. 숫자의 합

<br>

<a href="https://www.acmicpc.net/problem/11720">11720. 숫자의 합</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/2_Sum_Of_Number.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/190933854-3802e3e8-ecd2-490d-a655-6a2f1e6c490a.png)

**string**으로 받아 각각의 character들을 int로 바꾼 다음에 계산했다.

```cpp
int len;
string str;
int sum = 0;

cin >> len >> str;

for (char c : str)
{
    sum += c - '0';
}

cout << sum;
```

<br>
<br>

### 3. !밀비 급일

<br>

<a href="https://www.acmicpc.net/problem/11365">11365. !밀비 급일</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/3_!terceS_poT.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/190942019-658ea47e-9e77-4d18-b40b-fbfd7fe21a1c.png)

END가 나올 때까지 받은 문자열을 역순으로 출력하는 문제이다.

string으로 받아 **END가 되면 반복문을 끝내**주고, 반복문을 이용해 역순으로 출력했다.

<br>

```cpp
while (true)
{
    string input, temp;
    getline(cin, input);

    // END가 나오면 끝낸다.
    if (input == "END") break;

    // 역순 출력
    for (int i = input.size() - 1; i >= 0; i--)
    {
        temp.push_back(input[i]);
    }

    cout << temp << endl;
}
```

간단한 문자열 문제였다.    

<br>
<br>

### 4. 복호화

<br>

<a href="https://www.acmicpc.net/problem/9046">9046. 복호화</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/4_Decoding.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191048739-3b71158b-af88-4d16-9e40-da5aeee28264.png)

수월하게 풀 수 있었던 문제이지만... 입력 쪽에서 조금 헤맸다.
<br>
공백까지 포함해 입력 받아야 해서 `getline(cin, str)` 함수를 썼는데, 앞서 `cin`으로 입력 받았던 테스트케이스의 개수 때문에 오류가 났었던 것이다.

표준 입력 버퍼에 `'\n'`이 남아있었기 때문에 getline을 바로 들어가면서 생긴 문제였다.

이 경우는 

```
cin.ignore();
```

이 코드를 길이를 입력받은 후에 써주니 해결이 되었다. 버퍼를 클리어 해주는 함수인가보다.
<br>
입력을 해결한 다음에는 최댓값을 구하고, 그 최댓값이 2개 이상 있는지 검사하면 끝이었다.

```cpp
int len;
cin >> len;
cin.ignore();

while (len--)
{
    string input;
    getline(cin, input);
    int max = 0, maxCount = 0, maxIndex, alphabets[26] = { 0, };

    // 입력 받기
    for (int j = 0; j < input.size(); j++)
    {
        if (isalpha(input[j]))
        {
            alphabets[input[j] - 'a']++;
        }
    }

    // max값 지정
    for (int j = 0; j < 26; j++)
    {
        if (max < alphabets[j])
        {
            max = alphabets[j];
            maxIndex = j;
        }
    }

    // 다른 max값이 있는지 탐색
    for (int j = 0; j < 26; j++)
    {
        if (max == alphabets[j])
            maxCount++;
    }

    if (maxCount == 1)
        cout << (char)('a' + maxIndex) << endl;
    else
        cout << "?" << endl;
}
```

완벽하게 마음에 드는 코드는 아니지만... 나름 직관적이고 간단하게 짠 것 같다.

<br>
<br>

### 5. 세로읽기

<br>

<a href="https://www.acmicpc.net/problem/10798">10798. 세로읽기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/5_Vertical_Reading.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191050733-bd6bf95e-c063-4c49-9e7b-d00c0ee8e3f8.png)

<br>

문제는 길지만 사실은 엄청 간단하고 쉬운 문제이다. 5줄이라는 고정된 조건과 15개의 글자라는 작은 수의 조건 때문에 쉽게 느껴진 것 같다.

<br>

5줄을 길이가 5인 **string형 배열**로 받고 0번째, 1번째... N번째 문자를 배열 순서대로 출력했다.

string의 크기는 1~15까지이므로 특정 string보다 큰 인덱스부터는 출력하지 않는 예외처리를 했다.

```cpp
#include<iostream>
using namespace std;

int main()
{
    string str[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // 배열의 J번째보다 큰 인덱스는 출력하지 않는다.
            if (str[j].size() > i)
            {
                cout << str[j][i];
            }
        }
    }
}
```

빨리 문자열 문제로 머리를 싸매고 싶다!!!

<br>
<br>

### 6. 이 구역의 승자는 누구야?!

<br>

<a href="https://www.acmicpc.net/problem/20154">20154. 세로읽기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/6_Who_Is_The_Winner.cpp">문제 풀이</a><br>

![](C:\Users\USER\AppData\Roaming\marktext\images\2022-09-20-00-30-57-image.png)

<br>

초등학교 때 해봤던 이름점 놀이랑 비슷한 것 같다.

<br>더하는 순서를 꼭 맞춰야할 것 같지만, 사실은 한꺼번에 더하면서 10의 나머지로 만드는 것만 집중하면 된다. **어차피 모두 더하게 되기 때문에!**

<br>

그리고, 지옥의 switch문을 쓰지 않기 위해 알파벳과 획이 연결되는 부분은 **배열 룩업 테이블**로 정리해주었다.

map을 쓸까 하다가, A부터 Z까지 아스키 코드로 이어지니 맵은 굳이 쓸 필요가 없다고 생각했다.

<br>

```cpp
#include<iostream>
using namespace std;

int table[26] = { 3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3 ,1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1 };

int main()
{
    string str;
    int calc = 0;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        // 10이 넘으면 그 나머지로
        if (calc > 10)
            calc %= 10;

        calc += table[str[i] - 'A'];
    }

    // 짝수라면 패배
    if (calc % 2 == 0)
        cout << "You're the winner?";

    // 홀수라면 승리
    else
        cout << "I'm a winner!";
}
```

수월하게 풀 수 있었던 문제이다!
