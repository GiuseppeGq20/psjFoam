//Mean molar mass [kg/mol] 
// il codice vuole p in atm e T in K
    const scalar patm=p/101325;
	const int n= 5; //numero elementi di x
     
	const scalar x[n]={Foam::pow(Foam::log(patm),0), Foam::pow(Foam::log(patm),1), Foam::pow(Foam::log(patm),2), Foam::pow(Foam::log(patm),3), Foam::pow(Foam::log(patm),4)};

	const scalar  c0=0.028811;

	const scalar sigma1_log_a1[n]=		{-5.452539, -2.762076e-2, -3.327630e-3, -2.453118e-4, -6.332107e-6};	
	const scalar sigma1_log_c1[n]=		{8.170734, 5.708244e-2, 1.293374e-3,0,0};	
	const scalar sigma1_log_delta1[n]= {6.380594, 1.046470e-1, 8.553860e-4, -1.572857e-4,0};
	
	const scalar sigma2_log_a2[n]=		{-4.595514, 1.328152e-2, 9.294096e-4, -8.243998e-5, -9.490079e-6};	
	const scalar sigma2_log_c2[n]=		{8.805680, 5.468057e-2, 1.121881e-3,0,0};	
	const scalar sigma2_log_delta2[n]= {7.080690, 1.142540e-1, 6.869247e-4, -2.257365e-4,0};

	const scalar sigma3_log_a3[n]=		{-4.971377, -1.668833e-2, -2.409638e-3, -2.840529e-4, -2.934495e-5};	
	const scalar sigma3_log_c3[n]=				{9.525862, 6.639994e-2, 7.836529e-4 -2.447910e-4, -2.415297e-5};	
	const scalar sigma3_log_delta3[n]= 		{7.888211, 9.954169e-2 ,-1.327510e-4, -2.926560e-4, -4.717532e-5};
		
	const scalar sigma4_log_a4[n]=				{-6.720756, 7.203127e-2, 6.766486e-3, -1.019894e-3, 9.196578e-5};	
	const scalar sigma4_log_c4[n]=				{1.055726e+1, 8.397717e-3, 9.849480e-4, 3.539965e-4, -4.236150e-5};	
	const scalar sigma4_log_delta4[n]= 		{8.707609, 3.713173e-2, -1.670186e-2, -5.094908e-4, 4.248200e-4};
	
	const scalar sigma5_log_a5[n]=				{-6.218117, -7.145834e-2, 6.529894e-4, 1.599394e-3, 1.981881e-5};	
	const scalar sigma5_log_c5[n]=				{1.020784e+1, 2.553473e-2, -3.549988e-3,0,0};	
	const scalar sigma5_log_delta5[n]= 		{8.422438, 1.125955e-1, -3.204629e-3, -1.655103e-3, -2.051312e-4};	
	
	const scalar sigma6_log_a6[n]=				{-6.611171, 8.990124e-2, -5.418532e-3,0,0};	
	const scalar sigma6_log_c6[n]=				{1.096136e+1 ,2.887564e-2, -3.621097e-4,0,0};	
	const scalar sigma6_log_delta6[n]= 		{9.253817, 1.341329e-2, -6.004835e-3, 1.860800e-3, -1.229602e-4};	


	//a1,c1,delta1
	scalar a_1=0, c_1=0, delta_1=0;
	for(int i=0; i<n; i++)
	{
	    a_1+=    sigma1_log_a1[i]*x[i];
	    c_1+=    sigma1_log_c1[i]*x[i];
	    delta_1+=sigma1_log_delta1[i]*x[i];
	}
	
    a_1=Foam::exp(a_1);
    c_1=Foam::exp(c_1);
	delta_1=Foam::exp(delta_1);

	//a2,c2,delta2
	scalar a_2=0, c_2=0, delta_2=0;	
	for(int i=0; i<n; i++)
	{
	    a_2+=    sigma2_log_a2[i]*x[i];
	    c_2+=    sigma2_log_c2[i]*x[i];
	    delta_2+=sigma2_log_delta2[i]*x[i];
	}
    a_2=Foam::exp(a_2);
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
	    a_6+= sigma6_log_a6[i]*x[i];
	    c_6+= sigma6_log_c6[i]*x[i];
		delta_6+= sigma6_log_delta6[i]*x[i];
	}
		
	a_6=Foam::exp(a_6);
    c_6=Foam::exp(c_6);
	delta_6=Foam::exp(delta_6);
	
	//Definizioni q
	const scalar q1=(T-c_1)/delta_1;
	const scalar q2=(T-c_2)/delta_2;
	const scalar q3=(T-c_3)/delta_3;
	const scalar q4=(T-c_4)/delta_4;
	const scalar q5=(T-c_5)/delta_5;
	const scalar q6=(T-c_6)/delta_6;

	const scalar q[6]={q1,q2,q3,q4,q5,q6};
    
	//Definizione sigma e gamma
	scalar sigma[6];
	
	for (int j=0; j<6; j++)
	{
		sigma[j]=Foam::exp(q[j])/(Foam::exp(q[j])+Foam::exp(-q[j]));
	}
	
	//Definizione a
    const scalar a[6]={a_1,a_2,a_3,a_4,a_5,a_6};

	//CALCOLO mean molar mass
	scalar z=0; 
	for (int i=0; i<6; i++)
	{
		z+=a[i]*sigma[i];
	}
	
	scalar MM=(c0-z)*1000.0; //[Kg/Kmol]	
	
