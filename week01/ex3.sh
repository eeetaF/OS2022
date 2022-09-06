date
sleep 3
mkdir uselessfolder1
date
sleep 3
mkdir uselessfolder2
cd uselessfolder1
date
sleep 3
touch root.txt
cd ../uselessfolder2
date
sleep 3
touch home.txt
ls -tr / > ~/week1/uselessfolder1/root.txt
ls -tr ~ > ~/week1/uselessfolder2/home.txt
cat ~/week1/uselessfolder1/root.txt
cat ~/week1/uselessfolder2/home.txt
ls ~/week1/uselessfolder1
ls ~/week1/uselessfolder2
