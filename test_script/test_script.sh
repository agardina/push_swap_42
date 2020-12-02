#!/bin/bash

if (( $# != 2 )) ; then
	echo "Usage : ./test_perso.sh stack_size number_of_tests"
	exit 1 
fi

if (( $1 <= 0)); then
	echo "Please choose a stack_size greater than 0"
	exit 1
fi

if (( $2 <= 0 )); then
	echo "Please choose a number of tests greater than 0"
	exit 1
fi

let "total = 0"
for (( i=1 ; i<=$2 ; i++ )) ;
do
	ARG=`ruby -e "puts (-9999..9999).to_a.sort{ rand() - 0.5 }[0..($1 - 1)].join(' ') "`
	PS_RESULT="`./push_swap $ARG`"
	RESULT="`echo ${PS_RESULT} | tr " " "\n" | wc -l | bc`"
	let "total += RESULT"
	CHECKER_RESULT="`./push_swap $ARG | ./checker $ARG`"
	if (( $CHECKER_RESULT == "OK")) ; then
		CHECKER_RESULT="✓"
	else
		CHECKER_RESULT="⨯"
	fi
	printf "%d : %5d " $i ${RESULT}
    echo "${CHECKER_RESULT}"
done

let "average = total / $2"

echo "Average: ${average}"
