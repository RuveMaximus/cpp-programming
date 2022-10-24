FILE_NAME="build"
TARGET_DIR="vector"

cd $TARGET_DIR

g++ $(ls | grep cpp) -o $FILE_NAME

if ls | grep -q $FILE_NAME;
then 
    ./$FILE_NAME
    rm $FILE_NAME
fi

cd ..