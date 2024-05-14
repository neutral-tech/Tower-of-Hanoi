#include<stdio.h>
#include<stdlib.h>

int *A,*B,*C;
int topA=-1,topB=-1,topC=-1;
int n;
void push(int* stack,int a){
    if(stack==A){
        topA++;
        stack[topA]=a;
    }
    else if(stack==B){
        topB++;
        stack[topB]=a;
    }
    else if(stack==C){
        topC++;
        stack[topC]=a;
    }
    return;
}
void pop(int* stack){
    if(stack==A){
        stack[topA]=0;
        topA--;
    }
    else if(stack==B){
        stack[topB]=0;
        topB--;
    }
    else if(stack==C){
        stack[topC]=0;
        topC--;
    }
    return;
}
void display(){
    printf("\n");
    int i=0;
    for(i=n-1;i>=0;i--){
        if(A[i]==0) printf("     |   |");
        else printf("     | %d |",A[i]);
        if(B[i]==0) printf("     |   |");
        else printf("     | %d |",B[i]);
        if(C[i]==0) printf("     |   |");
        else printf("     | %d |",C[i]);
        printf("\n");
    }
    printf("----------------------------------\n");
    printf("       A         B        C\n");
}
int main(){
    printf("RULES:\n1. Only one disk can be move from one tower to another.\n2. A disk having higher radius can't be placed on top of disk having lower radious.\n");
    printf("NOTE: Number of disks should be greater than 0 and less than or equal to 10.\n");
    do{
        printf("Number of disks: ");
        scanf("%d",&n);
        if(n<1||n>10) printf("Enter again!!\n");
    }while(n<1||n>10);
    A=(int*)calloc(n,sizeof(int));
    B=(int*)calloc(n,sizeof(int));
    C=(int*)calloc(n,sizeof(int));
    int i=0;
    for(i=0;i<n;i++){
        push(A,n-i);
    }
    display();
    int choice=0;
    do{
      if(topC==(n-1)||topB==(n-1)){
        printf("YOU WON!!\n");
        break;
      }
      printf("\nOperations:\n1. A --> B\n2. B --> A\n3. A --> C\n4. C --> A\n5. B --> C\n6. C --> B\n7. Quit the game\n\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
        case 1: if(topA==-1) printf("Invalid Move!!\n");
                else if(topB==-1||A[topA]<B[topB]){
                    push(B,A[topA]);
                    pop(A);
                }
                else printf("Invalid Move!!\n");
                break;
        case 2: if(topB==-1) printf("Invalid Move!!\n");
                else if(topA==-1||B[topB]<A[topA]){
                    push(A,B[topB]);
                    pop(B);
                }
                else printf("Invalid Move!!\n");
                break;
        case 3: if(topA==-1) printf("Invalid Move!!\n");
                else if(topC==-1||A[topA]<C[topC]){
                    push(C,A[topA]);
                    pop(A);
                }
                else printf("Invalid Move!!\n");
                break;
        case 4: if(topC==-1) printf("Invalid Move!!\n");
                else if(topA==-1||C[topC]<A[topA]){
                    push(A,C[topC]);
                    pop(C);
                }
                else printf("Invalid Move!!\n");
                break;
        case 5: if(topB==-1) printf("Invalid Move!!\n");
                else if(topC==-1||B[topB]<C[topC]){
                    push(C,B[topB]);
                    pop(B);
                }
                else printf("Invalid Move!!\n");
                break;
        case 6: if(topC==-1) printf("Invalid Move!!\n");
                else if(topB==-1||C[topC]<B[topB]){
                    push(B,C[topC]);
                    pop(C);
                }
                else printf("Invalid Move!!\n");
                break;
        case 7: printf("Game finished!!\n");break;
        default: printf("Invalid choice!!\n");break;
      }
      system("clear");//Use system("cls") for windows OS. if it doesn't work, remove this line
      if(choice!=7) display();
    }while(choice!=7);
    return 0;
}
