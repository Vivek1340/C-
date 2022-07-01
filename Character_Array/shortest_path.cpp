#include<iostream>
using namespace std;
int main(){
    char route[1000];
    cout<<"Enter the route in following format e.g SNNNEWE "<<endl;
    cin.getline(route,1000);

    int x = 0;
    int y = 0;

    for(int i=0; route[i]!='\0';i++){

        switch(route[i]){
            case 'N' : y++;
                        break;

            case 'S' : y--;
                        break;

            case 'E' : x++;
                        break;

            case 'W' : x--;
                        break;
        }
    }
    cout<<"final x and y is : "<<x <<","<<y<<endl;
    if(x>=0 and y>=0){
        while(y--){
            cout<<"N";
        }
        while(x--){
            cout<<"E";
        }
    }
    else if(x<0 and y>=0){
        int z= -x;
        while((z)--){
           cout<<"W" ;
        }
        while(y--){
            cout<<"N";
        }
    }
    else if(x<0 and y<0){
        int a = -x;
        int b = -y;
        while(a--){
            cout<<"W";
        }
        while(b--){
            cout<<"S";
        }
    }
    else if(x>=0 and y<0){
        int a = -y;
        while(x--){
            cout<<"E";
        }
        while(a--){
            cout<<"S";
        }
    }
    return 0;
}