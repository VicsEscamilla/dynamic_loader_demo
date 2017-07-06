#include <string>

#include <zmq.h>

#include "zmq_wrapper.h"

using namespace std;

ZmqWrapper::ZmqWrapper(void){}

ZmqWrapper::~ZmqWrapper(void){}

void* ZmqWrapper::_ctx_new(void)
{
    return zmq_ctx_new();
}

void* ZmqWrapper::_socket(void *context, int type)
{
    return zmq_socket(context, type);
}

void* ZmqWrapper::_socket_REP(void *context)
{
    return zmq_socket(context, ZMQ_REP);
}

void* ZmqWrapper::_socket_REQ(void *context)
{
    return zmq_socket(context, ZMQ_REQ);
}

int ZmqWrapper::_bind(void *socket, const char *endpoint)
{
    return zmq_bind(socket, endpoint);
}

int ZmqWrapper::_send(void *socket, void *buf, size_t len, int flags)
{
    return zmq_send(socket, buf, len, flags);
}

int ZmqWrapper::_recv(void *socket, void *buf, size_t len, int flags)
{
    return zmq_recv(socket, buf, len, flags);
}

int ZmqWrapper::_close(void *socket)
{
    return zmq_close(socket);
}

int ZmqWrapper::_connect(void *socket, const char *endpoint)
{
    return zmq_connect(socket, endpoint);
}

int ZmqWrapper::_ctx_destroy(void *context)
{
    return zmq_ctx_destroy(context);
}
