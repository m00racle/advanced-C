# Advanced C Course LAB

This is the Git for the Advanced C course.
Why do I pick C to learn advanced programming? Well I think to learn advanced programming it will be better to use low level language.

Since it is low level programming language thus I can focus more on how things are done behind the scene.

## Task config
Here is the taks.json config (for the moment) for C :
```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: gcc.exe build active file",
            "command": "E:\\appsInstalled\\MSYS2\\mingw64\\bin\\gcc.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${fileDirname}/*.c",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Task generated by Debugger."
        }
    ],
    "version": "2.0.0"
}
```
Nothing special here just make sure that all files wiht c extension in the working folder (the folder where the source code is located NOT the workspace folder) gets compiled into machine code.

Other than that all standard with output set to be located in the same folder as the source code folder.

## Debug Configuration
The debug config is located in the launch.json:
```json
{
    "configurations": [
        {
            "name": "C/C++: gcc.exe build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "E:\\appsInstalled\\MSYS2\\mingw64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: gcc.exe build active file"
        }
    ],
    "version": "2.0.0"
}
```
Again just basic settings and still using stopAtEntry setting as false thus instead you put breakpoint or watch in the source code when pressing F5 (in Windows) you will have the result like running the program in task.json.
