//#include<stdio.h>
//
//int main()
//{
//   int len1, len2, arr1[789], arr2[987];
//   int sameIdx[789], sameCnt = 0;   // 겹치는 arr1의 index만 넣어주는 배열
//
//   scanf("%d %d", &len1, &len2);
//
//   for (int i = 0; i < len1; i++) scanf("%d", &arr1[i]);
//   for (int i = 0; i < len2; i++) scanf("%d", &arr2[i]);
//
//   // 겹치는 수 찾아서 넣어주기
//   for (int i = 0; i < len1; i++)
//   {
//      for (int j = 0; j < len2; j++)
//      {
//         if (arr1[i] == arr2[j])
//         {
//            sameIdx[sameCnt++] = i;
//            break;
//         }
//      }
//   }
//
//   // 버블정렬
//   for (int i = 0; i < sameCnt - 1; i++)
//   {
//      for (int j = 0; j < sameCnt - i - 1; j++)
//      {
//         int idx1 = sameIdx[j], idx2 = sameIdx[j + 1];
//
//         // idx1(왼쪽)가 더 작게 만들어주기
//         if (arr1[idx1] > arr1[idx2])
//         {
//            int temp = arr1[idx1];
//            arr1[idx1] = arr1[idx2];
//            arr1[idx2] = temp;
//         }
//      }
//   }
//
//   for (int i = 0; i < len1; i++)
//   {
//      printf("%d ", arr1[i]);
//   }
//}