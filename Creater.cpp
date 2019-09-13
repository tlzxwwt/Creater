#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#pragma comment(lib,"ws2_32.lib")
#define test MessageBox(NULL,"test","test",MB_OK);
#define qwq MessageBox(NULL,"�ù��������з��У���ע�����Ի�ȡ���£�","Information",MB_ICONINFORMATION|MB_OK);
#define MAXN 101
#define MAX_HOME_LEVEL 4
#define values home+day+money+fields+food+woods+wood+houses+science+farmers+workers+scientists+army+armyf+treat+lighting
#define ivalues &home,&day,&money,&fields,&food,&woods,&wood,&houses,&science,&farmers,&workers,&scientists,&army,&armyf,&treat,&lighting,&a,&b
#define ovalues home,day,money,fields,food,woods,wood,houses,science,farmers,workers,scientists,army,armyf,treat,lighting,a,b
#define new_game day=1;money=0;fields=1;food=1000;woods=1;wood=1000;houses=0;farmers=0;workers=0;science=0;scientists=0;army=0;armyf=0;treat=0;lighting=0;for(int i=0;i<=maxspells[home];i++){spells[i]=0;}home=1;
using namespace std;
bool qexit,connected;
int home,day,money,fields,food,woods,wood,houses,science,farmers,workers,scientists,army,armyf,treat,lighting,spells[MAXN],a,b,e;
int treats,lightings;
int maxfood[MAXN]={0,10000,50000,100000,200000};
int maxwood[MAXN]={0,10000,50000,100000,200000};
int maxscience[MAXN]={0,1000,2500,4000,8000};
int maxfields[MAXN]={0,10,40,80,100};
int maxwoods[MAXN]={0,10,40,80,100};
int maxhouses[MAXN]={0,3,8,20,25};
int armyHP[MAXN]={0,500,1000,2000,2500};
int armyACT[MAXN]={0,80,150,250,400};
int armycost[MAXN]={0,400,650,1000,2000};
int armyup[MAXN]={600,1250,2500,4000};
int maxspells[MAXN]={0,2,3,5,8};
int treatup[MAXN]={100,200,250,400};
int treateff[MAXN]={0,300,500,750,1000};
int treatcost[MAXN]={0,150,250,400,500};
int lightingup[MAXN]={100,200,250,400};
int lightingeff[MAXN]={0,300,500,750,1000};
int lightingcost[MAXN]={0,150,250,400,500};
int hlu[MAXN]={0,8000,40000,95000,190000};
FILE *fp1,*fp2;
TCHAR TextBuf[1001];
string strSvrIp;
int port;
WORD sockVersion;
WSADATA wsaData;
SOCKET client;
sockaddr_in qsin;
void save()
{
	fp2=fopen("value.a","w");
	a=(10-((values)%10))%10;
	b=sqrt(values+a);
	fprintf(fp2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d ",ovalues);
	for(int i=0;i<MAXN;i++) fprintf(fp1,"%d ",spells[i]);
	fprintf(fp2,"%d",23333);		
	fclose(fp2);
}
bool check()
{
	int t=values+a,t2=sqrt(t);
	if(t%10||a/10||b!=t2||e!=23333) return 0;
	return 1;
}
inline void init()
{
	system("cls");
	cout<<"--------------------��ׯ������--------------------\n";
	cout<<"                             maker:tlzx\n";
	Sleep(500);
	system("cls");
	cout<<"loading...\n";
	srand(time(0));
	fp1=fopen("value.a","r");	
	fscanf(fp1,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",ivalues);
	for(int i=0;i<MAXN;i++) fscanf(fp1,"%d",&spells[i]);
	fscanf(fp1,"%d",&e);	
	fclose(fp1);
	if(home==0)
	{
		new_game
		save();
	}
	else if(!check())
	{
		int c=MessageBox(NULL,"���ݳ��ֹ��ϣ��Ƿ����¿�ʼ��Ϸ��","Error",MB_ICONWARNING|MB_OKCANCEL);
		if(c==IDOK)
		{
			new_game
			save();
		}
		else
		{
			qexit=1;
			return;
		}
	}
	for(int i=1;i<=spells[0];i++)
	{
		switch(spells[i])
		{
			case 1:
			{
				treats++;
				break;
			}
			case 2:
			{
				lightings++;
				break;
			}			
		}
	}	
}
void show()
{
	system("cls");
	cout<<"��"<<day<<"��"<<endl;
	cout<<"����������"<<money<<endl;
	cout<<"��ׯ�ȼ���"<<home<<endl;
	cout<<"��ʳ������"<<food<<"/"<<maxfood[home]<<endl;
	cout<<"��ʳ�ܲ�����"<<fields*100-houses*50+farmers*75<<"/��"<<endl;
	cout<<"ľ�Ĵ�����"<<wood<<"/"<<maxwood[home]<<endl;
	cout<<"ľ���ܲ�����"<<woods*100+workers*25<<"/��"<<endl;
	cout<<"��ѧ��������"<<science<<"/"<<maxscience[home]<<endl;
	cout<<"��ѧ�������"<<scientists*75<<"/��"<<endl;	
	cout<<"С��������"<<houses<<"/" <<maxhouses[home]<<endl;
	cout<<endl;
	cout<<"������\n0.���¿�ʼ��Ϸ\n1.������ׯ\n2.���콨��\n3.���乤��\n4.�о�\n5.����\n6.���÷���\n7.ս��\n8.�̵�\n";
	cout<<"������\nn����һ��\ns������\ne�����沢�˳�\nh������\nc�����ӷ�����\n";
}
void menu(int mode)
{
	system("cls");
	switch(mode)
	{
		case 2:
		{
			cout<<"ũ��������"<<fields<<"/"<<maxfields[home]<<endl;
			cout<<"��ʳ������"<<food<<"/"<<maxfood[home]<<endl;			
			cout<<"����������"<<woods<<"/"<<maxwoods[home]<<endl;
			cout<<"ľ�Ĵ�����"<<wood<<"/"<<maxwood[home]<<endl;
			cout<<"С��������"<<houses<<"/" <<maxhouses[home]<<endl;
			cout<<endl;
			cout<<"������\n0.����\n1.����ũ��\n2.��������\n3.����С��\n";
			break;
		}
		case 3:
		{
			cout<<"����������"<<houses<<endl;
			cout<<"1.ũ��������"<<farmers<<endl;
			cout<<"2.��ľ������:"<<workers<<endl;
			cout<<"3.ѧ������:"<<scientists<<endl;
			cout<<endl;
			cout<<"������\n0.����\n1.���·��乤��\n";
			break;
		}
		case 4:
		{
			cout<<"�о���\n";
			cout<<"��ѧ��������"<<science<<"/"<<maxscience[home]<<endl;			
			cout<<"���ӵȼ���"<<army<<"/"<<home<<endl;
			cout<<"���Ʒ����ȼ���"<<treat<<"/"<<home<<endl;
			cout<<"���編���ȼ���"<<lighting<<"/"<<home<<endl;
			cout<<endl;
			cout<<"������\n0.����\n1.��������\n2.�������Ʒ���\n3.�������編��\n"; 
			break;
		}
		case 5:
		{
			cout<<"���ӵȼ���"<<army<<endl;
			cout<<"��������ֵ��"<<armyHP[army]<<endl;
			cout<<"���ӹ�������"<<armyACT[army]<<endl;
			cout<<"����״̬��"<<(armyf?"��":"��")<<endl;
			cout<<endl;
			cout<<"������\n0.����\n1.ѵ������\n";
			break;
		}
		case 6:
		{
			cout<<"����������"<<spells[0]<<"/"<<maxspells[home]<<endl;
			cout<<"���Ʒ�����"<<treats<<endl;
			cout<<"���編����"<<lightings<<endl;
			cout<<endl;
			cout<<"����:\n0.����\n1.�������Ʒ���\n2.�������編��\n";
			break;
		}
	}
}
bool comp(int a,int b)
{
	return a>b;
}
void fight()
{
	if(!armyf)
	{
		MessageBox(NULL,"����ѵ�����ӣ�","Error",MB_OK);
		return;
	}
	armyf=0;
	int HP=armyHP[army],ACT=armyACT[army],c,rew,i;
	int mHP[MAXN],mACT[MAXN],mcnt=rand()%home+2;
	for(int i=1;i<=mcnt;i++)
	{
		mHP[i]=rand()%(200*home+1)+home*400;
		mACT[i]=rand()%(40*home+1)+home*40;
	}
	while(1)
	{
		while(1)
		{
			system("cls");
			cout<<"ʣ�����������"<<mcnt<<endl;
			cout<<"��ǰ����HP��"<<mHP[mcnt]<<endl;
			cout<<"��ǰ���޹�������"<<mACT[mcnt]<<endl;
			cout<<endl;
			cout<<"����HP��"<<HP<<endl;
			cout<<"����ս������"<<ACT<<endl;
			cout<<endl;
			cout<<"������\n0.����\n1.����\n2.ʹ�÷���\n";		
			cin>>c;
			switch(c)
			{
				case 0:
				{
					return;
				}
				case 1:
				{
					cout<<"����HP-"<<ACT<<endl;
					mHP[mcnt]-=ACT;
					qexit=1;
					break;
				}
				case 2:
				{
					cout<<endl<<endl;
					cout<<"1��ʹ�����Ʒ���("<<treats<<")\n";
					cout<<"2��ʹ�����編��("<<lightings<<")\n";
					cout<<"���ࣺ������һ��\n";
					cin>>c;
					switch(c)
					{
						case 1:
						{
							if(!treats)
							{
								cout<<"�÷������ù�\n";
								Sleep(250);
							}
							else
							{
								cout<<"����HP+"<<treateff[treat]<<endl;
								treats--;
								i=1;
								while(spells[i]!=1) i++;
								spells[i]=0;
								sort(spells+1,spells+1+spells[0],comp);
								spells[0]--;
								HP+=treateff[treat];
								HP=min(HP,armyHP[army]);
							}
							break;
						}
						case 2:
						{
							if(!lightings)
							{
								cout<<"�÷������ù�\n";
								Sleep(250);
							}
							else
							{
								cout<<"����HP-"<<lightingeff[lighting]<<endl;
								lightings--;
								i=1;
								while(spells[i]!=2) i++;
								spells[i]=0;
								sort(spells+1,spells+1+spells[0],comp);
								spells[0]--;
								mHP[mcnt]-=lightingeff[lighting];
							}
							break;
						}						
					}
					break;
				}
				default :
				{
					cout<<"������Ч������������\n";
					Sleep(100);
					break;				
				}
			}
			if(qexit)
			{
				qexit=0;
				break;
			}		
		}
		if(mHP[mcnt]<=0)
		{
			cout<<"������һֻ���ޣ�\n";
			rew=rand()%(home)+1;
			cout<<"��������"<<rew<<endl;
			money+=rew;
			Sleep(800);
			mcnt--;
			if(mcnt<=0)
			{
				cout<<"ս��ʤ����\n";
				rew=rand()%(home*2)+1;
				cout<<"��������"<<rew<<endl;
				money+=rew;
				Sleep(800);
				return;
			}
		}
		else
		{
			cout<<"����HP-"<<mACT[mcnt]<<endl;
			HP-=mACT[mcnt];
			if(HP<=0)
			{
				cout<<"�㱻���޴���ˣ�\n";
				Sleep(800);
				return;
			}
			else Sleep(800);
		}
	}
}
void shop()
{
	system("cls");
	cout<<"��ӭ�����̵�\n";
	Sleep(1000);
	char c;
	while(1)
	{
		system("cls");
		cout<<"��Ľ���������"<<money<<endl;
		cout<<"������\n";
		cout<<"0.����\n";
		cout<<"1.������ʳ��100/1����\n";
		cout<<"2.����ľ�ģ�100/1����\n";
		cout<<"3.�����ѧ�㣺50/1����\n";
		cin>>c;
		switch(c)
		{
			case '0':return;
			case '1':
			{
				if(money<1)
				{
					MessageBox(NULL,"��Ľ��²�������","Error",MB_OK|MB_ICONWARNING);
					break;	
				}
				money-=1;
				food+=100;
				food=min(food,maxfood[home]);
				break;
			}
			case '2':
			{
				if(money<1)
				{
					MessageBox(NULL,"��Ľ��²�������","Error",MB_OK|MB_ICONWARNING);
					break;	
				}
				money-=1;
				wood+=100;
				wood=min(wood,maxwood[home]);
				break;
			}
			case '3':
			{
				if(money<1)
				{
					MessageBox(NULL,"��Ľ��²�������","Error",MB_OK|MB_ICONWARNING);
					break;	
				}
				money-=1;
				science+=50;
				science=min(science,maxscience[home]);
				break;
			}						
		}
	}
}
void help()
{
	FILE *fi;
	fi=fopen("help.txt","w");
	fprintf(fi,"������\n");
	fprintf(fi,"��ׯ��������һ������̨С��Ϸ������Ϸ�У���ҿ��Ը����Լ����뷨�������ׯ��ѵ�����ӵȡ�\n");
	fprintf(fi,"����Ϸ����ҳ���У�����Ը�����ʾ�����в�����\n");
	fprintf(fi,"����Խ���ũ���������������Դ����������С�ݣ����乤����������Դ������ͨ���о��������ӡ������ȡ�\n");
	fprintf(fi,"��������ׯ����Խ����������ݣ�\n");
	fprintf(fi,"������һЩ������ݣ�\n\n");
	fprintf(fi,"������ׯ����Ҫ��ľ�ģ�\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"����%d����ׯ��%d\n",i+1,hlu[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"������ׯ�������ޣ�\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d����ׯ��\n��ʳ��%d\tľ�ģ�%d\n",i,maxfood[i],maxwood[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"������ׯ�������ޣ�\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d����ׯ��\nũ�%d\t���֣�%d\tС�ݣ�%d\n",i,maxfields[i],maxwoods[i],maxhouses[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"������ׯ�����洢���ޣ�\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d����ׯ��%d\n",i,maxspells[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"�������ӣ�\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d�����ӣ�\nѵ�����ģ�%d\tHP��%d\t��������%d\n",i,armycost[i],armyHP[i],armyACT[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"���Ʒ�����\n");
	fprintf(fi,"Ч�����ָ�����HP\n");
	fprintf(fi,"����������\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d����\n�������ģ�%d\t�ָ�HP:%d\n",i,treatcost[i],treateff[i]);
	}
	fprintf(fi,"\n");
	fclose(fi);
	MessageBox(NULL,"help.txt�ļ��Ѿ����ɣ�������Ķ�������","help",MB_OK);
}
void Close(SOCKET& client)
{
	if(client != NULL) closesocket(client);
	WSACleanup();
}
void SendBuf(char* buf)
{
	int len=strlen(buf);
	buf[len]='e';
	buf[len+1]='n';
	buf[len+2]='d';
}
int SendMsg(SOCKET& client,char* buf, int len)
{
	if(client == NULL ||!buf || len <1) return 0;	//����ʧ��
	int l =send(client,buf,len,0);
	if(l != len) return 0;	//���͵ĳ��Ⱥ�ָ���ĳ��Ȳ��� ʧ��
	return 1;
}
bool Connect()
{
	system("cls");
	cout<<"������������...";
	strSvrIp="192.168.0.103";
	//strSvrIp="127.0.0.1";
	port =111;
	//��ʼ��WSA
	sockVersion = MAKEWORD(2,2);
	if(WSAStartup(sockVersion,&wsaData)!= 0){
		cout<<"�׽��������ʼ��ʧ��:"<<GetLastError()<<endl;
		return 0;
	} 
	//�����׽���
	client = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(client == INVALID_SOCKET){
		cout<<"�����׽���ʧ��:"<<GetLastError()<<endl;
		return 0;
	} 
	//����������IP�Ͷ˿ڽṹ 
	qsin.sin_family = AF_INET;
	qsin.sin_port=htons(port);
	qsin.sin_addr.S_un.S_addr=inet_addr(strSvrIp.c_str());
	//���������������
	if(connect(client,(sockaddr*)&qsin,sizeof(qsin))==SOCKET_ERROR){
		cout<<"\n���ӷ�����ʧ��:"<<GetLastError()<<endl;
		Close(client);
		Sleep(1000);
		return 0; 
	}
	system("cls");
	cout<<"���ӷ��������"<<endl;
	char t[15]={"001connect"};
	SendBuf(t);
	SendMsg(client,t,strlen(t));
	for(int i=0;i<strlen(t);i++)
	{
		cout<<(int)t[i]<<" ";
	}
	Sleep(1000);
	connected=1;
	return 1;
}
void inter()
{
	char c;	
	while(1)
	{
		system("cls");
		cout<<"�������ӷ�����\n";
		cout<<"������\n";
		cout<<"0.����\n";
		cout<<"1.���û�������Ϣ\n";		
		cin>>c;
		switch(c)
		{
			case '0':
			{
				return;
			}
			case '1':
			{
				qwq
				break;
			}
			default :
			{
				cout<<"������Ч������������\n";
				Sleep(800);
			}
		}		
	}

}
void play()
{
	char c;
	while(1)
	{
		show();
		cin.clear();
		cin.sync();
		cin>>c;
		switch(c)
		{
			case '0':
			{
				if((MessageBox(NULL,"��ȷ�����¿�ʼ��Ϸ��","New game",MB_OKCANCEL)==IDOK))
				{
					new_game				
				}
				break;
			}
			case '1':
			{
				if(home>=MAX_HOME_LEVEL)
				{
					qwq
					break;
				}
				if(wood>=hlu[home])
				{
					wsprintf(TextBuf,TEXT("��ȷ��������Ĵ�ׯ������ľ��%d"),hlu[home],hlu[home]);
					if(MessageBox(NULL,TextBuf,"Level up",MB_OKCANCEL)==IDOK)
					{
						wood-=hlu[home];
						home++;
					}
				}
				else
				{
					wsprintf(TextBuf,TEXT("�����Դ���Ҳ��㣬��������ľ��%d"),hlu[home]);
					MessageBox(NULL,TextBuf,"Error",MB_OK);
				}
				break;
			}
			case '2':
			{
				while(1)
				{
					menu(2);
					cin>>c;
					switch(c)
					{
						case '0':
						{
							qexit=1;
							break;
						}
						case '1':
						{
							if(food>=500)
							{
								if(fields>=maxfields[home])
								{
									MessageBox(NULL,"���ũ�������Ѵ����ޣ�������ׯ��������ũ��","Error",MB_OK);
								}
								else
								{
									if(MessageBox(NULL,"ȷ������ũ����������ʳ500","Build",MB_OKCANCEL)==IDOK)
									{
										food-=500;
										fields++; 
									} 
								}
							}
							else MessageBox(NULL,"�����Դ���Ҳ��㣬����������ʳ500","Error",MB_OK);
							break;
						}
						case '2':
						{
							if(wood>=500)
							{
								if(woods>=maxwoods[home])
								{
									MessageBox(NULL,"������������Ѵ����ޣ�������ׯ������������","Error",MB_OK);
								}
								else
								{
									if(MessageBox(NULL,"ȷ����������������ľ��500","Build",MB_OKCANCEL)==IDOK)
									{
										wood-=500;
										woods++; 
									} 
								}
							}
							else MessageBox(NULL,"�����Դ���Ҳ��㣬��������ľ��500","Error",MB_OK);
							break;
						}
						case '3':
						{
							if(wood>=500)
							{
								if(houses>=maxhouses[home])
								{
									MessageBox(NULL,"���С�������Ѵ����ޣ�������ׯ��������С��","Error",MB_OK);
								}
								else
								{
									if(MessageBox(NULL,"ȷ������С��������ľ��500","Build",MB_OKCANCEL)==IDOK)
									{
										wood-=500;
										houses++; 
									} 
								}
							}
							else MessageBox(NULL,"�����Դ���Ҳ��㣬��������ľ��500","Error",MB_OK);
							break;
						}											
						default :
						{
							cout<<"������Ч������������\n";
							Sleep(100);
							break;
						}
					}
					if(qexit)
					{
						qexit=0;
						break;
					}			
				}
				break;
			}
			case '3':
			{
				while(1)
				{
					menu(3);
					cin>>c;
					switch(c)
					{
						case '0':
						{
							qexit=1;
							break;
						}
						case '1':
						{
							farmers=0;
							workers=0;
							scientists=0;
							int a,b;
							while(houses-farmers-workers-scientists>0)
							{
								system("cls");
								cout<<"����������"<<houses<<endl;
								cout<<"1.ũ��������"<<farmers<<endl;
								cout<<"2.��ľ������:"<<workers<<endl;
								cout<<"3.ѧ������:"<<scientists<<endl;								
								cout<<"�����Ӧ�����ı����ù������������\n";								
								cin>>a>>b;
								if(a==1)
								{
									farmers=b;
									farmers=min(farmers,houses-workers-scientists);
								}
								else if(a==2)
								{
									workers=b;
									workers=min(workers,houses-farmers-scientists);
								}
								else if(a==3)
								{
									scientists=b;
									scientists=min(scientists,houses-farmers-workers);
								}															
							}
							break;	
						}
						default :
						{
							cout<<"������Ч������������\n";
							Sleep(100);							
							break;
						}
					}
					if(qexit)
					{
						qexit=0;
						break;
					}
				}
				break;
			}
			case '4':
			{
				while(1)
				{
					menu(4);
					cin>>c;
					switch(c)
					{
						case '0':
						{
							qexit=1;
							break;
						}
						case '1':
						{
							if(army==home) MessageBox(NULL,"��ľ����Ѵﵽ��ǰ��ׯ�ȼ�����߼�","Error",MB_OK);
							else if(science<armyup[army])
							{
								wsprintf(TextBuf,TEXT("�����Դ���Ҳ��㣬���������Ŀ�ѧ��%d"),armyup[army]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);
							}
							else
							{
								wsprintf(TextBuf,TEXT("ȷ���������������������Ŀ�ѧ��%d"),armyup[army]);
								if(MessageBox(NULL,TextBuf,"Level up",MB_OK)==IDOK)
								{
									science-=armyup[army];
									army++;
								}
							}
							break;
						}
						case '2':
						{
							if(treat==home) MessageBox(NULL,"������Ʒ����Ѵﵽ��ǰ��ׯ�ȼ�����߼�","Error",MB_OK);
							else if(science<treatup[treat])
							{
								wsprintf(TextBuf,TEXT("�����Դ���Ҳ��㣬���������Ŀ�ѧ��%d"),treatup[treat]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);
							}
							else
							{
								wsprintf(TextBuf,TEXT("ȷ���������Ʒ��������������Ŀ�ѧ��%d"),treatup[treat]);
								if(MessageBox(NULL,TextBuf,"Level up",MB_OK)==IDOK)
								{
									science-=treatup[treat];
									treat++;
								}
							}
							break;
						}
						case '3':
						{
							if(lighting==home) MessageBox(NULL,"������編���Ѵﵽ��ǰ��ׯ�ȼ�����߼�","Error",MB_OK);
							else if(science<lightingup[lighting])
							{
								wsprintf(TextBuf,TEXT("�����Դ���Ҳ��㣬���������Ŀ�ѧ��%d"),lightingup[lighting]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);
							}
							else
							{
								wsprintf(TextBuf,TEXT("ȷ���������編�������������Ŀ�ѧ��%d"),lightingup[lighting]);
								if(MessageBox(NULL,TextBuf,"Level up",MB_OK)==IDOK)
								{
									science-=lightingup[lighting];
									lighting++;
								}
							}
							break;
						}										
						default :
						{
							cout<<"������Ч������������\n";
							Sleep(100);							
							break;							
						}
					}
					if(qexit)
					{
						qexit=0;
						break;
					}
				}
				break;
			}
			case '5':
			{
				while(1)
				{
					menu(5);
					cin>>c;
					switch(c)
					{
						case '0':
						{
							qexit=1;
							break;
						}
						case '1':
						{
							if(armyf) MessageBox(NULL,"����������","Error",MB_OK);
							else if(food<armycost[army])
							{
								wsprintf(TextBuf,TEXT("�����Դ���Ҳ��㣬ѵ��������ʳ%d"),armycost[army]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);					
							}
							else
							{
								wsprintf(TextBuf,TEXT("ȷ��ѵ��������ѵ��������ʳ%d"),armycost[army]);
								if(MessageBox(NULL,TextBuf,"Practice",MB_OKCANCEL)==IDOK)
								{
									food-=armycost[army];
									armyf=1;
								}
							}
							break;
						}
						default :
						{
							cout<<"������Ч������������\n";
							Sleep(100);							
							break;							
						}
					}
					if(qexit)
					{
						qexit=0;
						break;
					}
				}
				break;
			}
			case '6':
			{
				while(1)
				{
					menu(6);
					cin>>c;
					switch(c)
					{
						case '0':
						{
							qexit=1;
							break;
						}
						case '1':
						{
							if(spells[0]>=maxspells[home]) MessageBox(NULL,"����������","Error",MB_OK);
							else if(science<treatcost[treat])
							{
								wsprintf(TextBuf,TEXT("�����Դ���Ҳ��㣬�������Ŀ�ѧ��%d"),treatcost[treat]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);					
							}
							else
							{
								wsprintf(TextBuf,TEXT("ȷ���������Ʒ������������Ŀ�ѧ��%d"),treatcost[treat]);
								if(MessageBox(NULL,TextBuf,"Practice",MB_OKCANCEL)==IDOK)
								{
									science-=treatcost[treat];
									treats++;
									spells[0]++;
									spells[spells[0]]=1;
								}
							}
							break;
						}
						case '2':
						{
							if(spells[0]>=maxspells[home]) MessageBox(NULL,"����������","Error",MB_OK);
							else if(science<lightingcost[lighting])
							{
								wsprintf(TextBuf,TEXT("�����Դ���Ҳ��㣬�������Ŀ�ѧ��%d"),lightingcost[lighting]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);					
							}
							else
							{
								wsprintf(TextBuf,TEXT("ȷ���������編�����������Ŀ�ѧ��%d"),lightingcost[lighting]);
								if(MessageBox(NULL,TextBuf,"Practice",MB_OKCANCEL)==IDOK)
								{
									science-=lightingcost[lighting];
									lightings++;
									spells[0]++;
									spells[spells[0]]=2;
								}
							}
							break;
						}						
						default :
						{
							cout<<"������Ч������������\n";
							Sleep(100);							
							break;							
						}
					}
					if(qexit)
					{
						qexit=0;
						break;
					}
				}
				break;
			}				
			case '7':
			{
				fight();
				break;
			}
			case '8':
			{
				shop();
				break;
			}						
			case 'n':
			{
				day++;
				food+=fields*100-houses*50+farmers*75;
				food=min(food,maxfood[home]);
				wood+=woods*100+workers*25;
				wood=min(wood,maxwood[home]);
				science+=75*scientists;
				science=min(science,maxscience[home]);			
				break;
			}
			case 's':
			{
				cout<<"saving...\n";
				save();
				break;
			}
			case 'h':
			{
				help();
				break;
			}			
			case 'e':
			{
				cout<<"saving...\n";
				save();
				cout<<"exit\n";
				return;
			}
			case 'c':
			{
				Connect();
				inter();
				break;
			}			
			default :
			{
				cout<<"������Ч������������\n";
				Sleep(100);
				break;
			}
		}
		save();
	}
}
int main()
{
	init();
	if(qexit)
	{
		MessageBox(NULL,"�������ݹ��ϣ������˳���Ϸ","Exit",MB_OK);
		return 0;
	}
	play();
	return 0;
}
