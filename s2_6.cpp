#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <fstream>
using namespace std;

struct WORD
{
    string word;
    int num;
};

vector<WORD> a;  //����vector����a[]

int&value(const string&s)
{
    for(int i=0;i<a.size();i++)
        if(s==a[i].word)
            return a[i].num;
        WORD p;
        p.word=s;
        p.num=0;
        a.push_back(p);  //������a����������
        return a[a.size()-1].num;
}

int main()
{
    string str;
    cout << "�����ַ�����\n";
    char c;
    while(c=cin.get())
    {
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || c==' ' || c=='\n')  
            str+=c;   //ȥ������
        if(c=='\n')
            break;
    }
//���ȥ����Ӣ���ַ����ַ���
        
    for(int j=0;str[j]!='\0';j++)
    {
        if(str[j]>='A'&&str[j]<='Z')
        {
            str[j]+= 32;  //��д��ĸAscll��+32ת��ΪСд
        }
    }
 //���ת��ΪСд���ַ���

    string buf;
    ofstream fout("D:\\123.txt");  //��ת���õ��ַ���д���ļ�
    fout<<str;
    fout.close ();
    ifstream fin("D:\\123.txt");  //����д����ַ���������
    while(fin>>buf){
		value(buf)++;
	}
    vector<WORD>::const_iterator p;  //����������Ԫ��
	ofstream output("D:\\Result1.txt");  //��������ļ���
    for(p=a.begin();p!=a.end();++p)
        output<<p->word<<":"<<p->num<<'\n';  //�����������浽Result1.txt��
    return 0;
}