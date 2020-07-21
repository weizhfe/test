#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct HTNode
{
	char charname;
	 int weight;
	 int parent, lchild, rchild;
}HTNode, *HuffmanTree;


typedef char **HuffmanCode;    //��̬��������洢�ַ�����Ķ�̬�ռ�

int n=27,m=53;    // m=2*n-1   mΪ���ڵ����
char *a;
int *b;

void HuffmanCoding(HuffmanTree HT,HuffmanCode HC,char *a,int *b,int n)
{
	int i;//ͨ�����ͱ���i������ѭ����
	int s1 = 0;  //����s1���ڹ��������Ĵ���
	int s2 = 0;//����s2���ڹ��������Ĵ���
	int j;
	int d;
	int m=2 * n - 1;
	char *cd=(char*)malloc(n*sizeof(char));  //������ʱ���ÿ���ַ�����Ķ�̬�ռ䣬����ʹ��

//�����������HT
	if(n<=1)
	{
		return ;
	}//nֵС�ڵ���1�������㴴����������������
	//HT=(HuffmanTree)malloc(((2*n-1)+1)*sizeof(HTNode));
	for(i=1;i<=n;++i)
	{
		HT[i].charname=a[i-1];
		HT[i].weight=b[i-1];
		HT[i].parent=0;
		HT[i].lchild=-1;
		HT[i].rchild=-1; 	
	}
	for(;i<=m;++i)    //��Ҫ��������ʼ����Ҫ�������
	{
		HT[i].charname='0';
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
	}


//���¹���ΪѰ��Ȩֵ����С������ֵ

	for(i=n+1;i<=m;++i)   //����ɸѡ������Ȩ����С������
	{ 
		for(s1=1;HT[s1].parent!=0;)
		{
			s1++;
		}       //˫�ײ�Ϊ0���ñ���s1��1��Ѱ��˫��Ϊ0�Ľ��
 
		for (j=s1;j<=i-1;j++)    //����Ѱ�ҵ�һ��˫��Ϊ0�Ľ��
		{
			if(HT[j].parent!=0)
			{
				continue;
			}
			s1=HT[j].weight<HT[s1].weight?j:s1;  //Ѱ�ҵ�һ��Ȩ����С���±�
		}
 
		HT[s1].parent=i;   
		HT[i].lchild=s1;
 
		for(s2=1;HT[s2].parent!=0;)   //ͬs1����һ�����ҵڶ���˫��Ϊ0�Ľ��
		{
			s2++;
		}
 
		for (j=s2;j<=i-1;j++)
		{
			if(HT[j].parent != 0)
			{
				continue;
			}
			s2 = HT[j].weight<HT[s2].weight?j:s2;
		}
		HT[s2].parent = i;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight+HT[s2].weight;  //��������С�Ľ��Ȩ�������ɸ����
	}


//��ÿ���ַ��Ĺ��������룬�洢�ڱ���HC��
//	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	cd[n-1]='\0';  //�洢����ֵ���±�n-1��Ϊ'\0'����
	for (i=1; i<=n;++i)  //����ַ������������
	{
		int start=n-1,c,f;   //start��ʼʱָ�����,�ȱ������λ��
		for (c=i,f=HT[i].parent; f!=0;c=f,f=HT[f].parent)  //fָ����c��˫�׽�㣬f��=0��Ҷ�ӽ�����ϻ��ݣ�ֱ�������
			                                               
		{
			if(HT[f].lchild==c)    //���c��f�����ӣ������ɴ���0
			{
				cd[--start]='0';    
			}
			else if(HT[f].rchild==c) //���c��f���Һ��ӣ������ɴ���1
			{
				cd[--start]='1';
			}
		}
		HC[i]=(char*)malloc((n-start) * sizeof(char));//Ϊÿ���ַ�����ռ�
		f=n-start;   //��������
		for(d=0;d<f;d++,start++)   //��cd�����е��ַ�����ֵ���͸�HC�Ķ�̬������ȥ
		{
			HC[i][d]=cd[start];
		}
	}
	free(cd);   //�ͷ���ʱ�ռ�
 
}

//��Ϣ�洢����
void cunchu_charnanme_Num()   
{
	int i;
	char charName[27]={' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N',     //�ַ��洢����
				 'O','P','Q','R','S','T','U','V','W','X','Y','Z'} ;    
    int Weight[27]={'186','64','13','22','32','103','21','15','47','57','1','5','32','20','57',   //Ȩ�ش洢����
					   '63','15','1','48','51','80','23','8','18','1','16','1'};
	
	a=(char *)malloc(n*sizeof(char));   //��ȫ�ֱ���a����ռ�
	b=(int *)malloc(n*sizeof(int));     //��ȫ�ֱ���b����ռ�

	for (i=0;i<n;i++)    //������charName���ݸ�������a
	{
		a[i]=charName[i];
	}
  
	for(i=0;i<n;i++)   //������Weight���ݸ�������b
	{
		b[i] = Weight[i];
	}
	
}

