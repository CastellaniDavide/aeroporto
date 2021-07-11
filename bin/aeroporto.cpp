#include <bits/stdc++.h>
using namespace std;

void pianifica(int R, int A[], int B[], int T[])
{
    // Trova il massimo tempo
    long long int maxT = INT_MIN;
    for (size_t i = 0; i < R; ++i)
        if (B[i] > maxT)
            maxT = B[i];

    // Trova k;
    long long int minT = 0;

    while (minT + 1 < maxT)
    {
        long long int K = (maxT + minT) / 2;
        bool ok = true;

        long long int parti = 0;
        for (size_t i = 0; i < R; ++i)
        {
            if (parti < A[i])
            {
                parti = A[i] + K;
            }
            else if (parti <= B[i])
            {
                parti += K;
            }
            else
            {
                ok = false;
                break;
            }
        }
        
        if (ok)
            minT = K;
        else
            maxT = K;
    }
    long long int K = minT;

    // Soluzione
    int parti = 0;
    for (size_t i = 0; i < R; ++i) {
        if (parti < A[i]) {
            T[i] = A[i];
            parti = A[i] + K;
        } else {
            T[i] = parti;
            parti += K;
        }
    }
}
