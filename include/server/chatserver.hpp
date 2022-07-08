#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <mymuduo/TcpServer.h>
#include <mymuduo/Logger.h>
#include <mymuduo/EventLoop.h>

//聊天服务器的主类
class ChatServer
{
public:
    //初始化聊天服务器对象，构造TCPServer 
    ChatServer(EventLoop *loop,
               const InetAddress &listenAddr,
               const string &nameArg);

    //启动服务
    void start();

private:
    //上报链接相关信息的回调函数
    void onConnection(const TcpConnectionPtr &);

    //上报读写事件相关信息的回调函数
    void onMessage(const TcpConnectionPtr &,
                   Buffer *,
                   Timestamp);

    TcpServer _server;//组合的muduo库，实现服务器功能的类对象
    EventLoop *_loop;//指向事件循环对象的指针, 可以在合适的时候退出事件循环
};

#endif