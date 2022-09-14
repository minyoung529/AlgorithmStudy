#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
	int len, eraseCount = 0;
	cin >> len >> eraseCount;

	string str;
	stack<char> stack;
	cin >> str;

	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		// 들어온 수를 앞과 계속 비교해
		// 앞의 수가 작다면 계속 지운다
		while (!stack.empty() && stack.top() < str[i] && eraseCount > 0)
		{
			stack.pop();
			eraseCount--;
		}

		stack.push(str[i]);
	}
	
	// 지우지 못했다면 뒤에서부터 지워준다
	while (eraseCount-- > 0)
	{
		stack.pop();
	}

	int size = static_cast<int>(stack.size());
	str = "";

	// 스택을 string으로 옮긴다
	for (int i = 0; i < size; i++)
	{
		str.push_back(stack.top());
		stack.pop();
	}

	// 거꾸로
	reverse(str.begin(), str.end());

		cout << str;
}
