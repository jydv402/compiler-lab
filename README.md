## to run a C Program

```bash
gcc filename.c
./a.out
```
## to run a lex program

```bash
lex filename.l
gcc lex.yy.c
./a.out
```
## to install YACC (bison)
```bash
sudo apt-get install bison
sudo apt-get install gcc flex bison
```
## to run a YACC program
```bash
yacc -d filename.y
lex filename.l
gcc lex.yy.c y.tab.c -w
./a.out
```