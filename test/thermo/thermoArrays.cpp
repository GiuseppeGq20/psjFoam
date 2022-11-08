
#include <iostream>
#include <fstream>
#include <cmath>

const int N=100;

double T[N];

double getH(double T,double p){
    #include "H.H"
    return H;
}


int main(){

    // initialize temperature array
    double dT= 500.0;
    T[0]=50.0;
    for (int i = 1; i < N; i++) {
        T[i]= T[i-1] + dT;
    }

    //set pressure [Pa]
    const double p=101325.0;


    // create file
    std::ofstream file;

    // create T file
    file.open("Tarray.H",std::ios::out | std::ios::trunc);
    if (file.is_open()) {

        // calc T [K]
        for (int i = 0;  i<N-1 ; i++) {
            
            file<<T[i]<<",\n";
            
        }
        file<<T[N-1]<<std::endl;
        file.close();
    }

    // create H file
    file.open("Harray.H",std::ios::out | std::ios::trunc);
    if (file.is_open()) {

        // calc H [J/Kg]
        for (int i = 0;  i<N-1 ; i++) {
            
            double H=getH(T[i],p);
            file<<H<<",\n";
            
        }
        
        file<<getH(T[N-1],p)<<std::endl;
        file.close();
    }

    std::cout<<"created .H files"<<std::endl;

}
