#!/usr/bin/python3

import sys
import client
import utils
import move

def test_args(argv):
    if (len(argv) % 2 != 1):
        return True
    if (utils.search_argv(argv, "-p") == "-1"):
        return True
    if (utils.search_argv(argv, "-n") == "-1" or utils.search_argv(argv, "-n") == "GRAPHIC"):
        return True
    try:
        port = int(utils.search_argv(argv, "-p"))
    except ValueError:
        return True
    if (port < 0):
        return True
    i = 1
    while (i < len(argv)):
        if (argv[i] != "-p" and argv[i] != "-n" and argv[i] != "-h"):
            return True
        i+=2
    return False

def print_help():
    print("USAGE:\t./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")

def main(argv):
    if (test_args(argv)):
        print_help()
        exit(84)
    client.connect(argv)
    # Lancer la connection avec le serveur
    # à partir de la connection, Gérer les choix etc


main(sys.argv)
