
/* NOTE
 * in the openfoam implementation of the D'angola model we left out the
 * seventh sigmoid function (sigma_7) for the following reasons:
 * - floating point exception in the definition of sigma, precisely at p=1atm:
 *   - c7=497945 
 *   - delta7=0.221389
 *   this lead at T=300K to q7 of orde -2e6, in turn this lead to an exponential of the 
 *   sigmod to give an overflow error
 * - on a physical stand point the sigma_7 is relevant for temperature of order
 *   5e5 K, and these temperature are outside the range of interest for the plasma
 *   in the psj actuator
 */
//Specific entalpy [cal/g]
// il codice vuole p in atm e T in K

	const int n=10;  //numero elementi di x
    
    const double patm=p/101325.0;

	const double x[n]={1.0, pow(log(patm),1), pow(log(patm),2), pow(log(patm),3), pow(log(patm),4), pow(log(patm),5), pow(log(patm),6), pow(log(patm),7), pow(log(patm),8), pow(log(patm),9)};

	const double  pc1[n]={2.350912e-1, -1.120236e-3, -2.508755e-5,0,0,0,0,0,0,0};
	const double  pc2[n]={1.542966e-5, 6.556647e-7,0,0,0,0,0,0,0,0};

	const double sigma1_log_a1[n]=		{6.587335, -6.112145e-2, -9.108114e-3, -9.569561e-4, -1.128838e-4, -8.757988e-6,0,0,0,0};	
	const double sigma1_log_c1[n]=		{8.164839, 5.283021e-2, 4.741812e-4, -1.276598e-4, -9.877950e-6,0,0,0,0,0};	
	const double sigma1_log_delta1[n]= {6.513247, 1.040239e-1, -8.104042e-4, -2.991537e-4, 4.348437e-5, 6.258153e-6,0,0,0,0};
	
	const double sigma2_log_a2[n]=		{8.740885, 3.050736e-3, 1.599171e-3, -2.859059e-4, -5.371695e-5,0,0,0,0,0};	
	const double sigma2_log_c2[n]=		{8.856133, 5.964702e-2, 1.745638e-3, 2.343688e-5, -3.102821e-6,0,0,0,0,0};
	const double sigma2_log_delta2[n]= {6.981907, 1.119408e-1, 4.185626e-3, -2.499247e-4, -5.209456e-5,0,0,0,0,0};

	const double sigma3_log_a3[n]=		{1.014496e+1, -1.833015e-2, -4.265166e-3, -8.321612e-4, -6.481810e-5,0,0,0,0,0};	
	const double sigma3_log_c3[n]=				{9.593196, 7.089945e-2, 1.640521e-3, -1.055407e-4, -1.510653e-5,0,0,0,0,0};	
	const double sigma3_log_delta3[n]= 		{7.910995, 1.006930e-1, -1.608832e-3, -2.526731e-4,0,0,0,0,0,0};
		
	const double sigma4_log_a4[n]=				{1.082665e+1, -4.777223e-2, -4.682547e-3,0,0,0,0,0,0,0};	
	const double sigma4_log_c4[n]=				{1.030572e+1, 6.607308e-2, 1.512694e-3, -5.009486e-5, -5.192881e-6, 1.116840e-6,0,0,0,0};	
	const double sigma4_log_delta4[n]= 		{8.320951, 7.474585e-2, 1.789257e-3, 5.273341e-4, 3.755570e-5, 3.425485e-6,0,0,0,0};
		
	const double sigma5_log_a5[n]=				{1.145937e+1, 5.122940e-4, -8.805300e-3, -1.193042e-3,0,0,0,0,0,0};	
	const double sigma5_log_c5[n]=				{1.076031e+1, 6.404003e-2, 9.621465e-4, -1.883920e-5,0,0,0,0,0,0};	
	const double sigma5_log_delta5[n]= 		{8.846750, 1.307197e-1, -2.943134e-4, -6.425060e-4,0,0,0,0,0,0};	
	
	const double sigma6_log_a6[n]=				{1.172458e+1, -5.461477e-2, 3.413385e-3, 7.407737e-4, -1.644220e-4, -1.878043e-5,0,0,0,0};	
	const double sigma6_log_c6[n]=				{1.109244e+1, 6.026294e-2, 1.125935e-3, -2.170126e-5, -3.141895e-6,0,0,0,0,0};	
	const double sigma6_log_delta6[n]= 		{8.942747, 8.687938e-2, 1.554323e-2, 3.584506e-5, -2.447405e-4,0,0,0,0,0};	
	
	const double sigma7_log_a7[n]=				{ -1.011841e+1, -2.295953e+1, -1.220667e+1, -3.504472, -4.373233e-1, 1.127311e-2,6.598926e-3,-2.119755e-4,-1.369506e-4,-8.311253e-6};
	const double sigma7_log_c7[n]=				{1.314544e+1, 2.079129, 9.992304e-1, 2.223931e-1, 1.963954e-2, -1.622592e-4,-1.094608e-5,2.304744e-5,1.817656e-6,0};	
	const double sigma7_log_delta7[n]= 		{-1.743314, -1.807206e+1, -1.393980e+1, -5.232064, -7.607736e-1, 8.529592e-2,4.967101e-2,7.733746e-3,5.507513e-4,1.527569e-5};
	
	//Calcolo coef

	double pc_1=0.0, pc_2=0.0;
	
	for(int i=0; i<n; i++)
	{
	    pc_1+=pc1[i]*x[i];
	    pc_2+=pc2[i]*x[i];
	    
	}

	//a1,c1,delta1
	double a_1=0.0, c_1=0.0, delta_1=0.0;
	for(int i=0; i<n; i++)
	{
	    a_1+=sigma1_log_a1[i]*x[i];
	    c_1+=sigma1_log_c1[i]*x[i];
	    delta_1+= sigma1_log_delta1[i]*x[i];
	}
	
    a_1=exp(a_1);
    c_1=exp(c_1);
	delta_1=exp(delta_1);

	//a2,c2,delta2
	double a_2=0, c_2=0, delta_2=0;	
	for(int i=0; i<n; i++)
	{
	    a_2+=sigma2_log_a2[i]*x[i];
	    c_2+=sigma2_log_c2[i]*x[i];
	    delta_2+=sigma2_log_delta2[i]*x[i];
	    
	}
		
    a_2=exp(a_2);
    c_2=exp(c_2);
	delta_2=exp(delta_2);
	
	//a3,c3,delta3
	double a_3=0.0, c_3=0.0, delta_3=0.0;	
	for(int i=0; i<n; i++)
	{
	    a_3+=sigma3_log_a3[i]*x[i];
	    c_3+=sigma3_log_c3[i]*x[i];
	    delta_3+=sigma3_log_delta3[i]*x[i];
	}
	
    a_3=exp(a_3);
    c_3=exp(c_3);
	delta_3=exp(delta_3);

	
	
	//a4,c4,delta4
	double a_4=0.0, c_4=0.0, delta_4=0.0;
	for(int i=0; i<n; i++)
	{
	    a_4+= sigma4_log_a4[i]*x[i];
	    c_4+= sigma4_log_c4[i]*x[i];
	    delta_4+= sigma4_log_delta4[i]*x[i];
	}
	

    a_4=exp(a_4);
    c_4=exp(c_4);
	delta_4=exp(delta_4);
	
	//a5,c5,delta5
	double a_5=0.0, c_5=0.0, delta_5=0.0;	
	for(int i=0; i<n; i++)
	{
	    a_5+=    sigma5_log_a5[i]*x[i];
	    c_5+=    sigma5_log_c5[i]*x[i];
	    delta_5+=sigma5_log_delta5[i]*x[i];
	}
		
    a_5=exp(a_5);
    c_5=exp(c_5);
	delta_5=exp(delta_5);
		
	//a6,c6,delta6
	double a_6=0.0, c_6=0.0, delta_6=0.0;
	for(int i=0; i<n; i++)
	{
	    a_6+= sigma6_log_a6[i]*x[i];
	    c_6+= sigma6_log_c6[i]*x[i];
	    delta_6+=sigma6_log_delta6[i]*x[i];
	}
		
	a_6=exp(a_6);
    c_6=exp(c_6);
	delta_6=exp(delta_6);
	
	
	//a7,c7,delta7
	double a_7=0.0, c_7=0.0, delta_7=0.0;
	for(int i=0; i<n; i++)
	{
	    a_7+=    sigma7_log_a7[i]*x[i];
	    c_7+=    sigma7_log_c7[i]*x[i];
	    delta_7+= sigma7_log_delta7[i]*x[i];
	}
		
    a_7=exp(a_7);
    c_7=exp(c_7);
	delta_7=exp(delta_7);

	//Definizioni q
	const double q1=(T-c_1)/delta_1;
	const double q2=(T-c_2)/delta_2;
	const double q3=(T-c_3)/delta_3;
	const double q4=(T-c_4)/delta_4;
	const double q5=(T-c_5)/delta_5;
	const double q6=(T-c_6)/delta_6;
	//const double q7=(T-c_7)/delta_7;
    
    //const double q[7]={q1,q2,q3,q4,q5,q6,q7};
    const double q[6]={q1,q2,q3,q4,q5,q6};

    //Definizione sigma
    //vedi nota ad inizio file
    //const double sigma[7] {sigma1,sigma2,sigma3,sigma4,sigma5,sigma6,sigma7}; 
    const double sigma[6]= {sigma1,sigma2,sigma3,sigma4,sigma5,sigma6}; 
    for (int j=0; j<6; j++)
	{      
		sigma[j]=exp(q[j])/(exp(q[j])+exp(-q[j]));
	}
	

	//Definizione a 
	const double a[7]={a_1,a_2,a_3,a_4,a_5,a_6,a_7};
	
	//CALCOLO H
	
	double z=pc_1*T+pc_2*pow(T,2); 
	
	for (int i=0; i<7; i++)
	{
		z+=a[i]*sigma[i];
	}
	
     double H=z*4.1867999409*1000.0; // conversion from cal/g to J/Kg


