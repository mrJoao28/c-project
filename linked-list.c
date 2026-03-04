#include <stdio.h>
#include <stdlib.h>


int add(int num , int index , link *p);
int delete(int index , link*p);

typedef struct link{
    struct link*last;
    int num;
    struct link*next;
}link;

int main(void){
    link *in = NULL;
    link *out = NULL;

    for (int i = 0 ; i <5 ; i++){

        int number;
        link*p = malloc(sizeof(link));
        if (p == NULL){
            return 1;
        }
        if (i ==0){
            printf("Select a number: ");
            scanf("%i",&number);
            p->num = number;
            p->next = NULL;
            p->last = NULL;
            p->next = in;
            p->last = p;
            in = p;
            out = p;  //primeiro elemento
        } else {
            printf("Select a number: ");
            scanf("%i",&number);
            p->num = number;
            p->next = NULL;
            p->last = NULL;
            //dupla ligaçao
            p->next = in;

            //procedimentos normais
            in->last = p;

            in = p;//o ultimo elemento
        }
    }
    for (int i = 0 ; i <5 ; i++){
        printf("%i \n",in->num);
        in = in->next;
    }

    printf("\n");

    for (int i = 0 ; i <5 ; i++){
        printf("%i \n",out->num);
        out = out->last;
    }

    free(out);
    free(in);

}


int add(int num , int index , link *p){
    int counter = 0;
    while (p->next != NULL){
        if (counter == index){
            link *new = malloc(sizeof(link));
            new->num = num;
            new->next = p->next;
            new->last = p;
            return 0;
        }
        counter ++;
        p = p->next;
    }
}

int delete(int index , link*p){
    int counter = 0;
    link *last = NULL;
    link *next = NULL;
    while (p->next != NULL){
        if (counter == index){
            last = p->last;
            next = p->next;
            next->last = last;
            last->next = next;
            free(p);
            return 0;
        }
        counter ++;
        p = p->next;
    }
}

