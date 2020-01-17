#ifndef MY_ARRAY_HPP
#define MY_ARRAY_HPP
#include <iostream>
#include <array>

template<typename T, int N>
class My_Array{
    
private:
   
    
    
public:
    std::array<T, N> a;
    int Aantal = 0;
    
    
    void add(T x){
        if(Aantal != N ){//&& contains(x) != true){
            a[Aantal] = x;
            Aantal++;
        }else{
            hwlib::cout<<"Dikke pech, lege plekken zijn weg" << "\n";
        }
    }

    void remove(T x){
        
        if(contains(x) == true){
            for( int i = 0; i < Aantal; i++){
                if(a[i] == x){
                    Aantal--;
                    for(int temp = i; temp < Aantal ; temp++){
                        a[temp] = a[temp+1];
                    }
                    a[Aantal] = 0;
                    
                    break;
                }
            }
        }
        
    }
  
    bool contains(T x){
        for(   T i : a){
            if(i == x){
                return true;
            }
        }
        return false;
        
        
    }
   
    My_Array(){
        a.fill(T(0));
    }
   

    
};


#endif