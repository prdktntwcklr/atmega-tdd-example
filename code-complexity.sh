#!/bin/bash

set -ou pipefail

checker=lizard

if ! command -v "$checker" &> /dev/null; then
    echo "ERROR $checker is not installed." >&2
    exit 1
fi

echo ""
echo " ========================================================= "
echo "     Running Code Complexity Analysis                      "
echo "     using $checker...                                     "
echo " ========================================================= "

results=$("$checker" Src Inc -w)
exit_code=$?

echo "     RESULTS                                               "
echo ""

if [ "$exit_code" -ne 0 ]; then
    echo "$results"
    echo ""
    echo "     FAIL                                                  "
    echo "     $checker has found problems!                          "
    echo " ========================================================= "
    exit 1
fi

echo "     SUCCESS                                               "
echo "     $checker says code is OK!                             "
echo " ========================================================= "
echo ""
exit 0
