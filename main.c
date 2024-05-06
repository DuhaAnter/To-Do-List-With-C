#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
struct task
{
    int id;
    char content[50];
    char status [20];
    float duration;
};
typedef struct task task;
void Resize(task**t,int num,int newnum)
{

    //allocate new array w new size
    task *tr=malloc((num+newnum)*sizeof(task));
    //put data of old array in new array
    for(int i=0; i<num; i++)
    {
        tr[i]=(*t)[i];
    }
    //deallocate old array
    free(*t);
    //make my pointer point to new array
    *t=tr;
}
void addtask(task **t,int newnum,int num)
{
    for(int i=0; i<1; i++)
    {

        for(int j=num; j<newnum+num; j++)

        {
            SetColor(10);
            printf("Enter Data Of Task %i\n\n",j+1);
            SetColor(3);
            printf("ID of Task:\n");
            SetColor(15);
            scanf("%i",&t[i][j].id);
            printf("\n");
            SetColor(10);
            printf("Content of Task:\n");
            SetColor(15);
            scanf("%s",&t[i][j].content);
            printf("\n");
            strcpy(t[i][j].status,"Not Completed");
            SetColor(10);
            printf("Status : ");
            SetColor(4);
            printf("\nTask Not Completed\n");
            printf("\n");
            SetColor(10);
            printf("Duration of Task:\n");
            SetColor(15);
            scanf("%f",&t[i][j].duration);
        }
    }
}
void showtask(task **t,int num)
{
    for(int i=0; i<1; i++)
    {
        for(int j=0; j<num; j++)

        {
            SetColor(10);
            printf("ID: %i",t[i][j].id);
            printf("\t");
            SetColor(15);
            printf("Content: %s",t[i][j].content);
            printf("\t");
            SetColor(14);
            printf("duration: %f",t[i][j].duration);
            printf("\t");
            SetColor(15);
            printf("Status: %s",t[i][j].status);
            printf("\n\n");

        }
    }
}
void updatetask(task **t,int num,int id)
{
    for(int i=0; i<1; i++)
    {
        for(int j=0; j<num; j++)
        {

            if (t[i][j].id==id)
            {
                char newcontent[50];
                SetColor(10);
                printf("Enter New Content\n");
                SetColor(15);
                scanf("%s",&newcontent);
                strcpy( t[i][j].content,newcontent);
                float newduration;
                printf("\n");
                SetColor(10);
                printf("Enter New Duration\n");
                SetColor(15);
                scanf("%f",&newduration);
                t[i][j].duration =newduration;
                printf("\n\n");
                SetColor(10);
                printf("Update Done\n\nPress 0 for MENU\n");
                int p;
                SetColor(15);
                scanf("%i",&p);

            }
        }
    }
}
void mark(task **t,int num,int id)
{
    for(int i=0; i<1; i++)
    {
        for(int j=0; j<num; j++)
        {

            if (t[i][j].id==id)

            {
                strcpy( t[i][j].status,"Completed");
                SetColor(12);
                printf("Task Completed\n\n");
                SetColor(10);
                printf("Update Done\n\n\nPress 0 for MENU\n");
                int p;
                SetColor(15);
                scanf("%i",&p);
            }
        }
    }
}
int num;
// void main to end program when i need in key 4
void main()
{
    SetColor(14);
    printf("\t\t\t\t\t\tWelcome\n");
    printf("\n");
    printf("\n");
    SetColor(10);
    printf("How Many Tasks U Want To Complete Today ?\n");
    SetColor(15);
    scanf("%i",&num);
    printf("\n");
    system("cls");
    task *t[num];      // array of pointers to task
    for(int i=0; i<1; i++)
    {
        t[i]=(task*)malloc(num*sizeof(task));
        for(int j=0; j<num; j++)

        {
            SetColor(10);
            printf("Enter Data Of Task %i\n\n",j+1);
            SetColor(3);
            printf("ID of Task:\n");
            SetColor(15);
            scanf("%i",&t[i][j].id);
            printf("\n");
            SetColor(3);
            printf("Content of Task:\n");
            SetColor(15);
            scanf("%s",&t[i][j].content);
            printf("\n");
            strcpy(t[i][j].status,"Not Completed");
            SetColor(3);
            printf("Status :");
            SetColor(4);
            printf("\nTask Not Completed\n");
            printf("\n");
            SetColor(3);
            printf("Duration of Task:\n");
            SetColor(15);
            scanf("%f",&t[i][j].duration);
        }
    }
    system("cls");
    while(1)
    {
        SetColor(6);
        printf("\t\tMENU\n\n");
        SetColor(10);
        printf("Press 1 to add Task\nPress 2 to Update Certain Task or Show All Tasks\nPress 3 to Mark Task as Completed\nPress 4 to Exit Program\n");
        int key;
        SetColor(15);
        scanf("%i",&key);
        system("cls");
        if(key==1)
        {
            SetColor(10);
            printf("Enter New Number of Tasks\n");
            int newnum=0;
            SetColor(15);
            scanf("%i",&newnum);
            Resize(&t,num,newnum);
            addtask(&t,newnum,num);
            num=num+newnum;   // to use it in update if exist
            system("cls");
        }
        else if(key==2)
        {
            showtask(&t,num);
            SetColor(10);
            printf("\nEnter ID Of Task U Want To Update its (Content/Duration)  \n  ");
            int id;
            SetColor(15);
            scanf("%i",&id);
            updatetask(&t,num,id);
            system("cls");
        }
        else if(key==3)
        {
            showtask(&t,num);
            SetColor(10);
            printf("Enter ID Of Task U Want To Mark as Completed\n");
            int id;
            SetColor(15);
            scanf("%i",&id);
            mark(&t,num,id);
            system("cls");
        }
        else if(key=4)
        {
            return 0;

        }

    }
}
