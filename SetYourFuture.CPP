/**************************************
            HEADER FILES 
**************************************/

#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<fstream.h>
#include<stdlib.h>
/**************************************
        DECLERATION OF FUNCTIONS
**************************************/

show();
process();
view_jobs();
view_employs();
add_info();
modify_info();
delete_info();
post_offer();
modify_offer();
delete_offer();
begin();
Welcome();
login();
explore();
Search_Employ();
Search_Job();
mouse_welcome();
mouse_login();
mouse_explore();
mouse_srh_emp();
mouse_srh_job();
end();

/**************************************
	  GLOBAL VARIABLES
**************************************/

int btn,mouse_x,mouse_y;

/**************************************
        MOUSE CONFIGURATION 
**************************************/

union REGS i,o;

initmouse() //INITIALISE MOUSE
{
  i.x.ax = 0;
  int86(0x33,&i,&o);
  return(o.x.ax);
}

void showmouseptr() //DISPLAYS MOUSE POINTER
{
  i.x.ax = 1;
  int86(0x33,&i,&o);
}
void hidemouse()
{
  i.x.ax=2;
  int86(0x33,&i,&o);
}

void restrictmouseptr(int x1,int y1, int x2, int y2) //RESTRICTS MOUSE MOVEMENT
{
  i.x.ax = 7;
  i.x.cx = x1;
  i.x.dx = x2;
  int86(0x33,&i,&o);
  i.x.ax = 8;
  i.x.cx = y1;
  i.x.dx = y2;
  int86(0x33,&i,&o);
}

void getmouse(int *button, int *x, int *y) // GETS MOUSE STATUS
{
  i.x.ax = 3;
  int86(0x33,&i,&o);
  *button = o.x.bx;
  *x = o.x.cx;
  *y = o.x.dx;
}

void mouse()
{
  gotoxy(0,0);
  if (initmouse() == 0)
  {
     closegraph();
     restorecrtmode();
     cout<<"\nMouse driver not loaded...";
     getch();
     return;
  }
  restrictmouseptr(0,0,639,479);
  showmouseptr();
}
/**************************************
        FUNTION DEFINITIONS 
**************************************/

void show(int x, int y, char ch[])
{
   delay(200);
   outtextxy(x,y,ch);
}

void process(int count)
{
    cleardevice();
    setcolor(YELLOW);
    settextstyle(10,0,4);
    for(int i=0; i<count; i++)
    {
      cleardevice();
      show(130,200,"P");
      for(int j=205; j<210; j++)
	circle(320,240,j);
      show(160,200,"R");
      for(j; j<215; j++)
	circle(320,240,j);
      show(190,200,"O");
      for(j; j<220; j++)
	circle(320,240,j);
      show(220,200,"C");
      for(j; j<225; j++)
	circle(320,240,j);
      show(253,200,"E");
      for(j; j<230; j++)
	circle(320,240,j);
      show(280,200,"S");
      for(j; j<235; j++)
	circle(320,240,j);
      show(310,200,"S");
      for(j; j<240; j++)
	circle(320,240,j);
      show(340,200,"I");
      for(j; j<245; j++)
	circle(320,240,j);
      show(360,200,"N");
      for(j; j<250; j++)
	circle(320,240,j);
      show(390,200,"G");
      for(j; j<255; j++)
	circle(320,240,j);
      show(420,200,".");
      for(j; j<260; j++)
	circle(320,240,j);
      show(450,200,".");
      for(j; j<265; j++)
	circle(320,240,j);
      show(480,200,".");
      for(j; j<270; j++)
	circle(320,240,j);
    }
}

/**************************************
          CLASS DEFINITIONS 
**************************************/

class employ
{
  char First_Name[20];
  char Last_Name[20];
  char Designation[30];
  float Salary;
  char contact[11];
  int Reference_Code;
  public:
    employ()
    {
      First_Name[0]=Last_Name[0]=contact[0]='\0';
    }
    read_data();
    display_data();
    view_employs();
    add_info();
    Assign_Employ_Code();
    modify_info();
    delete_info();
    char* rtn_desig()
    {
      return Designation;
    }
    void assign_code(int num)
    {
      Reference_Code=num;
    }
    int rtn_code()
    {
      return Reference_Code;
    }
}E;

class job
{
  char Company_Name[50];
  char Designation[30];
  int Experience,Reference_Code;
  char contact[11];
  public:
    job()
    {
      Company_Name[0]=Designation[0]=contact[0]='\0';
      Experience=-1;
    }
    read_data();
    display_data();
    view_jobs();
    Assign_Offer_Code();
    post_offer();
    modify_offer();
    delete_offer();
    char* rtn_name()
    {
      return Company_Name;
    }
    char* rtn_desig()
    {
      return Designation;
    }
    void assign_code(int num)
    {
      Reference_Code=num;
    }
    int rtn_code()
    {
      return Reference_Code;
    }
}J;

