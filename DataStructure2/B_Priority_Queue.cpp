#include <string>
#include <queue>
#include <vector>
#include<iostream>
using namespace std;

bool popped[1000000] = { false, };	// �̹� ���ŵ� ���̵��� üũ�ϴ� �迭
priority_queue<pair<int, int>> maxHeap;
priority_queue<pair<int, int>> minHeap;

int getvalue(priority_queue<pair<int, int>>& queue, bool isMin = false);

vector<int> solution(vector<string> operations)
{
	vector<int> answer;

	for (int i = 0; i < operations.size(); i++)
	{
		if (operations[i][0] == 'I')
		{
			int val = stoi(operations[i].substr(2, operations.size()));
			maxHeap.push({ val, i });
			minHeap.push({ -val, i });
		}
		else
		{
			if (operations[i][2] == '1')
				getvalue(maxHeap);
			else
				getvalue(minHeap, true);
		}
	}

	answer.push_back(getvalue(maxHeap));
	answer.push_back(getvalue(minHeap, true));

	return answer;
}

int getvalue(priority_queue<pair<int, int>>& queue, bool isMin)
{
	if (queue.empty()) return 0;

	while (!queue.empty())
	{
		pair<int, int> top = queue.top();
		queue.pop();

		if (!popped[top.second])	// �̹� ���ŵ��� ���� �ֵ鸸 return
		{
			popped[top.second] = true;	// ���ŵ��� üũ

			if (isMin) return -top.first;
			return top.first;
		}
	}
	return 0;
}