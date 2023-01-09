Úkolem je realizovat program, který bude analyzovat zadanou číselnou posloupnost.

Předpokládáme posloupnost čísel. Z této posloupnosti vybíráme souvislé intervaly, například můžeme vybrat interval mezi 5. a 10. zadaným číslem. Interval musí obsahovat nejméně dvě čísla ze vstupní posloupnosti. Pro vybraný interval určíme součet čísel, která jej tvoří. Takto ze vstupní posloupnosti vybereme všechny možné intervaly a pro každý interval určíme jeho součet. Zajímá nás, kolik dvojic navzájem různých intervalů bude mít stejný součet.

Například pro vstupní posloupnost:
1 5 2 4 2 2 2
existuje celkem 21 možných intervalů délky alespoň 2:
0..1:  1 5               suma=6
0..2:  1 5 2             suma=8
0..3:  1 5 2 4           suma=12
0..4:  1 5 2 4 2         suma=14
0..5:  1 5 2 4 2 2       suma=16
0..6:  1 5 2 4 2 2 2     suma=18
1..2:  5 2               suma=7
1..3:  5 2 4             suma=11
1..4:  5 2 4 2           suma=13
1..5:  5 2 4 2 2         suma=15
1..6:  5 2 4 2 2 2       suma=17
2..3:  2 4               suma=6
2..4:  2 4 2             suma=8
2..5:  2 4 2 2           suma=10
2..6:  2 4 2 2 2         suma=12
3..4:  4 2               suma=6
3..5:  4 2 2             suma=8
3..6:  4 2 2 2           suma=10
4..5:  2 2               suma=4
4..6:  2 2 2             suma=6
5..6:  2 2               suma=4
A z těchto 21 intervalů lze vybrat 12 dvojic různých intervalů se stejným součtem:
0..1 ~ 2..3             suma=6  
0..1 ~ 3..4             suma=6  
0..1 ~ 4..6             suma=6  
0..2 ~ 2..4             suma=8  
0..2 ~ 3..5             suma=8  
0..3 ~ 2..6             suma=12 
2..3 ~ 3..4             suma=6  
2..3 ~ 4..6             suma=6  
2..4 ~ 3..5             suma=8  
2..5 ~ 3..6             suma=10 
3..4 ~ 4..6             suma=6  
4..5 ~ 5..6             suma=4  
Vstupem programu je posloupnost celých čísel (kladných, nulových i záporných). Zadávání vstupní posloupnosti skončí po dosažení konce vstupu (EOF). Čísel ve vstupní posloupnosti může být nejvýše 2000.

Výstupem programu je počet nalezených dvojic intervalů se stejným součtem.

Program musí detekovat nesprávný vstup. Za chybu považujte:

vstupní posloupnost je prázdná (obsahuje 0 čísel),
vstupní posloupnost je příliš dlouhá (přes 2000 čísel),
hodnota na vstupu není platné celé číslo.
