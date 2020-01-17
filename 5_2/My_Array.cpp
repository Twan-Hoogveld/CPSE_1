/*#include <iostream>
#include <array>
#include "My_Array.hpp"
#include "hwlib.hpp"
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"

    template<typename T, int N>
    void My_Array<T, N>::add(int x){
        if(Aantal != N && contains(x) != true){
            a[Aantal] = x;
            Aantal++;
        }else{
            hwlib::cout<<"Dikke pech, lege plekken zijn weg" << "\n";
        }
    }
    template<typename T, int N>
    void My_Array<T, N>::remove(int x){
        if(contains(x) == true){
            for( int i = 0; i < Aantal; i++){
                if(a[i] == x){
                    for(int temp = i; temp < Aantal ; temp++){
                        a[temp] = a[temp+1];
                    }
                    Aantal--;
                    break;
                }
            }
        }
        
    }
    template<typename T, int N>
    bool My_Array<T, N>::contains(int x){
        for(  int i : a){
            if(i == x){
                return true;
            }
        }
        return false;
        
        
    }
    
    
    TEST_CASE("You can add till full", "[add]"){
        My_Array array1;
        for(int i = 0; i<15 ; i++){
            array1.add(i);
        }
        REQUIRE( array1.Aantal == 10);
    }
    
    TEST_CASE("You can only uniques", "[add]"){
        My_Array array1;
        for(int i = 0; i<3 ; i++){
            array1.add(3);
        }
        REQUIRE( array1.Aantal == 1);
    }
    
    TEST_CASE("You can remove elements", "[remove]"){
        My_Array array1;
        for(int i = 0; i<8 ; i++){
            array1.add(i);
        }
        array1.remove(3);
        REQUIRE( array1.contains(3) == false);
    }*/