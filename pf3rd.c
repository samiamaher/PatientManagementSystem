void display_record()
{
	int counter = 0;
	FILE* fptr;
	struct patient p1;

	fptr = fopen("patient_record.txt", "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "not open");
		exit(0);
	}
	else
	{
		while (fread(&p1, sizeof(struct patient), 1, fptr))
		{
			counter++;
			printf("ID = %s\n", p1.id);
			printf("NAME = %s\n", p1.name);
			printf("CNIC = %s\n", p1.cnic);
			printf("PHONE = %s\n", p1.phone);
			printf("DISEASE = %s\n", p1.disease);
			printf("ISADMITTED = %c\n\n", p1.isadmit);
		}
		fclose(fptr);
	}
	if (counter == 0)
	{
		printf("No record Found\n");
	}
}
void update()
{

	FILE* fptr, * fptr1;
	struct patient p1;


	fptr = fopen("patient_record.txt", "r");
	fptr1 = fopen("update.txt", "w");

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
				if (strcmp(id, p1.id) == 0)
			{
				fflush(stdin);
                int op=0;
                puts("< MENU FOR UPDATION >");
                printf("1-Phone Number:\n2-Disease:\n3-isadmitted:\n");
                printf("SELECT OPTION: \n");
                scanf("%d",&op);
                if(op==3)
                {
				printf("isAdmiitted : ");
                fflush(stdin);
//				gets(p1.isadmit);
				scanf("%c",&p1.isadmit);
                }
                else if(op==1)
                {
                    printf("NUMBER: ");
                    fflush(stdin);
                    gets(p1.phone);
                }
                else if(op==2)
                {
                    printf("Disease: ");
                    fflush(stdin);
                    gets(p1.disease);
                }
			}
            	
				fwrite(&p1, sizeof(struct patient), 1, fptr1);

		}
		fclose(fptr);
		fclose(fptr1);
		fptr = fopen("patient_record.txt", "w");
		fptr1 = fopen("update.txt", "r");
		while (fread(&p1, sizeof(struct patient), 1, fptr1))
		{
			fwrite(&p1, sizeof(struct patient), 1, fptr);
		}
		fclose(fptr);
		fclose(fptr1);
		remove("update");
	}
}
void search()
{
    FILE* fptr;
	struct patient p1;
	fptr = fopen("patient_record.txt", "r");
    if (fptr == NULL)
	{
		printf("file not open");
	}
	else
	{
		char id[10];
        int flag=0;
		puts("Enter Id");
		scanf("%s", &id);
		while (fread(&p1, sizeof(struct patient), 1, fptr))
		{
				if (strcmp(id, p1.id) == 0)
			{
                flag==1;
               printf("RECORD IS FOUND.\n");
                  printf("ID = %s\n", p1.id);
			printf("NAME = %s\n", p1.name);
			printf("CNIC = %s\n", p1.cnic);
			printf("PHONE = %s\n", p1.phone);
			printf("DISEASE = %s\n", p1.disease);
			printf("ISADMITTED = %c\n\n", p1.isadmit);
		    }

         }
		fclose(fptr);
	}
}
