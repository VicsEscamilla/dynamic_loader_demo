#ifndef ZMQ_WRAPPER_H
#define ZMQ_WRAPPER_H

#include "zmq_wrapper_interface.h"

class ZmqWrapper : public ZmqWrapperInterface
{
public:
    ZmqWrapper(void);
    virtual ~ZmqWrapper(void);
    void* _ctx_new(void);
    void* _socket(void *context, int type);
    void* _socket_REQ(void *context);
    void* _socket_REP(void *context);
    int _bind(void *socket, const char *endpoint);
    int _send(void *socket, void *buf, size_t len, int flags);
    int _recv(void *socket, void *buf, size_t len, int flags);
    int _close(void *socket);
    int _connect(void *socket, const char *endpoint);
    int _ctx_destroy(void *context);
};

extern "C"
{
    ZmqWrapper* getZmqWrapperInstance()
    {
        return new ZmqWrapper();
    }
}

#endif // ZMQ_WRAPPER_H
