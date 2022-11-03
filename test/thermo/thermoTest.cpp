#include <iostream>
#include <fstream>
#include <cmath>

const int N=50;

double T[N], p[N];

double getCp(double T,double p){

    #include "cp.H"
    return Cp;
}

double getH(double T,double p){
    #include "H.H"
    return H;
}

double getS(double T,double p){
    #include "S.H"
    return S;
}

double getSigma(double T,double p){
    #include "sigma.H"
    return Sigma;
}

double getMu(double T,double p){
    #include "mu.H"
    return mu;
}

double getKappa(double T,double p){
    #include "kappa.H"
    return kappa;
}

int main(){

    // initialize temperature array
    double dT= 1000.0;
    T[0]=50.0;
    for (int i = 1; i < N; i++) {
        T[i]= T[i-1] + dT;
    }
    // create file
    std::ofstream file;


    file.open("cp.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc cp [cal/g/K]
        file<<"# " <<"T cp [cal/g/K] p=0.1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double cp=getCp(T[i],1013.25);
            cp=cp/1000.0/4.18;
            file<<cp<<" "<<T[i]<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }

    // create H file
    file.open("H.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc cp [cal/g/K]
        file<<"# " <<"T H [cal/g] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double H=getH(T[i],101325.0);
            H=H/1000.0/4.18;
        file<<T[i]<<" "<<H<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }

    // create S file
    file.open("S.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc S [cal/g/K]
        file<<"# " <<"T S [cal/g/K] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double S=getS(T[i],101325.0);
            S=S/1000.0/4.18;
            file<<T[i]<<" "<<S<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }
    
    // create Sigma file
    file.open("Sigma.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc sigma [S/m]
        file<<"# " <<"T Sigma [S/m] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double Sigma=getSigma(T[i],101325.0);
            file<<T[i]<<" "<<Sigma<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }

    // create mu file
    file.open("mu.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc mu [Kg/m/s]
        file<<"# " <<"T mu [Kg/m/s] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double mu=getMu(T[i],101325.0);
            file<<T[i]<<" "<<mu<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }    

    // create kappa file
    file.open("kappa.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc kappa [W/K/m]
        file<<"# " <<"T kappa [W/K/m] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double kappa=getKappa(T[i],101325.0);
            file<<T[i]<<" "<<kappa<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    } 

    return 0;
}

