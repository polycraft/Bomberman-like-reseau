#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <vector>
#include "../util/Threadable.h"

namespace Engine
{
    class Socket;
}

#include "IObserverSocketAccept.h"
#include "IObserverSocketRecv.h"

#include "../util/windows.h"
#ifdef WINDOWS /* si vous êtes sous Windows */
	#include <windows.h>
	typedef int socklen_t;
//#include <winsock2.h>

#elif defined (linux) /* si vous êtes sous Linux */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else /* sinon vous êtes sur une plateforme non supportée */

#error not defined for this platform

#endif

#include "Paquet.h"

using namespace std;


namespace Engine
{
typedef enum
{
    TP_TCP,
    TP_UDP
} ETypeProtocole;

typedef enum
{
    TC_Server,
    TC_Client
} ETypeConnection;

/**
Gestion des sockets
**/
class Socket : public Threadable
{
    public:
        /**
        Constructeur
        Initialise le type de connexion
        **/
        Socket(const char *address,unsigned int port,ETypeProtocole protocole=TP_TCP,ETypeConnection connection=TC_Client);

        /**
        Constructeur
        Initialise un serveur
        **/
        Socket(unsigned int port,ETypeProtocole protocole);

        /**
        Destructeur
        Deconnecte le socket
        **/
        virtual ~Socket();

        /**
        Démare le thread de la socket
        **/
        void runThread(bool *close);

        virtual Socket* createSocketAccept(SOCKET sock,SOCKADDR_IN csin,ETypeConnection connection);

        /**
        Vérifie si la connexion est établit
        **/
        bool hasConnect();

        /**
        Retourne la taille du buffer de reception
        **/
        unsigned int getSizeBufferRecv();

        /**
        Modifie la taille du buffer de reception
        **/
        void setSizeBufferRecv(unsigned int val);

        /**
        Retourne la taille du buffer de reception
        **/
        unsigned int getSizeBufferSend();

        /**
        Modifie la taille du buffer de reception
        **/
        void setSizeBufferSend(unsigned int val);

        /**
        Envoie une donnéee
        **/
        void sendData(const char *data,unsigned int size);
        void sendData(string &data);
        void sendData(Paquet &paquet);
		template<class T> void sendData(T *data)
		{
				this->sendData(reinterpret_cast<char*>(data),sizeof(T));
		}

        /**
        Reçoit une chaine
        **/
        int recept();
        virtual void recvData();
        virtual Paquet recvDataSync();

        /**
        setter isSync
        **/
        void setIsSync(bool sync);

        /**
        #Gestion des observables
        **/
            /**
            Ajoute un Observateur de l'action recevoir
            **/
            void addObserverRecv(IObserverSocketRecv* observer);

            /**
            Ajoute un Observateur de l'action accept
            **/
            void addObserverAccept(IObserverSocketAccept* observer);

            /**
            Retire l'observateur
            **/
            void removeObserverRecv(IObserverSocketRecv* observer);

            /**
            Retire l'observateur
            **/
            void removeObserverAccept(IObserverSocketAccept* observer);

            /**
            Notifie tous les observateurs de l'action recevoir
            **/
            void notifyRecv(char*,int size);
            void notifyRecv(Paquet paquet);

            /**
            Notifie tous les observateurs de l'action Accept
            **/
            void notifyAccept(Socket *);

        /**
        #Fin gestion des observables
        **/

    protected:
        /**
        #Gestion des sockets
        **/
            /**
            Crée une socket à partir d'une autre socket
            **/
            Socket(SOCKET sock,SOCKADDR_IN csin,ETypeConnection connection);

            /**
            Initialise la socket
            **/
            void initSocket(const char *address,unsigned int port,ETypeProtocole protocole=TP_TCP,ETypeConnection connection=TC_Client);

            /**
            Initialise la mémoire des buffers
            **/
            void initBuffer();


            /**
            Etat de la connexion
            **/
            bool isConnect;

            /**
            Etat de la configuration
            **/
            bool isConfig;

            /**
            Identifiant de socket
            **/
            SOCKET sock;

            /**
            Buffer de reception
            **/
            char *bufferRecv;

            /**
            Buffer de d'emission
            **/
            char *bufferSend;

            /**
            Taille du buffer de reception
            **/
            unsigned int sizeBufferRecv;

            /**
            Taille du buffer d'emission
            **/
            unsigned int sizeBufferSend;

            /**
            Information avec la machine connecté
            **/
            SOCKADDR_IN infoConnection;

            /**
            Type de connexion
            **/
            ETypeConnection connection;

            /**
            Type de protocole
            **/
            ETypeProtocole protocole;

            /**
            Type de connexion (synchrone ou asynchrone)
            **/
            bool isSync;
        /**
        #Fin gestion des sockets
        **/

        pthread_mutex_t mutex1;

        /**
        #Gestion des observables
        **/
            /**
            Observeur de l'action recevoir
            **/
            vector<IObserverSocketRecv*> observerRecv;

            vector<vector<IObserverSocketRecv*>::iterator> observerRecvSupr;

            /**
            Observateur de l'action accept
            **/
            vector<IObserverSocketAccept*> observerAccept;
        /**
        #Fin gestion des observables
        **/

        #ifdef WINDOWS
            /**
            #Gestionnaire de socket windows
            **/
                /**
                Initialise le gestionnaire de socket
                **/
                static void init();

                /**
                Ferme le gestionnaire de socket
                **/
                static void end();

                /**
                Etat du gestionnaire de socket
                **/
                static bool isInit;
                /**
                Nombre de socket créé
                **/
                static unsigned int nbSocket;
            /**
            #Fin gestionnaire de socket windows
            **/
        #endif

};
}
#endif // SOCKET_H
