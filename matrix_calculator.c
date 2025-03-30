#include <stdio.h>
void input_matrix(int r1,int c1,int r2,int c2,int a[100][100],int b[100][100]);
void order_matrix(int* r1,int* c1,int* r2,int* c2);
void matrix_result(int r1,int c2,int C[100][100]);
void input_matrix(int r1,int c1,int r2,int c2,int a[100][100],int b[100][100]){ 
    //input element of matrix A
    printf("\nEnter the element of marix A :\n");
    for(int i = 0; i < r1;i++){
        for(int j = 0; j < c1;j++){
            scanf("%d", &a[i][j]);
        }
    }
    //input element of matrix B
    printf("\nEnter the element of marix B :\n");
    for(int i = 0; i < r2;i++){
        for(int j = 0; j < c2;j++){
            scanf("%d", &b[i][j]);
        }
    }
    return;
}
void matrix_result(int r1,int c2,int C[100][100]){
    //printing Updated matrix C
    printf("\nUpdated Matrix :\n");
    for(int i = 0; i < r1;i++){
        for(int j = 0; j < c2;j++){
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    return;
}
void order_matrix(int* r1,int* c1,int* r2,int* c2){
    printf("\nEnter the order of matrix A : ");
    scanf("%d %d", r1, c1);
    printf("\nEnter the order of matrix B : ");
    scanf("%d %d", r2, c2);
    return;
}
int main(){
    int n = 1,r1,c1,r2,c2;
    int a[100][100],b[100][100],C[100][100];
    while(n != 5){
        printf("CHOICE :\n");
        printf("1. ADDITION\n") ;
        printf("2. SUBTRACTION\n") ;
        printf("3. MULTIPLICATION\n") ;
        printf("4. TRANSPOSE\n") ;
        printf("5. EXIT\n");
        scanf("%d", &n);
        switch(n){
            case 1:
                //adding both matrix and assining to C matrix
                order_matrix(&r1,&c1,&r2,&c2);
                if(r1 != r2 || c1 != c2){
                    printf("\nAddition is not possible\n");
                    break;
                }
                input_matrix(r1,c1,r2,c2,a,b);
                for(int i = 0; i < r1;i++){
                    for(int j = 0; j < c1;j++){
                        C[i][j] = a[i][j] + b[i][j];
                    }
                }
                matrix_result(r1,c2,C);
                break;
            case 2:
                //subtract both matrix and assining to C matrix
                order_matrix(&r1,&c1,&r2,&c2);
                if(r1 != r2 || c1 != c2){
                    printf("\nsubtraction is not possible\n");
                    break;
                }
                input_matrix(r1,c1,r2,c2,a,b);
                for(int i = 0; i < r1;i++){
                    for(int j = 0; j < c1;j++){
                        C[i][j] = a[i][j] - b[i][j];
                    }
                }
                matrix_result(r1,c2,C);
                break;
            case 3:
                //multiplication of both matrix
                order_matrix(&r1,&c1,&r2,&c2);
                //checking the condition 
                if(c1 == r2){
                    input_matrix(r1,c1,r2,c2,a,b);
                    //printing the order of (A X B)
                    printf("\nOrder of (A x B) : %d X %d\n",r1,c2);
                    // multiplly the both matrix 
                    printf("\n(A X B) : \n");
                    for(int i =  0; i < r1; i++){
                        for(int j = 0;j < c2; j++){
                            C[i][j] = 0;
                            for( int k = 0; k < r2;k++){
                                C[i][j] += a[i][k] * b[k][j]; 
                            }
                        }
                    }
                    matrix_result(r1,c2,C);
                }
                else{
                    printf("\nMultiplication is not possible\n");
                }
                
                break;
            case 4:
                printf("\nEntar the elements of matrix :\n");
                for (int i = 0; i < c1; i++) {
                    for (int j = 0; j < r1; j++) {
                        scanf("%d\t", &a[i][j]);
                    }
                    printf("\n");
                }
                printf("\nTranspose of matrix A:\n");
                for (int i = 0; i < c1; i++) {
                    for (int j = 0; j < r1; j++) {
                        printf("%d\t", a[j][i]);
                    }
                    printf("\n");
                }
                break;
            case 5:
                printf("\n!!END TASK!!\n");
                break;
            default:
                printf("\n!!INVALID CHOICE!!\n");
                break;
        }
    }
    
    return 0;
}