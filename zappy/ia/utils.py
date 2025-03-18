import queue

IoHandler = queue.Queue()

required_items = [
    {},
    {'players': 1, 'linemate': 1, 'deraumere': 0, 'sibur': 0, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
    {'players': 2, 'linemate': 1, 'deraumere': 1, 'sibur': 1, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
    {'players': 2, 'linemate': 2, 'deraumere': 0, 'sibur': 1, 'mendiane': 0, 'phiras': 2, 'thystame': 0},
    {'players': 4, 'linemate': 1, 'deraumere': 1, 'sibur': 2, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
    {'players': 4, 'linemate': 1, 'deraumere': 2, 'sibur': 1, 'mendiane': 3, 'phiras': 0, 'thystame': 0},
    {'players': 6, 'linemate': 1, 'deraumere': 2, 'sibur': 3, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
    {'players': 6, 'linemate': 2, 'deraumere': 2, 'sibur': 2, 'mendiane': 2, 'phiras': 2, 'thystame': 1},
    {}
]

def search_argv(argv, str):
    i = 1
    while (i < len(argv)):
        if (argv[i] == str):
            return argv[i+1]
        i+=2
    if (str == "-h"):
        return "localhost"
    return "-1"

def send_msg(client, msg):
    client.send((msg + "\n").encode('utf-8'))

def receive_msg(client):
    global IoHandler
    if (IoHandler.empty()) :
        res = client.recv(16384).decode('utf-8')[:-1]
        reslist = str(res).split("\n")
        for i in range(1, IoHandler.qsize() + 1):
            IoHandler.put_nowait(reslist[i])
        if (reslist[0] == "dead"):
            client.close()
            exit()
        return reslist[0]
    else:
        res = IoHandler.get(False)
        if (res == "dead"):
            client.close()
            exit()
        return res

def parse_inventory(stri):
    stri = stri.strip("[]")
    elements = stri.split(", ")
    parsed_dict = {}
    for element in elements:
        elems = str(element).split()
        if (len(elems) > 1):
            key, value = elems[0], elems[1]
            parsed_dict[key] = int(value)
    return parsed_dict

def parse_look(str):
    basicdico = {'food': 0, 'player': 0, 'linemate': 0, 'deraumere': 0, 'sibur': 0, 'mendiane': 0, 'phiras': 0, 'thystame': 0}
    str = str.strip("[]")
    str = str[1:-1]
    elements = str.split(",")
    parsed_dict = []
    index = 0
    for element in elements:
        parsed_dict.append(basicdico.copy())
        elems = element.split(" ")
        for elem in elems:
            if (elem != ''):
                parsed_dict[index][elem] += 1
        index += 1
    return parsed_dict

def create_heatmap(dico, level):
    res = [0, 0, 0, 0, 0, 0, 0]
    if (dico['food'] < 8):
        res[0] = 1
    if (level < 8 and dico['food'] > 5):
        if (dico['linemate'] < required_items[level]['linemate']):
            res[1] = 1
        if (dico['deraumere'] < required_items[level]['deraumere']):
            res[2] = 1
        if (dico['sibur'] < required_items[level]['sibur']):
            res[3] = 1
        if (dico['mendiane'] < required_items[level]['mendiane']):
            res[4] = 1
        if (dico['phiras'] < required_items[level]['phiras']):
            res[5] = 1
        if (dico['thystame'] < required_items[level]['thystame']):
            res[6] = 1
    return res