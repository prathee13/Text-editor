#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<stdlib.h>

void menu();

void create();

void add();

void view();

void main()

{

clrscr();

menu();

getch();

}

void menu()

{

int c;

clrscr();

do

{

printf("\nMENU\n");

printf("1.FILE CREATION\n");

printf("2.ADD\n");

printf("3.VIEW\n");

printf("4.EXIT\n");

printf("\nENTER YOUR CHOICE : ");

scanf("%d",&c);

switch(c)

{

case 1:

create();

break;

case 2:

add();

break;

case 3:

view();

break;

case 4:

exit(0);

break;

default:

break;

}

}

while(c!=4);

}

void create()

{

FILE *fp;                                                                                                                               

char name[20],inp[40];

printf("\nENTER THE FILENAME: ");

scanf("%s",&name);

fp=fopen(name,"w");

printf("\nENTER THE CONTENTS: ");

fflush(stdin);

gets(inp);

fprintf(fp,"%s",inp);

fclose(fp);

}

void add()

{

FILE *fp;

char name[20],inp[40];

printf("\nENTER THE FILE NAME: ");

scanf("%s",&name);

fp=fopen(name,"a");

if(fp==NULL)

{

printf("\nERROR:file not found\n");

getch();

menu();

}

printf("\nENTER THE FILE CONTENTS: ");

fflush(stdin);

gets(inp);

fprintf(fp,"%s",inp);

fclose(fp);

printf("\nCONTENTS ADDED\n");

getch();

}

void view()

{

FILE *fp;

char a;

char fname[20];

printf("\nENTER THE FILENAME: ");

scanf("%s",&fname);

fp=fopen(fname,"r");

if(fp==NULL)

{

printf("ERROR:file not found\n");

getch();

menu();

}

a=fgetc(fp);

while(!feof(fp))

{

printf("%c",a);

a=fgetc(fp);

}

getch();                                                                                                                                  

fclose(fp);

}

 