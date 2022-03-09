#include<iostream>  // same rain water trapping question using Stack // TC = 0(n)    SC= 0(n)
#include<stack>
using namespace std;

class solution
{
    public:
    int RainwaterTrap(int arr[] , int n)
    {
        stack<int> st;
        int WaterSum =0;

        for(int i=0; i<n; i++)
        {
            while(!st.empty()  &&  arr[st.top()] < arr[i])
            {
                int current = st.top();
                st.pop();

                if(st.empty())
                {
                    break;
                }
                else
                {
                    int width = i-st.top() -1;
                    WaterSum +=  (min( arr[i] , arr[st.top()]) - arr[current]) * width;
                }
            }
            st.push(i);
        }

        return WaterSum;
    }
};


int main()
{
    solution S1;
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<S1.RainwaterTrap(arr,12);
    return 0;
}