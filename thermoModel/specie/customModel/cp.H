// Specific Heat [cal/(gK)]
		
    const scalar patm=p/101325;
	const int n=7;  //numero elementi di x

	//Coef Tab 25
	const scalar x[n]={Foam::pow(Foam::log(patm),0), Foam::pow(Foam::log(patm),1), Foam::pow(Foam::log(patm),2), Foam::pow(Foam::log(patm),3), Foam::pow(Foam::log(patm),4), Foam::pow(Foam::log(patm),5),Foam::pow(Foam::log(patm),6)};

	const scalar  pc0[n]={4.303513e-3, 6.487052e-2, -6.616517e-3, 2.391262e-4,0,0,0};
	const scalar  pc1[n]={-2.472201e-5, 1.865503e-5, -1.298963e-6,0,0,0,0};

	const scalar sigma1_log_a1[n]=		{-3.497916e-1, -2.900058e-1, -3.839544e-2, -6.284876e-3, -4.130292e-4,0,0};	
	const scalar sigma1_log_c1[n]=		{1.008338e+1, 8.730410e-2, 8.590102e-3, 5.892083e-4,0,0,0};	
	const scalar sigma1_log_delta1[n]= {8.043134, 3.294414e-1, 4.681080e-2, -1.509745e-3, -4.534410e-4,0,0};
	
	const scalar sigma2_log_a2[n]=		{-2.305816, 9.286290e-2, -1.095463e-2, -1.929857e-3, -2.358095e-4,0,0};	
	const scalar sigma2_log_c2[n]=		{7.803107, 6.576559e-2, 1.214098e-4, -2.773380e-4,0,0,0};	
	const scalar sigma2_log_delta2[n]= {6.212416, 1.085758e-1, -1.459860e-2, 4.297049e-4,0,0,0};

	const scalar sigma3_log_a3[n]=		{1.885717e+1, 1.564732e+1, 3.946648, 2.094257e-1, -4.423704e-2,-5.854376e-3, -1.750164e-4};	
	const scalar sigma3_log_c3[n]=				{1.174382e+1, 1.351866e-1, -5.421755e-2, -1.623227e-2, 7.438041e-4,4.977237e-4, 3.456374e-5};	
	const scalar sigma3_log_delta3[n]= 		{6.596434, -5.025506, -3.238969, -6.901133e-1, -1.855573e-2,8.925939e-3, 7.161553e-4};
		
	const scalar sigma4_log_a4[n]=				{9.844680e-1, -2.553591e-1, -8.898889e-3, 1.493946e-3, 6.005988e-5,0,0};	
	const scalar sigma4_log_c4[n]=				{1.052223e+1, 8.741211e-3, -2.198211e-4,0,0,0,0};	
	const scalar sigma4_log_delta4[n]= 		{9.241400, -6.373646e-2, -7.339952e-3, 5.024652e-4,0,0,0};
		
	const scalar sigma5_log_a5[n]=				{4.664598e-1, -2.233574e-1, -1.441672e-2, -1.177062e-3, -6.026800e-5,0,0};	
	const scalar sigma5_log_c5[n]=				{8.854075, 5.131262e-2, 1.507223e-3, 3.158892e-4,0,0,0};	
	const scalar sigma5_log_delta5[n]= 		{8.973554, 1.209818e-2, 2.753489e-3, 2.401117e-4,0,0,0};	
	
	const scalar gamma6_log_a6[n]=				{-8.639771e-1, -2.135237e-1, -1.735545e-2, -1.885139e-3, -1.226041e-4,0,0};	
	const scalar gamma6_log_c6[n]=				{8.164620, 5.272624e-2, 5.356645e-4, -4.303413e-5,0,0,0};	
	const scalar gamma6_log_delta6[n]= 		{6.414342, 7.141268e-2, -3.184188e-3, -3.896052e-4,0,0,0};	
	
	const scalar gamma7_log_a7[n]=				{ 9.596448e-1, -1.130686e-1, -2.461674e-3, 4.743607e-5,0,0,0};	
	const scalar gamma7_log_c7[n]=				{8.857074, 5.974192e-2, 1.621499e-3, 2.811880e-5,0,0,0};	
	const scalar gamma7_log_delta7[n]= 		{7.031326, 9.966653e-2, 2.637695e-3, -3.740228e-5,0,0,0};

	const scalar gamma8_log_a8[n]=		{1.431534, -1.255579e-1, -5.407784e-3, -4.894608e-4,0,0, 0};	
	const scalar gamma8_log_c8[n]=				{9.598608, 7.030841e-2, 9.720862e-4, -8.467979e-5,0,0, 0};	
	const scalar gamma8_log_delta8[n]= 		{7.915774, 9.011657e-2, -7.629395e-4, -1.579088e-4,0,0, 0};	
	
	const scalar gamma9_log_a9[n]=				{1.658985, -1.098660e-1, -7.382403e-3, -1.597338e-3, -1.259823e-4,0,0};	
	const scalar gamma9_log_c9[n]=				{1.030698e+1, 6.396773e-2, 1.387554e-3, 5.277379e-5,0,0,0};	
	const scalar gamma9_log_delta9[n]= 		{8.306511, 8.714253e-2, 6.812322e-4,0,0,0,0};
		
	const scalar gamma10_log_a10[n]=			{1.638978, -1.238859e-1, -3.036868e-3, -1.130285e-3, -1.070291e-4,0,0};	
	const scalar gamma10_log_c10[n]=			{1.076627e+1, 6.602355e-2, 1.098331e-3, -2.395208e-5,0,0,0};	
	const scalar gamma10_log_delta10[n]= 		{8.764870, 1.276501e-1, -5.083689e-4, -7.452322e-4, 2.885332e-5,0,0};	
	
	const scalar gamma11_log_a11[n]=			{1.933029, -1.248750e-1, -1.646256e-2, 5.253210e-4, 3.143929e-4,0,0};	
	const scalar gamma11_log_c11[n]=			{1.109308e+1, 5.876202e-2, 1.243864e-3, 3.958414e-5,0,0,0};	
	const scalar gamma11_log_delta11[n]= 		{8.959570, 1.014329e-1, 1.073510e-2, -1.155143e-3, -2.731432e-4,0,0};	

	//Calcolo coef

    //c0 c1
	scalar pc_0=0, pc_1=0;
	for(int i=0; i<n; i++)
	{
	    pc_0+= pc0[i]*x[i];
	    pc_1+= pc1[i]*x[i];
	}

	//a1,c1,delta1
	scalar a_1=0, c_1=0, delta_1=0;
	for(int i=0; i<n; i++)
	{
	    a_1+= sigma1_log_a1[i]*x[i];
	    c_1+= sigma1_log_c1[i]*x[i];
	    delta_1+= sigma1_log_delta1[i]*x[i];
	}
	
    a_1=Foam::exp(a_1);
    c_1=Foam::exp(c_1);
	delta_1=Foam::exp(delta_1);

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
	    a_6+= gamma6_log_a6[i]*x[i];
	    c_6+= gamma6_log_c6[i]*x[i];
	    delta_6+= gamma6_log_delta6[i]*x[i];
	}
		
	a_6=Foam::exp(a_6);
    c_6=Foam::exp(c_6);
	delta_6=Foam::exp(delta_6);
	
	//a7,c7,delta7
	scalar a_7=0, c_7=0, delta_7=0;
	for(int i=0; i<n; i++)
	{
	    a_7+= gamma7_log_a7[i]*x[i];
	    c_7+= gamma7_log_c7[i]*x[i];
	    delta_7+= gamma7_log_delta7[i]*x[i];
	}
		
    a_7=Foam::exp(a_7);
    c_7=Foam::exp(c_7);
	delta_7=Foam::exp(delta_7);
	
	//a8,c8,delta8
	scalar a_8=0, c_8=0, delta_8=0;
	for(int i=0; i<n; i++)
	{
	    a_8+= gamma8_log_a8[i]*x[i];
	    c_8+= gamma8_log_c8[i]*x[i];
	    delta_8+= gamma8_log_delta8[i]*x[i];
	}	

    a_8=Foam::exp(a_8);
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
	
	//a11,c11,delta11
	scalar a_11=0, c_11=0, delta_11=0;
	for(int i=0; i<n; i++)
	{
	    a_11+=    gamma11_log_a11[i]*x[i];
	    c_11+=    gamma11_log_c11[i]*x[i];
	    delta_11+=gamma11_log_delta11[i]*x[i];
	}
	
    a_11=Foam::exp(a_11);
    c_11=Foam::exp(c_11);
	delta_11=Foam::exp(delta_11);

	//Definizioni q
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
	const scalar q11=(T-c_11)/delta_11;

	const scalar q[5]={q1,q2,q3,q4,q5}, qq[6]={q6,q7,q8,q9,q10,q11};

    /*for (int i=0; i<5; i++)
    {
        Info<<" q"<<i<<": "<<q[i]; 
    }
    for (int i=0; i<6; i++)
    {
        Info<<" qq"<<i<<": "<<qq[i]; 
    }
    Info<<endl;
	*/
    
    //Definizione sigma e gamma
    const scalar maxValue=-100.0; // for q<-2.5 the sigmoid is less than 7e-3
	scalar sigma[5], gamma[6];
	for (int j=0; j<5; j++)
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

	for (int j=0; j<6; j++)
	{
		gamma[j]=Foam::exp(-Foam::pow(qq[j],2));
	}
	
	//Definizione a aa
	scalar a[5]={a_1,a_2,a_3,a_4,a_5}, aa[6]={a_6,a_7,a_8,a_9,a_10,a_11};
	//CALCOLO Cp
	scalar z=0.0, h=0.0; 
	for (int i=0; i<5; i++)
	{
		z=z+a[i]*sigma[i];
	}
	
	for (int i=0; i<6; i++)
	{
		h=h+aa[i]*gamma[i];
	}
	
	const scalar cp=pc_0+pc_1*T+z+h;	
	const scalar Cp=cp*4.1867999409*1000; // conversion from cal/g*K to J/Kg*K
