#include <iostream>
#include <array>
#include "hwlib.hpp"
#include "My_Array.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


    TEST_CASE("You can get the maximum of std::array<chars, 3>", "[maxi]"){
        My_Array<std::array<char, 3>, 3> array1;
        std::array<char, 3>array2{('a' + 1),('b' +1),('c' +1)};
        std::array<char, 3>array3{('a' + 2),('b' +2),('c' +2)};
        std::array<char, 3>array4{('a' + 3),('b' +3),('c' +3)};
        array1.add(array2);
        array1.add(array3);
        array1.add(array4);
        REQUIRE( array1.maxi() == array4);
    }



    
    TEST_CASE("You can get the maximum of ints", "[maxi]"){
        My_Array<int, 18> array2;
        for(unsigned int i = 0; i<=15 ; i++){
            array2.add(i);
        }
        REQUIRE( array2.maxi() == 15);
    }
    
    TEST_CASE("You can get the maximum of doubles", "[maxi]"){
        My_Array<double, 20> array1;
        for(double i = 0.0; i<=19.0 ; i++){
            array1.add(i);
        }
        REQUIRE( array1.maxi() == 19.0);
    }


    TEST_CASE("You can add till full", "[add]"){
        My_Array<int, 10> array1;
        for(int i = 0; i<15 ; i++){
            array1.add(i);
        }
        REQUIRE( array1.getAantal() == 10);
    }
    
    TEST_CASE("You can only uniques", "[add]"){
        My_Array<int, 18> array1;
        for(int i = 0; i<3 ; i++){
            array1.add(3);
        }
        REQUIRE( array1.getAantal() == 1);
    }
    
    TEST_CASE("You can remove elements", "[remove]"){
        My_Array<int, 18> array1;
        for(int i = 0; i<8 ; i++){
            array1.add(i);
        }
        array1.remove(3);
        REQUIRE( array1.contains(3) == false);
    }


/*
int man(int argc, char * argv[]){
    
    
    My_Array<int, 18> a1;
    My_Array<double, 20> b1;
    
    for(unsigned int i = 0; i < 10; i++){
        a1.add(i);
    }
    for(unsigned int i = 0; i < 10; i++){
        hwlib::cout<<a1.a[i] << "\n";
    }
    hwlib::cout<<a1.max();
    
    
    //hwlib::cout<<a.contains(2) << " " << a.contains(3);
    

    return 0;


}
*/