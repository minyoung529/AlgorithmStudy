#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

void printarr(deque<int>& list, bool reverse);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int count;
	cin >> count;

	while (count--)
	{
		string command, arr, num = "";
		int length;
		bool isError = false, isReverse = false;
		deque<int> list;

		cin >> command >> length >> arr;

		// 문자열 파싱
		for (int i = 1; i < static_cast<int>(arr.size()); i++)
		{
			if ((arr[i] == ',' || arr[i] == ']') && !num.empty())
			{
				list.push_back(stoi(num));
				num = "";
			}
			else
			{
				num += arr[i];
			}
		}

		// 명령어 실행
		for (char c : command)
		{
			if (c == 'R')
			{
				isReverse = !isReverse;
			}
			else // D
			{
				if (list.empty())
				{
					isError = true;
					break;
				}
				else
				{
					if (isReverse)
						list.pop_back();
					else
						list.pop_front();
				}
			}
		}

		// 결과 출력
		if (isError)
		{
			cout << "error\n";
		}
		else
		{
			printarr(list, isReverse);
		}
	}
}

void printarr(deque<int>& list, bool isR)
{
	if (isR)
		reverse(list.begin(), list.end());

	cout << '[';
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i];
		if (i != list.size() - 1) cout << ',';
	}
	cout << "]\n";
}