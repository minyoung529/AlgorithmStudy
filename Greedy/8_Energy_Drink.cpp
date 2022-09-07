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
		// (가장 큰 요소 + 가장 작 요소/2)
		double newDrink = drinks.back() + (double)(drinks.front() / 2);
		
		// 합친 원래 값을 제거
		drinks.pop_back();
		drinks.pop_front();

		drinks.push_back(newDrink);

		// 새로 만든 드링크의 적절한 자리를 비교해서 지정 (도장깨기)
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