#include<iostream>
#include<string.h>
using namespace std;

typedef struct{
	char book[15];
	char author[15];
}Book;


void storeBook(Book* p,int* size);//存储书 
void searchBook(Book* p,int* size);//寻找书 
void printMenu();//打印菜单 
int exit();//退出 
void printBook(Book* p,int* size);//打印图书馆里的所有书 


int main()
{
	//模拟图书馆存书和找书
	//=========菜单========
	//1.存储书
	//2.寻找书 (是否存在这本书)
	//3.查看图书馆有多少本书：
	//4.退出 
	char key;
	char s[1000]; 
    Book book[10000];//能存储10000本书的数组 
    int size = 0;//书的总数目 
	do{
		//打印菜单
		printMenu();
		scanf("%s",s);//注：只会获取第一个字符，如果首字符在1-4之间，则能调用程序的功能 
		key = s[0];
		switch(key){
			case '1':	storeBook(book,&size);
						break;
			case '2':	searchBook(book,&size);
						break;
			case '3':   printf("\n\n总共有%d本书：\n\n",size);
						break;	
			case '4':	if(exit()){
						printf("\n\n程序退出..\n\n");
						return 0;
						}else{
							printf("\n\n放弃退出！\n\n");
						}
						break;
			case '5': 	printBook(book,&size); 
						break;
			default:	printf("\n\n输入有误，请输入(1-4)\n\n");	
		}	
		
		getchar();
	}while(1);
				
	
} 

void storeBook(Book* p,int* size)
{
	int length = *size;
	printf("请输入书名：\n");
	scanf("%s",p[length].book);
	printf("请输入作者名：\n");
	scanf("%s",p[length].author);	
	
	(*size)++;//书本总数加1 
	printf("\n\n存储成功!\n");
	
}
void searchBook(Book* p,int* size)
{
	Book t;
	int i;
	printf("请输入需要查找的书名:\n");
	scanf("%s",t.book);
	printf("请输入需要查找的书名的作者名：\n");
	scanf("%s",t.author);
	//遍历Book数组 
	for(i = 0; i < *size; i++) {
		if(strcmp(t.author,p[i].author) == 0 && strcmp(t.book,p[i].book) == 0){
			printf("\n\n查找成功！图书馆有这本书!\n\n");
			return;
		}
	}
	
	printf("\n\n查找失败！图书馆没这本书！\n\n");
}

void printMenu(){
	//打印菜单 
		printf("\n\n=========菜单========\n");	
		printf("1.存储书\n");
		printf("2.寻找书 (是否存在这本书)\n");
		printf("3.查看图书馆有多少本书：\n");
		printf("4.退出\n"); 
		printf("5.查看图书管有哪些书\n");
		printf("请输入你的选择（输入1-5）：\n");
}
void printBook(Book* p,int* size){
	if(*size == 0){
		printf("图书馆里没有书!\n");
		return;
	}
	for(int i = 0; i < *size; i++) {
		printf("书名： %s  作者名： %s\n",p[i].book,p[i].author);
	}
}

int exit(){
	char c;
	printf("是否确定退出程序？y/n\n");
	getchar();
	scanf("%c",&c);
	//判断用户输入的字母，以回应需求 
	if(c == 'y' || c == 'Y'){
		return 1;
	}else if(c == 'n' || c == 'N'){
		return 0;
	} else{
		printf("\n\n输入有误！请输入y/n\n\n");
	}
}


