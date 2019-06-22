#include <iostream>
#include <vector>
using namespace std;
struct element
{
    long int dis;
    long int value;
};
int main()
{
    long int n;
    cin>>n;
    element A[n];
    for(long int i = 0; i <n ; i++)
    {
        long int num;
        cin>>num;
        A[i].dis = i+1;
        A[i].value = num;
    }
    long int X[n], Y[n];
    vector <element> vecX;
    vector <element> vecY;
    vecX.push_back(A[0]);
    X[0]= -1;
    for (long int i = 1; i < n ; i++)
    {
        flag:
        if(!vecX.empty())
        {
            if( A[i].value >= vecX[vecX.size()-1].value)
            {
                vecX.pop_back();
                goto flag;
            }
            else //if (A[i].value < vecX[vecX.size()-1].value)
            {
                X[i] = vecX[vecX.size()-1].dis ;
                vecX.push_back(A[i]);
            }
        }
        else
        {
            X[i] = -1;
            vecX.push_back(A[i]);
        }
            //vecX.push_back(A[i]);
    }
    vecY.push_back(A[n-1]);

    Y[0] = -1;

    for (long int i = n-2; i >= 0 ; i--)
    {
        flag1:
        if(!vecY.empty())
        {
            if(A[i].value >= vecY[vecY.size()-1].value )
            {
                vecY.pop_back();
                goto flag1;
            }
            else
            {
                Y[n-i-1] = vecY[vecY.size()-1].dis;
                vecY.push_back(A[i]);
            }
        }
        else
        {
            Y[n-i-1] = -1;
            vecY.push_back(A[i]);
        }


    }
    for (long int i = 0; i < n ; i++)
    {
        cout<<X[i] + Y[n-i-1]<<" ";
        //cout<<Y[n-i-1]<<" ";
        //cout<<X[i]<<" ";
    }
    return 0;
}
