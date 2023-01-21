Parafráze zadání

Ukolem je vytvořit rozhraní pro správu studentů ucházejících se o splnění zkoušky.
Na vstupu jsou zadáná jména studentů ve formátu X: Jmeno1 Jmeno2 Jmeno3,
kde „X“ je buď písmeno „R“ (zaregistroval se na zkoušku) nebo „P“ (přišel na zkoušku).
Jmeno1, Jmeno2 a Jmeno3 má maximálně 32 znaků a může být zadáno jedno až tři jména studenta, přičemz mezi jmény je právě jedna mezera.
BONUS: Pocet jmen nebyl omezeny a jejich velikost taky nebyla omezena.
Jména studentů jsou stejná i pakliže nejsou ve stejném pořadí, nebo mají jinak velká písmena
Ladislav Vagner == Vagner Ladislav == LaDIslAV VagNER.
Ukolem je:
1) vypsat ty studenty, kteří se zaregistrovali na zkoušku, ale nepřišli
2) vypsat ty studenty, kteří přišli na zkoušku, ale nezaregistrovali se
Výpis jmen studentů musí být ve stejnem pořadí jako při zadání jmen a také case-sensitivite jako na vstupu.
např. vstup Franta PEPA jeDnička → výstup Franta PEPA jeDnička
Poradi vypsání ruznych jmen studentu neni urceno, Progtest si jej upraví.
Pokud byli zadáni studenti přihlášní na zkoušku se stejným jménem např. Jarda Pepa == PePA jaRDA,
ale registrován byl pouze jeden student s tímto jménem (např. JArda PePA), tak platí priorita toho, který byl na vstupu zadaný jako první.
Nespravny Vstup:
1) Nejdrive se zadavaji Registrovani studenti a poté Přítomní. Pokud na vstupu je zadán Registrovaný student až po přítomném je vstup chybný.
2) Na začátku řádky není identifikátor P nebo R.
! prádný vstup není nesprávný vstup