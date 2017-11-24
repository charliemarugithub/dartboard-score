/****************************************
Program: Dart Game Score
Author: Md. Mujtaba Asif
Date: 1/27/2017
Update: Game selection, choice input, game check
Updated on: 11/24/2017
***************************************/

#include<bits/stdc++.h>
#include<windows.h>
#include<fstream>
using namespace std;
class game
{
private:
    int TotalScore,redScore,yellowScore,turn,a,b,c,i,p,q;
    string red,yellow;
    char x[5];
public:
    game()
    {
        char o;
        cout<<"DART GAME"<<endl<<"Created by Mujtaba Asif"<<endl<<"Date: 1/27/2017"<<endl;
        cout<<endl;
        cout<<"Choose game\nPress 1 for 301\nPress 2 for 501\nPress 3 for 1001\nPress 4 for custom\nYour choice: ";
        cin>>o;
        if(o=='1')
        {
            TotalScore=301;
        }
        else if(o=='2')
        {
            TotalScore=501;
        }
        else if(o=='3')
        {
            TotalScore=1001;
        }
        else if(o=='4')
        {
            cout<<"Enter custom initial score: ";
            cin>>TotalScore;
        }
        else
        {
            game();
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
        cout<<"PLAYING: "<<TotalScore<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        redScore=yellowScore=0;//TotalScore;
        gamePlayer();
        gamePlay();
    }
    void gamePlayer()
    {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
        cout<<"Red dart player last name: ";
        cin>>red;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
        cout<<"Yellow dart player last name: ";
        cin>>yellow;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
    }
    int checkScore()
    {
        if(TotalScore-redScore==0|| TotalScore-yellowScore==0) return 1;
        return 0;
    }
    void winner()
    {
        int x;
        cout<<endl;
        if(!turn)
        {
            //system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
            cout<<red<<" is the WINNER"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
            fstream fs;
            fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);

            fs <<red<<endl;

            fs.close();
        }
        else
        {
            //system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
            cout<<yellow<<" is the WINNER"<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
            fstream fs;
            fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);

            fs <<yellow<<endl;

            fs.close();
        }
        cout<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0D);
        cout<<"PRESS 1 TO PLAY AGAIN: ";
        cin>>x;
        if(x==1)
        {
            //system("cls");
            cout<<endl;
            game();
        }
        else
        {
            exit(1);
        }
    }
    void filter()
    {
        p=q=0;
        if(x[0]=='-')
        {
            if(strlen(x)==3)
            {
                p=(x[1])-48;

                q=(x[2])-48;

                if((p<0 || p>9) || (q<0 || q>9))
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
                    cout<<"Input again: ";
                    input();
                }
                else
                {
                    if(i==1) a=(-1)*(p*10+q);
                    else if(i==2) b=(-1)*(p*10+q);
                    else c=(-1)*(p*10+q);
                }
            }
            else if(strlen(x)==2)
            {
                p=(x[1]-'0');
                if(p<0 || p>9)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
                    cout<<"Input again: ";
                    input();
                }
                else
                {
                    if(i==1) a=p*(-1);
                    else if(i==2) b=p*(-1);
                    else c=p*(-1);
                }
            }
        }
        else if(strlen(x)==2)
        {
            p=x[0]-'0';
            q=x[1]-'0';
            if((p<0 || p>9) || (q<0 || q>9))
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
                cout<<"Input again: ";
                input();
            }
            else
            {
                if(i==1) a=p*10+q;
                else if(i==2) b=p*10+q;
                else c=p*10+q;
            }
        }
        else if(strlen(x)==1)
        {
            p=x[0]-'0';
            if(p<0 || p>9)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
                cout<<"Input again: ";
                input();
            }
            else
            {
                if(i==1) a=p;
                else if(i==2) b=p;
                else c=p;
            }

        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
            cout<<"Input again: ";
            input();
        }
    }
    void input()
    {
        cin>>x;
        filter();
    }
    void gamePlay()
    {
        while(1)
        {
            if(!checkScore())
            {
                if(turn) //1=red && 0=yellow
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
                    cout<<endl;
                    cout<<"Turn "<<red<<endl;
                    /*cout<<"1st dart point: ";
                    //cin>>a; //1st dart;
                    cout<<"2nd dart point: ";
                    //cin>>b; //2nd dart;
                    cout<<"3rd dart point: ";
                    //cin>>c; //3rd dart
                    */
                    for(i=1;i<=3;i++)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
                        if(i==1)
                        {
                            cout<<"1st dart point: ";
                            input();
                            if(TotalScore-redScore-a<=0)
                            {
                                b=c=0;
                                break;
                            }
                        }
                        else if(i==2)
                        {
                            cout<<"2nd dart point: ";
                            input();
                            if(TotalScore-redScore-a-b<=0)
                            {
                                c=0;
                                break;
                            }
                        }
                        else
                        {
                            cout<<"3rd dart point: ";
                            input();
                        }
                    }
                    redScore=redScore+a+b+c;
                    if(TotalScore-redScore<0)
                    {
                        redScore=redScore-a-b-c;
                    }
                    cout<<"Total: "<<a+b+c<<"\t Remaining: ";
                    //redScore=TotalScore-redScore;
                    cout<<TotalScore-redScore<<endl;
                    turn=0;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
                    cout<<endl;
                    cout<<"Turn "<<yellow<<endl;
                    for(i=1;i<=3;i++)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
                        if(i==1)
                        {
                            cout<<"1st dart point: ";
                            input();
                            if(TotalScore-yellowScore-a<=0)
                            {
                                b=c=0;
                                break;
                            }
                        }
                        else if(i==2)
                        {
                            cout<<"2nd dart point: ";
                            input();
                            if(TotalScore-yellowScore-a-b<=0)
                            {
                                c=0;
                                break;
                            }
                        }
                        else
                        {
                            cout<<"3rd dart point: ";
                            input();
                        }
                        //input();
                    }
                    /*cout<<"1st dart point: ";
                    cin>>a; //1st dart;
                    cout<<"2nd dart point: ";
                    cin>>b; //2nd dart;
                    cout<<"3rd dart point: ";
                    cin>>c; //3rd dart */
                    yellowScore=yellowScore+a+b+c;
                     if(TotalScore-yellowScore<0)
                    {
                        yellowScore=yellowScore-a-b-c;
                    }
                    cout<<"Total: "<<a+b+c<<"\t Remaining: ";
                    //yellowScore=TotalScore-yellowScore;
                    cout<<TotalScore-yellowScore<<endl;
                    turn=1;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
                }
            }
            else
            {
                break;
            }
        }
        winner();
    }
};
int main()
{
    game();
    return 0;
}
