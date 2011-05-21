#ifndef EXCEPTION_H
#define EXCEPTION_H

/**
Inclusion de toutes les exceptions
**/

/**
Resource
**/
#include "ExceptionBadRessource.h"
#include "ExceptionNoFileFound.h"
#include "ExceptionNoLoader.h"
#include "ExceptionNoRessource.h"

/**
Network
**/
#include "ExceptionConnect.h"
#include "ExceptionInvalidSocket.h"
#include "ExceptionListen.h"
#include "ExceptionRecv.h"
#include "ExceptionSelect.h"
#include "ExceptionSend.h"
#include "ExceptionUnknowHost.h"

/**
Thread/Mutex
**/
#include "ExceptionMutex.h"

/**
Main Engine
**/
#include "ExceptionNoEngine.h"

#endif // EXCEPTION_H
