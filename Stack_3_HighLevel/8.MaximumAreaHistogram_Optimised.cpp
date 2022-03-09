#include<iostream>   // more optimised code approach .....simple line easy coding
#include<stack>      
using namespace std;

class solution
{
    public:
    int  MaxAreaOfHistogram(int arr[] , int  n)
    {
        stack<int> st;
        int  MaxArea =0;
        
        for(int i=0; i<=n; i++)
        {
            while(!st.empty()  &&   (i==n  || arr[st.top()] >= arr[i]) )
            {
                int height =   arr[st.top()];
                st.pop();
                int width;
                if(st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - st.top() -1;
                }

                MaxArea = max(MaxArea , height * width);
            }
            st.push(i);
        }
        return MaxArea;
    }
};



int main()

{

   solution S1;
   int arr[] = {6,2,5,4,5,1,6}; 
   cout<<S1.MaxAreaOfHistogram(arr, 7);

    return 0;
}