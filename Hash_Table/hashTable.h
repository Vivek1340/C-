#include<iostream>
#include<string>

using namespace std;

template <typename T>
class Node{
public:
    string key;
    T value;
    Node* next;

    Node(string key , T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};
template <typename T>
class Hashtable{

    Node<T> **table;
    int cs; //total enteries that have been inserted'
    int ts; //size of the table

    int hashFn(string key){
        int idx =0;
        int power = 1;
        for(auto ch :key){
            idx = (idx + ch *power)%ts;
            power =(power*29)%ts;

        }
        return idx;
    }

    void rehash(){
        //save the ptr to the oldTable and we will do insertion in the new table
        Node<T> **oldTable = table;
        int oldTs = ts;
        //increase the table size
        cs=0;
        ts = 2*ts+1;   // ideally it should be prime
        table = new Node<T>*[ts];  

        for(int i=0; i<ts;i++){
            table[i] = NULL;
        }
        //Copy elements from old table to new table
        for(int i=0;i<oldTs; i++){
            Node<T> *temp = oldTable[i];

            while(temp != NULL){
                string key = temp->key;
                T value = temp->value;
                //happen in the new table
                insert(key,value);
                temp = temp->next;
            }
            //destroy the its linked list
            if(oldTable[i] !=NULL){
                delete oldTable[i];
            }
        }
        delete [] oldTable;
    }

public:
Hashtable(int default_size = 7){

    cs= 0;
    ts = default_size;
    table = new Node<T> *[ts];


    for(int i=0; i<ts ;i++){
        table[i] = NULL;
    }
}

void insert(string key , T val){
    //next

    int idx = hashFn(key);

    Node<T> *n = new Node<T>(key,val);
    //insertion at head of the linkedlist (O(1))
    n->next = table[idx];
    table[idx] = n;
    cs++;

    float load_factor = cs/float(ts);
    if(load_factor > 0.7){
        rehash();
    }
}
bool isPresent(string key){
    int idx = hashFn(key);
    Node<T> *temp = table[idx];
    while(temp!=NULL){
        if(temp->key == key){
            return true;
        }
        else{
            return false;
        }
    }
}


T search1(string key){
    int idx= hashFn(key);
    if(isPresent(key)){
        Node<T> *temp = table[idx];
        while(temp != NULL){
            if(temp->key == key){
                return temp->value;
            }
        }
    }
}
//Another SEarch Technique

T* search(string key){
    int idx = hashFn(key);

    Node<T> *temp = table[idx];

    while(temp!=NULL){
        if(temp->key == key){
            return &temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

void erase(string key){

    int idx = hashFn(key);
    Node<T> *temp = table[idx];

    while(temp!=NULL){
        if(temp->key == key){
            cout<<endl;
            cout<<temp->key<<" deleted with price " << temp->value <<endl;
            table[idx] = table[idx]->next;
            temp->next = NULL;
            delete temp;
        }
        temp = temp->next;
    }
    print();

}
T& operator[](string key){
        
        T* valueFound = search(key);
        if(valueFound==NULL){
            T object;
            insert(key,object);
            valueFound = search(key);       
        }
        return *valueFound;
    }


void print(){
    //iterate over buckets
    for(int i =0;i<ts;i++){
        cout<<"Bucket "<<i<<"->";

        Node<T> *temp = table[i];
        while(temp!=NULL){
            cout<<temp->key <<"->";
            temp = temp->next;

        }

        cout<<endl;
    }
}

};