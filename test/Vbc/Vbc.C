#include "scalar.H"
#include <iostream>
#include <fstream>   

using namespace Foam;

scalar getVBot(const scalar t)
{

    scalar field=0.0;

    const scalar       p1 =  -7.084e+32;  
    const scalar       p2 =   3.017e+27;  
    const scalar       p3 =  -3.076e+21;  
    const scalar       p4 =   -9.95e+14;  
    const scalar       p5 =   2.317e+08;  
    const scalar       p6 =       986.6;  

    const scalar        pp1 =   8.706e+07;        
    const scalar        pp2 =  -505.2;               



    const scalar     a0 =   8.934e+04  ;
    const scalar      a1 =  -1.073e+05 ;
    const scalar      b1 =   1.239e+05 ;
    const scalar      a2 =  -1.809e+04 ;
    const scalar      b2 =  -1.259e+05 ;
    const scalar      a3 =   6.752e+04 ;
    const scalar      b3 =   4.214e+04 ;
    const scalar      a4 =  -3.728e+04 ;
    const scalar      b4 =    1.25e+04 ;
    const scalar      a5 =        4817 ;
    const scalar      b5 =  -1.332e+04 ;
    const scalar      a6 =        1536;
    const scalar      b6 =        2404;
    const scalar      w =   2.344e+07 ;

    //const scalar a= 1.7355e+08;
    //const scalar b=-867.7419;
    /*if (t<1e-7) {
        field =Foam::sin(t*1e7*3.14/2)*((p1*Foam::pow(t,5) + p2*Foam::pow(t,4) + p3*Foam::pow(t,3) + p4*Foam::pow(t,2) + p5*t + p6)/2);
    }
    else if (t>=1e-7 && t < 1.766e-06)*/
    if ( t < 1.766e-06)
    {
        field = (p1*Foam::pow(t,5) + p2*Foam::pow(t,4) + p3*Foam::pow(t,3) + p4*Foam::pow(t,2) + p5*t + p6)/2; 
    }else if ( t>=1.766e-06 && t<=1.9e-6)   
    {
        field = (a0 + a1*Foam::cos(t*w) + b1*Foam::sin(t*w) 
                + a2*Foam::cos(2*t*w) + b2*Foam::sin(2*t*w) + a3*Foam::cos(3*t*w) + b3*Foam::sin(3*t*w) 
                + a4*Foam::cos(4*t*w) + b4*Foam::sin(4*t*w) + a5*Foam::cos(5*t*w) + b5*Foam::sin(5*t*w) 
                + a6*Foam::cos(6*t*w) + b6*Foam::sin(6*t*w))/2 ; 
    }else if ( t>=1.9e-06 && t <=2.9e-6 )   
	{
        field =  (pp1*t + pp2)/2 ; 
    }else if ( t > 2.9e-06)
    {
        field = scalar (1e-15); 
    }

    return field;
}

scalar getVTop(const scalar t)
{
    scalar field=0.0;
    const scalar p1=1.649e+21;  
    const scalar p2=-4.444e+15;  
    const scalar p3=1.473e+09;     
    const scalar p4=799.3;

    const scalar        pp1 =   8.706e+07;        
    const scalar        pp2 =  -505.2;      

     const scalar     a0 =   8.934e+04  ;
     const scalar      a1 =  -1.073e+05 ;
     const scalar      b1 =   1.239e+05 ;
     const scalar      a2 =  -1.809e+04 ;
     const scalar      b2 =  -1.259e+05 ;
     const scalar      a3 =   6.752e+04 ;
     const scalar      b3 =   4.214e+04 ;
     const scalar      a4 =  -3.728e+04 ;
     const scalar      b4 =    1.25e+04 ;
     const scalar      a5 =        4817 ;
     const scalar      b5 =  -1.332e+04 ;
     const scalar      a6 =        1536;
     const scalar      b6 =        2404;
     const scalar      w =   2.344e+07 ;

    //const scalar a= 1.7355e+08;
    //const scalar b=-867.7419;

    if ( t < 1.766e-06)
    {
        field = -(p1*Foam::pow(t,3) + p2*Foam::pow(t,2) + p3*t + p4)/2; 
    
    }else if ( t>=1.766e-06 && t<=1.9e-6) 
    {                
        field = -(a0 + a1*Foam::cos(t*w) + b1*Foam::sin(t*w) 
                + a2*Foam::cos(2*t*w) + b2*Foam::sin(2*t*w) + a3*Foam::cos(3*t*w) + b3*Foam::sin(3*t*w) 
                + a4*Foam::cos(4*t*w) + b4*Foam::sin(4*t*w) + a5*Foam::cos(5*t*w) + b5*Foam::sin(5*t*w) 
                + a6*Foam::cos(6*t*w) + b6*Foam::sin(6*t*w))/2; 		
    }else if ( t>=1.9e-06 && t <=2.9e-6 )               
    {    
        field =  -(pp1*t + pp2)/2 ; 
            
    }else if ( t > 2.9e-06)
    {
        field = scalar (1e-15); 
    }
    
    return field;
}


int main()
{
    
    const scalar dt=0.2e-7;
    scalar t=0.0;
    const scalar N = floor(3e-6/dt);

    std::ofstream file;
    
    //create data file
    file.open("VBot.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()){
        
        file<<"# t[s] V[Volt]"<<std::endl;
        for (int i=0;i<N;i++)
        {   
            file<<t<<" "<<getVBot(t)<<"\n";
            t+=dt;
        }
        file<<std::endl;
    }
    file.close();

    t=0.0; //reinitialize t
    file.open("VTop.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()){
        
        file<<"# t[s] V[Volt]"<<std::endl;
        for (int i=0;i<N;i++)
        {   
            file<<t<<" "<<getVTop(t)<<"\n";
            t+=dt;
        }
        file<<std::endl;
    }
    file.close();

    t=0.0; //reinitialize t
    file.open("Vsum.dat",std::ios::out | std::ios::trunc);

    if (file.is_open()){
        
        file<<"# t[s] V[Volt]"<<std::endl;
        for (int i=0;i<N;i++)
        {   
            file<<t<<" "<<getVTop(t)+getVBot(t)<<"\n";
            t+=dt;
        }
        file<<std::endl;
    }
    file.close();
    return 0;
}
