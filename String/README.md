[메인으로 돌아가기](https://github.com/minyoung529/AlgorithmStudy/blob/main/README.md)

<div align="center">

# String

문자열과 관련된 문제들이 있습니다.<br><br>

**[ 현재 진행 상황 ]**<br>
🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩<br>
_100%_
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

<br>
<br>

### 7. 그룹 단어 체커

<br>

<a href="https://www.acmicpc.net/problem/1316">1316. 그룹 단어 체커</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/7_Group_Word_Checker.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191063098-7ad3c570-9aba-4320-9009-407c3993e5f8.png)

인접한 문자끼리 묶이지 않는 단어를 고르는 문제!

<br>

26의 길이를 가진 int형 배열에 알파벳의 위치를 저장해주기로 했다.

**가장 최근 문자의 위치와 현재 위치**를 비교했을 때 **차가 1 이상**이라면 그룹으로 묶이지 않는 단어임을 이용했다.

<br>

처음 나온 문자를 구별하기 위해서 초기값을 -1로 두고, 그 값은 차를 비교하지 않았다. 

<br>

```cpp
#include<iostream>
using namespace std;

int main()
{
    int len, answer = 0;
    int alphabets[26] = { 0, };
    cin >> len;
    answer = len;

    while (len--)
    {
        string input;
        cin >> input;

        // 초기화
        for (int i = 0; i < 26; i++)
            alphabets[i] = -1;

        for (int i = 0; i < input.size(); i++)
        {
            int alpha = input[i] - 'a';

            // 처음 나온 것이 아니고
            // 가장 최근에 있던 자리의 차가 1 이상이라면
            // 그룹이 아닌 것!
            if (alphabets[alpha] != -1 && i - alphabets[alpha] > 1)
            {
                answer--;
                break;
            }

            // 위치 저장
            alphabets[alpha] = i;
        }
    }

    cout << answer;
}
```

이제 문자의 아스키 코드와 정수형을 번갈아가면서 문제를 접근하는 건 나름 능숙해진 것 같아서 기분이 좋다.

<br>

어려운 문제는 싫지만... 빨리 쉬운 문자열 문제를 후딱 풀어서 어려운 문제로 고생하고 싶다!!

<br>
<br>

### 8. 단어 정렬

<br>

<a href="https://www.acmicpc.net/problem/1181">1181. 단어 정렬</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/8_Word_Sort.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191068375-1e280ef0-ab6b-42a4-9922-5a7fb1a575af.png)

<br>

먼저 단어 수로 정렬하고, 사전순으로 정렬하는 문제. 단어 길이의 최댓값이 꽤 작은 50이므로 `set<string>`을 담고 있는 길이가 50개인 배열을 먼저 만들어주었다.

<br>

알고리즘 설계를 해보았다.
<br>

1. 길이가 50개인 `set<string>`형 배열을 만든다.

2. 단어를 입력받을 때마다 `배열[단어의 길이]`의 set에 단어를 삽입해준다.

3. 길이가 1~50인 것까지 순서대로 set의 모든 문자열을 출력한다.

<br>

코드로 구현해봤다.

```cpp
int main()
{
    int len;
    set<string> str[51];

    cin >> len;

    for (int i = 0; i < len; i++)
    {
        string input;
        cin >> input;

        // 글자수별로 다른 배열 인덱스에 넣기
        str[input.size()].insert(input);
    }

    for (int i = 1; i < 51; i++)
    {
        // 단어 수대로 먼저, 사전 순으로 출력한다.
        for (string s : str[i])
        {
            cout << s << '\n';
        }
    }
}
```

set을 사용해서 시간 초과가 날 줄 알았는데, 그런 일이 없어서 다행이었다. 또, set은 인덱스로 접근이 되지 않아서 범위 기반 반복문을 사용해주었다.

오랜만에 set을 쓰니 반갑고, 알고리즘과 벡터 헤더를 쓰는 것보다 훨씬 간편해서 좋았다.

<br>

재미있었던 문제였다. 

<br>
<br>

### 9. 비밀번호 발음하기

<br>

<a href="https://www.acmicpc.net/problem/4659">4659. 비밀번호 발음하기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/9_Pronounce_Password.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191242626-365240fa-8af4-4d67-8620-0d8d3542e4c4.png)
<br>
프로그래머스 카카오 비밀번호 추천 문제랑 비슷한 문제였다. 난이도는 훨씬 쉽지만 조건을 모두 맞추는 게 조금 까다로웠다.

그래도 순서대로 조건을 쓰니 수월하게 풀렸다.

<br>

알고리즘 설계는...

1. 각 알파벳들이 **최근에 나타난 위치**를 저장하는 **int형 배열**을 이용해 `현재 위치 - 배열 위치` 의 **차가 1이면 연속됨**을 이용해 3번 조건을 체크한다.

```cpp
if (alphabets[idx] != -1 && i - alphabets[idx] == 1)
{
    if (!(s[i] == 'e' || s[i] == 'o'))
    {
        fail = true;
    }
}
```

2. **모음**이면 **자음 카운트를 초기화**하고 **모음 카운트를 올려주고**, 자음이면 그 반대로 해준다. 자음 혹은 모음 카운트가 **3**이 넘어가면 2번 조건에 위배됨을 이용했다.

