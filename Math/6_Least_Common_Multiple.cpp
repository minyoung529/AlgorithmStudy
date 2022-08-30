#include<iostream>
#include<vector>
#include<string>


using namespace std;

int GetLCM(int a, int b)
{
	int num = a * b;

	// 유클리드 호제법
	// GCD(a, b) == GCD(b, a%b)
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	// LCM = ( a*b / GCD(a, b) )
	return (num / a);
}

int main()
{
	/*ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len, a, b;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> a >> b;
		if (b > a) swap(a, b);

		cout << GetLCM(a, b) << '\n';
	}*/
}