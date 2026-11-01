# VScode_C_basic_0

A minimal C program example for compiling and running in Visual Studio Code.

## Build and run

Open this folder in VS Code, then use its integrated terminal:

```sh
gcc -std=c11 -Wall -Wextra -pedantic main.c -o main
./main
```

On Windows, run the generated program with:

```powershell
.\main.exe
```

The program prints `Hello, C!`.