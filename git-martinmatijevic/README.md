# Osnove sustava za upravljanje kodom Git

## Instalacija

Ukoliko ste na Linux sustavu Git je preinstaliran i može se odmah koristiti.
Na Mac i Windows sustavima Git je potrebno  instalirati. Za Windows OS vidjeti
stranicu  https://gitforwindows.org/, a za Mac OS stranicu https://git-scm.com/.
U slučaju problema postoje brojni resursi na web-u koji nude
pomoć pri instalaciji Git-a.

## Priprema za rad sa Git-om

Sa Git-om ćemo raditi koristeći komandnu liniju, odnosno Git naredbe ćemo
zadavati u terminalu. Sve Git naredbe imaju oblik
```bash
git naredba [opcije]
```
Prije samog rada s Git-om potrebno je izvršiti konfiguraciju Git-a koja se
sastoji u tome da se postavi korisničko ime i email adresa.
U radu s GitHub-om važno je postaviti email adresu koja je dana GitHub-u
prilikom kreiranja računa.

Naredbe koje treba iskoristiti su sljedeće:
```bash
git config --global user.name "korisničko_ime"
git config --global user.email "email_adresa"
```


Repozitorij možemo kreirati na dva načina. Prazan repozitorij kreiramo sa
`git init` naredbom ili možemo *klonirati* već postojeći repozitorij sa
`git clone` naredbom.


## Kreiranje novog repozitorija

Ako kreiramo posve novi repozitorij prvo trebamo kreirati njegov
direktorij i ući u njega.

```bash
mkdir Zadatak67
cd Zadatak67
```
Unutar direktorija sada je dovoljno izvršiti
```bash
git init
```
naredbu. Git će odgovoriti sa `Initialized empty Git repository in ...`
Ako izlistate direktorij s naredbom
```bash
ls -a
```
vidjet ćete da je Git kreirao skriveni direktorij `.git` u kojem drži sve svoje
podatke (repozitorij). Repozitorij je u ovom trenutku prazan i datoteke se
u njega uključuju sa `git add` naredbom.  Status direktorija se dobiva sa
```bash
git status
```
naredbom.

Git prati datoteke koje su mu dane i pamti svaku njihovu izmjenu koja je predana
repozitoriju. Ako su neke izmjene napravljene u repozitoriju dovele do
grešaka uvijek je moguće vratiti se na prethodnu verziju repozitorija. Git će
zapamtiti čitavu povijest repozitorija.

Git pamti promjene samo onih datoteka koje mu damo sa `git add` naredbom. Druge
datoteke u direktoriju ignorira. Recimo da smo u našem direktoriju (Zadatak67)
kreirali datoteku `CMakeLists.txt`. Kako bi je Git počeo pratiti moramo
izvršiti naredbu
```bash
git add CMakeLists.txt
```
Uključivanje datoteke u Git repozitorij sastoji se od dva koraka. Pomoću naredbe
`git add` datoteka se uključuje u indeks (češći naziv je _staging area_).
U drugom koraku potrebno je pozvati `git commit` naredbu koja sve datoteke iz
indeksa prebacuje u repozitorij i kreira novu trenutnu sliku čitavog radnog
direktorija u repozitoriju. Nakon poziva naredbe
```bash
git commit
```
Git će otvoriti editor (na linuxu obično vi, no to se može konfigurirati) u koji
trebamo upisati komentar našeg _commit-a_. Pomoću `-m` opcije možemo direktno
dodati komentar.
```bash
git commit -m "Dodan je file CMakeLists.txt"
```

## Rad sa Git-om

U direktoriju u kojem razvijamo kod kreiramo Git repozitorij sa `git init` naredbom.
Svaku datoteku koju želimo pratiti u repozitoriju dodajemo sa `git add` naredbom.
Obično u svakom direktoriju ima i trenutnih i pomoćnih datoteka koje ne želimo
pamtiti u repozitoriju. To se prije svega odnosi na sve  datoteke generirane pomoću
prevodioca ili drugih alata; njih nikada ne dodajemo sa `git add` naredbom.

