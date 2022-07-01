#include<iostream>
using namespace std;
int main()
{
    int x = 10;
    float y =5.5;
    cout<< &x <<endl;
      int *xptr = &x;
      cout<< xptr <<endl;

      //address of a pointer variable
      cout<<&xptr<<endl;

      //pointer to a pointer
      int **xxptr = &xptr;
      cout<<xxptr <<endl;
      return 0;
      

}