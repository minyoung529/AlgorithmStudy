//#include<iostream>
//#include<algorithm>
//#include<map>
//#include<set>
//using namespace std;
//
//struct problem
//{
//	int difficulty;
//	int number;
//	int group;
//
//	bool operator < (const problem& p) const
//	{
//		if (p.difficulty == difficulty)
//			return  (p.number > number);
//
//		return (p.difficulty > difficulty);
//	}
//	bool operator > (const problem& p) const
//	{
//		if (p.difficulty == difficulty)
//			return  (p.number < number);
//
//		return (p.difficulty < difficulty);
//	}
//};
//
//set<problem> problems;
//set<problem, greater<problem>> rProblems;
//
//map<int, set<problem>> groupMap;
//map<int, set<problem, greater<problem>>> rGroupMap;
//
//map<int, problem> problemMap;
//
//void insert(int num)
//{
//	int difficulty, group;
//	cin >> difficulty >> group;
//
//	problem p = { difficulty, num, group };
//
//	problems.insert(p);
//	rProblems.insert(p);
//
//	groupMap[group].insert(p);
//	rGroupMap[group].insert(p);
//
//	problemMap.insert({ num, p });
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
//
//	int orderCount;
//	int num, difficulty, group;
//
//	cin >> orderCount;
//
//	for (int i = 0; i < orderCount; i++)
//	{
//		cin >> num;
//		insert(num);
//	}
//
//	cin >> orderCount;
//
//	for (int i = 0; i < orderCount; i++)
//	{
//		string order;
//		cin >> order >> num;
//
//		if (order == "add")
//		{
//			insert(num);
//		}
//
//		// 그룹 중 어렵거나 쉬운, 문제 번호
//		// num == group
//		else if (order == "recommend")
//		{
//			cin >> difficulty;
//
//			if (difficulty == 1)
//				cout << (*rGroupMap[num].begin()).number << '\n';
//
//			else
//				cout << (*--rGroupMap[num].end()).number << '\n';
//		}
//
//		// 어렵거나 쉬운, 문제 번호
//		else if (order == "recommend2")
//		{
//			if (num == 1)
//				cout << (*--problems.end()).number << '\n';
//
//			else
//				cout << (*problems.begin()).number << '\n';
//		}
//
//		// 난이도가 크거나 같은, 작거나 같은, 문제 번호
//		else if (order == "recommend3")
//		{
//			cin >> difficulty;
//			set<problem>::iterator iter;
//
//			if (num == 1)
//			{
//				iter = find_if(problems.begin(), problems.end(), [difficulty](problem p) {return p.difficulty >= difficulty; });
//
//				if (iter != problems.end())
//				{
//					cout << (*iter).number << '\n';
//					continue;
//				}
//			}
//			else
//			{
//				iter = find_if(rProblems.begin(), rProblems.end(), [difficulty](problem p) {return p.difficulty <= difficulty; });
//
//				if (iter != rProblems.end())
//				{
//					cout << (*iter).number << '\n';
//					continue;
//				}
//			}
//
//			cout << -1;
//		}
//
//		else
//		{
//			problems.erase(problemMap[num]);
//			rProblems.erase(problemMap[num]);
//
//			groupMap[problemMap[num].group].erase(problemMap[num]);
//			rGroupMap[problemMap[num].group].erase(problemMap[num]);
//		}
//	}
//}