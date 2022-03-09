#include<iostream>  // maximum area of rectangle with minimum number of code
#include<stack>    // same logic as that of previous one
#include<algorithm>
#include<vector>
using namespace std;

class solution
{
    public:
    int LargestRectangleArea(int arr[], int n)
    {
        vector<int> left;
        vector<int> right;
        stack<int> st;    //NSL

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i] )
            {
                st.pop();
            }
            if(st.empty())
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(st.top());
            }

            st.push(i);
        }

        // emptying stack for reuse
        while(!st.empty())
        {
            st.pop();
        }

        // NSR
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty()  && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                right.push_back(n);  // n is my pseudo index
            }
            else
            {
                right.push_back(st.top());
            }

            st.push(i);
        }
        // reversed... hence it is Right to left traversal....need to reverse the ans
        reverse(right.begin() , right.end());


        //Calculate the max area in the rectangle
        int MaxArea =0;
        for(int i=0; i<n; i++)
        {
            MaxArea = max(MaxArea , arr[i] * (right[i] - left[i] - 1));
        }
        
        return MaxArea;
    }
};

int main()
{
   solution s1;
   int arr[] = {6,2,5,4,5,1,6};
   cout<<s1.LargestRectangleArea(arr,7);


    return 0;
}