# INTRODUCTION
This is a small project of mine I created because I was bored. It takes in mutiple integer arguments and creates a cli graph!

## Usage
### Prerequisities
You will need a compiler (e.g. gcc)

### Installation
1. Please copy these commands and paste them into your terminal (Linux):
```bash
git clone "https://github.com/jantar1154/graphme"
gcc graphme/main.c -o graphme/graphme
sudo mv graphme/graphme /usr/local/bin
rm -rf graphme
```
2. Reload your terminal and the tool is ready to use!

### Usage
1. The command is ```graphme```
2. You can input any number of arguments but two minimal
```bash
$ graphme [arg1, arg2, arg3,...]
```
**For example:**
```bash
$ graphme 3 5 1 -5 11 32

                    X   
                    X   
                    X   
                    X   
                    X   
                    X   
                    X   
                    X   
                    X   
                    X   
                    X   
                X   X   
                X   X   
                X   X   
    X           X   X   
X   X           X   X   
X   X   X       X   X   
X   X   X       X   X   
X   X   X       X   X   
X   X   X   X   X   X  
```
3. The program prints out the resulting graph
