#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "include/ev.h"

static void sigint_callback(struct ev_loop * loop,ev_signal *w,int revents)
{
    if(revents & EV_SIGNAL)//\u7528\u8fd9\u4e2a\u53ef\u4ee5\u5224\u65ad\u8fd9\u6b21\u8fdb\u6765\u7684\u662f\u4e0d\u662fev_signal \u5982\u679c\u4e00\u4e2acallback\u56de\u8c03\u51fd\u6570\u590d\u7528\u7684\u8bdd\uff0c\u5c31\u53ef\u4ee5\u7528\u8fd9\u4e2a\u6765\u533a\u5206
    {
        printf("signal SIGINT\n");
        //ev_break(loop, EVBREAK_ONE);
        ev_signal_stop(loop, w);
    }
}

static void sigquit_callback(struct ev_loop * loop,ev_signal *w,int revents)
{
    printf("signal SIGQUIT\n");
    //ev_break(loop, EVBREAK_ALL);
    ev_signal_stop(loop, w);
}

int main(int argc, char **args)
{
    struct ev_loop * main_loop=ev_default_loop(0);

    ev_signal sigint_watcher;
    ev_signal sigquit_watcher;

    ev_init(&sigint_watcher,sigint_callback);
    ev_signal_set(&sigint_watcher,SIGINT/*Other want to catch*/);//\u8fd9\u91cc\u591a\u4e2a\u4fe1\u53f7\u4e0d\u80fd\u7528\u6216\u7b26\u53f7| \u8fde\u63a5\u8d77\u6765
    ev_signal_start(main_loop,&sigint_watcher);

    ev_init(&sigquit_watcher,sigquit_callback);
    ev_signal_set(&sigquit_watcher,SIGQUIT/*Other want to catch*/);
    ev_signal_start(main_loop,&sigquit_watcher);

    ev_run(main_loop,0);
	printf("End the main\n");
    return 0;
}

