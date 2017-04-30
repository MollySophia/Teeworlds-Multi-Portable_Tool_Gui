#include <QDialog>
#include <QFileDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>

#include "mainwindow.h"
#include "dialogdf.h"
#include "dialogset.h"
#include "dialogf2.h"

#include <QApplication>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <shlobj.h>
#include <io.h>
using namespace std;

struct user
{
    string name;
    string clan;
}users[5],duser;
int uid=-1;
string path,exepath,appdata;
bool about=false;
QListWidgetItem *ud,*u1,*u2,*u3,*u4,*u5;

int readgameconf(string path,int uid)
{
    FILE* fd=freopen(path.c_str(),"r",stdin);
    if(fd==NULL) return -1;
    string buf;
    while(1)
    {
        getline(cin,buf);
        int pos=buf.find("player_name",0);
        if(pos!=string::npos)break;
    }
    string name,clan;
    name=buf.substr(13,buf.length()-14);
    getline(cin,buf);
    clan=buf.substr(13,buf.length()-14);
    fclose(stdin);
    if(uid==-1)
    {
        duser.name=name;
        duser.clan=clan;
        duser.name+="（本机）";
    }
    else
    {
        users[uid].name=name;
        users[uid].clan=clan;
    }
    return 0;
}

int refresh()
{
    if(readgameconf(path,-1)==-1)
        return -1;
    int k=0;
    string p="config\\user0";
    int pos=p.find("0",0);
    while(/*_access(p.c_str(),0)!=-1&&*/k<5)
    {
        p+="\\Teeworlds\\settings_ddnet.cfg";
        readgameconf(p,k);
        k++;
        cout<<p<<endl;
        p="config\\user0";
        p[pos]=k+'0';
    }
    return 0;
}

void reflist()
{
    ud->setText(duser.name.c_str());
    u1->setText(users[0].name.c_str());
    u2->setText(users[1].name.c_str());
    u3->setText(users[2].name.c_str());
    u4->setText(users[3].name.c_str());
    u5->setText(users[4].name.c_str());
}

int runclient(string path, int uid)
{
    char cmd[255];
    memset(cmd,0,sizeof(cmd));
    if(exepath.find("exe",0)==string::npos)
    {
        Dialogf2 dlg;
        dlg.show();
        return dlg.exec();
    }
    if(uid==-1)
        sprintf(cmd,"run.bat \"%s\\..\\Roaming\\\" \"%s\"",appdata.c_str(),exepath.c_str());
    else
        sprintf(cmd,"run.bat \"config\\user%i\" \"%s\"",uid,exepath.c_str());

    cout<<cmd<<endl;
    system(cmd);
    refresh();
    reflist();
    return 0;
}

int createuser()
{
    int k=0;
    refresh();
    string p="config\\user0";
    int pos=p.find("0",0);
    while(_access(p.c_str(),0)!=-1&&k<5)
    {
        k++;
        p[pos]=k+'0';
    }
    if(k==5)
        return -1;
    string f="cd config && mkdir user0 && cd ..";
    pos=f.find("0",0);
    f[pos]=k+'0';
    system(f.c_str());
    runclient(exepath,k);
    return 0;
}
int deleteuser(int uid)
{
    string i="config\\user0\\";
    int pos=i.find("0",0);
    i[pos]=uid+'0';
    i.insert(0,"del /Q ");
    i+=" && pause";
    cout<<i<<endl;
    system(i.c_str());
    refresh();
    reflist();
    return 0;
}

void selectchange(int currentRow)
{
    uid=currentRow-1;
    cout<<"Selection changed:"<<uid<<endl;
}

void Wchar_tToString(std::string& szDst, wchar_t *wchar)
{
    wchar_t * wText = wchar;
    DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wText,-1,NULL,0,NULL,FALSE);// WideCharToMultiByte的运用
    char *psText;  // psText为char*的临时数组，作为赋值给std::string的中间变量
    psText = new char[dwNum];
    WideCharToMultiByte (CP_OEMCP,NULL,wText,-1,psText,dwNum,NULL,FALSE);// WideCharToMultiByte的再次运用
    szDst = psText;// std::string赋值
    delete []psText;// psText的清除
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialogdf d;
    QListWidget* list = new QListWidget(&w);
    wchar_t szPath[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, szPath);
    Wchar_tToString(path,szPath);
    appdata=path;
    path+="\\..\\Roaming\\Teeworlds\\settings_ddnet.cfg";
    if(_access("config",0)==-1)
        system("mkdir config");
    char tmp1[200];
    memset(tmp1,0,sizeof(tmp1));
    FILE* nfd=fopen("config\\exepath.txt","r+");
    fscanf(nfd,"%s",tmp1);
    exepath=tmp1;
    cout<<exepath<<endl;
    fclose(nfd);
    switch(refresh())
    {
        case -1: d.show(); break;
    }
    list->setGeometry(6,15,161,201);
    ud = new QListWidgetItem(duser.name.c_str(),list);
    u1 = new QListWidgetItem(users[0].name.c_str(),list);
    u2 = new QListWidgetItem(users[1].name.c_str(),list);
    u3 = new QListWidgetItem(users[2].name.c_str(),list);
    u4 = new QListWidgetItem(users[3].name.c_str(),list);
    u5 = new QListWidgetItem(users[4].name.c_str(),list);
    reflist();
    QObject::connect(list, &QListWidget::currentRowChanged,&selectchange);
    w.show();
    return a.exec();
}

void MainWindow::on_start_clicked()
{
    runclient(exepath,uid);
}

void Dialogset::on_toolButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this, tr("Open File"),NULL,tr("exeFile (*.* *.exe)"));
    exepath = filename.toStdString();
    FILE* f=fopen("config\\exepath.txt","w+");
    fprintf(f,exepath.c_str());
    fclose(f);
}

void MainWindow::on_brefresh_clicked()
{
    refresh();
    reflist();
}

void MainWindow::on_create_clicked()
{
    createuser();
}

void MainWindow::on_del_clicked()
{
    deleteuser(uid);
}
