#!/bin/bash
##
## EPITECH PROJECT, 2022
## corewar
## File description:
## tester.sh
##

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

for fich in `ls ../champions/$fich`
do
    ../asm/asm ../champions/$fich
    ../ressources/asm/asm ../champions/$fich
    fich_no_ext=$(basename "$fich" | sed 's/\.[^.]*$//')
    new_fich=$fich_no_ext.cor
    if cmp -s ../champions/$new_fich $new_fich
    then
        echo -e "$fich : ${GREEN}SUCCESS${NC}"
    else
        echo -e "$fich : ${RED}FAILURE${NC}"
    fi
done
rm ../champions/*.cor
rm *.cor
