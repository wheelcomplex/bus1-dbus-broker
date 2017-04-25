#pragma once

/*
 * DBus Driver
 */

#include <stdlib.h>

typedef struct Message Message;
typedef struct Peer Peer;

enum {
        _DRIVER_E_SUCCESS,

        DRIVER_E_PEER_ALREADY_REGISTERED,
        DRIVER_E_PEER_NOT_REGISTERED,

        DRIVER_E_UNEXPECTED_MESSAGE_TYPE,
        DRIVER_E_UNEXPECTED_PATH,
        DRIVER_E_UNEXPECTED_INTERFACE,
        DRIVER_E_UNEXPECTED_METHOD,
        DRIVER_E_UNEXPECTED_SIGNATURE,

        DRIVER_E_INVALID_MESSAGE,

        DRIVER_E_PEER_NOT_FOUND,

        DRIVER_E_NAME_RESERVED,
        DRIVER_E_NAME_NOT_FOUND,
        DRIVER_E_NAME_OWNER_NOT_FOUND,

        DRIVER_E_ADT_NOT_SUPPORTED,
        DRIVER_E_SELINUX_NOT_SUPPORTED,
};

int driver_dispatch_interface(Peer *peer,
                              uint32_t serial,
                              const char *interface,
                              const char *member,
                              const char *path,
                              const char *signature,
                              Message *message);
int driver_goodbye(Peer *peer, bool silent);
