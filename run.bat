@echo off
gcc -o app "E:\programming projects\maze-generator\src\main.c" "E:\programming projects\maze-generator\src\otuput.c" "E:\programming projects\maze-generator\src\generation.c"

app.exe
Del app.exe