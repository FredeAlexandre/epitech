import utils

def perform_elevation(client, inventory, current_level):
    required_items = utils.required_items[current_level]
    enough_resources = True

    if inventory['food'] < 5:
        return current_level

    for item, quantity in required_items.items():
        if item != "players" and inventory[item] < quantity:
            enough_resources = False
            break

    if enough_resources:
        for item, quantity in required_items.items():
            if item != "players":
                for i in range(1, quantity + 1):
                    utils.send_msg(client, "Set " + item)
                    utils.receive_msg(client)

    text = "kk"
    utils.send_msg(client, "Incantation")
    text = utils.receive_msg(client)
    if (text == "Elevation underway" and enough_resources):

        finallevel = utils.receive_msg(client)
        finallevel = str(finallevel)[15:]
        if finallevel != "":
            return int(finallevel)

    return current_level
