Úkolem je vytvořit program, který bude spravovat parkovací dům.

Předpokládáme parkovací dům, který má x pater a na každém patře y parkovacích stání. Do tohoto parkovacího domu přijíždějí automobily a automobily z něj odjíždějí. Příjezd a odjezd je řízen Vaším programem. Při příjezdu je zadáno místo k zaparkování (patro, pozice na patře a RZ automobilu). Řídící systém rozhodne, zda je takové parkování možné (tj. zda je uvedené parkovací místo volné) a případně jej obsadí. Pokud parkovací místo volné není, je takový požadavek odmítnut.

Analogicky, při odjezdu je naskenovaná RZ odjíždějícího automobilu a odpovídající parkovací místo je označeno za volné. Pokud není RZ odjíždějícího automobilu nalezena v seznamu zaparkovaných vozů, program na to upozorní.

Program dostane na vstupu nejprve rozměry parkoviště. Jedná se o dvojici celých čísel - počet pater následovaný počtem parkovacích míst na jednom patře. Za tímto zadáním následuje seznam příjezdů a odjezdů automobilů. Příjezd má tvar + patro pozice RZ, kde patro a pozice jsou celá čísla v rozsahu 0 až počet pater - 1, resp. počet parkovacích pozic - 1 a RZ je libovolná posloupnost znaků udávající registrační značku (registrační značka může být maximálně 10 znaků dlouhá a neobsahuje bílé znaky). Odjezd automobilu je zadán jako - RZ, kde RZ je registrační značka odjíždějícího automobilu, platí pro ni stejná omezení jako v případě zadání RZ při příjezdu.

Výstupem programu je reakce na zpracování jednotlivých příjezdů a odjezdů. Pokud je příjezd / odjezd zpracován správně, program pouze zobrazí hlášku OK. Pokud je při příjezdu zadané obsazené místo, případně při odjezdu zadaná RZ automobilu, který aktuálně v parkovacím domě není zaparkován, program to vyhodnotí jako nesplnitelný požadavek a vypíše odpovídající hlášku. Dále pak pokračuje zpracováním dalších vstupních požadavků.

Pokud je vstup neplatný, program to musí detekovat, zobrazit chybové hlášení a ukončit se. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

velikost parkovacího domu není zadaná jako dvojice celých kladných čísel,
je zadaný jiný pokyn než příjezd nebo odjezd (tj. požadavek nezačíná ani + ani -),
u příjezdu chybí některý údaj (patro, pozice, RZ) nebo patro/pozice jsou mimo rozsah parkovacího domu,
u odjezdu není zadaná RZ.