#include <string>
#include <map>
#include <iostream>
#include <regex>

using namespace std;

int solution(string s)
{
	string pair[] =
	{
		"zero", "one", "two", "three", "four" , "five", "six" ,"seven", "eight", "nine"
	};

	for (int i = 0; i < 10; i++)
	{
		// value = "zero", "one"...
		string value = pair[i];

		// s �ȿ� ��� value�� ���ڷ� ġȯ
		// ex) "zero" => "0", "one" => "1"...
		s = regex_replace(s, regex(value), to_string(i));
	}

	return stoi(s);
}