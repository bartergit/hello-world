#!/bin/bash
start_ind=$1
end_ind=$2
array=(0 0) # 1 - не простое число
if [ "$start_ind" -lt "$end_ind" ] && [ "$start_ind" -gt 0 ]
    then
    for (( i=2; i <= end_ind; i++ ))
    do
      array+=(1)
    done
    for (( ind=2; ind * ind <= end_ind; ind++ ))  # если ind - простое (не вычеркнуто)
    do
      if [ ${array[$ind]} -eq 1 ]
      then
        for (( k=ind * ind; k <= end_ind; k += ind )) # то вычеркнем кратные ind
          do
            array[$k]=0
            done
      fi
    done
    echo "Простые числа на отрезке [${start_ind}, ${end_ind}]:"
    rm -r data &> /dev/null
    mkdir data
    counter=0
    for (( ind=$start_ind; ind <= end_ind; ind++ ))
    do
        if [ ${array[$ind]} -eq 1 ]
        then
            counter=$(( counter+1 ))
            from=$(( (ind - 1) / 10 * 10 + 1 ))
            to=$(( (ind - 1) / 10 * 10 + 10 ))
            filename="primes_${from}-${to}.lst"
            echo $ind
            echo $ind >> data/$filename
        fi
    done
    echo "Итого: ${counter} простых чисел на отрезке [${start_ind}, ${end_ind}]"
    FILES=data/*
    segment_counter=0
    for f in $FILES
    do
        amount=$(wc -l $f)
        amount=${amount:0:1}
        index=$(( (${#f} - 17)/2 ))
        from=${f:12:index}
        to=$(( from + 9 ))
        echo "Простые числа на отрезке [${from}, ${to}]:
$(cat $f)
Итого: ${amount} простых чисел на отрезке [${from}, ${to}]" > $f
    done
    echo $s
fi