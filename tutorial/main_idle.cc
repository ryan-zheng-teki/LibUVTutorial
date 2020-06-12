#include <stdio.h>
#include <uv.h>
#include <time.h>

int64_t counter = 0;

struct tm *get_time()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return timeinfo;
}
void wait_for_a_while(uv_idle_t *handle)
{
    counter++;
    struct tm *timeinfo = get_time();
    printf("Current local time and date: %s", asctime(timeinfo));

    if (counter >= 10e6)
        uv_idle_stop(handle);
}

int main()
{
    uv_idle_t idler;

    uv_idle_init(uv_default_loop(), &idler);
    uv_idle_start(&idler, wait_for_a_while);

    printf("Idling...\n");
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_loop_close(uv_default_loop());
    return 0;
}