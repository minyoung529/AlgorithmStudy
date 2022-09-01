#include <string>
#include <map>
#include <iostream>
#include <regex>

using namespace std;

int solution(string s)
{
	map<string, string> pair =
	{
		{"0","zero"}, { "1" , "one" }, { "2" , "two" }, { "3" , "three" },
		{ "4" , "four" }, { "5" , "five" }, { "6" , "six" },
		{"7","seven"}, { "8" , "eight" }, { "9" , "nine" }
	};

	for (int i = 0; i < 10; i++)
	{
		// value = "zero", "one"...
		string value = pair[to_string(i)];

		// s 안에 모든 value를 숫자로 치환
		// ex) "zero" => "0", "one" => "1"...
		s = regex_replace(s, regex(value), to_string(i));
	}

	return stoi(s);
}