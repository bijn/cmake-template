# Bijan Sondossi
# generate_project.sh
# Generates a basic project from the default template.

if [ -z "$1" ] && ! [ -e "$1" ]
then
    echo "USAGE: ./generate_project.sh project_name"
    exit -1
fi

if mkdir -p $1/modules && cp -r template/* $1 && cd $1
then
    mv include/Template include/$1

    for file in * */* */*/*
    do
        if ! [ -d $file ]
        then
            if [ "$(uname)" == 'Darwin' ]
            then
                sed -i '' "s/Template/$1/g" $file
                sed -i '' "s/TEMPLATE/$1/g" $file
            else
                sed -i "s/template/$1/Ig" $file
            fi
        fi
    done

    git init

    git submodule add --name gtest \
        https://github.com/google/googletest modules/gtest

    git submodule add --name cmake-helpers \
        https://github.com/bijn/cmake-helpers modules/cmake-helpers

    git add .
fi
