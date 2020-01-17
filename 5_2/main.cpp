#include <iostream>
#include <array>
#include "hwlib.hpp"
#include "My_Array.hpp"

int main(){
    
    
    My_Array<int, 18> a1;
    My_Array<double, 20> b1;
    
    for(unsigned int i = 0; i < 10; i++){
        a1.add(i);
    }
    a1.remove(2);
    hwlib::cout<<a1.contains(2) << " : ";
    for(int i = 0; i < 8; i++){
            hwlib::cout<< a1.a[i]<< " "; ;
    }
    hwlib::cout<<"\n";
    for(double i = 0.0; i < 10.0; i++){
        b1.add(i);
    }
    b1.remove(5.0);
    hwlib::cout<< b1.contains(3.0) << " : ";
    for(int i = 0; i < 8; i++){
            std::cout<< b1.a[i]<< " ";; 
    }
    
    
    //hwlib::cout<<a.contains(2) << " " << a.contains(3);
    



	return 0;
}
