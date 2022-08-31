#include<iostream>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;
	bool check[1001] = { false, };

	for (int i = 2; i <= n; i++)
	{
		// 이미 체크한 숫자면 continue
		if (check[i]) continue;

		int p = i;

		while (p <= n)
		{
			// 이미 체크한 숫자면 체크하지 않는다
			if (!check[p])
			{
				check[p] = true;

				// K번째 지울 수일 때
				if (--k == 0)
				{
					cout << p << endl;
					return 0;
				}
			}

			// p의 배수를 순서대로 (ex) 3, 6, 9...)
			p += i;
		}
	}
}