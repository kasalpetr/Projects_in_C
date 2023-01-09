Úkolem je realizovat program, který bude počítat zůstatek na bankovním účtu. Program bude zpracovávat transakce (vklad, výběr) a bude zohledňovat úročení.

Předpokládáme, že banka vede účty v korunách. Svým klientům umožňuje vkládat a vybírat peníze, ale připouští vždy nejvýše jednu operaci za jeden den. Dále, banka je benevolentní a umožňuje neomezený debet. Kladný zůstatek je úročen kreditní úrokovou mírou, záporný zůstatek je úročen debetní sazbou (která může být odlišná). Úročení probíhá vždy po jednotlivých dnech. Výše zůstatku i výše připsaného/strženého úroku musí být vždy vyjádřena a počítána v korunách a celých haléřích. Všechny částky se zaokrouhlují směrem k nule (tedy připsaný/stržený úrok ve výši 1.3499 bude zpracován jako částka 1.34). V daný den se úročí částka, která byla na účtu v půlnoci, vklad/výběr se v úročení tedy projeví až následující den.

Vstupem programu jsou hodnoty kreditní a debetní úrokové sazby v podobě dvou desetinných čísel. Hodnoty vyjadřují denní úrok v procentech. Následuje seznam transakcí. Každá transakce je tvořena dvěma čísly: dnem provedení transakce a částkou. Transakce jsou na vstupu zadávané seřazené, tedy čísla dne se zvyšují. Kladná částka představuje vklad, záporná částka představuje výběr. Nulová částka znamená zrušení účtu, program na to zareaguje výpisem celkového zůstatku a ukončením.

Výstupem programu je hodnota zůstatku při rušení účtu. Formát výstupu je zřejmý z ukázek níže. Nezapomeňte na odřádkování za výpisem.

Pokud vstup není platný (na vstupu jsou nečíselné nebo nesmyslné hodnoty), program tuto situaci detekuje a vypíše chybové hlášení. Formát chybového hlášení je opět uveden v ukázkách níže. Za chybu je považováno, pokud je na vstupu:

nečíselná hodnota,
pořadí transakcí není správné (čísla dne v transakci netvoří rostoucí posloupnost) nebo
chybějící oddělovač (částka) v zadání transakce.
Pokud program detekuje chybu, přestane se dotazovat na další vstupní hodnoty, vypíše chybové hlášení a ukončí se. Chybu je tedy potřeba detekovat okamžitě po načtení hodnoty (neodkládejte kontrolu vstupních údajů až za načtení celého vstupu). Chybové hlášení vypisujte na standardní výstup (nevypisujte jej na standardní chybový výstup).
