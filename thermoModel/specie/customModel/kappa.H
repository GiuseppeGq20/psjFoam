//Thermal Conductivity [W/(K m)]
// il codice vuole p in atm e T in K

	const int n=4;  //numero elementi di x
    const scalar patm=p/101325;
	const scalar Tlog=Foam::log(T);	
	
    //Coef Tab 25
	const scalar x[n]={Foam::pow(Foam::log(patm),0), Foam::pow(Foam::log(patm),1), Foam::pow(Foam::log(patm),2), Foam::pow(Foam::log(patm),3)};
	
	const scalar  a0=-1.283401e+1;
    
	const scalar sigma1_a1=		1.991839e+1;	
	const scalar sigma1_c1=		6.622230;	
	const scalar sigma1_delta1= 1.184624e+1;
	
	const scalar sigma2_log_a2[n]=		{7.133981e-1, -2.282818e-2, 5.491632e-4, 0};	
	const scalar sigma2_log_c2[n]=		{2.080280, 7.242844e-3, 1.959358e-4, 0};	
	const scalar sigma2_log_delta2[n]= {-1.421111, 7.326017e-2, 1.685275e-3, 0};

	const scalar sigma3_log_meno_a3[n]=		{8.309337e-1, -2.699607e-3, 2.836175e-3, 0};	
	const scalar sigma3_log_c3[n]=				{2.114417, 6.588084e-3, 1.041527e-4, 0};	
	const scalar sigma3_log_delta3[n]= 		{-1.873926, 7.669056e-2, 4.311158e-3, 0};
	
	const scalar sigma4_log_a4[n]=				{5.566144e-1, 1.402546e-1, -4.355200e-3, 1.422302e-4};	
	const scalar sigma4_log_c4[n]=				{2.275814, 2.789634e-3, 1.613876e-4, 0};	
	const scalar sigma4_log_delta4[n]= 		{-1.078759, 1.962265e-2, -8.795026e-3, 5.277830e-4};
	
		
	const scalar sigma5_log_a5[n]=				{-1.893687, 3.628971e-2, 9.796743e-3, 0};	
	const scalar sigma5_log_c5[n]=				{2.361178, 6.072448e-3, -1.995121e-5, 0};	
	const scalar sigma5_log_delta5[n]= 		{-1.820338, 1.075866e-1, 0,0};	
	
	const scalar sigma6_log_a6[n]=				{1.153927, -1.647523e-2, -2.502041e-3, 0};	
	const scalar sigma6_log_c6[n]=				{2.467469, 5.822255e-3, 0, 0};	
	const scalar sigma6_log_delta6[n]= 		{-2.830928e-2, -2.218935e-2, -2.718760e-3,0};	
	
	
	const scalar gamma7_log_a7[n]=				{-1.700917e+2, -2.131620e+1, -3.099200, 0};	
	const scalar gamma7_log_c7[n]=				{2.061427, 1.117607e-3, -3.916231e-4,0};	
	const scalar gamma7_log_delta7[n]= 		{-3.290998e+1, -3.353576, -5.634466e-1,0};
	

	const scalar gamma8_log_meno_a8[n]=		{-1.456072e-1, -1.437036e-1, -1.480764e-3, 0};	
	const scalar gamma8_log_c8[n]=				{2.205458, 6.659429e-3, 1.324918e-4, 0};	
	const scalar gamma8_log_delta8[n]= 		{-1.819779, 3.825355e-3, 1.202891e-3, 0};
	
	const scalar gamma9_log_a9[n]=				{1.055279, -2.677491e-2, 2.446759e-3,0};	
	const scalar gamma9_log_c9[n]=				{2.183883, 5.938113e-3, 1.877191e-4, 4.341127e-6};	
	const scalar gamma9_log_delta9[n]= 		{-9.494270e-1, 3.609984e-2, 1.528015e-3, -9.686251e-5};
	
		
	const scalar gamma10_log_a10[n]=			{2.885339e-1, -7.133722e-2, 2.612269e-4 ,2.585150e-4};	
	const scalar gamma10_log_c10[n]=			{2.255570, 5.826924e-3, -5.486194e-5 ,-1.143664e-5};	
	const scalar gamma10_log_delta10[n]= 		{-1.374699, 2.577156e-2 ,-1.763376e-3,0};	

		
		
	//Calcolo coef
    //a_0
	const scalar a_0= a0*x[0];

	//a1,c1,delta1
	const scalar a_1=sigma1_a1*x[0];	
	const scalar c_1=sigma1_c1*x[0];	
	const scalar delta_1=sigma1_delta1*x[0];	

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
	    a_3+=    sigma3_log_meno_a3[i]*x[i];
	    c_3+=    sigma3_log_c3[i]*x[i];
	    delta_3+=sigma3_log_delta3[i]*x[i];
	}
	
    a_3=-Foam::exp(a_3);
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
	    a_6+=    sigma6_log_a6[i]*x[i];
	    c_6+=    sigma6_log_c6[i]*x[i];
	    delta_6+=sigma6_log_delta6[i]*x[i];
	}
		
	a_6=Foam::exp(a_6);
    c_6=Foam::exp(c_6);
	delta_6=Foam::exp(delta_6);
	
	
	//a7,c7,delta7
	scalar a_7=0, c_7=0, delta_7=0;
	for(int i=0; i<n; i++)
	{
	    a_7+=    gamma7_log_a7[i]*x[i];
	    c_7+=    gamma7_log_c7[i]*x[i];
	    delta_7+=gamma7_log_delta7[i]*x[i];
	}
    a_7=Foam::exp(a_7);
    c_7=Foam::exp(c_7);
	delta_7=Foam::exp(delta_7);
	
	//a8,c8,delta8
	scalar a_8=0, c_8=0, delta_8=0;
	for(int i=0; i<n; i++)
	{
	    a_8+=    gamma8_log_meno_a8[i]*x[i];
	    c_8+=    gamma8_log_c8[i]*x[i];
	    delta_8+=gamma8_log_delta8[i]*x[i];
	}	
    a_8=-Foam::exp(a_8);
    c_8=Foam::exp(c_8);
	delta_8=Foam::exp(delta_8);

	//a9,c9,delta9
	scalar a_9=0, c_9=0, delta_9=0;
	for(int i=0; i<n; i++)
	{
	    a_9+=    gamma9_log_a9[i]*x[i];
	    c_9+=    gamma9_log_c9[i]*x[i];
	    delta_9+=gamma9_log_delta9[i]*x[i];
	}	
    a_9=Foam::exp(a_9);
    c_9=Foam::exp(c_9);
	delta_9=Foam::exp(delta_9);
	
	//a10,c10,delta10
	scalar a_10=0, c_10=0, delta_10=0;
	for(int i=0; i<n; i++)
	{
	    a_10+=    gamma10_log_a10[i]*x[i];
	    c_10+=    gamma10_log_c10[i]*x[i];
	    delta_10+=gamma10_log_delta10[i]*x[i];
	}
    a_10=Foam::exp(a_10);
    c_10=Foam::exp(c_10);
	delta_10=Foam::exp(delta_10);
	
	//Definizioni q
	const scalar q1=(Tlog-c_1)/delta_1;
	const scalar q2=(Tlog-c_2)/delta_2;
	const scalar q3=(Tlog-c_3)/delta_3;
	const scalar q4=(Tlog-c_4)/delta_4;
	const scalar q5=(Tlog-c_5)/delta_5;
	const scalar q6=(Tlog-c_6)/delta_6;
	const scalar q7=(Tlog-c_7)/delta_7;
	const scalar q8=(Tlog-c_8)/delta_8;
	const scalar q9=(Tlog-c_9)/delta_9;
	const scalar q10=(Tlog-c_10)/delta_10;

	const scalar q[6]={q1,q2,q3,q4,q5,q6}, qq[4]={q7,q8,q9,q10};
    
	//Definizione sigma e gamma
	scalar sigma[6], gamma[4];
	
    const scalar maxValue=-100.0; // for q<-2.5 the sigmoid is less than 7e-3
	
    for (int j=0; j<6; j++)
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
	
	for (int j=0; j<4; j++)
	{
		gamma[j]=Foam::exp(-Foam::pow(qq[j],2));
	}
	
	//Definizione a aa
	scalar a[6]={a_1,a_2,a_3,a_4,a_5,a_6}, aa[4]={a_7,a_8,a_9,a_10};
	
	//CALCOLO Kappa
	
	scalar z=0, h=0; 
	
	for (int i=0; i<6; i++)
	{
		z+=a[i]*sigma[i];
	}
	
	for (int i=0; i<4; i++)
	{
		h+=aa[i]*gamma[i];
	}
	
	const scalar log_k=a_0+z+h;	
	const scalar kappa=Foam::exp(log_k);
	
