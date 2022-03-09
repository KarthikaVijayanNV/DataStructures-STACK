#include <iostream>  // more optimised code..TC = 0(n)   SC = o(1) <--------space optimised
using namespace std;

class solution
{
public:
    int RainWaterTrapping(int arr[], int n)
    {
        int left = 0;
        int right = n - 1;
        int leftmax = 0;
        int rightmax = 0;
        int  WaterSum = 0;

        while(left <= right)
        {
            if(arr[left] <= arr[right])
            {
                if(arr[left] >= leftmax)
                {
                    leftmax = arr[left];
                }
                else
                {
                    WaterSum += leftmax - arr[left];
                }
                left++;
            }
            else
            {
                if(arr[right] >= rightmax)
                {
                    rightmax = arr[right];
                }
                else
                {
                    WaterSum += rightmax - arr[right];
                }
                right--;
            }
        }

        return WaterSum;

    }
};

int main()
{
    solution S1;
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<S1.RainWaterTrapping(arr,12);

    return 0;
}
