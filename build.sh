FILE_NAME="build"
TARGET_DIR=$1

cd $TARGET_DIR

g++ $(ls | grep cpp) -o $FILE_NAME && ./$FILE_NAME

if ls | grep -q $FILE_NAME;
then 
    rm $FILE_NAME
fi

cd ..