class Signup
{
  char first_name[50];
  char last_name[50];
  char email_id[100];
  char password[100];
  char confirm_password[100];
  char mobile_no[11];
  char city[30];
  int ref_code;
  public:
    Signup()
    {
      first_name[0]=last_name[0]=email_id[0]=password[0]=confirm_password[0]=mobile_no[0]=city[0]='\0';
    }
    read_data();
    refer_code();
    void assign_code(int code)
    {
      ref_code=code;
    }
    void change_pword(char newpword[])
    {
      strcpy(password,newpword);
    }
    int rtn_code()
    {
      return ref_code;
    }
    char* rtn_email()
    {
      return email_id;
    }
    char* rtn_password()
    {
      return password;
    }
}S;
/**************************************
      MEMBER FUNCTION DEFINITIONS 
**************************************/

employ::read_data()
{
  cout<<"\n\t\tFirst Name : ";
  cin>>First_Name;
  cout<<"\n\t\tLast Name : ";
  cin>>Last_Name;
  cout<<"\n\t\tDesignation : ";
  gets(Designation);
  cout<<"\n\t\tExpected Salary (per annum) : ";
  cin>>Salary;
  cout<<"\n\t\tContact Number : ";
  cin>>contact;
  int size=strlen(contact);
  contact[++size]='\0';
  return 0;
}

employ::display_data()
{
  cout<<"\n\n\t\tFirst Name : "
      <<First_Name
      <<"\n\t\tLast Name : "
      <<Last_Name
      <<"\n\t\tDesignation : ";
  puts(Designation);
  cout<<"\n\t\tExpected Salary (per annum) : "
      <<Salary
      <<"\n\t\tContact Number : "
      <<contact;
  return 0;
}

job::read_data()
{
  cout<<"\n\t\tName of the Enterprise : ";
  gets(Company_Name);
  cout<<"\n\t\tDesignation : ";
  gets(Designation);
  while(Experience<0)
  {
    cout<<"\n\t\tExperience : ";
    cin>>Experience;
  }
  cout<<"\n\t\tContact Number : ";
  cin>>contact;
  int size=strlen(contact);
  contact[++size]='\0';
  return 0;
}

job::display_data()
{
  cout<<"\n\n\t\tName of the Enterprise : ";
  puts(Company_Name);
  cout<<"\n\t\tDesignation : ";
  puts(Designation);
  cout<<"\n\t\tExperience : "
      <<Experience
      <<"\n\t\tContact Number : "
      <<contact;
  return 0;
}

Signup::read_data()
{
  cout<<"\n\t\tFirst Name : ";
  cin>>first_name;
  cout<<"\n\t\tLast Name : ";
  cin>>last_name;
  cout<<"\n\t\tEmail ID : ";
  cin>>email_id;
  a:
  int i=0;
  cout<<"\n\t\tPassword : ";
  while(1)
  {
     password[i]=getch();
     if(password[i]=='\b')
     {
       if(i!=0)
       {
	 i--;
	 cout<<"\b \b";
       }
     }
     else if(isspace(password[i]))
     {
       break;
     }
     else
     {
       printf("*");
       i++;
     }
  }
  password[i]='\0';
  cout<<"\n\n\t\tConfirm password : ";
  i=0;
  while(1)
  {
     confirm_password[i]=getch();
     if(confirm_password[i]=='\b')
     {
       if(i!=0)
       {
	 i--;
	 cout<<"\b \b";
       }
     }
     else if(isspace(confirm_password[i]))
     {
       break;
     }
     else
     {
       printf("*");
       i++;
     }
  }
  confirm_password[i]='\0';
  if(strcmpi(confirm_password,password)!=0)
  {
    cout<<"\n\t\tPassword does not match. Please enter again.";
    goto a;
  }
  cout<<"\n\n\t\tMobile : ";
  cin>>mobile_no;
  int size=strlen(mobile_no);
  mobile_no[++size]='\0';
  cout<<"\n\t\tCity : ";
  gets(city);
  return 0;
}

Signup::refer_code()
{
  fstream file("D.dat",ios::binary|ios::in);
  file.seekg(0,ios::end);
  int pos=file.tellg();
  int code=pos+1000;
  return code;
}

/**************************************
        FUNCTION TO REGISTER
**************************************/

Register()
{
  cleardevice();
  settextstyle(3,0,1);
  textcolor(GREEN);
  fstream file("D.dat",ios::binary|ios::app);
  if(!file)
  {
    cout<<"\nERROR IN ASSOCIATION!";
    getch();
    return 0;
  }
  char agree;
  S.read_data();
  cout<<"\n\t\tConfirm your Registration ? <Y/N> : ";
  cin>>agree;
  if(agree=='y' || agree=='Y')
  {
     aa:
     randomize();
     int verify, confirm_verify;
     verify=random(9000)+1000;
     cout<<"\n\t\tVerification Code : ";
     cout<<verify;
     cout<<"\n\n\t\tEnter Verification Code : ";
     cin>>confirm_verify;
     if( verify == confirm_verify )
     {
	cout<<"\n\n\t\tREGISTRATION SUCCESSFUL.";
	int code=S.refer_code();
	cout<<"\n\n\t\tYOUR REFERENCE CODE IS : "<<code;
	S.assign_code(code);
	file.write((char*)&S,sizeof(S));
	getch();
     }
     else
     {
       cout<<"\n\t\tVerification Code does not match. Please enter again.";
       goto aa;
     }
  }
  file.close();
  return 0;
}

/**************************************
      FUNTION TO CHANGE PASSWORD 
**************************************/

