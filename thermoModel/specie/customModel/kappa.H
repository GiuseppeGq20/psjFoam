//Thermal Conductivity [W/(K m)]
// il codice vuole p in atm e T in K

	const int n=4;  //numero elementi di x
    double patm=p/101325;
	double Tlog=log(T);	
	
    //Coef Tab 25
	double x[n]={pow(log(patm),0), pow(log(patm),1), pow(log(patm),2), pow(log(patm),3)};
	
	double  a0[n]={-1.283401e+1,0,0,0};
    
	double sigma1_a1[n]=		{1.991839e+1,0,0,0};	
	double sigma1_c1[n]=		{6.622230,0,0,0};	
	double sigma1_delta1[n]= {1.184624e+1,0,0,0};
	
	double sigma2_log_a2[n]=		{7.133981e-1, -2.282818e-2, 5.491632e-4, 0};	
	double sigma2_log_c2[n]=		{2.080280, 7.242844e-3, 1.959358e-4, 0};	
	double sigma2_log_delta2[n]= {-1.421111, 7.326017e-2, 1.685275e-3, 0};

	double sigma3_log_meno_a3[n]=		{8.309337e-1, -2.699607e-3, 2.836175e-3, 0};	
	double sigma3_log_c3[n]=				{2.114417, 6.588084e-3, 1.041527e-4, 0};	
	double sigma3_log_delta3[n]= 		{-1.873926, 7.669056e-2, 4.311158e-3, 0};
	
	double sigma4_log_a4[n]=				{5.566144e-1, 1.402546e-1, -4.355200e-3, 1.422302e-4};	
	double sigma4_log_c4[n]=				{2.275814, 2.789634e-3, 1.613876e-4, 0};	
	double sigma4_log_delta4[n]= 		{-1.078759, 1.962265e-2, -8.795026e-3, 5.277830e-4};
	
		
	double sigma5_log_a5[n]=				{-1.893687, 3.628971e-2, 9.796743e-3, 0};	
	double sigma5_log_c5[n]=				{2.361178, 6.072448e-3, -1.995121e-5, 0};	
	double sigma5_log_delta5[n]= 		{-1.820338, 1.075866e-1, 0,0};	
	
	double sigma6_log_a6[n]=				{1.153927, -1.647523e-2, -2.502041e-3, 0};	
	double sigma6_log_c6[n]=				{2.467469, 5.822255e-3, 0, 0};	
	double sigma6_log_delta6[n]= 		{-2.830928e-2, -2.218935e-2, -2.718760e-3,0};	
	
	
	double gamma7_log_a7[n]=				{-1.700917e+2, -2.131620e+1, -3.099200, 0};	
	double gamma7_log_c7[n]=				{2.061427, 1.117607e-3, -3.916231e-4,0};	
	double gamma7_log_delta7[n]= 		{-3.290998e+1, -3.353576, -5.634466e-1,0};
	

	double gamma8_log_meno_a8[n]=		{-1.456072e-1, -1.437036e-1, -1.480764e-3, 0};	
	double gamma8_log_c8[n]=				{2.205458, 6.659429e-3, 1.324918e-4, 0};	
	double gamma8_log_delta8[n]= 		{-1.819779, 3.825355e-3, 1.202891e-3, 0};
	
	double gamma9_log_a9[n]=				{1.055279, -2.677491e-2, 2.446759e-3,0};	
	double gamma9_log_c9[n]=				{2.183883, 5.938113e-3, 1.877191e-4, 4.341127e-6};	
	double gamma9_log_delta9[n]= 		{-9.494270e-1, 3.609984e-2, 1.528015e-3, -9.686251e-5};
	
		
	double gamma10_log_a10[n]=			{2.885339e-1, -7.133722e-2, 2.612269e-4 ,2.585150e-4};	
	double gamma10_log_c10[n]=			{2.255570, 5.826924e-3, -5.486194e-5 ,-1.143664e-5};	
	double gamma10_log_delta10[n]= 		{-1.374699, 2.577156e-2 ,-1.763376e-3,0};	

		
		
	//Calcolo coef


    //a_0
	double a_0= a0[0]*x[0];

	//a1,c1,delta1
	double sigma1_a1v[4],sigma1_c1v[4],sigma1_delta1v[4];
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
	double sigma2_log_a2v[4],sigma2_log_c2v[4],sigma2_log_delta2v[4];
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
	double sigma3_log_meno_a3v[4],sigma3_log_c3v[4],sigma3_log_delta3v[4];
	double a_3=0, c_3=0, delta_3=0;	
	for(int i=0; i<n; i++)
	{
	    sigma3_log_meno_a3v[i]=    sigma3_log_meno_a3[i]*x[i];
	    sigma3_log_c3v[i]=    sigma3_log_c3[i]*x[i];
	    sigma3_log_delta3v[i]=sigma3_log_delta3[i]*x[i];
	    
	    a_3=a_3+sigma3_log_meno_a3v[i];
		c_3=c_3+sigma3_log_c3v[i];
		delta_3=delta_3+sigma3_log_delta3v[i];	
	}
	
    a_3=-exp(a_3);
    c_3=exp(c_3);
	delta_3=exp(delta_3);

	
	
	//a4,c4,delta4
	double sigma4_log_a4v[4],sigma4_log_c4v[4],sigma4_log_delta4v[4];
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
	double sigma5_log_a5v[4],sigma5_log_c5v[4],sigma5_log_delta5v[4];
	double a_5=0, c_5=0, delta_5=0;	
	for(int i=0; i<n; i++)
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
	double sigma6_log_a6v[4],sigma6_log_c6v[4],sigma6_log_delta6v[4];
	double a_6=0, c_6=0, delta_6=0;
	for(int i=0; i<n; i++)
	{
	    sigma6_log_a6v[i]=    sigma6_log_a6[i]*x[i];
	    sigma6_log_c6v[i]=    sigma6_log_c6[i]*x[i];
	    sigma6_log_delta6v[i]=sigma6_log_delta6[i]*x[i];
	    
	a_6=a_6+sigma6_log_a6v[i];
	c_6=c_6+sigma6_log_c6v[i];
	delta_6=delta_6+sigma6_log_delta6v[i];


	}
		
	a_6=exp(a_6);
    c_6=exp(c_6);
	delta_6=exp(delta_6);
	
	
	//a7,c7,delta7
	double gamma7_log_a7v[4],gamma7_log_c7v[4],gamma7_log_delta7v[4];
	double a_7=0, c_7=0, delta_7=0;
	for(int i=0; i<n; i++)
	{
	    gamma7_log_a7v[i]=    gamma7_log_a7[i]*x[i];
	    gamma7_log_c7v[i]=    gamma7_log_c7[i]*x[i];
	    gamma7_log_delta7v[i]=gamma7_log_delta7[i]*x[i];
	    
	a_7=a_7+gamma7_log_a7v[i];
	c_7=c_7+gamma7_log_c7v[i];
	delta_7=delta_7+gamma7_log_delta7v[i];


	}
		
    a_7=exp(a_7);
    c_7=exp(c_7);
	delta_7=exp(delta_7);
	
	//a8,c8,delta8
	double gamma8_log_meno_a8v[4],gamma8_log_c8v[4],gamma8_log_delta8v[4];
	double a_8=0, c_8=0, delta_8=0;
	for(int i=0; i<n; i++)
	{
	    gamma8_log_meno_a8v[i]=    gamma8_log_meno_a8[i]*x[i];
	    gamma8_log_c8v[i]=    gamma8_log_c8[i]*x[i];
	    gamma8_log_delta8v[i]=gamma8_log_delta8[i]*x[i];
	    
	a_8=a_8+gamma8_log_meno_a8v[i];
	c_8=c_8+gamma8_log_c8v[i];
	delta_8=delta_8+gamma8_log_delta8v[i];


	}	

    a_8=-exp(a_8);
    c_8=exp(c_8);
	delta_8=exp(delta_8);

	//a9,c9,delta9
	double gamma9_log_a9v[4],gamma9_log_c9v[4],gamma9_log_delta9v[4];
	double a_9=0, c_9=0, delta_9=0;
	for(int i=0; i<n; i++)
	{
	    gamma9_log_a9v[i]=    gamma9_log_a9[i]*x[i];
	    gamma9_log_c9v[i]=    gamma9_log_c9[i]*x[i];
	    gamma9_log_delta9v[i]=gamma9_log_delta9[i]*x[i];
	    
	a_9=a_9+gamma9_log_a9v[i];
	c_9=c_9+gamma9_log_c9v[i];
	delta_9=delta_9+gamma9_log_delta9v[i];


	}	
	
    a_9=exp(a_9);
    c_9=exp(c_9);
	delta_9=exp(delta_9);
	
	
	//a10,c10,delta10
	double gamma10_log_a10v[4],gamma10_log_c10v[4],gamma10_log_delta10v[4];
	double a_10=0, c_10=0, delta_10=0;
	for(int i=0; i<n; i++)
	{
	    gamma10_log_a10v[i]=    gamma10_log_a10[i]*x[i];
	    gamma10_log_c10v[i]=    gamma10_log_c10[i]*x[i];
	    gamma10_log_delta10v[i]=gamma10_log_delta10[i]*x[i];
	    
   	a_10=a_10+gamma10_log_a10v[i];
	c_10=c_10+gamma10_log_c10v[i];
	delta_10=delta_10+gamma10_log_delta10v[i];

	}
	
	
    a_10=exp(a_10);
    c_10=exp(c_10);
	delta_10=exp(delta_10);
	


		
	//Definizioni q
	
	double q1=(Tlog-c_1)/delta_1;
	double q2=(Tlog-c_2)/delta_2;
	double q3=(Tlog-c_3)/delta_3;
	double q4=(Tlog-c_4)/delta_4;
	double q5=(Tlog-c_5)/delta_5;
	double q6=(Tlog-c_6)/delta_6;
	double q7=(Tlog-c_7)/delta_7;
	double q8=(Tlog-c_8)/delta_8;
	double q9=(Tlog-c_9)/delta_9;
	double q10=(Tlog-c_10)/delta_10;


	double q[6]={q1,q2,q3,q4,q5,q6}, qq[4]={q7,q8,q9,q10};
    
	//Definizione sigma e gamma
	double sigma[6], gamma[4];
	
	for (int j=0; j<6; j++)
	{
		sigma[j]=exp(q[j])/(exp(q[j])+exp(-q[j]));

	}
	
	for (int j=0; j<4; j++)
	{
		gamma[j]=exp(-pow(qq[j],2));
	}
	

	
	//Definizione a aa
	double a[6]={a_1,a_2,a_3,a_4,a_5,a_6}, aa[4]={a_7,a_8,a_9,a_10};
	
	//CALCOLO Kappa
	
	double z=0, h=0; 
	
	for (int i=0; i<6; i++)
	{
		z=z+a[i]*sigma[i];
	}
	
	for (int i=0; i<4; i++)
	{
		h=h+aa[i]*gamma[i];
	}
	
	double log_k=a_0+z+h;	
	
	double kappa=exp(log_k);
	
