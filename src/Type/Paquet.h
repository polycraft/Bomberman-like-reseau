#ifndef PAQUET2_H
#define PAQUET2_H


/**
Déclaration des différents types de paquet

Chaque type de paquet contient un caractère d'identification nommé type ainsi que l'heure de départ du paquet
**/


//Paquet concernant les bombes
typedef struct PaquetBomb
{
    char type;//b
    int timePaquet;
    int idBomber;//id du poseur de bombe
    int x;//x relatif de la bombe
    int y;//y relatif de la bombe
    int putTime;//l'heure de la pose de la bombe
    int power;//force de la bombe
    int explodeTime;//Temps avant explosion
    int vitesseExplode;//Temps entre chaque explosion de flame
} PaquetBomb;

//Paquet pour les déplacements des bombermans
typedef struct PaquetMove
{
    char type;//m
    int timePaquet;
    int idBomber;//id du bomberman déplacé
    double x;//x absolue du bomberman
    double y;//y absolue du bomberman
	double rotation;//valeur de l'angle
}PaquetMove;

//Paquet d'un nouveau bonus
typedef struct PaquetBonus
{
    char type;//u
    int timePaquet;
    int bonus;//type de bonus
    int x;//x relatif du bonus
    int y;//y relatif du bonus
}PaquetBonus;

//Paquet de synchronisation de phase
typedef struct PaquetPhase
{
    char type;//p
    int timePaquet;
    int phase;//numéro de la phase actuelle
}PaquetPhase;



//Paquet de modification d'état d'un bomberman (l'état mort par exemple)
typedef struct PaquetEtat
{
    char type;//e
    int timePaquet;
    int idBomber;//Numéro du bomberman à modifier
    int property;//etat à modifier
    bool etat;//valeur de l'état
}PaquetEtat;

//Paquet d'atribution d'id
typedef struct PaquetId
{
    char type;//i
    int timePaquet;
    int id;//id du bomberman
}PaquetId;

//Paquet de placement sur les spawn
typedef struct PaquetSpawn
{
    char type;//s
    int timePaquet;
    int idBomber;//id du bomberman à placer
    int idSpawn;//id du spawn où placer le bomberman
    char name[100];
}PaquetSpawn;

//Paquet de chargement de map
typedef struct PaquetMap
{
    char type;//c
    int timePaquet;
    char name[50];//Nom de la map
}PaquetMap;

//Paquet de ping
typedef struct PaquetPing
{
    char type;//g
    int timePaquet;
}PaquetPing;

//Paquet de demande
typedef struct PaquetAsk
{
    char type;//a
    int timePaquet;
    char paquet;//type du paquet à demander
}PaquetAsk;

//Paquet d'erreur
typedef struct PaquetError
{
    char type;//r
    int timePaquet;
    char error;//type de l'erreur
}PaquetError;

//Paquet de deconnexion
typedef struct PaquetDeconnect
{
    char type;//d
    int timePaquet;
    int idBomber;//id du Bomber qui deconnecte
}PaquetDeconnect;


//Paquet pour attribuer un nom à un bomberman
typedef struct PaquetName
{
    char type;//n
    int timePaquet;
    char name[100];
}PaquetName;

#endif // PAQUET2_H