change_password()
{
  fstream file("D.dat",ios::binary|ios::in|ios::out);
  if(!file)
  {
    cout<<"\nERROR IN ASSOCIATION!";
    getch();
    return 0;
  }
  int pos=0, code=0, flag=0;
  char new_password[100],conf_new_password[100],id[100];
  clrscr();
  cleardevice();
  cout<<"\n\n\n\n\n\n\n\t\tEnter Your Reference Code : ";
  cin>>code;
  while(file.read((char*)&S,sizeof(S)))
  {
    if(S.rtn_code()==code)
    {
      flag=1;
      cout<<"\n\t\tYour Email ID : ";
      strcpy(id,S.rtn_email());
      puts(id);
      a:
      cout<<"\n\t\tEnter Your New Password : ";
      int i=0;
      while(1)
      {
	new_password[i]=getch();
	if(new_password[i]=='\b')
	{
	  if(i!=0)
	  {
	    i--;
	    cout<<"\b \b";
	  }
	}
	else if(isspace(new_password[i]))
	{
	  break;
	}
	else
	{
	  printf("*");
	  i++;
	}
      }
      new_password[i]='\0';
      cout<<"\n\t\tConfirm New Password : ";
      i=0;
      while(1)
      {
	conf_new_password[i]=getch();
	if(conf_new_password[i]=='\b')
	{
	  if(i!=0)
	  {
	    i--;
	    cout<<"\b \b";
	  }
	}
	else if(isspace(conf_new_password[i]))
	{
	  break;
	}
	else
	{
	  printf("*");
	  i++;
	}
      }
      conf_new_password[i]='\0';
      if(strcmpi(conf_new_password,new_password)!=0)
      {
	cout<<"\n\t\tPassword does not match. Please enter again.";
	goto a;
      }
      cout<<"\n\n\t\t\tPress ENTER to submit...";
      getch();
      S.change_pword(new_password);
      file.seekg(pos,ios::beg);
      file.write((char*)&S,sizeof(S));
      break;
    }
    pos=file.tellg();
  }
  if(flag==1)
  {
    aa:
    randomize();
    int verify, confirm_verify;
    verify=random(9000)+1000;
    cout<<"\n\t\tVerification Code : ";
    cout<<verify;
    cout<<"\n\n\t\tEnter Verification Code : ";
    cin>>confirm_verify;
    if( verify == confirm_verify )
    {
      cout<<"\n\n\t\t Password Changed.";
      getch();
      return 0;
    }
    else
    {
      cout<<"\n\t\tVerification Code does not match. Please enter again.";
      goto aa;
    }
  }
  else
    cout<<"\n INVALID REFERENCE CODE..";
  getch();
  return 0;
}

/**************************************
	 FUNCTION TO SIGN IN
**************************************/

sign_in()
{
  a:
  clrscr();
  cleardevice();
  fstream file("D.dat",ios::binary|ios::in);
  if(!file)
  {
    cout<<"\n\t\t\tLOGIN ERROR";
    getch();
    return 0;
  }
  setcolor(GREEN);
  settextstyle(0,0,2);
  rectangle(100,50,550,100);
  rectangle(101,51,549,99);
  show(110,75,"PRESS 'ESC' TO GO BACK");
  int flag=0;
  char email[100],password[100],x;
  cout<<"\n\n\n\n\n\n\n\n\t\t"
      <<"Email Id : ";
  int j=0;
  while(1)
  {
    email[j]=getch();
    if(email[j]==27)
    {
      return 2;
    }
    else if(email[j]=='\b')
    {
      if(j!=0)
      {
	j--;
	cout<<"\b \b";
      }
    }
    else if(isspace(email[j]))
    {
      break;
    }
    else
    {
      cout<<email[j];
      j++;
    }
  }
  email[j]='\0';
  cout<<"\n\t\tPassword : ";
  int i=0;
  while(1)
  {
     password[i]=getch();
     if(password[i]==27)
     {
       return 2;
     }
     else if(password[i]=='\b')
     {
       if(i!=0)
       {
	 i--;
	 cout<<"\b \b";
       }
     }
     else if(isspace(password[i]))
     {
       break;
     }
     else
     {
       printf("*");
       i++;
     }
  }
  password[i]='\0';
  cout<<"\n\n\t\t\tPress ENTER to submit...";
  getch();
  while(file.read((char*)&S,sizeof(S)))
  {
    if((strcmp(S.rtn_email(),email)==0)&&(strcmp(S.rtn_password(),password)==0))
    {
      flag=1;
      break;
    }
  }
  if(!flag)
  {
    cout<<"\n\n\n\t\t\tINVALID EMAIL_ID OR PASSWORD...";
    cout<<"\n\n\n\t\t\tFORGOT PASSWORD ? <Y/N> : ";
    cin>>x;
    if(toupper(x)=='Y')
    {
	change_password();
	goto a;
    }
    else
       goto a;
  }
  file.close();
  return 1;
}

/**************************************
	FUNCTION DEFINITIONS
**************************************/

