//#include<bits/stdc++.h>
//using namespace std;
//
//// 아직 못 푼 문제 ㅠㅠ
//
//int main()
//{
//	stack<char> stack;
//	string str, target;
//	int checkIdx = 0;
//	cin >> str >> target;
//
//	for (int i = 0; i < str.size(); i++)
//	{
//		stack.push(str[i]);
//
//		if (str[i] == target[checkIdx])
//		{
//			checkIdx++;
//
//			if (checkIdx == target.size())
//			{
//				while (checkIdx--)
//				{
//					stack.pop();
//				}
//
//				checkIdx = 0;
//			}
//		}
//		else
//		{
//			checkIdx = 0;
//
//			if (str[i] == target[checkIdx])
//				checkIdx++;
//		}
//	}
//
//	if (stack.empty())
//	{
//		cout << "FRULA";
//	}
//	else
//	{
//		while (!stack.empty())
//		{
//			cout << stack.top();
//			stack.pop();
//		}
//	}
//}