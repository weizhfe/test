#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct HTNode
{
	char charname;
	 int weight;
	 int parent, lchild, rchild;
}HTNode, *HuffmanTree;


typedef char **HuffmanCode;    //动态分配数组存储字符编码的动态空间

int n=27,m=53;    // m=2*n-1   m为根节点个数
char *a;
int *b;

void HuffmanCoding(HuffmanTree HT,HuffmanCode HC,char *a,int *b,int n)
{
	int i;//通用整型变量i，用于循环中
	int s1 = 0;  //变量s1用于哈夫曼树的创建
	int s2 = 0;//变量s2用于哈夫曼树的创建
	int j;
	int d;
	int m=2 * n - 1;
	char *cd=(char*)malloc(n*sizeof(char));  //分配临时存放每个字符编码的动态空间，译码使用

//构造哈夫曼树HT
	if(n<=1)
	{
		return ;
	}//n值小于等于1，不满足创建哈弗曼树的条件
	//HT=(HuffmanTree)malloc(((2*n-1)+1)*sizeof(HTNode));
	for(i=1;i<=n;++i)
	{
		HT[i].charname=a[i-1];
		HT[i].weight=b[i-1];
		HT[i].parent=0;
		HT[i].lchild=-1;
		HT[i].rchild=-1; 	
	}
	for(;i<=m;++i)    //所要产生结点初始化所要产生结点
	{
		HT[i].charname='0';
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
	}


//以下功能为寻找权值字最小的两个值

	for(i=n+1;i<=m;++i)   //用于筛选出两个权重最小的两个
	{ 
		for(s1=1;HT[s1].parent!=0;)
		{
			s1++;
		}       //双亲不为0，让变量s1加1，寻找双亲为0的结点
 
		for (j=s1;j<=i-1;j++)    //用于寻找第一个双亲为0的结点
		{
			if(HT[j].parent!=0)
			{
				continue;
			}
			s1=HT[j].weight<HT[s1].weight?j:s1;  //寻找第一个权重最小的下标
		}
 
		HT[s1].parent=i;   
		HT[i].lchild=s1;
 
		for(s2=1;HT[s2].parent!=0;)   //同s1作用一样，找第二个双亲为0的结点
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
		HT[i].weight = HT[s1].weight+HT[s2].weight;  //将两个最小的结点权重相加组成父结点
	}


//求每个字符的哈夫曼编码，存储在编码HC中
//	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	cd[n-1]='\0';  //存储编码值，下标n-1的为'\0'结束
	for (i=1; i<=n;++i)  //逐个字符求哈夫曼编码
	{
		int start=n-1,c,f;   //start开始时指向最后,既编码结束位置
		for (c=i,f=HT[i].parent; f!=0;c=f,f=HT[f].parent)  //f指向结点c的双亲结点，f！=0从叶子结点向上回溯，直到根结点
			                                               
		{
			if(HT[f].lchild==c)    //结点c是f的左孩子，则生成代码0
			{
				cd[--start]='0';    
			}
			else if(HT[f].rchild==c) //结点c是f的右孩子，则生成代码1
			{
				cd[--start]='1';
			}
		}
		HC[i]=(char*)malloc((n-start) * sizeof(char));//为每个字符分配空间
		f=n-start;   //继续回溯
		for(d=0;d<f;d++,start++)   //将cd数组中的字符译码值传送给HC的动态数组中去
		{
			HC[i][d]=cd[start];
		}
	}
	free(cd);   //释放临时空间
 
}

//信息存储函数
void cunchu_charnanme_Num()   
{
	int i;
	char charName[27]={' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N',     //字符存储数组
				 'O','P','Q','R','S','T','U','V','W','X','Y','Z'} ;    
    int Weight[27]={'186','64','13','22','32','103','21','15','47','57','1','5','32','20','57',   //权重存储数组
					   '63','15','1','48','51','80','23','8','18','1','16','1'};
	
	a=(char *)malloc(n*sizeof(char));   //给全局变量a分配空间
	b=(int *)malloc(n*sizeof(int));     //给全局变量b分配空间

	for (i=0;i<n;i++)    //将数组charName内容给予数组a
	{
		a[i]=charName[i];
	}
  
	for(i=0;i<n;i++)   //将数组Weight内容给予数组b
	{
		b[i] = Weight[i];
	}
	
}

