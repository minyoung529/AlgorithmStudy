#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct parcel
{
	int send, receive, box;

	// �������� > �������� > �ù跮 ������� ����
	bool operator <(const parcel& p1) const
	{
		if (receive == p1.receive)
		{
			if (send == p1.send)
				return box < p1.box;

			return send < p1.send;
		}
		return receive < p1.receive;
	}
};

int limits[2001] = { 0, };
vector<parcel> sendedBox;

int main()
{
	int countryCnt, limit, len;
	int answer = 0, curLimit = 0;
	cin >> countryCnt >> limit >> len;

	for (int i = 0; i < len; i++)
	{
		int send, receive, box;
		cin >> send >> receive >> box;

		sendedBox.push_back({ send, receive, box });
	}

	sort(sendedBox.begin(), sendedBox.end());

	for (int i = 0; i < sendedBox.size(); i++)
	{
		int maxLimit = 0, box;

		// ���������� ���� ���� ���� Ʈ�� �뷮�� ���Ѵ�
		for (int j = sendedBox[i].send; j < sendedBox[i].receive; j++)
		{
			if (maxLimit < limits[j])
				maxLimit = limits[j];
		}

		// �� á�� ��� ��� X
		if (maxLimit >= limit) continue;

		// ���� �� ���� ��ŭ �ִ´�.
		if (sendedBox[i].box + maxLimit > limit)
			box = limit - maxLimit;

		else
			box = sendedBox[i].box;

		answer += box;

		// ��� ���� ~ ������������ Ʈ�� �뷮��
		// ���� ����� �ڽ��� ���Ѵ�.
		for (int j = sendedBox[i].send; j < sendedBox[i].receive; j++)
		{
			if (limits[j] + box > limit)
				limits[j] = limit;
			else
				limits[j] += box;
		}
	}

	cout << answer;
}