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
		// ���� ���� �հ� ��� ����
		// ���� ���� �۴ٸ� ��� �����
		while (!stack.empty() && stack.top() < str[i] && eraseCount > 0)
		{
			stack.pop();
			eraseCount--;
		}

		stack.push(str[i]);
	}
	
	// ������ ���ߴٸ� �ڿ������� �����ش�
	while (eraseCount-- > 0)
	{
		stack.pop();
	}

	int size = static_cast<int>(stack.size());
	str = "";

	// ������ string���� �ű��
	for (int i = 0; i < size; i++)
	{
		str.push_back(stack.top());
		stack.pop();
	}

	// �Ųٷ�
	reverse(str.begin(), str.end());

		cout << str;
}
