#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	unordered_map<int, int> map;
	int len, input;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> input;
		map[input]++;
	}

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> input;
		cout << map[input] << ' ';
	}
}