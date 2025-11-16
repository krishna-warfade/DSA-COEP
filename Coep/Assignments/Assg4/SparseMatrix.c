/* Steps: 
 *
 * CREATE A SPARSE MATRIX
 * FILL THE SPARSE MATRIX
 * PRINT IT
 * CREATE ANOTHER SPARSE MATRIX
 * PRINT IT
 * ADD 2 SPARSE MATRICES
 * PRINT RESULTANT MATRIX
 * TRANSPOSE THE RESULTANT MATRIX
 * PRINT IT
*/

#include<stdio.h>
#include<stdlib.h>

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *s){
    printf("Enter the dimensions of matrix:");
    scanf("%d %d",&s->m,&s->n);
    printf("Enter number of non-zero elements:");
    scanf("%d",&s->num);
    s->e=(struct Element*)malloc(s->num*sizeof(struct Element));
    printf("Enter the elements:");
    for(int i  = 0;i<s->num;i++){
        scanf("%d %d %d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
}

void Display(struct Sparse s){
    int k = 0;
    for(int i = 0;i<s.m;i++){
        for(int j = 0;j<s.n;j++){
            if(i==s.e[k].i&&j==s.e[k].j){
                printf("%d ",s.e[k++].x);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse* add(struct Sparse *s1,struct Sparse *s2){
    struct Sparse *add;
    add=(struct Sparse*)malloc(sizeof(struct Sparse));
    add->m=s1->m;
    add->n=s1->n;
    add->e=(struct Element*)malloc((s1->num+s2->num)*sizeof(struct Element));
    if(s1->m!=s2->m||s1->n!=s2->n){
        return NULL;
    }
    int i=0,j=0,k=0;
    while(i<s1->num&&j<s2->num){
        if(s1->e[i].i<s2->e[j].i){
            add->e[k++]=s1->e[i++];
        }else if(s1->e[i].i>s2->e[j].i){
            add->e[k++]=s2->e[j++];
        }else{
            if(s1->e[i].j<s2->e[j].j){
                add->e[k++]=s1->e[i++];
            }else if(s1->e[i].j>s2->e[j].j){
                add->e[k++]=s2->e[j++];
            }else{
                add->e[k]=s1->e[i];
                add->e[k++].x=s1->e[i++].x+s2->e[j++].x;
            }
        }
        
    }
    for(;i<s1->num;i++)add->e[k++]=s1->e[i++];
    for(;j<s2->num;j++)add->e[k++]=s2->e[j++];
    add->num=k;
    return add;
}

void fast_transpose(struct Sparse *t, struct Sparse *s) {
    t->m = s->n;       // transpose: rows become cols
    t->n = s->m;
    t->num = s->num;

    if (s->num > 0) {
        t->e = (struct Element*)malloc(s->num * sizeof(struct Element));

        int *rowterms = (int*)malloc(s->n * sizeof(int));
        int *start_pos = (int*)malloc(s->n * sizeof(int));


        for (int i = 0; i < s->n; i++) {
            rowterms[i] = 0;
        }


        for (int i = 0; i < s->num; i++) {
            rowterms[s->e[i].j]++;
        }

        start_pos[0] = 0;
        for (int i = 1; i < s->n; i++) {
            start_pos[i] = start_pos[i-1] + rowterms[i-1];
        }

        for (int i = 0; i < s->num; i++) {
            int col = s->e[i].j;
            int pos = start_pos[col]++;
            t->e[pos].i = s->e[i].j;
            t->e[pos].j = s->e[i].i;
            t->e[pos].x = s->e[i].x;
        }

        free(rowterms);
        free(start_pos);
    } else {
        t->e = NULL;
    }
}


int main(){
    struct Sparse s1,s2,*sum, t;
    create(&s1);
    create(&s2);

    printf("\nMatrix 1:\n");
    Display(s1);

    printf("\nMatrix 2:\n");
    Display(s2);

    sum = add(&s1,&s2);
    printf("\nSum Matrix:\n");
    Display(*sum);

    printf("\nTransposed Matrix:\n");
    fast_transpose(&t, sum);
    Display(t);

    free(s1.e);
    free(s2.e);
    free(sum->e);
    free(sum);
    free(t.e);
    return 0;
}
