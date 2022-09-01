#include <string>
#include <regex>
#include <algorithm>
#include <iostream>

using namespace std;

// ���ǿ� �´� �������� �ƴ��� �Ǻ�
bool Check(char c);

string solution(string new_id)
{
    // 1. �ҹ��� ġȯ
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    // 2. ���ǿ� ���� ������ ����
    for (int i = 0; i < new_id.length(); i++)
    {
        if (Check(new_id[i]))
        {
            new_id.erase(new_id.begin() + i);
            --i;
        }
    }

    // 3. ��ħǥ �ϳ��� ġȯ
    for (int i = 1; i < new_id.length(); i++)
    {
        if (new_id[i] == '.' && new_id[i - 1] == '.')
        {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }

    // 4. �� �� ��ħǥ ���ֱ�

    if (new_id.front() == '.')
        new_id.erase(new_id.begin());

    if (new_id.back() == '.')
        new_id.pop_back();


    // 5. �� ���ڿ��̶�� a ����
    if (new_id.empty())
        new_id = "a";

    // 6. 16 ���� �̻��̸� �ڸ���
    while (new_id.size() >= 16)
    {
        new_id.pop_back();
    }

    // 6 - 1. �߶��� �� ���� ��ħǥ�� ���ֱ�
    if (new_id.back() == '.')
    {
        new_id.pop_back();
    }

    // 7. ���̰� 2�� ���϶�� ������ ���� �ݺ��ϱ�
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