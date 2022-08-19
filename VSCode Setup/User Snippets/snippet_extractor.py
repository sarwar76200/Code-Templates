import json, re, sys, os

def read_file(file_name):
    json_file = open(file_name, "r")
    text = json_file.read()
    json_file.close()
    text = delete_comments(text)
    return text

def delete_comments(text : str):
    lines = text.split('\n')
    res : str = ''
    for line in lines:
        line = line.strip()
        if line[0 : 2] == '//': continue
        res += f'{line}\n'

    return res


def is_valid(name : str):
    for symbol in ['/', '<', '>', ':', '"', '\\', '|', '?', '*']:
        if name.find(symbol) != -1:
            return False
    return True


def prepare_json(file_name, folder_name):
    text = read_file(file_name)
    regex = r'''(?<=[}\]"']),(?!\s*[{["'])'''
    result = re.sub(regex, '', text, 0)

    data = json.loads(result)
    os.makedirs(folder_name)
    for key in data:
        name : str = key
        prefix = data[key]['prefix']

        file_name = name if is_valid(name) else prefix
        
        f_out = open(f'{folder_name}/{file_name}.cpp', 'w')

        lines = data[key]['body']
        res : str = ''
        for line in lines:
            res += f'{line}\n'
        f_out.write(res)
    


argc = len(sys.argv)

file_name = 'cpp.json' if argc < 2 else sys.argv[1]
folder_name = 'Snippets' if argc < 3 else sys.argv[2]


prepare_json(file_name, folder_name)