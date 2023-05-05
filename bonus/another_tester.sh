#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
BOLD='\033[1m'

for fich in `ls ../ressources/champions/$fich`
do
    ../ressources/asm/asm ../ressources/champions/$fich
    ../asm/asm ../ressources/champions/$fich
    fich_no_ext=$(basename "$fich" | sed 's/\.[^.]*$//')
    new_fich=$fich_no_ext.cor
    if cmp -s ../ressources/champions/$new_fich $new_fich
    then
        echo -e "$fich : ${GREEN}${BOLD}SUCCESS${NC}"
    else
        echo -e "$fich : ${RED}${BOLD}FAILURE${NC}"
        hexdump -C ../ressources/champions/$new_fich > ../ressources/champions/$fich_no_ext.hex
        hexdump -C $new_fich > $fich_no_ext.hex
        diff ../ressources/champions/$fich_no_ext.hex $fich_no_ext.hex
    fi
done
rm ../ressources/champions/*.cor
rm *.cor
rm ../ressources/champions/*.hex
rm *.hex
