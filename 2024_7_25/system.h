#include <stdio.h>
#include "student.h"
#include "School.h"
typedef struct {
School *school;/**/
Student *student;/**/
/* int size; */
}Elemtype;/**/
#include "LinkList.h"


STATUS makeStudent( Elemtype **e)
{
	(*e)=( Elemtype*) malloc(sizeof( Elemtype));/* malloc pointer */
	Student *st;/* define pointer value */
	st=(Student*)malloc(sizeof( Student));/* malloc  */
	char input_str[64];/* */


printf("enter name:");/* tip */
scanf("%s",input_str);/* input */
strcpy(st->name,input_str);/* copy string */
//memset((*e)->student->place,0,sizeof((*e)->student->place));
printf("enter place:");/* tip */
scanf("%s",input_str);/* input */
strcpy(st->place,input_str);/* copy string */
(*e)->student=st;/* save value */
printf("made node\n");/* */
return OK;/* */


}

void visitStudent( Elemtype *e){
		Student *st;
		st=e->student;

		printf("|\t%s\t\t|\t%s\t\t|\n",st->name,st->place);/*  */
		printf("-----------------------------------------\n");/*  */
	
	}

STATUS saveStudent( Elemtype **e,FILE *f){
Student *st;
st=(*e)->student;

fwrite(st,sizeof(Student),1,f);/**/
return sizeof(Student);/**/


}

STATUS readStudent( Elemtype** e,FILE *f){
	Student *st;
	/*st=(*e)->student;*/
	/*(*e)->student=(Student*)malloc(sizeof(Student));*/
	st=(Student*)malloc(sizeof(Student));/* malloc */
if(fread( st,sizeof( Student),1,f)==1){
/* if read 
	 else not read,
	must use () */
(*e)->student=st;
printf("read\n");
	return 1;/**/
}
else return 0;

}

STATUS sortStudentName(Elemtype** e1,Elemtype** e2){
	Student *temp;
	if(strcmp((*e1)->student->name,(*e2)->student->name)>=0){
		temp=(*e1)->student;
		(*e1)->student=(*e2)->student;
		(*e2)->student=temp;
		return 1;
	}else{
		
	}
	
	
}


STATUS findStudentNode(Elemtype** e1,Elemtype** e2){
	if((e1)&&e2){
	if(strcmp((*e1)->student->name,(*e2)->student->name)==0){
/*		printf("hello world?%s\n",(*e1)->student->name); */
		return 1;
	}else{
/*		printf("hello?%s\n",(*e1)->student->name); */
		return 0;
	}	
		
	}else{
		return 0;
		
	}
	
}

STATUS findTip(Elemtype* de){
	Student *st;
	st=(Student*)malloc(sizeof(Student));
	printf("enter need find student name:\n");
	scanf("%s",st->name);
	strcpy(st->place,"");
	de->student=st;
	return 1;
	
}

STATUS updateStudent(Elemtype** e){
	Student *st;
	st=(Student*)malloc(sizeof(Student));
	printf("enter need update student name:");
	scanf("%s",st->name);
	printf("enter need update student place:");
	scanf("%s",st->place);
	(*e)->student=st;
	return 1;
	
}


int allow(char *choose)
{
	if (strcmp(choose,"y")== 0|| strcmp(choose,"Y")==0) 
	{
		return 1;/**/
	}
	else {
		return 0;/**/
	}

}
void menu()
{
system("cls");/**/
printf("************  welcome to book manage system  **********\n\n");/*  */
printf("************   欢迎来到图书管理系统   **********\n\n");/*  */
printf("\t1.打印\t 2.添加\t 3.更改\n\n");/*  */
printf("\t4.删除\t 5.查询\t 6.退出\n\n");/*  */
printf("*********************************\n");/*  */
printf("请输入想要进行的操作数：");/*  */

}

void inquire()
{//set  choose answer to app run
	char ch[2];/**/
	printf("display menu?y/n:\n");/* tip  */
	scanf("%s",ch);/* use global value choose */
	if(allow(ch)){
	menu();/**/
	}else {
		exit(0);/* exit app */
	}
}
void showhead()
{
printf("==========================================\n");/* tip */
printf("\t           显示学生信息            \n");/* tip */
printf("=============================================\n");/* tip */
printf("\t名字\t\t|\t地区\t\t|\n");/* tip */
printf("-------------------------------------------\n");/*tip  */
}

void showall(LinkList *head)
{
	showhead();/**/
	display_LinkList(head, visitStudent);/**/
	inquire();/**/
}


void addStudent(LinkList *head)
{
	  create_list(&head,makeStudent);/* add node */
		save_LinkList(head,saveStudent,"Student.txt","w");/**/
		read_LinkList(head, readStudent,"Student.txt");/**/
		inquire();/**/
}


STATUS upStudent(LinkList *head){
	update_LinkList(head,findTip,findStudentNode,
			visitStudent,updateStudent);
	save_LinkList(head, saveStudent,"Student.txt","w");/**/
		inquire();/**/
	
}


STATUS delStudent(LinkList *head){
	delete_LinkList(head,findTip,findStudentNode,visitStudent);
	save_LinkList(head, saveStudent,"Student.txt","w");/**/
		inquire();/**/

}


STATUS queryStudent( LinkList *head){
query_LinkList(head,findTip,findStudentNode,visitStudent,showhead);
inquire();/**/

}

int runstudentsystem()
{
	
		LinkList *head,*head2;/**/
	init_list(&head);/**/
	init_list(&head2);
	read_LinkList(head2, readStudent,"Student.txt");/**/


	int n;/**/
	menu();/* show menu */
	scanf("%d",&n);/* input */
	while(n){
	switch(n){
		case 1:showall(head2);/* show all book info data */
		       break;/* */

		case 2:addStudent(head2);/**/
		       break;/**/
		       
		case 3: upStudent(head2);/**/
					 break;/**/
		
		case 4:delStudent(head2);/**/
					 break;/**/

		case 5:queryStudent(head2);/**/
					 break;/**/
		case 6:exit(0);/* quit app */
		default:break;/**/
	}
	scanf("%d",&n);/**/
	
	}
}


