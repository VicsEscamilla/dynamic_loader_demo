#ifndef ZMQ_WRAPPER_INTERFACE_H
#define ZMQ_WRAPPER_INTERFACE_H

class ZmqWrapperInterface
{
public:
    ZmqWrapperInterface(void){};
    virtual ~ZmqWrapperInterface(void){};
    virtual void* _ctx_new(void)=0;
    virtual void* _socket(void *context, int type)=0;
    virtual void* _socket_REQ(void *context)=0;
    virtual void* _socket_REP(void *context)=0;
    virtual int _bind(void *socket, const char *endpoint)=0;
    virtual int _send(void *socket, void *buf, size_t len, int flags)=0;
    virtual int _recv(void *socket, void *buf, size_t len, int flags)=0;
    virtual int _close(void *socket)=0;
    virtual int _connect(void *socket, const char *endpoint)=0;
    virtual int _ctx_destroy(void *context)=0;
};

#endif // ZMQ_WRAPPER_INTERFACE_H
