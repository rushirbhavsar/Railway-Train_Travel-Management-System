#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

struct Admin
{
    char adname[50],adpass[50];
    struct Admin *next;

}*adhead,*adtemp;

struct Train
{
    int tno,ttime;
    float prc,tarr,tdept;
    char tsrc[50],tdest[50],tname[50];
    struct Train *link;

}*thead,*ttemp;

struct Passenger
{
    int train,p_age,n;
    char pname[30],mobile_no[10],psrc[30],pdest[30],cclass[3],date[10];
    char gender[2];
    struct Passenger *next;

}*phead;

int found,choice,dd,mm,yy,train_no;
float tprice;
char name[50],pass[50],psrc[30];


void read_admin();
void write_admin();
void read_database();
void write_database();
void display_trains();
void delete_trains();
void insert_trains();
void Train_enquiry();
void add_admin();
void modify_admin();
void delete_admin();
void display_admin();
void book();
int  Book_Train();

int main()
{
    system("color f1");
    FILE *infile;
    do{
            printf("\n----------------------------------------------------------------------------\n");
            printf("                     Welcome to Railway Reservation System"                    );
            printf("\n----------------------------------------------------------------------------\n");
            printf("\tLog in as:\n");
            printf(" \n\t\t 1. ADMIN \n\n\t\t 2. USER \n\n\t\t 0. EXIT");
            printf("\n----------------------------------------------------------------------------\n");
            printf("                                                            "                    );
            printf("\n----------------------------------------------------------------------------\n");
            printf("\nChoice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                    case 1:
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                     Welcome ADMIN"                    );
                        printf("\n----------------------------------------------------------------------------\n");
                        read_admin();
                        adtemp=adhead;
                        int i=0;
                        printf("\n Enter Username : ");
                        scanf("%s",name);
                        printf("\n Enter  Password : ");
                                while (i<=9)
                                {
                                    pass[i]=getch();
                                    if(pass[i]==13)
                                    break;
                                    else printf("*");
                                    i++;
                                }
                                pass[i]='\0';
                        for(i=1;adtemp!=NULL;i++)
                        {
                            if((strcmp(adtemp->adname,name)==0)&&(strcmp(adtemp->adpass,pass)==0))
                                {
                                    found=1;
                                }
                            adtemp=adtemp->next;
                        }
                        if(found==1)
                        {
                            do
                            {
                                system("CLS");
                                printf("\n---------------------------------------------\n");
                                printf("                   Menu                      ");
                                printf("\n---------------------------------------------\n");
                                printf("\n\t1. Train Enquiry\n\t");
                                printf("2. Add new Train \n\t3. Delete existing Train");
                                printf("\n\t4. Display Train Data \n\t5. Admin Profile Settings \n\t0. EXIT \n\n\t");
                                printf("Choice:\t");
                                scanf("%d",&choice);

                                switch(choice)
                                    {
                                        case 0: exit(0);
                                                    break;
                                        case 1: system("CLS");
                                                Train_enquiry();
                                                break;

                                        case 2: system("CLS");
                                                insert_trains();
                                                display_trains();
                                                break;

                                        case 3: system("CLS");
                                                delete_trains();
                                                break;

                                        case 4: system("CLS");
                                                read_database();
                                                display_trains();
                                                break;

                                        case 5:
                                            do{

                                                    system("CLS");
                                                    printf("\n---------------------------------------------\n");
                                                    printf("              PROFILE SETTINGS                   ");
                                                    printf("\n---------------------------------------------\n");
                                                    printf("\n\t1. Add Admins\n\t");
                                                    printf("2. Change Username or Password");
                                                    printf("\n\t3. Delete Admin\n\t4. Display Admins\n\t0. EXIT \n\n\t");
                                                    printf("Choice:\t");
                                                    int choice1;
                                                    scanf("%d",&choice1);
                                                    switch(choice1)
                                                    {
                                                        case 1: system("CLS");
                                                                add_admin();
                                                                display_admin();
                                                                break;

                                                        case 2:system("CLS");
                                                               modify_admin();
                                                               display_admin();
                                                               break;

                                                        case 3:system("CLS");
                                                               delete_admin();
                                                               display_admin();
                                                               break;

                                                        case 4:system("CLS");
                                                               display_admin();
                                                               break;

                                                        case 0:system("CLS");
                                                                exit(0);
                                                               break;

                                                    }
                                                    printf("\n----------------------------------------------------------------------------\n");
                                                    printf("\n\t Want to Continue[Profile Setting] (y/n):\t");
                                                    char ch1;
                                                    scanf("%c",&ch1);
                                                    scanf("%c",&ch1);
                                                    if (ch1=='y' || ch1=='Y');
                                                    else
                                                        break;

                                               }while(1);

                                        }
                                printf("\n----------------------------------------------------------------------------\n");
                                printf("\n\tWant to Continue[Main Menu] (y/n):\t");
                                char ch;
                                scanf("%c",&ch);
                                scanf("%c",&ch);
                                if (ch=='y' || ch=='Y');
                                else
                                    exit(0);
                                }
                                while(1);

                        }
                        else
                        {
                            system("CLS");
                            printf("\n\n\n\t!! INVALID CREDENTIALS ...... Enter Correct Username And Password !!\n\n");
                        }
                        break;

                    case 2:
                        do
                        {
                            int choice1;
                            system("CLS");
                            printf("\n---------------------------------------------\n");
                            printf("                 USER Menu                      ");
                            printf("\n---------------------------------------------\n");
                            printf("\n\t1. Book ticket\n\t");
                            printf("\n\t2. Train Enquiry\n\t");
                            printf("\n\t0. Exit\n\t");
                            printf("\nChoice:\t");
                            scanf("%d",&choice1);
                            switch(choice1)
                            {
                                case 0: exit(0);
                                        break;
                                case 1:
                                        system("CLS");
                                        printf("\n----------------------------------------------------------------------------\n");
                                        printf("                     Ticket Booking"                    );
                                        printf("\n----------------------------------------------------------------------------\n");
                                        book();
                                        //trainselect();
                                        //payout();
                                        break;

                                case 2: system("CLS");
                                        Train_enquiry();
                                        break;
                            }
                            printf("\n----------------------------------------------------------------------------\n");
                            printf("\n\tWant to Continue[Main Menu] (y/n):\t");
                            char ch;
                            scanf("%c",&ch);
                            scanf("%c",&ch);
                            if (ch=='y' || ch=='Y');
                            else
                                exit(0);

                        }while(1);

                    case 0: exit(0);
            }
    }while(!found==1);

}


