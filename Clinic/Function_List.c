#include <stdio.h>
#include <stdlib.h>
#include"STD_TYPES.h"
#define Size_of_Slots 5

u32 length =0 ,id;
u16 z=0,y=0;
extern node head ;
void Add_new_patient_record(void)
{
    u32 age ;
    u8 name[100], gender[7];
    u16 record;
    node*Last;
    Last = &head;
    node*Last_1;
    Last_1 = &head;
    //Scan information.
    printf("Please, Enter The Id = ");
        scanf("%d",&id);
    printf("Please, Enter The Name : ");
        scanf(" %s",name);
    printf("Please, Enter The Age = ");
        scanf("%d",&age);
    printf("Please, Enter The Gender : ");
       scanf(" %s",gender);
    record = 1 ;

    if (length==0)
    {
        length++;

        head.ID = id ;
        strcpy(Last_1->Name,name);
        strcpy(Last_1->Gender,gender);
        head.Age = age ;
        head.Record = record ;
		head.Next  = NULL;
		printf("Patient Added.\nThank You.\n");
    }
    else
    {
        while ((Last->Next)!=NULL)
        {
           if ((Last->ID)== id)
        {
            printf("\n\nThe entered ID is already exists.\n\nPlease, Enter a correct ID.\n");
            z=1;
        }
        if ((Last->ID)== id)
            break;
        else
        {
            Last=Last->Next;
        }
        }

        if ((Last->Next)==NULL)
        {
            if ((Last->ID)==id)
            {
                printf("\n\nThe entered ID is already exists.\n\nPlease, Enter a correct ID.\n");
                z=1;
            }
        }
        if (z==0)
        {
            length++;

        node*last;
        node*new = (node*)malloc(sizeof(node));

        new->ID=id;
        strcpy(new->Name,name);
        strcpy(new->Gender,gender);
        new->Age=age;
        new->Record=record;

        printf("Patient Added.\nThank You.\n");

        new->Next=NULL;
        last=&head;
        while((last->Next)!=NULL)
        {
            last=last->Next;
        }
        last->Next=new;
        }
        }
}
void Edit_patient_record(void)
{
    u32 age;
    y=0;
    node*ptr_Record;
    ptr_Record = &head;

    printf("Please, Enter The Id = ");
    scanf("%d",&id);

    while ((ptr_Record->Next)!=NULL)
        {
           if ((ptr_Record->ID)== id)
        {
            printf("Please, Enter The New Age = ");
                scanf("%d",&age);

            ptr_Record->Record =ptr_Record->Record + 1;
            ptr_Record->Age =age ;
            y=1;
        }
        if ((ptr_Record->ID)== id)
            break;
        else
        {
            ptr_Record=ptr_Record->Next;
        }
        }

        if ((ptr_Record->Next)==NULL)
        {
            if ((ptr_Record->ID)==id)
            {
                printf("Please, Enter The New Age = ");
                scanf("%d",&age);

            ptr_Record->Record =ptr_Record->Record + 1;
            ptr_Record->Age =age ;
            y=1;
            }
        }
        if (y == 0)
        {
            printf("\n incorrect ID.\n\n");
        }
}

void Reserve_a_slot_with_the_doctor(void)
{
    u16 s ,ss, slot ;
    node*ptr_Slot;
    ptr_Slot = &head;

    node*Choose_Slot;
    Choose_Slot = &head;

    for (u8 i =1;i<=Size_of_Slots;i++)
    {
       while ((ptr_Slot->Next)!=NULL)
        {
           if ((ptr_Slot->Slot)== i)
        {
            s--;
        }
        if ((ptr_Slot->Slot)== i)
            break;
        else
        {
            ptr_Slot=ptr_Slot->Next;
        }
        }

        if ((ptr_Slot->Next)==NULL)
        {
            if ((ptr_Slot->Slot)==i)
            {
                s--;
            }
        }
        if (s==0)
        {
            printf("Solt %d is Available\n",i);
        }
        ptr_Slot = &head;
        s=0;
    }
    printf("Please, Enter The Id = ");
    scanf("%d",&id);

    printf("Please, Enter The a Slot from Available Slots = ");
    scanf("%d",&slot);

    y=0;

     while ((Choose_Slot->Next)!=NULL)
        {
           if ((Choose_Slot->ID)== id)
        {
            Choose_Slot->Slot =slot;
            y=1;
        }
        if ((Choose_Slot->ID)== id)
            break;
        else
        {
            Choose_Slot=Choose_Slot->Next;
        }
        }

        if ((Choose_Slot->Next)==NULL)
        {
            if ((Choose_Slot->ID)==id)
            {
                Choose_Slot->Slot =slot;
                y=1;
            }
        }
        if (y == 0)
        {
            printf("\n incorrect ID.\n\n");
        }

}

void Cancel_reservation(void)
{
    node*Cancel;
    Cancel = &head;

    printf("Please, Enter The Id = ");
    scanf("%d",&id);

    y=0;

     while ((Cancel->Next)!=NULL)
        {
           if ((Cancel->ID)== id)
        {
            Cancel->Slot =0;
            y=1;
        }
        if ((Cancel->ID)== id)
            break;
        else
        {
            Cancel=Cancel->Next;
        }
        }

        if ((Cancel->Next)==NULL)
        {
            if ((Cancel->ID)==id)
            {
                Cancel->Slot =0;
                y=1;
            }
        }
        if (y == 0)
        {
            printf("\n incorrect ID.\n\n");
        }

}

void View_patient_record(void)
{
    node*ptr_record;
    ptr_record = &head;
    y=0;

    printf("Please, Enter The Id = ");
    scanf("%d",&id);

    while ((ptr_record->Next)!=NULL)
        {
           if ((ptr_record->ID)== id)
        {
            printf("The Age of patient is %d\n",ptr_record->Age);
            printf("The record of patient '%s' is %d\n",ptr_record->Name,ptr_record->Record);
            y=1;

        }
        if ((ptr_record->ID)== id)
            break;
        else
        {
            ptr_record=ptr_record->Next;
        }
        if ((ptr_record->ID)== id)
            break;
        }

        if ((ptr_record->Next)==NULL)
        {
            if ((ptr_record->ID)==id)
            {
                printf("The Age of patient is %d\n",ptr_record->Age);
                printf("The record of patient '%s' is %d\n",ptr_record->Name,ptr_record->Record);
                y=1;
            }
        }
        if (y == 0)
        {
            printf("\n incorrect ID.\n\n");
        }
}

void View_today_reservations(void)
{
    node*Inf;
    Inf = &head;

    for (u8 i =1;i<=Size_of_Slots;i++)
    {
       while ((Inf->Next)!=NULL)
        {
           if ((Inf->Slot)== i)
        {
           printf("The id of The patient = %d\n",Inf->ID);
           printf("The Slot of The patient = %d\n",Inf->Slot);
        }
        if ((Inf->Slot)== i)
            break;
        else
        {
            Inf=Inf->Next;
        }
        }

        if ((Inf->Next)==NULL)
        {
            if ((Inf->Slot)==i)
            {
               printf("The id of The patient = %d\n",Inf->ID);
               printf("The Slot of The patient = %d\n",Inf->Slot);
            }
        }
        Inf = &head;

}
}
