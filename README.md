## Steps to run a C Program

```bash
gcc filename.c
./a.out
```
## Steps to run a lex program

```bash
lex filename.l
gcc lex.yy.c
./a.out
```
## Steps to install YACC (bison)
```bash
sudo apt-get install bison
sudo apt-get install gcc flex bison
```
## Steps to run a YACC program
```bash
yacc -d filename.y
lex filename.l
gcc lex.yy.c y.tab.c -w
./a.out
```