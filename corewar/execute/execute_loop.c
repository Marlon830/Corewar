/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** execute_loop
*/

#include "corewar.h"

void cycle_gestion(vm_t *vm)
{
    if (nb_of_live(vm) >= NBR_LIVE) {
        vm->cycle_to_die -= CYCLE_DELTA;
        vm->nbr_cycle = 0;
    }
    if (vm->nbr_cycle == vm->cycle_to_die) {
        check_alive(vm);
        vm->nbr_cycle = 0;
    }
    vm->nbr_cycle++;
}

void champ_gestion(vm_t *vm)
{
    champion_t *champ;
    op_t op;

    for (list_t *tmp = vm->champ_list; tmp; tmp = tmp->next) {
        champ = tmp->data;
        op = op_tab[vm->arena[champ->pc] - 1];
        if (champ->is_loading && champ->load_cycle == vm->cycles) {
            vm->exec_func[op.code - 1].exec_instr(vm, champ);
        }
        if (!champ->is_loading) {
            champ->is_loading = true;
            champ->load_cycle = vm->cycles + op.nbr_cycles;
        }
    }
}

int main_loop(vm_t *vm)
{
    while (verif_whos_alive(vm)) {
        if (vm->cycles == vm->nbr_cycle_to_print) {
            display_arena(vm);
            cycle_gestion(vm);
            champ_gestion(vm);
            vm->cycles++;
            break;
        }
        cycle_gestion(vm);
        champ_gestion(vm);
        vm->cycles++;
    }
    return 0;
}
