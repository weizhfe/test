#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXSIZE 105
 
using namespace std;
 
int A[MAXSIZE];
int mul[MAXSIZE][MAXSIZE];
int loc[MAXSIZE][MAXSIZE];
 
int main()
{
    int n,t,i,r,k,j;
    cin >> n;
    memset(mul,0,sizeof(mul));
    for(i=0;i<n;i++)
    {
        cin >> A[i];
        cin >> t;
    }
    A[n] = t;
    for(r= 1;r<n;r++)
	{
        for(i =1;i<n;i++)
        {
            j = i + r;
            mul[i][j] = mul[i+1][j]+A[i-1]*A[i]*A[j];
            loc[i][j] = i;
            for(k = i + 1; k < j; k++)
            {
                t = mul[i][k]+mul[k + 1][j] + A[i - 1]*A[k]*A[j];
                if(t < mul[i][j])
                {
                    mul[i][j] = t;
                    loc[i][j] = k;
                }
            }
        }
    }
    cout << mul[1][n] << endl;
    return 0;
}
