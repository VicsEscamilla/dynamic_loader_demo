#ifndef ZMQ_WRAPPER_H
#define ZMQ_WRAPPER_H

#include "dynamic_loader.h"

#define ZMQ_PAIR 0
#define ZMQ_PUB 1
#define ZMQ_SUB 2
#define ZMQ_REQ 3
#define ZMQ_REP 4
#define ZMQ_DEALER 5
#define ZMQ_ROUTER 6
#define ZMQ_PULL 7
#define ZMQ_PUSH 8
#define ZMQ_XPUB 9
#define ZMQ_XSUB 10
#define ZMQ_STREAM 11

typedef void* (*zmq_ctx_new_func_t) (void);

typedef void* (*zmq_socket_func_t) (void *context, int type);

typedef int (*zmq_bind_func_t) (void *socket, const char *endpoint);

typedef int (*zmq_send_func_t) (void *socket, void *buf, size_t len, int flags);

typedef int (*zmq_recv_func_t) (void *socket, void *buf, size_t len, int flags);

typedef int (*zmq_close_func_t) (void *socket);

typedef int (*zmq_connect_func_t) (void *socket, const char *endpoint);

typedef int (*zmq_ctx_destroy_func_t) (void *context);

class ZmqWrapper : public DynamicLoader
{
public:
    ZmqWrapper(void);
    virtual ~ZmqWrapper(void);
    void* zmq_ctx_new(void);
    void* zmq_socket(void *context, int type);
    int zmq_bind(void *socket, const char *endpoint);
    int zmq_send(void *socket, void *buf, size_t len, int flags);
    int zmq_recv(void *socket, void *buf, size_t len, int flags);
    int zmq_close(void *socket);
    int zmq_connect(void *socket, const char *endpoint);
    int zmq_ctx_destroy(void *context);

protected:
    zmq_ctx_new_func_t ctx_new;
    zmq_socket_func_t socket;
    zmq_bind_func_t bind;
    zmq_recv_func_t recv;
    zmq_send_func_t send;
    zmq_close_func_t close;
    zmq_connect_func_t connect;
    zmq_ctx_destroy_func_t ctx_destroy;
};

#endif // ZMQ_WRAPPER_H
