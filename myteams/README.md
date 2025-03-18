# MyTeams

## User Section

### Protocol

TODO: Write how protocol works

### Client Usage 

TODO: Write how to use client

### Server

TODO: Write how to use Server

## Dev Section

### Server

1. Trame

Le serveur fonctionne par trame/command a travers le protocole TCP. Une trame est definie comme ceci:

Example trame:

```txt
<data> <PACKET_END>
```

Par default le serveur a comme `PACKET_END` la valeur `\n` on peut donc utiliser netcat et pour chaque retour a la ligne le serveur l'interpretera comme une nouvelle commande

2. Entree/Sortie

Le serveur peut recevoir et envoyer des donnees "en meme temps" c'est a dire qu'il n'est pas bloquer par l'attente par exemple de la fin d'une trame.

Example:

Le client (qui a etait mal fait) envoie la commande `/login Alexandre` au serveur en plusieur fois

```txt
-> "/log"
-> "in "
-> "Alexandre"
-> "\n"
```

c'est unique a la reception du 4eme paquet que le serveur executera la logique derriere la commande "/login".

```txt
-> "/log"
-> "in "
<- "reponse d'une commande precedente... (je suis beteeee)"
-> "Alexandre"
-> "\n"
```
ce scenario fonctionnera aussi car toutes les reception et envoie sont bufferiser

### How commands and replies works ?

This is how CLI communicate with server

Request:
```
<COMMAND>[[[[:<USER_ID>]:<TEAM_ID>]:<CHANNEL_ID>]:<THREAD_ID>][|<DATA>]
```

Examples:
```sh
/list
```
```
LIST
```

```sh
/login Alex
```
```
LOGIN|Alex
```

```
EVENT_NAME:PARAM1:PARAM2:...
```