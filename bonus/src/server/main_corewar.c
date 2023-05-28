/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-corewar-marlon.pegahi
** File description:
** main.c
*/

#include "corewar.h"
#include "server.h"

vm_t *init_vm(void)
{
    vm_t *vm = malloc(sizeof(vm_t));

    vm->nbr_cycle = 0;
    vm->nbr_cycle_to_print = -1;
    vm->load_address = -1;
    vm->prog_number = -1;
    vm->nb_champ = 0;
    vm->champ_list = NULL;
    vm->nbr_live = 0;
    vm->winner_champ = -1;
    return vm;
}

server_t get_arena_at_cycle(int argc, char **argv, int cycle)
{
    vm_t *vm = init_vm();
    server_t server = {0};
    champion_t *champ;
    list_t *champ_list;

    for (int i = 0; i != 4; i++)
        vm->lives[i] = -1;
    if (handling_error(argc, argv, vm)) {
        server.my_errno = -1;
        return server;
    }
    fill_champ_list(vm);
    if (init_arena(vm)) {
        write(2, "Error: init arena\n", 18);
        server.my_errno = -1;
        return server;
    }
    main_loop(vm, cycle);
    for (int i = 0; i != 6144; i++) {
        server.arena[i] = vm->arena[i];
        server.champ_bytes[i] = vm->champ_bytes[i];
    }
    server.my_errno = 0;
    champ_list = vm->champ_list;
    while (champ_list != NULL) {
        champ = champ_list->data;
        server.champ_bytes[champ->pc] = 5;
        champ_list = champ_list->next;
    }
    for (int i = 0; i < 4; i++)
        server.lives[i] = vm->lives[i];
    server.winner = -1;
    if (vm->winner_champ != -1)
        server.winner = get_nb_champ(vm->winner, vm->champ_list);
    for (int i = 0; i < 4; i++)
        strcpy(server.champ_name[i], vm->champ_name[i]);
    return server;
}
