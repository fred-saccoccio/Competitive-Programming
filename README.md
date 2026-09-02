# Tips

## Neovim snippet for C++
### Description
A quick an easy neovim command to automatically generate a C++ template code.<br/>
Just typeset the following command at neovim `:CpBootstrap`.

## How 
The following code must be added at the end of your init.lua in neovim.
It adds to neovim the `CpBootstrap` command and this command appends the folowwing C++ code :
```cpp
#include<bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]) {
  // Stdin/stdout optimizations => quicker i/o for competitive programming
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  return 0;
}
```

Here is the lua code (written with Chatgpt's help :):
```lua
vim.api.nvim_create_user_command("CpBootstrap", function()

    local row, col = unpack(vim.api.nvim_win_get_cursor(0))

    local lines = {
        "#include<bits/stdc++.h>",
        "",
        "using namespace std;",
        "",
        "int main (int argc, char *argv[]) {",
        "  // Stdin/stdout optimizations => quicker i/o for competitive programming",
        "  ios::sync_with_stdio(0);",
        "  cin.tie(0);",
        "  cout.tie(0);",
        "  ",
        "   ",
        "  ",
        "  return 0;",
        "}"
    }

    -- Buffer vide : remplacer la ligne vide existante
    if vim.api.nvim_buf_line_count(0) == 1
        and vim.api.nvim_buf_get_lines(0, 0, 1, false)[1] == "" then

        vim.api.nvim_buf_set_lines(0, 0, 1, false, lines)

        -- Curseur au début de la ligne 11, col. 3 
        vim.api.nvim_win_set_cursor(0, { 11, 3 })

    else
        -- Insérer après la ligne courante
        vim.api.nvim_buf_set_lines(0, row, row, false, lines)

        vim.api.nvim_win_set_cursor(0, { row + 11, 3 })
    end

end, {})
```

## Python ; debug without stdin problems
### Description
### Source code
```python
import sys
import pdb
import os

if len(sys.argv) < 3:
    print(f"Usage: {sys.argv[0]} <script.py> <input_file> [arguments...]")
    sys.exit(1)

script = os.path.abspath(sys.argv[1])
input_file = sys.argv[2]
script_args = sys.argv[3:]

# --------------------------------------------------
# stdin for the DEBUGGEE
# --------------------------------------------------
program_stdin = open(input_file, "r", encoding="utf-8")

# --------------------------------------------------
# stdin for the DEBUGGER : adapt to the operating system
# --------------------------------------------------
if os.name == "nt":
    debugger_stdin = open("CONIN$", "r")
else:
    debugger_stdin = open("/dev/tty", "r")

# --------------------------------------------------
# Configuring the debugged program
# --------------------------------------------------
sys.stdin = program_stdin
sys.argv = [script] + script_args

# --------------------------------------------------
# Configuring pdb
debugger = pdb.Pdb(
    stdin=debugger_stdin,
    stdout=sys.stdout
)

# Tell pdb the main file to debug 
debugger.mainpyfile = debugger.canonic(script)
debugger._wait_for_mainpyfile = True

# --------------------------------------------------
# Lauch !
# --------------------------------------------------
with open(script, "rb") as f:
    code = compile(f.read(), script, "exec")

debugger.run(code)
```

```

