#!/bin/bash

set -eou pipefail

checker=clang-tidy
dummy_file=dummyfile

echo ""
echo " ========================================================= "
echo "     Running Static Code Analysis                          "
echo "     using $checker ...                                    "
echo " ========================================================= "
echo ""

$checker -p Build/ --config-file=.clang-tidy Src/*.c -header-filter=.* --quiet > $dummy_file

echo ""
echo " ========================================================= "
echo "     RESULTS                                               "
echo ""

results=$(cat $dummy_file)

rm $dummy_file

if [[ $results ]]; then
    echo "     FAIL                                                  "
    echo "     $checker has found problems!                          "
    echo " ========================================================= "
    echo ""
    echo "$results"
    echo ""
    exit 1
else
    echo "     SUCCESS                                               "
    echo "     $checker says code is OK!                             "
    echo " ========================================================= "
    echo ""
fi

exit 0
