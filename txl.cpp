#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<cstring>
#include<iostream>
using namespace std;
//�ڵ�ṹ��
typedef struct NODE
{
	int xh;
	char* name;
	char* phone;
	struct NODE* pNext;
}Node;
//��ҳ�ṹ��
typedef struct PAGE
{
	int TotalItem;
	int OnePageItem;
	int TotalPage;
	int CurrentPage;
} Page;

int g_menu_type = 0;
char g_key;
void InitInfo(Node** top,Node** end,int n);//��ʼ����Ϣ
char GetKey();//��ȡ������������

char* GetName();//��ȡ����
char* GetPhone();//��ȡ�绰��
int GetNumber();//��ȡ���
Node* GetNode();//��ȡһ���ڵ�

char* InputName();//����һ������
char* InputPhone();//����һ���绰��
int InputNumber();//����һ�����
Node* InputNode();//����һ���ڵ�

void LookTXL(Node* top);//�鿴
void QueryTXL(Node* top);//��ѯ
void AddNode(Node** top,Node** end,Node* node);	//��ӽڵ�
void DelNode(Node** top,Node** end,int n);//ɾ���ڵ�
void DelTXL(Node** top,Node** end);//ɾ��			
void UpDateTXL(Node* top);//�޸�
void Show(Node* top,Page* page);//��ʾ
void ShowMenu(Page* page);
void ShowALL(Node* top);//ȫ����ʾ
Page* InitPage(Node* top,int n);
void OperatePage(Page* page,Node* top);

