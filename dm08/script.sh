#/bin/bash
for FILE in CZE/*_in.txt; 
do ./a.out < $FILE | diff - ${FILE/in/out};
 done