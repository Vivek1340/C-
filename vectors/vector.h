//generalizing our header file using templates

template<typename T>
class Vector{
    //Data Members
    T *arr;
    T cs;        //current size
    T ms;         //maximum size


    //Constructor ,Destructor,METHODS
public:
    Vector(T max_size = 5){
        cs = 0;
        ms = max_size;
        arr = new T[ms];
    }

    // d does not changes inside the function
    void push_back(const T d){
        //two case
        if(cs == ms){
            //create a new array and delete the old one , double the capacity
            T *oldArr = arr;
            ms = 2* ms;
            arr = new T [ms];

            //copy the element
            for(int i=0;i<cs;i++){
                arr[i] = oldArr[i];
            }

            //delete
            delete[] oldArr;
        }

        arr[cs] = d;
        cs++;
    }

    void pop_back(){
        if(cs>=0){
        cs--;
        }
    }

    bool isEmpty()const{
        return cs==0;
    }

    //front, back, at [i],][]
    T front()const{
        return arr[0];
    }

    T back()const{
        return arr[cs-1];
    }
// const function are those which do not modify the data members


    T at(int i) const{
        return arr[i];
    }

    int size() const{
    return cs;
    }

    int capacity()const{
        return ms;
    }
// [] whenever this opertor is used by the obbject it will return arr of i
// since i is not changing inside the function (i.e i++ or i--)  we should use const
    T operator[](const int i) const {
        return arr[i];
    }

};