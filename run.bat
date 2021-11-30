@echo off
gcc -o app "src\main.c" "src\otuput.c" "src\generation.c"

app.exe
Del app.exe