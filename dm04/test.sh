#!/bin/bash
# Otestuje program podle referenčních dat ze souborů *_in.txt a porovná je s referenčním výstupem *_out.txt
# Soubory musejí být uloženy ve složce "CZE"


TEST_DIR="CZE/"

for IN_FILE in ${TEST_DIR}*_in.txt
do
	REF_FILE=$(echo -n $IN_FILE | sed -e 's/_in\(.*\)$/_out\1/')

	./a < $IN_FILE > my_out.txt

	if ! diff $REF_FILE my_out.txt > temp.txt
	then
		printf "\e[0;31mFail: %s\e[0m\n" "$IN_FILE"
		cat temp.txt
		#echo "Vstupni data:"
		#echo `cat "$IN_FILE"`
		#exit
	else
		printf "\e[0;32mOK:\e[0m %s\n" $IN_FILE
	fi
done

rm my_out.txt temp.txt
