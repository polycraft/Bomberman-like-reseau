#include "testSocket.h"
#include "../NetworkEngine/Socket.h"
#include "../NetworkEngine/IObserverSocketAccept.h"
#include "../NetworkEngine/IObserverSocketRecv.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace Engine;
using namespace std;

class Serveur : public IObserverSocketAccept,public IObserverSocketRecv
{
private :
    vector<Socket*> clients;
    vector<Thread*> threads;
    map<Socket*,bool> stop;
    Thread* thread;
    Socket socket;
    bool stopLoc;

public:
    void updateAccept(Socket* s)
    {
        clients.push_back(s);
        s->addObserverRecv(this);

        stop[s]=false;
        threads.push_back(s->run(&(stop[s])));
    }

    void updateRecv(Socket *sock,Paquet &paquet)
    {
        string s(paquet.getData(),paquet.getSize());

        cout << "serveur reçu :" << s << endl;

        if(s=="quit")
        {
            for(vector<Socket*>::iterator it = clients.begin(); it!=clients.end(); ++it)
            {
cout << *it << sock << endl;
                if(*it==sock)
                {
                    stop[*it]=true;
                    (*it)->removeObserverRecv(this);
                    //delete *it;
                    clients.erase(it);
                    cout << "yaya" << endl;
                    break;
                }
            }
        }

        for(vector<Socket*>::iterator it = clients.begin(); it!=clients.end(); ++it)
        {
            if(*it!=sock and *it!=NULL)
            {
                cout << "send" << endl;
                (*it)->sendData(paquet);
            }
        }
    }

    Serveur():socket(5000,TP_TCP)
    {
        socket.addObserverAccept(this);
        stopLoc=false;
        thread=socket.run(&stopLoc);
    }

    ~Serveur()
    {
        stopLoc=true;
        socket.removeObserverAccept(this);
    }
};

class Client : public IObserverSocketRecv
{
public:
    Client(const char *s):socket("127.0.0.1",5000,TP_TCP),nom(s)
    {
        this->stop=false;
        socket.addObserverRecv(this);
        thread=socket.run(&stop);
    }

    void updateRecv(Socket *sock,Paquet &paquet)
    {
        string s(paquet.getData(),paquet.getSize());
        cout << nom << " reçoit " << s<< endl;

        if(s=="quit")
        {
            socket.removeObserverRecv(this);
        }
    }

    int ecrire()
    {
        string s;

        cout << nom << " ecrit :";

        cin >> s;
        socket.sendData(s);
        if(s=="quit")
        {
            stop=true;
            socket.removeObserverRecv(this);
            return 0;
        }
        return 1;
    }

    ~Client()
    {

    }

private:
    string nom;
    bool stop;
    Socket socket;
    Thread *thread;
};

void testSocket()
{
    Serveur *serveur=new Serveur();

    vector<Client*> client;

    client.push_back(new Client("roger"));
    client.push_back(new Client("Ginette"));
    /*client.push_back(new Client("Bernard"));
    client.push_back(new Client("Micouille"));
    client.push_back(new Client("Andre"));*/
    //client[2]=new Client("Bernadette",&stop);
    //client[3]=new Client("Michouille",&stop);
    //client[4]=new Client("André",&stop);

    while(client.size()!=0)
    {
        for(vector<Client*>::iterator it = client.begin(); it!=client.end(); ++it)
        {
            if((*it)->ecrire()==0)
            {
                Client *tmp=*it;
                client.erase(it);
                delete tmp;
                break;
            }
        }

    }

    delete serveur;

}
