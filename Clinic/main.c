#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"STD_TYPES.h"
#include"Linked List.h"
#include"Function_List.c"
#define Size_of_Slots 5
node head;
void main()
{
    u8 Mode;
    u16 Exit =0,Select, Password =1234,Pass,user;
    u32 newValue,i=0;

    Choose_Mode: printf("Admin mode.\nUser mode\nPlease, Select The first Capital letter of what you need : ");
                 scanf(" %c",& Mode);

    switch (Mode)
    {
    case 'A':
    Admin_mode: printf("You are on the Admin mode\n");
    printf("Please, Enter The Password = ");
    scanf("%d",&Pass);
    while (Pass!=Password&&i<2)
    {
    printf("Please, Enter The Correct Password = ");
    scanf("%d",&Pass);
    i++;
    if (i==3)
    {
        printf("Thank you.");
        break;
    }
    }
    if (Pass == Password)
    {
        printf("The Password is Correct.\n");
        while (Exit == 0)
        {
            printf("To Add new patient record. Select 0\n");
		    printf("To Edit patient record. Select 1\n");
		    printf("To Reserve a slot with the doctor. Select 2\n");
		    printf("To Cancel reservation. Select 3\n");
		    printf("To Go to user Mode. Select 4\n");
		    printf("To exit. Select 5\n");
		    printf("Select what you need : ");
		    scanf("%d",&Select);
		    switch (Select)
		    {
		        case 0 :
            Add_new_patient_record();
            break;
                case 1 :
            Edit_patient_record();
            break;
                case 2 :
                    printf(" The Slot 1 From 2:00PM to 2:30PM \n The Slot 2 From 2:30PM to 3:00PM \n The Slot 3 From 3:00PM to 3:30PM \n The Slot 4 From 4:00PM to 4:30PM \n The Slot 5 From 4:30PM to 5:00PM \n\n");
            Reserve_a_slot_with_the_doctor();
            break;
                case 3 :
            Cancel_reservation();
            break;
                case 4 :
                    goto user_Mode;
                    break;
                case 5:
                    printf("Thank You.\nGood Bye.");
                    Exit = 1 ;
                    break;
        default:
            printf("Please, Enter a correct Selection.\n");
		    }
        }
    }
        break;
    case 'U':
        user_Mode: printf("You are on the User mode.\n");

        printf("To View patient record.Select(0)\nTo View today’s reservations.Select(1)\nTo Go to Admin mode.Select(2)\n");
        scanf("%d",&user);

        switch (user)
        {
        case 0 :
            View_patient_record();
            goto user_Mode;
            break;
        case 1 :
            View_today_reservations();
            goto user_Mode;
        break;
        case 2 :
            goto Admin_mode;
            break;
        default :
            printf("Please, Enter a correct Selection.\n");
        }
        break;
        default:
        printf("Enter A Correct letter.\n");
        goto Choose_Mode;
    }
}
