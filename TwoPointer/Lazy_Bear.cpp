#include <iostream>
using namespace std;
#define MAX 1000001
int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	long long int sum = 0, answer = 0;
	cin >> n >> k;

	// �Է� �ޱ�
	for (int i = 0; i < n; i++)
	{
		int pos, amount;
		cin >> amount >> pos;
		arr[pos] = amount;
	}

	// ���� �� ���ϱ�
	for (int i = 0; i < min(k * 2 + 1, MAX); i++)
		sum += arr[i];
	
	answer = sum;

	for (int i = k * 2 + 1; i < MAX; i++)
	{
		int prev = arr[i - (k * 2 + 1)];

		// �����͵��� ���������� �̵�
		answer = max(answer, sum - prev + arr[i]);
		sum += -prev + arr[i];
	}

	cout << answer;
}