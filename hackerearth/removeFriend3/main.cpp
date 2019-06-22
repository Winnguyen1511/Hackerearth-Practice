#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n, k;
        cin>>n>>k;
        vector <int> myList;
        while (n--)
        {
            int num;
            //flag2:
            cin>>num;
            flag:
            if (myList.empty())
                myList.push_back(num);
            else
            {
                if (k!=0)
            {

                if(myList[myList.size()-1] < num)
                {
                    myList.pop_back();
                    k--;
                    //myList.push_back(num);
                    goto flag;
                }
                else myList.push_back(num);
            }
            else
            {
                myList.push_back(num);
            }
            }

        }
        for (int i = 0; i < k ;i++)
            myList.pop_back();
        for (int i = 0; i< myList.size(); i++)
        {
            cout<<myList[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
