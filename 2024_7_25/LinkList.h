#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int STATUS;/* */


typedef struct node{

Elemtype *data;/*  */
struct node *next;/*  */

}LinkList;
/* define link list struct */

/*
STATUS make_node( Elemtype **e);
void visit( Elemtype *e);
STATUS init_list(LinkList **head);
STATUS create_list(LinkList **head);
STATUS display_LinkList(LinkList *head,void (*vi)( Elemtype*));
STATUS save_LinkList(LinkList *head);
STATUS read_LinkList(LinkList *head);

*/


/*init LinkList */
STATUS init_list(LinkList **head){

(*head)=(LinkList*)malloc(sizeof(LinkList));/* alloc memory to head */
(*head)->data=NULL;/* */
(*head)->next=NULL;/* set NULL */
printf("init link list\n");/* */
return OK;/* return */


}
STATUS create_list(LinkList **head,STATUS (*make)( Elemtype**)){
LinkList *p,*q;/* */
int num,i;/* */
q=(*head);/* */
while(q->next!=NULL){
	q=q->next;
}
printf("enter create num:");/* */
scanf("%d",&num);/* */
for(i=0;/* */
i<num;/* */
i++){
p=(LinkList *)malloc(sizeof(LinkList));/* */
(p->data)=( Elemtype*) malloc(sizeof( Elemtype));/* malloc pointer */
make(&(p->data));/* */
p->next=NULL;/* */
q->next=p;/* */
q=p;/* */
q->next=NULL;/* */

}

printf("created link list\n");/* */
return OK;/* */

}

STATUS display_LinkList(LinkList *head,void (*vi)( Elemtype*)){
LinkList *p;/* */
p=head->next;/* */
while(p){

vi(p->data);/* */
p=p->next;/* */

}

return OK;/* */

}

STATUS save_LinkList(LinkList *head,STATUS (*saveNode)( Elemtype**,FILE*),char* filename,char* power){
LinkList *p;/*  */
p=head->next;/*  */
FILE *fp;/*  */
fp=fopen(filename,power);/*  */
if(fp){

while(p){

	Elemtype *e=p->data;/**/
/*fwrite(e,sizeof( Elemtype),1,fp); */
	saveNode(&e,fp);/**/
p=p->next;/*  */
printf("saved\n");/*  */

}

}
fclose(fp);/*  */
return OK;/* */
}

STATUS read_LinkList(LinkList *head,STATUS (*readNode)( Elemtype**,FILE*),char *filename){
LinkList *p,*r;/*  */
Elemtype *e;/**/
FILE *fp;/*  */
 r=head;/*  */
fp=fopen(filename,"r");/*  */
if(fp==NULL){
printf("open have error\n");/*  */
return ;/*  */


}
rewind(fp);/**/
while(!feof(fp)){
e=( Elemtype*)malloc(sizeof( Elemtype));/* alloc memroy */
p=( LinkList*)malloc(sizeof( LinkList));/**/
/*if(fread( e,sizeof( Elemtype),1,fp)==1){*/
if(readNode(&e,fp)==1){
	p->data=e;/**/
p->next=NULL;/*  */
r->next=p;/*  */
r=p;/*  */

}

}
fclose(fp);/*  */
printf("read close\n");/*  */
return OK;/* */

}

STATUS sort_LinkList(LinkList *head,STATUS (*sortNode)(Elemtype**,Elemtype**)){
	
	LinkList *p;/* */
	LinkList *q;
p=head->next;/* */
q=p->next;
while(p){
while(q){
sortNode(&p->data,&q->data);/* */	
	q=q->next;
}

p=p->next;/* */

}

return OK;/* */

}


STATUS delete_LinkList(LinkList *head,
STATUS (*deleteTip)(Elemtype*),
STATUS (*findDeleteNode)( Elemtype**,Elemtype**),
void (*vi)( Elemtype*)){
LinkList *p,*q,*temp;/* */
/*p=head->next;*/
q=head;
p=q->next;
Elemtype *del;
del=(Elemtype*)malloc(sizeof(Elemtype));
deleteTip(del);
printf("need delete:\n");
vi(del);
while(p){	
vi(q->next->data);
	if(!findDeleteNode(&(p->data),&del)){
	//	printf("test\t");
		q=q->next;
		p=p->next;/* */
		//printf("test pointer \t");

}
if(findDeleteNode(&(p->data),&del)){
	/* maybe p->data not data ,so need test if() */
vi(p->data)	;
temp=p;

q->next=p->next;
return OK;/* */	
}

}

if(!p || !findDeleteNode(&(p->data),&del)){
	printf("not found\n");
return 0;
}

}


STATUS update_LinkList(LinkList *head,
STATUS (*findTip)(Elemtype*),
STATUS (*findUpdateNode)( Elemtype**,Elemtype**),
void (*vi)( Elemtype*),
STATUS (*updateNode)(Elemtype**)){
LinkList *p,*q,*temp;/* */
/*p=head->next;*/
q=head;
p=q->next;
Elemtype *up;
up=(Elemtype*)malloc(sizeof(Elemtype));
findTip(up);
printf("need update:\n");
vi(up);
while(p){	
vi(q->next->data);
	if(!findUpdateNode(&(p->data),&up)){
	//	printf("test\t");
		q=q->next;
		p=p->next;/* */
		//printf("test pointer \t");

}
if(findUpdateNode(&(p->data),&up)){
	/* maybe p->data not data ,so need test if() */
vi(p->data)	;
temp=p;
updateNode(&(p->data));
return OK;/* */	
}

}

if(!p || !findUpdateNode(&(p->data),&up)){
	printf("not found\n");
return 0;
}

}


STATUS query_LinkList(LinkList *head,
STATUS (*findTip)(Elemtype*),
STATUS (*findQueryNode)( Elemtype**,Elemtype**),
void (*vi)( Elemtype*),
void (*queryNode)()){
LinkList *p,*q,*temp;/* */
/*p=head->next;*/
q=head;
p=q->next;
Elemtype *up;
up=(Elemtype*)malloc(sizeof(Elemtype));
findTip(up);
printf("need query:\n");
vi(up);
while(p){	
//vi(q->next->data);
	if(!findQueryNode(&(p->data),&up)){
	//	printf("test\t");
		q=q->next;
		p=p->next;/* */
		//printf("test pointer \t");

}
if(findQueryNode(&(p->data),&up)){
	/* maybe p->data not data ,so need test if() */
queryNode();
vi(p->data)	;

return OK;/* */	
}

}

if(!p || !findQueryNode(&(p->data),&up)){
	printf("not found\n");
return 0;
}

}


#endif
