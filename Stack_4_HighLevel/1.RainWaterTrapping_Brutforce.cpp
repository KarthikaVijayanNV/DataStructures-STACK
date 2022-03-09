#include<iostream>
using namespace std;

int RainWaterTrapping(int arr[], int n)
{
    int MaxL[n];
    int MaxR[n];
    //  Left maximum of all elements
    MaxL[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        MaxL[i] = max(MaxL[i-1] , arr[i]);
        
    }

    //  right Maximum of all elements
    MaxR[n-1] = arr[n-1];
    for(int i=n-2 ; i>=0; i--)
    {
        MaxR[i] = max(MaxR[i+1] , arr[i]);
    }

    int waterSum = 0;
    for(int i=0; i<n; i++)
    {
        waterSum+= min(MaxL[i] ,MaxR[i]) - arr[i];
    }

    return waterSum;
}





int main()
{

  int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout<<"Rain water accumilated is " <<RainWaterTrapping(arr, 12);

    return 0;
}