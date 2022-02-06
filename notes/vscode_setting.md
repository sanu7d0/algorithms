# build.bat

```bat
set VS2022TOOLS="...\VisualStudio\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

if not exist %VS2022TOOLS% (
    echo VS 2022 Build Tools are missing!
    exit
)

call %VS2022TOOLS%

echo Building...
:: run cl.exe with args
cl.exe %*

exit
```

bat 파일로 build하면, cl.exe path를 커스텀 할 수 있다.

$~$

# keybindings.json

```json
[
  {
    "key": "f6",
    "command": "workbench.action.tasks.build",
    "args": "cpp-build-run",
    "when": "editorTextFocus && editorLangId == cpp"
  },
  {
    "key": "f7",
    "command": "workbench.action.tasks.test",
    "args": "cpp-test",
    "when": "editorTextFocus && editorLangId == cpp"
  }
]
```
