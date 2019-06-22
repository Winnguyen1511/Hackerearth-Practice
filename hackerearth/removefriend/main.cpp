#include <iostream>
#include <cstdlib>
using namespace std;
struct list
{
    int popular;
    list *next;
};

void insertNode(list*&,int);
void deleteFriend(list*&);
void deleteNode(list*&,list*&);
void deleteLast(list*&);
void printList(list*&);
int main()
{
    int T;
    cin>>T;
    for (int i = 0 ; i< T ; i++)
    {
        list *myList = NULL;
        int n, k;
        cin>>n>>k;
        for (int i = 0; i< n; i++)
        {
            int num;
            cin>>num;
            insertNode(myList,num);
        }
        list *nodeptr=myList;
        for (int i = 0; i< k; i++)
        {
            deleteNode(myList,nodeptr);
        }
        printList(myList);
        cout<<endl;
    }
    return 0;
}
void insertNode(list*& listnode,int num)
{
    list *newNode;
    list *nodeptr;
    newNode = new list;
    newNode->popular = num;
    newNode->next = NULL;
    if (!listnode)
        listnode = newNode;
    else
    {
        nodeptr = listnode;
        while(nodeptr->next)
            nodeptr = nodeptr->next;
        nodeptr->next = newNode;
    }
}
void deleteFriend(list *& listnode)
{

}
void deleteNode(list*& listnode,list *&nodeptr)
{
    /*list *nodeptr=NULL, *previousNode=NULL;
    if(!listnode)
        return;
    if (!listnode->next)
    {
        nodeptr = listnode->next;
        delete listnode;
        listnode = nodeptr;
    }
    if (listnode->popular < listnode->next->popular)
    {
        nodeptr = listnode;
        listnode = listnode ->next;
        delete nodeptr;
    }
    else
    {
        nodeptr = listnode;
        while (nodeptr)
        {
            if (nodeptr->popular < nodeptr->next->popular) break;
            previousNode = nodeptr;
            nodeptr = nodeptr->next;
        }
        if (nodeptr)
        {
            previousNode->next = nodeptr->next;
            delete nodeptr;
            nodeptr = previousNode;
        }
        else
            deleteLast(listnode);
    }*/
    list  *previousNode;
    if (!listnode) return;
    if (!listnode->next)
    {
        delete listnode;
        listnode = NULL;
        nodeptr = listnode;
    }
    if (listnode->popular < listnode->next->popular)
    {
        //nodeptr = listnode;
        listnode = listnode ->next;
        delete nodeptr;
        nodeptr = listnode;
    }
    else
    {
        while (nodeptr)
        {
            if (nodeptr->popular < nodeptr->next->popular) break;
            previousNode = nodeptr;
            nodeptr = nodeptr->next;
        }
        if (nodeptr)
        {
            previousNode->next = nodeptr->next;
            delete nodeptr;
            nodeptr = previousNode;
        }
        else
        {
            previousNode = NULL;
            delete previousNode;
        }
            //eleteLast(listnode);
    }
}
/*void deleteLast(list*& listnode)
{
    list *nodeptr;
    nodeptr = listnode;
    if (!listnode)
        return;
    else
    {
        while(nodeptr->next->next)
            nodeptr = nodeptr->next;
        delete nodeptr->next;
        nodeptr->next = NULL;
    }

}*/
void printList(list*& listnode)
{
    list* nodeptr;
    nodeptr = listnode;
    while(nodeptr)
    {
        cout<<nodeptr->popular<<" ";
        nodeptr = nodeptr->next;
    }
}
