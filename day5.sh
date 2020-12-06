#!/bin/bash

MAX_SEAT_IND=0
ROWS_COUNT=127
COLS_COUNT=7
declare -a OCCUPIED=( $(for i in {1..1024}; do echo 0; done) )

while read SEAT; do
    CUR_MAX_ROW=$ROWS_COUNT
    CUR_MAX_COL=$COLS_COUNT
    CUR_MIN_ROW=0
    CUR_MIN_COL=0

    for (( i=0; i<${#SEAT}; i++ )); do
        c=${SEAT:$i:1}
        case $c in
            F)
                CUR_MAX_ROW=$(( ($CUR_MAX_ROW+$CUR_MIN_ROW)/2 ))
            ;;
            B) 
                CUR_MIN_ROW=$(( ($CUR_MAX_ROW+$CUR_MIN_ROW+1)/2 ))
            ;;
            L)
                CUR_MAX_COL=$(( ($CUR_MAX_COL+$CUR_MIN_COL)/2 ))
            ;;
            R) 
                CUR_MIN_COL=$(( ($CUR_MAX_COL+$CUR_MIN_COL+1)/2 ))
            ;;
        esac
    done

    SEAT_INDEX=$(( 8*$CUR_MAX_ROW+$CUR_MAX_COL ))
    OCCUPIED[$SEAT_INDEX]=1
    # part 1
    if [ $SEAT_INDEX -gt $MAX_SEAT_IND ]; then
        MAX_SEAT_IND=$SEAT_INDEX
    fi
done

echo $MAX_SEAT_IND

# part 2
MY_SEAT_IND=$MAX_SEAT_IND
while [ ${OCCUPIED[MY_SEAT_IND]} -ne 0 ]; do
    (( MY_SEAT_IND-- ))
done
echo $MY_SEAT_IND
