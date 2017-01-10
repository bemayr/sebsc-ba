%title: Ergebnisse der theoretischen Bachelorarbeit
%author: Bernhard Mayr (S1510307081)
%date: 2017-01-08



\                                         ##         .
\                                   ## ## ##        ==
\                                ## ## ## ## ##    ===
\                            /"""""""""""""""""\\\_\_\_/ ===
\                       ~~~ {~~ ~~~~ ~~~ ~~~~ ~~~ ~ /  ===- ~~~
\                            \\\_\_\_\_\_\_ o           \_\_/
\                              \\    \\         \_\_/
\                               \\\_\_\_\_\\\_\_\_\_\_\_\_/


-> "Docker als unterstützendes Werkzeug <-
-> für Software-Entwickler" <-



-> ## Datum: 10.01.2017 <-
-> ## Betreuer: FH-Prof. DI Johann Heinzelreiter <-
-> ## Institution: Fachhochschule Hagenberg [SE] <-

--------------------------------------------------

-> # Erkenntnisse <-

^
1. Virtualisierung
  - Container sind der nächste Schritt (Skalierung, Cloud, ...)
^
2. Konfigurationsmanagement
  - Vagrant braucht für viele Projekte zu viel Speicher
  - Infrastrukturautomatisierung wird immer wichtiger (Orchestrierung)
^
3. Docker
  - natives Docker for Windows & Docker for Mac (+ Windows Container)
  - Dockerfiles: Linux-Kenntnisse notwendig

^
-> ## Inspiration <-
-> Wobei kann mir Docker helfen? <-

^
4. Anwendungsmöglichkeiten
  - Softwareevaluierung
  - *Verbesserung des Build-Prozesses*
  - Testen mithilfe von Containern
  - Plattformübergreifende Übersetzung
  - IDE as a Container
  - *Replikation der Produktionsumgebung*
  - *Plattformunabhängige (CLI)-Anwendungen*

--------------------------------------------------

-> # Verbesserung des Build-Prozesses & Replikation der Produktionsumgebung <-


Entwicklung der [Homepage](http://ff-wartberg.mayr.io/) für die *Freiwillige Feuerwehr Wartberg ob der Aist*.
> Frontend: `Jekyll` (Static Site Generator - Ruby)
> Backend: `cockpit` (Headless CMS - PHP+SQLite)
> Build-Prozess: PHP-Build-Skript + `GitHub Pages`


^
-> # Frontend - Jekyll <-
-> ## While Windows is not an officially-supported platform, <-
-> ## it can be used to run Jekyll with the proper tweaks. <-

^
> *Frontend Build Task (inkl. Watch-Modus)*
~~~
    docker-compose up -d
    docker-compose logs -f   # falls Ausgabe erwünscht ist
~~~


> *auf Basis von docker-compose.yml*
~~~
    version: '2' 
    services: 
      jekyll: 
        image: jekyll/jekyll 
        ports: 
        - "4000:4000" 
        volumes: 
        - .:/srv/jekyll
~~~


^
-> # Backend - cockpit <-
> * Backend auch auf Basis von docker-compose, jedoch mit eigenem Docker-Image*
~~~
    [...]   # in der Bachelorarbeit
~~~

--------------------------------------------------

-> # Plattformunabhängige CLI-Anwendungen <-

> *Create Dockerfile for [mdp](https://github.com/visit1985/mdp)*
~~~
    FROM alpine:3.5
    MAINTAINER Bernhard Mayr <bernhard@mayr.io>
    ENV MDP_VERSION 1.0.9
    RUN apk update && \
        apk add make gcc [...] && \
        [...]
        wget -P /mdp https://github.com/visit1985/mdp/archive/$MDP_VERSION.tar.gz && \
        tar -xzf /mdp/$MDP_VERSION.tar.gz -C /mdp && \
        make -C /mdp/mdp-$MDP_VERSION && make -C /mdp/mdp-$MDP_VERSION install && \
        cp /mdp/mdp-$MDP_VERSION/sample.md /demo.md && \
        printf "#!/bin/sh\nsleep 0.1\n\$*\n" > /start.sh && chmod +x /start.sh && \
        rm -rf /mdp && apk del make && apk del gcc
    
    WORKDIR /data
    ENTRYPOINT ["/start.sh"]
    CMD ["mdp", "/demo.md"]
~~~


^
> *Integrate `mdp` into Windows (Create Powershell-"Alias")*
~~~
    docker build -t bemayr/mdp .
    function mdp { docker run -it --rm -v ${pwd}:/data bemayr/mdp mdp ${args} }
    mdp <presentation.md>
~~~



^
-> ## Creating Docker Images (for Non-(Linux-Geeks)) <-

> *Run Interactive Container from Base-Image*
~~~
    docker run -it --rm alpine sh
    ... # guess commands ;)
~~~

--------------------------------------------------

-> # Status <-

- Inhalt finalisiert
- alle Quellen gesammelt und zugeordnet
- Schrift ~50%
- Anwendungsmöglichkeiten ~85%



-> geschätzter Fertigstellungsgrad (inkl. Korrekturlesen) <-

-> *~65%* <-

--------------------------------------------------

-> # Fazit <-

> Durch Containertechnologien ergeben sich zahlreiche Vorteile
> für Softwareentwickler.
> Auch wenn momentan die Verwendung von Containern noch etwas
> umständlich ist und zu viel Detailwissen erfordert, wird deren
> Verbreitung in den nächsten Jahren nicht zu stoppen sein.
> Ob Docker dann noch Werkzeug der Wahl ist, ist offen, durch die
> [Open Container Initiative](https://www.opencontainers.org/) wurde ein Standard geschaffen,
> der einer Monopolisierung des Containervirtualisierungsmarktes
> entgegenwirkt, indem Vendor-Lock-Ins verhindert werden.



-> Als unterstützendes Werkzeug für Entwickler eignen sich Container <-
-> sehr gut, da bei korrekter Verwendung endlich Plattformunabhängigkeit <-
-> und Entwicklungsprozessvereinheitlichungen geschaffen werden. <-
