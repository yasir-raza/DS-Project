#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<fstream>

using namespace std;

 int bubble(int*,int);
 void filewrite();
 void avgmarks();
 void fileprint();
 void filesort();
 void rollin();

//	 SORTING FUNCTION 

int bubble(int x[],int n)
{
 int hold,j,pass,i,switched = 1;
 for(pass = 0; pass < n-1 && switched == 1;pass++)
 {
  switched=0;
  for (j=0;j<n-pass-1;j++)
   if (x[j]>x[j+1])
   {
    switched=1;
    hold = x[j];
    x[j] = x[j+1];
    x[j+1]=hold;
    }
   }

}
//	FILE WRITING FUNCTION

void filewrite()
{
  int roll,ch,mark;
  char nam[50];
   FILE *fp;
  fp = fopen("student.txt","a");
  cout<<"Please Enter:\n\nRoll Number \t\tName \t\tMarks"<<endl;
  ch =1;
  while(ch==1)
  {
	cin>>roll>>nam>>mark;
  fprintf(fp,"%d %s %d\n",roll,nam,mark);
  cout<<"\n\n Press 1 to continue OR any other key to Back!";
  cin>>ch;
  }
   fclose(fp) ;
}
//	OUTPUTING DATA ON SCREEN

void fileprint()
{
  int marks[100],rollno[100],x[100],i;
  char name[100][50];
  FILE *fp; 
  system("pause");
  fp = fopen("student.txt","r");
   i=0;
   system("cls");
   cout<<"ROLLNO:\t        NAME:\t       MARKS:\n";
   while(!feof(fp))
  {	cout<<"\n";
	 fscanf(fp,"%d %s %d\n",&rollno[i],&name[i],&marks[i]);
	 cout<<rollno[i]<<"\t\t"<<name[i]<<"\t\t"<<marks[i];
     i=i+1;
   }
   fclose(fp);
   cout<<endl<<endl;
   cout<<"Press any Key to Return into Main Menu!";
   getch();

  }
//	SORTING FILE

void filesort()
  { int marks[100],rollno[100],x[100],n,i,j;
    char name[100][50];
    FILE *fp,*fm;

    fp = fopen("student.txt","r");
    fm = fopen("marks.txt","w");
    i=0;
   while(! feof(fp))
    {

     fscanf(fp,"%d %s %d\n",&rollno[i],&name[i],&marks[i]);
     x[i]= marks[i];
     i=i+1;
      }
       n=i;
       bubble(x,n);
    for(i=0;i<n;i++)
    {
    cout<<"\t"<<x[i];
    //printf(" %d\t",x[i]);
    }

 for(i=0;i<n;i++)
 {
   for (j=0;j<n;j++)
 {
   if(x[i]==marks[j])
   {
      fprintf(fm,"%d %s %d\n",rollno[j],name[j],marks[j]);
   }
 }
 }
  fclose(fm);
  fclose(fp);
  cout<<"\nPress any Key to Return into Main Menu!";
  //  printf("\n\n\nPRESS ANY KEY");
  getch();
}
//	DATA USING ROLLNO

void rollin()
{   int i,roll,ch,mark,roll1;
    char nam[50];
    FILE *fm;
    ch=1;
    
  while(ch)
  { system("cls");
    fm = fopen("marks.txt","r");
    cout<<endl<<"Enter Your Roll Number: ";
   cin>>roll1;  
      i=0;
   while(! feof(fm))
    {
     fscanf(fm,"%d %s %d\n",&roll,&nam,&mark);
     if(roll1==roll)
    {
	cout<<"\nRollNo:     NAME        MARKS\n ";
	cout<<"\n"<<roll<<"\t\t"<<nam<<"\t\t"<<mark;
     break;
     }
     else
     i=i+1;
      }
  cout<<"\n\nPress 1 to see Student Info OR 0 to return into Main Menu!\n";
  cin>>ch;
  fclose(fm);
  }
 }

void avgmarks()
 {
    int marks[100],rollno[100],n,i;
    float avg,x;
    char name[100][50];
    FILE *fm;
    fm = fopen("marks.txt","r");
    i=0;
   while(! feof(fm))
    {	
     fscanf(fm,"%d %s %d\n",&rollno[i],&name[i],&marks[i]);
     x = x + marks[i];
     i=i+1;
      }
     n = i;
   avg = x/n;
  cout<<"Average Marks Of "<<n<<" Students Are: "<<avg<<endl;
  fclose(fm);
  cout<<"\n\n\nPress any key to Exit! ";
   getch();
 }

main()
{
	
  int marks[100],rollno[100],x[100],n,i,j,roll,c,mark,roll1;
  char name[100][10],nam[50];

  while(c!=6)
   {  
     system("cls");
     cout<<"\n\n\t* * * * * * * * * * STUDENT MANAGEMENT SYSTEM! * * * * * * * * * *\n\t*\t\t\t\t\t\t\t\t *\n\t*\t\t\t\t\t\t\t\t *\n\t*\t\t\t\t\t\t\t\t *\n\t*\t\t\t\t\t\t\t\t *\n";
     cout<<"\t*\t   Press 1 to Enter Student Info!\t\t\t * \n\t*\t\t\t\t\t\t\t\t *\n";
     cout<<"\t*\t   Press 2 to See Student Records!\t\t\t * \n\t*\t\t\t\t\t\t\t\t *\n";
     cout<<"\t*\t   Press 3 to Sort File on  the basis of Marks! \t *\n\t*\t\t\t\t\t\t\t\t *\n";
     cout<<"\t*\t   Press 4 to Print Student Info Using ROLL NUMBER!\t * \n\t*\t\t\t\t\t\t\t\t *\n";
     cout<<"\t*\t   Press 5 to Find Average of Total Student's Marks! \t *\n\t*\t\t\t\t\t\t\t\t *\n";
     cout<<"\t*\t   Press 6 to Exit! \t\t\t\t\t *\n\t*\t\t\t\t\t\t\t\t *\n\t*\t\t\t\t\t\t\t\t *\n\t";
     cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * *"<<endl<<endl;
     cout<<" Enter Your Choice: ";
     cin>>c;
     system("cls");
     switch(c)
     {
     case 1:
          filewrite();
          break;
     case 2:
          fileprint();
         break;
     case 3:
         filesort();
         break;
     case 4:  rollin();
          break;
     case 5:  avgmarks();
          break;
     case 6:
          break;
     default:
          break;
     }
    }

  }
