output=$(./build/app)

predictions=$(echo "$output" | grep -A 3 "Predictions:")

label_ch=$(echo "$predictions" | grep "ch:" | awk '{print $2}')
label_dc=$(echo "$predictions" | grep "dc:" | awk '{print $2}')
label_sc=$(echo "$predictions" | grep "sc:" | awk '{print $2}')

if (( $(echo "$label_ch > $label_dc" | bc -l) )) && (( $(echo "$label_ch > $label_sc" | bc -l) )); then
    echo "ch"
elif (( $(echo "$label_dc > $label_ch" | bc -l) )) && (( $(echo "$label_dc > $label_sc" | bc -l) )); then
    echo "dc"
else
    echo "sc"
fi
