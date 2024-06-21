
#include <stdio.h>
#include <stdlib.h>


#define SIZE (4)

int set[SIZE];
int current_index, empty_state = 0;

int *front, *back;


void print_set() 
{
        printf("[ ");
        for (int z=0 ; z<(current_index+1) ; z++) {
                printf(" %i ", set[z]);
        }; printf(" ]\n");
}


int check_ret() 
{
        for (int a=0 ; a<SIZE ; a++) {
                if (set[a] == -1) {
                        current_index = a;
                        return 0;
                }
        }

        return 1;
}


int en_queue(int value) 
{       
        empty_state = 0;
        
        if (check_ret() == 1) {
                puts("|||Queue Full!|||"); return 0;
        }

        set[current_index] = value;
        back = &set[current_index];

        printf("\nEn-queued %i\n", value);
        print_set();

        return 0;
}


int de_queue() 
{
        int ret = set[0];
        
        for (int i=0 ; i<(SIZE-1) ; i++) {
                set[i] = set[i+1];
        }

        set[SIZE - 1] = -1;
        front = &set[0];
        
        printf("\nRemoved : %i\n", ret);
        check_ret();
        
        if (empty_state == 1) { 
                puts("|||Empty|||");
                return 1;
        }

        current_index -= 1;
        print_set();
        current_index += 1;

        back = &set[current_index-1];
        if (front == back) empty_state = 1;
        
        return 0;
}


int queue_init() {
        for (int x=0 ; x<SIZE ; x++) {
                set[x] = -1;
        }

        front = &set[0];
        back = &set[0];

        return 0;
}
