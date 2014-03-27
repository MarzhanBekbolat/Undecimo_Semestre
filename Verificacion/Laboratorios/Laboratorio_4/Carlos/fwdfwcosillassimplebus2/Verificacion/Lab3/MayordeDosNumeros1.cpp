#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
   int A, B;
   cout<<"COMPARACION DE NUMEROS\n\n"; //Uso similar al printf(...
   cout<< "A = ";
   cin>>A;
   cout<< "\nB = ";
   cin>>B;

   //scanf("%d%d", &A, &B);//scan lee valores
   if(A>B)
   {
      printf("A es el mayor\n");
   }
   if(B>A)
   {
      printf("B es el mayor\n");
   }
   if(B==A)
   {
      printf("B es igual que A\n");
   }
   
   system("pause");
}
