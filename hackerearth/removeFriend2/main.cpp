#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int i =0 ; i< T; i++)
    {
        int n,k;
        cin>>n>>k;
        vector<int> mylist;
        for (int i = 0; i< n; i++)
        {
            int num;
            cin>>num;
            mylist.push_back(num);
        }
        int mark = 1;
       while(k--){

            if (mylist[0] < mylist[1]) mylist.erase(mylist.begin());
            else
            {
                bool deletefriend = 0;
                for ( int j = mark; j < mylist.size()-1; j++,mark++)
                {
                    if (mylist[j] < mylist[j+1])
                    {
                        mylist.erase(mylist.begin()+j);
                        deletefriend = 1;
                        //cout<<"Mark in: "<<mark<<endl;
                        break;

                    }
                }
                 if (deletefriend == 0)
                 {
                    //while(k--)
                    for (int  i = 0; i<= k ; i++)
                        mylist.pop_back();
                    break;
                 }
                 //mylist.pop_back();
                 if(mark != 0)
                    mark--;
                 //cout<<"Mark out: "<<mark<<endl;
                 //cout<<"k = "<<k<<endl;
            }
        }

        for (int i = 0 ; i < mylist.size(); i++)
            cout<<mylist[i]<<" ";
        cout<<endl;
    }
    return 0;
}
