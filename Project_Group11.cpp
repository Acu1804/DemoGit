#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>

using namespace std;

void ghifilename();
void docfilename();
void hienthithongtin();
void nhapthongtin();

void readacc();
void login();
void createacc();
void returnmain();
void editinfo();

void nhapact();
void ghifileact();
void docfileact();

void chinhsuatkb();
void ghifiletkb();
void docfiletkb();

void nhapcothe();
void ghifilebody();
void docfilebody();

struct tkb{
    int time;
    int sl;
    int ngay[8];
    int chay;
};

struct tapluyen{
    float sumcalo;
};

struct thongtin{
    char ten[100];
    int tuoi;
    char sex[10];
};

struct cothe{
    float cc;
    float cn;
};

// CHI SO CO THE
void nhapcothe(cothe &man){
    system("cls");
    cout<<"Enter height(m):";
    cin>>man.cc;
    cout<<"Enter weight(kg):";
    cin>>man.cn;
}

void ghifilebody(cothe man, char filebody[]){
    FILE* f;
    f=fopen(filebody, "w");
    fprintf(f,"%f\t%f", man.cc, man.cn);
    fclose(f);
}

void docfilebody(cothe man, char filebody[]){
    FILE*f;
    f=fopen(filebody, "rb");
    if(f==NULL){
        cout<<"file does not exist!"<<endl;
        exit(0);
    }
    fscanf(f, "%f", &man.cc);
    fscanf(f, "%f", &man.cn);
    cout<<"your height: "<<man.cc<<"m     "<<setw(10)<<"your weight: "<<man.cn<<"kg"<<endl;
}

//LAM VIEC VOI THOI KHOA BIEU
void chinhsuatkb(tkb &tuan){
    system("cls");
    cout<<"Enter the number of months:"<<endl;
    cin>>tuan.time;
    cout<<"Enter the number of days of the week:"<<endl;
    cin>>tuan.sl;
    cout<<"Select the dates you're interested in(2to7):"<<endl;
    for(int i=0;i<tuan.sl;i++){
        cin>>tuan.ngay[i];
    }
}

void ghifiletkb(tkb tuan, char filetime[]){
    FILE*f;
    f=fopen(filetime, "w");
    fprintf(f,"%d\n%d\n",tuan.time,tuan.sl);
    for(int i=0;i<tuan.sl;i++){
        fprintf(f,"%d\t", tuan.ngay[i]);
    }
    fclose(f);
}

void docfiletkb(tkb tuan, char filetime[]){
    FILE* fp;
    int arr[7];
    fp=fopen(filetime, "rb");
    if(fp==NULL){
        cout<<"file does not exist!"<<endl;
        exit(0);
    }
    cout<<"_________________________________________________________"<<endl;
    fscanf(fp,"%d", &tuan.time);
    fscanf(fp, "%d", &tuan.sl);
    if(tuan.time==1){
        cout<<"Your workout lasts 1 month"<<endl;
    }
    else{
        cout<<"Your workout lasts "<<tuan.time<<" months"<<endl;
    }
    cout<<"Your bill: "<<tuan.time*tuan.sl*100000<<" (dong)"<<endl;
    cout<<"Your workout schedule:";
    for(int i=0;i<tuan.sl;i++){
        fscanf(fp, "%d", &arr[i]);
    }
    for(int i=0;i<tuan.sl;i++){
        switch(arr[i]){
            case 2: cout<<"-Monday";
                    break;
            case 3: cout<<"-Tuesday";
                    break;
            case 4: cout<<"-Wednesday";
                    break;    
            case 5: cout<<"-Thursday";
                    break; 
            case 6: cout<<"-Friday";
                    break;
            case 7: cout<<"-Saturday|";
                    break;
        }
    }
    cout<<endl;
    fclose(fp);
}

//làm việc thông tin tập luyện của người sử dụng
void nhapact(tapluyen &hard){
    system("cls");
    int n;
    int time;
    float calo;
    do{
        cout<<"________________________________________"<<endl;
        cout<<"exercises:           "<<endl;
        cout<<"1:Lunge(1set:30rep)"<<endl;
        cout<<"2:Side lunge(1set:15rep)"<<endl;
        cout<<"3:Push up(1set:25rep)"<<endl;
        cout<<"4:Muscle up(1set:15rep)"<<endl;
        cout<<"5:Pull up(1set:20rep)"<<endl;
        cout<<"6:Plank(1set:5m)"<<endl;
        cout<<"7:Sit-ups(1set:20rep)"<<endl;
        cout<<"8:Curl (Crunch)"<<endl;
        cout<<"9:Reverse curl"<<endl;
        cout<<"10:Squat(1set:25rep) "<<endl;
        cout<<"_________________________________________"<<endl;
        do{
            cout<<"Enter your exercise:"<<endl;
            cin>>n;
        }while(n<1||n>11);
        switch(n){
            case 1: system("cls");
                    cout<<"start Lunge:";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
            case 2: system("cls");
                    cout<<"start Side lunge:";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
            case 3: system("cls");
                    cout<<"start Push up:";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
            case 4: system("cls");
                    cout<<"start Muscle up:";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
            case 5: system("cls");
                    cout<<"start Pull up:";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
            case 6: system("cls");
                    cout<<"start Plank:";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
            case 7: system("cls");
                    cout<<"start Sit-ups:";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
            case 8: system("cls");
                    cout<<"Curl (Crunch):";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
            case 9: system("cls");
                    cout<<"start Reverse curl:";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
            case 10:system("cls");
                    cout<<"start Squat:";
                    cin>>time;
                    cout<<"calories burned:"<<time*10<<"(cal)"<<endl;
                    calo+=time*10;
                    break;
        }
    }while(n>=1 && n<=10);
    hard.sumcalo=calo;
}