job::view_jobs()
{
  hidemouse();
  char ch='Y';
  while(ch=='Y' || ch=='y')
  {
    clrscr();
    cleardevice();
    fstream file("JOB_FILE.dat",ios::binary|ios::in);
    if(!file)
    {
      cout<<"\n\n\n\n\n\n\n\n\t\t\t NO JOBS AVAILABLE ";
      getch();
      Search_Job();
      showmouseptr();
      return 0;
    }
    char name[50], desig[30];
    int found=0;
    A:
    clrscr();
    cleardevice();
    cout<<"\n\n\n\n\n\n\t\t"
	<<"SEARCH BY : "
	<<"\n\t\t 1.NAME."
	<<"\n\t\t 2.DESIGNATION."
	<<"\n\t\t 3.BACK."
	<<"\n\n\t\tENTER YOUR CHOICE : ";
    int choice;
    cin>>choice;
    if(choice==1)
    {
      cout<<"\n\t\t Enter Name : ";
      gets(name);
    }
    else if(choice==2)
    {
      cout<<"\n\t\t Enter Designation : ";
      gets(desig);
    }
    else if(choice==3)
      break;
    else
    {
      cout<<"\n\t\t Invalid Choice : ";
      getch();
      goto A;
    }
    clrscr();
    cleardevice();
    while(file.read((char*)&J,sizeof(J)))
    {
      switch(choice)
      {
	case 1 : if(strcmpi(Company_Name,name)==0)
		 {
		   display_data();
		   found++;
		 }
		 break;
	case 2 : if(strcmpi(Designation,desig)==0)
		 {
		   display_data();
		   found++;
		 }
		 break;
	case 3 : found++;
		 break;
      }
    }
    if(found==0)
    {
      cout<<"\n\t\tINVALID DATA";
    }
    getch();
    file.close();
    cout<<"\n\n\t\t DO YOU WISH TO CONTINUE ? <Y/N> : ";
    cin>>ch;
  }
  Search_Job();
  showmouseptr();
  return 0;
}

employ::view_employs()
{
  hidemouse();
  char ch='Y';
  while(ch=='Y' || ch=='y')
  {
    clrscr();
    cleardevice();
    fstream file("EMPLOY_FILE.dat",ios::binary|ios::in);
    if(!file)
    {
      cout<<"\n\n\n\n\n\n\n\n\t\t\t NO EMPLOY DETAILS AVAILABLE ";
      getch();
      Search_Employ();
      showmouseptr();
      return 0;
    }
    char desig[30];
    int found=0;
    A:
    clrscr();
    cleardevice();
    cout<<"\n\n\n\n\n\n\n\n\t\t1.ENTER DESIGNATION TO SEARCH."
	<<"\n\t\t2.BACK."
	<<"\n\n\t\tENTER YOUR CHOICE : ";
    int choice;
    cin>>choice;
    if(choice==1)
    {
      cout<<"\n\n\t\t Enter Designation : ";
      gets(desig);
    }
    else if(choice==2)
      break;
    else
    {
      cout<<"\n\n\t\t INVALID CHOICE.";
      getch();
      goto A;
    }
    clrscr();
    cleardevice();
    while(file.read((char*)&E,sizeof(E)))
    {
      switch(choice)
      {
	case 1 : if(strcmpi(Designation,desig)==0)
		 {
		   display_data();
		   found++;
		 }
		 break;
      }
    }
    if(!found)
    {
      cout<<"\n\n\t\t INVALID DATA.";
    }
    getch();
    file.close();
    cout<<"\n\n\t\t DO YOU WISH TO CONTINUE ? <Y/N> : ";
    cin>>ch;
  }
  Search_Employ();
  showmouseptr();
  return 0;
}

employ::add_info()
{
  hidemouse();
  clrscr();
  cleardevice();
  fstream file("EMPLOY_FILE.dat",ios::binary|ios::in|ios::out);
  if(!file)
  {
    cout<<"\n\n\n\n\n\n\n\n\t\tERROR IN ASSOCIATION";
    getch();
    Search_Job();
    showmouseptr();
    return 0;
  }
  file.seekg(0,ios::end);
  char ch='Y';
  while(ch=='Y' || ch=='y')
  {
    clrscr();
    cleardevice();
    read_data();
    int pos=file.tellg();
    Reference_Code=pos+1000;
    cout<<"\n\n\t\tYour Reference Code is : "<<Reference_Code;
    file.write((char*)&E,sizeof(E));
    cout<<"\n\n\t\t DO YOU WANT TO ADD MORE INFO ? <Y/N> : ";
    cin>>ch;
  }
  file.close();
  Search_Job();
  showmouseptr();
  return 0;
}

