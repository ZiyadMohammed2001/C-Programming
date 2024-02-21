#include"D:\Imt\STD_TYPES\STD_TYPES.h"
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct Node_type node;

struct Node_type{
    u32 ID;
    u8 Name[100];
    u8 Gender[7];
    u16 Record;
    u32 Age;
    u8 Slot;
    node *Next;
};

void Add_new_patient_record(node head_1,u32 Id);
void Edit_patient_record(void);
void Reserve_a_slot_with_the_doctor(void);
void Cancel_reservation(void);
void View_patient_record(void);
void View_today_reservations(void);
#endif
