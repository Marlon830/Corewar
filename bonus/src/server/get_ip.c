/*
** EPITECH PROJECT, 2022
** GraphicCorewar
** File description:
** get_ip.c
*/

#include "server.h"
#include <string.h>

int get_ip_bis(struct ifreq *ifr, struct ifconf *ifc, int fd)
{
    struct ifreq *it = ifc->ifc_req;
    struct ifreq *end = it + (ifc->ifc_len / sizeof(struct ifreq));

    for (; it != end; ++it) {
        strcpy(ifr->ifr_name, it->ifr_name);
        if (!ioctl(fd, SIOCGIFFLAGS, ifr) &&
        !(ifr->ifr_flags & IFF_LOOPBACK) &&
        !strncmp(ifr->ifr_name, "wl", 2) &&
        !ioctl(fd, SIOCGIFADDR, ifr)) {
            return 1;
        }
    }
    close(fd);
    return 0;
}

char *get_ip(void)
{
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    struct ifreq ifr;
    struct ifconf ifc;
    char buffer[1024];
    int success = 0;

    ifc.ifc_len = sizeof(buffer);
    ifc.ifc_buf = buffer;
    if (ioctl(fd, SIOCGIFCONF, &ifc) != 0)
        return 0;
    success = get_ip_bis(&ifr, &ifc, fd);
    if (success)
        return inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
    return 0;
}
