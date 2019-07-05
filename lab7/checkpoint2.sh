g++ -Wall start.cpp && {
    for i in {1,2,3,4}
    do
        echo grid$i.txt "---------start----------"
        ./a.out grid$i.txt
        echo
        echo grid$i.txt "----------end-----------"
    done
}
