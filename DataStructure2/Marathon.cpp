#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";
	unordered_map<string, int> map;

	for (string str : completion)
	{
		map[str]++;
	}

	for (string str : participant)
	{
		if (--map[str] == -1)
		{
			return str;
		}
	}
}