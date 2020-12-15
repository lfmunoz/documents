#!/bin/bash

# This describes the shell that will be interpreting any commands you type in. 
#  In most cases, this will be bash by default, but other values can be set if 
#  you prefer other options.
echo $SHELL
# /usr/bin/zsh

# This specifies the type of terminal to emulate when running the shell. Different 
#   hardware terminals can be emulated for different operating requirements. You
#   usually won’t need to worry about this though.
echo $TERM
# screen-256color

# The current logged in user.
echo $USER
# luis

#  The current working directory.
echo $PWD
# /home/luis/github/documents/lang/Bash/src

# The previous working directory. This is kept by the shell in order to switch back 
#  to your previous directory by running cd -.
echo $OLDPWD
# /home/luis/github/documents/lang/Bash

# This defines color codes that are used to optionally add colored output to 
#  the ls command. This is used to distinguish different file types and provide 
#  more info to the user at a glance.
echo $LS_COLORS 

#  The path to the current user’s mailbox.
echo $MAIL
# blank

#  A list of directories that the system will check when looking for commands. 
#   When a user types in a command, the system will check directories in this order for the executable.
echo $PATH
# /home/luis/anaconda3/bin:/home/luis/.cargo/bin::/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

#  The current language and localization settings, including character encoding.
echo $LANG
# en_US.UTF-8

# The current user’s home directory.
echo $HOME
# /home/luis

# The most recent previously executed command.
echo $_
# /home/luis

# The hostname of the machine the script is running on.
echo $HOSTNAME 
# luis-workstation

# The number of seconds since the script was started.
echo $SECONDS 
# 0

# Returns a different random number each time is it referred to.
echo $RANDOM  
echo $RANDOM  
# 26732
# 8430

# Returns the current line number in the Bash script.
echo $LINENO
# 69

# The process ID of the current script.
echo $$ 
# 11107
