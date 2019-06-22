#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i = 0; i <n ; i++)
    {
        cin>>A[i];
    }
    int X[n], Y[n];
    vector <int> vecX;
    vector <int> vecY;
    vecX.push_back(A[0]);
    X[0]= -1;
    int sameX = 0;
    for (int i = 1; i < n ; i++)
    {
        int count=0;
        //int same = 0;
        flag:
        if(!vecX.empty())
        {
            if(A[i] == vecX[vecX.size()-1]) sameX++;
            else {
            sameX = 0;
            if(A[i] > vecX[vecX.size()-1])
            {
                vecX.pop_back();
                count++;
                goto flag;
            }
            else vecX.push_back(A[i]);}
        }
        else vecX.push_back(A[i]);
        //X[i] = i - count;
        if (vecX.size() > 1)
            X[i] = i - count - sameX;
        else
            X[i] = - 1;
    }
    vecY.push_back(A[n-1]);

    Y[0] = -1;
    int same = 0;
    for (int i = n-2; i >= 0 ; i--)
    {
        //cout<<"A["<<i<<"] = "<<A[i]<<endl;
        int count = 0;

        flag1:
        if(!vecY.empty())
        {
            if(A[i] == vecY[vecY.size()-1])
            {
                same++;
            }
            else{
            same = 0;
            if(A[i]> vecY[vecY.size()-1])
            {
                vecY.pop_back();
                count++;
                goto flag1;
            }
            else vecY.push_back(A[i]);}
        }
        else
        {
            vecY.push_back(A[i]);
        }
        if (vecY.size() > 1)
            Y[n-i-1] = i + count + same + 2;
        else
            Y[n-i-1] = - 1;
    }
    for (int i = 0; i < n ; i++)
    {
        //cout<<X[i] + Y[n-i-1]<<" ";
        //cout<<Y[n-i-1]<<" ";
        cout<<X[i]<<" ";
    }
    return 0;
}
