#include<iostream>  // Nearest greater to Right /// or - Nearest largest element
#include<vector>
#include<algorithm> 
#include<stack>
using namespace std;

void NearestGreaterToRight(int arr[] , int n)
{
    vector<int> V;
    stack<int> st;

    for(int i = n-1; i>=0; i--)
    {
        if(st.empty())
        {
            V.push_back(-1);
        }
        else if(!st.empty()  && st.top()> arr[i])
        {
            V.push_back(st.top());
        }
        else if(!st.empty() && st.top() <= arr[i])
        {
            while(!st.empty() && st.top() <= arr[i])
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


        st.push(arr[i]);
    }

    //Reversing the vector
    reverse(V.begin(),V.end());

     //o/p
    for(auto i : V)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}



int main()
{
   int arr[] = {1,3,0,0,1,2,4};
   NearestGreaterToRight(arr,7);  //o/p =  3,4,1,1,2,4,-1


    return 0;
}