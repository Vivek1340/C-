#include<iostream>
using namespace std;

void sort(int c[],int n3)         //Function to sort the elements of the array
{
    for(int i=0;i<n3;i++)         
    {
        int temp;
        for(int j=i+1; j<n3 ;j++)
        {
            if(c[i]>c[j])
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }
}
int main()
{
    
    int n1,n2,n3;                   //Array size declaration
    printf("\nEnter the size of first array ");
    scanf("%d",&n1);
    printf("\nEnter the size of second array ");
    scanf("%d",&n2);
    
    n3=n1+n2;
    printf("\nEnter the array elements");
    int a[n1],b[n2],c[n3];                //Array Declaration
    for(int i=0;i<n1;i++)                 //Array Initialization
    {
       scanf("%d",&a[i]);
    }
    sort(a,n1);                             //Function call to sort the array
    int k=n1;
    printf("\nEnter the array elements");
    for(int i=0;i<n2;i++)                //Array Initialization
    {
        scanf("%d",&b[i]);
    }
    sort(b,n2);                          //Function call to sort the array
   
    for(int i=0;i<n1;i++)             //Merge two arrays
    {
        c[i]=a[i];
    }
    for(int j=0;j<n2;j++)
    {
        c[k]=b[j];
        k++;
    }
    printf("\nAfter sorting...\n");
    sort(c,n3);                               //Function call to sort the array
    for(int i=0 ; i<n3 ; i++)             //Print the resultant sorted array
    {
        printf(" %d ",c[i]);
    }
    return 0;  
}