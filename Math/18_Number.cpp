#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

#define LIMIT		100000

// Bit Flag
#define NONE		0
#define PNUMBER		1
#define MULTIPLY	2

short check[LIMIT + 1];
int m, k, result = 0;

vector<int> pNums;

void Check(int len, vector<int> v = { 0,1,2,3,4,5,6,7,8,9 }, int num = 0);
bool CheckM(int number);
bool CheckPlusPrimeNumber(int number);

int main()
{
	cin >> k >> m;

	// 모두 소수(PNUMBER) 상태로 만들어 놓는다.
	memset(&check, PNUMBER, sizeof(check));

	for (int i = 2; i * i < LIMIT; i++)
	{
		if (check[i])
		{
			for (int j = i * i; j < LIMIT; j += i)
				check[j] = NONE;
		}
	}

	for (int i = 2; i < LIMIT; i++)
	{
		if (check[i])
			pNums.push_back(i);
	}

	// 소수 배열을 차례대로 돌아가며 곱한다.
	for (int i = 0; i < pNums.size(); i++)
	{
		for (int j = i; j < pNums.size(); j++)
		{
			long long result = ((long long)pNums[j] * (long long)pNums[i]);

			if (result > LIMIT) break;

			// 곱한 값을 MULTIPLY(2)를 OR 연산을 해준다.
			check[result] |= MULTIPLY;
		}
	}

	Check(k);

	cout << result;
}

// DFS 함수
// len => K, len자릿수의 수를 만들어 순회한다
// v => 0~9까지의 숫자 중 이미 쓴 숫자를 제외하는 벡터
// num => 만들고 있는 숫자
void Check(int len, vector<int> v, int num)
{
	// 목표 길이가 되면
	if (v.size() == 10 - len)
	{
		// 서로 다른 두 수의 덧셈인지, 두 소수의 곱셈인지 체크
		if (CheckM(num) && CheckPlusPrimeNumber(num))
		{
			result++;
		}

		return;
	}

	// 첫 수가 0이면 안되므로 (0143 X)
	int start = (v.size() == 10) ? 1 : 0;

	for (int i = start; i < v.size(); i++)
	{
		vector<int> tempVec = v;

		// 연장할 임시 변수 temp
		int temp = num;

		// 다음 수를 연장함
		// ex) 34 => 340 => 341
		num *= 10;
		num += v[i];

		// 연장한 숫자를 벡터에서 지우고 재귀를 불러 매개변수로 입력해줌
		tempVec.erase(tempVec.begin() + i);
		Check(len, tempVec, num);

		// 다시 원래 숫자로 돌아온다
		num = temp;
	}
}

bool CheckM(int number)
{
	while (number % m == 0)
		number /= m;

	return ((check[number] & MULTIPLY) != 0);
}

// 서로 다른 두 소수의 합인지 체크
bool CheckPlusPrimeNumber(int number)
{
	for (int pNum : pNums)
	{
		if (pNum >= number / 2) break;

		int subNum = number - pNum;

		if ((check[subNum] & PNUMBER) != 0 && subNum != pNum)
			return true;
	}

	return false;
}