employ::modify_info()
{
  hidemouse();
  char ch='Y';
  while(ch=='Y'|| ch=='y')
  {
    clrscr();
    cleardevice();
    fstream file("EMPLOY_FILE.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
      cout<<"\n\n\n\n\n\n\n\n\t\t NO EMPLOY DETAILS AVAILABLE ";
      getch();
      Search_Job();
      showmouseptr();
      return 0;
    }
    A:
    int count=0;
    clrscr();
    cleardevice();
    int code, found=0;
    cout<<"\n\n\n\n\n\n\n\n\t\t"
	<<"1.ENTER CODE TO MODIFY DETAILS."
	<<"\n\t\t2.BACK."
	<<"\n\n\t\tENTER YOUR CHOICE : ";
    int choice;
    cin>>choice;
    if(choice == 1 )
    {
      int code;
      cout<<"\n\n\t\t Enter Your Reference Code : ";
      cin>>code;
      while(file.read((char*)&E,sizeof(E)))
      {
	if(Reference_Code==code)
	{
	  clrscr();
	  cleardevice();
	  display_data();
	  found=1;
	  break;
	}
	count++;
      }
      if(found==1)
      {
	cout<<"\n Want to Modify the above details <Y/N> : ";
	char ch;
	cin>>ch;
	if(ch=='y'|| ch=='Y')
	{
	  cout<<"\n Enter New Details : ";
	  employ E1;
	  E1.read_data();
	  E1.assign_code(E.Reference_Code);
	  file.seekg(count*sizeof(E1), ios::beg);
	  file.write((char*)&E1,sizeof(E1));
	  cout<<"\n DETAILS MODIFIED...";
	}
      }
      else
      {
	 cout<<"\n\n\t\t Invalid Code ";
	 getch();
	 goto A;
      }
      cout<<"\n\n Want to Modify More <Y/N> : ";
      cin>>ch;
    }
    else if(choice == 2 )
    {
      Search_Job();
      showmouseptr();
      return 0;
    }
    else
    {
      cout<<"\n\n\t\t INVALID CHOICE...";
      getch();
      goto A;
    }
  }
  Search_Job();
  showmouseptr();
  return 0;
}

employ::delete_info()
{
  hidemouse();
  char ch='Y';
  while(ch=='Y' || ch=='y')
  {
    clrscr();
    cleardevice();
    fstream file("EMPLOY_FILE.dat",ios::binary|ios::in);
    fstream temp("temporary.dat",ios::binary|ios::out);
    if(!file || !temp)
    {
      cout<<"\n\n\n\n\n\n\n\n\t\tNO EMPLOY DETAILS AVAILABLE";
      getch();
      Search_Job();
      showmouseptr();
      return 0;
    }
    A:
    clrscr();
    cleardevice();
    int code, found1=0;
    cout<<"\n\n\n\n\n\n\n\n\t\t"
	<<"1.ENTER CODE TO DELETE DETAILS."
	<<"\n\t\t2.BACK."
	<<"\n\n\t\tENTER YOUR CHOICE : ";
    int choice;
    cin>>choice;
    if(choice==1)
    {
      cout<<"\n\n\t\t Enter Your Reference Code : ";
      cin>>code;
    }
    else if(choice==2)
      break;
    else
    {
      cout<<"\n\n\t\t Invalid choice. ";
      getch();
      goto A;
    }
    clrscr();
    cleardevice();
    while(file.read((char*)&E,sizeof(E)))
    {
      switch(choice)
      {
	case 1 : if(Reference_Code==code)
		 {
		   display_data();
		   found1=1;
		 }
		 break;
      }
      if(found1!=0)
      {
	cout<<"\n\t\t Do you want to delete the above details ? <Y/N> : ";
	cin>>ch;
	if(ch=='Y' || ch=='y')
	{
	  cout<<"\n\n\t\tDELETION SUCCESSFUL";
	  break;
	}
	else
	{
	  temp.write((char*)&E,sizeof(E));
	  break;
	}
      }
      else
      {
	temp.write((char*)&E,sizeof(E));
      }
    }
    if(found1==0)
    {
      cout<<"\n\n\t\t INVALID CODE.";
      getch();
      goto A;
    }
    cout<<"\n\t\tDO YOU WANT TO DELETE MORE INFO ? <Y/N> : ";
    cin>>ch;
  }
  remove("EMPLOY_FILE.dat");
  rename("temporary.dat","EMPLOY_FILE.dat");
  Search_Job();
  showmouseptr();
  return 0;
}

job::post_offer()
{
  hidemouse();
  clrscr();
  cleardevice();
  fstream file("JOB_FILE.dat",ios::binary|ios::in|ios::out);
  if(!file)
  {
    cout<<"\n\n\n\n\n\n\t\t ERROR IN ASSOCIATION ";
    getch();
    Search_Employ();
    showmouseptr();
    return 0;
  }
  char ch='Y';
  file.seekg(0,ios::end);
  while( ch=='Y' || ch=='y')
  {
    clrscr();
    cleardevice();
    read_data();
    int pos=0,code;
    pos=file.tellg();
    Reference_Code=pos+1000;
    cout<<"\n\n\t\tYour Reference Code is : "<<Reference_Code;
    file.write((char*)&J,sizeof(J));
    cout<<"\n\n\t\t DO YOU WANT TO POST MORE ? <Y/N> : ";
    cin>>ch;
  }
  file.close();
  Search_Employ();
  showmouseptr();
  return 0;
}

