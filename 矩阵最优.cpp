#include<stdio.h>
 #include<iostream>
 #include<algorithm>
 #include<stdlib.h>
 using namespace std;
 const int MAX = 100;
 int n;
 int p[MAX+1],m[MAX][MAX],s[MAX][MAX];
 //p������¼����m[i][j]��ʾ��i�����󵽵�j����������Ž⣬s[][]��¼������Ͽ����Եõ����Ž�
 void matrixChain()
 {
     for(int i=1; i<=n; i++)//��ʼ������
         m[i][i]=0;
     for(int r=2; r<=n; r++)//�Խ���ѭ��
     {
         for(int i=1; i<=n-r+1; i++) //��ѭ��
         {
             int j=i+r-1;//�еĿ���
             m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];//��m[i][j]����Сֵ����ʼ��ʹk=i;
             s[i][j]=i;
             for(int k=i+1; k<j; k++)
             {
                 int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                 if(t<m[i][j])
                 {
                     s[i][j]=k;//��kλ�öϿ��õ����Ž�
                     m[i][j]=t;
                 }
             }
         }
     }
 }
 void traceback(int i,int j)
 {
     if(i==j)
         return;
     traceback(i,s[i][j]);
     traceback(s[i][j]+1,j);
     cout<<"Multiply A"<<i<<","<<s[i][j]<<"and A"<<s[i][j]+1<<","<<j<<endl;
 }
 int main()
 {
     cin>>n;
     for(int i=0; i<=n; i++)
         cin>>p[i];
     matrixChain();
     traceback(1,n);
     cout<<m[1][n]<<endl;
     return 0;
 }
