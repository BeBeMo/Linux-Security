#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/include/mysql/mysql.h"

int main(int argc, char *argv[])
{
	MYSQL my_connection;
	MYSQL_RES *res_ptr;   /*ָ������Ľ����ŵ�ַ��ָ��*/
	MYSQL_ROW sqlrow;     /*���صļ�¼��Ϣ*/
	MYSQL_FIELD *fd;      /*�ֶνṹָ��*/
	char aszflds[25][25]; /*������Ÿ��ֶ���*/
	char buf[100]={0};
	int res,res1;             /*ִ�в�ѯ������ķ��ر�־*/
	int i,j,k;
	int flag=0;
	//��ʼ��MYSQL�ṹ
	mysql_init(&my_connection);

	//�������ݿ�
	if (mysql_real_connect(&my_connection, "127.0.0.1", "root", "ubuntu","userinfo",0,NULL,CLIENT_FOUND_ROWS))
	{

		//���ݿ��ѯ
		res = mysql_query(&my_connection, "select name,passwd from user");

		if (res)
		{
			printf("SELECT error:%s\n",mysql_error(&my_connection));
		}
		else
		{
			/*����ѯ��ȫ�������ȡ���ͻ���*/
			res_ptr=mysql_store_result(&my_connection);
			if(res_ptr)
			{
				/*ȡ�ø��ֶ���*/
				for(i=0;fd=mysql_fetch_field(res_ptr);i++)
					strcpy(aszflds[i],fd->name);
				/*���������¼*/
				j=mysql_num_fields(res_ptr);
				/*�ж��û��Ƿ����*/
				while((sqlrow=mysql_fetch_row(res_ptr)))
				{
					if(!strcmp(sqlrow[0],argv[1])){
						flag = 1;
					}
				}
				/*�û���������ע��������û���Ϣ*/	
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
				/*�û������������ʾ��Ϣ*/
				else
				{
					//printf("the user existed!chose another one!\n");
				        printf("%d\n",flag);
						
				}

			}
			//�ͷŽ����Դ
			mysql_free_result(res_ptr);
		}
		//�ر����ݿ�����
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