//��ʾ��������
void showHT_AND_showHC(HuffmanTree HT,HuffmanCode HC,int n, int m,char* a)
{
	int i=0;    
	int j=0;    
	int k=0;    //��ӡѭ��k

	printf("\n");
	printf("   >>>>���洢�Ĺ����������Լ�����<<<<\n");
	printf("  |__________________________________|\n");
	for (i = 1; i <= n; i++)      //�Ѷ�ά�������ʽ�����������
	{
		printf("  |**%4c  :",a[i-1]);    //����ַ�
		
		for(k=0;HC[i][k]!='\0'; k++)
		{
			printf("%c",HC[i][k]);   //����ַ���Ӧ������ֵ
		
		}
	    printf("%13c",'*');
		printf("\n");
	}
	printf("  |__________________________________|\n");
	printf("\n");
}


//��������Ҫ����ĸ�ı���ֵ
void Find_letter(HuffmanTree HT,HuffmanCode HC,int n, int m,char* a)
{
	int i;
	int j;
	int k;
	int num=0;
	char find1[100];   //���ַ�������
	printf(">>>>>>>>>>>>>��������Ҫ���ҵ��ַ��ı���ֵ('#'��������):");
	for(i=0;;i++)                 //��ѭ�������ַ���'#'��������
	{
		num++;
		scanf("%c",&find1[i]);
		if(find1[i]=='#')
		{
			 break;
		} 
		
	}

	printf("\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>�ַ��Ĺ�����������:");

	for (i=0;i<num;i++)                       //��ӡ���ҵ���Ӧ�ַ��ı���ֵ
	{	
		for(k=1;k<n;k++)
		{	
			if(find1[i]==HT[k].charname)            //��������ַ���洢�����ַ���ȣ���ӡ�����
			{
				
				for(j=0;j<=11;j++)
				{	
			 		printf("%c",HC[k][j]);
				}
			}
		
		}
		//printf("\n");
	}
	printf("\n");
	printf("\n");
}


void Find_num(HuffmanTree HT,HuffmanCode HC,int n, int m,char* a)
{

	int i=0;
	int j;
	int k=0;
	int c=0;
	char find2[100];       //����������
	printf(">>>>>>>>>>>>����������Ҫ��ѯ�����Ӧ��ĸ��ֵ('#'��������):");
	//scanf("%s",&find2);
    gets(find2);
	printf("\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>��Ҫ��ѯ���ַ�Ϊ:");

	while(find2[i]!='#')            //����������ֵ������Ϊ'#'�����whileѭ�����ҵ���Ӧ���ַ�
	{
		for(j=1;j<28;j++)
		{	
			while(find2[i+k]==HC[j][k])         //����ҵ���������ֵ��洢����ֵ��ȣ�����
			{	
				//printf("0");
				k++;
				if(HC[j][k]=='\0')      //�������������'\0'
				{
				
					k--;
					printf("%c",HT[j].charname);   //��ӡ��Ӧ���ַ�
					break;
				}
			
			}
		    if(find2[i+k]!=HC[j][k])    //���������ѭ�����ж���һ����ά����ֵ�Ƿ���ȣ�ֱ���ҵ�Ϊֹ
			{
				k=0;
				continue;
			} 
			else 
			{
				i=i+k+1;              //���ʱ��i=i+k+1,�жϵڶ����ַ�����ֵ�����û��������
				k=0;
				continue;
			}
		}
	}
		printf("\n");
}
 
void main()
{
	int t;
	char ss;
	HuffmanTree HT;    
	HuffmanCode HC;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));    //��̬����m+1����Ԫ
	HC=(HuffmanCode)malloc(n*sizeof(HuffmanCode));   //��̬����n����Ԫ

	cunchu_charnanme_Num();    //�洢����
	HuffmanCoding(HT, HC, a, b, n);   //�洢���뺯��



	while(t!=4)    //���벻ͬ��ֵ���в�ͬ����
	{	printf("     ��������Ӧ�ַ���ʼִ�г���\n");
		printf("\n");
		printf("     >>>>>1. ����洢�Ĺ��������������ֵ <<<<<\n");
		printf("     >>>>>2.�����ַ���ȡ���Ӧ�Ķ���������<<<<<\n");
		printf("     >>>>>3.  ��������ƻ�ȡ���Ӧ���ַ�  <<<<<\n");
	    printf("     >>>>>4.              �˳�            <<<<<\n");
		printf("          >>>>>>>>>>>>>>>����<<<<<<<<<<<<<<<\n");
		printf("                     ָ�  "); 
		scanf("%d",&t);
		switch(t)
		{
			 case 1:	
				
				 showHT_AND_showHC(HT, HC, n, m, a);   //����1����ӡ�洢������
				 break;
			 case 2: 
				 Find_letter(HT, HC, n, m, a);   //����2��Ѱ���ַ���Ӧ����ֵ
				 break;
			 case 3:
				 scanf("%c",&ss);
				 Find_num(HT, HC, n, m, a);   //����3��Ѱ�ұ����Ӧ�ַ�
				 break;
			 case 4: 
				 printf("          >>>>>>>>>>>>>>>�˳�<<<<<<<<<<<<<<<\n");   //����4���˳�ϵͳ
				 break;
				 
		}
	}
}