job::modify_offer()
{
  hidemouse();
  char ch='Y';
  while(ch=='Y' || ch=='y')
  {
    clrscr();
    cleardevice();
    fstream file("JOB_FILE.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
      cout<<"\n\n\n\n\n\n\n\n\t\t NO JOB DETAILS AVAILABLE ";
      getch();
      Search_Employ();
      showmouseptr();
      return 0;
    }
    A:
    int count=0;
    clrscr();
    cleardevice();
    int code, found=0;
    cout<<"\n\n\n\n\n\n\n\n\t\t"
	<<"1.ENTER CODE TO MODIFY DETAILS."
	<<"\n\t\t2.BACK."
	<<"\n\n\t\tENTER YOUR CHOICE : ";
    int choice;
    cin>>choice;
    if(choice == 1 )
    {
      int code;
      cout<<"\n\n\t\t Enter Your Reference Code : ";
      cin>>code;
      while(file.read((char*)&J,sizeof(J)))
      {
	if(Reference_Code==code)
	{
	  clrscr();
	  cleardevice();
	  display_data();
	  found=1;
	  break;
	}
	count++;
      }
      if(found==1)
      {
	cout<<"\n Want to Modify the above details <Y/N> : ";
	char ch;
	cin>>ch;
	if(ch=='y'|| ch=='Y')
	{
	  cout<<"\n Enter New Details : ";
	  job J1;
	  J1.read_data();
	  J1.assign_code(J.Reference_Code);
	  file.seekg(count*sizeof(J1), ios::beg);
	  file.write((char*)&J1,sizeof(J1));
	  cout<<"\n DETAILS MODIFIED...";
	}
      }
      else
      {
	 cout<<"\n\n\t\t Invalid Code ";
	 getch();
	 goto A;
      }
      cout<<"\n\n Want to Modify More <Y/N> : ";
      cin>>ch;
    }
    else if(choice == 2 )
    {
      Search_Job();
      showmouseptr();
      return 0;
    }
    else
    {
      cout<<"\n\n\t\t INVALID CHOICE...";
      getch();
      goto A;
    }
  }
  Search_Job();
  showmouseptr();
  return 0;
}

job::delete_offer()
{
  hidemouse();
  char ch='Y';
  while(ch=='Y' || ch=='y')
  {
    clrscr();
    cleardevice();
    fstream file("JOB_FILE.dat",ios::binary|ios::in);
    fstream temp("temporary.dat",ios::binary|ios::out);
    if(!file || !temp)
    {
      cout<<"\n\n\n\n\n\n\n\n\t\tNO DETAILS AVAILABLE";
      getch();
      Search_Employ();
      showmouseptr();
      return 0;
    }
    A:
    clrscr();
    cleardevice();
    int code, found1=0;
    cout<<"\n\n\n\n\n\n\n\n\t\t"
	<<"1.ENTER CODE TO MODIFY DETAILS."
	<<"\n\t\t2.BACK."
	<<"\n\n\t\tENTER YOUR CHOICE : ";
    int choice;
    cin>>choice;
    if(choice==1)
    {
      cout<<"\n\n\t\t Enter Your Reference Code : ";
      cin>>code;
    }
    else if(choice==2)
      break;
    else
    {
      cout<<"\n\n\t\t Invalid choice. ";
      getch();
      goto A;
    }
    clrscr();
    cleardevice();
    while(file.read((char*)&J,sizeof(J)))
    {
      switch(choice)
      {
	case 1 : if(Reference_Code==code)
		 {
		   display_data();
		   found1=1;
		 }
		 break;
      }
      if(found1==1)
      {
	cout<<"\n\t\t Do you want to delete the above details ? <Y/N> : ";
	cin>>ch;
	if(ch=='N' || ch=='n')
	{
	  temp.write((char*)&J,sizeof(J));
	  break;
	}
	else
	{
	  cout<<"\n\n\t\tDELETION SUCCESSFUL";
	  break;
	}
      }
      else
      {
	temp.write((char*)&J,sizeof(J));
      }
    }
    if(found1==0)
    {
      cout<<"\n\n\t\t INVALID CODE.";
      getch();
      goto A;
    }
    cout<<"\n\t\tDO YOU WANT TO DELETE MORE INFO ? <Y/N> : ";
    cin>>ch;
  }
  remove("JOB_FILE.dat");
  rename("temporary.dat","JOB_FILE.dat");
  Search_Employ();
  showmouseptr();
  return 0;
}

Search_Employ()
{
  cleardevice();
  hidemouse();
  setcolor(GREEN);
  settextstyle(3,0,4);
  rectangle(100,50,450,100);
  rectangle(101,51,449,99);
  show(110,52,"VIEW EMPLOYS");
  rectangle(100,150,450,200);
  rectangle(101,151,449,199);
  show(110,152,"POST AN OFFER");
  rectangle(100,250,450,300);
  rectangle(101,251,449,299);
  show(110,252,"MODIFY YOUR OFFER");
  rectangle(100,350,450,400);
  rectangle(101,351,449,399);
  show(110,352,"DELETE YOUR OFFER");
  settextstyle(3,0,3);
  rectangle(500,30,600,65);
  rectangle(501,31,599,64);
  show(510,32,"BACK");
  showmouseptr();
  return 0;
}

Search_Job()
{
  cleardevice();
  hidemouse();
  setcolor(GREEN);
  settextstyle(3,0,4);
  rectangle(100,50,450,100);
  rectangle(101,51,449,99);
  show(110,52,"VIEW JOBS");
  rectangle(100,150,450,200);
  rectangle(101,151,449,199);
  show(110,152,"ADD YOUR INFO");
  rectangle(100,250,450,300);
  rectangle(101,251,449,299);
  show(110,252,"MODIFY YOUR INFO");
  rectangle(100,350,450,400);
  rectangle(101,351,449,399);
  show(110,352,"DELETE YOUR INFO");
  settextstyle(3,0,3);
  rectangle(500,30,600,65);
  rectangle(501,31,599,64);
  show(510,32,"BACK");
  showmouseptr();
  return 0;
}

