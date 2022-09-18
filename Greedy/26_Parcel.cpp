#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct parcel
{
	int send, receive, box;

	// 도착지점 > 시작지점 > 택배량 순서대로 정렬
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

		// 도착지까지 가장 많이 담은 트럭 용량을 구한다
		for (int j = sendedBox[i].send; j < sendedBox[i].receive; j++)
		{
			if (maxLimit < limits[j])
				maxLimit = limits[j];
		}

		// 꽉 찼을 경우 배송 X
		if (maxLimit >= limit) continue;

		// 넣을 수 있을 만큼 넣는다.
		if (sendedBox[i].box + maxLimit > limit)
			box = limit - maxLimit;

		else
			box = sendedBox[i].box;

		answer += box;

		// 배송 지역 ~ 도착지까지의 트럭 용량에
		// 현재 배송한 박스를 더한다.
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