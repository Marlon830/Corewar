/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init_arena
*/

#include "init.h"
#include "server.h"

void init_exec_func(vm_t *vm)
{
    vm->exec_func = malloc(sizeof(function_t) * 17);
    vm->exec_func[0].exec_instr = &exec_live;
    vm->exec_func[1].exec_instr = &exec_ld;
    vm->exec_func[2].exec_instr = &exec_st;
    vm->exec_func[3].exec_instr = &exec_add;
    vm->exec_func[4].exec_instr = &exec_sub;
    vm->exec_func[5].exec_instr = &exec_and;
    vm->exec_func[6].exec_instr = &exec_or;
    vm->exec_func[7].exec_instr = &exec_xor;
    vm->exec_func[8].exec_instr = &exec_zjmp;
    vm->exec_func[9].exec_instr = &exec_ldi;
    vm->exec_func[10].exec_instr = &exec_sti;
    vm->exec_func[11].exec_instr = &exec_fork;
    vm->exec_func[12].exec_instr = &exec_lld;
    vm->exec_func[13].exec_instr = &exec_lldi;
    vm->exec_func[14].exec_instr = &exec_lfork;
    vm->exec_func[15].exec_instr = &exec_aff;
    vm->exec_func[16].exec_instr = NULL;
}

void init_register(vm_t *vm)
{
    vm->r = malloc(sizeof(char) * 16);
    for (int i = 0; i != 16; i++)
        vm->r[i] = 0;
}

int init_arena(vm_t *vm)
{
    list_t *temp = vm->champ_list;
    champion_t *champ = NULL;
    int k = 0;

    vm->cycles = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    init_register(vm);
    vm->arena = malloc(sizeof(char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        vm->arena[i] = 0;
    for (; temp != NULL; temp = temp->next, k++) {
        champ = (champion_t *)temp->data;
        if (my_strcory(vm->arena, champ, vm, k) == 84)
            return 84;
    }
    init_exec_func(vm);
    vm->winner = NULL;
    return 0;
}
