set VS2022TOOLS="D:\Dev\VisualStudio\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

if not exist %VS2022TOOLS% (
    echo VS 2022 Build Tools are missing!
    exit
)

call %VS2022TOOLS%

echo Building...
:: run cl.exe with args
cl.exe %*

exit