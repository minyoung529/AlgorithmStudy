//#include<iostream>
//#include<vector>
//using namespace std;
//
//int sutoku[9][9];
//int horizontal[9];
//int vertical[9];
//int check[9];
//
//int main()
//{
//	for (int i = 0; i < 9; i++)
//	{
//		string s;
//		cin >> s;
//
//		for (int j = 0; j < 9; j++)
//		{
//			sutoku[i][j] = s[j] - '0';
//
//			horizontal[i] |= (1 << sutoku[i][j]);
//			vertical[j] |= (1 << sutoku[i][j]);
//			check[i / 3 * 3 + j / 3] |= (1 << sutoku[i][j]);
//		}
//	}
//
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			if (sutoku[i][j] != 0)continue;
//
//			int area = i / 3 * 3 + j / 3;
//			int idx = -1;
//
//			for (int k = 1; k <= 9; k++)
//			{
//				if ((check[area] & (1 << k)) != 0) continue;
//
//				if (((vertical[j] & (1 << k)) == 0) &&
//					((horizontal[i] & (1 << k)) == 0))
//				{
//					vertical[j] |= (1 << k);
//					horizontal[i] |= (1 << k);
//					check[area] |= (1 << k);
//
//					sutoku[i][j] = k;
//					break;
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//			cout << sutoku[i][j];
//		cout << '\n';
//	}
//}
