/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** execute_loop
*/

#include "corewar.h"

void cycle_gestion(vm_t *vm)
{
    if (vm->nbr_cycle >= vm->cycle_to_die) {
        check_alive(vm);
        vm->nbr_cycle = 0;
    }
    if (vm->nbr_live >= NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->nbr_live -= NBR_LIVE;
        if (vm->nbr_cycle >= vm->cycle_to_die) {
            check_alive(vm);
            vm->nbr_cycle = 0;
        }
    }
    vm->nbr_cycle++;
}

int check_champ_pc(vm_t *vm, champion_t *champ)
{
    if (champ->is_dead)
        return 0;
    champ->pc = my_modulo(champ->pc, MEM_SIZE);
    if ((vm->arena[champ->pc] - 1) > 15 || (vm->arena[champ->pc] - 1) < 0) {
        champ->pc += 1;
        return 0;
    }
    return 1;
}

void champ_gestion(vm_t *vm)
{
    champion_t *champ;
    op_t op;

    for (list_t *tmp = vm->champ_list; tmp; tmp = tmp->next) {
        champ = tmp->data;
        if (!check_champ_pc(vm, champ))
            continue;
        op = op_tab[vm->arena[champ->pc] - 1];
        if (!champ->is_loading) {
            champ->is_loading = true;
            champ->load_cycle = vm->cycles + op.nbr_cycles - 1;
        }
        if (champ->is_loading && champ->load_cycle == vm->cycles) {
            vm->exec_func[op.code - 1].exec_instr(vm, champ);
            champ->is_loading = false;
        }
    }
}

void print_winner(vm_t *vm)
{
    if (vm->winner != NULL) {
        my_putstr("Le joueur ");
        my_put_nbr(vm->winner->prog_number);
        my_putstr(" (");
        my_putstr(vm->winner->header->prog_name);
        my_putstr(") a gagné.\n");
        vm->winner_champ = vm->winner->prog_number;
    }
}

int main_loop(vm_t *vm, int cycle_to_stop)
{
    while (verif_whos_alive(vm) && vm->cycle_to_die > 0) {
        if (vm->cycles == cycle_to_stop)
            return 0;
        cycle_gestion(vm);
        champ_gestion(vm);
        vm->cycles++;
    }
    print_winner(vm);
    return 0;
}
