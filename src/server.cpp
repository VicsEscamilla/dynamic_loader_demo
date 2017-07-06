#include <iostream>
#include <unistd.h>

#include "dynamic_loader.h"
#include "zmq_wrapper_interface.h"

using namespace std;

DynamicLoader dl("libzmq_wrapper.so");

ZmqWrapperInterface* getZmqHandler(void)
{
    auto access_point = (void* (*)(void))dl.getSymbol("getZmqWrapperInstance");
    if (access_point)
        return (ZmqWrapperInterface*)access_point();
    cout << "Unable to find libzmq_wrapper.so. The program will end." << endl;
    return NULL;
}

int main (void)
{
    ZmqWrapperInterface *zmq = getZmqHandler();

    if (!zmq)
        return 1;

    void* context = zmq->_ctx_new();
    void* responder = zmq->_socket_REP(context);
    int rc = zmq->_bind(responder, "tcp://*:5555");

    while(1)
    {
        char buff_in[10];
        char buff_out[6] = "hello";
        zmq->_recv(responder, buff_in, 10, 0);
        cout << "Received Message: " << buff_in << endl;
        sleep(1);
        cout << "Sent Message: " << buff_out << endl;
        zmq->_send(responder, buff_out, 6, 0);
    }

    return 0;
}
