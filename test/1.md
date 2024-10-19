主要部分是work函数，work_dir是lean项目的根目录，repl_path是repl的路径，repl是一个可执行的文件
work函数接收的参数是需要解析的lean定理文件的路径，解析过程是由Lean4Client类的对象完成的，主函数部分是我批量解析定理附加的内容

```python
import pexpect
import json
import argparse
import os
import re


class Lean4Client:
    def __init__(self, repl_path, work_dir):

        cmd = "lake env {}".format(repl_path)
        self.proc = pexpect.spawn(
            cmd, cwd=work_dir, encoding="utf-8"
        )
        self.proc.debug = True

    def run_allTactics(self, code, env=None, verbose=True):
        if env:
            command = (
                '{ "cmd" : "' + repr(code)[1:-1] + f'", "allTactics": true' + " }"
            )  # [1:-1] removes single quotes
        else:
            command = (
                '{ "cmd" : "' + repr(code)[1:-1] + f'", "allTactics": true' + " }"
            )  # [1:-1] removes single quotes

        if verbose:
            print(command)
        self.proc.sendline(command)
        self.proc.expect_exact(command + "\r\n")

        # debugging
        # print(self.proc.before)

        self.proc.sendline()
        self.proc.expect_exact("\r\n")
        try:
            index = self.proc.expect('env": \d+\}', timeout=60)
            output = self.proc.before + self.proc.match.group()
            if verbose: 
                print(output)
                print("=======================")
                output = output[output.index('{'):output.rfind('}')+1]
                print(output)
            return json.loads(output)
        except pexpect.exceptions.TIMEOUT:
            print("FAILED DUE TO TIMEOUT")


def work(filepath: str) -> None:
    
    work_dir = "/home2/wanglei/Project/"
    
    repl_path = "/home2/wanglei/tmp_hgl/Lean4client_v1/REPL/v4.3.0-rc1/repl"

    lean = Lean4Client(repl_path, work_dir)

    with open(filepath, 'r') as file:
        filename = os.path.basename(file.name)
        content = file.read()
    print(filepath)
    output = lean.run_allTactics(content, verbose=False)
    output['leanfilename']=filepath
    with open( "{}.json".format(filename), 'w') as f:
        json.dump(output, f)


filter_list = set()
with open('/home2/wanglei/tmp_hgl/Lean4client_v1/filter_list.txt') as file:
    for line in file.readlines():
        if line.startswith('./'):
            line = line[2:]
        filter_list.add(line.strip())
print(filter_list)
directory = input('input abs dir to convert: ')
if not directory.endswith('/'):
    directory = directory + '/'
for file in os.listdir(directory):
    filepath = directory + file
    if file in filter_list:
        continue
    if os.path.isfile(filepath) and filepath.endswith('.lean'):
        work(directory + file)
```