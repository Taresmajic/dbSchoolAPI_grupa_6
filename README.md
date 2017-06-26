# Strukture Podataka-grupa 6
Projekat Strukture podataka
Projekat je pravljen od strane:
Tarik Smajić
Kenan Mazalović
Ajdin Rahmanović
Emir Terzić

Projekat je pravljen na sljedećem principu:
Prvi korak:
Prvi korak je da se kreiraju klase za sve tekstualne file-ove, te da se kreiraju odgovarajući geteri i seteri
sto se moze vidjeti u:
(Ajdin)
1.student.h
2.teacher.h
3.subject.h
4.department.h
(Emir, Tarik)
5.studentsSubjectsTeachers.h
6.depSub.h
7.subjectTeachers.h

Osnovni seteri i geteri od student.h i teacher.h su naslijedjeni od osoba.h.

Drugi korak:(Kenan, Ajdin)
Drugi korak je omogucavanje parsiranja i funkcija upisivanja u tekstualne file-ove.
Parsiranje se moze naci u parsiranje.cpp i parsiranje.h također kao i upis u txt file-ove.
Parsiranje je izvrseno pomocu jedne glavne funkcije separate i overloadinga funkcije parsiraj.
Parsiranje je vrseno nad listanam odredjenih klasa ili relacija.
Ovime je omogucen rad sa listama te uvezivanje nasih listi.

Treci korak:(Tarik, Ajdin)
Treci korak je napraviti strukturu listu "List.h" koja je jednostruko linkana i koja sortira po id-u nase podatke.
Takodje smo napravili strukturu Vektor.h pomocu koje smo ispisivali nase podatke sortirane po odredjenim parametrima putem metoda sort i lambda izraza.
Vektor je napravljen kao sa predavanja te su izvrsene odredjene izmjene i dodatci.


Cetvrti korak:(Tarik, Kenan, Ajdin, Emir)
Nakon svega toga napravljena je klasa Baza.h.
Baza.h:
-Sadrzi privatne clanove listi u koje se smjestaju podatci iz txt file-ova.
-Napravljene su odredjene liste relacija(service) pomocu kojih smo uvezali sve nase podatke, i pomocu kojih smo mi uradili nasu bazu.
-Konstruktor koji vrsi parsiranje podataka.
-Metod koji upisuje nazad u txt file-ove.
-Sadrzi metode koje sluze za ispis razlicitih kriterija i razlicitih podataka,
npr: svi studenti sa odredjenog departmenta.
-Takodje sadrzi metode pomocu kojih su povezani nasi podatci i koji sluze pri ispisu kao i pri uvezivanju podataka.
-Sadrzi i metode koje koristimo unutar klase options.h.
-Sve metode sadrze komentare koji sluze za orijentaciju i koje opisuju njihovu upotrebu.

Peti korak:
(Emir i Tarik)
U petom koraku napravljen je options.h u kojem se nalazi sljedece:
-Napravljen je interfejs za main menu i kretanje kroz nas menu.
-Napravljene su funkcije insert update i read te pomocne funkcije koje se ukljucuju pomocu switch grananja, te pomocu kojih vrsimo sljedece od navedenog:
(Tarik)
1.Insert:
-Upisujemo nove podatke pomocu raznih opcija koje nam nudi sam program.
(Tarik, Emir)
2.Update
-Pomocu funkcije i pomocnih funkcija vrsimo update postojecih podataka.
(Kenan)
3.Read:
Pomocu read funkcije te pomocnih funkcija mi vrsimo citanje nasih podataka sa razlicitim parametrima.
Nakon gasenja projekta poziva se metod alltxt koji ce spremiti sve sto smo uradili sa podatcima u prethodne tri funkcije, te je sa time program gotov sa radom, a podatci upisani u nase baze podataka.
(Ajdin, Kenan)
Napravljeni su metodi getbyid ili getid te je omoguceno citanje i pisanje potadatak u nase liste. Takodje je omogucena i provjera nasih upisa za odredjena polja koja ne smiju da budu ista kao npr id ili jmbg te samo jedan profesor za jedan predmet kao i da profesor smije biti samo na jednom departmentu.
Takodje Jmbg ne smije imati ispod 13 cifara niti iznad , a eval u intervalu izmedju 6 i 10, kao i prilikom odabira godine predmeta mora se odabrati u koji odgovarajuci semestar da se upise u skladu sa godinom. 

Prilikom pokretanja programa mi pomocu brojeva biramo zeljene opcije te prilikom odabira tih opcija ekran se resetuje i pokazuje nove opcije zajedno sa opcijom za go back ili exit.

Mi smo Odabrali da pravimo objekte za sve datoteke radi lakseg parsiranja ali i funkcionalnost programa ostaje ista te je lakse uociti greske.

Takodje smo odabrali da pravimo service koji su predlozeni jer preko njih smo uvezali nase podatke iz tekstualnih file-ova kako bi oni bili pravilno koristeni te uvezani.

Program je radjen kolektivno te su samo mali dijelovi radjeni odvojeno kod kuce, te smo prilikom pravljenja programa te uploada na github koristili dva do tri laptopa tako da smo izvrsili upload sa tih laptopa te kolektivno i efikasno razrijesili problem i kreirali rjesenje.
