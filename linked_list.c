#include <stdio.h>

typedef struct _linked_list{
    char *data;
    struct _linked_list * next;
}LINKED_LIST;

LINKED_LIST *linked_init(char * data){
    LINKED_LIST * head = (LINKED_LIST *)malloc(sizeof(LINKED_LIST));
    if(data){
        head->data = (char *)malloc(sizeof(char) * 12);    
        sprintf(head->data,"%s",data);
    }
    return head;
}

LINKED_LIST * linked_head_add(LINKED_LIST * head, char *data){
    if(!head){
        printf("head is null!!!  not init\n");
        return -1;
    }

    LINKED_LIST * ptr = head;    

    LINKED_LIST * add_linked = NULL;
    add_linked = malloc(sizeof(LINKED_LIST));
    add_linked->data = malloc(sizeof(char) * 12);

    sprintf(add_linked->data,"%s",data);

    if(ptr->next){
        add_linked->next = ptr->next;//假如head的next有东西，则将新的插入这中间
    }else{
        add_linked->next = NULL;
    }
    
    ptr->next = add_linked;
        
    return add_linked;
}

LINKED_LIST * linked_tail_add(LINKED_LIST * head, char *data){
    if(!head){
        printf("head is null!!!  not init\n");
        return -1;
    }

    LINKED_LIST * ptr = head;    
    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    LINKED_LIST * add_linked = NULL;
    add_linked = malloc(sizeof(LINKED_LIST));
    add_linked->data = malloc(sizeof(char) * 12);

    sprintf(add_linked->data,"%s",data);

    ptr->next = add_linked;
    add_linked->next = NULL;

    return add_linked;
}

LINKED_LIST * linked_find(LINKED_LIST * head, int index){
    if(!head){
        printf("head is null!!!  not init\n");
        return -1;
    }

    LINKED_LIST * ptr = head;    
    while(ptr->next != NULL && index >= 1){
        ptr = ptr->next;
        index--;
    }

    if(!ptr){
        printf("index exceed max num\n");
        return NULL;
    }

    return ptr;
}

int linked_delete(LINKED_LIST * head, LINKED_LIST * delet_linked){
    if(!delet_linked){
        printf("deleted_linked is null!!!\n");
        return -1;
    }
    
    if(!head){
        printf("head is null!!\n");
        return -1;
    }

    LINKED_LIST * ptr = head;

    int ret = 0;

    while(ptr->next && ptr->next->data && (ret = strcmp(ptr->next->data,delet_linked->data))){
        ptr = ptr->next;
    }

    if(ret){
        printf("not find deleted linked list!!!\n");
        return -1;
    }

    LINKED_LIST * tmpptr = ptr->next;

    ptr->next = ptr->next->next;

    free(tmpptr->data);
    free(tmpptr);

    return 0;
}

int linked_printf(LINKED_LIST * head){
    if(!head){
        printf("head is null\n");
        return -1;    
    }

    printf("===================================\n");
    LINKED_LIST * ptr = head;
    while(ptr){
        printf("data:%s \n",ptr->data);
        ptr = ptr->next;
    }

    return 0;
}

int main(){
    LINKED_LIST * head_ptr = linked_init(NULL);
    
    LINKED_LIST * point0 = NULL;
    point0 = linked_tail_add(head_ptr,"teststr0");

    LINKED_LIST * point1 = NULL;
    point1 = linked_tail_add(head_ptr,"teststr1");

    LINKED_LIST * point2 = NULL;
    point2 = linked_tail_add(head_ptr,"teststr2");

    LINKED_LIST * point3 = NULL;
    point3 = linked_tail_add(head_ptr,"teststr3");

    linked_printf(head_ptr);   

    LINKED_LIST * point4 = NULL;
    point4 = linked_tail_add(head_ptr,"teststr4");

    linked_printf(head_ptr);

    printf("======test add return print===========\n");
    printf("data:%s\n",point1->data);

    printf("======test find return print===========\n");
    LINKED_LIST * point5 = linked_find(head_ptr,4);
    printf("data:%s\n",point5->data);

    printf("======test delete print================\n");
    linked_delete(head_ptr,point4);
    linked_printf(head_ptr);


	return 0;
}
