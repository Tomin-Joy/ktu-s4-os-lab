echo "Enter a limit";
read n;
a=0;
b=1;
echo "The Fibonacci Series is:";
for((i=0; i<=n; i++))
do
    echo "$a";
    c=$((a+b));
    a=$b;
    b=$c;
done