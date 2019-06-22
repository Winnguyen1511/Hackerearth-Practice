#include <iostream>
const int MAX_SIZE = 101;
using namespace std;
void merge (int*,int*,int, int , int);
void merge_pass(int*,int*,int,int);
void merge_sort(int*,int);
void PrintArrayClockwise(int *array,int n)
{

}

int main()
{
    int n;
    cin>>n;
    int arr[n*n];
    for (int i = 0; i < n*n ; i++)
        cin>>arr[i];
    merge_sort(arr,n);
    //PrintArrayClockwise(arr,n,n);
    return 0;
}
void merge(int list[], int sorted[], int i, int m, int n)
{
    int j, k, t;
    j = m+1;
    k = i;
    while(i <=m && j <= n)
    {
        if (list[i] <= list[j]) sorted[k++] = list[i++];
        else sorted[k++] = list[j++];
    }
    if(j>m)
        for (t =j; t<=n; t++) sorted[k+t-j] = list[t];
    else
        for(t = i; t<=m; t++) sorted[k+t-i] = list[t];
}
void merge_pass(int list[], int sorted[], int n, int length)
{
    int i,j;
    for (i = 0; i < n - 2*length ; i += 2*length)
        merge(list,sorted, i, i+length-1, i+2*length-1);
    if(i+length <n)
        merge(list,sorted,i,i+length-1,n-1);
    else
        for (j = i; j <n ; j++)
        sorted[j] = list[j];
}
void merge_sort(int list[], int n)
{
    int length = 1;
    int extra[MAX_SIZE];
    while(length<n)
    {
        merge_pass(list,extra,n,length);
        length *= 2;
        merge_pass(extra,list,n,length);
        length *= 2;
    }
}
/*#include <stdio.h>

void PrintArrayClockwise(int *array, int rows, int columns)
{
	int r = 0;
	int rh = rows / 2;
	int i;
	while (r < rh)
	{
		for (i=r; i<(columns - r); i++) printf("%d ",array[(r*columns)+i]);
		printf("\n");
		for (i=rows-r-2; i>r; i--) printf("%d ",array[(i*columns)+r]);

		for (i=r+2; i<=(rows-r); i++) printf("%d ",array[(i*columns)-1-r]);
		//printf("\n");
		for (i=(columns-r-2); i>=r; i--) printf("%d ",array[((rows-r-1)*columns)+i]);
		//printf("\n");

		//printf("\n");
		r++;
	}
}

int main()
{
	int numbs[16];
	int i;
	for (i=0; i<16; i++) numbs[i]=i+1;

	PrintArrayClockwise(numbs, 4, 4);

	return 0;
}
*/
