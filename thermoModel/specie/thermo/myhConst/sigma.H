    double patm=p/101325;
    


	
	int n=5;  //numero elementi di x

		
	//Coef Tab 25
	double x[n]={pow(log(patm),0), pow(log(patm),1), pow(log(patm),2), pow(log(patm),3),pow(log(patm),4)};
	
	double  eps0_log_a0[n]={1.635045, 4.450390e-2, -5.928863e-4, 0, 0};
	double  eps0_log_c0[n]={5.748398, 6.411299e-2, 0, 0, 0};
	double  eps0_log_delta0[n]={1.786355, -1.212690e-2, -2.375673e-4, 0, 0};
	double  eps0_log_w0[n]={1.419925 , -3.875497e-2,0,0,0};	
		    
	double sigma1_log_a1[n]=		{4.493934e-2 -9.063708e-3 -2.489500e-3,0,0};	
	double sigma1_log_c1[n]=		{8.930803, 5.718843e-2, 1.093759e-3,0,0};	
	double sigma1_log_delta1[n]= {7.014976, 7.625175e-2, 3.011941e-4,0,0};
	
	double sigma2_a2[n]=		{1.593153, 4.137850e-2, 1.430491e-2, -4.403957e-7,0};	
	double sigma2_log_c2[n]=		{8.576847, 1.004174e-1, 7.406762e-3, -1.095186e-3,0};	
	double sigma2_log_delta2[n]= {9.113182, -8.202725e-2, 6.299430e-3, 9.099828e-4,0};

	double sigma3_meno_a3[n]=		{2.627897e-1, 2.917558e-3, 3.036205e-3, -1.926651e-4, -2.917018e-5};	
	double sigma3_log_c3[n]=				{1.023493e+1, 6.651575e-2, 1.090308e-3, -6.576415e-5, 4.715318e-7};	
	double sigma3_log_delta3[n]= 		{8.039563, 1.435966e-1, 8.862611e-3, -3.478227e-4, -3.614711e-5};
	
	double sigma4_meno_a4[n]=				{1.707216e-1, 2.035164e-2, 1.809127e-3, -9.630175e-5, 1.781249e-5};	
	double sigma4_log_c4[n]=				{1.072380e+1, 5.671452e-2, 1.468210e-4, 2.608196e-5, 6.511719e-6};	
	double sigma4_log_delta4[n]= 		{8.556977, 2.227207e-1, -2.773160e-3, -1.684219e-3, 1.878188e-4};
	
		
	double sigma5_meno_a5[n]=				{2.480007e-1, 2.217818e-2, 9.094614e-4,0, 0};	
	double sigma5_log_c5[n]=				{1.106431e+1, 5.578774e-2, 6.639655e-4,0,0};	
	double sigma5_log_delta5[n]= 		{9.309043, 1.366510e-1, -2.599317e-3, 0,0};	
	
	double sigma6_a6[n]=				{3.636707, -1.436268e-1, -2.934926e-3,0,0};	
	double sigma6_log_c6[n]=				{1.023203e+1, 8.703300e-2, 5.007602e-3, 0, 0};	
	double sigma6_log_delta6[n]= 		{1.130562e+1, -2.184155e-2, -1.865543e-4,0,0};	
	
	
	double sigma7_log_a7[n]=				{};	
	double sigma7_log_c7[n]=				{2.946755e+1, -4.289010, -3.224136e-1, 9.371814e-2,0};	
	double sigma7_log_delta7[n]= 		{2.430324e+1, -2.653523, -3.309222e-1, 4.769061e-2,0};
	
		
		
	//Calcolo coef


   
    //eps_0
	double esp0_a0v[n],esp0_c0v[n],esp0_delta0v[n],esp0_w0v[n];
	double a_0=0, c_0=0, delta_0=0,w_0=0;
	
	for(int i=0; i<n; i++)
	{
	    esp0_a0v[i]=    eps0_log_a0[i]*x[i];
	    esp0_c0v[i]=    eps0_log_c0[i]*x[i];
	    esp0_delta0v[i]=eps0_log_delta0[i]*x[i];
	    esp0_w0v[i]=eps0_log_w0[i]*x[i];	    
	    
	    a_0=a_0+esp0_a0v[i];
	    c_0=c_0+esp0_c0v[i];
	    delta_0=delta_0+esp0_delta0v[i];
	    w_0=w_0+esp0_w0v[i];
	}

	a_0=exp(a_0);
    c_0=exp(c_0);
	delta_0=exp(delta_0);
	w_0=exp(w_0);	
	
	//a1,c1,delta1
	double sigma1_log_a1v[n],sigma1_log_c1v[n],sigma1_log_delta1v[n];
	double a_1=0, c_1=0, delta_1=0;
	
	for(int i=0; i<n; i++)
	{
	    sigma1_log_a1v[i]=    sigma1_log_a1[i]*x[i];
	    sigma1_log_c1v[i]=    sigma1_log_c1[i]*x[i];
	    sigma1_log_delta1v[i]=sigma1_log_delta1[i]*x[i];
	    
	    a_1=a_1+sigma1_log_a1v[i];
	    c_1=c_1+sigma1_log_c1v[i];
	    delta_1=delta_1+sigma1_log_delta1v[i];
	}
    
	a_1=exp(a_1);
    c_1=exp(c_1);
	delta_1=exp(delta_1);

	//a2,c2,delta2
	double sigma2_a2v[n],sigma2_log_c2v[n],sigma2_log_delta2v[n];
	double a_2=0, c_2=0, delta_2=0;	
	for(int i=0; i<n; i++)
	{
	    sigma2_a2v[i]=    sigma2_a2[i]*x[i];
	    sigma2_log_c2v[i]=    sigma2_log_c2[i]*x[i];
	    sigma2_log_delta2v[i]=sigma2_log_delta2[i]*x[i];
	    
	    a_2=a_2+sigma2_a2v[i];
	    c_2=c_2+sigma2_log_c2v[i];
	    delta_2=delta_2+sigma2_log_delta2v[i];	    
	}
		

    c_2=exp(c_2);
	delta_2=exp(delta_2);
	
	//a3,c3,delta3
	double sigma3_meno_a3v[n],sigma3_log_c3v[n],sigma3_log_delta3v[n];
	double a_3=0, c_3=0, delta_3=0;	
	for(int i=0; i<n; i++)
	{
	    sigma3_meno_a3v[i]=    sigma3_meno_a3[i]*x[i];
	    sigma3_log_c3v[i]=    sigma3_log_c3[i]*x[i];
	    sigma3_log_delta3v[i]=sigma3_log_delta3[i]*x[i];
	    
	    a_3=a_3+sigma3_meno_a3v[i];
		c_3=c_3+sigma3_log_c3v[i];
		delta_3=delta_3+sigma3_log_delta3v[i];	
	}
	
    a_3=-a_3;
    c_3=exp(c_3);
	delta_3=exp(delta_3);

	
	
	//a4,c4,delta4
	double sigma4_meno_a4v[n],sigma4_log_c4v[n],sigma4_log_delta4v[n];
	double a_4=0, c_4=0, delta_4=0;
	for(int i=0; i<n; i++)
	{
	    sigma4_meno_a4v[i]=    sigma4_meno_a4[i]*x[i];
	    sigma4_log_c4v[i]=    sigma4_log_c4[i]*x[i];
	    sigma4_log_delta4v[i]=sigma4_log_delta4[i]*x[i];
	    
	a_4=a_4+sigma4_meno_a4v[i];
	c_4=c_4+sigma4_log_c4v[i];
	delta_4=delta_4+sigma4_log_delta4v[i];
	}
	

    a_4=-(a_4);
    c_4=exp(c_4);
	delta_4=exp(delta_4);
	
	//a5,c5,delta5
	double sigma5_meno_a5v[n],sigma5_log_c5v[n],sigma5_log_delta5v[n];
	double a_5=0, c_5=0, delta_5=0;	
	for(int i=0; i<n; i++)
	{
	    sigma5_meno_a5v[i]=    sigma5_meno_a5[i]*x[i];
	    sigma5_log_c5v[i]=    sigma5_log_c5[i]*x[i];
	    sigma5_log_delta5v[i]=sigma5_log_delta5[i]*x[i];
	    
	a_5=a_5+sigma5_meno_a5v[i];
	c_5=c_5+sigma5_log_c5v[i];
	delta_5=delta_5+sigma5_log_delta5v[i];
	}
		
    a_5=-(a_5);
    c_5=exp(c_5);
	delta_5=exp(delta_5);
		
	//a6,c6,delta6
	double sigma6_a6v[n],sigma6_log_c6v[n],sigma6_log_delta6v[n];
	double a_6=0, c_6=0, delta_6=0;
	for(int i=0; i<n; i++)
	{
	    sigma6_a6v[i]=    sigma6_a6[i]*x[i];
	    sigma6_log_c6v[i]=    sigma6_log_c6[i]*x[i];
	    sigma6_log_delta6v[i]=sigma6_log_delta6[i]*x[i];
	    
	a_6=a_6+sigma6_a6v[i];
	c_6=c_6+sigma6_log_c6v[i];
	delta_6=delta_6+sigma6_log_delta6v[i];


	}
		

    c_6=exp(c_6);
	delta_6=exp(delta_6);
	
	
	//a7,c7,delta7
	double sigma7_log_c7v[n],sigma7_log_delta7v[n];
	double a_7=0, c_7=0, delta_7=0;
	for(int i=0; i<n; i++)
	{

	    sigma7_log_c7v[i]=    sigma7_log_c7[i]*x[i];
	    sigma7_log_delta7v[i]=sigma7_log_delta7[i]*x[i];
	    

	c_7=c_7+sigma7_log_c7v[i];
	delta_7=delta_7+sigma7_log_delta7v[i];


	}
		
    a_7=a_3+a_4+a_5-a_1-a_2-a_6;
    c_7=exp(c_7);
	delta_7=exp(delta_7);
	
	


		
	//Definizioni q
	double eps0=a_0-c_0*exp(-pow(log(T)/delta_0,w_0));
	
	double q1=(T-c_1)/delta_1;
	double q2=(T-c_2)/delta_2;
	double q3=(T-c_3)/delta_3;
	double q4=(T-c_4)/delta_4;
	double q5=(T-c_5)/delta_5;
	double q6=(T-c_6)/delta_6;
	double q7=(T-c_7)/delta_7;
	

	double q[7]={q1,q2,q3,q4,q5,q6,q7};
    
	//Definizione sigma e gamma
	double sigma[7];
	
	for (int j=0; j<7; j++)
	{
		sigma[j]=exp(q[j])/(exp(q[j])+exp(-q[j]));

	}
	

	

	
	//Definizione a aa
	double a[7]={a_1,a_2,a_3,a_4,a_5,a_6,a_7};
	
	//CALCOLO Kappa
	
	double z=0; 
	
	for (int i=0; i<7; i++)
	{
		z=z+a[i]*sigma[i];
	}
	
	
	double log_sigma_elec=eps0+z;	
	

	
	scalar Sigma=exp(log_sigma_elec);
	
	

