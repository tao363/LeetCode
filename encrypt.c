#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


//临时变量
char ch = '0';
char filename[256] = "";
const char tempfile[256] = "tmpfile123456789.txt";
FILE* fp = NULL;
FILE* fptemp = NULL;
char password[12] = "123456";
int pwdlen = 0;
int i = 0;

/* 封装一些函数*/

void Menu();

void InputPass(char* pass);

void InputPass(char* pass)
{
    scanf("%s",pass);
}

void Menu()
{
    printf("***********************************\n");
    printf("**********安全课程小程序************\n");
    printf("***********************************\n");
    printf("**请输入要加密或解密的小程序**\n");
    printf("**例如：/user/Ming/tb.txt**\n");

    /*步骤一： 要打开一些文件或目录*/
    gets(filename);
    if(NULL == (fp = fopen(filename,"rb")))
    {
        printf("您好，所输入的文件不存在\n");
        //退出
        exit(1);
    }
    printf("文件存在，请输入密码：\n");
    InputPass(password);
    pwdlen = (int)strlen(password);
    if(0 == pwdlen)
    {
        printf("对不起，密码长度不能为零！！\n");
        exit(1);
    }
    /*步骤二： 读出文件中的内容进行加密*/
    fptemp = fopen(tempfile,"wb");

    /*步骤三： 把加密的信息写入到文件中覆盖原来的数据*/
    while(1)
    {
        ch = getc(fp);
        if(feof(fp))
        {
            break;
        }
        //每取出一个字符就加密
        ch ^= password[i++];
        fputc(ch,fptemp);
        if(i == pwdlen)
        {
            i = 0;
        } 
    }
    fclose(fp);
    fclose(fptemp);
    remove(filename);
    rename(tempfile,filename);
    printf("恭喜你，加密或解密成功\n");
}


int main()
{
    Menu();
    return 0;
}