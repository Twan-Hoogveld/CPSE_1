#ifndef MY_ARRAY_HPP
#define MY_ARRAY_HPP
#include <iostream>
#include <array>
#include "hwlib.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

template<typename T, int N>
class My_Array{
    
private:
    std::array<T, N> a;
    int Aantal = 0;
    
    
public:

    

    std::array<char, 3> operator<(std::array<char, 3> chars2){
        std::array<char, 3> chars1 = this;
        int tempChars1;
        int tempChars2;
        for(int i = 0; i< Aantal; i++){
            tempChars1 += a[int(i)];
        }
        for(int j = 0; j< chars2.size(); j++){
            tempChars2 += int(chars2[j]);
            
        }
        
        
        return(tempChars1 < tempChars2);
    }
    
    std::array<char, 3> operator>(char char2){
        char char1 = this;
        return(int(char1) > int(char2));
    }   

   int getAantal(){
       return Aantal;
   }
   
   T getArrayIndex(int x){
       if(x < Aantal){
           return a[x];
       }
   }
    
    
    T maxi(){
        T temp = a[0];
        for(int j = 0; j< Aantal;j++){
            if(a[j] > temp){
                temp = a[j];
            }
        }
        return temp;

    }
    
    void add(T x){
        if(Aantal != N && contains(x) != true){
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
    

    
   
    My_Array(){}
   

    
};



    


#endif