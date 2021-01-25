# Projekt PWI - Szachy online, offline oraz zagadki szachowe
Projekt służy tylko i wyłącznie do celów naukowych - jest to praca na zaliczenie przedmiotu Podstawowy Warsztat Informatyka na Uniwersytecie Wrocławskim

Michał Bednarz, Anna Krysta, Michał Wach, Tomasz Marx, Marcin Linkiewicz

## Wymagania
System Linux z terminalem obsługującym wyświetlanie 256 kolorów lub system Windows (uproszczone wyświetlanie na windowsie)
Kompilator GCC lub inny

## Instalacja
Instalacja na systemie Linux:
- Pobierz kod źródłowy z repozytorium: 
- Jeżeli korzystasz z GCC skompiluj kod poleceniem ``g++ -o <nazwa_pliku> main.cpp``
- Program możesz uruchomić poleceniem ``./<nazwa_pliku>``

## Działanie
Po włączeniu programu użytkownik zostanie zapytany o wybranie trybu gry: gra lokalnie w trybie hot-seat, zagadki szachowe typu "mate in one" lub gra przez sieć z innym graczem  
Aby poruszyć się figurą należy wpisać koordynaty początku i końca  ruchu, np. "a2a4", małymi literami, razem.  

W grze hot-seat:  
Żeby poprosić o remis wpisz "draw".  
Żeby zakończyć grę wpisz "quit".  
Żeby poddać się wpisz "surr".  

![](https://i.imgur.com/Q38glul.png)

## Eksport do PGN
Program oferuje eksport danej partii do pliku w formacie PGN (Portable Game Notation).  
Specyfikacja PGN - [LINK](http://www.saremba.de/chessgml/standards/pgn/pgn-complete.htm)

Po zakończeniu lub przerwaniu gry program zapyta użytkownika czy chce on zapisać rozegraną właśnie partię (lub przerwaną bez zakończenia).
Zapis meczu zostanie zapisany w pliku PGN o nazwie w formacie \[year\]-\[month\]-\[day\]-\[hours\]-\[minutes\]-\[seconds\].pgn  

## Import z PGN
Niestety program nie wspiera jeszcze importu gier w PGN  

## Gra sieciowa
Niestety program nie wspiera jeszcze rozgrywki przez sieć


