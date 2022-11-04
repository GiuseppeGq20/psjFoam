// Specific Heat [cal/(gK)]
		
    double patm=p/101325;
	const int n=7;  //numero elementi di x



	//Coef Tab 25
	double x[n]={pow(log(patm),0), pow(log(patm),1), pow(log(patm),2), pow(log(patm),3), pow(log(patm),4), pow(log(patm),5),pow(log(patm),6)};

	double  pc0[n]={4.303513e-3, 6.487052e-2, -6.616517e-3, 2.391262e-4,0,0,0};
	double  pc1[n]={-2.472201e-5, 1.865503e-5, -1.298963e-6,0,0,0,0};

	double sigma1_log_a1[n]=		{-3.497916e-1, -2.900058e-1, -3.839544e-2, -6.284876e-3, -4.130292e-4,0,0};	
	double sigma1_log_c1[n]=		{1.008338e+1, 8.730410e-2, 8.590102e-3, 5.892083e-4,0,0,0};	
	double sigma1_log_delta1[n]= {8.043134, 3.294414e-1, 4.681080e-2, -1.509745e-3, -4.534410e-4,0,0};
	
	double sigma2_log_a2[n]=		{-2.305816, 9.286290e-2, -1.095463e-2, -1.929857e-3, -2.358095e-4,0,0};	
	double sigma2_log_c2[n]=		{7.803107, 6.576559e-2, 1.214098e-4, -2.773380e-4,0,0,0};	
	double sigma2_log_delta2[n]= {6.212416, 1.085758e-1, -1.459860e-2, 4.297049e-4,0,0,0};

	double sigma3_log_a3[n]=		{1.885717e+1, 1.564732e+1, 3.946648, 2.094257e-1, -4.423704e-2,-5.854376e-3, -1.750164e-4};	
	double sigma3_log_c3[n]=				{1.174382e+1, 1.351866e-1, -5.421755e-2, -1.623227e-2, 7.438041e-4,4.977237e-4, 3.456374e-5};	
	double sigma3_log_delta3[n]= 		{6.596434, -5.025506, -3.238969, -6.901133e-1, -1.855573e-2,8.925939e-3, 7.161553e-4};
		
		
	double sigma4_log_a4[n]=				{9.844680e-1, -2.553591e-1, -8.898889e-3, 1.493946e-3, 6.005988e-5,0,0};	
	double sigma4_log_c4[n]=				{1.052223e+1, 8.741211e-3, -2.198211e-4,0,0,0,0};	
	double sigma4_log_delta4[n]= 		{9.241400, -6.373646e-2, -7.339952e-3, 5.024652e-4,0,0,0};
	
		
	double sigma5_log_a5[n]=				{4.664598e-1, -2.233574e-1, -1.441672e-2, -1.177062e-3, -6.026800e-5,0,0};	
	double sigma5_log_c5[n]=				{8.854075, 5.131262e-2, 1.507223e-3, 3.158892e-4,0,0,0};	
	double sigma5_log_delta5[n]= 		{8.973554, 1.209818e-2, 2.753489e-3, 2.401117e-4,0,0,0};	
	
	
	
	
	double gamma6_log_a6[n]=				{-8.639771e-1, -2.135237e-1, -1.735545e-2, -1.885139e-3, -1.226041e-4,0,0};	
	double gamma6_log_c6[n]=				{8.164620, 5.272624e-2, 5.356645e-4, -4.303413e-5,0,0,0};	
	double gamma6_log_delta6[n]= 		{6.414342, 7.141268e-2, -3.184188e-3, -3.896052e-4,0,0,0};	
	
	
	double gamma7_log_a7[n]=				{ 9.596448e-1, -1.130686e-1, -2.461674e-3, 4.743607e-5,0,0,0};	
	double gamma7_log_c7[n]=				{8.857074, 5.974192e-2, 1.621499e-3, 2.811880e-5,0,0,0};	
	double gamma7_log_delta7[n]= 		{7.031326, 9.966653e-2, 2.637695e-3, -3.740228e-5,0,0,0};


	double gamma8_log_a8[n]=		{1.431534, -1.255579e-1, -5.407784e-3, -4.894608e-4,0,0, 0};	
	double gamma8_log_c8[n]=				{9.598608, 7.030841e-2, 9.720862e-4, -8.467979e-5,0,0, 0};	
	double gamma8_log_delta8[n]= 		{7.915774, 9.011657e-2, -7.629395e-4, -1.579088e-4,0,0, 0};	

	
	
	double gamma9_log_a9[n]=				{1.658985, -1.098660e-1, -7.382403e-3, -1.597338e-3, -1.259823e-4,0,0};	
	double gamma9_log_c9[n]=				{1.030698e+1, 6.396773e-2, 1.387554e-3, 5.277379e-5,0,0,0};	
	double gamma9_log_delta9[n]= 		{8.306511, 8.714253e-2, 6.812322e-4,0,0,0,0};
	
		
	double gamma10_log_a10[n]=			{1.638978, -1.238859e-1, -3.036868e-3, -1.130285e-3, -1.070291e-4,0,0};	
	double gamma10_log_c10[n]=			{1.076627e+1, 6.602355e-2, 1.098331e-3, -2.395208e-5,0,0,0};	
	double gamma10_log_delta10[n]= 		{8.764870, 1.276501e-1, -5.083689e-4, -7.452322e-4, 2.885332e-5,0,0};	
	
	double gamma11_log_a11[n]=			{1.933029, -1.248750e-1, -1.646256e-2, 5.253210e-4, 3.143929e-4,0,0};	
	double gamma11_log_c11[n]=			{1.109308e+1, 5.876202e-2, 1.243864e-3, 3.958414e-5,0,0,0};	
	double gamma11_log_delta11[n]= 		{8.959570, 1.014329e-1, 1.073510e-2, -1.155143e-3, -2.731432e-4,0,0};	


	//Calcolo coef

    //c0 c1
	double pc0v[n],pc1v[n];
	double pc_0=0, pc_1=0;
	
	for(int i=0; i<n; i++)
	{
	    pc0v[i]=    pc0[i]*x[i];
	    pc1v[i]=    pc1[i]*x[i];
	     
	    pc_0=pc_0+pc0v[i];
	    pc_1=pc_1+pc1v[i];
	    
	}

	//a1,c1,delta1
	double sigma1_a1v[n],sigma1_c1v[n],sigma1_delta1v[n];
	double a_1=0, c_1=0, delta_1=0;
	
	for(int i=0; i<n; i++)
	{
	    sigma1_a1v[i]=    sigma1_log_a1[i]*x[i];
	    sigma1_c1v[i]=    sigma1_log_c1[i]*x[i];
	    sigma1_delta1v[i]=sigma1_log_delta1[i]*x[i];
	    
	    a_1=a_1+sigma1_a1v[i];
	    c_1=c_1+sigma1_c1v[i];
	    delta_1=delta_1+sigma1_delta1v[i];
	}
	
    a_1=exp(a_1);
    c_1=exp(c_1);
	delta_1=exp(delta_1);

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
	double sigma3_log_a3v[n],sigma3_log_c3v[n],sigma3_log_delta3v[n];
	double a_3=0, c_3=0, delta_3=0;	
	for(int i=0; i<n; i++)
	{
	    sigma3_log_a3v[i]=    sigma3_log_a3[i]*x[i];
	    sigma3_log_c3v[i]=    sigma3_log_c3[i]*x[i];
	    sigma3_log_delta3v[i]=sigma3_log_delta3[i]*x[i];
	    
	    a_3=a_3+sigma3_log_a3v[i];
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
	double gamma6_log_a6v[n],gamma6_log_c6v[n],gamma6_log_delta6v[n];
	double a_6=0, c_6=0, delta_6=0;
	for(int i=0; i<n; i++)
	{
	    gamma6_log_a6v[i]=    gamma6_log_a6[i]*x[i];
	    gamma6_log_c6v[i]=    gamma6_log_c6[i]*x[i];
	    gamma6_log_delta6v[i]=gamma6_log_delta6[i]*x[i];
	    
	a_6=a_6+gamma6_log_a6v[i];
	c_6=c_6+gamma6_log_c6v[i];
	delta_6=delta_6+gamma6_log_delta6v[i];


	}
		
	a_6=exp(a_6);
    c_6=exp(c_6);
	delta_6=exp(delta_6);
	
	
	//a7,c7,delta7
	double gamma7_log_a7v[n],gamma7_log_c7v[n],gamma7_log_delta7v[n];
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
	double gamma8_log_a8v[n],gamma8_log_c8v[n],gamma8_log_delta8v[n];
	double a_8=0, c_8=0, delta_8=0;
	for(int i=0; i<n; i++)
	{
	    gamma8_log_a8v[i]=    gamma8_log_a8[i]*x[i];
	    gamma8_log_c8v[i]=    gamma8_log_c8[i]*x[i];
	    gamma8_log_delta8v[i]=gamma8_log_delta8[i]*x[i];
	    
	a_8=a_8+gamma8_log_a8v[i];
	c_8=c_8+gamma8_log_c8v[i];
	delta_8=delta_8+gamma8_log_delta8v[i];


	}	

    a_8=exp(a_8);
    c_8=exp(c_8);
	delta_8=exp(delta_8);

	//a9,c9,delta9
	double gamma9_log_a9v[n],gamma9_log_c9v[n],gamma9_log_delta9v[n];
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
	double gamma10_log_a10v[n],gamma10_log_c10v[n],gamma10_log_delta10v[n];
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
	
	
	//a11,c11,delta11
	double gamma11_log_a11v[n],gamma11_log_c11v[n],gamma11_log_delta11v[n];
	double a_11=0, c_11=0, delta_11=0;
	for(int i=0; i<n; i++)
	{
	    gamma11_log_a11v[i]=    gamma11_log_a11[i]*x[i];
	    gamma11_log_c11v[i]=    gamma11_log_c11[i]*x[i];
	    gamma11_log_delta11v[i]=gamma11_log_delta11[i]*x[i];
	    
   	a_11=a_11+gamma11_log_a11v[i];
	c_11=c_11+gamma11_log_c11v[i];
	delta_11=delta_11+gamma11_log_delta11v[i];

	}
	
	
    a_11=exp(a_11);
    c_11=exp(c_11);
	delta_11=exp(delta_11);


		
	//Definizioni q
	
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
	double q11=(T-c_11)/delta_11;

	double q[5]={q1,q2,q3,q4,q5}, qq[6]={q6,q7,q8,q9,q10,q11};
    
	//Definizione sigma e gamma
	double sigma[5], gamma[6];
	
	for (int j=0; j<5; j++)
	{
		sigma[j]=exp(q[j])/(exp(q[j])+exp(-q[j]));

	}
	
	for (int j=0; j<6; j++)
	{
		gamma[j]=exp(-pow(qq[j],2));
	}
	

	
	//Definizione a aa
	double a[5]={a_1,a_2,a_3,a_4,a_5}, aa[6]={a_6,a_7,a_8,a_9,a_10,a_11};

	//CALCOLO Kappa
	
	double z=0, h=0; 
	
	for (int i=0; i<5; i++)
	{
		z=z+a[i]*sigma[i];
	}
	
	for (int i=0; i<6; i++)
	{
		h=h+aa[i]*gamma[i];
	}
	
	double cp=pc_0+pc_1*T+z+h;	
			
	double Cp=cp*4.1867999409*1000; // conversion from cal/g*K to J/Kg*K
