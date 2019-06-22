#include <iostream>
#include <stack>
using namespace std;
const unsigned int MAX_TIMES = 11;
const unsigned long int MAX_SIZE = 1000001;
void findLess (std::stack<unsigned long int> &,unsigned long int *,unsigned long int);
int main()
{
    int times;
    cin>>times;
    if (times< MAX_TIMES)
    {
        for(int i = 0; i<times ; i++)
        {
            unsigned long int size ;
            cin>>size;
            if(size<MAX_SIZE)
            {
            unsigned long int *span = new unsigned long int[size] ;
            unsigned long int *list = new unsigned long int[size] ;
            span[0] = 1;
            unsigned long int tmp;
            for(unsigned long int i = 0; i < size; i++)
            {
                cin>>tmp;
                list[i] = tmp;
            }

            for(unsigned long int j = 0; j < size ; j++)
            {
                std::stack<unsigned long int> s ;
                s.push(0);

                unsigned long int count=0;
                findLess(s,list,j);
                count = s.size();
                span[j] = count+1;

            }
            for(unsigned long int i = 0; i < size ; i++)
                cout<<span[i]<<" ";
            cout<<endl;
            }

        }
    }
    return 0;
}
void findLess (std::stack<unsigned long int> &s,unsigned long int list[], unsigned long int j)
{
    while (!s.empty())
    {
        s.pop();
    }
    if(j != 0)
    {
        unsigned long int max = list[j];
        for (unsigned long int i = j-1; i>= 0; i--)
        {
            if (list[i] <= max ) s.push(list[i]);
            else break;
        }
    }
    else return;
}