int main()
{
	Node* top = NULL;
	Node* end = NULL;
	//Page* page = NULL;
	//��ʼ����Ϣ
	InitInfo(&top,&end,49);
	
	char key;
	
	while(1)
	{
		printf("1.�鿴ͨѶ¼\n");
		printf("2.��ѯͨѶ¼\n");
		printf("3.���ͨѶ¼\n");
		printf("4.ɾ��ͨѶ¼\n");
		printf("5.�޸�ͨѶ¼\n");
		printf("6.�˳�ͨѶ¼\n");
		//��ȡ������������
		key = GetKey();
		switch(key)
		{
			case '1':
				g_menu_type = 1;
				LookTXL(top);
				break;
			case '2':
				g_menu_type = 2;
				QueryTXL(top);
				break;
			case '3':
				g_menu_type = 3;
				AddNode(&top,&end,InputNode());
				break;
			case '4':
				g_menu_type = 4;
				DelTXL(&top,&end);
				break;
			case '5':
				g_menu_type = 5;
				UpDateTXL(top);
				break;
			case '6':
				return 0;
				break;
			default:
				printf("��������ȷ�����֣�\n");
				break;
		}
	}
	return 0;
}
char GetKey()//��ȡ������������
{
	char c,v;
	int a = 0;
	//int a;scanf("%d",&a);//123\n����123����a�����뻺�����л���һ��\n��Ӧ��ȡ������getchar����
	//�� || a == 0������������뻺�������Ѿ�����һ��\n����ѭ��ֱ���˳���vΪһ������ֵ��������û����
	while((c=getchar()) != '\n' || a == 0)
	{
		v = c;
		a = -1;
	}
	return v;
}
char* GetName()//��ȡ����
{
	char name[6]={0};
	char* p = (char*)malloc(6);
	for(int i = 0;i<5;i++)
	{
		name[i] = 'a'+rand()%26;
	}
	strcpy(p, name);//
	/*
strcpy_s(b, a)
��˼�ǽ�a������b,����һ��Ҫ��֤bװ����a������ᱨ��
void main()
{
	 char str[10], str1[9];
	for(int i=0; i<9;i++)
	{
		str1[i] ='a';
	 }
	 strcpy_s(str, sizeof(str), str1);
 }
������������ʱ�쳣��Ϊʲô������쳣��
strcpy_s�Ǹ���'\0'�ж�Դ�ַ���������
�����е�str1[9]��9�������Ա������ֵΪ'a'��û�н�����'\0'��
���strcpy_s�ڸ�����str1��9���ַ����ڼ�����ֵ�����ڴ棬
�������ո��Ƶ��ַ���������Ŀ�껺�����ĳ���10����������˶���ʧ�ܡ�

������ڳ�����䣨���£���
strcpy_s(p,strlen(p1),p1);
strcpy_s(p1,strlen(p2),p2);
strcpy_s(p2,strlen(p),p);
���У��ַ���p1��p2�ֱ�ָ��ĳ���ַ�����p�Ƕ����һ���ַ����顣��������ڶ�strlen()��ʹ�ã��������������ַ��������ǲ�����'\0���ģ�
���������õڶ������������������ȣ�ʱ���ͻ�����쳣����Ϊ�ڿ���ʱ��Ҫ���ַ����Ľ�����־ҲҪһͬ������ȥ��
���ԣ�������ʾBuffer is too small�ͱ����ڶ����������õ�ֵС��Դ�ַ�����
���Խ���������ǣ���strlen(p1)�޸�Ϊstrlen(p1)+1������ͼ���޸ĺ����ͨ����
strcpy_s(p,strlen(p1)+1,p1);
strcpy_s(p1,strlen(p2)+1,p2);
strcpy_s(p2,strlen(p)+1,p);

	*/
	return p;

	//char* name = (char*)malloc(8);
	//int i;
	//char c[2] = {0};
	//*name = 0;
	//for(i = 1;i<=7;i++)
	//{
	//	c[0] = rand()%26+97;
	//	strcat_s(name,8,c);
	//}
	//return name;
}
char* GetPhone()//��ȡ�绰��
{
	char phone[11]={0};
	char* p = (char*)malloc(12);
	switch(rand()%4)
	{
		case 0:
			strcpy(p,"131");
			//phoneҪ�������ĵط���phone�Ĵ�С��Ҫ�������ַ�������\0���������Ե������������ܴ��ڵ�һ������
			break;
		case 1:
			strcpy(p,"156");
			break;
		case 2:
			strcpy(p,"136");
			break;
		case 3:
			strcpy(p,"188");
			break;		
	}
	for(int i=0;i<8;i++)
	{
		//_itoa_s(rand()%10,c,2,10);
		//���ֱ�Ϊ�ַ������֣�Ҫ����ַ����ĵ�ַ���ַ����Ĵ�С��������
		phone[i] = rand()%10+'0';
	}
	strcat(p, phone);
	return p;
/*
	int i;
	char* phone = (char*)malloc(12);
	char c[2];
	switch(rand()%4)
	{
		case 0:
			strcpy_s(phone,12,"156");
			break;
		case 1:
			strcpy_s(phone,12,"135");
			break;
		case 2:
			strcpy_s(phone,12,"131");
			break;
		case 3:
			strcpy_s(phone,12,"188");		
			break;
	}
	for(i = 1;i<=8;i++)
	{
		_itoa_s(rand()%10,c,2,10);
		strcat_s(phone,12,c);
	}
	return phone;*/

}
int GetNumber()//��ȡ���
{
	static int i = 0;
	i++;
	return i;
}
char* InputName()//����һ������
{
	/*char c;
	char* name = (char*)malloc(7);
	while((c = getchar() ) != '\n')
	{
	}
	return name;*/

	//ע������⣺�����ֿռ䲻����ô���
	char c;
	int count = 0;
	int size = 5;
	char* str = (char*)malloc(size);
	char* newStr = NULL;
	char* jStr = str;
	while((c = getchar() ) != '\n')
	{
		count++;
		*str++ = c;
		if(count+1 == size)
		{
			*str = '\0';
			size += 5;
			newStr = (char*)malloc(size);
			strcpy(newStr,jStr);
			free(jStr);
			jStr = newStr;
			str = jStr+count;
		}
	}
	*str = 0;
	return jStr;
	
	
}
char* InputPhone()//����һ���绰��
{
	char c;
	char* phone = (char*)malloc(13);
	char* bj = phone;
	while((c = getchar() ) != '\n')
	{
		*phone = c;
		phone++;
	}
	*phone = 0;
	return bj;
}
int InputNumber()//����һ�����
{
	int n;
	scanf("%d",&n);
	getchar();
	return n;
}
Node* InputNode()//����һ���ڵ�
{
	Node* node = (Node*)malloc(sizeof(Node));
	printf("������һ�����֣�\n");
	node->name = InputName();
	printf("������һ���绰�ţ�\n");
	node->phone = InputPhone();
	printf("������һ��ѧ�ţ�\n");
	node->xh = InputNumber();
	node->pNext = NULL;
	return node;
}
Node* GetNode()//��ȡһ���ڵ�
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->name = GetName();
	node->phone = GetPhone();
	node->xh = GetNumber();
	node->pNext = NULL;
	return node;
}
void InitInfo(Node** top,Node** end,int n)//��ʼ����Ϣ
{
	int i;
	srand((unsigned int)time(0));//ÿ�����г���õ���������ݶ���һ��
	for(i = 0;i < n;i++)
	{
		//��ӽڵ�
		AddNode(top,end,GetNode());
	}
	
}
void AddNode(Node** top,Node** end,Node* node)	//���
{
	//����Ϊ��
	if(*top == NULL)
	{
		*top = node;
		*end = node;
	}
	//ͷ���� ��������Ϊͷָ��
	//(*top)->pNext = node;
	//β���� ��������Ϊβָ��
	else
	{
		(*end)->pNext = node;
		*end = node;
	}
}
void DelNode(Node** top,Node** end,int n)//ɾ��			
{
	Node* temp = *top;
	Node* del = NULL;
	//ShowALL(temp);
	/*printf("��������Ҫɾ����ѧ�ţ�\n");*/
	//========================�˴������⣬Ӧ�ý������֣�����˫λ������=====================================
	/*int n = 0;
	scanf("%d",&n);
	getchar();
	*/
	/*int n = 0;
	n = atoi(InputName());*/
	/*int n = InputNumber();*/

	//ͷɾ��
	if(temp->xh == n)
	{
		del = temp;
		temp = temp->pNext;
		free(del);
		del = NULL;
		*top = temp;
		/*ShowALL(*top);*/
		return;
	}
	//�м�ɾ��
	while(temp->pNext != NULL)
	{
		if(temp->pNext->xh  == n)
		{
			del = temp->pNext;
			temp->pNext = temp->pNext->pNext;
			free(del);
			del = NULL;
			//�ж��Ƿ�Ϊβ�ڵ�
			if(temp->pNext == *end)
			{
				*end = temp;
			}
			
			//ShowALL(*top);
			return;
		}
		temp = temp->pNext;
	}
	
}
void LookTXL(Node* top)//�鿴
{
	
	Page* page = InitPage(top,20);
	OperatePage(page,top);	
}
void QueryTXL(Node* top)//��ѯ
{
	char* keyword = (char*)malloc(12);
	Node* bj = top;
	Node* node = NULL;
	Node* del = NULL;
	Node* newTop = NULL;
	Node* newEnd = NULL;
	//��Ϊģ����ѯ��Ӧ����ôд���룿����
	while(1)
	{
		while(1)
		{
			printf("��������Ҫ��ѯ�Ĺؼ��֣�\n");
			keyword = InputName();
			printf("��yȷ�����������������룺\n");
			if(GetKey() == 'y')
				break;
			else
			{
				free(keyword);
				keyword = NULL;
			}
		}
		bj = top;
		newTop = NULL;
		newEnd = NULL;

		while(bj)
		{
			if(strncmp(bj->name,keyword,strlen(keyword)) == 0 || strncmp(bj->phone,keyword,strlen(keyword)) == 0)
			{
				node = (Node*)malloc(sizeof(Node));
				node->xh = bj->xh;
				node->phone = bj->phone;
				node->name = bj->name;
				node->pNext = NULL;
				//�����в�ѯ���Ľڵ㣬�ŵ�һ���µ�������
				AddNode(&newTop,&newEnd,node);
			}
			bj = bj->pNext;
		}
		if(newTop == NULL)
			printf("û�ҵ���\n");
		else
		{
			LookTXL(newTop);
			//ɾ����ѯ�������н��
			while(newTop)
			{
				del = newTop;
				newTop = newTop->pNext;
				free(del);
				del = NULL;
				newEnd = NULL;
			}
		}
		if(g_key == 'c')
			continue;
		if(g_key == 'd' && g_menu_type == 4)
			return;
		if(g_key == 'u' && g_menu_type == 5)
			return;
		if(g_key == 'b')
			return;
	}
}
void DelTXL(Node** top,Node** end)//ɾ��	
{
	int xh;
	char key;
	while(1)
	{
		printf("���ѯ����Ҫɾ����ѧ�ţ�\n");
		QueryTXL(*top);
		if(g_key == 'b')
			return;
		printf("��������Ҫɾ����ѧ�ţ�\n");
		xh = atoi(InputName());
		DelNode(top,end,xh);
		printf("��y����ɾ�����������������˵���\n");
		key = GetKey();
		if(key == 'y')
			;
		else
			return;
	}
	
	
	
}
void UpDateTXL(Node* top)//�޸�
{
	int xh;
	char key = 0;
	Node* bj = top;
	while(1)
	{
		printf("���ѯ��Ҫ�޸ĵ���Ϣ��\n");
		QueryTXL(top);
		if(g_key == 'b')
			return;
		printf("��������Ҫ�޸ĵ���Ϣ�ı�ţ�\n");
		xh = atoi(InputName());
		bj = top;
		while(bj)
		{
			if(bj->xh == xh)
			{
				printf("��������%d��������",bj->xh);
				bj->name = InputName();
				printf("��������%d���µ绰����",bj->xh);
				bj->phone = InputPhone();
				printf("��y�����޸ģ��������������˵���\n");
				key =GetKey();
				if(key == 'y')
					break;
				else
					return;
			}
			bj=bj->pNext;		
		}
		if(bj == NULL)
			printf("û�ҵ���Ҫ�޸ĵ���Ϣ��\n");		
	}
}
void ShowALL(Node* top)//ȫ����ʾ
{
	printf("ѧ��\t����\t�绰��\t\n");
	while(top)
	{
		printf("%d\t%s\t%s\t\n",top->xh,top->name,top->phone);
		top = top->pNext;
	}
}
void Show(Node* top,Page* page)//��ʾ��ҳ��Ϣ
{
	int count =0;
	int begin = (page->CurrentPage-1) * page->OnePageItem + 1;
	int end = page->CurrentPage * page->OnePageItem;
	printf("ѧ��\t����\t�绰��\t\n");
	while(top)
	{
		count++;
		if(count >= begin && count <= end)
			printf("%d\t%s\t%s\t\n",top->xh,top->name,top->phone);
		top = top->pNext;
	}

}
void ShowMenu(Page* page)
{
	switch(g_menu_type)
	{
		case 1:
			printf("��%d�� ��%dҳ ��ǰ��%dҳ ��һҳ(w) ��һҳ(s) ����(b) \n",page->TotalItem,page->TotalPage,page->CurrentPage);
			break;
		case 2:
			printf("��%d�� ��%dҳ ��ǰ��%dҳ ��һҳ(w) ��һҳ(s) ������ѯ(c) ����(b) \n",page->TotalItem,page->TotalPage,page->CurrentPage);
			break;		
		case 4:
			printf("��%d�� ��%dҳ ��ǰ��%dҳ ��һҳ(w) ��һҳ(s) ɾ��(d) ����(b) \n",page->TotalItem,page->TotalPage,page->CurrentPage);
			break;
		case 5:
			printf("��%d�� ��%dҳ ��ǰ��%dҳ ��һҳ(w) ��һҳ(s) �޸�(u) ����(b) \n",page->TotalItem,page->TotalPage,page->CurrentPage);
	}
	
}
Page* InitPage(Node* top,int OnePageItem)
{
	//�������ǰ�����з�ҳ����Ϣ
	//������ҳ������Ŀ��һҳ��ʾ�ĸ�������ҳ������ǰҳ
	Page* page = (Page*)malloc(sizeof(Page));
	page->CurrentPage = 0;
	page->OnePageItem = OnePageItem;
	page->TotalItem = 0;
	while(top)
	{
		page->TotalItem++;
		top = top->pNext;
	}
	page->TotalPage = page->TotalItem % page->OnePageItem == 0 ? page->TotalItem / page->OnePageItem : page->TotalItem / page->OnePageItem + 1;
	//���ȼ��Ӹߵ���˳��->	/	==	?:	= 
	return page;
}
void OperatePage(Page* page,Node* top)
{
	char key = 's';
	while(key != 'b')
	{
		switch(key)
		{
			case 's':
				if(page->CurrentPage == page->TotalPage)
					printf("�Ѿ������һҳ�ˣ�\n");
				else
				{
					page->CurrentPage++;
					Show(top,page);
					ShowMenu(page);
				}
				break;
			case 'w':
				if(page->CurrentPage == 1)
					printf("�Ѿ��ǵ�һҳ�ˣ�\n");
				else
				{
					page->CurrentPage--;
					Show(top,page);
					ShowMenu(page);
				}

				break;
			case 'b':
				return;
				break;
			case 'c':
			case 'd':
			case 'u':
				break;
			default:
				printf("����������������룺\n");
				break;
		}
		g_key = key = GetKey();
		if(key == 'c' || key == 'd' || key == 'u')
			return;//break;���ɣ�������ֹѭ�����˳�ѭ����
	}
}