Ako smo jednu datoteku dodali u indeks sa `git add` naredbom i zatim je izmjenili,
nove izmjene nisu registrirane u indeksu sve dok ju ponovo ne dodamo u indeks
sa `git add` naredbom.

Kada smo sa grupom izmjena datoteka zadovoljni dodajemo te izmjene u repozitorij
sa  `git commit` naredbom. Ono što je repozitoriju dodano sa  `git commit` predstavlja
jednu fazu u razvoju softvera. Svako spremanje u repozitorij (svaki _commit_)
dobiva svoj identifikator i predstavlja jednu točku u povijesti razvoja koda na
koju se možemo vratiti.


Osnovni ciklus rada sa repozitorijem je sljedeći:
1. Mijenjamo datoteke u radnom direktoriju;
2. Dodajemo izmjene u indeks (`git add`). Iteriramo 1 -> 2  sve dok nismo zadovoljni s izmjenama.
3. Ubacujemo izmjene iz indeksa u repozitorij (`git commit`). Vraćamo se na 1 sve dok
zadatak (projekt) nije gotov.

Pomoću `git status` naredbe možemo vidjeti koje datoteke nisu u indeksu, koje jesu
ali su u međuvremenu izmijenjene i na osnovu toga znamo koju operaciju treba izvršiti.

## Kloniranje postojećeg repozitorija


Projekt često započinjemo kloniranjem već postoječeg Git repozitorija. To će biti slučaj sa zadacima
u ovom kolegiju. Zadatak s početnim kodom bit će postavljen kao Git repozitorij na
GitHub servisu. Repozitorij treba klonirati na lokalnu mašinu, doraditi kod u repozitoriju
prema danim uputama i gurnuti izmjene u GitHub repozitorij.

Kloniranje repozitorija se radi sa `git clone` naredbom koja kao opciju uzima URL repozitorija
koji se klonira. Klonirajmo trenutni repozitorij koji je na adresi https://github.com/PMF-MO-OPCPP/Git.
```bash
git clone https://github.com/PMF-MO-OPCPP/Git
```
Git će u direktoriju u kojem smo izvršili ovu naredbu kreirati lokalni direktorij `Git` i u njega povući
cijeli sadržaj repozitorija. Ako želimo drukčije ime lokalnog direktorija možemo ga zadati kao
dodatni argument. Naredba
```bash
git clone https://github.com/PMF-MO-OPCPP/Git myGit
```
kreirati lokalni direktorij `myGit` i u njega povlači cijeli sadržaj repozitorija.

Rad sa repozitorijem je posve isti kao i kada repozitorij kreiramo lokalno sa `git init`
naredbom. Modificiramo datoteke, koristimo `git add` naredbu za prijavljivanje izmjena
u indeks i `git commit` naredbu za ubacivanje izmjena iz indeksa u (lokalni) repozitorij.

Kad je jedan dio zadatka (projekta) gotov potrebno je lokalni repozitorij gurnuti na GitHub,
odnosno u repozitorij koji je kloniran (koji može biti bilo gdje, na lokalnom serveru ili nekom drugom stroju).
Naravno, za tu operaciju je potrebno imati odgovarajuće ovlasti.

Za prebacivanje modifikacija lokalnog repozitorija na udaljeni repozitorij
koristimo naredbu
```bash
git push origin master
```
Analogna naredba postoji za povlačenje izmjena sa udaljenog repozitorija u lokalni
repozitorij:
```bash
git pull origin master
```
U ovim naredbama `origin` je kratak naziv za udaljeni repozitorij. Naredba
```bash
git remote -v
```
otkriva punu adresu `origin` repozitorija. Nadalje, `master` je ime grane na kojoj se nalazimo.
Glavna grana u repozitoriju se kreira automatski i dobiva ime `master`. Prilikom razvoja softvera,
ispravljanja grešaka ili dodavanja nove funkcionalnosti, novi kod se obično razvija u novoj grani
dok `master` grana ostaje netaknuta sve dok izmjene u novoj grani nisu potpune. Tada se te izmjene
uključuju u `master` granu (to je proces koji se naziva `merge`). Mi grane nećemo koristiti
tako da će jedina grana uvijek biti `master`.

