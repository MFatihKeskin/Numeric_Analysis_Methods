/*
	Description: Bisection Method
	Copyright: Muhammet Fatih KESKIN - 2019
*/

#include<stdio.h>
#include <stdlib.h> 
#include<math.h>//for pow
//#define f(x) pow(x,3)+4*pow(x,2)-10

float fonk(double x){//only function
	float y;
	y=pow(x,3)+4*pow(x,2)-10;
	return y;
}
float fonk1(double x1){//printing function output
	float y1;
	y1=pow(x1,3)+4*pow(x1,2)-10;
	printf("y(%f)= %f\n",x1,y1);
	return y1;
}

int main(){
	int i,iterasyon=1;
	float a=1;
	float b=2;
	float x,y,x1,y1,p,d,k,l,m,n,r,s,q;
	float err;//relative error
	float tolerans=0.001;// identified tolerance
	printf("\n\t\t\t~~~~~~~~BISECTION METHOD~~~~~~~~\n\n");//description
	printf("\t\t\t####f(x) = x*x*x + 4*x*x - 10####\n");//function
	printf("\t\t\t---------------------------------\n\n");//parenthesis
	p=(a+b)/2;	//midpoint finding			
	err = (p-b)/p; //relative error finding
	q=fonk(a)*fonk(p);//multiplying of two functions
	fonk1(a);//calculate a and print 
	fonk1(b);//calculate b and print 
	printf("p =((%f+%f)/2) = %f\n",a,b,p);fonk1(p);
	
	if(err<0){	//A simple absolute value function
		err = err*-1;
		printf("Relative Error= %f\n",err);
	}
	else{
		printf("Relative Error%d = %f\n",err);
	}
	puts("");//for space
	printf("~~iterasyon=%d\n~~An=%f\n~~Bn=%f\n~~f(An)=%f\n~~f(Pn)=%f\n~~Relative Error= %f\n\n",iterasyon,a,b,fonk(a),fonk(p),err);
	//for the desired table for all value
	printf("------------------------------------------\n");
	if(err>tolerans){//our error value should be less than the identified tolerance
	for(i=1;err>tolerans;i++){
		if(q<0){// if function multiplications less than zero, entering the loop
		b=p;
	}
		else{
			a=p;
		}
		p=(a+b)/2;//midpoint finding		
		err = fabs((p-b)/p);//I get an absolute value with a single command instead of a function like the one above.
		q = fonk(a)*fonk(p);//multiplying of two functions
		fonk1(a);//calculate a and print 
		fonk1(b);//calculate b and print 
		printf("p =((%f+%f)/2) = %f\n",a,b,p);fonk1(p);//calculate and print
		printf("Relative Error= %f\n",err);puts("");
		printf("~~iterasyon=%d\n~~An=%f\n~~Bn=%f\n~~Pn=%f\n~~f(An)=%f\n~~f(Pn)=%f\n~~Relative Error= %f\n\n",iterasyon+1,a,b,p,fonk(a),fonk(p),err);
		//for the desired table for all value
		printf("------------------------------------------\n");
		if(err<tolerans){//to determine the number of iterations
		printf("%d. Iterasyon sonucunda 0.001 tolerans ile kok degerine ulasildi",i+1);}
		iterasyon++;
//		until (err<=tolerans);
		}
	}
	else{//no gap in wrong range selection
		printf("Girilen [a,b] araliginda kok yoktur..");
	}
	return 0;}
