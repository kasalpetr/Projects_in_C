Hotovo
-----------

Úkolem je vytvořit program, který bude vyhledávat plán pro cyklistický výlet. Vstupem programu je zadaná cyklotrasa. Cyklotrasa je definována body, kde lze jízdu začít/ukončit (mezi 
zadanými body nelze najet/sjet). Úkolem je vybrat, kde začít a kde ukončit cyklistický výlet. Pro plán výletu máme následující omezení:

  Nadmořská výška nástupního bodu musí být vyšší nebo stejná jako nadmořská výška výstupního bodu (chceme jet z kopce nebo v nejhorším po rovině).
  Stoupání uprostřed trasy nevadí, ale celkově musíme klesnout.
  Máme-li více voleb se stejným klesáním, zvolíme tu delší.
Vstupem programu jsou jednotlivé nástupní/koncové body na cyklotrase, např. 210 + 5 300 + 6 270

První vstup udává nadmořskou výšku startovního bodu trasy. Následují další body na trase vždy v podobě + vzdálenost_od_startu nadmořská_výška. Vstup končí s EOF. Výstupem programu je 
vyhledaný úsek na cyklotrase, kde lze dosáhnout největšího klesání. Výstupem je jednak délka nalezeného úseku, dále dosažené klesání a počet variant kde ho lze dosáhnout. Na dalších 
řádkách pak následuje výpis těchto úseků.