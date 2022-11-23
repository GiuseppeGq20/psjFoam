//Specific entropy [cal/(g K)]
// il codice vuole p in atm e T in K
    scalar patm=p/101325.0;
	const int n=4;  //numero elementi di x



	//Coef Tab 25
	scalar x[n]={Foam::pow(Foam::log(patm),0), Foam::pow(Foam::log(patm),1), Foam::pow(Foam::log(patm),2), Foam::pow(Foam::log(patm),3)};


	scalar phi_a0[n]=		{7.247773e-1, -5.579293e-2, 1.246960e-3, 0};	
	scalar phi_log_w0[n]=		{-1.949369, 4.114017e-2, -1.494867e-4,0};	


	scalar sigma1_a1[n]=		{2.181324e-1, -2.219875e-2, -3.107110e-4, 0};	
	scalar sigma1_log_c1[n]=		{8.148014, 5.310698e-2, 1.031964e-3,0};	
	scalar sigma1_log_delta1[n]= {6.487571, 1.023051e-1, 2.174761e-3,0};
	
	scalar sigma2_a2[n]=		{9.599015e-1, -5.505086e-2, 1.666018e-5,0};	
	scalar sigma2_log_c2[n]=		{8.839993, 5.776858e-2, 1.370456e-3,0};
	scalar sigma2_log_delta2[n]= {7.037019, 1.068246e-1, 2.382441e-3,0};

	scalar sigma3_log_a3[n]=		{6.970847e-1, -6.594736e-2, -2.375941e-3, -6.719048e-5};	
	scalar sigma3_log_c3[n]=				{9.574258, 6.744128e-2, 1.024908e-3, -4.207616e-5};	
	scalar sigma3_log_delta3[n]= 		{8.030117, 1.278105e-1, 2.875819e-3, 5.995551e-5};
		
		
	scalar sigma4_log_a4[n]=				{7.418974e-1, -6.340965e-2, -1.805794e-3, -5.053043e-5};	
	scalar sigma4_log_c4[n]=				{1.029506e+1, 6.492224e-2, 1.056643e-3, -1.643501e-5};	
	scalar sigma4_log_delta4[n]= 		{8.459989, 1.137276e-1, 3.515754e-3,0};
	
		
	scalar sigma5_log_a5[n]=				{7.657208e-1, -5.775822e-2, -7.902876e-4,0};	
	scalar sigma5_log_c5[n]=				{1.073845e+1, 6.189030e-2, 1.130363e-3,0};	
	scalar sigma5_log_delta5[n]= 		{8.822908, 1.163591e-1, 3.457547e-3,0};	
	
	
	
	scalar sigma6_a6[n]=				{2.767445, -1.126949e-1, 2.483520e-3,0};	
	scalar sigma6_log_c6[n]=				{1.108196e+1, 6.043375e-2, 1.256963e-3,0};	
	scalar sigma6_log_delta6[n]= 		{9.251052, 1.085228e-1, 1.802991e-3,0};	
	
	
	scalar sigma7_log_a7[n]=				{ 1.503593, 6.710278e-2, 1.417762e-3,0};	
	scalar sigma7_log_c7[n]=				{1.188475e+1, 8.409849e-2, 1.321048e-3,0};	
	scalar sigma7_log_delta7[n]= 		{1.082135e+1, 1.048287e-1, -5.310563e-3,0};

	//Calcolo coef

    //c0 c1
	scalar a_0=0, w_0=0;
	
	for(int i=0; i<n; i++)
	{ 
	    a_0=a_0+ phi_a0[i]*x[i];
	    w_0=w_0+ phi_log_w0[i]*x[i];
	    
	}
    w_0=Foam::exp(w_0);
    
	//a1,c1,delta1
	scalar sigma1_a1v[n],sigma1_log_c1v[n],sigma1_log_delta1v[n];
	scalar a_1=0, c_1=0, delta_1=0;
	
	for(int i=0; i<n; i++)
	{
	    sigma1_a1v[i]=    sigma1_a1[i]*x[i];
	    sigma1_log_c1v[i]=    sigma1_log_c1[i]*x[i];
	    sigma1_log_delta1v[i]=sigma1_log_delta1[i]*x[i];
	    
	    a_1=a_1+sigma1_a1v[i];
	    c_1=c_1+sigma1_log_c1v[i];
	    delta_1=delta_1+sigma1_log_delta1v[i];
	}
	

    c_1=Foam::exp(c_1);
	delta_1=Foam::exp(delta_1);

	//a2,c2,delta2
	scalar sigma2_a2v[n],sigma2_log_c2v[n],sigma2_log_delta2v[n];
	scalar a_2=0, c_2=0, delta_2=0;	
	for(int i=0; i<n; i++)
	{
	    sigma2_a2v[i]=    sigma2_a2[i]*x[i];
	    sigma2_log_c2v[i]=    sigma2_log_c2[i]*x[i];
	    sigma2_log_delta2v[i]=sigma2_log_delta2[i]*x[i];
	    
	    a_2=a_2+sigma2_a2v[i];
	    c_2=c_2+sigma2_log_c2v[i];
	    delta_2=delta_2+sigma2_log_delta2v[i];	    
	}
		
    c_2=Foam::exp(c_2);
	delta_2=Foam::exp(delta_2);
	
	//a3,c3,delta3
	scalar sigma3_log_a3v[n],sigma3_log_c3v[n],sigma3_log_delta3v[n];
	scalar a_3=0, c_3=0, delta_3=0;	
	for(int i=0; i<n; i++)
	{
	    sigma3_log_a3v[i]=    sigma3_log_a3[i]*x[i];
	    sigma3_log_c3v[i]=    sigma3_log_c3[i]*x[i];
	    sigma3_log_delta3v[i]=sigma3_log_delta3[i]*x[i];
	    
	    a_3=a_3+sigma3_log_a3v[i];
		c_3=c_3+sigma3_log_c3v[i];
		delta_3=delta_3+sigma3_log_delta3v[i];	
	}
	
    a_3=Foam::exp(a_3);
    c_3=Foam::exp(c_3);
	delta_3=Foam::exp(delta_3);

	
	
	//a4,c4,delta4
	scalar sigma4_log_a4v[n],sigma4_log_c4v[n],sigma4_log_delta4v[n];
	scalar a_4=0, c_4=0, delta_4=0;
	for(int i=0; i<n; i++)
	{
	    sigma4_log_a4v[i]=    sigma4_log_a4[i]*x[i];
	    sigma4_log_c4v[i]=    sigma4_log_c4[i]*x[i];
	    sigma4_log_delta4v[i]=sigma4_log_delta4[i]*x[i];
	    
	a_4=a_4+sigma4_log_a4v[i];
	c_4=c_4+sigma4_log_c4v[i];
	delta_4=delta_4+sigma4_log_delta4v[i];
	}
	

    a_4=Foam::exp(a_4);
    c_4=Foam::exp(c_4);
	delta_4=Foam::exp(delta_4);
	
	//a5,c5,delta5
	scalar sigma5_log_a5v[n],sigma5_log_c5v[n],sigma5_log_delta5v[n];
	scalar a_5=0, c_5=0, delta_5=0;	
	for(int i=0; i<n; i++)
	{
	    sigma5_log_a5v[i]=    sigma5_log_a5[i]*x[i];
	    sigma5_log_c5v[i]=    sigma5_log_c5[i]*x[i];
	    sigma5_log_delta5v[i]=sigma5_log_delta5[i]*x[i];
	    
	a_5=a_5+sigma5_log_a5v[i];
	c_5=c_5+sigma5_log_c5v[i];
	delta_5=delta_5+sigma5_log_delta5v[i];
	}
		
    a_5=Foam::exp(a_5);
    c_5=Foam::exp(c_5);
	delta_5=Foam::exp(delta_5);
		
	//a6,c6,delta6
	scalar sigma6_a6v[n],sigma6_log_c6v[n],sigma6_log_delta6v[n];
	scalar a_6=0, c_6=0, delta_6=0;
	for(int i=0; i<n; i++)
	{
	    sigma6_a6v[i]=    sigma6_a6[i]*x[i];
	    sigma6_log_c6v[i]=    sigma6_log_c6[i]*x[i];
	    sigma6_log_delta6v[i]=sigma6_log_delta6[i]*x[i];
	    
	a_6=a_6+sigma6_a6v[i];
	c_6=c_6+sigma6_log_c6v[i];
	delta_6=delta_6+sigma6_log_delta6v[i];


	}
		

    c_6=Foam::exp(c_6);
	delta_6=Foam::exp(delta_6);
	
	
	//a7,c7,delta7
	scalar sigma7_log_a7v[n],sigma7_log_c7v[n],sigma7_log_delta7v[n];
	scalar a_7=0, c_7=0, delta_7=0;
	for(int i=0; i<n; i++)
	{
	    sigma7_log_a7v[i]=    sigma7_log_a7[i]*x[i];
	    sigma7_log_c7v[i]=    sigma7_log_c7[i]*x[i];
	    sigma7_log_delta7v[i]=sigma7_log_delta7[i]*x[i];
	    
	a_7=a_7+sigma7_log_a7v[i];
	c_7=c_7+sigma7_log_c7v[i];
	delta_7=delta_7+sigma7_log_delta7v[i];


	}
		
    a_7=Foam::exp(a_7);
    c_7=Foam::exp(c_7);
	delta_7=Foam::exp(delta_7);
	

		
	//Definizioni q
	
	scalar q1=(T-c_1)/delta_1;
	scalar q2=(T-c_2)/delta_2;
	scalar q3=(T-c_3)/delta_3;
	scalar q4=(T-c_4)/delta_4;
	scalar q5=(T-c_5)/delta_5;
	scalar q6=(T-c_6)/delta_6;
	scalar q7=(T-c_7)/delta_7;


	scalar q[7]={q1,q2,q3,q4,q5,q6,q7};
    
	//Definizione sigma e gamma
	scalar sigma[7]; 
	
	for (int j=0; j<7; j++)
	{
		sigma[j]=Foam::exp(q[j])/(Foam::exp(q[j])+Foam::exp(-q[j]));

	}
	
	scalar phi0; 
	 
	phi0=a_0*Foam::pow(T,w_0); 
	

	
	//Definizione a aa
	scalar a[7]={a_1,a_2,a_3,a_4,a_5,a_6,a_7};
	

	//CALCOLO Kappa
	
	scalar z=0; 
	
	for (int i=0; i<7; i++)
	{
		z=z+a[i]*sigma[i];
	}
	
	
	
	scalar S=z+phi0;	
	
	S=S*4.1867999409*1000; // conversion from cal/g*K to J/Kg*K
