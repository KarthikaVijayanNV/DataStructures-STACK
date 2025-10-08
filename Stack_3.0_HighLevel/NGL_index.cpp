#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void NGLindex(int arr[] , int n)
{
    stack<int> st;
    vector<int> V;

    for(int i=0; i<n; i++)
    {
        if(st.empty())
        {
            V.push_back(-1);
        }

        else if(!st.empty() && arr[st.top()] > arr[i]) // only change "arr" here
        {
            V.push_back(st.top());
        }

        else if(!st.empty() && arr[st.top()] <= arr[i]) // "arr" here 
        {
            while(!st.empty() && arr[st.top()] <=  arr[i]) // "arr" here
            {
                st.pop();
            }
            if(st.empty())
            {
                V.push_back(-1);
            }
            else
            {
                V.push_back(st.top());
            }
        }

        st.push(i); // instead of arr[i] ..we are pushing just "i"  the index
    }

    for(auto &i : V)
    {
        cout<<i<<" ";
    }
}




int main()
{
    int arr[] = {1,3,2,4};
    NGLindex(arr,4);  //  -1 -1 1 -1

    return 0;
}