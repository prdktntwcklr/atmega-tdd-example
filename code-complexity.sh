#!/bin/bash

set -ou pipefail

CHECKER="lizard"

if ! command -v "$CHECKER" &> /dev/null; then
    echo "ERROR $CHECKER is not installed." >&2
    exit 1
fi

echo ""
echo " ========================================================= "
echo "     Running Code Complexity Analysis                      "
echo "     using $CHECKER...                                     "
echo " ========================================================= "

results=$("$CHECKER" Src Inc -w)
exit_code=$?

echo "     RESULTS                                               "
echo ""

if [ "$exit_code" -ne 0 ]; then
    echo "$results"
    echo ""
    echo "     FAIL                                                  "
    echo "     $CHECKER has found problems!                          "
    echo " ========================================================= "
    exit 1
fi

echo "     SUCCESS                                               "
echo "     $CHECKER says code is OK!                             "
echo " ========================================================= "
echo ""
exit 0
