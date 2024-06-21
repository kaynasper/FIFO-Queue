
#include <stdio.h>
#include <stdlib.h>

#include "my_fifo.h"


//<C>
int main() 
{
        queue_init();

        en_queue(1);
        en_queue(2);
        en_queue(3);
        en_queue(4);
        en_queue(5);
        en_queue(6);

        de_queue();
        de_queue();
        de_queue();
        de_queue();
        de_queue();
        de_queue();

        en_queue(5);
        en_queue(6);
        
        return 0;
}
