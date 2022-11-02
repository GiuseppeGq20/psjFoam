//Dynamic Viscosity [kg/(ms)]
// il codice vuole p in atm e T in K
    double patm=p/101325;
	int n=6;  //numero elementi di x

		
	//Coef Tab 25
	double x[n]={pow(log(patm),0), pow(log(patm),1), pow(log(patm),2), pow(log(patm),3), pow(log(patm),4), pow(log(patm),5)};
	
	double  eps0_a0[n]={-2.490318e-3,0,0,0,0,0};
	double  eps0_c0[n]={1.138022e-5,0,0,0,0,0};
	double  eps0_delta0[n]={2.525477e+2,0,0,0,0,0};
	double  eps0_w0[n]={1,0,0,0,0,0};
    
	double sigma1_a1[n]=		{2.658346e-3,0,0,0,0,0};	
	double sigma1_c1[n]=		{-1.158238e+4,0,0,0,0,0};	
	double sigma1_delta1[n]= {8.370196e+3,0,0,0,0,0};
	
	double sigma2_log_a2[n]=		{-9.146259, 9.214388e-2, -7.532526e-3,0,0, 0};	
	double sigma2_log_c2[n]=		{8.758933, 5.609203e-2, 7.113878e-4,0,0, 0};	
	double sigma2_log_delta2[n]= {7.621521, 6.802267e-2, -4.173943e-3,0,0, 0};

	double sigma3_log_a3[n]=		{-1.077843e+1, 8.010183e-2, 5.530383e-3,0,0,0};	
	double sigma3_log_c3[n]=				{8.183393, 5.531418e-2, 1.161696e-3,0,0 ,0};	
	double sigma3_log_delta3[n]= 		{6.544301, 1.395158e-1, 1.269937e-3,0,0, 0};
		
		//
	double sigma4_log_a4[n]=				{-9.136467, 4.321416e-2, -1.415683e-2, -9.589284e-4, 2.418933e-4, 5.834458e-6};	
	double sigma4_log_c4[n]=				{9.196899, 6.227176e-2, 1.047858e-3, -1.062417e-4, -1.844923e-6, 0};	
	double sigma4_log_delta4[n]= 		{7.345945, 9.087033e-2, -2.859605e-3, -1.787083e-4, 1.598906e-4,0};
	
		
	double sigma5_log_a5[n]=				{-1.924773e-2, -1.929031e-1, -7.597965e-2, 1.232504e-3, 2.797944e-4, 0};	
	double sigma5_log_c5[n]=				{1.054992e+1, 6.447025e-2, -3.834145e-4, -3.294639e-5, -3.605812e-6, 0};	
	double sigma5_log_delta5[n]= 		{8.500778, 7.811525e-2, 4.703012e-3, -1.262204e-4, -1.791684e-5,0};	
	
	double sigma6_meno_a6[n]=				{3.551938, -3.852851e-1, -1.698205e-2, 7.712558e-4, 1.558067e-4, 0};	
	double sigma6_log_c6[n]=				{9.648995, 6.284331e-2, 8.307533e-4, -5.453268e-6, 0, 0};	
	double sigma6_log_delta6[n]= 		{8.298063, 8.885346e-2, -2.901675e-3, -4.450595e-4,0,0};	
	
	
	double sigma7_meno_log_a7[n]=				{ 2.202713, -5.805578e-3, -8.393797e-3, -1.542107e-4, -2.149336e-5, -3.876960e-7};	
	double sigma7_log_c7[n]=				{1.029898e+1, 6.646081e-2, 9.291080e-4, -2.151764e-5,0,0};	
	double sigma7_log_delta7[n]= 		{9.012095, 9.149373e-2, -3.140624e-3, -3.285520e-6,0,0};
	
	double sigma8_meno_log_a8[n]=		{-9.551600e-1, -1.743228e-1, -2.627017e-3, 2.020135e-3, 1.148529e-4, 0};	
	double sigma8_log_c8[n]=				{1.077964e+1, 6.865954e-2, 1.085963e-3, -3.640453e-5,0, 0};	
	double sigma8_log_delta8[n]= 		{8.301383, 3.547869e-2, 3.053608e-3, 1.705129e-3, 4.357310e-5, 0};	

	double sigma9_meno_log_a9[n]=				{-4.892131e-1, 3.979950e-2, 2.397782e-3, -2.138908e-4, 1.140375e-5,0};	
	double sigma9_log_c9[n]=				{1.108799e+1, 5.677599e-2, 4.945738e-4, -2.418338e-5,0,0};	
	double sigma9_log_delta9[n]= 		{9.032754, 1.718233e-1, -1.352010e-3, -2.482520e-4, 1.256822e-4,0};
	
		
	double sigma10_a10[n]=			{1.134500 ,-5.153304e-2, 6.888543e-3,0,0,0};	
	double sigma10_log_c10[n]=			{1.144639e+1, 6.234266e-2, 3.785377e-3,0,0,0};	
	double sigma10_delta10[n]= 		{2.879605e+4, 2.066908e+3, 1.929331e+2, -6.651374e+1, -7.803606,0};	

	//Calcolo coef


    //a_0
	double esp0_a0v[n],esp0_c0v[n],esp0_delta0v[n],esp0_w0v[n];
	double a_0=0, c_0=0, delta_0=0,w_0=0;
	
	for(int i=0; i<n; i++)
	{
	    esp0_a0v[i]=    eps0_a0[i]*x[i];
	    esp0_c0v[i]=    eps0_c0[i]*x[i];
	    esp0_delta0v[i]=eps0_delta0[i]*x[i];
	    esp0_w0v[i]=eps0_w0[i]*x[i];	    
	    
	    a_0=a_0+esp0_a0v[i];
	    c_0=c_0+esp0_c0v[i];
	    delta_0=delta_0+esp0_delta0v[i];
	    w_0=w_0+esp0_w0v[i];
	}

	//a1,c1,delta1
	double sigma1_a1v[n],sigma1_c1v[n],sigma1_delta1v[n];
	double a_1=0, c_1=0, delta_1=0;
	
	for(int i=0; i<n; i++)
	{
	    sigma1_a1v[i]=    sigma1_a1[i]*x[i];
	    sigma1_c1v[i]=    sigma1_c1[i]*x[i];
	    sigma1_delta1v[i]=sigma1_delta1[i]*x[i];
	    
	    a_1=a_1+sigma1_a1v[i];
	    c_1=c_1+sigma1_c1v[i];
	    delta_1=delta_1+sigma1_delta1v[i];
	}
   

	//a2,c2,delta2
	double sigma2_log_a2v[n],sigma2_log_c2v[n],sigma2_log_delta2v[n];
	double a_2=0, c_2=0, delta_2=0;	
	for(int i=0; i<n; i++)
	{
	    sigma2_log_a2v[i]=    sigma2_log_a2[i]*x[i];
	    sigma2_log_c2v[i]=    sigma2_log_c2[i]*x[i];
	    sigma2_log_delta2v[i]=sigma2_log_delta2[i]*x[i];
	    
	    a_2=a_2+sigma2_log_a2v[i];
	    c_2=c_2+sigma2_log_c2v[i];
	    delta_2=delta_2+sigma2_log_delta2v[i];	    
	}
		
    a_2=exp(a_2);
    c_2=exp(c_2);
	delta_2=exp(delta_2);
	
	//a3,c3,delta3
	double sigma3_log_meno_a3v[n],sigma3_log_c3v[n],sigma3_log_delta3v[n];
	double a_3=0, c_3=0, delta_3=0;	
	for(int i=0; i<n; i++)
	{
	    sigma3_log_meno_a3v[i]=    sigma3_log_a3[i]*x[i];
	    sigma3_log_c3v[i]=    sigma3_log_c3[i]*x[i];
	    sigma3_log_delta3v[i]=sigma3_log_delta3[i]*x[i];
	    
	    a_3=a_3+sigma3_log_meno_a3v[i];
		c_3=c_3+sigma3_log_c3v[i];
		delta_3=delta_3+sigma3_log_delta3v[i];	
	}
	
    a_3=exp(a_3);
    c_3=exp(c_3);
	delta_3=exp(delta_3);

	
	
	//a4,c4,delta4
	double sigma4_log_a4v[n],sigma4_log_c4v[n],sigma4_log_delta4v[n];
	double a_4=0, c_4=0, delta_4=0;
	for(int i=0; i<n; i++)
	{
	    sigma4_log_a4v[i]=    sigma4_log_a4[i]*x[i];
	    sigma4_log_c4v[i]=    sigma4_log_c4[i]*x[i];
	    sigma4_log_delta4v[i]=sigma4_log_delta4[i]*x[i];
	    
	a_4=a_4+sigma4_log_a4v[i];
	c_4=c_4+sigma4_log_c4v[i];
	delta_4=delta_4+sigma4_log_delta4v[i];
	}
	

    a_4=exp(a_4);
    c_4=exp(c_4);
	delta_4=exp(delta_4);
	
	//a5,c5,delta5
	double sigma5_log_a5v[n],sigma5_log_c5v[n],sigma5_log_delta5v[n];
	double a_5=0, c_5=0, delta_5=0;	
	for(int i=0; i<4; i++)
	{
	    sigma5_log_a5v[i]=    sigma5_log_a5[i]*x[i];
	    sigma5_log_c5v[i]=    sigma5_log_c5[i]*x[i];
	    sigma5_log_delta5v[i]=sigma5_log_delta5[i]*x[i];
	    
	a_5=a_5+sigma5_log_a5v[i];
	c_5=c_5+sigma5_log_c5v[i];
	delta_5=delta_5+sigma5_log_delta5v[i];
	}
		
    a_5=exp(a_5);
    c_5=exp(c_5);
	delta_5=exp(delta_5);
		
	//a6,c6,delta6
	double sigma6_log_a6v[n],sigma6_log_c6v[n],sigma6_log_delta6v[n];
	double a_6=0, c_6=0, delta_6=0;
	for(int i=0; i<4; i++)
	{
	    sigma6_log_a6v[i]=    sigma6_meno_a6[i]*x[i];
	    sigma6_log_c6v[i]=    sigma6_log_c6[i]*x[i];
	    sigma6_log_delta6v[i]=sigma6_log_delta6[i]*x[i];
	    
	a_6=a_6+sigma6_log_a6v[i];
	c_6=c_6+sigma6_log_c6v[i];
	delta_6=delta_6+sigma6_log_delta6v[i];


	}
		
	a_6=-(a_6);
    c_6=exp(c_6);
	delta_6=exp(delta_6);
	
	
	//a7,c7,delta7
	double sigma7_log_a7v[n],sigma7_log_c7v[n],sigma7_log_delta7v[n];
	double a_7=0, c_7=0, delta_7=0;
	for(int i=0; i<4; i++)
	{
	    sigma7_log_a7v[i]=    sigma7_meno_log_a7[i]*x[i];
	    sigma7_log_c7v[i]=    sigma7_log_c7[i]*x[i];
	    sigma7_log_delta7v[i]=sigma7_log_delta7[i]*x[i];
	    
	a_7=a_7+sigma7_log_a7v[i];
	c_7=c_7+sigma7_log_c7v[i];
	delta_7=delta_7+sigma7_log_delta7v[i];


	}
		
    a_7=-exp(a_7);
    c_7=exp(c_7);
	delta_7=exp(delta_7);
	
	//a8,c8,delta8
	double sigma8_log_meno_a8v[n],sigma8_log_c8v[n],sigma8_log_delta8v[n];
	double a_8=0, c_8=0, delta_8=0;
	for(int i=0; i<4; i++)
	{
	    sigma8_log_meno_a8v[i]=    sigma8_meno_log_a8[i]*x[i];
	    sigma8_log_c8v[i]=    sigma8_log_c8[i]*x[i];
	    sigma8_log_delta8v[i]=sigma8_log_delta8[i]*x[i];
	    
	a_8=a_8+sigma8_log_meno_a8v[i];
	c_8=c_8+sigma8_log_c8v[i];
	delta_8=delta_8+sigma8_log_delta8v[i];


	}	

    a_8=-exp(a_8);
    c_8=exp(c_8);
	delta_8=exp(delta_8);

	//a9,c9,delta9
	double sigma9_log_a9v[n],sigma9_log_c9v[n],sigma9_log_delta9v[n];
	double a_9=0, c_9=0, delta_9=0;
	for(int i=0; i<4; i++)
	{
	    sigma9_log_a9v[i]=    sigma9_meno_log_a9[i]*x[i];
	    sigma9_log_c9v[i]=    sigma9_log_c9[i]*x[i];
	    sigma9_log_delta9v[i]=sigma9_log_delta9[i]*x[i];
	    
	a_9=a_9+sigma9_log_a9v[i];
	c_9=c_9+sigma9_log_c9v[i];
	delta_9=delta_9+sigma9_log_delta9v[i];


	}	
	
    a_9=-exp(a_9);
    c_9=exp(c_9);
	delta_9=exp(delta_9);
	
	
	//a10,c10,delta10
	double sigma10_log_a10v[n],sigma10_log_c10v[n],sigma10_log_delta10v[n];
	double a_10=0, c_10=0, delta_10=0;
	for(int i=0; i<4; i++)
	{
	    sigma10_log_a10v[i]=    sigma10_a10[i]*x[i];
	    sigma10_log_c10v[i]=    sigma10_log_c10[i]*x[i];
	    sigma10_log_delta10v[i]=sigma10_delta10[i]*x[i];
	    
   	a_10=a_10+sigma10_log_a10v[i];
	c_10=c_10+sigma10_log_c10v[i];
	delta_10=delta_10+sigma10_log_delta10v[i];

	}
	
	

    c_10=exp(c_10);

		
	//Definizioni 

    double eps0=a_0-c_0*exp(-pow(T/delta_0,w_0));
	
	double q1=(T-c_1)/delta_1;
	double q2=(T-c_2)/delta_2;
	double q3=(T-c_3)/delta_3;
	double q4=(T-c_4)/delta_4;
	double q5=(T-c_5)/delta_5;
	double q6=(T-c_6)/delta_6;
	double q7=(T-c_7)/delta_7;
	double q8=(T-c_8)/delta_8;
	double q9=(T-c_9)/delta_9;
	double q10=(T-c_10)/delta_10;


	double q[5]={q1,q2,q3,q4,q5}, qq[5]={q6,q7,q8,q9,q10};
    
	//Definizione sigma e sigma
	double sigma[5], sigmasigma[5];
	
	for (int j=0; j<5; j++)
	{
		sigma[j]=exp(q[j])/(exp(q[j])+exp(-q[j]));

	}
	
	for (int j=0; j<5; j++)
	{
		sigmasigma[j]=exp(qq[j])/(exp(qq[j])+exp(-qq[j]));
	}
	

	
	//Definizione a aa
	double a[5]={a_1,a_2,a_3,a_4,a_5}, aa[5]={a_7,a_8,a_9,a_10};
	
	//CALCOLO Kappa
	
	double z=0, h=0; 
	
	for (int i=0; i<5; i++)
	{
		z=z+a[i]*sigma[i];
	}
	
	for (int i=0; i<5; i++)
	{
		h=h+aa[i]*sigmasigma[i];
	}
	
	double log_mu=log( eps0+z)+h;	
	

	
	scalar mud=exp(log_mu);
	
	 