//显示哈夫曼树
void showHT_AND_showHC(HuffmanTree HT,HuffmanCode HC,int n, int m,char* a)
{
	int i=0;    
	int j=0;    
	int k=0;    //打印循环k

	printf("\n");
	printf("   >>>>所存储的哈夫曼编码以及译码<<<<\n");
	printf("  |__________________________________|\n");
	for (i = 1; i <= n; i++)      //已二维数组的形式输出哈夫曼树
	{
		printf("  |**%4c  :",a[i-1]);    //输出字符
		
		for(k=0;HC[i][k]!='\0'; k++)
		{
			printf("%c",HC[i][k]);   //输出字符对应的译码值
		
		}
	    printf("%13c",'*');
		printf("\n");
	}
	printf("  |__________________________________|\n");
	printf("\n");
}


//查找所需要的字母的编码值
void Find_letter(HuffmanTree HT,HuffmanCode HC,int n, int m,char* a)
{
	int i;
	int j;
	int k;
	int num=0;
	char find1[100];   //存字符码数组
	printf(">>>>>>>>>>>>>请输入所要查找的字符的编码值('#'结束输入):");
	for(i=0;;i++)                 //可循环输入字符，'#'结束输入
	{
		num++;
		scanf("%c",&find1[i]);
		if(find1[i]=='#')
		{
			 break;
		} 
		
	}

	printf("\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>字符的哈夫曼编码是:");

	for (i=0;i<num;i++)                       //打印所找到对应字符的编码值
	{	
		for(k=1;k<n;k++)
		{	
			if(find1[i]==HT[k].charname)            //如果输入字符与存储数组字符相等，打印其编码
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
	char find2[100];       //译码存放数组
	printf(">>>>>>>>>>>>请输入所需要查询译码对应字母的值('#'结束输入):");
	//scanf("%s",&find2);
    gets(find2);
	printf("\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>所要查询的字符为:");

	while(find2[i]!='#')            //如果输入编码值结束不为'#'则进入while循环来找到对应的字符
	{
		for(j=1;j<28;j++)
		{	
			while(find2[i+k]==HC[j][k])         //如果找到输入译码值与存储译码值相等，进入
			{	
				//printf("0");
				k++;
				if(HC[j][k]=='\0')      //如译码数组结束'\0'
				{
				
					k--;
					printf("%c",HT[j].charname);   //打印对应的字符
					break;
				}
			
			}
		    if(find2[i+k]!=HC[j][k])    //不相等跳出循环，判断下一个二维数组值是否相等，直到找到为止
			{
				k=0;
				continue;
			} 
			else 
			{
				i=i+k+1;              //相等时让i=i+k+1,判断第二个字符编码值，如果没有则跳出
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
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));    //动态分配m+1个单元
	HC=(HuffmanCode)malloc(n*sizeof(HuffmanCode));   //动态分配n个单元

	cunchu_charnanme_Num();    //存储函数
	HuffmanCoding(HT, HC, a, b, n);   //存储译码函数



	while(t!=4)    //输入不同的值进行不同操作
	{	printf("     请输入相应字符开始执行程序\n");
		printf("\n");
		printf("     >>>>>1. 输出存储的哈夫曼编码和译码值 <<<<<\n");
		printf("     >>>>>2.输入字符获取其对应的二进制译码<<<<<\n");
		printf("     >>>>>3.  输入二进制获取其对应的字符  <<<<<\n");
	    printf("     >>>>>4.              退出            <<<<<\n");
		printf("          >>>>>>>>>>>>>>>输入<<<<<<<<<<<<<<<\n");
		printf("                     指令：  "); 
		scanf("%d",&t);
		switch(t)
		{
			 case 1:	
				
				 showHT_AND_showHC(HT, HC, n, m, a);   //输入1，打印存储哈夫曼
				 break;
			 case 2: 
				 Find_letter(HT, HC, n, m, a);   //输入2，寻找字符对应编码值
				 break;
			 case 3:
				 scanf("%c",&ss);
				 Find_num(HT, HC, n, m, a);   //输入3，寻找编码对应字符
				 break;
			 case 4: 
				 printf("          >>>>>>>>>>>>>>>退出<<<<<<<<<<<<<<<\n");   //输入4，退出系统
				 break;
				 
		}
	}
}