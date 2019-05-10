
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<iomanip>
 
using namespace std;
 
string  skipblacks(string str) //���Կո�
{
    string return_str="";
    int length=str.length();
    for(int i=0;i<length;i++)
		if(str[i]!=' ')
			 return_str+=str[i];
    return return_str;
}
 
string str_dele(string s,int m)    //ɾ���ַ���str�ĵ�m���ַ�
{
	int len=s.length(); 
	char temp_str[100];
 
	if(m>len)
		cout<<"ɾ����λ�ò���!"<<endl;
	else
	{
		int j = 0;
		for(int i = 0;i<s.size();i++)
		{
			if(i==m-1) 
				continue;
			else 
				temp_str[j++]=s[i];
		}
	}
	for(int i=0,j=0;j<len-1;)
		s[j++]=temp_str[i++];
	string sn = "";
	for(int i = 0;i<s.size()-1;++i)
		sn += s[i];
	return sn;
}
 
vector<double> renew(vector<double> num,double tmpresult,int i)
{
	vector<double> vnew;
	for(int j = 0;j<i;++j)
		vnew.push_back(num[j]);
	vnew.push_back(tmpresult);
	if(i < num.size()-2)
		for(int j = i + 2;j<num.size();++j)
			vnew.push_back(num[j]);
 
	return vnew;
}
 
vector<char> clearchch(vector<char> vch)  //ȥ���˺ų���
{
	vector<char> nvch;
	for(int i = 0;i<vch.size();++i)
		if(vch[i] != '*'&&vch[i] != '/')
			nvch.push_back(vch[i]);
 
	return nvch;
}
 
int main()
{
	string str;
	vector<double> result;//������
	while(getline(cin,str))
	{
		if(str == "0")
			break;
		vector<char> vch;
		vector<int> vi;
		string s = skipblacks(str);//�����ַ����еĿո�
 
		for(int i = 0;i<s.size();++i)
		{
			if((s[i]=='+')|(s[i]=='-')|(s[i]=='*')|(s[i]=='/'))
				vch.push_back(s[i]); //�����������
			else if(s[i]>='0'&&s[i]<='9')
				vi.push_back(s[i]-'0'); //��������
		}
 
		string ns = s;
		vector<double> vpos;//��¼���������ԭ�ַ����е�λ��
		vector<double> vnum;//��¼ÿ������λ��
		for(int i = 0;i<vch.size();++i)
		{
			size_t pos = ns.find(vch[i]);
			ns = str_dele(ns,pos+1);
			vpos.push_back(pos+i+1);
		}
 
		vnum.push_back(vpos[0]-1);
		for(int i = 0;i<vpos.size()-1;++i)
			vnum.push_back(vpos[i+1]-vpos[i]-1);
 
		double tmpsum = 0;
		for(int i = 0;i<vnum.size();++i)
			tmpsum += vnum[i];
		double tmps = s.size()-vch.size()-tmpsum;
		vnum.push_back(tmps);
 
		vector<double> num;//��viת��Ϊ����
		double tmpn = 0;
		for(int i = 0;i<=vch.size();++i)
		{
			double sum = 0;
			tmpn += vnum[i];
			for(int j = 0;j<vnum[i];++j)
				sum += vi[j+tmpn-vnum[i]]*pow(10,vnum[i]-1-j);
			num.push_back(sum);
		}
	
		vector<double> vnew = num;
		int ccnt = 0;
		for(int i = 0;i<vch.size();++i)
		{
			if((vch[i] == '*')|(vch[i] == '/'))
			{
				double tmpresult;
				if(vch[i] == '*')
					tmpresult = num[i]*num[i+1];
				else
					tmpresult = num[i]/num[i+1];
				vnew = renew(vnew,tmpresult,i-ccnt);//���½��
				++ccnt; //ͳ���Ѿ���������ٸ�*��/��
			}
		}
 
		vector<char> nvch = clearchch(vch);//ȥ���˺źͳ���ֻʣ�¼Ӽ���
		double restmp = vnew[0];
		for(int i = 0;i<nvch.size();++i)
		{
			if(nvch[i] == '+')
				restmp = restmp + vnew[i+1];
			else
				restmp = restmp - vnew[i+1];
		}
		result.push_back(restmp);
	}
	for(int i = 0;i<result.size();++i)
		cout<<fixed<<setprecision(2)<<result[i]<<endl;  //������λС��
 
	system("pause");
	return 0;
	} 
