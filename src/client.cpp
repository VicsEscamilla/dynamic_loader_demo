#include <iostream>
#include <unistd.h>

#include "zmq_wrapper.h"

using namespace std;

int main (void)
{
    ZmqWrapper zmq;
    void *context = zmq.zmq_ctx_new();
    void *requester = zmq.zmq_socket(context, ZMQ_REQ);
    zmq.zmq_connect(requester, "tcp://localhost:5555");

    while(1)
    {
        char buff_out[6] = "Hello";
        char buff_in[10];
        cout << "Sent message: " << buff_out<< endl;
        zmq.zmq_send(requester, buff_out, 6, 0);
        zmq.zmq_recv(requester, buff_in, 10, 0);
        cout << "Received message: " << buff_in << endl;
        sleep(1);
    }
    zmq.zmq_close(requester);
    zmq.zmq_ctx_destroy(context);
    return 0;
}
