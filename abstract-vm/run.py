import os

def print_success(path):
    print("\033[92m" + path + ": OK" + "\033[0m")

def print_failure(path):
    print("\033[91m" + path + ": KO" + "\033[0m")

def run(directory):
    items = os.listdir(directory)

    for item in items:
        path = directory + "/" + item
        if os.path.isdir(path):
            run(path)
        if os.path.isfile(path):
            if path.endswith(".avm"):
                exit_code = os.WEXITSTATUS(os.system("./abstractVM " + path))
                if "success" in path:
                    if exit_code == 0:
                        print_success(path)
                    else:
                        print_failure(path)
                if "fail" in path:
                    if exit_code == 84:
                        print_success(path)
                    else:
                        print_failure(path)
                    

run(os.getcwd() + "/samples")