explore()
{
  hidemouse();
  cleardevice();
  setcolor(GREEN);
  settextstyle(3,0,2);
  rectangle(350,200,550,255);
  rectangle(351,201,549,254);
  show(360,202,"SEARCH YOUR");
  show(360,222,"CAPABLE EMPLOY");
  rectangle(30,200,200,255);
  rectangle(31,201,199,254);
  show(40,202,"SEARCH YOUR");
  show(40,222,"DREAM JOB");
  rectangle(500,30,600,65);
  rectangle(501,31,599,64);
  show(510,32,"LOG OUT");
  showmouseptr();
  return 0;
}

login()
{
  char username[1000];
  cleardevice();
  setcolor(GREEN);
  settextstyle(0,0,2);
  show(50,50,"PLEASE REGISTER BEFORE YOU LOGIN");
  settextstyle(3,0,3);
  rectangle(390,263,500,300);
  rectangle(391,264,499,299);
  show(400,265,"REGISTER");
  rectangle(220,263,320,300);
  rectangle(221,264,319,299);
  show(230,265,"SIGN IN");
  rectangle(90,263,170,300);
  rectangle(91,264,169,299);
  show(100,265,"BACK");
  showmouseptr();
  return 0;
}

Welcome()
{
  cleardevice();
  setcolor(GREEN);
  settextstyle(3,0,6);
  show(200,60,"W");
  show(245,60,"E");
  show(275,60,"L");
  show(300,60,"C");
  show(335,60,"O");
  show(370,60,"M");
  show(405,60,"E");
  show(280,110,"T");
  show(305,110,"O");
  show(100,160,"S");
  show(130,160,"E");
  show(155,160,"T");
  show(180,160,"Y");
  show(210,160,"O");
  show(240,160,"U");
  show(270,160,"R");
  show(300,160,"F");
  show(330,160,"U");
  show(360,160,"T");
  show(390,160,"U");
  show(420,160,"R");
  show(450,160,"E");
  show(480,160,".");
  show(490,160,"C");
  show(520,160,"O");
  show(550,160,"M");
  rectangle(490,260,555,295);
  rectangle(491,261,554,294);
  settextstyle(3,0,1);
  show(500,265,"LOGIN");
  rectangle(100,260,150,295);
  rectangle(101,261,149,294);
  show(110,265,"EXIT");
  showmouseptr();
  return 0;
}

begin()
{
  for(int i=0; i<350; i++)
  {
    cleardevice();
    setcolor(BROWN);
    rectangle(10+i,200,250+i,220);
    rectangle(30+i,220,230+i,320);
    setcolor(WHITE);
    rectangle(80+i,150,180+i,199);
    line(90+i,165,105+i,185);
    line(105+i,185,120+i,165);
    line(120+i,165,135+i,185);
    line(142+i,165,142+i,185);
    circle(160+i,175,10);
    delay(10);
  }
  setcolor(LIGHTRED);
  settextstyle(3,0,6);
  show(5,200,"PROCESSING");
  for(i=0 ; i<=2; i++)
  {
    setcolor(LIGHTRED);
    for(int j=300; j<=330; j+=15)
    {
      delay(50);
      show(j,200,".");
    }
    setcolor(BLACK);
    for(j; j>=300; j-=15)
    {
      show(j,200,".");
    }
  }
  return 0;
}

/**************************************
    FUNCTIONS FOR MOUSE COORDINATES
**************************************/

mouse_srh_emp()
{
  while(1)
  {
    getmouse(&btn,&mouse_x,&mouse_y);
    if(btn==1)
    {
      if( mouse_x>=100 && mouse_x<=450 && mouse_y>=50 && mouse_y<=100 ) //VIEW EMPLOY
      {
	E.view_employs();
      }
      else if( mouse_x>=100 && mouse_x<=450 && mouse_y>=150 && mouse_y<=200 ) //POST OFFER
      {
	J.post_offer();
      }
      else if( mouse_x>=100 && mouse_x<=450 && mouse_y>=250 && mouse_y<=300 ) //MODIFY OFFER
      {
	J.modify_offer();
      }
      else if( mouse_x>=100 && mouse_x<=450 && mouse_y>=350 && mouse_y<=400 ) //DELETE OFFER
      {
	J.delete_offer();
      }
      else if( mouse_x>=500 && mouse_x<=600 && mouse_y>=30 && mouse_y<=65 ) //BACK
      {
	hidemouse();
	explore();
	showmouseptr();
	int option;
	option=mouse_explore();
	if(option==0)
	{
	  break;
	}
      }
    }
  }
  return 0;
}

mouse_srh_job()
{
  while(1)
  {
    getmouse(&btn,&mouse_x,&mouse_y);
    if(btn==1)
    {
      if( mouse_x>=100 && mouse_x<=450 && mouse_y>=50 && mouse_y<=100 ) //VIEW JOBS
      {
	J.view_jobs();
      }
      else if( mouse_x>=100 && mouse_x<=450 && mouse_y>=150 && mouse_y<=200 ) //ADD INFO
      {
	E.add_info();
      }
      else if( mouse_x>=100 && mouse_x<=450 && mouse_y>=250 && mouse_y<=300 ) //MODIFY INFO
      {
	E.modify_info();
      }
      else if( mouse_x>=100 && mouse_x<=450 && mouse_y>=350 && mouse_y<=400 ) //DELETE INFO
      {
	E.delete_info();
      }
      else if( mouse_x>=500 && mouse_x<=600 && mouse_y>=30 && mouse_y<=65 ) //BACK
      {
	hidemouse();
	explore();
	showmouseptr();
	int option;
	option=mouse_explore();
	if(option==0)
	{
	  break;
	}
      }
    }
  }
  return 0;
}

