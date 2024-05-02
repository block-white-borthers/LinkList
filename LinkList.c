#include "LinkList.h"



LinkList *init(){
	LinkList *head;
	head=(LinkList *)malloc(sizeof(LinkList));
	head->data=0;
	head->next=NULL;
	return head;
	
}

void createLinkList(LinkList *head){
	LinkList *p,*q;
	q=head;
	int i;
	for(i=1;i<5;i++){
		p=(LinkList *)malloc(sizeof(LinkList));
		p->data=i;
		q->next=p;
		q=p;
		q->next=NULL;
		
	}
	printf("success\n");
	
}

void displayLinkList(LinkList *head){
	LinkList *p;
	p=head->next;
	
	while(p!=NULL){
		printf("\t%d\t",p->data);
		p=p->next;
		
	}
printf("success\n");
	
}

void saveLinkList(LinkList *head){
	LinkList *p;
	p=head;
	
	FILE *fp;
	fp=fopen(LinkListDataPath,"w");
	while(p!=NULL){
	fwrite(p,sizeof(struct node),1,fp);	
	p=p->next;
		
	}
	printf("success for save\n");	
}

void readLinkList(LinkList *head){
	LinkList *p,*q;
	q=head;
	FILE *fp;
	fp=fopen(LinkListDataPath,"r");
	while(fp!='\0'){
		fread(p,sizeof(struct node),1,fp);
		q->next=p;
		q=p;
		q->next=NULL;
		
		
	}
	printf("read success\n");
	
}


