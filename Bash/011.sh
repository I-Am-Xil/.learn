#!/bin/bash

while [ -f ./testfile ]
do
    echo "As of $(date). The test file exists."
    sleep 1
done

echo "As of $(date), the test file has gone missing."
