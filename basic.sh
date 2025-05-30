#!/bin/bash
echo "os: $(uname -s)"
echo "release: $(lsb_release -d)"
echo "kernel: $(uname -r)"
echo "shells"
cat /etc/shells
echo "processor: $(lscpu)"
echo "free memory"
free -h
echo "hard disk: $(lsblk)"
echo "cache"
df
echo "file"
df -h
