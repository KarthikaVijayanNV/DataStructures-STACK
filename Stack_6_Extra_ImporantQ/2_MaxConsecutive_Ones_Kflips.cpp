#include<iostream>
#include<vector>
using namespace std;

int MaxConsecutiveOnes(int  arr[] , int n, int k)
{
    int MaxConseOne = 0;
    int start = 0;
    int ZeroCnt = 0;

    for(int end =0 ;end<n; end++)
    {
        if(arr[end] == 0)
        {
            ZeroCnt++;
        }
        while(ZeroCnt > k)
        {
            if(arr[start] == 0) // after increasing start if you find start value is zero then...
            {
                ZeroCnt--;   // shrink the window which is already exceeded
            }

            start++;
        }

        MaxConseOne = max (MaxConseOne ,  end - start +1);
    }
   
   //return  the size the longest subarray
   return MaxConseOne;
}


int main()
{

  int arr[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};

  cout<<MaxConsecutiveOnes(arr, 19, 3);

  //  n=10   1,1,0,0,0,1,1,1,1,1                        k= 2   0/p = 7
  //  n= 11  1,1,1,0,0,0,1,1,1,1,0                        k=2    0/p = 6
  //  n= 19  0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1        k=3    0/p = 10

    return 0;
}