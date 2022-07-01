#include <iostream>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
    int i=0,j=0,l;
    string temp,b,c;
    vector<string>::iterator it;
    vector<string>a ({"anikesh","animesh","anitesh","anihesh","anilesh"});
    for(i=0;i<a.size();i++)
        {
          
                 if(strcmp(a[i].c_str(),a[i+1].c_str()) == 0)
                    {
                        temp=a[i];

                    }
                 else
                    break;

               }
        }
    cout<<temp;
    return 0;
}
