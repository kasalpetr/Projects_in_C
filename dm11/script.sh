#bin/bash
for $FILE in CZE/*_in.txt; do diff ./a.out < $FILE | diff ${FILE/in/out}; done