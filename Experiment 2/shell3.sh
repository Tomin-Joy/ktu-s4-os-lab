echo "Enter the first number";
read a;
echo "Enter the second number";
read b;
echo "The values are $a and $b";
if [ $a -gt $b ]
then
    echo "$a is bigger";
else
    echo "$b is bigger";
fi