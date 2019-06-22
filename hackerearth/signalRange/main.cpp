#include <iostream>

using namespace std;
const unsigned int MAX_TIMES = 11;
const unsigned long int MAX_SIZE = 1000001;
struct stack{
    unsigned long int SIZE;
    unsigned long int *array;
    unsigned long int top ;
};
stack createStack(unsigned long int);
bool stack_isEmpty(stack);
bool stack_isFull(stack);
void push(stack&, unsigned long int);
unsigned long int pop (stack&);
unsigned long int countStack(stack);
void coppyStack(stack&,stack);
void findLess (stack &,unsigned long int *,unsigned long int);
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
                unsigned long int *span = new unsigned long int[size];
            unsigned long int *list = new unsigned long int[size];
            unsigned long int tmp;
            for(unsigned long int i = 0; i < size; i++)
            {
                cin>>tmp;
                list[i] = tmp;
            }
            stack s = createStack(size);
            for(unsigned long int j = 0; j < size ; j++)
            {
                unsigned long int count=0;
                findLess(s,list,j);
                count = countStack(s);
                span[j] = count+1;
                s = createStack(size);
            }
            for(unsigned long int i = 0; i < size ; i++)
                cout<<span[i]<<" ";
            cout<<endl;
            }

        }
    }
    return 0;
}
stack createStack(unsigned long int size)
{
    stack temp;
    temp.SIZE =size;
    temp.array = new unsigned long int[temp.SIZE];
    temp.top = -1;
    return temp;
}
bool stack_isEmpty(stack s)
{
    return (s.top == -1);
}
bool stack_isFull(stack s)
{
    return (s.top == s.SIZE -1);
}
void push(stack &s,unsigned long int value)
{
    if (!stack_isFull(s)) s.array[++s.top] = value;
}
unsigned long int pop(stack &s)
{
    if (!stack_isEmpty(s)) return s.array[s.top--];
}
unsigned long int countStack(stack s)
{
    return s.top+1;
}
void coppyStack(stack& s, stack that)
{
    for (unsigned long int i = 0; i <= that.top ; i++)
    {
        s.array[i] = that.array[i]  ;
    }
    s.top = that.top;
}
void findLess (stack & s,unsigned long int list[], unsigned long int j)
{
    if(j != 0)
    {
         unsigned long int max = list[j];
        for (unsigned long int i = j-1; i>= 0; i--)
        {
            if (list[i] <= max ) push(s, list[i]);
            else break;
        }
    }
    else return;
}
