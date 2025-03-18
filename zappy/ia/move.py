import utils

def find_closest_object_index(heatmap, vision):
    priority_order = ['food', 'linemate', 'deraumere', 'sibur', 'mendiane', 'phiras', 'thystame']
    indexvision = 0
    indexlist = [0, 2, 6, 12, 1, 3, 20, 5, 7, 30, 4, 11, 13, 8, 42, 10, 19, 21, 14, 56, 9, 18, 29, 31, 22, 15, 72, 17, 28, 41, 43, 32, 23, 16, 27, 40, 55, 57, 44, 33, 24, 26, 39, 54, 71, 73, 58, 45, 34, 25, 38, 53, 70, 74, 59, 46, 35, 37, 52, 69, 75, 60, 47, 36, 51, 68, 76, 61, 48, 50, 67, 77, 62, 49, 66, 78, 63, 65, 79, 64, 80]

    for indexvision in indexlist:
        index = 0
        if indexvision >= len(vision):
            continue
        while index < 7:
            if heatmap[index] == 1 and vision[indexvision][priority_order[index]] > 0:
                return indexvision
            index += 1
        indexvision += 1
    return -1

def getFaxis(index):
    res = 0
    while index >= ((res + 1) * (res + 1)):
        res += 1
    return res

def getDirAndSize(index, Faxis):
    res = 0
    for num in range(0, Faxis + 1):
        res += num
    res *= 2
    return (index - res)

def TestMovement(client, Tile):
    if (Tile == -1):
        utils.send_msg(client, "Left")
        utils.receive_msg(client)
        return True
    Forw = getFaxis(Tile)
    Turn = getDirAndSize(Tile, Forw)
    for _ in range(0, Forw):
        utils.send_msg(client, "Forward")
        utils.receive_msg(client)
    if Turn < 0:
        utils.send_msg(client, "Left")
        utils.receive_msg(client)
    if Turn > 0:
        utils.send_msg(client, "Right")
        utils.receive_msg(client)
    for _ in range(0, abs(Forw)):
        utils.send_msg(client, "Forward")
        utils.receive_msg(client)
    return False

def TakeOnMe(client, HMap, Vision):
    priority_order = ['food', 'linemate', 'deraumere', 'sibur', 'mendiane', 'phiras', 'thystame']
    index = 0
    while index < 7:
        if HMap[index] == 1 and Vision[priority_order[index]] > 0:
            utils.send_msg(client, "Take " + priority_order[index])
            utils.receive_msg(client)
        index += 1