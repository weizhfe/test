#include <iostream>
using namespace std;
#define n 4
int s[n] = { 1,2,3,4};//������������1��4
int r[4];
int v[n];
 
void print(){
    for(int i = 0; i<4;i++)
       cout<<s[r[i]]<<" ";//�������ֵ������
    cout<<endl;
}
void combination(){
    int k = 0 ;r[0] = -1;
	while(k>=0){
		r[k]++;
		while(r[k]<n&&v[r[k]]!=0)
			r[k]++;
		if(r[k]<n){
			v[r[k]] = 1;
			if(k==2) //�ѵ����һλ���ҵ�һ�����У������
				print();
		    else{
				k++;
				r[k] = -1;
			}
		}else{//������ǰ����
			k--;
			for(int i = r[k]-1; i< n; i++)
				v[i] = 0;
		}
	}
}
 
int main(){
	memset(v,0,sizeof(v));
	combination();
	return 0 ;
}
