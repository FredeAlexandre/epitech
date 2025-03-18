import socket
import utils
import move
import elevation

currentlevel = 1

def connect (argv):
    HOST = utils.search_argv(argv, "-h")
    PORT = int(utils.search_argv(argv, "-p"))

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((HOST, PORT))

    WelcomeMsg = utils.receive_msg(client)
    TeamNameMessage = utils.search_argv(argv, "-n")
    utils.send_msg(client, TeamNameMessage)

    TeamNameAnswer = utils.receive_msg(client)
    global currentlevel
    while(True and TeamNameAnswer != "ko"):

        utils.send_msg(client, "Inventory")
        Inventory = utils.parse_inventory(utils.receive_msg(client))

        utils.send_msg(client, "Look")
        Look = utils.parse_look(utils.receive_msg(client))

        currentlevel = elevation.perform_elevation(client, Inventory, currentlevel)


        HMap = utils.create_heatmap(Inventory, currentlevel)
        Tile = move.find_closest_object_index(HMap, Look)

        if (move.TestMovement(client, Tile)):
            continue
        move.TakeOnMe(client, HMap, Look[Tile])

        utils.send_msg(client, "Connect_nbr")
        FreeSlots = (utils.receive_msg(client))
        Slots = 1
        try:
            Slots = int(FreeSlots)
        except:
            Slots = 1
        if (Slots < 1 and Inventory['food'] > 3):
            utils.send_msg(client, "Fork")
            utils.receive_msg(client)


        continue
    client.close()
