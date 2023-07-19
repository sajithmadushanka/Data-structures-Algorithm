
#include<iostream>
using namespace std;
class DynamicArray{
    private:
        int value_count;
        int __initial_capacity;
        int capacty;
        int* data;

    public:
         DynamicArray(int __initial_capacity){
          
            data = new int[__initial_capacity];
            value_count = 0;
            capacty = __initial_capacity;
            this->__initial_capacity = __initial_capacity;
           

        }

        void copy(int list_[]){
               for(int i =0; i < value_count; i++){
                    data[i] = list_[i];
               }
        }
        void insert(int value){
            if(value_count  == capacty){
                  
                        int* temp = data;
                        data = new int[capacty *2];
                        capacty *= 2; 
                        copy(temp);
                        delete[] temp;

            }
            data[value_count] = value;
            value_count++;
        }
        void delete_(){
                data[value_count] = 0;
                value_count--;
                if(__initial_capacity == value_count || (capacty/2 == value_count && capacty%2 == 0)){
                    capacty /=2;                
                    
                    int* temp = data;
                    data = new int[capacty];
                    copy(temp);
                    delete[] temp;
                    }

        }
        void print(){
            for(int i = 0; i< value_count; i++){
                    cout<< data[i] << " ";
            }
            cout << endl;
        }
        int get_capacity(){
            return capacty;
        }
         int get_count(){
            return value_count;
        }
          int get_iniatial(){
            return __initial_capacity;
        }

};

int main(){
  DynamicArray d(2);
 
    for(int i =0; i < 8; i++){
        d.insert((i+1) * 10);
    //    cout <<  d.get_count() << " ";
        
    }
    cout << endl;
   
  d.print();
 cout << "capcity: " << d.get_capacity() <<endl;
 
 for(int i = 0; i < 6; i++){
    d.delete_();
 }
  
 d.print();
 cout  << "capcity: " << d.get_capacity() <<endl;


  return 0;
}