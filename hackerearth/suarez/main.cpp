#include <bits/stdc++.h>
using namespace std;
struct treeNode
{
    int value;
    treeNode *left, *right;
};
treeNode* newNode(int);
treeNode* insertNode(int*,treeNode*,int,int);
void inorder(treeNode*,int*, int,int);
//void addnode(treeNode*&, treeNode*&);
int minSwaps(int*, int);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    treeNode *root = NULL;
    root = insertNode(arr,root,0,n);
    int inorderArray[n];
    inorder(root,inorderArray,0,n);
    int tmp = sizeof(inorderArray)/ sizeof(int);
    cout<<minSwaps(inorderArray,tmp);
    return 0;
}
int minSwaps(int arr[], int n)
{
    // Create an array of pairs where first
    // element is array element and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    // Sort the array by array element values to
    // get right position of every element as second
    // element of pair.
    sort(arrPos, arrPos + n);

    // To keep track of visited elements. Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);

    // Initialize result
    int ans = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;

        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }

        // Update answer by adding current cycle.
        if(cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }

    // Return result
    return ans;
}

treeNode* insertNode(int arr[], treeNode* root, int i, int n)
{
    if (i < n)
    {
        treeNode *tmp = newNode(arr[i]);
        root = tmp;
        root->left = insertNode(arr,root->left,2*i+1,n);
        root->right = insertNode(arr,root->right, 2*i + 2,n);
    }
    return root;
}
treeNode* newNode(int num)
{
    treeNode* tmp = NULL;
    tmp = new treeNode;
    tmp->value = num;
    tmp->left = tmp->right = NULL;
    return tmp;
}
void inorder(treeNode *root,int arr[], int i, int n )
{
    stack <treeNode*> s;
    treeNode *temp = root;
    for(;temp||!s.empty();)
    {
        for(;temp; temp = temp ->left)
            s.push(temp);
        temp  = s.top();
        s.pop();
        arr[i++] = temp->value;
        temp = temp->right;
    }
}

