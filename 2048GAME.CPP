#include<stdio.h>
#include<conio.h>
#include<bios.h>
#include<ctype.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<math.h>
int stack1[5],stack2[5],stack3[5],stack4[5],b[4];
int ss1[5],ss2[5],ss3[5],ss4[5];
int top1=-1,top2=-1,top3=-1,top4=-1,top=-1,l=-1,m=-1;
int ep[16],points=0,k=-1;
void shiftdown(int a[]);
void emptyarr(int a[]);
void shiftup(int a[]);
void set();
void q();
void s();
void emptypos();
void generateall();
void generateone(int arr[]);
void d();
void display(int stack1[],int stack2[],int stack3[],int stack4[]);
void add(int a[]);
int reprint(int s);
void replaceall1(int ss[],int i);
void ss();
void transpose();
void reversearray(int a[]);
void shiftallup();
void addright();
void addleft();
void shiftalldown();
void addonedown(int stack[]);
void adddown();
void addup();
void g();
void main()
{
    int i;
    char n;
    clrscr();
    /*for(i=0;i<17;i++){printf("i no:%d\n",i+1);s();emptypos();q();} s();*/
    do
    {
	    printf("5/w:up\t\t\tpoints are:%d\n2/s:down\n1/a:left\n3/d:right\n",points);
	    s();
	    scanf("%c",&n);
	    printf("%c",n);
	    switch(n)
	    {
		   case '5':case 'w':addup();break;
		   case '2':case 's':adddown();break;
		   case '1':case 'a':addleft();break;
		   case '3':case 'd':addright();break;
	    }
	    clrscr();
    }
    while(k>=0||k<16);
    g();
    getch();
}
void shiftalldown()
{
	shiftdown(stack1);
	shiftdown(stack2);
	shiftdown(stack3);
	shiftdown(stack4);
}
void addleft()
{
		ss();
	shiftup(ss1);
	shiftup(ss2);
	shiftup(ss3);
	shiftup(ss4);
	add(ss1);add(ss2);add(ss3);add(ss4);
	transpose();
}
void g()
{
	printf("Game Over!!Your final points are:%d",points);
}
void addright()
{
	ss();
	shiftdown(ss1);      reversearray(ss1);
	shiftdown(ss2);      reversearray(ss2);
	shiftdown(ss3);      reversearray(ss3);
	shiftdown(ss4);      reversearray(ss4);
	shiftallup();
	add(ss1);add(ss2);add(ss3);add(ss4);
	reversearray(ss1);
	reversearray(ss2);
	reversearray(ss3);
	reversearray(ss4);
	transpose();
}
void addup()
{
	shiftallup();
	add(stack1);
	add(stack2);
	add(stack3);
	add(stack4);
}
void adddown()
{
	addonedown(stack1);
	addonedown(stack2);
	addonedown(stack3);
	addonedown(stack4);
}
void addonedown(int stack[])
{
	reversearray(stack);
	shiftup(stack);
	add(stack);
	reversearray(stack);
}









void add(int a[])
{
	int b,c,d,e;
	b=a[0];c=a[1];d=a[2];e=a[3];
	if(b==c)
	{
		b=b+c;
		points+=b;
		if(d==e)
		{
			c=d+e;
			points+=c;
			d=0;
			e=0;
		}
		else
		{
			c=d;
			d=e;
			e=0;
		}
	}
	else if(c==d)
	{
		c=c+d;
		points+=c;
		d=e;
		e=0;
	}
	else if(d==e)
	{
		d=d+e;
		points+=d;
		e=0;
	}
	a[0]=b;a[1]=c;a[2]=d;a[3]=e;
}
int reprint(int s)
{
    if(s==0){printf("--\t");}
    else printf("%d\t",s);
    return 0;
}
void display(int stack1[],int stack2[],int stack3[],int stack4[])
{
    printf("\n");
    int i=0;
    for(i=0;i<4;i++)
    {
	reprint(stack1[i]);reprint(stack2[i]);reprint(stack3[i]);reprint(stack4[i]);
	printf("\n");
    }
}
void d()
{
	display(stack1,stack2,stack3,stack4);
}
void sd()
{
	display(ss1,ss2,ss3,ss4);
}
void generateone(int arr[])
{
    int i=0;
    for(i=0;i<4;i++)
    {
	arr[i]=rand()%20;
    }
}
void generateall()
{
    srand(time(NULL));
    generateone(stack1);
    generateone(stack2);
    generateone(stack3);
    generateone(stack4);
}
void emptypos()
{
    int i=0;k=-1;
    for(i=0;i<4;i++)if(stack1[i]==0)ep[++k]=i;
    for(i=0;i<4;i++)if(stack2[i]==0)ep[++k]=i+4;
    for(i=0;i<4;i++)if(stack3[i]==0)ep[++k]=i+8;
    for(i=0;i<4;i++)if(stack4[i]==0)ep[++k]=i+12;
}
void set()
{
	srand(time(NULL));
	printf("rand no is:");
	int a=ep[rand()%(k+1)];
	if(a==NULL) a=ep[rand()%(k+1)];
	if(a>=12){stack4[a-12]=2;printf("%d",a);}
	else if(a>=8){stack3[a-8]=2;printf("%d",a);}
	else if(a>=4){stack2[a-4]=2;printf("%d",a);}
	else if(a>=0){stack1[a]=2;printf("%d",a);}
}
void q(){clrscr();}
void s()
{
	emptypos();
	set();
	emptypos();
	d();
}
void emptyarr(int a[])
{
	int i=0;
	for(i=0;i<4;i++)
	a[i]=0;
}
void shiftup(int a[])
{
	int i;
	l=-1;
	emptyarr(b);
	for(i=0;i<4;i++)
	{
		if(a[i]!=0)
		{
			b[++l]=a[i];
		}
	}
	for(i=0;i<4;i++) a[i]=b[i];
	for(i=l+1;i<4;i++) a[i]=0;
}
void shiftdown(int a[])
{
	int i;
	m=-1;
	emptyarr(b);
	for(i=0;i<4;i++)
	{
		if(a[3-i]!=0)
		{
			b[3-++m]=a[3-i];
		}
	}
	for(i=0;i<4;i++) a[i]=b[i];
	for(i=0;i<3-m;i++) a[i]=0;
}
void replaceall(int ss[],int i)
{
		ss[0]=stack1[i];
		ss[1]=stack2[i];
		ss[2]=stack3[i];
		ss[3]=stack4[i];
}
void replaceall1(int ss[],int i)
{
	ss[0]=ss1[i];
	ss[1]=ss2[i];
	ss[2]=ss3[i];
	ss[3]=ss4[i];
}
void ss()
{
	replaceall(ss1,0);
	replaceall(ss2,1);
	replaceall(ss3,2);
	replaceall(ss4,3);
}
void transpose()
{
	replaceall1(stack1,0);
	replaceall1(stack2,1);
	replaceall1(stack3,2);
	replaceall1(stack4,3);
}
void reversearray(int a[])
{
	int temp;
	temp=a[3];
	a[3]=a[0];
	a[0]=temp;
	temp=a[2];
	a[2]=a[1];
	a[1]=temp;
}
void shiftallup()
{
	shiftup(stack1);
	shiftup(stack2);
	shiftup(stack3);
	shiftup(stack4);
}