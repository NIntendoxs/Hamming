#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int bpar(int);
void Uhamming(int,char*,char*);//ubicacion de los bits
void VHamming(int,char*,char*);//Valor de los bits de hamming
void CHamming(char*,char*,int);
int main(){
    int m,n,i=0,nch,u,g=0,ehi=0,p,r=1,lsb=0,cbls=0;	
    char *bin;
    char *bch;
    char *bdh;
    char *bdc;
    bin = malloc(256);
    bch = malloc(256);
    bdh = malloc(256);
    bdc = malloc(256);
    ///////////////////////////////////////////////
    printf ("Ingresa la cadena de texto en binario\n");
    scanf ("%s255",bin);//ingresa la cadena de bits
    printf("Usted ingreso: %s\n",bin);//imprime la cadena de bits
    m=strlen(bin);//determina la longitud de la entrada
    n=bpar(m);//determina el numero de bits de hamming
    nch = m+n-1;//determina la cantidad de bits incluyendo los bits de hamming
    printf("Cantidad de bits de hamming: %d\nLongitud de la palabra con bits de hamming: %d\n",n,nch+1);//imprime el numero y tipo codificacion
    ///////////////////////////////////////////////
    //determinar ubicacion los bits de hamming
    Uhamming(nch,bch,bin);
    printf("Ubicacion de los bits de hamming %s\n",bch);
    ///////////////////////////////////////////////
    //determina el valor de los bits de hamming
    VHamming(nch,bch,bdh);
    printf("Cadena con bits de hamming %s\nBits de hamming %s\n",bch,bdh);
    ///////////////////////////////////////////////
    CHamming(bdc,bch,nch);
    ///////////////////////////////////////////////
    return 0;//fin del programa
}
///determina el numero de bits de hamming
int bpar(int m){
    int a=0, n=0, t=0, r=0;
    //printf("%d\n",m);
    do{
        a = pow(2,n);
        r = a*2;
        t = m+n+1;
        //printf("%d %d %d\n",a,t,n);
        n++;
    }while (r<t+1);
    return n;
}
void Uhamming(int nch, char *bch, char *bin){
    int g=0,u,ehi=0;
    for(int p=0;p<=nch;p++){
        g=0;
        u=pow(2,p);//determina la ubicacion del bit respecto a 2^n
        while(g<=nch){
            if(u==g){
                bch[g-1]='H';//determinamos la ubicacion de los bits de hamming
            }
            g++;
        }
        //printf("Estoy en %d\n",p);
        if(bch[p]=='\0'){//determina en que posiciones donde no hay bit de hamming y acomoda los bits de la cadena original
                bch[p]=bin[ehi];
                ehi++;
            }
    }
}
void VHamming(int nch,char *bch,char *bdh){
    int bh=0;
    int cbls=0;
    int r=1;
    int lsb=0;
    for(int p=0;p<=nch;p++){
        if(bch[p]=='H'){
            for(int g=p+1;g<=nch;g++){
                if(bch[g]=='1'){

                    int c=0;
                    int cb=g+1;
                    while(c<r){
                        lsb=cb%2;
                        cb=cb/2;
                        c++;
                        if(c==r){
                            cbls=cbls+lsb;
                        }
                    }
                }
            }
            if(cbls%2==1){
                bch[p]='1';
                bdh[bh]='1';
                bh++;
            }else {
                bch[p]='0';
                bdh[bh]='0';
                bh++;
            }
            //printf("El valor de H es \t%c cuando cbls es: %d\n\n", bch[p],cbls);
            cbls=0;
            r++;//variable que controla la conversion binaria      
        }
    }
    r=1;
    //printf("Cadena con bits de hamming %s\nBits de hamming %s\n",bch,bdh);
}
void CHamming(char *bdc, char *bch, int nch){
    char *udh;
    udh = malloc(256);
    printf ("Ingresa una cadena de bits con un error: ");
    scanf ("%s255",udh);
    int bh=0,b2,cbls=0,r=1,lsb=0,par=0,d=0,c=0,ch=0,nh;
    //int lh=strlen(bch);
    int lh=strlen(udh);
    
    for(nh=0;ch<lh;nh++){
        ch=pow(2,nh);
        //printf("%d\n",ch);
    }
    //nh--;
    
    //printf("Cantidad de bits%d\n",nh);
    for(int p=0;p<nh-1;p++){
        //b2=p%2;
        lsb=0;
        //b2=par-1;
        d=0;
        par=pow(2,p);
        //printf("\t\t\t estoy en %d, %d\n",p,par);
        
        for(int pr=par-1;pr<=nch;pr++){
            if(d<par){
                //printf("El valor de d es %d y el de pr es %d\n",d,pr);
                if(udh[pr]=='1'){
                    //printf("El valor de pr es %d\n",pr);
                    lsb++;
                }
                
                d++;
                
            }
            else {
                pr=pr+d-1;
                d=0;
                
            }
        }
        
        //printf("hay %d unos\n",lsb);
        if(lsb%2==1){
            bdc[c]='1';
            //printf("1 Hay algo en [%d] %c\n",c,bdc[c]);
            c++;
        }else {
            bdc[c]='0';
            //printf("0 Hay algo en [%d] %c\n",c,bdc[c]);
            c++;
        }
        
        
        
            //printf("El valor de H es \t%c cuando cbls es: %d\n\n", bch[p],cbls);
        //cbls=0;
        //r++;//variable que controla la conversion binaria      
        
    }
    printf("Bits de comprobacion: %s\n\n",bdc);
    
}
// cd /mnt/c/users/nintendoxs/desktop/hamming

//Cesar Heber Arambula Bautista
//ingpuebla@gmail.com
