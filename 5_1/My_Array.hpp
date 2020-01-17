#ifndef MY_ARRAY_HPP
#define MY_ARRAY_HPP
#include <iostream>
#include <array>


class My_Array{
    
private:
    std::array<int, 10> a;
    
    
public:
    int Aantal = 0;
    void add(int x);
    void remove(int x);
    bool contains(int x);
   

   

    
};


#endif