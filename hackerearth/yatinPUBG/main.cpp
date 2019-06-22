#include <iostream>
#include <cstdlib>
using namespace std;
struct treeNode
{
    int value;
    treeNode *left, *right;
};
void insertNode(treeNode*&,int);
void insert(treeNode*&,treeNode*&);
int findHeight(treeNode*);
int max(int, int);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        treeNode *root= NULL;
        int n;
        cin>>n;
        for(int i = 0; i< n ; i++)
        {
            int num;
            cin>>num;
            insertNode(root,num);
        }
        cout<<findHeight(root)<<endl;
    }
    return 0;
}
void insertNode(treeNode *&root, int num)
{
    treeNode *newNode = NULL;
    newNode = new treeNode;
    newNode->value = num;
    newNode->left = newNode->right = NULL;
    insert(root, newNode);
}
void insert(treeNode*& root, treeNode *&newNode)
{
    if (!root)
        root = newNode;
    else if (newNode->value < root->value)
        insert(root->left, newNode);
    else
        insert(root->right,newNode);
}
int findHeight(treeNode* root)
{
    if (!root) return 0;
    else
    {
        if (!root->left&&!root->right) return 1;
        else
            return max(1+findHeight(root->left), 1+findHeight(root->right));
    }

}
int max(int a, int b)
{
    if (a > b) return a;
    return b;
}
