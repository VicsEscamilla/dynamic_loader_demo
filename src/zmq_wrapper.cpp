#include <string>

#include "zmq_wrapper.h"

using namespace std;

ZmqWrapper::ZmqWrapper(void) : DynamicLoader("libzmq.so"),
                   ctx_new(NULL), socket(NULL), bind(NULL),
                   recv(NULL), send(NULL), close(NULL),
                   connect(NULL)
{
    if (isLoaded())
    {
        ctx_new = (zmq_ctx_new_func_t)getSymbol("zmq_ctx_new");
        socket = (zmq_socket_func_t)getSymbol("zmq_socket");
        bind = (zmq_bind_func_t)getSymbol("zmq_bind");
        recv = (zmq_recv_func_t)getSymbol("zmq_recv");
        send = (zmq_send_func_t)getSymbol("zmq_send");
        close = (zmq_close_func_t)getSymbol("zmq_close");
        connect = (zmq_connect_func_t)getSymbol("zmq_connect");
        ctx_destroy = (zmq_ctx_destroy_func_t)getSymbol("zmq_ctx_destroy");
    }
}

ZmqWrapper::~ZmqWrapper(void){}

void* ZmqWrapper::zmq_ctx_new(void)
{
    if (!ctx_new)
        return NULL;
    return (*ctx_new)();
}

void* ZmqWrapper::zmq_socket(void *context, int type)
{
    if (!socket)
        return NULL;
    return (*socket)(context, type);
}

int ZmqWrapper::zmq_bind(void *socket, const char *endpoint)
{
    if (!bind)
        return -1;
    return (*bind)(socket, endpoint);
}

int ZmqWrapper::zmq_send(void *socket, void *buf, size_t len, int flags)
{
    if (!send)
        return -1;
    return (*send)(socket, buf, len, flags);
}

int ZmqWrapper::zmq_recv(void *socket, void *buf, size_t len, int flags)
{
    if (!recv)
        return -1;
    return (*recv)(socket, buf, len, flags);
}

int ZmqWrapper::zmq_close(void *socket)
{
    if (!close)
        return -1;
    return (*close)(socket);
}

int ZmqWrapper::zmq_connect(void *socket, const char *endpoint)
{
    if (!connect)
        return -1;
    return (*connect)(socket, endpoint);
}

int ZmqWrapper::zmq_ctx_destroy(void *context)
{
    if (!ctx_destroy)
        return -1;
    return (*ctx_destroy)(context);
}
