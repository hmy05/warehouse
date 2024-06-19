#include<iostream>
#include<string.h>
using namespace std;

typedef struct{
	char book[15];
	char author[15];
}Book;


void storeBook(Book* p,int* size);//�洢�� 
void searchBook(Book* p,int* size);//Ѱ���� 
void printMenu();//��ӡ�˵� 
int exit();//�˳� 
void printBook(Book* p,int* size);//��ӡͼ������������ 


int main()
{
	//ģ��ͼ��ݴ��������
	//=========�˵�========
	//1.�洢��
	//2.Ѱ���� (�Ƿ�����Ȿ��)
	//3.�鿴ͼ����ж��ٱ��飺
	//4.�˳� 
	char key;
	char s[1000]; 
    Book book[10000];//�ܴ洢10000��������� 
    int size = 0;//�������Ŀ 
	do{
		//��ӡ�˵�
		printMenu();
		scanf("%s",s);//ע��ֻ���ȡ��һ���ַ���������ַ���1-4֮�䣬���ܵ��ó���Ĺ��� 
		key = s[0];
		switch(key){
			case '1':	storeBook(book,&size);
						break;
			case '2':	searchBook(book,&size);
						break;
			case '3':   printf("\n\n�ܹ���%d���飺\n\n",size);
						break;	
			case '4':	if(exit()){
						printf("\n\n�����˳�..\n\n");
						return 0;
						}else{
							printf("\n\n�����˳���\n\n");
						}
						break;
			case '5': 	printBook(book,&size); 
						break;
			default:	printf("\n\n��������������(1-4)\n\n");	
		}	
		
		getchar();
	}while(1);
				
	
} 

void storeBook(Book* p,int* size)
{
	int length = *size;
	printf("������������\n");
	scanf("%s",p[length].book);
	printf("��������������\n");
	scanf("%s",p[length].author);	
	
	(*size)++;//�鱾������1 
	printf("\n\n�洢�ɹ�!\n");
	
}
void searchBook(Book* p,int* size)
{
	Book t;
	int i;
	printf("��������Ҫ���ҵ�����:\n");
	scanf("%s",t.book);
	printf("��������Ҫ���ҵ���������������\n");
	scanf("%s",t.author);
	//����Book���� 
	for(i = 0; i < *size; i++) {
		if(strcmp(t.author,p[i].author) == 0 && strcmp(t.book,p[i].book) == 0){
			printf("\n\n���ҳɹ���ͼ������Ȿ��!\n\n");
			return;
		}
	}
	
	printf("\n\n����ʧ�ܣ�ͼ���û�Ȿ�飡\n\n");
}

void printMenu(){
	//��ӡ�˵� 
		printf("\n\n=========�˵�========\n");	
		printf("1.�洢��\n");
		printf("2.Ѱ���� (�Ƿ�����Ȿ��)\n");
		printf("3.�鿴ͼ����ж��ٱ��飺\n");
		printf("4.�˳�\n"); 
		printf("5.�鿴ͼ�������Щ��\n");
		printf("���������ѡ������1-5����\n");
}
void printBook(Book* p,int* size){
	if(*size == 0){
		printf("ͼ�����û����!\n");
		return;
	}
	for(int i = 0; i < *size; i++) {
		printf("������ %s  �������� %s\n",p[i].book,p[i].author);
	}
}

int exit(){
	char c;
	printf("�Ƿ�ȷ���˳�����y/n\n");
	getchar();
	scanf("%c",&c);
	//�ж��û��������ĸ���Ի�Ӧ���� 
	if(c == 'y' || c == 'Y'){
		return 1;
	}else if(c == 'n' || c == 'N'){
		return 0;
	} else{
		printf("\n\n��������������y/n\n\n");
	}
}


