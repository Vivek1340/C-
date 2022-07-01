#include<iostream>
#include<cstring>
using namespace std;

//Product (Shopping Cart)
class Product{
    int id;
    char *name;
    int mrp;
    int selling_price;
    public:
    //constructor
    Product(){
        cout<<"inside constructor";
    }
    Product(int id,char *n,int mrp,int selling_price){

        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;
        name = new char[strlen(n)+1];
        strcpy(name , n);
    }
    Product(Product &x){
        id = x.id;
        name = new char[strlen(x.name)+1];
        strcpy(name,x.name);
        mrp = x.mrp;
        selling_price = x.selling_price;

    }
    //copy assignment operator working
    void operator=(Product &x){
//Deep copy inside copy assignment operator
            id = x.id;
        name = new char[strlen(x.name)+1];
        strcpy(name,x.name);
        mrp = x.mrp;
        selling_price = x.selling_price;
    }
    //setters
    void setMrp(int price){
        if(price>0){
        mrp = price;
        }
    }
    void setSellingprice(int price){
         if(price>mrp){
            selling_price = mrp;
        }
        else {
            selling_price = price;
        }
    }
    void setName(char *name){
        strcpy(this->name,name);
    }

    //getters
    int getMrp(){
        return mrp;
    }
    int getSellingprice(){
        return selling_price;
    }

    void showDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"Id : "<<id<<endl;
        cout<<"Seling Price : " <<selling_price<<endl;
        cout<<"Mrp : "<<mrp<<endl;
        cout<<"--------------------"<<endl;
    }
    ~Product(){
        cout<<"Deeting "<<name<<endl;
        if(name != NULL){
            delete[] name;
            name = NULL;
        }
    }
};

int main(){
    // Product camera(101 , "GoProHero9" , 28000 , 26000);
//     Product webcam(camera);
//     webcam.setName("GoPro8");
//    webcam.setSellingprice(1000);
   

//     camera.showDetails();
//     webcam.showDetails();
//    
   // handycam.showDetails();

    //cout<<"MRP is : "<<camera.getMrp()<<endl;
    //cout<<"Selling Price is : "<<camera.getSellingprice()<<endl;
    //----------------------------------------
    // Copy assignment oprator      creates shalow copy

    Product camera(101 , "GoProHero9" , 28000 , 26000);//calls parametric constructor

    Product old_camera;//calls first constructor

    old_camera = camera;
    old_camera.setName("GoPro8 old");
    camera.showDetails();
    old_camera.showDetails();



    return 0;
}