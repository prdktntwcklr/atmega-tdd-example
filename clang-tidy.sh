#!/bin/bash

set -eou pipefail

BUILD_DIR="Build"
CHECKER="clang-tidy"
DUMMY_FILE="dummyfile"

if ! command -v "$CHECKER" &> /dev/null; then
    echo "ERROR $CHECKER is not installed." >&2
    exit 1
fi

echo ""
echo " ========================================================= "
echo "     Running Static Code Analysis                          "
echo "     using $CHECKER ...                                    "
echo " ========================================================= "
echo ""

$CHECKER -p ${BUILD_DIR:?}/ --config-file=.clang-tidy Src/*.c -header-filter=.* --quiet > $DUMMY_FILE

echo ""
echo " ========================================================= "
echo "     RESULTS                                               "
echo ""

results=$(cat $DUMMY_FILE)

rm $DUMMY_FILE

if [[ $results ]]; then
    echo "     FAIL                                                  "
    echo "     $CHECKER has found problems!                          "
    echo " ========================================================= "
    echo ""
    echo "$results"
    echo ""
    exit 1
else
    echo "     SUCCESS                                               "
    echo "     $CHECKER says code is OK!                             "
    echo " ========================================================= "
    echo ""
fi

exit 0