```cpp
if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
{
    consonant++;
    vowel = 0;
}

else
{
    vowel++;
    consonant = 0;
}

if (vowel >= 3 || consonant >= 3)
{
    fail = true;
}
```

3. 모음일 때 true가 되는 bool형 변수를 만들어주고, 모음이 하나라도 있는지 체크할 때 이용한다.

```cpp
if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
{
    consonant++;
    vowel = 0;
}

//...
// 반복문이 끝났을 때

if (fail || !hasVowel)
{
    cout << "<" << s << "> is not acceptable." << endl;
}
else
{
    cout << "<" << s << "> is acceptable." << endl;
}
```

<br>

조건을 하나 하나 정복해가며 푸는 게 재미있었던 문제!

<br>
<br>

### 10. 나는 친구가 적다 (Small)

<br>

<a href="https://www.acmicpc.net/problem/16171">16171. 나는 친구가 적다 (Small)</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/10_I_Have_Few_Friends.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191285876-2cb455bf-aa06-416a-8122-f0d0619eb443.png)

나는 친구가 많지만 풀어본 문제이다.

<br>

처음 접근부터 틀렸던 문제. 처음에는 순서대로 문자열을 비교해준 다음에, 만약 틀린 부분이 하나라도 있다면 **그 자리에서부터** 다시 검사하는 코드였다.

<br>

코드에서 생기는 치명적인 문제를 발견했다...

![image](https://user-images.githubusercontent.com/77655318/191289471-4e7d6b30-0b59-4ced-bb11-d32bff8ee5e8.png)

문자열이 아닌 순간부터 그 다음을 다시 체크하니 있는 문자열도 체크하지 못하는 것...

코드는 이러했었다.

```cpp
for (int i = 0; i < str.size(); i++)
{
    if (sameCnt == target.size()) break;

    if (str[i] == target[sameCnt])
        sameCnt++;

    else
        sameCnt = 0;
}
```

<br>

그래서 안전하게 모든 문자를 첫 시작으로써 검사하기로 한다.

예를 들어...

```
input =>
ABAD
AD

1. A
- string[0] => A 통과
- string[1] => B 실패 (D와 같지 않음)

2. B
- string[0] => 실패 (A와 같지 않음)

3. A
- string[0] => A 통과
- string[1] => D 통과
모두 통과! break!
```

이렇게 돌아가는 로직이다. 코드는...

```cpp
for (int i = 0; i < str.size(); i++)
{
    for (int j = i; j < str.size(); j++)
    {
        // target은 0부터 시작하기 때문에 idx => j - i
        if (str[j] == target[j - i])
        {
            if (++sameCnt == target.size())
            {
                break;
            }
        }
        else break;
    }

    if (sameCnt == target.size()) break;
}

cout << (sameCnt == target.size());
```

좋은 문제였다. 로직을 짜기 전에 테스트케이스를 생각하고 짜야겠다...

<br>
<br>

### 11. 부분 문자열

<br>

<a href="https://www.acmicpc.net/problem/6550">6550. 부분 문자열</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/11_Part_String.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191382630-d046ba18-eafc-4f7b-9a52-14c390d0f527.png)

<br>

처음엔 전체 문자를 돌았을 때, 포함되어야 하는 문자가 아니면 erase나 pop을 해주고 모두 front와 비교해 가독성을 높일까 생각하다가...

문자열의 값이 100000까지이니까... 시간이 조금 걸릴 것 같아서 **인덱스 변수**를 바꾸는 것으로 했다.

<br>

설계는

1. 포함문자열[체크인덱스]가 전체 문자열[i]에 있는지 체크한다.

2. 만약 있다면, 다음 문자를 체크해야하므로 **체크인덱스를 +1** 시켜준다.

3. 전체 문자열을 다 돌았을 때, `체크 인덱스 == 포함 문자열의 길이`이면 **포함 문자열을 다 체크한 것**이므로 Yes, 그렇지 않으면 No를 출력한다.

<br>

코드로 구현했다.

```cpp
#include<iostream>
using namespace std;

int main()
{
    while (true)
    {
        string part, total;
        int checkIdx = 0;
        cin >> part >> total;

        if (cin.eof()) break;

        for (int i = 0; i < total.size(); i++)
        {
            // 만약 두 문자가 같다면
            if (total[i] == part[checkIdx])
            {
                checkIdx++;
            }
        }

        // true이면 part를 모두 체크한 것이므로 Yes
        (checkIdx == part.size()) ? cout << "Yes" << endl : cout << "No" << endl;
    }
}
```

쉽고 재밌는 문제였다.

<br>
<br>

### 12. 염색체

<br>

<a href="https://www.acmicpc.net/problem/9342">9342. 염색체</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/12_Chromosome.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191534600-1cf26f7f-8b43-47d4-88d1-119c04f88e72.png)

난 제법 꼼꼼하다 생각하고 있었는데... 그 생각을 온몸으로 부정하게 만들었던 문제...

<br>

일단 출력 대소문자를 잘못 써서 세 네번 정도 틀렸다... 바보잉...

<br>