void ghifileact(tapluyen hard, char fileact[]){
    FILE*f;
    f=fopen(fileact,"w");
    fprintf(f, "%f", hard.sumcalo);
    fclose(f);
}

void docfileact(tapluyen hard, char fileact[]){
    FILE*q;
    q=fopen(fileact, "r");
    if(q==NULL){
        cout<<"file does not exist!"<<endl;
        exit(0);
    }
    fscanf(q, "%f", &hard.sumcalo);
    cout<<"_________________________________________________________"<<endl;
    cout<<"your workout stats:"<<endl;
    cout<<"Most recent calories burned:"<<hard.sumcalo<<"(cal)"<<endl;
    fclose(q);
}

//hàm gọi hàm
void returnmain(int n){
    cout<<"Press any number to continue:";
    cin>>n;
    system("cls");
}

//làm việc với thông tin cá nhân của người tập
void ghifilename(thongtin a,char filename[]){
    FILE* fp;
    fp=fopen(filename,"w");
    fprintf(fp, "%s\n%d\n%s", a.ten, a.tuoi,a.sex);
    fclose(fp);
}

void docfilename(thongtin a, char filename[]){
    FILE* fp;
    fp=fopen(filename, "rb");
    if(fp==NULL){
        cout<<"file does not exist!"<<endl;
        exit(0);
    }
    fgets(a.ten,100,fp);
    fscanf(fp, "%d", &a.tuoi);
    fscanf(fp,"%s", a.sex);
    cout<<"Your Info:"<<endl;
    cout<<"_________________________________________________________"<<endl;
    cout<<"full name: "<<a.ten<<setw(10)<<"\nAge: "<<a.tuoi<<setw(10)<<"sex: "<<a.sex<<endl;
    fclose(fp);
}

//TAO TAI KHOAN DANG NHAP
void createacc(char ACC[], char PASS[], char fileacc[]){
    system("cls");
    FILE*p;
    p=fopen(fileacc, "w");
    cout<<"Create Account:"<<endl;
    cout<<"__________________________________________________________"<<endl;
    cin.ignore();
    cout<<"Enter your new username(8 char):";
    cin.getline(ACC, 100);
    cout<<"Enter your new password(8 char):";
    cin.getline(PASS, 100);
    fprintf(p, "%s\n%s", ACC, PASS);
    fclose(p);
}

void readacc(char ACC[], char PASS[], char fileacc[]){
    FILE*p;
    p=fopen(fileacc, "r");
    if(p==NULL){
        cout<<"file does not exist!"<<endl;
        exit(0);
    }
    fscanf(p, "%s", ACC);
    fscanf(p, "%s", PASS);
    fclose(p);
}

void nhapthongtin(thongtin &a){
    system("cls");
    cout<<"Enter your info:"<<endl;
    cout<<"________________________________________________________"<<endl;
    cout<<"\nEnter your name(<=20 chars):";
    cin.getline(a.ten, 20);
    cout<<"\nEnter your age:";
    cin>>a.tuoi;
    cout<<"\nEnter gender:";
    cin>>a.sex;
}

//HAM DANG NHAP TAI KHOAN
void login(char acc[], char pass[],char ACC[], char PASS[], int test=0){
    system("cls");
    do{
        cout<<"Log in your Account:"<<endl;
        cout<<"_____________________________________________________"<<endl;
        test++;
        cout<<"Enter your username:"<<endl;
        cin.getline(acc, 100);
        cout<<"Enter your password:"<<endl;
        cin.getline(pass, 100);
        if(strcmp(acc, ACC)==0 && strcmp(pass, PASS)==0){
            break;
        }
        else if(test==3){
            cout<<"Log in failed!! Press any key to exit"<<endl;
            cin.ignore();
            exit(0);
        }
        else{
            cout<<"login warning!!"<<" You have "<<3-test<<" login attempts left!"<<endl;
            cout<<"Press any key to continue!"<<endl;
            cin.ignore();
            system("cls");
        }
    }while(test<3);
}

