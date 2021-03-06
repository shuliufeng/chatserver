# chatserver
可以工作在nginx tcp负载均衡环境中的集群聊天服务器和客户端源码 基于muduo实现 redis mysql

## chatserver介绍
1.	使用mymuduo网络库作为项目的网络核心模块，提供高并发网络IO服务；
2.	使用json序列化、反序列化消息作为私有通信协议；
3.	使用MySQL关系型数据库作为项目数据的落地存储；
4.	配置Nginx基于TCP的负载均衡，实现聊天服务器的集群功能；
5.	基于Redis的发布-订阅功能，实现跨服务器的消息通信。

## 环境配置
- vscode+ubuntu18.04
- Json简单配置
- mymuduo(自己实现)
- MySQL安装，建表
- Nginx安装
- Redis安装

## 服务端需求
- 注册、登录、注销、客户端异常退出、服务端异常退出
- 添加好友、一对一聊天、离线消息处理onechat
- 创建群、加入群、查询所在群的信息、群聊天

## 客户端
- 登录、注册、退出
- 主线程负责和用户交互，子线程负责接收数据
- 添加好友、一对一聊天
- 创建群组、加入群组、群组聊天

## Ngnix
- 单个服务器处理有上限
- 配置TCP负载均衡，每个服务器权重相同

## Redis
- 多个服务器两两通信编程复杂
- 基于发布-订阅功能，实现跨服务器通信