사실 처음 보자마자 문제도 잘 이해가 되지 않았다. `문자열이 A~F 중 0개 또는 1개로 시작해야 한다`는 말이 도저히 모르겠어서 예제 출력을 보고 문제를 이해했다.

<br>
알고리즘 설계를 해봤다.

1. 첫글자와 끝 글자가 A~F까지의 글자가 아니라면 실패로 판정한다.
   
   ```cpp
   if (!(str.front() >= 'A' && str.front() <= 'F') || !(str.back() >= 'A' && str.back() <= 'F'))
   {
       isFail = true;
   }
   ```

<br>

2. 입력받은 문자열을 처음부터 끝까지 **A, F, C**가 순서대로 있는지 검사해준다.
   
    이때 A, F, C 말고도 B, D, E가 나올 수 있는 **문자열의 각 양끝 자리**는 A, F, C가 아니라도 실패로 판정하지 않는다!
   
    다만, 양 끝 자리가 아니고 A, F, C 또한 아니라면 실패로 판정한다.
   
    A를 검사할 때는 F와 C가 나오지 않을 것, F는 A가 이미 나왔고 C가 나오지 않을 것, C는 A와 F가 모두 나왔을 것을 검사해준다.
   
   ```cpp
   for (int i = 0; i < str.size(); i++)
   {
       if (isFail) break;
   
       // 양 끝 자리이거나 A, F, C일 때
       if (i == 0 || i == str.size() - 1 || str[i] == 'A' || str[i] == 'F' || str[i] == 'C')
       {
           if (str[i] == 'A' && !a)
           {
               a = (!f && !c);
               isFail = !a;
           }
   
           else if (str[i] == 'F' && !f)
           {
               f = (a && !c);
               isFail = !f;
           }
   
           else if (str[i] == 'C' && !c)
           {
               c = (a && f);
               isFail = !c;
           }
       }
       else
       {
           isFail = true;
       }
   }
   ```
   
   <br>

3. A, F, C가 모두 나왔고, 실패로 판정되지 않았다면 `Infected`를 출력!
   
   ```cpp
   // a, f, c 중 하나라도 나오지 않았다면
   if (!a || !f || !c)
       isFail = true;
   
   if (isFail)
       cout << "Good" << '\n';
   else
       cout << "Infected!" << '\n';
   ```

<br>

이렇게 구현했다.

```cpp
#include<iostream>
using namespace std;

int main()
{
    int testCnt;
    cin >> testCnt;

    while (testCnt--)
    {
        string str;
        bool isFail = false;
        bool a = false, f = false, c = false;
        cin >> str;

        if (!(str.front() >= 'A' && str.front() <= 'F') || !(str.back() >= 'A' && str.back() <= 'F'))
        {
            isFail = true;
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (isFail) break;

            // 양 끝 자리이거나 A, F, C일 때
            if (i == 0 || i == str.size() - 1 || str[i] == 'A' || str[i] == 'F' || str[i] == 'C')
            {
                if (str[i] == 'A' && !a)
                {
                    a = (!f && !c);
                    isFail = !a;
                }

                else if (str[i] == 'F' && !f)
                {
                    f = (a && !c);
                    isFail = !f;
                }

                else if (str[i] == 'C' && !c)
                {
                    c = (a && f);
                    isFail = !c;
                }
            }
            else
            {
                isFail = true;
            }
        }

        // a, f, c 중 하나라도 나오지 않았다면
        if (!a || !f || !c)
            isFail = true;

        if (isFail)
            cout << "Good" << '\n';
        else
            cout << "Infected!" << '\n';
    }
}
```

전체 코드!

<br>

코드가 좀 스마트하지도 않고... 세련되지도 않고... 깔끔하지도 않지만... 그래도 조건에 나름 잘 맞는 코드라고 생각하기는 한다.

<br>

난이도가 있고, 재미있는 문제였다. 앞으로는 출력에 오타가 난 게 아닌지 잘 살펴야겠다.

<br>
<br>

### 13. 듣보잡

<br>

<a href="https://www.acmicpc.net/problem/1764">1764. 듣보잡</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/13_Never_Heard_Seen_Before.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191544174-346e3743-e5f0-4cbb-af4b-1ddb0cec9c5e.png)

해시를 써서 간단하게 해결했던 문제!

<br>

알고리즘 설계는...

1. 듣지도 못한 사람의 이름을 **map의 key**값, value는 모두 false로 해준다.
   
   ```cpp
   while (heardCnt--)
   {
       cin >> input;
       people.insert({ input, false });
   }
   ```
   
   <br>

2. 보지도 못한 사람의 이름이 **map의 key에 있다면**, value를 true로 바꾸어준다.
   
   ```cpp
   while (seenCnt--)
   {
       cin >> input;
   
       // 듣도 보도 못한 사람이었으면
       if (people.find(input) != people.end())
       {
           // value값을 true로
           people[input] = true;
           answer++;
       }
   }
   ```
   
   <br>

3. 듣보잡의 수를 출력하고 map을 **범위 기반 for문**으로 돌아 듣보잡의 이름(key) 또한 출력해준다.
   
   ```cpp
   // 듣보잡 수 출력
   cout << answer << '\n';
   
   for (auto pair : people)
   {
       // value값이 true인 요소들만 사전순으로 출력한다
       if (pair.second)
       {
           cout << pair.first << '\n';
       }
   }
   ```
   
   <br>