// CẦN ĐƯỢC CHỈNH SỬA LƠN
void kiemtraketqua(tapluyen hard){
    cout<<"Calories burned:"<<hard.sumcalo<<endl;
    if(hard.sumcalo>1000 && hard.sumcalo<10000){
        cout<<"Well Done"<<endl;
    }
    else if(hard.sumcalo>10000){
        cout<<"Super Ai do````"<<endl;
    }
    else cout<<"Oh!You need to try harder"<<endl;
}

void editinfo(cothe man, char filebody[], int m, thongtin &a, char filename[], int n, tapluyen &hard, char fileact[], tkb &tuan, char filetime[]){
    cout<<endl;
    do{
        cout<<"1.editinfo   2.doingex   3.edittime   4.checkworkoutstats   5.showall   6.exit"<<endl;
        do{
            cout<<"enter your option:";
            cin>>m;
        }while(m<1||m>6);
        switch(m){
            case 1:
                system("cls");
                docfilename(a, filename);
                docfilebody(man, filebody);
                int x;
                cout<<"Enter your option: 1.change info(m,a,s)   2.change body index"<<endl;
                cin>>x;
                if(x==1){
                    cin.ignore();
                    nhapthongtin(a);
                    ghifilename(a, filename);
                }
                else if(x==2){
                    nhapcothe(man);
                    ghifilebody(man, filebody);
                }
                break;
            case 2:
                system("cls");
                cin.ignore();
                docfileact(hard, fileact);
                cout<<"press any key to enter your new workout stats!"<<endl;
                cin.ignore();
                nhapact(hard);
                ghifileact(hard, fileact);
                break;
            case 3:
                system("cls");
                cin.ignore();
                docfiletkb(tuan, filetime);
                cout<<"press any key to change your workout schedule!"<<endl;
                cin.ignore();
                chinhsuatkb(tuan);
                ghifiletkb(tuan, filetime);
                break;
            case 4:
                kiemtraketqua(hard);
                break;
            case 5:
                system("cls");
                cout<<"1.show name and age"<<endl;
                cout<<"2.show body index"<<endl;
                cout<<"3.show workout schedule"<<endl;
                cout<<"4.show workout results"<<endl;
                cout<<"5.show all"<<endl;
                int y;
                cout<<"Enter your option:";
                cin>>y;
                if(y==1){
                    system("cls");
                    docfilename(a, filename);
                }
                else if(y==2){
                    system("cls");
                    docfilebody(man, filebody);
                }
                else if(y==3){
                    system("cls");
                    docfiletkb(tuan, filetime);
                }
                else if(y==4){
                    system("cls");
                    docfileact(hard, fileact);
                }
                else if(y==5){
                    system("cls");
                    docfilename(a, filename);
                    docfilebody(man, filebody);
                    docfiletkb(tuan, filetime);
                    docfileact(hard, fileact);
                }
                break;
            case 6:
                returnmain(n);
                break;
        }
    }while(m!=6);
}

int main(){
    
    thongtin a;
    tapluyen hard;
    tkb tuan;
    cothe man;
    int test=0;
    int n, m;
    char acc[100], pass[100], ACC[100], PASS[100];
    char filename[]="info_document.txt";
    char fileacc[]="acc_document.txt";
    char fileact[]="act_document.txt";
    char filetime[]="time_document.txt";
    char filebody[]="body_document.txt";

    do{
        cout<<"HE THONG QUAN LY LICH TAP CA NHANH"<<endl;
        cout<<"**********************************"<<endl;
        cout<<"____________1.|log in|.___________"<<endl;
        cout<<"____________2.|create|.___________"<<endl;
        cout<<"____________3.| exit |.___________"<<endl;
        cout<<"Enter your option:"<<endl;
        cin>>n;
        switch(n){
            case 1:
                readacc(ACC, PASS, fileacc);
                cin.ignore();
                login(acc, pass, ACC, PASS,test);
                system("cls");
                docfilename(a, filename);
                docfilebody(man, filebody);
                docfiletkb(tuan, filetime);
                editinfo(man, filebody, m, a, filename, n, hard, fileact, tuan, filetime);
                break;
            case 2:
                createacc(ACC, PASS, fileacc);
                nhapthongtin(a);
                ghifilename(a, filename);
                nhapcothe(man);
                ghifilebody(man, filebody);
                chinhsuatkb(tuan);
                ghifiletkb(tuan, filetime);
                nhapact(hard);
                ghifileact(hard, fileact);
                system("cls");
                editinfo(man, filebody, m, a, filename, n, hard, fileact, tuan, filetime);
                break;
            case 3:
                system("cls");
                exit(0);
        }
    }while(n!=3);

    return 0;
}