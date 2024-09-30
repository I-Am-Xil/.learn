#!/bin/bash

release_file=/etc/os-release

if grep -q "Arch" $release_file
then
    # The host is based on Arch, run the pacman update command
    sudo pacman -Syu
fi

if grep -q "debian" $release_file
then
    # The host is based on Debian. Run the apt version
    sudo apt update
    sudo apt dist-upgrade
    sudo apt autoremove -y
fi
