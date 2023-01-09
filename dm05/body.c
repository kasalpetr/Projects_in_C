#include<stdio.h>
#include<math.h>

double vypocet(double xA, double yA,double xB, double yB,double xC, double yC){
    // printf("%lf %lf %lf %lf %lf %lf\n",  xA,  yA, xB,  yB, xC,  yC );
 
   double slopeAB = 0;
   double slopeBC = 0;
   double slopeAC = 0;

    slopeAC = (yC - yA)/(xC - xA);
    slopeAC = slopeAC * 100;
    slopeAC = round(slopeAC);
    slopeAC = slopeAC / 100;
    // printf("%lf\n", slopeAC);

    slopeAB = (yB - yA)/(xB - xA);
    slopeAB = slopeAB * 100;
    slopeAB = round(slopeAB);
    slopeAB = slopeAB / 100;
    // printf("%lf\n", slopeAB);

    slopeBC = (yC - yB)/(xC - xB);
    slopeBC = slopeBC * 100;
    slopeBC = round(slopeBC);
    slopeBC = slopeBC / 100;

    // printf("%lf\n", slopeBC);
      if (((yA == yB) && (xA == xB)) || ((yA == yC) && (xA == xC)) || ((yB == yC) && (xB == xC)))
    {
       printf("Nektere body splyvaji.\n");
        
    }else{
    if (slopeAB == slopeAC && slopeAB == slopeBC)
    {
        printf("Body lezi na jedne primce.\n");
        return 1;

    }else{
        if (((yA == yB) && (yB == yC)) || ((xA == xB) && (xC == xB))){

        printf("Body lezi na jedne primce.\n");
        return 1;
    }

    }
      printf("Body nelezi na jedne primce.\n");

    }
       

  
     
    return 0;
}

double prostredni(double xA, double yA,double xB, double yB,double xC, double yC){

double bodA = 0;
double bodB = 0;
double bodC = 0;

bodA = xA + yA;
bodB = xB + yB;
bodC = xC + yC;

if (((bodA < bodB) && (bodB < bodC)) || ((bodC < bodB) && (bodB < bodA)))
{
    printf("Prostredni je bod B.\n");
}else{
if (((bodB < bodA) && (bodA < bodC)) || ((bodC < bodA) && (bodA < bodB)))
{
    printf("Prostredni je bod A.\n");
}else{

    printf("Prostredni je bod C.\n");
}
}



return 0;
}


int main(void)
{
    double bodA[2];
    double bodB[2];
    double bodC[2];


    printf("Bod A:\n");
       if (scanf("%lf %lf", &bodA[0], &bodA[1]) != 2)
    {
            printf("Nespravny vstup.\n");
            return 0;
    }
    
    // if (bodA[0]+1.-1.+1. != bodA[0]+1. || bodA[1]+1.-1. +1.!= bodA[1] +1.)
    // {
    //         printf("Nespravny vstup.\n");
    //         return 0;
    // }
    
    
    printf("Bod B:\n");
         if (scanf("%lf %lf", &bodB[0], &bodB[1]) != 2)
    {
            printf("Nespravny vstup.\n");
            return 0;
    }
 

    printf("Bod C:\n");
         if (scanf("%lf %lf", &bodC[0], &bodC[1]) != 2)
    {
            printf("Nespravny vstup.\n");
            return 0;
    }   
 

    if (bodA[0] *bodA[1] * bodB[0] *bodB[1] * bodC[0] * bodC[1] == 0)
    {
        bodA[0] = bodA[0] + 1;
        bodA[1] = bodA[1] + 1;
        bodB[0] = bodB[0] + 1;
        bodB[1] = bodB[1] + 1;
        bodC[0] = bodC[0] + 1;
        bodC[1] = bodC[1] + 1;
    }

    if (vypocet(bodA[0],bodA[1],bodB[0],bodB[1],bodC[0],bodC[1])== 1)
    {
        prostredni(bodA[0],bodA[1],bodB[0],bodB[1],bodC[0],bodC[1]);
    }
    

    return 0;
}
