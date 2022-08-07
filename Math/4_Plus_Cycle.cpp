#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	queue<char> queue;
	string input;
	int count = 0;

	cin >> input;

	if (input.size() == 1) input.insert(input.begin(), '0');

	queue.push(input[0]);
	queue.push(input[1]);

	do 
	{
		int val1 = queue.front() - '0';
		queue.pop();
		int val2 = queue.front() - '0';

		queue.push(to_string(val1 + val2).back());
		++count;

	} while (queue.front() != input[0] || queue.back() != input[1]);

	cout << count;
}