//#include<stdio.h>
//
//int main()
//{
//   int len1, len2, arr1[789], arr2[987];
//   int sameIdx[789], sameCnt = 0;   // ��ġ�� arr1�� index�� �־��ִ� �迭
//
//   scanf("%d %d", &len1, &len2);
//
//   for (int i = 0; i < len1; i++) scanf("%d", &arr1[i]);
//   for (int i = 0; i < len2; i++) scanf("%d", &arr2[i]);
//
//   // ��ġ�� �� ã�Ƽ� �־��ֱ�
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
//   // ��������
//   for (int i = 0; i < sameCnt - 1; i++)
//   {
//      for (int j = 0; j < sameCnt - i - 1; j++)
//      {
//         int idx1 = sameIdx[j], idx2 = sameIdx[j + 1];
//
//         // idx1(����)�� �� �۰� ������ֱ�
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