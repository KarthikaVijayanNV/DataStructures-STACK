#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void ThreeSumProblem(vector<int> arr, int n , int Target)
{
    sort(arr.begin() , arr.end());
    bool ans =false;

    for(int i=0; i<n; i++)
    {
        int low = i+1;
        int high = n-1;
        while(low<high)
        {
            int current = arr[i] + arr[low] + arr[high];
            if(current == Target)
            {
                ans= true;
            }
            if(current < Target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }

      if(ans)
        {
            cout<<"True: Triplet found"<<endl;
        }
        else 
        {
            cout<<"False: Triplet not found"<<endl;
        }
    
      
}



int main()

{
  int n;
  cin>>n;
  int Target;
  cin>>Target;
  vector<int> arr(n);
  
    for(auto &i : arr)
    {
        cin>>i;
    }
  
  ThreeSumProblem(arr,n,Target);
    return 0;
}