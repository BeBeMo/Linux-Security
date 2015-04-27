#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/include/mysql/mysql.h"

int main(int argc, char *argv[])
{
	MYSQL my_connection;
	MYSQL_RES *res_ptr;   /*指向检索的结果存放地址的指针*/
	MYSQL_ROW sqlrow;     /*返回的记录信息*/
	MYSQL_FIELD *fd;      /*字段结构指针*/
	char aszflds[25][25]; /*用来存放各字段名*/
	char buf[100]={0};
	int res,res1;             /*执行查询操作后的返回标志*/
	int i,j,k;
	int flag=0;
	//初始化MYSQL结构
	mysql_init(&my_connection);

	//连接数据库
	if (mysql_real_connect(&my_connection, "127.0.0.1", "root", "ubuntu","userinfo",0,NULL,CLIENT_FOUND_ROWS))
	{

		//数据库查询
		res = mysql_query(&my_connection, "select name,passwd from user");

		if (res)
		{
			printf("SELECT error:%s\n",mysql_error(&my_connection));
		}
		else
		{
			/*将查询的全部结果读取到客户端*/
			res_ptr=mysql_store_result(&my_connection);
			if(res_ptr)
			{
				/*取得各字段名*/
				for(i=0;fd=mysql_fetch_field(res_ptr);i++)
					strcpy(aszflds[i],fd->name);
				/*输出各条记录*/
				j=mysql_num_fields(res_ptr);
				/*判断用户是否存在*/
				while((sqlrow=mysql_fetch_row(res_ptr)))
				{
					if(!strcmp(sqlrow[0],argv[1])){
						flag = 1;
					}
				}
				/*用户不存在则注册插入新用户信息*/	
				if(flag == 0)
				{
					sprintf(buf,"INSERT INTO user(name,passwd) VALUES('%s','%s')",argv[1],argv[2]);
					res = mysql_query(&my_connection,buf);
					if(!res)
					{
						//printf("Inserted %lu rows\n",(unsigned long)mysql_affected_rows(&my_connection));
						printf("%d\n",flag);
					}
				}
				/*用户存在则输出提示信息*/
				else
				{
					//printf("the user existed!chose another one!\n");
				        printf("%d\n",flag);
						
				}

			}
			//释放结果资源
			mysql_free_result(res_ptr);
		}
		//关闭数据库连接
		mysql_close(&my_connection);
	}

	else
	{
		fprintf(stderr, "Connection failed\n");

		if (mysql_errno(&my_connection))
		{
			fprintf(stderr, "Connection error %d: %s\n",
					mysql_errno(&my_connection),
					mysql_error(&my_connection));
		}
	}
	return EXIT_SUCCESS;
}
