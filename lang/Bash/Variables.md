---
title: Variables
mathjax: true
layout: default
toc: true
---



# Variable


Bash reads .bashrc file in non login interactive shell and .bash_profile in login shells.

Zsh reads .zshrc in an interactive shell and .zprofile in a login shell.




* ${variable} is just a disambiguation mechanism
* $(command) is a modern synonym for `command` which stands for command substitution; it means run command and put its output here

. Before Bash interprets (or runs) every line of our script it first checks to see if any variable names are present. For every variable it has identified, it replaces the variable name with its value. Then it runs that line of code and begins the process again on the next line.

A variable may be placed anywhere in a script (or on the command line for that matter) and, when run, Bash will replace it with the value of the variable. This is made possible as the substitution is done before the command is run.




HOSTNAME: The hostname of the computer at this time.
IFS: The internal field separator to separate input on the command line. By default, this is a space.

PS1: The primary command prompt definition. This is used to define what your prompt looks like when you start a shell session. The PS2 is used to declare secondary prompts for when a command spans multiple lines.





## Command Line Arguments



<details>
<summary> <strong> cat src/cmd_line_args.sh </strong> </summary>
<p markdown="block">
```bash
{% include_relative src/cmd_line_args.sh %}
````
</p></details>  





## Predefined Variables


<details>
<summary> <strong> cat src/predefined_vars.sh </strong> </summary>
<p markdown="block">
```bash
{% include_relative src/predefined_vars.sh %}
````
</p></details>  





```bash

# Note there is no space on either side of the equals sign
myvariable=Hello
```
 under normal circumstances Bash uses a space to determine separate items.

### Environment Variables

child processes typically inherit the environmental variables of the parent process

```bash
#  List of all of our environmental variables by using the env or printenv commands
printenv


# env lets you modify the environment that programs run in by passing 
# a set of variable definitions into a command like this:
env VAR1="value" command_to_run command_options

```

### Shell Variables 

```bash
# to see shell variables use set    
set

# POSIX mode, won’t print the shell functions
(set -o posix; set)
```


```bash
# To create a shell variable 
TEST_VAR='Hello World!'

echo $TEST_VAR

# if you spawn a new shell nothing is returned
bash
echo $TEST_VAR

# Turn a shell variable into an environmental variable
export TEST_VAR
# or create an environment variable in a single step
export NEW_VAR="Testing export"
printenv | grep TEST_VAR

# change it back into a shell variable 
export -n TEST_VAR

# completely unset a variable, either shell or environmental
unset TEST_VAR
```



Note: Environmental variables are only passed to child processes.

## Setting Environmental Variables at Login

The bash shell reads different configuration files depending on how the session is started.

Login - A shell session that begins by authenticating the user (i.e, ssh)
* Reads global config file: /etc/profile
* Then user specific first of: ~/.bash_profile or ~/.bash_login or  ~/.profile
Non-Login - simply calling bash command, you weren't asked for a authentication
* /etc/bash.bashrc
* ~/.bashrc
Interactive - session is attached to a terminal
Non-Interactive - session is NOT attached to a terminal session (i.e., running a script)
* read file defined in BASH_ENV

