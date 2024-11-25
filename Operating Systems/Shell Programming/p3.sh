if [ $# -lt 1 ]; then
        echo "Insufficient args."
	exit 1
fi

if [ ! -d "$1" ]; then
        echo "Parameter is not a directory"
        exit 1
fi

lines=0

for f in $(find "$1" -type f | grep -E "\.c$"); do
	nr=`grep -E -c -v "^[ \t]*$" $f`
	echo "$f: $nr"
	lines=`expr $lines + $nr`
done
echo "Total number of lines: $lines"
