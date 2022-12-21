#include <iostream>
#include <fstream>
#include "scalar.H"
#include "IOstreams.H"

using namespace Foam;

const scalar T= 300;
const scalar rho = 1.2;
const scalar R= 8314.0;

scalar getMM(scalar p)
{
    #include "MM.H"
    return MM;
}

scalar F(scalar p)
{
   return p - rho*R*T/getMM(p); 
}

scalar bisect(scalar p1,scalar p2)
{
    if (F(p1)*F(p2)<0)
    {
        scalar Temp= (p1+p2)/2;
        scalar tol=1e-7;
        int it=0;

        while((Foam::mag(F(Temp))>tol) && it<10000)
        {
            if (F(p1)*F(Temp)<0)
            {
                p2=Temp;
            }else {
                p1=Temp;
            }
            Temp=(p1+p2)/2;
            it++;
        }

        return Temp;
    }else {
        return -1;
    }

}

int main()
{
    scalar p =  bisect(1e3,1e8);
    
    //raise error
    if (p == -1){
        return 1;
    }

    Info<<"p: "<<p<<endl;
    return 0;
}