> 전체 코드

```cpp
#include<iostream>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int heardCnt, seenCnt, answer = 0;
    map<string, bool> people;
    string input;

    cin >> heardCnt >> seenCnt;

    // 듣도 보도 못한 사람을 맵에 key로 넣어준다
    while (heardCnt--)
    {
        cin >> input;
        people.insert({ input, false });
    }

    while (seenCnt--)
    {
        cin >> input;

        // 듣도 보도 못한 사람이었으면
        if (people.find(input) != people.end())
        {
            // value값을 true로
            people[input] = true;
            answer++;
        }
    }

    // 듣보잡 수 출력
    cout << answer << '\n';

    for (auto pair : people)
    {
        // value값이 true인 요소들만 사전순으로 출력한다
        if (pair.second)
        {
            cout << pair.first << '\n';
        }
    }
}
```

간단하게 구현했다. 해시를 사용한 문제는 항상 재미있는 것 같다!

<br>
<br>

### 14. 파일 정리

<br>

<a href="https://www.acmicpc.net/problem/20291">20291. 파일 정리</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/14_Arrange_File.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191562664-0415aaca-3e45-43a8-8401-2c643f9ef22d.png)

확장자의 개수와 이름을 사전순으로 출력하는 문제.

확장자는 **이름이 같으면 같은 확장자**이므로, 개수도 이름이 같으면 해당 확장자의 개수가 더해진다. 따라서 이름으로 쉽게 접근할 수 있는 해시를 이용했다. MAP!

<br>

**알고리즘 설계**

1. '.'이 될 때까지 반복문을 돌고 그 인덱스를 구한다.

2. 저장한 인덱스부터 문자열의 끝까지는 확장자명이다. **Map**의 확장자 키에 value를 1씩 올려준다.

<br>

간단하게 구현할 수 있었다.

코드는...

```cpp
#include<iostream>
#include<map>
using namespace std;

int main()
{
    int len;
    map<string, int> extensions;
    cin >> len;

    while (len--)
    {
        string input, extension = "";
        int curIndex = 0;
        cin >> input;

        // '.'일 때까지 돌린다
        while (input[++curIndex] != '.');

        // 구한 curIndex부터 끝까지 새 문자열에 넣어준다
        while (++curIndex < input.size())
            extension.push_back(input[curIndex]);

        // 만든 새 문자열을 key로 등록하고, value를 1씩 올려준다
        extensions[extension]++;
    }

    // 사전순 출력
    for (auto pair : extensions)
    {
        cout << pair.first << ' ' << pair.second << '\n';
    }
}
```

쉽고 재밌는 문제!

<br>
<br>

### 15. 단어 뒤집기 2

<br>

<a href="https://www.acmicpc.net/problem/17413">17413. 단어 뒤집기 2</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/15_Reverse_Word.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191563924-7778aea7-8df1-40c1-8065-995b0b625883.png)

괄호를 보고 무조건 스택이다!! 했던 문제. 사실 굳이 스택을 쓸 필요는 없었지만... 그게 정석인 것 같아서 마음이 편했다.

<br>

**알고리즘 설계**

1. 만약 여는 괄호(**<**)라면 **스택에 Push**해주고 출력한다.

2. 닫는 괄호(**>**)라면 **스택에서 Pop**해주고 출력한다.

3. 괄호가 아니고, 스택이 비어있고, 문자나 숫자라면! 해당 인덱스부터 **'.'이나 '<'가 나올 때까지의 문자들을 모두 역순 출력** 해준다.

4. 공백이라면 공백을 출력한다.

<br>

**코드**

```cpp
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string input;
    stack<char> stk;
    getline(cin, input);

    for (int i = 0; i < input.size(); i++)
    {
        // '<'라면 스택에 push
        if (input[i] == '<')
        {
            stk.push(input[i]);
        }

        // '>'라면 스택에 pop
        else if (input[i] == '>')
        {
            stk.pop();
        }

        // 괄호의 영향을 받지 않고, 공백이 아닐 때
        else if (stk.empty() && input[i] != ' ')
        {
            int start = i;

            // i를 공백까지 인덱스로
            while (i + 1 < input.size() && input[i + 1] != ' ' && input[i + 1] != '<') { ++i; }

            // i부터 start까지 역순 출력
            for (int j = i; j >= start; j--)
            {
                cout << input[j];
            }

            continue;
        }

        // 현재 문자 출력
        cout << input[i];
    }
}
```

<br>

조금 어려웠지만, 조건들을 차근차근 풀어나가는 게 재미있었던 문제!

머릿속으로 코드를 시뮬레이션해보는 데 있어서 아직 부족함을 느꼈기도 하다. 비슷한 문제로 조금 더 어려운 문제도 있었으면 좋겠다.

<br>
<br>

### 16. 회문

<br>

<a href="https://www.acmicpc.net/problem/17609">17609. 회문</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/16_Palindrome.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191792483-f905da9c-b0c3-4dcb-9baa-41741f0d0388.png)

