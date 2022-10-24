g++ $(ls | grep cpp) -o compiled

if ls | grep -q compiled; 
then 
    ./compiled
    rm compiled
fi