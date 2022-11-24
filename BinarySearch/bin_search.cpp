//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v{ 3,2,8,5,100,1,8,3 };
//
//	sort(v.begin(), v.end());
//
//	int left = 0, right = v.size() - 1;
//	int target = 5;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//
//		if (v[mid] > target)
//		{
//			right = mid - 1;
//		}
//		else if (v[mid] < target)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			cout << "찾았다!";
//			return 0;
//		}
//	}
//
//	cout << "못찾앗다~~";
//}