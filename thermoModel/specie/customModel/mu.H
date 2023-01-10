//Dynamic Viscosity [kg/(ms)]
// il codice vuole p in atm e T in K
    const scalar patm=p/101325.0;
	const int n=6;  //numero elementi di x

	//Coef Tab 25
	const scalar x[n]={Foam::pow(Foam::log(patm),0), Foam::pow(Foam::log(patm),1), Foam::pow(Foam::log(patm),2), Foam::pow(Foam::log(patm),3), Foam::pow(Foam::log(patm),4), Foam::pow(Foam::log(patm),5)};
	
    //directly final coefficient for eps0
	const scalar  a_0 =-2.490318e-3;
	const scalar  c_0=1.138022e-5;
	const scalar  delta_0=2.525477e+2;
	const scalar  w_0=1;

	const scalar a_1= 2.658346e-3;	
	const scalar c_1= -1.158238e+4;	
	const scalar delta_1= 8.370196e+3;
	
	const scalar sigma2_log_a2[n]=		{-9.146259, 9.214388e-2, -7.532526e-3,0,0, 0};	
	const scalar sigma2_log_c2[n]=		{8.758933, 5.609203e-2, 7.113878e-4,0,0, 0};	
	const scalar sigma2_log_delta2[n]= {7.621521, 6.802267e-2, -4.173943e-3,0,0, 0};

	const scalar sigma3_log_a3[n]=		{-1.077843e+1, 8.010183e-2, 5.530383e-3,0,0,0};	
	const scalar sigma3_log_c3[n]=				{8.183393, 5.531418e-2, 1.161696e-3,0,0 ,0};	
	const scalar sigma3_log_delta3[n]= 		{6.544301, 1.395158e-1, 1.269937e-3,0,0, 0};
		
	const scalar sigma4_log_a4[n]=				{-9.136467, 4.321416e-2, -1.415683e-2, -9.589284e-4, 2.418933e-4, 5.834458e-6};	
	const scalar sigma4_log_c4[n]=				{9.196899, 6.227176e-2, 1.047858e-3, -1.062417e-4, -1.844923e-6, 0};	
	const scalar sigma4_log_delta4[n]= 		{7.345945, 9.087033e-2, -2.859605e-3, -1.787083e-4, 1.598906e-4,0};
		
	const scalar sigma5_log_a5[n]=				{-1.924773e-2, -1.929031e-1, -7.597965e-2, 1.232504e-3, 2.797944e-4, 0};	
	const scalar sigma5_log_c5[n]=				{1.054992e+1, 6.447025e-2, -3.834145e-4, -3.294639e-5, -3.605812e-6, 0};	
	const scalar sigma5_log_delta5[n]= 		{8.500778, 7.811525e-2, 4.703012e-3, -1.262204e-4, -1.791684e-5,0};	
	
	const scalar sigma6_meno_a6[n]=				{3.551938, -3.852851e-1, -1.698205e-2, 7.712558e-4, 1.558067e-4, 0};	
	const scalar sigma6_log_c6[n]=				{9.648995, 6.284331e-2, 8.307533e-4, -5.453268e-6, 0, 0};	
	const scalar sigma6_log_delta6[n]= 		{8.298063, 8.885346e-2, -2.901675e-3, -4.450595e-4,0,0};	
	
	const scalar sigma7_meno_log_a7[n]=				{ 2.202713, -5.805578e-3, -8.393797e-3, -1.542107e-4, -2.149336e-5, -3.876960e-7};	
	const scalar sigma7_log_c7[n]=				{1.029898e+1, 6.646081e-2, 9.291080e-4, -2.151764e-5,0,0};	
	const scalar sigma7_log_delta7[n]= 		{9.012095, 9.149373e-2, -3.140624e-3, -3.285520e-6,0,0};
	
	const scalar sigma8_meno_log_a8[n]=		{-9.551600e-1, -1.743228e-1, -2.627017e-3, 2.020135e-3, 1.148529e-4, 0};	
	const scalar sigma8_log_c8[n]=				{1.077964e+1, 6.865954e-2, 1.085963e-3, -3.640453e-5,0, 0};	
	const scalar sigma8_log_delta8[n]= 		{8.301383, 3.547869e-2, 3.053608e-3, 1.705129e-3, 4.357310e-5, 0};	

	const scalar sigma9_meno_log_a9[n]=				{-4.892131e-1, 3.979950e-2, 2.397782e-3, -2.138908e-4, 1.140375e-5,0};	
	const scalar sigma9_log_c9[n]=				{1.108799e+1, 5.677599e-2, 4.945738e-4, -2.418338e-5,0,0};	
	const scalar sigma9_log_delta9[n]= 		{9.032754, 1.718233e-1, -1.352010e-3, -2.482520e-4, 1.256822e-4,0};
		
	const scalar sigma10_a10[n]=			{1.134500 ,-5.153304e-2, 6.888543e-3,0,0,0};	
	const scalar sigma10_log_c10[n]=			{1.144639e+1, 6.234266e-2, 3.785377e-3,0,0,0};	
	const scalar sigma10_delta10[n]= 		{2.879605e+4, 2.066908e+3, 1.929331e+2, -6.651374e+1, -7.803606,0};	

	//Calcolo coef

	//a2,c2,delta2
	scalar a_2=0, c_2=0, delta_2=0;	
	for(int i=0; i<n; i++)
	{
	    a_2+= sigma2_log_a2[i]*x[i];
	    c_2+= sigma2_log_c2[i]*x[i];
	    delta_2+= sigma2_log_delta2[i]*x[i];
	}
		
    a_2=Foam::exp(a_2);
    c_2=Foam::exp(c_2);
	delta_2=Foam::exp(delta_2);
	
	//a3,c3,delta3
	scalar a_3=0, c_3=0, delta_3=0;	
	for(int i=0; i<n; i++)
	{
	    a_3+= sigma3_log_a3[i]*x[i];
	    c_3+= sigma3_log_c3[i]*x[i];
	    delta_3+= sigma3_log_delta3[i]*x[i];
	}
	
    a_3=Foam::exp(a_3);
    c_3=Foam::exp(c_3);
	delta_3=Foam::exp(delta_3);

	//a4,c4,delta4
	scalar a_4=0, c_4=0, delta_4=0;
	for(int i=0; i<n; i++)
	{
	    a_4+= sigma4_log_a4[i]*x[i];
	    c_4+= sigma4_log_c4[i]*x[i];
	    delta_4+= sigma4_log_delta4[i]*x[i];
	    
	}

    a_4=Foam::exp(a_4);
    c_4=Foam::exp(c_4);
	delta_4=Foam::exp(delta_4);
	
	//a5,c5,delta5
	scalar a_5=0, c_5=0, delta_5=0;	
	for(int i=0; i<n; i++)
	{
	    a_5+= sigma5_log_a5[i]*x[i];
	    c_5+= sigma5_log_c5[i]*x[i];
	    delta_5+= sigma5_log_delta5[i]*x[i];
	}

    a_5=Foam::exp(a_5);
    c_5=Foam::exp(c_5);
	delta_5=Foam::exp(delta_5);
		
	//a6,c6,delta6
	scalar a_6=0, c_6=0, delta_6=0;
	for(int i=0; i<n; i++)
	{
	    a_6+= sigma6_meno_a6[i]*x[i];
	    c_6+= sigma6_log_c6[i]*x[i];
	    delta_6+= sigma6_log_delta6[i]*x[i];
	}
		
	a_6=-(a_6);
    c_6=Foam::exp(c_6);
	delta_6=Foam::exp(delta_6);
	
	//a7,c7,delta7
	scalar a_7=0, c_7=0, delta_7=0;
	for(int i=0; i<n; i++)
	{
	    a_7+= sigma7_meno_log_a7[i]*x[i];
	    c_7+= sigma7_log_c7[i]*x[i];
	    delta_7+= sigma7_log_delta7[i]*x[i];
	}
		
    a_7=-Foam::exp(a_7);
    c_7=Foam::exp(c_7);
	delta_7=Foam::exp(delta_7);
	
	//a8,c8,delta8
	scalar a_8=0, c_8=0, delta_8=0;
	for(int i=0; i<n; i++)
	{
	    a_8+= sigma8_meno_log_a8[i]*x[i];
	    c_8+= sigma8_log_c8[i]*x[i];
	    delta_8+= sigma8_log_delta8[i]*x[i];
	}	

    a_8=-Foam::exp(a_8);
    c_8=Foam::exp(c_8);
	delta_8=Foam::exp(delta_8);

	//a9,c9,delta9
	scalar a_9=0, c_9=0, delta_9=0;
	for(int i=0; i<n; i++)
	{
	    a_9+= sigma9_meno_log_a9[i]*x[i];
	    c_9+= sigma9_log_c9[i]*x[i];
	    delta_9+= sigma9_log_delta9[i]*x[i];
	}	
	
    a_9=-Foam::exp(a_9);
    c_9=Foam::exp(c_9);
	delta_9=Foam::exp(delta_9);
	
	//a10,c10,delta10
	scalar a_10=0, c_10=0, delta_10=0;
	for(int i=0; i<n; i++)
	{
	    a_10+= sigma10_a10[i]*x[i];
	    c_10+= sigma10_log_c10[i]*x[i];
	    delta_10+= sigma10_delta10[i]*x[i];
	}
    c_10=Foam::exp(c_10);

	//Definizioni 
    const scalar eps0=a_0-c_0*Foam::exp(-Foam::pow(T/delta_0,w_0));
	
	const scalar q1=(T-c_1)/delta_1;
	const scalar q2=(T-c_2)/delta_2;
	const scalar q3=(T-c_3)/delta_3;
	const scalar q4=(T-c_4)/delta_4;
	const scalar q5=(T-c_5)/delta_5;
	const scalar q6=(T-c_6)/delta_6;
	const scalar q7=(T-c_7)/delta_7;
	const scalar q8=(T-c_8)/delta_8;
	const scalar q9=(T-c_9)/delta_9;
	const scalar q10=(T-c_10)/delta_10;

	const scalar q[5]={q1,q2,q3,q4,q5}, qq[5]={q6,q7,q8,q9,q10};
    
	//Definizione sigma e sigma
	scalar sigma[5], sigmasigma[5];
    const scalar maxValue=-100.0; // for q<-2.5 the sigmoid is less than 7e-3
    for (int j=0; j<5; j++)
	{   
        if (2*q[j]< maxValue ) {
            sigma[j]=0.0; 
        }else{
	    	sigma[j]=1.0/(1.0+Foam::exp(-2*q[j]));
	    }
    }

    for (int j=0; j<5; j++)
	{   
        if (2*qq[j]< maxValue ) {
            sigmasigma[j]=0.0; 
        }else{
	    	sigmasigma[j]=1.0/(1.0+Foam::exp(-2*qq[j]));
	    }
    }
	
	//Definizione a aa
	const scalar a[5]={a_1,a_2,a_3,a_4,a_5}, aa[5]={a_6,a_7,a_8,a_9,a_10};
	
	//CALCOLO mu
	scalar z=0.0, h=0.0; 
	
	for (int i=0; i<5; i++)
	{
		z+=a[i]*sigma[i];
	}
	
	for (int i=0; i<5; i++)
	{
		h+=aa[i]*sigmasigma[i];
	}
	
	const scalar log_mu=Foam::log( eps0+z)+h;	
    const scalar mu=Foam::exp(log_mu);
	
