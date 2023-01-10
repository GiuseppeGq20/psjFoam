    const scalar patm=p/101325.0;
    
	const int n=5;  //numero elementi di x

	//Coef Tab 25
	const scalar x[n]={Foam::pow(Foam::log(patm),0), Foam::pow(Foam::log(patm),1), Foam::pow(Foam::log(patm),2), Foam::pow(Foam::log(patm),3),Foam::pow(Foam::log(patm),4)};
	
	const scalar  eps0_log_a0[n]={1.635045, 4.450390e-2, -5.928863e-4, 0, 0};
	const scalar  eps0_log_c0[n]={5.748398, 6.411299e-2, 0, 0, 0};
	const scalar  eps0_log_delta0[n]={1.786355, -1.212690e-2, -2.375673e-4, 0, 0};
	const scalar  eps0_log_w0[n]={1.419925 , -3.875497e-2,0,0,0};	
		    
	const scalar sigma1_log_a1[n]=		{4.493934e-2 -9.063708e-3 -2.489500e-3,0,0};	
	const scalar sigma1_log_c1[n]=		{8.930803, 5.718843e-2, 1.093759e-3,0,0};	
	const scalar sigma1_log_delta1[n]= {7.014976, 7.625175e-2, 3.011941e-4,0,0};
	
	const scalar sigma2_a2[n]=		{1.593153, 4.137850e-2, 1.430491e-2, -4.403957e-7,0};	
	const scalar sigma2_log_c2[n]=		{8.576847, 1.004174e-1, 7.406762e-3, -1.095186e-3,0};	
	const scalar sigma2_log_delta2[n]= {9.113182, -8.202725e-2, 6.299430e-3, 9.099828e-4,0};

	const scalar sigma3_meno_a3[n]=		{2.627897e-1, 2.917558e-3, 3.036205e-3, -1.926651e-4, -2.917018e-5};	
	const scalar sigma3_log_c3[n]=				{1.023493e+1, 6.651575e-2, 1.090308e-3, -6.576415e-5, 4.715318e-7};	
	const scalar sigma3_log_delta3[n]= 		{8.039563, 1.435966e-1, 8.862611e-3, -3.478227e-4, -3.614711e-5};
	
	const scalar sigma4_meno_a4[n]=				{1.707216e-1, 2.035164e-2, 1.809127e-3, -9.630175e-5, 1.781249e-5};	
	const scalar sigma4_log_c4[n]=				{1.072380e+1, 5.671452e-2, 1.468210e-4, 2.608196e-5, 6.511719e-6};	
	const scalar sigma4_log_delta4[n]= 		{8.556977, 2.227207e-1, -2.773160e-3, -1.684219e-3, 1.878188e-4};
	
		
	const scalar sigma5_meno_a5[n]=				{2.480007e-1, 2.217818e-2, 9.094614e-4,0, 0};	
	const scalar sigma5_log_c5[n]=				{1.106431e+1, 5.578774e-2, 6.639655e-4,0,0};	
	const scalar sigma5_log_delta5[n]= 		{9.309043, 1.366510e-1, -2.599317e-3, 0,0};	
	
	const scalar sigma6_a6[n]=				{3.636707, -1.436268e-1, -2.934926e-3,0,0};	
	const scalar sigma6_log_c6[n]=				{1.023203e+1, 8.703300e-2, 5.007602e-3, 0, 0};	
	const scalar sigma6_log_delta6[n]= 		{1.130562e+1, -2.184155e-2, -1.865543e-4,0,0};	
	
	
	//a_7 is definied later because it depends on other a's coefficient
	const scalar sigma7_log_c7[n]=				{2.946755e+1, -4.289010, -3.224136e-1, 9.371814e-2,0};	
	const scalar sigma7_log_delta7[n]= 		{2.430324e+1, -2.653523, -3.309222e-1, 4.769061e-2,0};
	
	//Calcolo coef
   
    //eps_0
	scalar a_0=0, c_0=0, delta_0=0,w_0=0;
	for(int i=0; i<n; i++)
	{
	    a_0+=    eps0_log_a0[i]*x[i];
	    c_0+=    eps0_log_c0[i]*x[i];
	    delta_0+=eps0_log_delta0[i]*x[i];
	    w_0+=eps0_log_w0[i]*x[i];	    
	}

	a_0=Foam::exp(a_0);
    c_0=Foam::exp(c_0);
	delta_0=Foam::exp(delta_0);
	w_0=Foam::exp(w_0);	
	
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
	    a_3+=    sigma3_meno_a3[i]*x[i];
	    c_3+=    sigma3_log_c3[i]*x[i];
	    delta_3+=sigma3_log_delta3[i]*x[i];
	}
	
    a_3=-a_3;
    c_3=Foam::exp(c_3);
	delta_3=Foam::exp(delta_3);
	
	//a4,c4,delta4
	scalar a_4=0, c_4=0, delta_4=0;
	for(int i=0; i<n; i++)
	{
	    a_4+=    sigma4_meno_a4[i]*x[i];
	    c_4+=    sigma4_log_c4[i]*x[i];
	    delta_4+=sigma4_log_delta4[i]*x[i];
	}

    a_4=-(a_4);
    c_4=Foam::exp(c_4);
	delta_4=Foam::exp(delta_4);
	
	//a5,c5,delta5
	scalar a_5=0, c_5=0, delta_5=0;	
	for(int i=0; i<n; i++)
	{
	    a_5+=    sigma5_meno_a5[i]*x[i];
	    c_5+=    sigma5_log_c5[i]*x[i];
	    delta_5+=sigma5_log_delta5[i]*x[i];
	}
		
    a_5=-(a_5);
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
	    c_7+=    sigma7_log_c7[i]*x[i];
	    delta_7+=sigma7_log_delta7[i]*x[i];
	}
		
    a_7=a_3+a_4+a_5-a_1-a_2-a_6;
    c_7=Foam::exp(c_7);
	delta_7=Foam::exp(delta_7);
	
	//Definizioni q
	const scalar eps0=a_0-c_0*Foam::exp(-Foam::pow(Foam::log(T)/delta_0,w_0));
	
	const scalar q1=(T-c_1)/delta_1;
	const scalar q2=(T-c_2)/delta_2;
	const scalar q3=(T-c_3)/delta_3;
	const scalar q4=(T-c_4)/delta_4;
	const scalar q5=(T-c_5)/delta_5;
	const scalar q6=(T-c_6)/delta_6;
	const scalar q7=(T-c_7)/delta_7;

	const scalar q[7]={q1,q2,q3,q4,q5,q6,q7};
    /*for (int i=0; i<7; i++)
    {
        Info<<"q"<<i<<": "<<q[i]<<" ";
    }
    Info<<endl;
    */
	//Definizione sigma e gamma
	const scalar maxValue=-100.0;
	scalar sigma[7];
	// just 6 for overflow errors in exp()
	for (int j=0; j<7; j++)
	{
		if (2*q[j]< maxValue ) {
            sigma[j]=0.0; 
        }else{
	    	sigma[j]=1.0/(1.0+Foam::exp(-2*q[j]));
		}
	}
	
	//Definizione a aa
	scalar a[7]={a_1,a_2,a_3,a_4,a_5,a_6,a_7};
	
	//CALCOLO sigma [S/m]
	
	scalar z=0; 
	
	for (int i=0; i<7; i++)
	{
		z=z+a[i]*sigma[i];
	}
	
	const scalar log_sigma_elec=eps0+z;	
	const scalar Sigma=Foam::exp(log_sigma_elec);
	
