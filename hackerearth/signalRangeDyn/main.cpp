#include <iostream>
#include <cstdlib>
using namespace std;
const unsigned int MAX_TIMES = 11;
const unsigned long int MAX_SIZE = 1000001;
struct stackNode
{
    unsigned long int value;
    stackNode *next;
};
//stackNode *top;
stackNode* createStack();
bool isEmpty(stackNode*);
bool isFull(stackNode*);
void push(stackNode*&,unsigned long int);
unsigned long int pop(stackNode*&);
unsigned long int countStack(stackNode*);
void coppyStack(stackNode*&, stackNode*);
void insertLast(stackNode*&,unsigned long int);
void findLess (stackNode* &,unsigned long int *,unsigned long int);
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

            for(unsigned long int j = 0; j < size ; j++)
            {
                stackNode *s = createStack();
                unsigned long int count=0;
                findLess(s,list,j);
                count = countStack(s);
                span[j] = count+1;
                delete s;
            }
            for(unsigned long int i = 0; i < size ; i++)
                cout<<span[i]<<" ";
            cout<<endl;
            }

        }
    }
    return 0;
}
stackNode* createStack()
{
    stackNode *tmp;
    tmp = NULL;
    return tmp;
}
bool isEmpty(stackNode* s)
{
    return !s;
}
bool isFull(stackNode*)
{

}
void push(stackNode*& s,unsigned long int num)
{
    stackNode *newNode = NULL;
    newNode = new stackNode;
    newNode ->value = num;
    newNode->next = NULL;
    if (isEmpty(s))
    {
        s = newNode;
    }
    else
    {
        newNode->next = s;
        s = newNode;
    }
}
unsigned long int pop(stackNode*& s)
{
    stackNode *nodeptr= NULL;
    if (!isEmpty(s))
    {
        unsigned long int num = s->value;
        nodeptr = s->next;
        delete s;
        s = nodeptr;
    }
}
void coppyStack(stackNode*& s1, stackNode* that)
{
    stackNode *nodeptr;
    if (isEmpty(that))
    {
        s1 = NULL;
    }
    else
    {
        nodeptr = that;
        while(nodeptr)
        {
          insertLast(s1,nodeptr->value);
          nodeptr = nodeptr->next;
        }
    }

}
void insertLast(stackNode*& s,unsigned long int num)
{
    stackNode *newNode;
    stackNode *nodeptr;
    newNode = new  stackNode;
    newNode->value = num;
    newNode->next =NULL;
    if (isEmpty(s))
    {
        s = newNode;
    }
    else
    {
        nodeptr = s;
        while(nodeptr->next)
        {
            nodeptr = nodeptr->next;
        }
        nodeptr->next = newNode;
    }
}
void findLess (stackNode* & s,unsigned long int list[], unsigned long int j)
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
unsigned long int countStack(stackNode*s)
{
    stackNode *nodeptr;
    nodeptr = s;
    if (!s) return 0;
    else
    {
        int count = 0;
        while (nodeptr)
        {
            nodeptr = nodeptr->next;
            count ++;
        }
        return count;
    }
}
