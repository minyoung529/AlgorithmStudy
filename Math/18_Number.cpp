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

	// ��� �Ҽ�(PNUMBER) ���·� ����� ���´�.
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

	// �Ҽ� �迭�� ���ʴ�� ���ư��� ���Ѵ�.
	for (int i = 0; i < pNums.size(); i++)
	{
		for (int j = i; j < pNums.size(); j++)
		{
			long long result = ((long long)pNums[j] * (long long)pNums[i]);

			if (result > LIMIT) break;

			// ���� ���� MULTIPLY(2)�� OR ������ ���ش�.
			check[result] |= MULTIPLY;
		}
	}

	Check(k);

	cout << result;
}

// DFS �Լ�
// len => K, len�ڸ����� ���� ����� ��ȸ�Ѵ�
// v => 0~9������ ���� �� �̹� �� ���ڸ� �����ϴ� ����
// num => ����� �ִ� ����
void Check(int len, vector<int> v, int num)
{
	// ��ǥ ���̰� �Ǹ�
	if (v.size() == 10 - len)
	{
		// ���� �ٸ� �� ���� ��������, �� �Ҽ��� �������� üũ
		if (CheckM(num) && CheckPlusPrimeNumber(num))
		{
			result++;
		}

		return;
	}

	// ù ���� 0�̸� �ȵǹǷ� (0143 X)
	int start = (v.size() == 10) ? 1 : 0;

	for (int i = start; i < v.size(); i++)
	{
		vector<int> tempVec = v;

		// ������ �ӽ� ���� temp
		int temp = num;

		// ���� ���� ������
		// ex) 34 => 340 => 341
		num *= 10;
		num += v[i];

		// ������ ���ڸ� ���Ϳ��� ����� ��͸� �ҷ� �Ű������� �Է�����
		tempVec.erase(tempVec.begin() + i);
		Check(len, tempVec, num);

		// �ٽ� ���� ���ڷ� ���ƿ´�
		num = temp;
	}
}

bool CheckM(int number)
{
	while (number % m == 0)
		number /= m;

	return ((check[number] & MULTIPLY) != 0);
}

// ���� �ٸ� �� �Ҽ��� ������ üũ
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