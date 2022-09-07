#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);  cout.tie(NULL); cin.tie(NULL);

	int len;
	deque<double> drinks;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int input;
		cin >> input;
		drinks.push_back(input);
	}

	sort(drinks.begin(), drinks.end());

	while (drinks.size() != 1)
	{
		// (���� ū ��� + ���� �� ���/2)
		double newDrink = drinks.back() + (double)(drinks.front() / 2);
		
		// ��ģ ���� ���� ����
		drinks.pop_back();
		drinks.pop_front();

		drinks.push_back(newDrink);

		// ���� ���� �帵ũ�� ������ �ڸ��� ���ؼ� ���� (�������)
		for (int i = drinks.size() - 1; i >= 0; i--)
		{
			if (drinks[i] < drinks.back())
				break;

			else
				swap(drinks[i], drinks.back());
		}
	}

	cout << drinks.front();
}