회문은 껌이라고 생각한 나에게... 유사 회문이란 시련을 준 문제. 첫 접근을 애매하게 잘해서 문제가 되었다.

<br>

처음 알고리즘 설계는...

<br>

1. 두 포인터가 문자열의 중심에서 가까워지며 **양 끝**이 같은지 검사한다.
   
   <br>

2. 두 포인터의 값이 같지 않다면...
   
   왼쪽 포인터는 `오른쪽 - 1`의 값과 같은지, 오른쪽 포인터는 `왼쪽 + 1`과 같은지 검사한다.
   
   만약 같다면 검사한 쪽의 포인터를 문자열에서 없애준다. 없애주면 회문이 될 수도 있으므로!
   
   <br>

3. 두 포인터의 값이 같지 않고, 2를 2번 이상 반복하면 유사 회문이 아니다.

<br>

글로 쓰니 이해가 안 돼서, 그림으로 가져왔다!

![image](https://user-images.githubusercontent.com/77655318/191867759-9a6b6409-f183-4e00-9e51-286fc199a5e1.png)

```cpp
#include<iostream>
using namespace std;

int main()
{
    int testCnt;
    cin >> testCnt;

    while (testCnt--)
    {
        string input;
        int exIndex = -1;
        int palindrome = 0;
        cin >> input;

        for (int i = 0; i < input.size() / 2 + 1; i++)
        {
            int ri = input.size() - i - 1;

            if (palindrome >= 2)break;
            if (input[i] == input[ri])continue;

            if (input[i] == input[ri - 1] || input[ri] == input[i + 1])
            {
                if (input[i] == input[ri - 1])
                    exIndex = ri;
                else
                    exIndex = i;

                input.erase(input.begin() + exIndex);
                i = 0;
                palindrome++;
            }
            else
            {
                palindrome = 2;
            }
        }

        if (palindrome > 2)
            palindrome = 2;

        cout << palindrome << endl;
    }
}
```

하지만... 이 로직에는 치명적인 단점이 있었다. 

왼쪽 포인터는 `오른쪽 - 1`의 값과 같은지, 오른쪽 포인터는 `왼쪽 + 1`과 같은지 검사할 때, 둘이 같은 경우는 처리해주지 않았던 것이다!

```
input =>
XYXYAAYXY

output =>
XYXYAAYX

answer =>
YXYAAYXY
```

그래서... 먼저 쓴 코드가 처리 된다는 점... 

<br>

많은 고민을 하다가, 왼쪽이 오른쪽-1, 오른쪽이 왼쪽+1, 둘 중 하나라도 같은 게 확인이 된다면

둘 모두 팰린드롬인지 검사하고, 하나라도 팰린드롬이면 **유사 회문** 처리를 하고, 그렇지 않으면 **회문이 아님**을 처리한다.

```cpp
#include<iostream>
using namespace std;

bool IsPalindrome(string str);
bool IsPseudoPalindrome(string str, int remove);

int main()
{
    int testCnt;
    cin >> testCnt;

    while (testCnt--)
    {
        string input;
        int answer = 0;
        cin >> input;

        for (int i = 0; i < input.size() / 2 + 1; i++)
        {
            int ri = input.size() - i - 1;

            // 값이 정해졌다면 break!
            if (answer > 0)break;
            if (input[i] == input[ri])continue;

            if (input[i] == input[ri - 1] || input[ri] == input[i + 1])
            {
                // 제거했을 때 둘 중 하나라도 팰린드롬이라면 유사팰린드롬
                // 그렇지 않으면 회문도, 유사회문도 아님
                if (IsPseudoPalindrome(input, ri) || IsPseudoPalindrome(input, i))
                {
                    answer = 1;
                }        
                else
                {
                    answer = 2;
                }
            }
            else
            {
                answer = 2;
            }
        }

        cout << answer << endl;
    }
}

// 팰린드롬 검사 함수
bool IsPalindrome(string str)
{
    for (int i = 0; i < str.size() / 2 + 1; i++)
    {
        int ri = str.size() - i - 1;

        if (str[i] != str[ri])
        {
            return false;
        }
    }

    return true;
}

// 유사 팰린드롬 검사 함수
bool IsPseudoPalindrome(string str, int remove)
{
    str.erase(str.begin() + remove);
    return (IsPalindrome(str));
}
```

확실히 시간이 조금 오래 걸리는 코드이지만, 깔끔한 것 같다.

<br>

코드에 조건을 걸 때도, 항상 여러 케이스를 생각하며 꼼꼼하게 조건을 달아야겠다!

<br>
<br>

### 17. 문자열 게임 2

<br>

<a href="https://www.acmicpc.net/problem/20437">20437. 문자열 게임 2</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/17_String_Game_2.cpp">문제 풀이</a><br>

![image](https://user-images.githubusercontent.com/77655318/191792886-8177cbfd-f128-40fb-bb7f-b59a372cfb5b.png)

보자마자 엄청 어려울 것 같은 문제였지만... 3번과 4번 조건을 하나하나씩 정복하면 꽤 쉬운 문제였다. 

<br>

하지만... 개행을 안 하는 치명적인 실수로 5번을 광탈한 다음에... 가장 최상의 코드로 도전을 해봤는데도 광속 탈락이길래 이상해서 **출력이 잘못된 것 아닌가** 의심을 했는데...

혹시나 했더니 역시나... 개행을 안 해줬던 것이다... 바보!!!!!

<br>

사소한 실수임에도 꽤 얻은 게 있다. 5번의 탈락으로 코드를 깔끔하고 효율적이게 정리했고, 코드의 길이를 2배 정도 줄일 수 있었다!

<br>

처음 접근은...

1. 알파벳마다 **queue**를 생성해주고, 알파벳 개수(26)개의 길이인 **최단길이 배열, 최장길이 배열**을 생성해준다.

`queue => 알파벳이 K개 들어있는 최단, 최장거리를 갱신해주기 위함`
`최단길이, 최장길이 배열 => 알파벳의 최단길이, 최장길이를 저장하기 위함`

<br>

2. 해당 알파벳의 queue의 길이가 K-1을 넘어가면, queue의 **front와 현재 위치의 거리**를 구해주고 pop해준다.

<br>

3. 문자열을 돌아가며 queue에 **해당 문자의 위치**를 넣어준다.

<br>

4. 2~3을 문자열이 끝날 때까지 **반복**한다.

<br>

5. 3에서 나온 거리 중에 가장 작은 값과 큰 값을 출력한다. 
   
   이때, 작은 값의 변수와 큰 값의 **변수가 초깃값과 같다면** 어떤 문자를 K개 포함하지 않으므로 -1을 출력한다.

<br>

코드로 짜봤다.

```cpp
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int tCnt;
    cin >> tCnt;

    while (tCnt--)
    {
        string str;
        queue<int> alphabets[26];
        int minDists[26], maxDists[26], num;
        int result1 = 10001, result2 = -1;
        cin >> str >> num;

        fill_n(minDists, 26, 10000);
        fill_n(maxDists, 26, 0);

        for (int i = 0; i < str.size(); i++)
        {
            int idx = str[i] - 'a';

            if (!alphabets[idx].empty() && alphabets[idx].size() == num - 1)
            {
                int dist = i - alphabets[idx].front() + 1;

                // 조건 3
                if (dist < minDists[idx])
                {
                    minDists[idx] = dist;

                    if (dist < result1)
                        result1 = dist;
                }

                // 조건 4
                if (dist > maxDists[idx])
                {
                    maxDists[idx] = dist;

                    if (dist > result2)
                        result2 = dist;
                }

                alphabets[idx].pop();
            }

            alphabets[idx].push(i);
        }

        if (result1 > 10000 && result2 < 0)
        {
            // 이때 개행을 안 했다...
            if (num == 1)
                cout << "1 1";
            else
                cout << -1;
        }
        else
            cout << result1 << ' ' << result2 << '\n';
    }
}
```

<br>

개행을 안 했으니 결과는 광속 탈락... 이었지만... 코드를 자세히 보다 필요 없는 부분을 떼어냈다. 

<br>

* 최단길이와 최장길이를 알파벳별로 저장하는 배열을 제거했다.
  
  알파벳에 상관 없이 최단길이, 최장길이를 구하면 되므로 굳이 필요가 없었던 배열이었기 때문이다.

* queue의 push하는 것을 길이를 구하는 것보다 먼저 했다.
  
  입력이 `1 >= K >= W`이므로 1도 포함이 된다. 길이를 먼저 구하면 queue의 size가 0이 되어 별도로 처리를 해주어야 하는데, 먼저 푸쉬하면 그럴 필요가 없다!

<br>

이 개선점을 반영해서 작성한 코드이다.

```cpp
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int tCnt;
    cin >> tCnt;

    while (tCnt--)
    {
        string str;
        queue<int> alphabets[26];
        int result1 = 10001, result2 = -1, num;
        cin >> str >> num;

        for (int i = 0; i < str.size(); i++)
        {
            int idx = str[i] - 'a';

            alphabets[idx].push(i);

            if (alphabets[idx].size() == num)
            {
                int dist = i - alphabets[idx].front() + 1;

                result1 = min(dist, result1);
                result2 = max(dist, result2);

                alphabets[idx].pop();
            }
        }

        if (result2 < 0)
            cout << -1 << '\n';

        else
            cout << result1 << ' ' << result2 << '\n';
    }
}
```

고친 것도 개행이 없어서 바로 틀렸습니다가 나왔었다... 이상해서 뚫어져라 쳐다보는데 개행이 빠진 걸 발견했다... 이 바보...

<br>

그래도 코드를 나름 깔끔하게 잘 짠 것 같아서 기분이 좋다!!!! 

<br>
<br>

### 18. 부분 문자열

<br>

<a href="https://www.acmicpc.net/problem/16916">16916. 부분 문자열</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/18_Part_String.cpp">문제 풀이</a><br>

나에게 strstr 함수를 쓰도록 만든 문제...

<br>

처음엔 어려운 문제는 아니니까 strstr은 안 써야지... 생각하고 있었다. 그래서 받은 string 길이로 반복문을 돌 때 첫 글자가 똑같다면, 거기서부터 부분과 비교하는 코드를 짰다.

```cpp
#include<iostream>
using namespace std;

string part, total;

int main()
{
    int checkIdx = 0;
    bool isPart = false;
    cin >> total >> part;

    for (int i = 0; i < total.size(); i++)
    {
        if (isPart)break;

        if (total[i] == part[0])
        {
            // 첫 글자가 같을 때 비교
            for (int j = i; j < i + part.size(); j++)
            {
                if (total[j] != part[j - i]) break;

                if (j == i + part.size() - 1)
                {
                    isPart = true;
                    break;
                }
            }
        }
    }

    (isPart) ? cout << 1 : cout << 0;
}
```

하지만... 이 코드는 시간 초과가 났고... 하나를 배우면 하나를 아는 나는 꼼수 아닌 꼼수를 써서 첫 글자와 마지막 글자를 비교해보기로 했다.

```cpp
        if (total[i] == part.front() && total[i + part.size() - 1] == part.back())
```

이렇게... 될 리가 있나.
아까보다 실행 속도가 조오금 빨라지긴 했지만... 그뿐이었다.

<br>

그래서 검사를 할 때 첫 글자인 부분이 끼어있다면, 재검사할 때 그곳부터 시작하는 거로 하였다.

```cpp
for (int i = 0; i < total.size() - part.size() + 1; i++)
{
    if (isPart)break;

    if (total[i] == part.front() && total[i + part.size() - 1] == part.back())
    {
        int start = i;
        for (int j = i; j < i + part.size(); j++)
        {
            // 가장 처음에 나온 시작 위치를 지정
            if (total[j] == part.front() && start == i)
                start = j - 1;

            if (total[j] != part[j - i])
            {
                i = start;
                break;
            }
            if (j == i + part.size() - 1)
            {
                isPart = true;
                break;
            }
        }
    }
}
```

얘도 뭐... 될 리가 없었고... ㅠ_ㅠ 

<br>

대망의 마지막 도전! 첫 글자를 비교해서 같을 때, **substr로 전체 문자열을 부분문자열의 사이즈로** 잘라주고 비교하는 것!

```cpp
for (int i = 0; i < total.size() - part.size() + 1; i++)
{
    if (isPart)break;

    if (total[i] == part.front())
    {
        string temp = total.substr(i, part.size());

        if (temp == part)
        {
            isPart = true;
            break;
        }
    }
}
```

이쁘게 짠 코드라고 생각했지만, 역시 시간 초과였다.

<br>

결국 strstr을 써서 해결했고...

```cpp
#include<iostream>
#include<string.h>
using namespace std;

char part[1000001], total[1000001];

int main()
{
    bool isPart = false;
    cin >> total >> part;

    cout << (strstr(total, part) != nullptr);
}
```

도대체 strstr을 구성하는 알고리즘이 뭐길래... 똑똑한 사람들이 한데모여 어떻게 이렇게 잘 짰는지 궁금해서 알고리즘을 찾아봤다.

<br>
strstr에서 사용한 알고리즘은 바로 보이어 무어 알고리즘!!

[설명 링크](https://chanhuiseok.github.io/posts/algo-15/)

이런 탐색 알고리즘을 생각한 사람은 천재 아닐까... 나중에 한 번 구현해봐야겠다!

<br>
<br>

### 19. 파일 탐색기

<br>

<a href="https://www.acmicpc.net/problem/20210">20210. 파일 탐색기</a><br>
<a href="https://github.com/minyoung529/AlgorithmStudy/blob/main/String/19_File_Explorer.cpp">문제 풀이</a><br>

단계단계 차례차례 조건을 해결해가는 게 엄청 재미있었던 문제! 구현할 코드가 많았지만, 그렇게 어려워하면서 풀지는 않았다. 예쁘장한 코드를 짜진 못했지만...

<br>

**알고리즘 설계!**

algorithm 헤더의 sort에 들어가 **cmp 함수**를 구현하는 데 집중했다.

<br>



1. 비교할 문자 2개의 길이 중 **큰 길이**로 반복문을 돌린다!

<br>

2. 어느 **하나라도 문자이고 둘이 같지 않다면**, 2개의 비교를 해준다.
   
   ```cpp
   if ((isalpha(str1[i]) || isalpha(str2[i])) && str1[i] != str2[i])...
   ```
   
   - 만약 한쪽이 숫자라면, **숫자인 쪽이 더 위로** 정렬된다.
     
     ```cpp
     // 문자 < 숫자
     if (isdigit(str1[i]) || isdigit(str2[i]))
     {
        return isdigit(str1[i]);
     }
     ```
   
   - 둘 다 문자라면, AaBbCc...Zz 순으로 정렬한다.
     정수로 바꿔 더 작은 쪽이 위로 정렬된다.
     
     ```cpp
     // a = 0, A = 0... b = 1, B = 1
     char temp1 = (isupper(str1[i])) ? str1[i] - 'A' : str1[i] - 'a';
     char temp2 = (isupper(str2[i])) ? str2[i] - 'A' : str2[i] - 'a';
     
     // 같은 문자라면 (a, A)
     // 대문자가 위로 정렬
     if (temp1 == temp2)
     {
        return isupper(str1[i]);
     }
     
     // a to z 문자 정렬
     return temp1 < temp2;
     ```
     
     <br>

3. 둘 다 숫자라면 숫자로 비교한다.
   
   - 비교할 문자 모두 숫자가 0부터 시작된다면, **0의 개수**를 각각 세어주고 string에서 **erase** 해준다.
     
     ```cpp
     int zCnt1 = 0, zCnt2 = 0;
     
     while (str1[i] == '0')
     {
         str1.erase(str1.begin() + i);
         zCnt1++;
     }
     while (str2[i] == '0')
     {
         str2.erase(str2.begin() + i);
         zCnt2++;
     }
     ```
   
   - 만약 한 문자열의 현재 값이 **먼저 알파벳**이 됐을 때, 자릿수가 더 작다는 뜻이므로 **위로 정렬**해준다.
     
     ```cpp
     if (isalpha(str1[i]) || isalpha(str2[i]))
     {
     return isdigit(str2[i]);
     }
     ```
   
   - 만약 두 숫자의 길이가 같고, 값이 같지 않을 때 **작은 자릿수의 숫자가 더 작았던** 문자열이 **숫자가 더 작은** 문자열이므로 **위로 정렬**해준다.
     
     ```cpp
     // 숫자가 큰 쪽
     // state == 1 > false, 2 > true
     // 기본값 0
     if (state == 0 && str1[i] != str2[i])
     {
      state = 1 + (str1[i] < str2[i]);
     }
     
     // 나중에 비교할 때
     if (state)
      return (state - 1);
     ```
   
   - 두 숫자의 길이가 같고, 값이 같을 땐 비교하기 전 세주었던 **0의 개수가 더 작은 쪽**이 위로 정렬되게끔 해준다.
     
     ```cpp
     if (zCnt1 != zCnt2)
     return zCnt2 > zCnt1;
     ```

<br>

4. 정렬이 아직 되지 않았다면, **길이가 더 짧은 문자열**이 위로 정렬된다.
   
   ```cpp
   return str1.size() < str2.size();
   ```



<br>



설명이 조금 불친절하긴 하지만... 이렇게 설계를 해봤다.



전체 코드를 보자.



> main

```cpp
int main()
{
	int len;

	cin >> len;
	strs.resize(len);

	for (int i = 0; i < len; i++)
	{
		cin >> strs[i];
	}

	sort(strs.begin(), strs.end(), cmp);

	for (string s : strs)
	{
		cout << s << '\n';
	}
}
```



> cmp function

```cpp
bool cmp(string str1, string str2)
{
	bool isGreater = true;
	int maxSize = max(str1.size(), str2.size());

	for (int i = 0; i < maxSize; i++)
	{
		if (i >= str1.size() || i >= str2.size()) break;

		// 그냥 문자
		if ((isalpha(str1[i]) || isalpha(str2[i])) && str1[i] != str2[i])
		{
			// 문자 < 숫자
			if (isdigit(str1[i]) || isdigit(str2[i]))
			{
				return isdigit(str1[i]);
			}

			char temp1 = (isupper(str1[i])) ? str1[i] - 'A' : str1[i] - 'a';
			char temp2 = (isupper(str2[i])) ? str2[i] - 'A' : str2[i] - 'a';

			if (temp1 == temp2)
			{
				return isupper(str1[i]);
			}

			// a to z 문자 정렬
			return temp1 < temp2;
		}

		// 숫자 비교
		else if (isdigit(str1[i]) && isdigit(str2[i]))
		{
			int zCnt1 = 0, zCnt2 = 0;
			int state = 0;

			while (str1[i] == '0')
			{
				str1.erase(str1.begin() + i);
				zCnt1++;
			}
			while (str2[i] == '0')
			{
				str2.erase(str2.begin() + i);
				zCnt2++;
			}

			while (isdigit(str1[i]) || isdigit(str2[i]))
			{
				if ((i >= str1.size() || i >= str2.size()) && str1.size() != str2.size())
				{
					return (str1.size() < str2.size());
				}

				// 자릿수가 더 큰 쪽이 위로
				if (isalpha(str1[i]) || isalpha(str2[i]))
				{
					return isdigit(str2[i]);
				}

				// 숫자가 큰 쪽
				if (state == 0 && str1[i] != str2[i])
				{
					state = 1 + (str1[i] < str2[i]);
				}

				i++;
			}

			if (state)
				return (state - 1);

			if (zCnt1 != zCnt2)
				return zCnt2 > zCnt1;

			i--;
		}
	}

	return str1.size() < str2.size();
}
```



딱 봐도 잘 쓰고 예쁜 코드는 아니지만... 나름 잘 해결해낸 것 같다! 단계별로 차근차근 풀어야하는 문자열 문제의 참맛을 알 수 있었다!



기분이 좋다 ㅎㅎ  b ^_^ d



<br>



그리 길지 않았던 문자열 추천 문제의 대장정이 끝나고... 나는 내가 부족한 다이나믹 프로그래밍 쪽을 풀어보려고 한다. dp는 조금 겁나긴 하지만... 언젠가 허물어야 할 벽이기 때문에 최대한 빨리 허물고 dp 문제를 연마하고 싶다!!



기다려라 dp...