void book()
{

    int i,value,valid,dd,mm,yy;
    struct Passenger *temp,*newnode=NULL;
        newnode=(struct Passenger*)malloc(sizeof(struct Passenger));
        phead=(struct Passenger*)malloc(sizeof(struct Passenger));
        newnode->next=NULL;
        printf("\n\tSource:\t\t");      //source of travel
        scanf("%s",newnode->psrc);
        strcpy(psrc,newnode->psrc);
        printf("\n\tDestination:\t");     //destination of travel
        scanf("%s",newnode->pdest);
        value=Book_Train(newnode->psrc,newnode->pdest);
        if (value==0)
        {
            do{
                //char buffer[5];
                //char buffer1[5];
                //char buffer2[5];
                time_t s, val = 1;
                struct tm* current_time;
                s = time(NULL);
                current_time = localtime(&s);
                printf("\n\t\t SYSTEM DATE:\t%d/%d/%d",current_time->tm_mday,(current_time->tm_mon + 1),(current_time->tm_year + 1900));

                printf("\n\n\tEnter the Date of travel(dd/mm/yyyy):\t\t");
                scanf("%d/%d/%d",&dd,&mm,&yy);
                printf("\nDate : %d/%d/%d",dd,mm,yy);
                valid = 0;
                if (yy != 0)
                {
                    if (mm >= 1 && mm <= 12)
                    {
                        int mdays;
                        if (mm == 2)
                            mdays = (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0) ? 29 : 28;
                        else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
                            mdays = 30;
                        else
                            mdays = 31;
                        if (dd >= 1 && dd <= mdays)
                            valid = 1;
                        if (dd<current_time->tm_mday && yy<current_time->tm_year + 1900)
                            valid=1;
                    }

                }
                else
                {
                     printf("\n\t\t Invalid Date .....!!!!!!\n");
                }

            }while(valid == 0);

                system("CLS");
                //printf("\nDate : %d/%d/%d",dd,mm,yy);
                printf("\n----------------------------------------------------------------------------\n");
                printf("\n\tTotal Number of passenger:\t\t");
                scanf("%d",&(newnode->n));
                phead=newnode;
                printf("\n----------------------------------------------------------------------------\n");
                printf("                             PASSENGER Details                   "                    );
                printf("\n----------------------------------------------------------------------------\n");
                printf("\n----------------------------------------------------------------------------");
                printf("\n\tEnter Details of Passenger 1\n");
                printf("----------------------------------------------------------------------------\n");
                printf("\n\tEnter the Passenger Name:\t");
                scanf("%s",newnode->pname);
                printf("\n\tAge:\t\t");
                scanf("%d",&(newnode->p_age));
                printf("\n\tGender(M/F):\t\t");
                scanf("%s",newnode->gender);
                    do{
                     printf("\n\tMobile No:\t\t");
                    scanf("%s",newnode->mobile_no);
                    if(strlen(newnode->mobile_no)!=10){
                          printf("\n\t\tInvalid MOBILE NO ....!!!!!!!\n") ;
                    }
                    }while(strlen(newnode->mobile_no)!=10);

                //fflush();
                //printf("\n\tEmail id:\t\t");
                //scanf("%s",newnode->email);
                printf("\n\tClass of travel \n\t 1. Sleeper=SL \n\t 2. AC_2_Tier=2AC \n\t 3. AC_3_Tier=3AC\t:\t");
                scanf("%s",newnode->cclass);
                newnode->train=train_no;
                temp=newnode;
                phead=newnode;
                for (i=1;i<phead->n;i++)
                {
                    newnode=(struct Passenger*)malloc(sizeof(struct Passenger));
                    newnode->next=NULL;
                    printf("\n----------------------------------------------------------------------------");
                    printf("\n\tEnter Details of Passenger %d\n",i+1);
                    printf("----------------------------------------------------------------------------\n");
                    printf("\n\tEnter the Passenger Name:\t");
                    scanf("%s",newnode->pname);
                    printf("\n\tAge:\t\t");
                    scanf("%d",&(newnode->p_age));
                    printf("\n\tGender(M/F):\t\t");
                    scanf("%s",newnode->gender);
                        do{
                         printf("\n\tMobile No:\t\t");
                        scanf("%s",newnode->mobile_no);
                        if(strlen(newnode->mobile_no)!=10){
                              printf("\n\t\tInvalid MOBILE NO ....!!!!!!!\n") ;
                        }
                        }while(strlen(newnode->mobile_no)!=10);

                    //printf("\n\tEmail id:\t\t");
                    //scanf("%s",newnode->email);
                    printf("\n\tClass of travel \n\t 1. Sleeper=SL \n\t 2. AC_2_Tier=2AC \n\t 3. AC_3_Tier=3AC\t:\t");
                    scanf("%s",newnode->cclass);
                    newnode->train=train_no;
                    temp->next=newnode;
                    temp=newnode;
                }
                system("CLS");
        //***Display****//
            printf("\n\n\tBooked Tickets\n\n");
            printf("\nDate : %d/%d/%d",dd,mm,yy);
            printf("\nSOURCE : %s",psrc);
            printf("\nDESTINATON : %s",phead->pdest);
            printf("\nTRAIN NO : %d",phead->train);
            temp=phead;
            int j=1;
            while(temp!=NULL)
            {
                printf("\n\n----------------------------------------------------------------------------");
                printf("\n\tPASSENGER %d\n",j);
                printf("----------------------------------------------------------------------------\n\n");
                printf("\tName: %s\n",temp->pname);
                printf("\tAge : %d\n",temp->p_age);
                printf("\tGender : %s\n",temp->gender);
                printf("\tMobile No : %s\n",temp->mobile_no);
                //printf("Email : %s\n",temp->email);
                printf("\tClass : %s",temp->cclass);
                temp=temp->next;
                j++;
            }
            printf("\n\n----------------------------------------------------------------------------");
            printf("\n\tAmount\n",j);
            printf("----------------------------------------------------------------------------\n");
            printf("\n\tTotal Amount to be paid : %f",tprice*phead->n);
            printf("\n\n\n\tYour ticket has been successfully booked");
        }

}

