#include <iostream>
#include <fstream>
#include <cmath>


const int N=100;
const double R= 8314.0; //[J/Kmol/K]

double T[N];

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

double getRho(double T, double p){
    #include "MM.H"
    return p*MM/R/T;
}

double getE(double T, double p){
    return getH(T,p) - p/getRho(T,p);

}

int main(){

    // initialize temperature array
    double dT= 500.0;
    T[0]=50.0;
    for (int i = 1; i < N; i++) {
        T[i]= T[i-1] + dT;
    }

    //set pressure [Pa]
    const double p=1e5;    
    // create file
    std::ofstream file;

    //create data file
    file.open("data.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc each thermo quantity
        file<<"# note: cp is at 0.01 atm while all the other quantities are at 1 atm"<<std::endl;

        file<<"# " <<"T cp[cal/g/K] H[cal/g] E[cal/g] S[cal/g/K] rho[Kg/m^3]" 
            <<" sigma[S/m] mu[Kg/m/s] kapp[W/m/K]"<< std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double cp=getCp(T[i],p/100.0)/1000.0/4.18; 
            double H=getH(T[i],p)/1000.0/4.18;
            double E=getE(T[i],p)/1000.0/4.18;
            double S=getS(T[i],p)/1000.0/4.18;
            double Sigma=getSigma(T[i],p);
            double mu=getMu(T[i],p);
            double kappa=getKappa(T[i],p);
            double rho=getRho(T[i],p);

            file<<T[i]
                <<" "<<cp
                <<" "<<H
                <<" "<<E
                <<" "<<S
                <<" "<<rho
                <<" "<<Sigma
                <<" "<<mu
                <<" "<<kappa
                <<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }


    file.open("cp.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc cp [cal/g/K]
        file<<"# " <<"T cp [cal/g/K] p=0.1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double cp=getCp(T[i],p/100.0);
            cp=cp/1000.0/4.18;
            file<<T[i]<<" "<<cp<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }
    
    //create H file
    file.open("H.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc H [cal/g]
        file<<"# " <<"T H [cal/g] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double H=getH(T[i],p);
            H=H/1000.0/4.18;
            file<<T[i]<<" "<<H<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }

    // create e % H-cp*T file
    file.open("hMCpT.dat",std::ios::out | std::ios::trunc);

    std::cout<<"H [cal/g] at T=300 K, p=1 atm\n"
             <<getH(300.0,p)/1000.0/4.18<<std::endl;

    if (file.is_open()) {

        // calc
        file<<"# " <<"T e% (H-cp*T)/H  at p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double H=getH(T[i],p);
            double cp=getCp(T[i],p);
        file<<T[i]<<" "<<100.0*(H-cp*T[i])/H<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }

    // create S file
    file.open("S.dat",std::ios::out | std::ios::trunc);

    std::cout<<"Delta S [J/kg/K] from T=298 K to T=500K, p=1 atm\n"
             <<getS(500.0,p) - getS(298.0,p)<<std::endl;
    
    if (file.is_open()) {

        // calc S [cal/g/K]
        file<<"# " <<"T S [cal/g/K] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double S=getS(T[i],p);
            S=S/1000.0/4.18;
            file<<T[i]<<" "<<S<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }
    
    // create Sigma file
    file.open("Sigma.dat",std::ios::out | std::ios::trunc);
    std::cout<<"sigma [S/m] at T=300 K, p=1 atm\n"
             <<getSigma(300.0,p)<<std::endl;
    if (file.is_open()) {

        // calc sigma [S/m]
        file<<"# " <<"T Sigma [S/m] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double Sigma=getSigma(T[i],p);
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
            
            double mu=getMu(T[i],p);
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
            
            double kappa=getKappa(T[i],p);
            file<<T[i]<<" "<<kappa<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }

    //calculate rho
    std::cout<<"rho [Kg/m^3] at T= 300K, P =1atm \n"
             <<getRho(300.0,p)<<std::endl;

    file.open("Rho.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc Rho [Kg/m^3]
        file<<"# " <<"T Rho [Kg/m^3] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double Rho=getRho(T[i],p);
            file<<T[i]<<" "<<Rho<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }

    //calculate E
    file.open("E.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()) {

        // calc E [J/Kg]
        file<<"# " <<"T Rho [J/Kg] p=1 atm" << std::endl;
        for (int i = 0;  i<N ; i++) {
            
            double E=getE(T[i],p);
            file<<T[i]<<" "<<E/1000/4.18<<"\n";
            
        }
        
        file<<std::endl;
        file.close();
    }



    return 0;
}

