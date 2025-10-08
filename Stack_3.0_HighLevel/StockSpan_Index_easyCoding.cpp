#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void StockSpan(int arr[] , int n)
{
    stack<int> st;
    vector<int> V;

    for(int i=0; i<n; i++)
    {
        if(st.empty())
        {
            V.push_back(-1);
        }
        else if(!st.empty() && arr[st.top ()] > arr[i])
        {
            V.push_back(st.top());
        }
        else if(!st.empty() &&  arr[st.top()] <= arr[i])
        {
            while(!st.empty() && arr[st.top()] <= arr[i])
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


        st.push(i);
    }


 for(int i=0; i<n; i++)
    {
        V[i]= i-V[i];
    }

    //output
    for(auto i : V)    // &i  alla...verum i mathii
    {
        cout<<i<<" ";
    }
    cout<<endl;

   
}



int main()
{
    int arr[] = {100,80,60,70,60,75,85};
    StockSpan(arr,7);
}