**Napomena:** `git pull` naredba povlači izmjene iz udaljenog repozitorija u lokalni i vrši uključivanje
izmjena u lokalni repozitorij (_merge_). U tom koraku može doći do **konflikta** između lokalnih izmjena
i izmjena u udaljenom repozitoriju koje se moraju rješavati _ručno_.


## GitHub Classroom

Za distribuciju zadataka u ovom kolegiju  koristimo _GitHub Classroom_ servis. Classroom   funkcionira
tako što nastavnik putem email poruke šalje studentima URL repozitorija koji trebaju klonirati.
Studenti trebaju slijediti dobiveni URL pri čemu Classroom za njih kreira privatni repozitorij
sa zadatkom. Na tom privatnom repozitoriju student ima pravo koristiti `pull` i `push` naredbe (koristeći
  svoj login i password).

**Važna napomena.** Pri rješavanju zadataka potrebno je `git push`  naredbu izvršiti barem dva puta: u sredini
procesa rješavanja i na kraju kada je zadatak riješen. Veći broj `push`-ova u udaljeni repozitorij
je dobrodošao. Ovo je nužno kako bi se spriječilo da se tuđe rješenje jednostavno gurne u GitHub Classroom
repozitorij. Zadaci koji su spremljeni sa samo jednom `git push` naredbom  neće se uzimati u obzir! 


## Submodul

Za testiranje koda koristit ćemo _Google Test_ biblioteku (*googletest*)  otvorenog koda koja se nalazi na GitHub-u na adresi
https://github.com/google/googletest. Biblioteku bismo mogli instalirati na lokalnom računalu i naše programe 
povezati s njom za vrijeme izgradnje programa. Mi ćemo iskoristiti drugi pristup koji je moguć stoga
što  *googletest* ima javno dostupan Git repozitorij, a sastoji se u tome da *gtest* učitamo u naš Git projekt kao **submodule**.
*Submodule* je Git repozitorij koji se nalazi u jednom direktoriju unutar nekog drugog Git repozitorija. 


Submodul se kreira pozivom naredbe `git submodule add` koja uzima URL repozitorija koji želimo preuzeti
kao *submodule*. U našim zadacima ćemo u repozitoriju imati direktorij `external`. Ako u tom direktoriju 
izvršimo naredbu
```
git submodule add https://github.com/google/googletest 
```
dobit ćemo poddirektorij `external/googletest` u koji će biti utočena googletest biblioteka. Pored toga 
bit će kreirana skrivena datoteka `.gitmodules` sljedećeg sadržaja:
```
[submodule "ex5/external/googletest"]
	path = ex5/external/googletest
	url = https://github.com/google/googletest
```
(čitav projekt je u direktoriju `ex5`). Git će automatski dodati  `.gitmodules` i `external/googletest` direktorij u 
indeks te nam preostaje samo sa `git commit` ubaciti ih u lokalni repozitorij. 

Kada gurnemo lokalni repozitorij sa submodulom u udaljeni repozitorij sam submodul neće biti kopiran već 
će biti kopiran samo prazan direktorij submodula (ovdje `/external/googletest`) i datoteka `.gitmodules`.
Isto se dešava kada kloniramo repozitorij sa submodulom.

Ako smo klonirali repozitorij sa submodulom (što će biti naš slučaj sa zadacima) onda prije rada na repozitoriju 
i kompilacije treba pozvati sljedeće dvije naredbe:

```
git submodule init
git submodule update
```
Prva naredba vrši lokalnu inicijalizaciju submodula, a druga dohvaća submodul iz njegovog udaljenog repozitorija 
i smješta ga njegov direktorij. Nakon toga se može početi raditi na projektu (zadatku).  


