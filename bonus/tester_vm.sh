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
BOLD='\033[1m'

for fich in `ls ../champions_cor/$fich`
do
    ../corewar/corewar -dump 1000 ../champions_cor/$fich ../champions_cor/$fich > $fich.1.txt
    ../ressources/corewar/corewar -dump 1000 ../champions_cor/$fich ../champions_cor/$fich > $fich.2.txt
    if cmp -s $fich.1.txt $fich.2.txt
    then
        echo -e "$fich : ${GREEN}${BOLD}SUCCESS${NC}"
    else
        echo -e "$fich : ${RED}${BOLD}FAILURE${NC}"
        diff $fich.1.txt $fich.2.txt
    fi
    rm $fich.1.txt $fich.2.txt
done
