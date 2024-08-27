#!/bin/bash

echo "Testing simple_shell"

# Test basic commands
echo "ls" | ./hsh
echo "/bin/ls" | ./hsh

# Test commands with arguments
echo "ls -l /tmp" | ./hsh

# Test non-existent commands
echo "non_existent_command" | ./hsh

# Test exit
echo "exit" | ./hsh

# Test env
echo "env" | ./hsh

# Test setenv and unsetenv
echo "setenv TEST_VAR test_value" | ./hsh
echo "env" | ./hsh
echo "unsetenv TEST_VAR" | ./hsh
echo "env" | ./hsh

# Test cd
echo "cd /tmp" | ./hsh
echo "pwd" | ./hsh

# Test command separator
echo "ls /var ; ls /var" | ./hsh

# Test logical operators
echo "ls /var && ls /var" | ./hsh
echo "ls /hbtn || ls /var" | ./hsh

# Test alias
echo "alias l='ls -l'" | ./hsh
echo "l" | ./hsh

# Test variable replacement
echo "echo $PATH" | ./hsh
echo "echo $$" | ./hsh
echo "echo $?" | ./hsh

# Test comments
echo "ls /var # this is a comment" | ./hsh
