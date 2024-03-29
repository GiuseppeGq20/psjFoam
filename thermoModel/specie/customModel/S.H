//Specific entropy [cal/(g K)]
// il codice vuole p in atm e T in K
    const scalar patm=p/101325.0;
	const int n=4;  //numero elementi di x



	//Coef Tab 25
	const scalar x[n]={Foam::pow(Foam::log(patm),0), Foam::pow(Foam::log(patm),1), Foam::pow(Foam::log(patm),2), Foam::pow(Foam::log(patm),3)};


	const scalar phi_a0[n]=		{7.247773e-1, -5.579293e-2, 1.246960e-3, 0};	
	const scalar phi_log_w0[n]=		{-1.949369, 4.114017e-2, -1.494867e-4,0};	


	const scalar sigma1_a1[n]=		{2.181324e-1, -2.219875e-2, -3.107110e-4, 0};	
	const scalar sigma1_log_c1[n]=		{8.148014, 5.310698e-2, 1.031964e-3,0};	
	const scalar sigma1_log_delta1[n]= {6.487571, 1.023051e-1, 2.174761e-3,0};
	
	const scalar sigma2_a2[n]=		{9.599015e-1, -5.505086e-2, 1.666018e-5,0};	
	const scalar sigma2_log_c2[n]=		{8.839993, 5.776858e-2, 1.370456e-3,0};
	const scalar sigma2_log_delta2[n]= {7.037019, 1.068246e-1, 2.382441e-3,0};

	const scalar sigma3_log_a3[n]=		{6.970847e-1, -6.594736e-2, -2.375941e-3, -6.719048e-5};	
	const scalar sigma3_log_c3[n]=				{9.574258, 6.744128e-2, 1.024908e-3, -4.207616e-5};	
	const scalar sigma3_log_delta3[n]= 		{8.030117, 1.278105e-1, 2.875819e-3, 5.995551e-5};
		
		
	const scalar sigma4_log_a4[n]=				{7.418974e-1, -6.340965e-2, -1.805794e-3, -5.053043e-5};	
	const scalar sigma4_log_c4[n]=				{1.029506e+1, 6.492224e-2, 1.056643e-3, -1.643501e-5};	
	const scalar sigma4_log_delta4[n]= 		{8.459989, 1.137276e-1, 3.515754e-3,0};
	
		
	const scalar sigma5_log_a5[n]=				{7.657208e-1, -5.775822e-2, -7.902876e-4,0};	
	const scalar sigma5_log_c5[n]=				{1.073845e+1, 6.189030e-2, 1.130363e-3,0};	
	const scalar sigma5_log_delta5[n]= 		{8.822908, 1.163591e-1, 3.457547e-3,0};	
	
	
	
	const scalar sigma6_a6[n]=				{2.767445, -1.126949e-1, 2.483520e-3,0};	
	const scalar sigma6_log_c6[n]=				{1.108196e+1, 6.043375e-2, 1.256963e-3,0};	
	const scalar sigma6_log_delta6[n]= 		{9.251052, 1.085228e-1, 1.802991e-3,0};	
	
	
	const scalar sigma7_log_a7[n]=				{ 1.503593, 6.710278e-2, 1.417762e-3,0};	
	const scalar sigma7_log_c7[n]=				{1.188475e+1, 8.409849e-2, 1.321048e-3,0};	
	const scalar sigma7_log_delta7[n]= 		{1.082135e+1, 1.048287e-1, -5.310563e-3,0};

	//Calcolo coef

    //c0 c1
	scalar a_0=0.0, w_0=0.0;
	
	for(int i=0; i<n; i++)
	{ 
	    a_0+= phi_a0[i]*x[i];
	    w_0+= phi_log_w0[i]*x[i];
	    
	}
    w_0=Foam::exp(w_0);
    
	//a1,c1,delta1
	scalar a_1=0, c_1=0, delta_1=0;
	for(int i=0; i<n; i++)
	{
	    a_1+=    sigma1_a1[i]*x[i];
	    c_1+=    sigma1_log_c1[i]*x[i];
	    delta_1+=sigma1_log_delta1[i]*x[i];
	}
    c_1=Foam::exp(c_1);
	delta_1=Foam::exp(delta_1);

	//a2,c2,delta2
	scalar a_2=0, c_2=0, delta_2=0;	
	for(int i=0; i<n; i++)
	{
	    a_2+=    sigma2_a2[i]*x[i];
	    c_2+=    sigma2_log_c2[i]*x[i];
	    delta_2+=sigma2_log_delta2[i]*x[i];
	}
    c_2=Foam::exp(c_2);
	delta_2=Foam::exp(delta_2);
	
	//a3,c3,delta3
	scalar a_3=0, c_3=0, delta_3=0;	
	for(int i=0; i<n; i++)
	{
	    a_3+=    sigma3_log_a3[i]*x[i];
	    c_3+=    sigma3_log_c3[i]*x[i];
	    delta_3+=sigma3_log_delta3[i]*x[i];
	}
    a_3=Foam::exp(a_3);
    c_3=Foam::exp(c_3);
	delta_3=Foam::exp(delta_3);

	//a4,c4,delta4
	scalar a_4=0, c_4=0, delta_4=0;
	for(int i=0; i<n; i++)
	{
	    a_4+=    sigma4_log_a4[i]*x[i];
	    c_4+=    sigma4_log_c4[i]*x[i];
	    delta_4+=sigma4_log_delta4[i]*x[i];
	}
    a_4=Foam::exp(a_4);
    c_4=Foam::exp(c_4);
	delta_4=Foam::exp(delta_4);
	
	//a5,c5,delta5
	scalar a_5=0, c_5=0, delta_5=0;	
	for(int i=0; i<n; i++)
	{
	    a_5+=    sigma5_log_a5[i]*x[i];
	    c_5+=    sigma5_log_c5[i]*x[i];
	    delta_5+=sigma5_log_delta5[i]*x[i];
	}
    a_5=Foam::exp(a_5);
    c_5=Foam::exp(c_5);
	delta_5=Foam::exp(delta_5);
		
	//a6,c6,delta6
	scalar a_6=0, c_6=0, delta_6=0;
	for(int i=0; i<n; i++)
	{
	    a_6+=    sigma6_a6[i]*x[i];
	    c_6+=    sigma6_log_c6[i]*x[i];
	    delta_6+=sigma6_log_delta6[i]*x[i];
	}
    c_6=Foam::exp(c_6);
	delta_6=Foam::exp(delta_6);
	
	//a7,c7,delta7
	scalar a_7=0, c_7=0, delta_7=0;
	for(int i=0; i<n; i++)
	{
	    a_7+=    sigma7_log_a7[i]*x[i];
	    c_7+=    sigma7_log_c7[i]*x[i];
	    delta_7+=sigma7_log_delta7[i]*x[i];
	}
    a_7=Foam::exp(a_7);
    c_7=Foam::exp(c_7);
	delta_7=Foam::exp(delta_7);
	
	//Definizioni q
	const scalar q1=(T-c_1)/delta_1;
	const scalar q2=(T-c_2)/delta_2;
	const scalar q3=(T-c_3)/delta_3;
	const scalar q4=(T-c_4)/delta_4;
	const scalar q5=(T-c_5)/delta_5;
	const scalar q6=(T-c_6)/delta_6;
	const scalar q7=(T-c_7)/delta_7;

	const scalar q[7]={q1,q2,q3,q4,q5,q6,q7};
    
	//Definizione sigma
	scalar sigma[7]; 
    //const scalar maxValue=-100.0; // for q<-2.5 the sigmoid is less than 7e-3
    for (int j=0; j<7; j++)
	{   
        /*if (2*q[j]< maxValue ) {
            sigma[j]=0.0; 
        }else{
	    	sigma[j]=1.0/(1.0+Foam::exp(-2*q[j]));
	    }*/
        if (q[j]>= 0){
            sigma[j]=1.0/(1.0+Foam::exp(-2*q[j]));
        }else{
            sigma[j]=Foam::exp(2*q[j])/(1+ Foam::exp(2*q[j]));
        }
    }
	
	const scalar phi0=a_0*Foam::pow(T,w_0); 
	
	//Definizione a
	scalar a[7]={a_1,a_2,a_3,a_4,a_5,a_6,a_7};

	//CALCOLO S
	scalar z=0.0; 
	for (int i=0; i<7; i++)
	{
		z=z+a[i]*sigma[i];
	}
	scalar S=z+phi0;	
	S=S*4.1867999409*1000; // conversion from cal/g*K to J/Kg*K
                           
