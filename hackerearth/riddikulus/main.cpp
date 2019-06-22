#include <iostream>

using namespace std;
const unsigned long int MAX_SIZE = 100001;
struct circleArray
{
    unsigned long int size;
    unsigned long int *array;
    unsigned long int front, rear;
    unsigned long int numItems;
};
bool isEmpty (circleArray);
void createArray(circleArray&,unsigned long int);
void readArray(circleArray&);
void rotateArray(circleArray&,unsigned long int);
void displayArray(circleArray);
int main()
{
    unsigned long int n;
    cin>>n;
    unsigned long int d;
    cin>>d;
    circleArray myArray;
    createArray(myArray,n);
    readArray(myArray);

    rotateArray(myArray,d);
    displayArray(myArray);
    return 0;
}
void createArray(circleArray& A,unsigned long int n)
{
    if (n < MAX_SIZE)
    {
        A.size = n;
        A.array = new unsigned long int [A.size];
         A.rear = -1;
         A.front =0;
        A.numItems = 0;
    }
}
void readArray(circleArray& A)
{
     int num;
    for (unsigned long int i = 0 ; i < A.size ; i++)
    {
        A.rear = (A.rear + 1) % A.size;
        cin>>num;
        A.array[A.rear] = num;
        A.numItems++;
    }
}
void rotateArray(circleArray& A,unsigned long int d)
{
    if(!isEmpty(A))
    {
        for (unsigned long int i = 0; i < d ; i++)
        {
            A.rear = (A.rear +1)% A.size;
            A.front = (A.front +1)% A.size;
        }
    }

}
void displayArray(circleArray A)
{
    for (unsigned long int i = A.front;  ; i = (i+1) % A.size )
    {
        cout<<A.array[i]<<" ";
        if (i == A.rear) break;
    }
}
bool isEmpty(circleArray A)
{
    return A.numItems  == 0;
}
