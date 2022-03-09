#include<iostream>  // longest substring without repeating characters
#include<vector>
using namespace std;

int longestSubstring(string  S)
{
    vector<int> IndexArr(256, -1);
    int start = -1;     // start will be the start index of the substring
    int Maxlength =0;

    for(int i=0; i<S.size(); i++)
    {
        if(IndexArr[S[i]] > start)
        {
            start = IndexArr[S[i]] ;
        }
        IndexArr[S[i]] = i;

        Maxlength = max(Maxlength  ,   i - start);

    }

    return Maxlength;
}




int main()
{

   string S;   // pwwkew
   cin>>S;
   cout<<longestSubstring(S);   // 0/p = 3

    return 0;
}