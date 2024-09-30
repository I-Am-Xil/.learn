#!/bin/bash

mynum=200

if [ -f ./myfile ]
then
    echo "The file exists."
    rm myfile
    echo "The file has been deleted."
else
    echo "The file does not exists."
    touch myfile
    echo "The file has been created."
fi
