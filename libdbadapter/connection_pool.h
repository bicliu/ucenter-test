#ifndef _CONNECTION_POOL_H  
#define _CONNECTION_POOL_H  
#include <mysql_connection.h>  
#include <mysql_driver.h>  
#include <cppconn/exception.h>  
#include <cppconn/driver.h>  
#include <cppconn/connection.h>  
#include <cppconn/resultset.h>  
#include <cppconn/prepared_statement.h>  
#include <cppconn/statement.h>  
#include <pthread.h>  
#include <list>  
using namespace std;  
using namespace sql;  
  
class   ConnPool{  
private:  
   int   _curSize;//当前已建立的数据库连接数量  
   int   _maxSize;//连接池中定义的最大数据库连接数  
   std::string  _username;  
   std::string  _password;  
   std::string  _url;  
   list<Connection*>   _connList;//连接池的容器队列  
   pthread_mutex_t  _lock;//线程锁  
   static   ConnPool *_connPool;  
   Driver  *  _driver;  
  
   //Connection *   CreateConnection();//创建一个连接  
   void   InitConnection(int iInitialSize);//初始化数据库连接池  
   //void   DestoryConnection(Connection *conn);//销毁数据库连接对象  
   void   DestroyConnPool();//销毁数据库连接池  
    ConnPool(const std::string & url,const std::string & user,const std::string & password,int maxSize);//构造方法  
public:  
    ~ConnPool(); 
    Connection  *  GetConnection();//获得数据库连接  
    void  ReleaseConnection(Connection *conn);//将数据库连接放回到连接池的容器中  
    static ConnPool *GetInstance(std::string user, std::string passwd , int nConnNum);//获取数据库连接池对象  
    static ConnPool *GetInstance();//获取数据库连接池对象
    Connection *   CreateConnection();//创建一个连接
    void   DestroyConnection(Connection *conn);//销毁数据库连接对象 
};  
#endif  /*_CONNECTION_POOL_H */
