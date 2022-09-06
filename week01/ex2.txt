    1  sudo apt-get update
    2  sudo apt-get install gcc
    3  mkdir ~/week1
    4  cd ~/week1
    5  find /usr/bin -name "gcc" || sort -r || tail -n 5 > ex1.txt
    6  find /usr/bin -name "*gcc*" | sort -r | tail -n 5 > ex1.txt
    7  touch ex1t.txt
    8  mv ex1t.txt ex1.sh
    9  history > ex2.txt
