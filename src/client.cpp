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

    void *context = zmq->_ctx_new();
    void *requester = zmq->_socket_REQ(context);
    zmq->_connect(requester, "tcp://localhost:5555");

    while(1)
    {
        char buff_out[6] = "Hello";
        char buff_in[10];
        cout << "Sent message: " << buff_out<< endl;
        zmq->_send(requester, buff_out, 6, 0);
        zmq->_recv(requester, buff_in, 10, 0);
        cout << "Received message: " << buff_in << endl;
        sleep(1);
    }
    zmq->_close(requester);
    zmq->_ctx_destroy(context);
    return 0;
}
