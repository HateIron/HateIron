#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <Sqltypes.h>
#include <iostream>
using namespace std;
int main()
{
     /*Step 1 定义句柄和变量 */
      SQLHENV hEnv;
      SQLHDBC hConnect;
      SQLHSTMT hStmt;
      SQLRETURN r;
      // 分配环境句柄
      r = SQLAllocHandle ( SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
      if ( r != SQL_SUCCESS )
      {
         cout << "SQLAllocHandle error!" << endl ;
         exit(1);
      }
      // 设置环境句柄
      r = SQLSetEnvAttr ( hEnv, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0 );
      if ( r != SQL_SUCCESS )
      {
         cout << "SQLSetEnvAttr error!" << endl ;
         exit(1);
      }
      // 分配连接句柄
      r = SQLAllocHandle ( SQL_HANDLE_DBC, hEnv, &hConnect);
      if ( r != SQL_SUCCESS )
      {
         cout << "SQLAllocHandle error!" << endl ;
         exit(1);
      }
      /*之上的程序代码读者直接粘贴即可，无限修改；至于具体语句或函数的功能，没有必要深入了解，
        只要清楚每一步的作用（注释给出）即可*/
      /* 连接ODBC数据库，主要函数中第二个参数test为操作的数据源的名称；第四个参数是操作数据库的用户名
        第六个参数是操作数据库的密码*/
//      r = SQLConnect ( hConnect, (SQLCHAR*) "SQL_Local", SQL_NTS, (SQLCHAR*) "sa",
//                     SQL_NTS, (SQLCHAR*) "wishcell", SQL_NTS);
      r = SQLConnect ( hConnect, (SQLCHAR*) "MySQL_ODBC", SQL_NTS, (SQLCHAR*) "admin",
                     SQL_NTS, (SQLCHAR*) "123456", SQL_NTS);
      if ( r!=SQL_SUCCESS && r!=SQL_SUCCESS_WITH_INFO )
      {
         cout << "SQLConnect error!" << endl;
         exit (1);
      }
      else
      {
        cout << "SQLConnect suceed!" << endl;
      }
      char SQLString[200] ;            //用于存储SQL语句
      // 分配语句句柄
      r = SQLAllocHandle ( SQL_HANDLE_STMT, hConnect, &hStmt);
      if ( r != SQL_SUCCESS )
      {
         cout << "SQLAllocHandle error!" << endl ;
         exit(1);
      }
      // 执行SQL查询（第二个参数即你想执行的SQL语句）
      strcpy ( SQLString, "select * from my_tbl_test");
      r = SQLExecDirect( hStmt, (SQLCHAR *)SQLString, SQL_NTS);
      if ( r != SQL_SUCCESS )
      {
        cout << "SQLExecDirect error!" << endl ;
        exit(1);
      }
#if 1
      // 绑定数据并输出 
      SQLCHAR authorName[20] ;

      SQLCHAR bookID[20] ;
      SQLINTEGER auName = SQL_NTS;       //函数SQLGetData中会用到
      SQLINTEGER bID = SQL_NTS;
      while(1)
      {
         r = SQLFetch(hStmt);   //数据库游标，当对某一行表项操作成功后，游标下移一位
         if(r == SQL_ERROR || r == SQL_SUCCESS_WITH_INFO)
         {
             cout << "SQLFetch error!" << endl ;
             exit(1);
         }
         
         /*SQLGetData用于检索结果集数据,其中用户可修改的参数为：参数2表示取第几列的数据；参数3表示数据类型SQL_C_X,
           X为具体的数据类型，如CHAR、INT等；参数4是存放数据的变量；参数5指向的缓冲区的最大大小，
           如果参数4是二进制或字符串，则参数5必须大于0；参数6事先要定义（名字可以参数4相关联），然后其值赋为SQL_NTS
         */
         if ( r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
         {
            SQLGetData(hStmt,1,SQL_C_CHAR,authorName,20,(SQLLEN *)&auName);
            SQLGetData(hStmt,2,SQL_C_CHAR,bookID,20,(SQLLEN *)&bID);
            printf("%s\t%s\n" , bookID , authorName);
         }
         else
           break ;
      } 
#endif
      return 0;
}