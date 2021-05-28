#include <stdio.h>
#include <stdlib.h>
/*
								Name		: MUHAMMET FATİH KESKİN
								Date        : 07.12.19 00:30
								Description : NATURAL CUBİC SPLİNE 
*/
void iter(){
	int i ,j ,iter=20;
    double h[iter+1][8];//h array 
    double x[]={0.9,1.3,1.9,2.1,2.6,3.0,3.9,4.4,4.7,5.0,6.0,7.0,8.0,9.2,10.5,11.3,11.6,12.0,12.6,13.0,13.3};//x array created
    double a[]={1.3,1.5,1.85,2.1,2.6,2.7,2.4,2.15,2.05,2.1,2.25,2.3,2.25,1.95,1.4,0.9,0.7,0.6,0.5,0.4,0.25};//a array created
    
	for (i=0; i<=(iter-1);i++) {//created the first line of h array with for loop
        h[i][1]=(x[i+1]-x[i]);//first column according to the formula given
    }
	
	//I couldn't use single loop because i are not equal for h[i][1] and h[i][2]

    for (i=1;i<=(iter-1);i++) {//created the second line of h array with for loop
        h[i][2]=(((3*(a[i+1]-a[i])/h[i][1]))-(3*(a[i]-a[i-1])/h[i-1][1]));//2nd column according to the formula given
    }
    //given equations(I don't know why it's written)
	h[0][3]=1;
    h[0][4]=0;
    h[0][5]=0;
    
	for (i=1;i<=(iter-1);i++) {//I used a single loop because i are equal
        h[i][3]=2*(x[i+1]-x[i-1])-(h[i-1][1]*h[i-1][4]);//created the third line of h array with for loop
        h[i][4]=h[i][1]/h[i][3];//created the fourth line of h array with for loop
        h[i][5]=(h[i][2]-(h[i-1][4]*h[i-1][5]))/h[i][3];//created the fiveth line of h array with for loop
    }
    //given equations(I don't know why it's written)
	h[20][4]=1; 
    h[20][5]=0;
    h[20][6]=0;
    
	for (j=(iter-1);j>=0;j--) { //I used a single loop because j are equal
        h[j][6]=h[j][5]-(h[j][4]*h[j+1][6]);
        h[j][7]=(a[j+1]-a[j])/(h[j][1])-(h[j][1]*(h[j+1][6]+2*h[j][6]))/3;
        h[j][8]=(h[j+1][6]-h[j][6])/(3*h[j][1]);
    }
    
    
    for (j=0;j<=iter;j++) {//I wrote the print function separately, but I didn't allocate all the values in that function 
							//because it would extend the code.
    	printf("iter=%d\t",j);//print j
    	printf("\tx(j)=%.2f\t",x[j]);//print xj
    	printf("a(j)=%.2f\t",a[j]);//print aj
    	printf("b(j)=%.2f\t",h[j][7]);//print bj
    	printf("c(j)=%.2f\t",h[j][6]);//print cj
    	printf("d(j)=%.2f\n\n",h[j][8]);//print dj
    }
	
}

int main(){
	printf("\n\n\t\t\t\t~~~~NATURAL CUBIC SPLINE~~~~\n\n\n");//Description
    iter(); // use function in main func
    //kitapta verilen algoritma ile kontrol ettim fakat bazı değerler farklı cıktı.matematiksel bir hata oldugunu düşünmüyorum.
    //kodumdaki hatanın ne oldugunu bulamadıgım için değiştiremedim.eğer hatam gözünüze çarparsa geri dönüş sağlarsanız çok memnun olurum.
    return 0;
}
