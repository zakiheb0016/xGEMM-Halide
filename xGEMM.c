#include <stdio.h>
#include <stdlib.h>
int main(){
int N1,M1,N2,M2;
FILE *input_file=fopen("data/matrices.txt","r");
if(input_file==NULL){
printf("Can't open matrices.txt file\n");
return -1;
}
fscanf(input_file,"%d %d",&N1,&M1);
int A[N1][M1];
for(int i=0;i<N1;i++){
	for(int j=0;j<M1;j++){
		fscanf(input_file,"%d",&A[i][j]);
	}
}
fscanf(input_file,"%d %d",&N2,&M2);
if(M1!=N2){
printf("Can't perform multiplication due to dimensions\n");
return -1;
}
int B[N2][M2];
for(int i=0;i<N2;i++){
        for(int j=0;j<M2;j++){ 
                fscanf(input_file,"%d",&B[i][j]);
        }
}
fclose(input_file);
int C[N1][M2];
for(int i=0;i<N1;i++){
        for(int j=0;j<M2;j++){ 
                C[i][j]=0;
		for(int k=0;k<M1;k++){
			C[i][j]+=A[i][k]*B[k][j];
		}
        }
}
FILE *output_file=fopen("data/CResult.txt","w");
if(output_file==NULL){
printf("Can't open CResult.txt file\n");
return -1;
}
fprintf(output_file,"%d %d\n",N1,M1);
for(int i=0;i<N2;i++){
        for(int j=0;j<M2;j++){ 
                fprintf(output_file,"%d ",C[i][j]);
        }
fprintf(output_file,"\n");
}
fclose(output_file);
return 0;
}

