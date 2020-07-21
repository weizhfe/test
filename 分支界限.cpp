#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
//bool select[10];//定义一个bool型数组用于判定是否选中对应物品；
int bagw=50,bagv,bestvalue,cw,cv;//背包可承受重量，背包可承受价值，最佳价值，当前重量，当前价值；
float ub;//上界;
//queue<thing> bestq;//定义一个结构体队列，用于存放最终结果；
struct avgvalue{//结构体存放物体的编号与单位重量的价值；

    int num;

    float avg;

    int value;//对应物品价值；

    int weight;//对应物品重量；

}re[10];
struct node{//定义结点；
	int cw;
    int cv;
    float ub;

}point[2];//point[0]表示左结点，[1]表示右结点；
void compare(avgvalue re[10])//排序物品单位重量的价值；
{

    int i,j,tmp;

    float t;

    for(i=0;i<=9;i++)

    {

       for(j=i+1;j<=9;j++)

        {

           if(re[i].avg<re[j].avg)

            {

               t=re[i].avg;

               re[i].avg=re[j].avg;

               re[j].avg=t;

               tmp=re[i].value;

               re[i].value=re[j].value;

               re[j].value=tmp;

               tmp=re[i].weight;

               re[i].weight=re[j].weight;

               re[j].weight=tmp;

            }

            else

               continue;

        }

    }

}

int der(avgvalue re1[10])//界限函数；
{

    int i,k,t;//j用来存放当前最大单位回报;

    float j;

    cw=0,cv=0;//初始化当前重量与价值；

    j=re[0].avg;

   ub=j*(bagw-cw)+cv;//上界公式,找到根节点；

    for(i=0;i<=8;i++)

    {

       j=re[i+1].avg;

       point[1].cv=cv;

       point[1].cw=cw;

        point[1].ub=j*(bagw-point[1].cw)+point[1].cv;//不包含第i个物品时当前最佳回报；

       point[0].cw=re1[i].weight;

       if(cw+point[0].cw<=bagw)//包含第i个物品不超重的情况下；

        {

           point[0].cv=re1[i].value;

           point[0].ub=j*(bagw-cw-point[0].cw)+point[0].cv+cv;//包含第i个物品时当前最佳回报；

 

           if(point[0].ub>point[1].ub)

            {

               ub=point[0].ub;

               cw+=point[0].cw;

               cv+=point[0].cv;

            }

            else

               ub=point[1].ub;

        }

        else//若包含超重，直接选择不包含的情况；

           ub=point[1].ub;

    }

    return cv;
}
int main()
{
	int i;
    for(i=0;i<=9;i++)
    {

       cin>>re[i].weight;//输入10个物品的重量；
    }
   for(i=0;i<=9;i++)
    {
       cin>>re[i].value;//输入10个物品的价值；
    }
    for(i=0;i<=9;i++)
    {
        re[i].num=i;
        re[i].avg=(float)re[i].value/re[i].weight;
    }
    compare(re);
   bestvalue=der(re);
   cout<<bestvalue<<endl;
    return 0;
}
