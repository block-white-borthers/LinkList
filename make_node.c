#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int STATUS;/* */

typedef struct elem_type{
int num;/* */
char name[20];/* */

}elem_type;/* */
/* define data struct  */


typedef struct node{

elem_type *data;/*  */
struct node *next;/*  */

}link_list;
/* define link list struct */



STATUS make_node(elem_type **e){
(*e)=(elem_type*)malloc(sizeof(elem_type));/* */
char input_str[20];/* */
int input_int;/* */
printf("enter num:");/* */
scanf("%d",&(*e)->num);/* */

printf("enter name:");/* */
scanf("%s",input_str);/* */
strcpy((*e)->name,input_str);/* */

printf("made node\n");/* */
return OK;/* */

}


void visit(elem_type *e) /* ListTraverse() use */
{
elem_type *output;/* */
output=e;/* */

printf("\n%d\t%s\t\n",output->num,output->name);/* */
printf("visited\n");/* */

}


/*init link_list */
STATUS init_list(link_list **head){

(*head)=(link_list*)malloc(sizeof(link_list));/* alloc memory to head */
(*head)->data=NULL;/* */
(*head)->next=NULL;/* set NULL */
printf("init link list\n");/* */
return OK;/* return */


}
STATUS create_list(link_list **head){
link_list *p,*q;/* */
int num,i;/* */
q=(*head);/* */
printf("enter create num:");/* */
scanf("%d",&num);/* */
for(i=0;/* */
i<num;/* */
i++){
p=(link_list *)malloc(sizeof(link_list));/* */
make_node(&(p->data));/* */
p->next=NULL;/* */
q->next=p;/* */
q=p;/* */
q->next=NULL;/* */



}

printf("created link list\n");/* */
return OK;/* */

}

STATUS display_link_list(link_list *head,void (*vi)(elem_type*)){
link_list *p;/* */
p=head->next;/* */
while(p){
vi(p->data);/* */
p=p->next;/* */

}


printf("displayed\n");/* */
return OK;/* */

}

STATUS save_link_list(link_list *head){
link_list *p;/*  */
p=head->next;/*  */
FILE *fp;/*  */
fp=fopen("link_list.txt","w");/*  */
if(fp){

while(p){
fwrite(p,sizeof(link_list),1,fp);/*  */
p=p->next;/*  */


}

}
fclose(fp);/*  */
return OK;/* */
}

STATUS read_link_list(link_list *head){
link_list *p,*r;/*  */
FILE *fp;/*  */
 r=head;/*  */
fp=fopen("link_list.txt","rb+");/*  */
if(fp==NULL){
printf("open have error\n");/*  */
return ;/*  */


}
while(!feof(fp)){
p=(link_list*)malloc(sizeof(link_list));/* alloc memroy */
if(fread(p,sizeof(link_list),1,fp)==1){
p->next=NULL;/*  */
r->next=p;/*  */
r=p;/*  */


}


}
fclose(fp);/*  */

return OK;/* */

}




void main(){
link_list *head,*head2;/* */
init_list(&head);/* */
create_list(&head);/* */
display_link_list(head,visit);/* */
save_link_list(head);/* */
read_link_list(head2);/* */
display_link_list(head2,visit);/* */



}

