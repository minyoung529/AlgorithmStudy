#include <iostream>
using namespace std;

int arr[50];

int main()
{
    int len, res = 0, sum = 0;
    cin >> len;

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    while (sum)
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i] % 2 == 1) 
            {
                // 홀수인 수 1 빼기
                --arr[i];
                --sum;
                ++res;
            }
        }

        if (sum != 0)
        {
            for (int i = 0; i < len; i++)
            {
                // 모든 수 2로 나누기
                sum -= arr[i] / 2;
                arr[i] /= 2;
            }

            res++;
        }
    }

    cout << res;
}