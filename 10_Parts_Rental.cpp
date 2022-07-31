#include<iostream>
#include<string>
#include<map>
using namespace std;

int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
struct user
{
	string name;
	int rentalTime;
};

int MonthToDay(int month)
{
	if (month == 1)return 0;

	int days = 0;

	for (int i = 0; i < month - 1; i++)
		days += monthDays[i];

	return days;
}

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len;
	int fine;
	string sDuration;
	int duration = 0;
	map<string, map<string, user>> rentals;
	map<string, long long> fineReports;

	cin >> len >> sDuration >> fine;

	duration += stoi(sDuration.substr(0, 3)) * 1440;		// Day
	duration += stoi(sDuration.substr(4, 2)) * 60;			// Hour	
	duration += stoi(sDuration.substr(7, 2));				// Minute

	for (int i = 0; i < len; i++)
	{
		string ymd, time, part, name;
		int curTime = 0;
		cin >> ymd >> time >> part >> name;

		curTime += MonthToDay(stoi(ymd.substr(5, 2))) * 1440;	// Month
		curTime += stoi(ymd.substr(8, 2)) * 1440;				// Day
		curTime += stoi(time.substr(0, 2)) * 60;				// Hour
		curTime += stoi(time.substr(3, 2));						// Minute

		// 대여 목록에서 찾는다면
		if (rentals.find(part) != rentals.end() && rentals[part].find(name) != rentals[part].end())
		{
			int rentalDuration = curTime - rentals[part][name].rentalTime;

			if (rentalDuration > duration)
			{
				fineReports[name] += (long long)((rentalDuration - duration) * fine);
			}

			rentals[part].erase(name);

			if (rentals[part].empty())
				rentals.erase(part);
		}
		else
			rentals[part][name] = { name, curTime };
	}


	if (fineReports.empty()) cout << -1;
	else
	{
		for (auto user : fineReports)
			cout << user.first << " " << user.second << '\n';
	}
}