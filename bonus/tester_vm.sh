#!/bin/bash
##
## EPITECH PROJECT, 2022
## corewar
## File description:
## tester_vm.sh
##

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
BOLD='\033[1m'

for fich in `ls ../champions_cor/$fich`
do
    ../corewar/corewar -dump 1000 ../champions_cor/$fich ../champions_cor/$fich > ../champions_cor/$fich.1.txt
    if cmp -s ../champions_cor/$fich.1.txt ../champions_cor/$fich.2.txt
    then
        echo -e "$fich : ${GREEN}${BOLD}SUCCESS${NC}"
    else
        echo -e "$fich : ${RED}${BOLD}FAILURE${NC}"
        diff ../champions_cor/$fich.1.txt ../champions_cor/$fich.2.txt
    fi
    rm ../champions_cor/$fich.1.txt
done