mouse_explore()
{
  while(1)
  {
    getmouse(&btn,&mouse_x,&mouse_y);
    if(btn==1)
    {
      if( mouse_x>=350 && mouse_x<=550 && mouse_y>=200 && mouse_y<=255 ) //SEARCH EMPLOY
      {
	hidemouse();
	Search_Employ();
	showmouseptr();
	int option;
	option=mouse_srh_emp();
	if(option==0)
	{
	  break;
	}
      }
      else if( mouse_x>=30 && mouse_x<=200 && mouse_y>=200 && mouse_y<=255 ) //SEARCH JOB
      {
	hidemouse();
	Search_Job();
	showmouseptr();
	int option;
	option=mouse_srh_job();
	if(option==0)
	{
	  break;
	}
      }
      else if( mouse_x>=500 && mouse_x<=600 && mouse_y>=30 && mouse_y<=65 ) //LOG OUT
      {
	hidemouse();
	process(1);
	login();
	int option;
	option=mouse_login();
	if(option==0)
	{
	  break;
	}
      }
    }
  }
  return 0;
}

mouse_login()
{
  while(1)
  {
     getmouse(&btn,&mouse_x,&mouse_y);
     if(btn==1)
     {
       if( mouse_x>=390 && mouse_x<=500 && mouse_y>=263 && mouse_y<=300 ) //REGISTER
       {
	 hidemouse();
	 process(1);
	 Register();
	 process(1);
	 login();
       }
       else if( mouse_x>=220 && mouse_x<=320 && mouse_y>=263 && mouse_y<=300 ) //SIGNIN
       {
	 hidemouse();
	 process(1);
	 int option=sign_in();
	 if(option==0)
	 {
	   break;
	 }
	 else if(option==1)
	 {
	   process(2);
	   explore();
	   showmouseptr();
	   option=mouse_explore();
	   if(option==0)
	   {
	     break;
	   }
	 }
	 else if(option==2)
	   login();
       }
       else if( mouse_x>=90 && mouse_x<=170 && mouse_y>=263 && mouse_y<=300 ) //BACK
       {
	 hidemouse();
	 Welcome();
	 showmouseptr();
	 int option;
	 option=mouse_welcome();
	 if(option==0)
	 {
	   break;
	 }
       }
     }
  }
  return 0;
}

mouse_welcome()
{
   while(1)
   {
     getmouse(&btn,&mouse_x,&mouse_y);
     if(btn==1)
     {
       if( mouse_x>=490 && mouse_x<=555 && mouse_y>=260 && mouse_y<=295) //LOGIN
       {
	 hidemouse();
	 process(1);
	 login();
	 int option;
	 option=mouse_login();
	 if(option==0)
	 {
	   break;
	 }
       }
       else if(mouse_x>=100 && mouse_x<=150 && mouse_y>=260 && mouse_y<=295) //EXIT
       {
	 hidemouse();
	 process(1);
	 return 0;
       }
     }
   }
   return 0;
}

/**************************************
           FUNCTION TO END 
**************************************/

end()
{
  cleardevice();
  for(int i=-50; i<380; i+=2)
  {
    cleardevice();
    setcolor(WHITE);
    line(0,300,640,300);
    setcolor(4);
    circle(100+i,285,15);
    circle(200+i,285,15);
    circle(100+i,285,5);
    circle(200+i,285,5);
    line(65+i,285,85+i,285);
    line(115+i,285,185+i,285);
    line(215+i,285,235+i,285);
    line(65+i,285,65+i,260);
    line(235+i,285,235+i,260);
    line(65+i,260,100+i,255);
    line(235+i,260,200+i,255);
    line(100+i,255,115+i,235);
    line(200+i,255,185+i,235);
    line(115+i,235,185+i,235);
    line(106+i,255,118+i,238);
    line(118+i,238,118+i,255);
    line(106+i,255,118+i,255);
    line(194+i,255,182+i,238);
    line(182+i,238,182+i,255);
    line(194+i,255,182+i,255);
    line(121+i,238,121+i,255);
    line(121+i,238,148+i,238);
    line(121+i,255,148+i,255);
    line(148+i,255,148+i,238);
    line(179+i,238,179+i,255);
    line(179+i,238,152+i,238);
    line(179+i,255,152+i,255);
    line(152+i,255,152+i,238);
    delay(20);
  }
  setcolor(GREEN);
  settextstyle(3,0,5);
  show(20,240,"DESIGNED BY TANAY");
  delay(2000);
  return 0;
}

/**************************************
            MAIN FUNCTION 
**************************************/

main()
{
  clrscr();
  int gd=DETECT, gm;
  initgraph(&gd, &gm, "C:/TURBOC3/BGI");
  mouse();
  hidemouse();
  begin();
  Welcome();
  showmouseptr();
  while(1)
  {
    int option;
    option=mouse_welcome();
    if(option==0)
    {
      break;
    }
  }
  end();
  closegraph();
  return 0;
}
