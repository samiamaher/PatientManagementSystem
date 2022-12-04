#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
void menu();
void add_patient();
void del_patient();
void display_record();
void update();
void search();
int name_checker(char array[]);
struct patient
{
    char id[30];
    char name[30];
    char cnic[11];
    char phone[12];
    char disease[20];
    char isadmit;
};

int main()
{
    FILE* fptr;
    fptr = fopen("patient_record.txt", "r");
    if (fptr == NULL)
    {
        fptr = fopen("patient_record.txt", "w");
    }
    fclose(fptr);
    puts("\t\t\t************************************************************************\n");
    printf("\t\t\t\t\t  PATIENTS RECORD USING FILE HANDLING.\n");
    printf("\n");
    puts("\t\t\t************************************************************************\n");
    menu();
}

void add_patient()
{

    struct patient p1;
    FILE* fp = NULL;
    
    char id[30];
    fflush(stdin);
    printf("Enter id of patient: ");
    gets(id);
    fflush(stdin);
    int check = 0;
    int flag = 1;
    while (flag)
    {
        fp = fopen("patient_record.txt", "r");
        check = 0;
        while (fread(&p1, sizeof(struct patient), 1, fp))
        {
            if (strcmp(p1.id, id) == 0)
            {
                fflush(stdin);
                printf("Record already exists.\n");
                puts("Enter vailid id  (in integer):");
                printf("id: ");
                gets(id);
                check = 1;
            }
        }
        fclose(fp);
        if (check == 0)
        {
            strcpy(p1.id, id);
            flag = 0;
        }
    }
    fflush(stdin);
    char name[30];
    puts("Enter name of patient:");
    gets(p1.name);
    while(!name_checker(p1.name))
    {
    	fflush(stdin);
    	puts("Enter valid name of patient:");
    	gets(p1.name);
	}
    fflush(stdin);
    puts("Enter CNIC of patient: ");
    gets(p1.cnic);
    fflush(stdin);
    puts("Enter number of patient:");
    gets(p1.phone);
    fflush(stdin);
    puts("Enter Desease of patient:");
    gets(p1.disease);
    fflush(stdin);
    puts("Enter isadmitted of patient:");
    scanf("%c",&p1.isadmit);
    fflush(stdin);
    while(p1.isadmit != '0' && p1.isadmit != '1')
	{
        puts("Enter valid input for admit:\n1-0\t\t\t2-1\n");
		scanf("%c",&p1.isadmit);
        fflush(stdin);
    }
    fflush(stdin);
    fp = fopen("patient_record.txt", "a");
    fwrite(&p1, sizeof(struct patient), 1, fp);
    fclose(fp);
}
int name_checker(char array[])
{
    struct patient p1;
    int check = 1;
size_t i ;
    for (i= 0; array[i]!='\0'; i++)
    {
        char num = array[i];
        if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    
    return check;
}
void menu()
{
    int choice = 0;
    do
    {
        puts("\t\t\t\t\t\t\t<MENU>\n");
        printf("\t\t\t\tENTER THE NUMBER TO SELECT THE FOLLOWING OPTIONS: \n");
        puts("");
        printf("\t\t\t1. Add a patient ? \t\t\t\t 2. Delete a record ? \n");
        printf("\t\t\t3. Update  a record ? \t\t\t\t 4. Search a particular record ? \n");
        printf("\t\t\t5. Display record ? \n");
        printf("\t\t\t6. Exit\n ");
        puts("SELECT AN OPTION:");

        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1)
        {
            add_patient();
        }
        else if (choice == 2)
        {
             del_patient();
        }
        else if (choice == 3)
        {
             update();
        }
       else if (choice == 4)
        {
            search();
        }
       else if (choice == 5)
        {
             display_record();
        }
       else if (choice == 6)
        {
            break;
        }
    } while (choice != 6);
}

void del_patient()
{

	FILE* fptr, * fptr1;
	struct patient p1;


	fptr = fopen("patient_record.txt", "r");
	fptr1 = fopen("del.txt", "w");

	if (fptr == NULL)
	{
		printf("file not open");
	}
	else
	{

		char id[10];
		puts("Enter Id");
		scanf("%s", &id);
		while (fread(&p1, sizeof(struct patient), 1, fptr))
		{
//			if (id != p1.id)
			if(strcmp(id,p1.id) != 0)
			{
				fwrite(&p1, sizeof(struct patient), 1, fptr1);
			}
        }
		fclose(fptr);
		fclose(fptr1);
		fptr = fopen("patient_record.txt", "w");
		fptr1 = fopen("del.txt", "r");
		while (fread(&p1, sizeof(struct patient), 1, fptr1))
		{
			fwrite(&p1, sizeof(struct patient), 1, fptr);
		}
		fclose(fptr);
		fclose(fptr1);
		remove("del.txt");
	}
}