void read_admin()
{
  int i,filempty=0;
	FILE *py=fopen("Admin.txt","r");
	adtemp=adhead;
	fseek(py,0,SEEK_END);
	if(adtemp==NULL)
	{
        adtemp=(struct Admin*)malloc(sizeof(struct Admin));
        adhead=adtemp;
	}
	int len=(int)ftell(py);
	if(len<=0)
	{
        filempty=1;
        adtemp=NULL;
        adhead=adtemp;
	}
	if(filempty==0)
	{
        rewind(py);
        while(fscanf(py,"%s\t%s\n",adtemp->adname,adtemp->adpass))
        {
            if(feof(py))
            {
                break;
            }
            adtemp->next=(struct Admin*)malloc(sizeof(struct Admin));
            adtemp=adtemp->next;
            adtemp->next=NULL;
        }
	}
	//fclose(py);

}

void read_database()
{
	int i,filempty=0;
	FILE *infile=fopen("Railway_database.txt","r");
	ttemp=thead;
	fseek(infile,0,SEEK_END);
	if(ttemp==NULL)
	{
        ttemp=(struct Train*)malloc(sizeof(struct Train));
        thead=ttemp;
	}
	int len =(int)ftell(infile);
	if(len<=0)
	{
        filempty=1;
        printf("File empty");
        ttemp=NULL;
        thead=ttemp;
	}
	if(filempty==0)
	{
        rewind(infile);
        while(fscanf(infile,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",&(ttemp->tno),ttemp->tsrc,ttemp->tdest,ttemp->tname,&(ttemp->prc),&(ttemp->tarr),&(ttemp->tdept),&(ttemp->ttime)))
        {
            if(feof(infile))
            {
                break;
            }
            ttemp->link=(struct Train*)malloc(sizeof(struct Train));
            ttemp=ttemp->link;
            ttemp->link=NULL;
        }
    }
}

void write_database()
{
	FILE *ne=fopen("Railway_database.txt","w");
	int i;
	struct Train *temp;
	temp=thead;
	if(temp==NULL)
	{
	    printf("Empty File");
	}
	else
	{
        for(i=0;temp!=NULL;i++)
        {
            fprintf(ne,"\n%d\t\t %s\t\t %s\t\t %s\t\t %f\t\t %f\t\t %f\t\t %d",(temp->tno),temp->tsrc,temp->tdest,temp->tname,temp->prc,temp->tarr,temp->tdept,(temp->ttime));
            temp=temp->link;
        }
	}
	fclose(ne);
}

void display_trains()
{
    //read_database();
	ttemp=thead;
	if(ttemp==NULL)
	{
        printf("list is empty");
	}
	else
    {
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        printf("Train No|| Source || Destination ||    Train name    || Price(Rs) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
        for(int i=0;ttemp!=NULL;i++)
        {
            printf("\n%d\t %s\t\t %s\t\t %s\t %.2f\t\t %.2f\t\t    %.2f\t\t %d",(ttemp->tno),ttemp->tsrc,ttemp->tdest,ttemp->tname,ttemp->prc,ttemp->tarr,ttemp->tdept,(ttemp->ttime));
            ttemp=ttemp->link;
        }
    }
}

void delete_trains()
{
    read_database();
    struct Train *temp,*ptr;
    temp=thead;
    int i=1,val;
    printf("Enter Train number you want to delete : ");
    scanf("%d",&val);
    if (temp->tno==val)
    {
        thead=temp->link;
        printf("\n\n\t\tThe Train is successfully deleted\n\n");
        display_trains();
    }
    else{
        while(temp->link!=NULL)
        {
            if(temp->link->tno==val)
            {
                i=0;
                break;
            }
            else
                temp=temp->link;
        }
        if (i==0)
        {
            ptr=temp;
            temp=temp->link;
            ptr->link=temp->link;
            printf("\n\n\t\tThe Train is successfully deleted\n\n");
            display_trains();
        }
        else
            printf("\n\n\t\tOops the train does not exist\n\n");

    }

    write_database();
}

void insert_trains()
{
    read_database();
    int n;
    struct Train *temp,*newnode;
    temp=thead;
    newnode=(struct Train *)malloc(sizeof(struct Train));
    printf("Enter Train number : ");
    scanf("%d",&n);
    while(temp!=NULL)
    {
        if (temp->tno==n)
        {
            system("CLS");
            printf("\n\n\t\tThis train no. already exist\n\n");
            insert_trains();
        }
        temp=temp->link;
    }

        newnode->tno=n;
        printf("Enter Train source : ");
        scanf("%s",&newnode->tsrc);
        printf("Enter Train destination : ");
        scanf("%s",&newnode->tdest);
        printf("Enter Train name : ");
        scanf("%s",&newnode->tname);
        printf("Enter Price : ");
        scanf("%f",&newnode->prc);
        printf("Enter Arrival time : ");
        scanf("%f",&newnode->tarr);
        printf("Enter Departure time : ");
        scanf("%f",&newnode->tdept);
        printf("Enter Duration of journey: ");
        scanf("%d",&newnode->ttime);

    temp=thead;
    while(temp->link!=NULL)
    {
         temp=temp->link;
    }
    newnode->link=temp->link;
    temp->link=newnode;
    printf("\n\n\t\tThe Train is successfully inserted\n\n");
    write_database();
    //display_trains();

}

void Train_enquiry()
{
    read_database();
    int i=0;
    char src[50],des[50];
    printf("Enter source : ");
    scanf("%s",src);
    printf("Enter destination : ");
    scanf("%s",des);
    struct Train *temp;
    temp=thead;
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Price(Rs) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
    while(temp!=NULL)
    {
        if ((strcmp(src,temp->tsrc)==0) && (strcmp(des,temp->tdest)==0))
        {
            i=1;
            printf("\n%d\t %s\t\t %s\t\t %s\t %.2f\t\t %.2f\t\t    %.2f\t\t %d",(temp->tno),temp->tsrc,temp->tdest,temp->tname,temp->prc,temp->tarr,temp->tdept,(temp->ttime));
        }
        temp=temp->link;
    }
    if (i==0)
    {
        system("CLS");
        printf("\n\n\t\tOops there is no train between %s to %s\n\n",src,des);
    }
}

void add_admin()
{
    int i=0;
    read_admin();
    char str1[50],str2[50];
    printf("\n Enter New Admin Name:\t");
    scanf("%s",str1);
    printf("\n Enter New Admin Password:\t");
    while (i<=9)
    {
        str2[i]=getch();
        if(str2[i]==13)
        break;
        else printf("*");
        i++;
    }
    str2[i]='\0';

    struct Admin *temp,*newnode;
    newnode=(struct Admin*)malloc(sizeof(struct Admin));
    temp=adhead;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    strcpy(newnode->adname,str1);
    strcpy(newnode->adpass,str2);
    newnode->next=NULL;
    temp->next=newnode;
	write_admin();
    printf("\n\t!!   Admin Profile Created Successfully !!");
}

void write_admin()
{
    FILE *ppy=fopen("Admin.txt","w");
	int i;
	struct Admin *temp;
	temp=adhead;
	if(temp==NULL)
	{
	    printf("list is empty");
	}
	else
	{
        for(i=0;temp!=NULL;i++)
        {
            fprintf(ppy,"%s\t%s\n",temp->adname,temp->adpass);
            temp=temp->next;
        }
	}
	fclose(ppy);
}

void modify_admin()
{
    read_admin();int i=0;
    struct Admin *temp;
    temp=adhead;
    while(temp!=NULL)
    {
        if((strcmp(temp->adname,name)==0)&&(strcmp(temp->adpass,pass)==0))
        {
            break;
        }
        temp=temp->next;
    }
    printf("Enter new Username : ");
    scanf("%s",name);
    printf("\nEnter new Password : ");
    while (i<=9)
    {
        pass[i]=getch();
        if(pass[i]==13)
        break;
        else printf("*");
        i++;
    }
     pass[i]='\0';
     strcpy(temp->adname,name);
     strcpy(temp->adpass,pass);
     printf("\n\n\t\tThe username and Password are successfully changed\n\n");
     write_admin();
}

void delete_admin()
{
    read_admin();
    struct Admin *temp,*ptr;
    temp=adhead;
    int i=1;char val[50];
    printf("Enter Username you want to delete : ");
    scanf("%s",val);
    if (strcmp(temp->adname,val)==0)
    {
        adhead=temp->next;
        printf("\n\n\t\tThe Username is successfully deleted\n\n");
    }
    else{
        while(temp->next!=NULL)
        {
            if (strcmp(temp->next->adname,val)==0)
            {
                i=0;
                break;
            }
            else
                temp=temp->next;
        }
        if (i==0)
        {
            ptr=temp;
            temp=temp->next;
            ptr->next=temp->next;
            printf("\n\n\t\tThe Admin is successfully deleted\n\n");
        }
        else
            printf("\n\n\t\tOops the Username does not exist\n\n");

    }
    write_admin();
}

void display_admin()
{
    int i;
    read_admin();
    struct Admin *temp;
	temp=adhead;
	if(temp==NULL)
	{
        printf("list is empty");
	}
	else
	{
        for(i=0;temp!=NULL;i++)
        {
            printf("\n\tAdmin Name:\t\t");
            printf("%s",temp->adname);
            printf("\t\tPassword:\t\t");
            printf("%s",temp->adpass);

            temp=temp->next;

        }
	}
}

int  Book_Train(char src[], char des[])
{
    read_database();
    int i=0;
    struct Train *temp;
    temp=thead;
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Train No|| Source || Destination ||    Train name    || Price(Rs) || Arr. time(Hrs) || Dept. time(Hrs) || Duration||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
    while(temp!=NULL)
    {
        if ((strcmp(src,temp->tsrc)==0) && (strcmp(des,temp->tdest)==0))
        {
            i=1;
            printf("\n%d\t %s\t\t %s\t\t %s\t %.2f\t\t %.2f\t\t    %.2f\t\t %d",(temp->tno),temp->tsrc,temp->tdest,temp->tname,temp->prc,temp->tarr,temp->tdept,(temp->ttime));
        }
        temp=temp->link;
    }
    if (i==0)
    {
        system("CLS");
        printf("\n\n\t\tOops there is no train between %s to %s\n\n",src,des);
        int check=1;
        return check;
    }

    label:
    printf("\n\nEnter the train no : \t");
    scanf("%d",&train_no);
    temp=thead;
    int val=0;
    while(temp!=NULL)
    {
        if ((temp->tno==train_no) && (strcmp(src,temp->tsrc)==0) && (strcmp(des,temp->tdest)==0))
        {
          val=1;
          tprice=temp->prc;
        }

        temp=temp->link;
    }
    if (val==0)
    {
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\tOops this train is not traveling between %s to %s\n",src,des);
        printf("\t\tPls Enter valid Train no.\n");
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        goto label;
    }

}
