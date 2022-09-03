#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

void Calculate(vector<long long>& arr, string str);
long long Converter(int base, string number);

struct Result
{
	long long x;
	int a, b;
};

int main()
{
	string a, b;
	cin >> a >> b;

	vector<long long> aArr;
	vector<long long> bArr;

	vector<Result> results;

	Calculate(aArr, a);
	Calculate(bArr, b);

	for (int i = 0; i < 35; i++)
	{
		if (aArr[i] == -1 || aArr[i] >= pow(2, 63)) continue;

		auto bFind = find(bArr.begin(), bArr.end(), aArr[i]);

		if (bFind != bArr.end() && i != bFind - bArr.begin())
		{
			results.push_back({ aArr[i], i + 2, bFind - bArr.begin() + 2 });
		}
	}

	if (results.empty())
		cout << "Impossible";

	else if (results.size() > 1)
		cout << "Multiple";

	else
		cout << results.front().x << " " << results.front().a << " " << results.front().b;
}

void Calculate(vector<long long>& arr, string str)
{
	char max = *max_element(str.begin(), str.end());

	// 2 ~ 36진법
	for (int i = 2; i <= 36; i++)
	{
		// 최댓값 M
		// M진수 이하일 때는 계산하지 않음
		if (isalpha(max) && i <= max - 'a' + 10)
			arr.push_back(-1);

		else if (isdigit(max) && i <= max - '0')
			arr.push_back(-1);

		else arr.push_back(Converter(i, str));
	}
}

long long Converter(int base, string number)
{
	long long result = 0;

	for (int i = number.size() - 1; i >= 0; i--)
	{
		int count = number.size() - i - 1;

		// alphabet
		if (isalpha(number[i]))
			result += (long long)((number[i] - 'a' + 10) * pow(base, count));

		// digit
		else
			result += (long long)((number[i] - '0') * pow(base, count));
	}

	return result;
}
