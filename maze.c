#include <stdio.h>
#include <stdlib.h>

#define mlin 10
#define mcol 10
#define FALSE   0
#define TRUE    1
#define caminho  0
#define ocupado          1
#define visitado        -1
#define saida_labirinto 100


	int Matriz[mlin][mcol];
	int procura(M,lin,col)
	int M[mlin][mcol];
	int lin,col;
	{
  		char proc;

  		if ( (lin > mlin) || (lin < 0) || (col > mcol) || (col < 0) )
     		proc=FALSE;
  		else
     	
		 if ( (M[lin][col] == ocupado) || (M[lin][col] == visitado) )
        	proc=FALSE;
     	
		 else if (M[lin][col] == saida_labirinto)
             proc=TRUE;
         	else if (M[lin][col] == caminho)
               {
                   M[lin][col]=visitado;    
                   proc = procura(M,lin-1,col);
                   proc = procura(M,lin,col-1) || proc;
                   proc = procura(M,lin,col+1) || proc;
                   proc = procura(M,lin+1,col) || proc;
               }

   		return(proc);
	}
	void lerarquivo(labirinto,M)
	char labirinto[255];
	int  M[mlin][mcol];
	{
  		FILE *arqtxt;
  		int lin,col;
		arqtxt=fopen("labirinto.txt","rt");
  		
		  if (arqtxt==NULL){
     		printf("Insira o arquivo do labirinto\n\n");
     		exit(-1);
  	}
  		  else
  			for (lin=0; lin < mlin; lin++)
      			for (col=0; col < mcol; col++)
          			fscanf(arqtxt,"%d\n",&(M[lin][col]));
			fclose(arqtxt);
	}
	void mostra_matriz(M)
	int M[mlin][mcol];
	{
  	int lin,col;

  		for (lin=0; lin < mlin; lin++){
      		for (col=0; col < mcol; col++){
          		if (M[lin][col] == caminho)
             		printf(" ");
          		if (M[lin][col] == ocupado)
             		printf("O");
          		if (M[lin][col] == saida_labirinto)
             		printf("_ \n Fim !");
      }
      printf("\n");
  	}
	}

	main(){
  	int Labirinto[mlin][mcol];

  	printf("\n\n Caminho Labirinto \n\n");
  	lerarquivo("labirinto.txt",Labirinto);
  	mostra_matriz(Labirinto);
  	getch();
	
}
