#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#pragma comment(lib,"ws2_32.lib")
#define test MessageBox(NULL,"test","test",MB_OK);
#define qwq MessageBox(NULL,"该功能正在研发中，关注作者以获取更新！","Information",MB_ICONINFORMATION|MB_OK);
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
	cout<<"--------------------村庄建设者--------------------\n";
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
		int c=MessageBox(NULL,"数据出现故障，是否重新开始游戏？","Error",MB_ICONWARNING|MB_OKCANCEL);
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
	cout<<"第"<<day<<"天"<<endl;
	cout<<"奖章数量："<<money<<endl;
	cout<<"村庄等级："<<home<<endl;
	cout<<"粮食储量："<<food<<"/"<<maxfood[home]<<endl;
	cout<<"粮食总产量："<<fields*100-houses*50+farmers*75<<"/天"<<endl;
	cout<<"木材储量："<<wood<<"/"<<maxwood[home]<<endl;
	cout<<"木材总产量："<<woods*100+workers*25<<"/天"<<endl;
	cout<<"科学点数量："<<science<<"/"<<maxscience[home]<<endl;
	cout<<"科学点产量："<<scientists*75<<"/天"<<endl;	
	cout<<"小屋数量："<<houses<<"/" <<maxhouses[home]<<endl;
	cout<<endl;
	cout<<"操作：\n0.重新开始游戏\n1.升级村庄\n2.建造建筑\n3.分配工作\n4.研究\n5.军队\n6.配置法术\n7.战斗\n8.商店\n";
	cout<<"操作：\nn：下一天\ns：保存\ne：保存并退出\nh：帮助\nc：连接服务器\n";
}
void menu(int mode)
{
	system("cls");
	switch(mode)
	{
		case 2:
		{
			cout<<"农田数量："<<fields<<"/"<<maxfields[home]<<endl;
			cout<<"粮食储量："<<food<<"/"<<maxfood[home]<<endl;			
			cout<<"树林数量："<<woods<<"/"<<maxwoods[home]<<endl;
			cout<<"木材储量："<<wood<<"/"<<maxwood[home]<<endl;
			cout<<"小屋数量："<<houses<<"/" <<maxhouses[home]<<endl;
			cout<<endl;
			cout<<"操作：\n0.返回\n1.开辟农田\n2.开辟树林\n3.建造小屋\n";
			break;
		}
		case 3:
		{
			cout<<"村民数量："<<houses<<endl;
			cout<<"1.农民人数："<<farmers<<endl;
			cout<<"2.伐木工人数:"<<workers<<endl;
			cout<<"3.学者人数:"<<scientists<<endl;
			cout<<endl;
			cout<<"操作：\n0.返回\n1.重新分配工作\n";
			break;
		}
		case 4:
		{
			cout<<"研究室\n";
			cout<<"科学点数量："<<science<<"/"<<maxscience[home]<<endl;			
			cout<<"军队等级："<<army<<"/"<<home<<endl;
			cout<<"治疗法术等级："<<treat<<"/"<<home<<endl;
			cout<<"闪电法术等级："<<lighting<<"/"<<home<<endl;
			cout<<endl;
			cout<<"操作：\n0.返回\n1.升级军队\n2.升级治疗法术\n3.升级闪电法术\n"; 
			break;
		}
		case 5:
		{
			cout<<"军队等级："<<army<<endl;
			cout<<"军队生命值："<<armyHP[army]<<endl;
			cout<<"军队攻击力："<<armyACT[army]<<endl;
			cout<<"军队状态："<<(armyf?"满":"空")<<endl;
			cout<<endl;
			cout<<"操作：\n0.返回\n1.训练军队\n";
			break;
		}
		case 6:
		{
			cout<<"法术储量："<<spells[0]<<"/"<<maxspells[home]<<endl;
			cout<<"治疗法术："<<treats<<endl;
			cout<<"闪电法术："<<lightings<<endl;
			cout<<endl;
			cout<<"操作:\n0.返回\n1.配置治疗法术\n2.配置闪电法术\n";
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
		MessageBox(NULL,"请先训练军队！","Error",MB_OK);
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
			cout<<"剩余怪兽数量："<<mcnt<<endl;
			cout<<"当前怪兽HP："<<mHP[mcnt]<<endl;
			cout<<"当前怪兽攻击力："<<mACT[mcnt]<<endl;
			cout<<endl;
			cout<<"军队HP："<<HP<<endl;
			cout<<"军队战斗力："<<ACT<<endl;
			cout<<endl;
			cout<<"操作：\n0.放弃\n1.攻击\n2.使用法术\n";		
			cin>>c;
			switch(c)
			{
				case 0:
				{
					return;
				}
				case 1:
				{
					cout<<"怪兽HP-"<<ACT<<endl;
					mHP[mcnt]-=ACT;
					qexit=1;
					break;
				}
				case 2:
				{
					cout<<endl<<endl;
					cout<<"1：使用治疗法术("<<treats<<")\n";
					cout<<"2：使用闪电法术("<<lightings<<")\n";
					cout<<"其余：返回上一步\n";
					cin>>c;
					switch(c)
					{
						case 1:
						{
							if(!treats)
							{
								cout<<"该法术已用光\n";
								Sleep(250);
							}
							else
							{
								cout<<"军队HP+"<<treateff[treat]<<endl;
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
								cout<<"该法术已用光\n";
								Sleep(250);
							}
							else
							{
								cout<<"怪兽HP-"<<lightingeff[lighting]<<endl;
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
					cout<<"输入无效，请重新输入\n";
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
			cout<<"你打败了一只怪兽！\n";
			rew=rand()%(home)+1;
			cout<<"奖励奖章"<<rew<<endl;
			money+=rew;
			Sleep(800);
			mcnt--;
			if(mcnt<=0)
			{
				cout<<"战斗胜利！\n";
				rew=rand()%(home*2)+1;
				cout<<"奖励奖章"<<rew<<endl;
				money+=rew;
				Sleep(800);
				return;
			}
		}
		else
		{
			cout<<"军队HP-"<<mACT[mcnt]<<endl;
			HP-=mACT[mcnt];
			if(HP<=0)
			{
				cout<<"你被怪兽打败了！\n";
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
	cout<<"欢迎来到商店\n";
	Sleep(1000);
	char c;
	while(1)
	{
		system("cls");
		cout<<"你的奖章数量："<<money<<endl;
		cout<<"操作：\n";
		cout<<"0.返回\n";
		cout<<"1.购买粮食：100/1奖章\n";
		cout<<"2.购买木材：100/1奖章\n";
		cout<<"3.购买科学点：50/1奖章\n";
		cin>>c;
		switch(c)
		{
			case '0':return;
			case '1':
			{
				if(money<1)
				{
					MessageBox(NULL,"你的奖章不够啦！","Error",MB_OK|MB_ICONWARNING);
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
					MessageBox(NULL,"你的奖章不够啦！","Error",MB_OK|MB_ICONWARNING);
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
					MessageBox(NULL,"你的奖章不够啦！","Error",MB_OK|MB_ICONWARNING);
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
	fprintf(fi,"帮助：\n");
	fprintf(fi,"村庄建设者是一个控制台小游戏，在游戏中，玩家可以根据自己的想法来建设村庄、训练军队等。\n");
	fprintf(fi,"在游戏的主页面中，你可以根据提示来进行操作。\n");
	fprintf(fi,"你可以建造农田或树林来增加资源产量，建造小屋，分配工作来增加资源产量，通过研究升级军队、法术等。\n");
	fprintf(fi,"而升级村庄则可以解锁更多内容！\n");
	fprintf(fi,"以下是一些相关数据：\n\n");
	fprintf(fi,"升级村庄所需要的木材：\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"升至%d级村庄：%d\n",i+1,hlu[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"各级村庄储存上限：\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d级村庄：\n粮食：%d\t木材：%d\n",i,maxfood[i],maxwood[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"各级村庄建造上限：\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d级村庄：\n农田：%d\t树林：%d\t小屋：%d\n",i,maxfields[i],maxwoods[i],maxhouses[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"各级村庄法术存储上限：\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d级村庄：%d\n",i,maxspells[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"各级军队：\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d级军队：\n训练消耗：%d\tHP：%d\t攻击力：%d\n",i,armycost[i],armyHP[i],armyACT[i]);
	}
	fprintf(fi,"\n");
	fprintf(fi,"治疗法术：\n");
	fprintf(fi,"效果：恢复军队HP\n");
	fprintf(fi,"各级法术：\n");
	for(int i=1;i<=MAX_HOME_LEVEL;i++)
	{
		fprintf(fi,"%d级：\n配置消耗：%d\t恢复HP:%d\n",i,treatcost[i],treateff[i]);
	}
	fprintf(fi,"\n");
	fclose(fi);
	MessageBox(NULL,"help.txt文件已经生成，请打开以阅读帮助！","help",MB_OK);
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
	if(client == NULL ||!buf || len <1) return 0;	//发送失败
	int l =send(client,buf,len,0);
	if(l != len) return 0;	//发送的长度和指定的长度不等 失败
	return 1;
}
bool Connect()
{
	system("cls");
	cout<<"服务器连接中...";
	strSvrIp="192.168.0.103";
	//strSvrIp="127.0.0.1";
	port =111;
	//初始化WSA
	sockVersion = MAKEWORD(2,2);
	if(WSAStartup(sockVersion,&wsaData)!= 0){
		cout<<"套接字组件初始化失败:"<<GetLastError()<<endl;
		return 0;
	} 
	//创建套接字
	client = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(client == INVALID_SOCKET){
		cout<<"创建套接字失败:"<<GetLastError()<<endl;
		return 0;
	} 
	//构建服务器IP和端口结构 
	qsin.sin_family = AF_INET;
	qsin.sin_port=htons(port);
	qsin.sin_addr.S_un.S_addr=inet_addr(strSvrIp.c_str());
	//向服务器发起连接
	if(connect(client,(sockaddr*)&qsin,sizeof(qsin))==SOCKET_ERROR){
		cout<<"\n连接服务器失败:"<<GetLastError()<<endl;
		Close(client);
		Sleep(1000);
		return 0; 
	}
	system("cls");
	cout<<"连接服务器完成"<<endl;
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
		cout<<"你已连接服务器\n";
		cout<<"操作：\n";
		cout<<"0.返回\n";
		cout<<"1.向用户发送信息\n";		
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
				cout<<"输入无效，请重新输入\n";
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
				if((MessageBox(NULL,"你确定重新开始游戏吗？","New game",MB_OKCANCEL)==IDOK))
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
					wsprintf(TextBuf,TEXT("你确定升级你的村庄吗？消耗木材%d"),hlu[home],hlu[home]);
					if(MessageBox(NULL,TextBuf,"Level up",MB_OKCANCEL)==IDOK)
					{
						wood-=hlu[home];
						home++;
					}
				}
				else
				{
					wsprintf(TextBuf,TEXT("你的资源尚且不足，升级消耗木材%d"),hlu[home]);
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
									MessageBox(NULL,"你的农田数量已达上限，升级村庄解锁更多农田","Error",MB_OK);
								}
								else
								{
									if(MessageBox(NULL,"确定开辟农田吗？消耗粮食500","Build",MB_OKCANCEL)==IDOK)
									{
										food-=500;
										fields++; 
									} 
								}
							}
							else MessageBox(NULL,"你的资源尚且不足，建造消耗粮食500","Error",MB_OK);
							break;
						}
						case '2':
						{
							if(wood>=500)
							{
								if(woods>=maxwoods[home])
								{
									MessageBox(NULL,"你的树林数量已达上限，升级村庄解锁更多树林","Error",MB_OK);
								}
								else
								{
									if(MessageBox(NULL,"确定开辟树林吗？消耗木材500","Build",MB_OKCANCEL)==IDOK)
									{
										wood-=500;
										woods++; 
									} 
								}
							}
							else MessageBox(NULL,"你的资源尚且不足，建造消耗木材500","Error",MB_OK);
							break;
						}
						case '3':
						{
							if(wood>=500)
							{
								if(houses>=maxhouses[home])
								{
									MessageBox(NULL,"你的小屋数量已达上限，升级村庄解锁更多小屋","Error",MB_OK);
								}
								else
								{
									if(MessageBox(NULL,"确定建造小屋吗？消耗木材500","Build",MB_OKCANCEL)==IDOK)
									{
										wood-=500;
										houses++; 
									} 
								}
							}
							else MessageBox(NULL,"你的资源尚且不足，建造消耗木材500","Error",MB_OK);
							break;
						}											
						default :
						{
							cout<<"输入无效，请重新输入\n";
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
								cout<<"村民数量："<<houses<<endl;
								cout<<"1.农民人数："<<farmers<<endl;
								cout<<"2.伐木工人数:"<<workers<<endl;
								cout<<"3.学者人数:"<<scientists<<endl;								
								cout<<"输入对应工作的编号与该工作分配的人数\n";								
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
							cout<<"输入无效，请重新输入\n";
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
							if(army==home) MessageBox(NULL,"你的军队已达到当前村庄等级的最高级","Error",MB_OK);
							else if(science<armyup[army])
							{
								wsprintf(TextBuf,TEXT("你的资源尚且不足，升级需消耗科学点%d"),armyup[army]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);
							}
							else
							{
								wsprintf(TextBuf,TEXT("确定升级军队吗？升级需消耗科学点%d"),armyup[army]);
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
							if(treat==home) MessageBox(NULL,"你的治疗法术已达到当前村庄等级的最高级","Error",MB_OK);
							else if(science<treatup[treat])
							{
								wsprintf(TextBuf,TEXT("你的资源尚且不足，升级需消耗科学点%d"),treatup[treat]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);
							}
							else
							{
								wsprintf(TextBuf,TEXT("确定升级治疗法术吗？升级需消耗科学点%d"),treatup[treat]);
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
							if(lighting==home) MessageBox(NULL,"你的闪电法术已达到当前村庄等级的最高级","Error",MB_OK);
							else if(science<lightingup[lighting])
							{
								wsprintf(TextBuf,TEXT("你的资源尚且不足，升级需消耗科学点%d"),lightingup[lighting]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);
							}
							else
							{
								wsprintf(TextBuf,TEXT("确定升级闪电法术吗？升级需消耗科学点%d"),lightingup[lighting]);
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
							cout<<"输入无效，请重新输入\n";
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
							if(armyf) MessageBox(NULL,"军队已满！","Error",MB_OK);
							else if(food<armycost[army])
							{
								wsprintf(TextBuf,TEXT("你的资源尚且不足，训练消耗粮食%d"),armycost[army]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);					
							}
							else
							{
								wsprintf(TextBuf,TEXT("确定训练军队吗？训练消耗粮食%d"),armycost[army]);
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
							cout<<"输入无效，请重新输入\n";
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
							if(spells[0]>=maxspells[home]) MessageBox(NULL,"法术已满！","Error",MB_OK);
							else if(science<treatcost[treat])
							{
								wsprintf(TextBuf,TEXT("你的资源尚且不足，配置消耗科学点%d"),treatcost[treat]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);					
							}
							else
							{
								wsprintf(TextBuf,TEXT("确定配置治疗法术吗？配置消耗科学点%d"),treatcost[treat]);
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
							if(spells[0]>=maxspells[home]) MessageBox(NULL,"法术已满！","Error",MB_OK);
							else if(science<lightingcost[lighting])
							{
								wsprintf(TextBuf,TEXT("你的资源尚且不足，配置消耗科学点%d"),lightingcost[lighting]);
								MessageBox(NULL,TextBuf,"Error",MB_OK);					
							}
							else
							{
								wsprintf(TextBuf,TEXT("确定配置闪电法术吗？配置消耗科学点%d"),lightingcost[lighting]);
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
							cout<<"输入无效，请重新输入\n";
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
				cout<<"输入无效，请重新输入\n";
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
		MessageBox(NULL,"由于数据故障，被迫退出游戏","Exit",MB_OK);
		return 0;
	}
	play();
	return 0;
}
