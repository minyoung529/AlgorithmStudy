#include<iostream>
#include<string>
using namespace std;

int main()
{
	while (true)
	{
		string input, temp;
		getline(cin, input);

		if (input == "END") break;

		for (int i = input.size() - 1; i >= 0; i--)
		{
			temp.push_back(input[i]);
		}

		cout << temp << endl;
	}
}