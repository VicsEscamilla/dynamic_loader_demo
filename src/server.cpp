#include <iostream>
#include <unistd.h>

#include "zmq_wrapper.h"

using namespace std;

int main()
{
    ZmqWrapper zmq;
    void* context = zmq.zmq_ctx_new();
    void* responder = zmq.zmq_socket(context, ZMQ_REP);
    int rc = zmq.zmq_bind(responder, "tcp://*:5555");

    while(1)
    {
        char buff_in[10];
        char buff_out[6] = "hello";
        zmq.zmq_recv(responder, buff_in, 10, 0);
        cout << "Received Message: " << buff_in << endl;
        sleep(1);
        cout << "Sent Message: " << buff_out << endl;
        zmq.zmq_send(responder, buff_out, 6, 0);
    }

    return 0;
}
