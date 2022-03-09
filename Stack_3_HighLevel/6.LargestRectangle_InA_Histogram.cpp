#include<iostream>    // Largest Rectangle In a histogram... area of largest  rectangle in a histogram
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void LargestAreaHistogrm(int arr[], int n)
{
  // NSL  code

  vector<int> left;
  int pseudoIndex1 = -1;

  stack <pair<int,int>> st1;

   for(int i=0; i<n; i++)
   {
       if(st1.empty())
       {
           left.push_back(pseudoIndex1);
       }
       else if(!st1.empty()  && st1.top().first < arr[i])
       {
           left.push_back(st1.top().second);
       }
       else if(!st1.empty() && st1.top().first >= arr[i])
       {
           while(!st1.empty() && st1.top().first >= arr[i])
           {
               st1.pop();
           }
           if(st1.empty())
           {
               left.push_back(-1);
           }
           else
           {
               left.push_back(st1.top().second);
           }
       }

       st1.push({arr[i], i});  // in stack pushing both element and it's index
   }


   // NSR code

   vector<int> right;
  int pseudoIndex2 = n;

  stack <pair<int,int>> st2;

   for(int i=n-1; i>=0; i--)
   {
       if(st2.empty())
       {
           right.push_back(pseudoIndex2);
       }
       else if(!st2.empty()  && st2.top().first < arr[i])
       {
           right.push_back(st2.top().second);
       }
       else if(!st2.empty() && st2.top().first >= arr[i])
       {
           while(!st2.empty() && st2.top().first >= arr[i])
           {
               st2.pop();
           }
           if(st2.empty())
           {
               right.push_back(-1);
           }
           else
           {
               right.push_back(st2.top().second);
           }
       }

       st2.push({arr[i], i});  // in stack pushing both element and it's index
   }

    reverse(right.begin(), right.end());


    // Output   ........width array is not made separately........
                        // width is finding within the loop

    int MaxArea=0;
    for(int i=0; i<n; i++)
    {
        MaxArea = max( MaxArea, arr[i] * (right[i] - left[i] -1) );
    }

    cout<<"Area: "<<MaxArea<<endl;
}



int main()
{

    int arr[] = {2,1,5,6,2,3};
    LargestAreaHistogrm(arr, 6);   // answere getting correctly

    return 0;
}