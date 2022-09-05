clang++ A.cpp -o A -std=c++17
clang++ Ard.cpp -o Ard -std=c++17
clang++ Avd.cpp -o Avd -std=c++17

while true; do
./Ard > A.in
cp A.in Avd.in
./A < A.in >> Avd.in
./Avd < Avd.in > Avd.out
if diff Avd.out Aac.out; then
printf AC
else 
echo WA
exit 0
fi
done