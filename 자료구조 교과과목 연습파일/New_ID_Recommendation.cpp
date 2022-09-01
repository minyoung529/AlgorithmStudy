#include <string>
#include <regex>
#include <algorithm>
#include <iostream>

using namespace std;

// 조건에 맞는 문자인지 아닌지 판별
bool Check(char c);

string solution(string new_id)
{
    // 1. 소문자 치환
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    // 2. 조건에 맞지 않으면 삭제
    for (int i = 0; i < new_id.length(); i++)
    {
        if (Check(new_id[i]))
        {
            new_id.erase(new_id.begin() + i);
            --i;
        }
    }

    // 3. 마침표 하나로 치환
    for (int i = 1; i < new_id.length(); i++)
    {
        if (new_id[i] == '.' && new_id[i - 1] == '.')
        {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }

    // 4. 양 끝 마침표 없애기

    if (new_id.front() == '.')
        new_id.erase(new_id.begin());

    if (new_id.back() == '.')
        new_id.pop_back();


    // 5. 빈 문자열이라면 a 대입
    if (new_id.empty())
        new_id = "a";

    // 6. 16 글자 이상이면 자르기
    while (new_id.size() >= 16)
    {
        new_id.pop_back();
    }

    // 6 - 1. 잘랐을 때 끝이 마침표면 없애기
    if (new_id.back() == '.')
    {
        new_id.pop_back();
    }

    // 7. 길이가 2자 이하라면 마지막 문자 반복하기
    while (new_id.size() < 3)
    {
        new_id += new_id.back();
    }

    return new_id;
}

bool Check(char c)
{
    return!(isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.');
}