#include <stdio.h>
#include <zephyr.h>
#include "signaling.h"

void signal_handle_calculation(struct k_sem *request, struct k_sem *response, struct signal_data *data){
    k_sem_take(request, K_FOREVER);     //wait for request to be given
    data->output = data->input +5;
    k_sleep(K_MSEC(1));
    k_sem_give(response);



}

int signal_request_calculate(struct k_sem *request, struct k_sem *response, struct signal_data *data){
    k_sem_give(request);
    int res = k_sem_take(response, K_MSEC(1000));
    return res;


}
