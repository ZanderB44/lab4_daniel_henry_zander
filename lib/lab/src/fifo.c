#include "fifo.h"
#include <zephyr.h>
#include <stdio.h>
#include <random/rand32.h>

void fifo_worker_handler(struct k_msgq *requests, struct k_msgq *results, int id)
{
    struct request_msg cur_message;

    while(1){
         
        k_msgq_get(&requests, &cur_message, K_FOREVER);
        cur_message.output = cur_message.input + 5;
        cur_message.handled_by = id;
        k_msgq_put(&results, &cur_message, K_FOREVER);

    }
}