/* Main function of the C program. 
Codici numerici  e Bitwise operation
*/
#include<stdio.h>
#include<stdlib.h>

void printBits(unsigned int x){
  unsigned int mask=0x80000000;
   do{
      printf("%c",(x&mask?'1':'0')); // if (x & mask )   '1' else '0'     &= AND Bitwise operation 
      mask = mask >>1;   // >> shift a destra di 1
       //printf("%x\n",mask);
    }while(mask);
}

void print8Bits (unsigned int k)
{ int m;
    for (m=128;m>0;m>>=1) if (k&m) printf ("1");else printf ("0");printf ("\n");
}
int numerobit1(unsigned int a)
{ int conta=0;
for (;a>0;a>>=2) if(a&1) conta++;
return(conta);
}
int hd (unsigned int a,unsigned int b )
{ return(numerobit1(a^b));
}
int bitwise (void)

{ int t,i=1,x1,x2; 
    printf("\t Inserisci un numero intero : ~$");
    scanf("%d",&x1);
    printf("\t Inserisci un altro numero : ~$");
    scanf("%d",&x2);
    printf ("\n%d AND %d = %d \n",x1,x2,x1&x2);
    printf ("%d OR %d = %d \n",x1,x2,x1|x2);
    printf ("%d XOR %d = %d \n",x1,x2,x1^x2);
    printf ("HD(%x;%x) = %d \n",x1,x2,hd(x1,x2));
    printf ("\nCOMPLEMENTO A 1 DI 0X%X = %X \n",x1,~x1);
    printf ("\nCOMPLEMENTO A 2 DI 0X%X = %X \n",x1,-x1); 
    
    printf ("SHIFT LEFT\n");
    for (t=0;t<8;t++) { print8Bits(i);i<<=1;}
    printf ("SHIFT RIGHT\n");
    for (t=0;t<8;t++) {i>>=1;print8Bits(i);}

    getchar();
    return (0);
}


int and_or(void)
{ int a,b,c; 
  
    printf ("A | B |AND| OR|\n"); 
    printf ("--|---|---|---|\n");
    for (a=0;a<2;++a)
      for (b=0;b<2;++b) {
        c=(a && b);
        if (a) printf("1 | ");
        else printf ("0 | ");
        if (b) printf("1 | ");
        else printf ("0 | ");
        if (c) printf("1 | ");
        else printf ("0 | ");
        c=(a || b);
        if (c) printf("1 | \n");
        else printf ("0 | \n");
          }
    getchar();
   
    return(0);
}

unsigned int binToBcd(unsigned int x)
{ unsigned int conv=0,i; 
  for( i=0 ; x>0;i++){
    conv = (x%10<<(i<<2))|conv;
    x/=10;
  }
  return( conv );
}
unsigned int bcdToBin(unsigned int x)
{ unsigned int conv=0,i; 
  for( i=1 ; x>0;i*=10){
    conv = (x&0xF)*i+conv;
    x/=16;
       }
  return( conv );
}

// Binary to Gray code 
 unsigned int btg(unsigned x) {return x^(x>>1);// Gray code    ^= EXOR  Bitwise operation  
}
// Gray code to binary 
 unsigned int gtb(unsigned x) {
     x= x^(x>>16);// Gray code to bin
     x= x^(x>>8);
     x= x^(x>>4);
     x= x^(x>>2); 
     return x^(x>>1);
}


void tableBinGray(unsigned int x){
    int i=((x<1000000000)?0:x-1000000000) ;
    printf("\t DEC \t BIN \t\t\t\t\t\t Gray \n");
    for( ; i<=x;i++){ 
      printf("\t %u \t ",i);
       printBits(i);
       printf("\t ");
       printBits(btg(i));
       printf("\n ");
    }
      
}
int main()
{   
    unsigned int num ;
//  Richiesta inserimento di un numero
    printf("I Byte occupati da una variabile unsigned int sono : %i\n",(int)sizeof ( num ));
    printf("\t Inserisci un numero intero : ~$");
    scanf("%d",&num);
    printf("%u In Esadecimale: 0x%x \n",num,  num);  // Stampo il numero in esadecimale 
// Stampa i bits 
    printf("%u In binario: \t",num);
    printBits(num); // Funzione creata per stampare i singoli bit della variabile num 
    printf("\n");
//Stampa in bcd    
    printf("%u In BCD : 0x%x \n",num, binToBcd( num));
    printf("%u In Esadecimale: 0x%x \n",num, bcdToBin(binToBcd( num)));    
    
//Stampa in Gray   
    printf("%u In 0xGray:0x%x  (%u)\n\t\t",num,btg(num),btg(num));
    printBits(btg(num));  // funzione che trasforma in codice binario-reflesso "Gray" num 
    printf("\n");
    getchar();
    tableBinGray(num);
    getchar();
    and_or(); // funzione che stampa tabella verita 
    getchar();
    bitwise();
//system("pause");
    return 0; 
     
} 
